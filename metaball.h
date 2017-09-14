#include "CUBE_GRID.h"
#include "vec.h"

#ifndef _METABALL_H
#define _METABALL_H

#define GRID_SIZE 20
#define NUM_X 2
#define NUM_Y 3
#define X_MIN -0.3f
#define X_MAX 0.3f
#define Y_MIN -1.0f
#define Y_MAX 0.0f
#define Z_MIN 0.4f
#define Z_MAX 0.4f

class MetaBalls {
public:
	Vec3f position;
	float squaredRadius;
	inline void initialize(Vec3f posi, float sRad)
	{
		position = posi;
		squaredRadius = sRad;
	}
};

class MetaBallSystem {
public:
	MetaBallSystem(float rad, float thres);
	void grid();
	void makeMetaballs();
	void evaluationField();
	void draw();

private:
	float threshold;
	float radius;
	CUBE_GRID cubeGrid;
	MetaBalls metaballs[NUM_X * NUM_Y];
};

#endif