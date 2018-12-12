#include "stdafx.h"
#include "GameObject.h"
#include <iostream>


GameObject::GameObject(sf::Vector2f pos) : _position(pos)
{
	/*if (string_to_tag("Player") == Player)
		std::cout << "this is player";*/
}

sf::Sprite GameObject::GetSprite()
{

	return _sprite;
}

//sf::Texture texture;
//texture.loadFromFile("texture.png");
//// Create a sprite
//sf::Sprite sprite;
//sprite.setTexture(texture);
//sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
//sprite.setColor(sf::Color(255, 255, 255, 200));
//sprite.setPosition(100, 25);

void GameObject::SetSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}


void GameObject::Collide()
{
	_position = _lastPosition;
}
void GameObject::Move(float x, float y)
{
	_lastPosition = _position;
	//std::cout << "Moving object" << std::endl;
	_position.x = _position.x+x;
	_position.y = _position.y + y;
	_sprite.setPosition(_position);
	_collider.SetPosition(_position);

}
sf::Texture GameObject::GetTexture()
{
	return sf::Texture();
}

sf::Vector2f GameObject::GetPos()
{
	return _position;
}

void GameObject::SetTexture(sf::Texture texture)
{
	_sprite.setTexture(texture);
}

int GameObject::GetFrame()
{
	return _currFrame;
}

void GameObject::SetFrame(int frame)
{
	_currFrame = frame;
}

int GameObject::GetDir()
{
	return _direction;
}

void GameObject::SetDir(int dir)
{
	_direction = dir;
}

std::string GameObject::GetTag()
{
	return _tag;
}

void GameObject::SetTag(std::string s)
{
	_tag = s;
}

std::string GameObject::GetName()
{
	return _name;
}

void GameObject::SetName(std::string s)
{
	_name = s;
}

Collider GameObject::GetCollider()
{
	return _collider;
}

void GameObject::SetCollider(Collider c)
{
	_collider = c;
}
