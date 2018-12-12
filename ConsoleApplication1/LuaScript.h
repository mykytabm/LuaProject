#pragma once
#include <lua.hpp>
class LuaScript
{
public:

	LuaScript();
	void Initialize();
	void Update();
	void registerFunctions();
	void stackDump(lua_State *state, const char * pre);

	static int CreateGameObject(lua_State* state);
	static int MoveObject(lua_State* state);
	static int KeyPressed(lua_State * state);
	static int KeyUp(lua_State * state);
	static int KeyDown(lua_State * state);

	static int DrawSprite(lua_State * state);
	static int CloseGame(lua_State * state);
	static int SetViewCenter(lua_State * state);
	static int GetPositionX(lua_State* state);
	static int GetPositionY(lua_State* state);
	static int Collide(lua_State* state);
	static int BounceOff(lua_State* state);
	static int SetCollisionBox(lua_State* state);
	static int ShowDialogue(lua_State* state);
	static int SetDialogueText(lua_State* state);


	static int SetAninSequence(lua_State* state);



	static int Time(lua_State* state);




private:
	lua_State * state_;
};

