// ---------------------------------------------------------------------------

#ifndef Model_with_MatricesH
#define Model_with_MatricesH
// ---------------------------------------------------------------------------
#include <vector>
#include <cstring>
#include "AbstractModel.h"

#define DIMENSIONS 2
#define MATRIX_SIZE (DIMENSIONS+1)

namespace model {

	using namespace std;

	class Model_with_Matrices : public AbstractModel {
	private:
		typedef float Matrix[MATRIX_SIZE][MATRIX_SIZE];

		// | scale_x * cos(a)   scale_x * -sin(a)  0 |
		// | scale_y * sin(a)   scale_y * cos(a)   0 |
		// | trans_x            trans_y            1 |
		Matrix transformMatrix;

		float rotateAngleRad;
		float scale[DIMENSIONS];

		void transformPoint(pair<int, int>&) const ;

		void untransformPoint(pair<int, int>&point) const {
			// leaving currently as is, still TODO
		};

		void updateTransformMatrix() {
			float cos_a = cos(rotateAngleRad);
			float sin_a = sin(rotateAngleRad);
			transformMatrix[0][0] = scale[0] * cos_a;
			transformMatrix[0][1] = scale[0]*(-sin_a);
			transformMatrix[1][0] = scale[1] * sin_a;
			transformMatrix[1][1] = scale[1] * cos_a;
		};

	public:
		Model_with_Matrices() {
			scale[0] = 1;
			scale[1] = 1;

			// build identity matrix assuming MATRIX_SIZE == 3
			memset(&transformMatrix, 0, sizeof(Matrix));
			transformMatrix[0][0] = 1;
			transformMatrix[1][1] = 1;
			transformMatrix[2][2] = 1;
		};

		void adjustTranslate(axis, int value);
		void adjustScale(axis, float value);
		void adjustRotation(float value);
	};

}

// ---------------------------------------------------------------------------
#endif
