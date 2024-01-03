#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include "common.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>


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
		static bool checkPlayerCol(glm::vec3& normal, float& depth, bool &obb);

	};
    class OBB
    {
    public:
        OBB(glm::vec3 pos, glm::vec3 halfSize, glm::quat orientation)
            : Pos(pos), Half_size(halfSize), Orientation(orientation)
        {
        }

        bool checkCollision( OBB& other)
        {
            glm::vec3 RPos = other.Pos - Pos;

            bool detected = !(getSeparatingPlane(RPos, glm::rotate(Orientation, glm::vec3(1.0f, 0.0f, 0.0f)), *this, other) ||
                getSeparatingPlane(RPos, glm::rotate(Orientation, glm::vec3(0.0f, 1.0f, 0.0f)), *this, other) ||
                getSeparatingPlane(RPos, glm::rotate(Orientation, glm::vec3(0.0f, 0.0f, 1.0f)), *this, other) ||
                getSeparatingPlane(RPos, glm::rotate(other.Orientation, glm::vec3(1.0f, 0.0f, 0.0f)), *this, other) ||
                getSeparatingPlane(RPos, glm::rotate(other.Orientation, glm::vec3(0.0f, 1.0f, 0.0f)), *this, other) ||
                getSeparatingPlane(RPos, glm::rotate(other.Orientation, glm::vec3(0.0f, 0.0f, 1.0f)), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(1.0f, 0.0f, 0.0f)), glm::rotate(other.Orientation, glm::vec3(1.0f, 0.0f, 0.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(1.0f, 0.0f, 0.0f)), glm::rotate(other.Orientation, glm::vec3(0.0f, 1.0f, 0.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(1.0f, 0.0f, 0.0f)), glm::rotate(other.Orientation, glm::vec3(0.0f, 0.0f, 1.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(0.0f, 1.0f, 0.0f)), glm::rotate(other.Orientation, glm::vec3(1.0f, 0.0f, 0.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(0.0f, 1.0f, 0.0f)), glm::rotate(other.Orientation, glm::vec3(0.0f, 1.0f, 0.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(0.0f, 1.0f, 0.0f)), glm::rotate(other.Orientation, glm::vec3(0.0f, 0.0f, 1.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(0.0f, 0.0f, 1.0f)), glm::rotate(other.Orientation, glm::vec3(1.0f, 0.0f, 0.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(0.0f, 0.0f, 1.0f)), glm::rotate(other.Orientation, glm::vec3(0.0f, 1.0f, 0.0f))), *this, other) ||
                getSeparatingPlane(RPos, glm::cross(glm::rotate(Orientation, glm::vec3(0.0f, 0.0f, 1.0f)), glm::rotate(other.Orientation, glm::vec3(0.0f, 0.0f, 1.0f))), *this, other));
            if (detected)
            {
                return true;
            }
            else
                return false;
        }

    private:
        glm::vec3 Pos, Half_size;
        glm::quat Orientation;

        static bool getSeparatingPlane(const glm::vec3& RPos, const glm::vec3& Plane, const OBB& box1, const OBB& box2)
        {
            return (glm::abs(glm::dot(RPos, Plane)) >
                (glm::abs(glm::dot(box1.getAxis(0) * box1.Half_size.x, Plane)) +
                    glm::abs(glm::dot(box1.getAxis(1) * box1.Half_size.y, Plane)) +
                    glm::abs(glm::dot(box1.getAxis(2) * box1.Half_size.z, Plane)) +
                    glm::abs(glm::dot(box2.getAxis(0) * box2.Half_size.x, Plane)) +
                    glm::abs(glm::dot(box2.getAxis(1) * box2.Half_size.y, Plane)) +
                    glm::abs(glm::dot(box2.getAxis(2) * box2.Half_size.z, Plane))));
        }

        glm::vec3 getAxis(int i) const
        {
            return glm::rotate(Orientation, glm::vec3(i == 0, i == 1, i == 2));
        }

        glm::vec3 calculateCollisionNormal(const OBB& other) const
        {
            glm::vec3 relativePos = other.Pos - Pos;

            int minAxis = 0;
            float minPenetration = calculatePenetrationDepth(other, getAxis(0));
            for (int i = 1; i < 3; ++i) {
                float penetration = calculatePenetrationDepth(other, getAxis(i));
                if (penetration < minPenetration) {
                    minPenetration = penetration;
                    minAxis = i;
                }
            }
            return getAxis(minAxis);
        }
        float calculatePenetrationDepth(const OBB& other, const glm::vec3 axis) const
        {
            glm::vec3 relativePos = other.Pos - Pos;
            return Half_size.x + other.Half_size.x - glm::abs(glm::dot(relativePos, axis));
        }
    };
}
#endif // !COLLISION_H
