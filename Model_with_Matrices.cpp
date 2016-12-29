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
	const int new_x = p.first * m[0][0] + p.second * m[1][0] + m[2][0];
	const int new_y = p.first * m[0][1] + p.second * m[1][1] + m[2][1];

	p.first = new_x;
	p.second = new_y;
}

void Model_with_Matrices::untransformPoint(pair<int, int> &p) const {
	// only for readabily
	const Matrix &m = transformMatrix;

	// first undo translation
	p.first -= m[2][0];
	p.second -= m[2][1];

	// undo scale and rotate
	// multiply by inverse 2x2 matrix, using formula 1/detA * [[d,-b][-c, a]]
	const float a = m[0][0], b = m[0][1], c = m[1][0], d = m[1][1];
	const float detInv = 1.0f / (a * d - b * c);

	const int new_x = detInv * (p.first * d + p.second*-c);
	const int new_y = detInv * (p.first*-b + p.second * a);

	p.first = new_x;
	p.second = new_y;
}
