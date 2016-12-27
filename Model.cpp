// ---------------------------------------------------------------------------
#include <algorithm>
#include <math.h>
#pragma hdrstop

#include "Model.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace model;

void Model::adjustTranslate(axis a, int value) {
	switch (a) {
	case axis::X:
		translateValue.first += value;
		break;
	case axis::Y:
		translateValue.second += value;
		break;
	}
}

void Model::adjustScale(axis a, float value) {
	switch (a) {
	case axis::X:
		scaleValue.first += value;
		break;
	case axis::Y:
		scaleValue.second += value;
		break;
	}
}

void Model::adjustRotation(float value) {
	rotateValue += value;
}

void Model::transformPoint(pair<int, int> &point) const {
	translatePoint(point);
	scalePoint(point);
	rotatePoint(point);
}

void Model::translatePoint(pair<int, int> &point) const {
	point.first += translateValue.first;
	point.second += translateValue.second;
}

void Model::scalePoint(pair<int, int> &point) const {
	point.first *= scaleValue.first;
	point.second *= scaleValue.second;
}

void Model::rotatePoint(pair<int, int> &point) const {
	const int x = point.first, y = point.second;
	const float sinValue = sin(rotateValue);
	const float cosValue = cos(rotateValue);
	point.first = x * cosValue - y * sinValue;
	point.second = y * cosValue + x * sinValue;
}

const vector<pair<int, int> >Model::getTransformedPoints() const {
	vector<pair<int, int> >copy(points);

	vector<pair<int, int> >::iterator currentPoint = copy.begin();

	while (currentPoint != copy.end()) {
		transformPoint(*currentPoint);
		currentPoint++;
	}

	return copy;
}
