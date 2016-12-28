// ---------------------------------------------------------------------------
#include <algorithm>
#include <math.h>
#pragma hdrstop

#include "AbstractModel.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace model;

const vector<pair<int, int> >AbstractModel::getTransformedPoints() const {
	vector<pair<int, int> >copy(points);

	vector<pair<int, int> >::iterator currentPoint = copy.begin();

	while (currentPoint != copy.end()) {
		transformPoint(*currentPoint);
		currentPoint++;
	}

	return copy;
}
