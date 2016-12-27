// ---------------------------------------------------------------------------

#ifndef ModelH
#define ModelH
// ---------------------------------------------------------------------------
#include <vector>

namespace model {

	using namespace std;

	class Model {
	private:
		vector<pair<int, int> >points;

		pair<int, int>translateValue;

		pair<float, float>scaleValue;

		float rotateValue;

		void transformPoint(pair<int, int>&) const ;

		void translatePoint(pair<int, int>&) const ;
		void scalePoint(pair<int, int>&) const ;
		void rotatePoint(pair<int, int>&) const ;

	public:
		enum class axis {
			X, Y
		};

		Model() : scaleValue(1, 1) {
		};
		// virtual ~Model();

		virtual void addPoint(int x, int y) {
			pair<int, int>point(x, y);

            // here we need transform back or untransform
			transformPoint(point);
			points.push_back(point);
		}

		virtual void adjustTranslate(axis, int value);
		virtual void adjustScale(axis, float value);
		virtual void adjustRotation(float value);

		const vector<pair<int, int> >getTransformedPoints() const ;
	};

}

// ---------------------------------------------------------------------------
#endif
