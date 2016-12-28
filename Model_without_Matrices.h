// ---------------------------------------------------------------------------

#ifndef Model_without_MatricesH
#define Model_without_MatricesH
// ---------------------------------------------------------------------------
#include <vector>
#include "AbstractModel.h"

namespace model {

	using namespace std;

	class Model_without_Matrices : public AbstractModel {
	private:
		pair<int, int>translateValue;
		pair<float, float>scaleValue;
		float rotateValue;

		void transformPoint(pair<int, int>&) const ;

		void untransformPoint(pair<int, int>&point) const {
            // leaving currently as is, still TODO
		};

		void translatePoint(pair<int, int>&) const ;
		void scalePoint(pair<int, int>&) const ;
		void rotatePoint(pair<int, int>&) const ;

	public:
		Model_without_Matrices() : scaleValue(1, 1) {
		};

		void adjustTranslate(axis, int value);
		void adjustScale(axis, float value);
		void adjustRotation(float value);
	};

}

// ---------------------------------------------------------------------------
#endif
