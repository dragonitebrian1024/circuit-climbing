#pragma once
#include "Collision.h"
#include "Physics.h"
//if leave chasingOffset NULL if you don't have a second set of chasing variables because i added this just for my program
void Chaser(float& chasedx, float& chasedy,float& chasingOffsetx, float& chasingOffsetY ,float& chasingx, float& chasingy, float speed) {
    glm::vec2 directionToPlayer = glm::normalize(glm::vec2(chasedx, chasedy) - glm::vec2(chasingx, chasingy));
    chasingx += directionToPlayer.x * speed;
    chasingy += directionToPlayer.y * speed;
    chasingOffsetx += directionToPlayer.x * speed;
    chasingOffsetY += directionToPlayer.y * speed;
}
//example of a one-use only function which this engine will not be using
/*//0 for up 1 for down 2 for right 3 for left
int Spawn(float& EnemyOffsetX, float& EnemyOffsetY, float& Enemyx, float& Enemyy) {
    int gorp = rand() % 4;
    if (gorp == 0) {
        Enemyy = 1.15f;
        EnemyOffsetY = 1.395f;
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::default_random_engine generator1(rd());// rd() provides a random seed
        std::uniform_real_distribution<float> distribution(0.005f, -0.79f);
        Enemyx = distribution(generator);

        EnemyOffsetX = Enemyx + 0.36;

    }
    else if (gorp == 1) {
        Enemyy = -0.446f;
        EnemyOffsetY = -0.206f;
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::default_random_engine generator1(rd());// rd() provides a random seed
        std::uniform_real_distribution<float> distribution(0.005f, -0.79f);
        Enemyx = distribution(generator);

        EnemyOffsetX = Enemyx + 0.36;

    }
    else if (gorp == 2) {
        Enemyx = 0.005f;
        EnemyOffsetX = 0.365f;
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::default_random_engine generator1(rd());// rd() provides a random seed
        std::uniform_real_distribution<float> distribution(-0.446f, 1.15f);
        Enemyy = distribution(generator);
        EnemyOffsetY = Enemyy + 0.24;
    }
    else if (gorp == 3) {
        Enemyx = -0.79f;
        EnemyOffsetX = -0.46f;
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::default_random_engine generator1(rd());// rd() provides a random seed
        std::uniform_real_distribution<float> distribution(-0.446f, 1.15f);
        Enemyy = distribution(generator);
        EnemyOffsetY = Enemyy + 0.24;
    }
    return gorp;
};*/