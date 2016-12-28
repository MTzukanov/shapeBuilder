// ---------------------------------------------------------------------------
#include <algorithm>
#include <math.h>
#pragma hdrstop

#include "Model_with_Matrices.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace model;

void Model_with_Matrices::adjustTranslate(axis a, int value) {
	// switch (a) {
	// case axis::X:
	// translateValue.first += value;
	// break;
	// case axis::Y:
	// translateValue.second += value;
	// break;
	// }
}

void Model_with_Matrices::adjustScale(axis a, float value) {
	// switch (a) {
	// case axis::X:
	// scaleValue.first += value;
	// break;
	// case axis::Y:
	// scaleValue.second += value;
	// break;
	// }
}

void Model_with_Matrices::adjustRotation(float value) {
	// rotateValue += value;
}

// myltiplies a vector matrix by a square matrix, the result is in pointMatrix
// assumes target is initialized to 0's
void multiplyMatrix(const float(&pointMatrix)[MATRIX_SIZE],
	const float(&transformMatrix)[MATRIX_SIZE][MATRIX_SIZE],
	float(&target)[MATRIX_SIZE]) {

	// generic algorithm, can be optimized by removing loops assuming MATRIX_SIZE == 3
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			target[i] += pointMatrix[i] * transformMatrix[j][i];
		}
	}

}

void Model_with_Matrices::transformPoint(pair<int, int> &point) const {
	float pointMatrix[MATRIX_SIZE] = {point.first, point.second, 1};
	float target[MATRIX_SIZE] = {0, 0, 0};

	multiplyMatrix(pointMatrix, transformMatrix, target);
}

//void Model_with_Matrices::translatePoint(pair<int, int> &point) const {
//	point.first += translateValue.first;
//	point.second += translateValue.second;
//}
//
//void Model_with_Matrices::scalePoint(pair<int, int> &point) const {
//	point.first *= scaleValue.first;
//	point.second *= scaleValue.second;
//}
//
//void Model_with_Matrices::rotatePoint(pair<int, int> &point) const {
//	const int x = point.first, y = point.second;
//	const float sinValue = sin(rotateValue);
//	const float cosValue = cos(rotateValue);
//	point.first = x * cosValue - y * sinValue;
//	point.second = y * cosValue + x * sinValue;
//}
