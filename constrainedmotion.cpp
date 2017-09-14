#include "constrainedmotion.h"

void ConstrainedMotion::moveArms(double targetX, double targetY, double targetZ) {
	Vec3f target(targetX, targetY, targetZ);
	double minDistance = 100;
	int x1, y1, z1, x2;
	int x1m, y1m, z1m, x2m;
	for (x1 = -30; x1 <= 180; x1 += SEARCH_STEP) {
		for (y1 = -30; y1 <= 60; y1 += SEARCH_STEP) {
			for (z1 = 0; z1 <= 120; z1 += SEARCH_STEP) {
				for (x2 = -10; x2 <= 120; x2 += SEARCH_STEP) {
						Mat4f m;
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								m[i][j] = 0;
							}
						}
						for (int i = 0; i < 4; i++) m[i][i] = 1;
						translation(SHOULDER_RADIUS + 0.2f, 0.8f, 0, m);
						rotation(-x1, 'x', m);
						rotation(-y1, 'y', m);
						rotation(z1, 'z', m);
						rotation(20, 'z', m);
						translation(0, -UPPERARM_LENGTH, 0, m);
						rotation(-20, 'z', m);
						rotation(-x2, 'x', m);
						translation(0, -1.4, 0, m);
						Vec3f dv = Vec3f(m[0][3], m[1][3], m[2][3]) - target;
						if (dv.length() < minDistance) {
							minDistance = dv.length();
							x1m = x1;
							y1m = y1;
							z1m = z1;
							x2m = x2;
						}
				}
			}
		}
	}

	SETVAL(RIGHTARMX, x1m);
	SETVAL(RIGHTARMY, y1m);
	SETVAL(RIGHTARMZ, z1m);
	SETVAL(RIGHTELBOWX, x2m);

	minDistance = 100;
	for (x1 = -30; x1 <= 180; x1 += SEARCH_STEP) {
		for (y1 = -60; y1 <= 30; y1 += SEARCH_STEP) {
			for (z1 = -120; z1 <= 0; z1 += SEARCH_STEP) {
				for (x2 = -10; x2 <= 120; x2 += SEARCH_STEP) {
						Mat4f m;
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								m[i][j] = 0;
							}
						}
						for (int i = 0; i < 4; i++) m[i][i] = 1;
						translation(-SHOULDER_RADIUS - 0.2f, 0.8f, 0, m);
						rotation(-x1, 'x', m);
						rotation(-y1, 'y', m);
						rotation(z1, 'z', m);
						rotation(-20, 'z', m);
						translation(0, -UPPERARM_LENGTH, 0, m);
						rotation(+20, 'z', m);
						rotation(-x2, 'x', m);
						translation(0, -1.4, 0, m);
						Vec3f dv = Vec3f(m[0][3], m[1][3], m[2][3]) - target;
						if (dv.length() < minDistance) {
							minDistance = dv.length();
							x1m = x1;
							y1m = y1;
							z1m = z1;
							x2m = x2;
						}
				}
			}
		}
	}

	SETVAL(LEFTARMX, x1m);
	SETVAL(LEFTARMY, y1m);
	SETVAL(LEFTARMZ, z1m);
	SETVAL(LEFTELBOWX, x2m);
	Fl::redraw();
}

void ConstrainedMotion::translation(const float vx, const float vy, const float vz, Mat4f & m)
{
	Vec4f nv = m*Vec4f(vx, vy, vz, 1);
	for (int i = 0; i < 4; i++) m[i][3] = nv[i];
}

void ConstrainedMotion::rotation(const int a, char n, Mat4f& m)
{
	Mat4f mr;
	float r = M_PI * a / 180;
	mr[3][3] = 1;
	switch (n) {
		case 'x': {
			mr[0][0] = 1;
			mr[1][1] = cos(r);
			mr[1][2] = -sin(r);
			mr[2][1] = -mr[1][2];
			mr[2][2] = mr[1][1];
			break;
		}
		case 'y': {
			mr[1][1] = 1;
			mr[0][0] = cos(r);
			mr[0][2] = sin(r);
			mr[2][0] = -mr[0][2];
			mr[2][2] = mr[0][0];
			break;
		}
		case 'z': {
			mr[2][2] = 1;
			mr[0][0] = cos(r);
			mr[0][1] = -sin(r);
			mr[1][0] = -mr[0][1];
			mr[1][1] = mr[0][0];
			break;
		}
		default: break;
	};
	mr = mr*m;
	for (int i = 0; i < 3; i++) mr[i][3] = m[i][3];
	m = mr;
}
