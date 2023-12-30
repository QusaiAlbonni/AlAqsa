#include "Collision.h"
#include "audio.h"

bool Collision::CollisionDetector::checkAABBCollision(const AABB& box1, const AABB& box2, glm::vec3& collisionNormal, float& penetrationDepth)
{
    // Calculate overlap on each axis
    float overlapX = std::min(box1.max.x, box2.max.x) - std::max(box1.min.x, box2.min.x);
    float overlapY = std::min(box1.max.y, box2.max.y) - std::max(box1.min.y, box2.min.y);
    float overlapZ = std::min(box1.max.z, box2.max.z) - std::max(box1.min.z, box2.min.z);

    // Check for overlap on all axes
    if (overlapX > 0 && overlapY > 0 && overlapZ > 0) {
        // Determine the axis with the smallest overlap (penetration)
        if (overlapX < overlapY && overlapX < overlapZ) {
            collisionNormal = glm::vec3((box1.min.x < box2.min.x) ? -1.0f : 1.0f, 0.0f, 0.0f);
            penetrationDepth = overlapX;
        }
        else if (overlapY < overlapZ) {
            collisionNormal = glm::vec3(0.0f, (box1.min.y < box2.min.y) ? -1.0f : 1.0f, 0.0f);
            penetrationDepth = overlapY;
        }
        else {
            collisionNormal = glm::vec3(0.0f, 0.0f, (box1.min.z < box2.min.z) ? -1.0f : 1.0f);
            penetrationDepth = overlapZ;
        }

        return true; // Collision detected
    }

    return false;
}

void Collision::CollisionDetector::check()
{
    AABB box1 = { {-5.0f, 0, -5.0f},{5.0f,2.0f, 5.0f} };
    AABB box2 =
    {
        glm::vec3(camera.Position.x - 0.4f, 0, camera.Position.z - 0.4f),
         glm::vec3(camera.Position.x + 0.4f, 1.8f, camera.Position.z + 0.4f)
    };
    glm::vec3 normal;
    float depth;

    if (checkAABBCollision(box1, box2, normal, depth))
    { 
        camera.Position.y = 3.0f;
    }
    else
        camera.Position.y = 1.5f;
    
}
