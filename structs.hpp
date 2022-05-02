#pragma once
#include "Includes.h"

#ifndef structs
#define structs
struct Vector3 {
	float x, y, z;

	Vector3 operator+(Vector3 o) {
		return Vector3{ x + o.x, y + o.y, z + o.z };
	}

	Vector3 operator-(Vector3 o) {
		return Vector3{x - o.x, y - o.y, z - o.z};
	}

	Vector3 operator*(float n) {
		return Vector3{x * n, y * n, z * n};
	}

	void Normalize() {
		while (y < -180) { y += 360; }
		while (y > 180) { y -= 360; }
		if (x > 89) { x = 89; }
		if (x < -89) { x = -89; }
	}

};
#endif