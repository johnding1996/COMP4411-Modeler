#include "Metaball.h"


MetaBallSystem::MetaBallSystem(float rad, float thres) {
	radius = rad;
	threshold = thres;
}

void MetaBallSystem::grid() {
	//set up grid
	cubeGrid.CreateMemory();
	cubeGrid.Init(GRID_SIZE);
}

void MetaBallSystem::makeMetaballs() {
	// make metaball matirx
	int counter = 0;
	float dx = (X_MAX - X_MIN) / (NUM_X - 1);
	float dy = (Y_MAX - Y_MIN) / (NUM_Y - 1);
	float dz = (Z_MAX - Z_MIN) / (NUM_Y - 1);
	for (int j = 0; j < NUM_Y; j++) {
		for (int i = 0; i < NUM_X; i++) {
			metaballs[counter].initialize(Vec3f(X_MIN + dx * i, Y_MIN + j * dy, Z_MIN + j * dz), radius*radius);
			++counter;
		}
	}

}

void MetaBallSystem::evaluationField() {
	// clear the data
	for (int i = 0; i<cubeGrid.numVertices; i++) {
		cubeGrid.vertices[i].value = 0.0f;
		cubeGrid.vertices[i].normal.zeroElements();
	}

	// evaluate the field at each point
	Vec3f ballToPoint;
	float squaredRadius;
	Vec3f ballPosition;
	float normalScale;
	for (int i = 0; i<NUM_X*NUM_Y; i++) {
		squaredRadius = metaballs[i].squaredRadius;
		ballPosition = metaballs[i].position;

		for (int j = 0; j<cubeGrid.numVertices; j++) {
			ballToPoint = cubeGrid.vertices[j].position - ballPosition;
			float squaredDistance = ballToPoint.length2();
			// field value is r^2/d^2
			cubeGrid.vertices[j].value += squaredRadius / squaredDistance;
			// normal scale is r^2/d^4
			normalScale = squaredRadius / (squaredDistance*squaredDistance);
			cubeGrid.vertices[j].normal += ballToPoint * normalScale;
		}
	}
}

void MetaBallSystem::draw() {
	cubeGrid.DrawSurface(threshold);
}
