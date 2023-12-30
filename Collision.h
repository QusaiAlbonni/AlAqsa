#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include "common.h"


namespace Collision {

	struct AABB {
		glm::vec3 min;
		glm::vec3 max;
	};

	class CollisionDetector
	{
	public:
		static bool checkAABBCollision(const AABB& box1, const AABB& box2, glm::vec3& collisionNormal, float& penetrationDepth);
		static void check();


	};
}
#endif // !COLLISION_H
