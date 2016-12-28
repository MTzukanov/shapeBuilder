// ---------------------------------------------------------------------------

#ifndef Model_with_MatricesH
#define Model_with_MatricesH
// ---------------------------------------------------------------------------
#include <vector>
#include "AbstractModel.h"

#define MATRIX_SIZE 3

namespace model {

	using namespace std;

	class Model_with_Matrices : public AbstractModel {
	private:
		float transformMatrix[MATRIX_SIZE][MATRIX_SIZE];

		void transformPoint(pair<int, int>&) const ;

		void untransformPoint(pair<int, int>&point) const {
			// leaving currently as is, still TODO
		};

	public:
		Model_with_Matrices() {
			fill_n((float*)transformMatrix, MATRIX_SIZE*MATRIX_SIZE, 0);
            // build identity matrix assuming MATRIX_SIZE == 3
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
