#ifndef CONSTRAINEDMOTION_H
#define CONSTRAINEDMOTION_H

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <FL/Fl.H>

#include "modelerglobals.h"
#include "modelerapp.h"
#include "vec.h"
#include "mat.h"

#define SEARCH_STEP 10

class ConstrainedMotion
{
public:
	ConstrainedMotion() {}
	void moveArms(double targetX, double targetY, double targetZ);
private:
	void translation(const float vx, const float vy, const float vz, Mat4f& m);
	void rotation(const int a, char n, Mat4f& m);
};

#endif
#pragma once
