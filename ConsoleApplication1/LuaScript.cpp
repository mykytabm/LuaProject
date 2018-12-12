#include "stdafx.h"
#include "LuaScript.h"
#include "GameObject.h"
#include "Game.h"


LuaScript::LuaScript()
{
	state_ = luaL_newstate();

	luaL_openlibs(state_);
	luaL_dofile(state_, "main.lua");
	registerFunctions();

}

void LuaScript::Initialize()
{
	std::cout << "initializing" << std::endl;
	lua_getglobal(state_, "Initialize"); 
	int isFunc = lua_isfunction(state_, -1);
	if (isFunc) {
		if (lua_pcall(state_, 0, 0, 0) != 0) {
		}
	}

}

void LuaScript::Update()
{
	lua_getglobal(state_, "Update"); // pushes global update
	int isFunc = lua_isfunction(state_, -1);
	if (isFunc) {
		if (lua_pcall(state_, 0, 0, 0) != 0) {

		}
	}

}
void LuaScript::registerFunctions()
{
	lua_newtable(state_);
	lua_pushcfunction(state_, CreateGameObject);
	lua_setfield(state_, -2, "CreateGameObject");

	lua_pushcfunction(state_, MoveObject);
	lua_setfield(state_, -2, "MoveObject");

	lua_pushcfunction(state_, SetViewCenter);
	lua_setfield(state_, -2, "SetViewCenter");

	lua_pushcfunction(state_, KeyPressed);
	lua_setfield(state_, -2, "KeyPressed");

	lua_pushcfunction(state_, KeyDown);
	lua_setfield(state_, -2, "KeyDown");

	lua_pushcfunction(state_, KeyUp);
	lua_setfield(state_, -2, "KeyUp");

	lua_pushcfunction(state_, GetPositionY);
	lua_setfield(state_, -2, "GetPositionY");

	lua_pushcfunction(state_, GetPositionX);
	lua_setfield(state_, -2, "GetPositionX");
	
	lua_pushcfunction(state_, CloseGame);
	lua_setfield(state_, -2, "CloseGame");

	lua_pushcfunction(state_, BounceOff);
	lua_setfield(state_, -2, "BounceOff");

	lua_pushcfunction(state_, Collide);
	lua_setfield(state_, -2, "Collide");

	lua_pushcfunction(state_, SetCollisionBox);
	lua_setfield(state_, -2, "SetCollisionBox");

	lua_pushcfunction(state_, SetDialogueText);
	lua_setfield(state_, -2, "SetDialogueText");

	lua_pushcfunction(state_, ShowDialogue);
	lua_setfield(state_, -2, "ShowDialogue");

	lua_pushcfunction(state_, DrawSprite);
	lua_setfield(state_, -2, "DrawSprite");

	lua_pushcfunction(state_, Time);
	lua_setfield(state_, -2, "Time");	

	lua_setglobal(state_, "Game");

	std::cout << "registered functions" << std::endl;
}



int LuaScript::CreateGameObject(lua_State * state)
{

	if (lua_gettop(state) == 5 && lua_isstring(state, 1) && lua_isstring(state, 2) &&
		lua_isstring(state, 3) && lua_isnumber(state, 4) && lua_isnumber(state, 5))
		/*if (lua_gettop(state) == 3 && lua_isstring(state, 1) && lua_isstring(state, 2) &&
			lua_isstring(state, 3))*/
	{
		std::string tag = (std::string)lua_tostring(state, 1);
		std::string name = (std::string)lua_tostring(state, 2);
		std::string textureFilePath = (std::string)lua_tostring(state, 3);
		sf::Vector2f pos = sf::Vector2f((float)lua_tonumber(state, 4), (float)lua_tonumber(state, 5));

		
		std::cout << "Creating GameObj with tag: " << tag << ", Name: " << name << "," << std::endl <<
			" TextureFilePath: " << textureFilePath << ", x: " << pos.x << ", y: " << pos.y << std::endl;

		GameObject* gameObj = new GameObject(pos);
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(textureFilePath);	
		sf::IntRect SpriteRect = sf::IntRect(0, 0, 32, 32);
		sf::Sprite sprite(*texture, SpriteRect);
		sprite.setOrigin(sf::Vector2f(SpriteRect.width / 2, SpriteRect.height / 2));
		sf::Vector2f sprScale = sf::Vector2f(2, 2);
		sprite.scale(sprScale);
		sprite.setPosition(pos);
		gameObj->SetSprite(sprite);
		Game::GetInstance()->AddGameObject(gameObj);
		lua_pushlightuserdata(state, gameObj);
		return 1;
	}
	return luaL_error(state, " Error calling Game.CreateGameObject(tag, name,textFilePath,pos.x,pos.y), check arguments");

}


