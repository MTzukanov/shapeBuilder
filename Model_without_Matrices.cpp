// ---------------------------------------------------------------------------
#include <algorithm>
#include <math.h>
#pragma hdrstop

#include "Model_without_Matrices.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace model;

void Model_without_Matrices::adjustTranslate(axis a, int value) {
	switch (a) {
	case axis::X:
		translateValue.first += value;
		break;
	case axis::Y:
		translateValue.second += value;
		break;
	}
}

void Model_without_Matrices::adjustScale(axis a, float value) {
	switch (a) {
	case axis::X:
		scaleValue.first += value;
		break;
	case axis::Y:
		scaleValue.second += value;
		break;
	}
}

void Model_without_Matrices::adjustRotation(float value) {
	rotateValue += value;
}

void Model_without_Matrices::transformPoint(pair<int, int> &point) const {
	translatePoint(point);
	scalePoint(point);
	rotatePoint(point);
}

void Model_without_Matrices::translatePoint(pair<int, int> &point) const {
	point.first += translateValue.first;
	point.second += translateValue.second;
}

void Model_without_Matrices::scalePoint(pair<int, int> &point) const {
	point.first *= scaleValue.first;
	point.second *= scaleValue.second;
}

void Model_without_Matrices::rotatePoint(pair<int, int> &point) const {
	const int x = point.first, y = point.second;
	const float sinValue = sin(rotateValue);
	const float cosValue = cos(rotateValue);
	point.first = x * cosValue - y * sinValue;
	point.second = y * cosValue + x * sinValue;
}

