#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include "common.h"


namespace Collision {

	struct AABB {
		glm::vec3 min;
		glm::vec3 max;
	};
	extern const AABB cameraAABB;
	class CollisionDetector
	{
	public:
		static bool checkAABBCollision(const AABB box1, const AABB box2, glm::vec3& collisionNormal, float& penetrationDepth);
		static bool check(glm::vec3 &normal, float &depth);
		static bool enteredDome();
		static bool updateCamPos();
		static bool checkPlayerCol(glm::vec3& normal, float& depth);

	};
}
#endif // !COLLISION_H