int LuaScript::KeyPressed(lua_State * state)
{


	if (lua_gettop(state) == 1 && lua_isstring(state, 1))
	{
		std::string key = (std::string)lua_tostring(state, 1);
		lua_pushboolean(state, KeyHandler::KeyPressed(key));

		return 1;

	}
	return luaL_error(state, "Error calling Game.KeyPressed(string),check arguments");
}

int LuaScript::KeyUp(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isstring(state, 1))
	{
		std::string key = (std::string)lua_tostring(state, 1);
		lua_pushboolean(state, KeyHandler::KeyUp(key));

		return 1;

	}
	return luaL_error(state, "Error calling Game.KeyUp(string),check arguments");
}

int LuaScript::KeyDown(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isstring(state, 1))
	{

		std::string key = (std::string)lua_tostring(state, 1);
		lua_pushboolean(state, KeyHandler::KeyDown(key));
		return 1;

	}
	return luaL_error(state, "Error calling Game.KeyDown(string),check arguments");
}

int LuaScript::DrawSprite(lua_State * state)
{
	if (lua_gettop(state) == 7 && lua_isstring(state, 1) && lua_isnumber(state, 2) &&
		lua_isnumber(state, 3) && lua_isnumber(state, 4) && lua_isnumber(state, 5)&& 
		lua_isnumber(state, 6) && lua_isnumber(state, 7))
	{
		std::string path = (std::string)lua_tostring(state, 1);

		int width = (float)lua_tonumber(state, 2);
		int height = (float)lua_tonumber(state, 3);

		int posX = (float)lua_tonumber(state, 4);
		int posY = (float)lua_tonumber(state, 5);

		int scaleX = (float)lua_tonumber(state,6);
		int scaleY = (float)lua_tonumber(state, 7);

		sf::Texture* texture=new sf::Texture;
		sf::IntRect SpriteRect = sf::IntRect(0, 0, width, height);
		texture->loadFromFile(path);
		
		sf::Sprite* sprite = new sf::Sprite(*texture, SpriteRect);

		sprite->setScale(sf::Vector2f(scaleX, scaleY));
		Game::GetInstance()->AddSprite(sprite);
		sprite->setPosition(posX, posY);

		lua_pushlightuserdata(state, sprite);
		return 1;
	}
	return luaL_error(state, "Error calling Game.KeyDown(string),check arguments");

}

int LuaScript::CloseGame(lua_State * state)
{
	if (Game::GetInstance()->GetWindow()->isOpen()) Game::GetInstance()->GetWindow()->close();
	return 0;
}

int LuaScript::SetViewCenter(lua_State * state)
{
	if (lua_gettop(state) == 2 && lua_isnumber(state, 1) && lua_isnumber(state, 2))
	{
		int x = (float)lua_tonumber(state, 1);
		int y = (float)lua_tonumber(state, 2);

		sf::View view = Game::GetInstance()->GetWindow()->getView();
		view.setCenter(sf::Vector2f(x, y));

		Game::GetInstance()->GetWindow()->setView(view);
		return 0;
	}
	return luaL_error(state, "Error calling SetWindowPos( pointerToObj ), wrong arguments");
}

int LuaScript::GetPositionX(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isuserdata(state, 1))
	{
		GameObject * object = (GameObject *)lua_topointer(state, 1);
		int x=object->GetPos().x;
		lua_pushinteger(state, x);
		return 1;
	}
	return luaL_error(state, "Error calling GetPositionX( pointerToObj ), wrong arguments");
}

