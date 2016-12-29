// ---------------------------------------------------------------------------

#ifndef AbstractModelH
#define AbstractModelH
// ---------------------------------------------------------------------------
#include <vector>

namespace model {

	using namespace std;

	enum class axis {
		X, Y
	};

	class AbstractModel {
	private:
		vector<pair<int, int> >points;

		// transforms the point according to current values
		virtual void transformPoint(pair<int, int>&) const = 0;

		// transforms the point back from the transformed space original
		virtual void untransformPoint(pair<int, int>&) const = 0;

	public:
		virtual ~AbstractModel() {};

		virtual void addPoint(int x, int y) {
			pair<int, int>point(x, y);
			untransformPoint(point);
			points.push_back(point);
		}

		virtual void adjustTranslate(axis, int value) = 0;
		virtual void adjustScale(axis, float value) = 0;
		virtual void adjustRotation(float value) = 0;

		virtual void reset() {
			points.clear();
			// TODO: need also to reset space
		};

		const vector<pair<int, int> >getTransformedPoints() const ;
	};
}

// ---------------------------------------------------------------------------
#endif
