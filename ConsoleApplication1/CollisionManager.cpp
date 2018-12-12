#include "stdafx.h"
#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager()
{
}

bool CollisionManager::CheckCollision(Collider a, Collider b)
{
	if (a.IsInabled() && b.IsInabled())
	{
		bool xCheck = 
			(a.GetPosition().x + a.GetWidth() / 2 >= b.GetPosition().x - b.GetWidth() / 2)&&
			(a.GetPosition().x - a.GetWidth() / 2 <= b.GetPosition().x + b.GetWidth()/2);

		bool yCheck = 
			(a.GetPosition().y + a.GetHeight()/2 >= b.GetPosition().y - b.GetHeight() / 2) &&
			( a.GetPosition().y - a.GetHeight() / 2 <= b.GetPosition().y + b.GetHeight() / 2);
		if (xCheck&&yCheck)
		{
			return true;
		}
	}
	return false;
}

