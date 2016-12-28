// ---------------------------------------------------------------------------
#include <algorithm>
#include <math.h>
#pragma hdrstop

#include "Model_with_Matrices.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace model;

void Model_with_Matrices::adjustTranslate(axis a, int value) {
	transformMatrix[MATRIX_SIZE - 1][a] += value;
}

void Model_with_Matrices::adjustScale(axis a, float value) {
	scale[a] += value;
	updateTransformMatrix();
}

void Model_with_Matrices::adjustRotation(float value) {
	rotateAngleRad += value;
	updateTransformMatrix();
}

void Model_with_Matrices::transformPoint(pair<int, int> &p) const {
    // only for readabily
	const Matrix &m = transformMatrix;

    // multiply p vector by transform matrix
	int new_x = p.first * m[0][0] + p.second * m[1][0] + m[2][0];
	int new_y = p.first * m[0][1] + p.second * m[1][1] + m[2][1];

	p.first = new_x;
	p.second = new_y;
}
