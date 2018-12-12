#pragma once
#include <vector>
#include "Collider.h"
class CollisionManager
{
public:
	CollisionManager();
	bool CheckCollision(Collider a,Collider b);

private:
	std::vector<Collider> colliders;
};

