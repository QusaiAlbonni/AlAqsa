#include "Collision.h"
#include "audio.h"

const Collision::AABB Collision::cameraAABB =
{
    glm::vec3(camera.Position.x - 0.4f, 0, camera.Position.z - 0.4f),
     glm::vec3(camera.Position.x + 0.4f, 1.8f, camera.Position.z + 0.4f)
};


bool Collision::CollisionDetector::checkAABBCollision(const AABB box1, const AABB box2, glm::vec3& collisionNormal, float& penetrationDepth)
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

bool Collision::CollisionDetector::check(glm::vec3 &normal, float &depth)
{
    AABB box1 = { {-45.0f, 0, -20.1f},{-35.0f,2.0f, -17.0f} };
    AABB box2 =
    {
        glm::vec3(camera.Position.x - 0.4f, 0, camera.Position.z - 0.4f),
         glm::vec3(camera.Position.x + 0.4f, 1.8f, camera.Position.z + 0.4f)
    };

    if (checkAABBCollision(box1, box2, normal, depth))
    {
        return true;
    }
    else
        return  false;
    
}

bool Collision::CollisionDetector::enteredDome()
{
    AABB box1 = { {-45.0f, 0, -17.01f},{-35.0f,2.0f, -17.0f} };
    AABB box2 =
    {
        glm::vec3(camera.Position.x - 0.4f, 0, camera.Position.z - 0.4f),
         glm::vec3(camera.Position.x + 0.4f, 1.8f, camera.Position.z + 0.4f)
    };
    glm::vec3 inormal;
    float idepth;

    if (checkAABBCollision(box1, box2, inormal, idepth))
    {
        return true;
    }
    else
        return  false;
}

bool Collision::CollisionDetector::updateCamPos()
{
    if (camera.fps)
    {
        AABB box1 = { {-85.0f, 0, -90.01f},{25.0f,1.0f, 20.0f} };
        AABB box2 =
        {
            glm::vec3(camera.Position.x - 0.4f, 0, camera.Position.z - 0.4f),
             glm::vec3(camera.Position.x + 0.4f, 1.8f, camera.Position.z + 0.4f)
        };
        glm::vec3 inormal;
        float idepth;

        if (checkAABBCollision(box1, box2, inormal, idepth))
        {
            camera.Position.y = 2.5f;
        }
        else {
            camera.Position.y = 1.5f;
        }
        return true;
    }
    else
        return false;
}

bool Collision::CollisionDetector::checkPlayerCol(glm::vec3& normal, float& depth)
{
    bool col = false;

    AABB box1 = { {-100.0f, 0, -152.1f},{100.0f,2.0f, -150.0f} };
    AABB cam =
    {
        glm::vec3(camera.Position.x - 0.4f, 0, camera.Position.z - 0.4f),
         glm::vec3(camera.Position.x + 0.4f, 1.8f, camera.Position.z + 0.4f)
    };

    if (checkAABBCollision(box1, cam, normal, depth))
    {
        col = true;
    }
    
    AABB box2 = { {+99.0f, 0, -150.1f},{+102.0f,2.0f, 150.0f} };
    if (checkAABBCollision(box2, cam, normal, depth))
    {
        col = true;
    }
    
    AABB box3 = { {-102.0f, 0, -150.0f},{-99.0f,2.0f, 150.0f} };
    if (checkAABBCollision(box3, cam, normal, depth))
    {
        col = true;
    }
    
    AABB box4 = { {-100.0f, 0, +149.1f},{100.0f,2.0f, 152.0f} };
    if (checkAABBCollision(box4, cam, normal, depth))
    {
        col = true;
    }


    AABB box5 = { {-43.0f, 0, -12.1f},{-42.0f,2.0f, -11.0f} };
    if (checkAABBCollision(box5, cam, normal, depth))
    {
        col = true;
    }

    AABB box6 = { {-38.0f, 0, -12.1f},{-37.0f,2.0f, -11.0f} };
    if (checkAABBCollision(box6, cam, normal, depth))
    {
        col = true;
    }
    AABB box7 = { {-37.0f, 0, -17.1f},{-30.0f,2.0f, -16.0f} };
    if (checkAABBCollision(box7, cam, normal, depth))
    {
        col = true;
    }
    AABB box8 = { {-50.0f, 0, -17.1f},{-43.0f,2.0f, -16.0f} };
    if (checkAABBCollision(box8, cam, normal, depth))
    {
        col = true;
    }

    
    return col;


}
