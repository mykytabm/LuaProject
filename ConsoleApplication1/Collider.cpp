#include "stdafx.h"
#include "Collider.h"


Collider::Collider(float w,float h,sf::Vector2f pos):_width(w),_height(h),_pos(pos)
{
}

bool Collider::IsInabled()
{
	return _enabled;
}

void Collider::Enabled(bool v)
{
	_enabled = v;
}

float Collider::GetWidth()
{
	return _width;
}

float Collider::GetHeight()
{
	return _height;
}

sf::Vector2f Collider::GetPosition()
{
	return _pos;
}

void Collider::SetPosition(sf::Vector2f p)
{
	_pos = p;
}

void Collider::SetWidth(float w)
{
	_width = w;
}

void Collider::SetHeight(float h)
{
	_height = h;
}

