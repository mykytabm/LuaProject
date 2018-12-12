#pragma once
#include "../SFML-2.4.2/SFML-2.4.2/include/SFML/Graphics.hpp"
#include "Collider.h"

class GameObject
{
public:
	GameObject(sf::Vector2f pos);
	sf::Sprite GetSprite();
	void SetSprite(sf::Sprite);
	void Move(float x, float y);
	void Collide();
	sf::Texture GetTexture();
	sf::Vector2f GetPos();
	void SetTexture(sf::Texture);
	int GetFrame();
	void SetFrame(int frame);
	int GetDir();
	void SetDir(int dir);
	std::string GetTag();
	void SetTag(std::string s);
	std::string GetName();
	void SetName(std::string s);
	Collider GetCollider();
	void SetCollider(Collider c);


private:
	std::string _tag;
	std::string _name;
	Collider _collider;
	sf::Vector2f _position;
	sf::Vector2f _lastPosition;
	sf::Sprite _sprite;
	/*std::string;*/
	int _currFrame;
	int _numOfFrames;
	int _direction;
};

