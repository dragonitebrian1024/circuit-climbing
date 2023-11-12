#pragma once
#include "Shader.h"
#include <glm.hpp>

struct AABB {
	glm::vec2 min;
	glm::vec2 max;
};

static bool CheckAABBCollision(const AABB& a1, const AABB& a2) {
	return (a1.min.x <= a2.max.x && a1.max.x >= a2.min.x) &&
		(a1.min.y <= a2.max.y && a1.max.y >= a2.min.y);
}
