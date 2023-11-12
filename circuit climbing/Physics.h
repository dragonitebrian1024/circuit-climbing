#pragma once
#include "Collision.h"

	//to move while gaining speed and just make a random int variable that equals 0 (like int y = 0) for currentspeed since it is just for calculations and also isMoving must be true for it to move and when it is false currentspeed = 0
void velocity(float startingSpeed, float speedgain, float maxspeed, float& position, float& currentspeed,bool isMoving, bool negative) {
	float total = startingSpeed + currentspeed;
	bool dont = false;

	if (negative == false) {
		if (isMoving == true) {
			if (total <= maxspeed) {
				position += total;
			}
			else if (total >= maxspeed) {
				position += maxspeed;
				dont = true;
			}

		if (dont != true && total <= maxspeed)
			currentspeed += speedgain;
		}
		else if (isMoving == false) {
			currentspeed = 0.0f;
			total = 0;
		}
	}

	else if (negative == true) {
		if (isMoving == true) {
			if (total >= maxspeed) {
				position += total;
			}
			else if (total <= maxspeed) {
				position += maxspeed;
				dont = true;
			}

		if (dont != true && total >= maxspeed)
			currentspeed += speedgain;
		}
		else if (isMoving == false) {
			currentspeed = 0.0f;
			total = 0;
		}
	}
}

void bounce(float startingSpeed, float speedgain, float maxspeed, float& position, float& currentspeed, bool isMoving, bool negative, float bouncespeed, AABB object, AABB platform) {
	bool reverse = false;
	if (CheckAABBCollision(object, platform) == true) {
		currentspeed = bouncespeed;
		reverse = true;
	}
	else if (CheckAABBCollision(object, platform) == false) {
		reverse = false;
	}
	if (reverse == false) {
	    velocity(startingSpeed, speedgain, maxspeed, position, currentspeed, isMoving, negative);
	}
	else if (reverse == true) {
		velocity(-startingSpeed, -speedgain, -maxspeed, position, currentspeed, isMoving, negative);
	}

}


void SineWave(float howbigisawave, float& positionthatwillchange, float speed, const float initialposition) {
	bool reverse;
	if (positionthatwillchange > initialposition + howbigisawave)
		reverse = true;
	else if (positionthatwillchange < initialposition - howbigisawave)
		reverse = false;

	if (reverse == false)
		positionthatwillchange += speed;
	else
		positionthatwillchange -= speed;
}