int LuaScript::GetPositionY(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isuserdata(state, 1))
	{
		GameObject * object = (GameObject *)lua_topointer(state, 1);
		int y=object->GetPos().y;
		lua_pushinteger(state, y);
		return 1;
	}
	return luaL_error(state, "Error calling GetPositionY( pointerToObj ), wrong arguments");
}

int LuaScript::Collide(lua_State * state)
{
	if (lua_gettop(state) == 2 && lua_isuserdata(state, 1) && lua_isuserdata(state, 2))
	{
		GameObject * obj1 = (GameObject *)lua_topointer(state, 1);
		GameObject * obj2 = (GameObject *)lua_topointer(state, 2); 
		bool value=Game::GetInstance()->GetCollManager()->CheckCollision(obj1->GetCollider() , obj2->GetCollider());
		lua_pushboolean(state, value);
		return 1;
	}
	return luaL_error(state, "Error calling Collide(pointerToObj,pointerToObj), wrong arguments");
}

int LuaScript::BounceOff(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isuserdata(state, 1))
	{
		GameObject * obj1 = (GameObject *)lua_topointer(state, 1);
		obj1->Collide();
		return 0;
	}
	return luaL_error(state, "Error calling BounceOff, wrong arguments");

}

int LuaScript::SetCollisionBox(lua_State * state)
{
	if (lua_gettop(state) == 3 && lua_isuserdata(state, 1) && lua_isnumber(state, 2) && lua_isnumber(state, 3)) {
		
		GameObject * object = (GameObject *)lua_topointer(state, 1);

		float width = (float)lua_tonumber(state, 2);
		float height = (float)lua_tonumber(state, 3);

		Collider col =  Collider(width, height, object->GetPos());
		object->SetCollider(col);
		return 0;
	}
}

int LuaScript::ShowDialogue(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isboolean(state, 1))
	{
		bool value = (bool)lua_toboolean(state, 1);
		Game::GetInstance()->SetDialogueVisible(value);	
		return 0;
	}
}

int LuaScript::SetDialogueText(lua_State * state)
{
	if (lua_gettop(state) == 1 && lua_isstring(state, 1))
	{
		std::string text = (std::string)lua_tostring(state, 1);
		Game::GetInstance()->SetDialogueText(text);
		return 0;
	}
}

int LuaScript::SetAninSequence(lua_State * state)
{
	return 0;
}

int LuaScript::Time(lua_State * state)
{
	sf::Int32 time = Game::GetInstance()->GetElapsedTime()->asMilliseconds();
	lua_pushnumber(state, time);
	return 1;
}

int LuaScript::MoveObject(lua_State * state)
{

	if (lua_gettop(state) == 3 && lua_isuserdata(state, 1) && lua_isnumber(state, 2) && lua_isnumber(state, 3)) {
		GameObject * object = (GameObject *)lua_topointer(state, 1);
		float x = (float)lua_tonumber(state, 2);
		float y = (float)lua_tonumber(state, 3);
		object->Move(x, y);
		return 0;
	}
	return luaL_error(state, "Error calling MoveObject( pointerToObj,x, y ), wrong arguments");
}

void LuaScript::stackDump(lua_State *state, const char * pre) {
	int i;
	int top = lua_gettop(state);
	for (i = 1; i <= top; i++) {  /* repeat for each level */
		int t = lua_type(state, i);
		switch (t) {

		case LUA_TSTRING:  /* strings */
			//printf("(%d)%s'", i, lua_tostring(state, i));
			break;

		case LUA_TBOOLEAN:  /* booleans */
			//printf("(%d)%s", i, lua_toboolean(state, i) ? "true" : "false");
			break;

		case LUA_TNUMBER:  /* numbers */
			//printf("(%d)%g", i, lua_tonumber(state, i));
			break;

		default:  /* other values */
			//printf("(%d)%s", i, lua_typename(state, t));
			break;

		}
		//printf("  ");  /* put a separator */
	}
}

