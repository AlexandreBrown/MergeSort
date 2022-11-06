#include <cmath>
#include "MergeSortAlgorithm.h"

using namespace std;

void MergeSortAlgorithm::sort(vector<int>& a) const {
	if (a.size() > 1) {
		auto leftRight = divide(a);
		sort(leftRight.first);
		sort(leftRight.second);
		merge(leftRight.first, leftRight.second, a);
	}
}

pair<vector<int>, vector<int>> MergeSortAlgorithm::divide(vector<int>& a) const {
	int median = floor(a.size()/2);

	vector<int> left;
	for (int i = 0; i < median; ++i) {
		left.push_back(a[i]);
	}

	vector<int> right;
	for (int i = median; i < a.size(); ++i) {
		right.push_back(a[i]);
	}

	return make_pair(left, right);
}

void MergeSortAlgorithm::merge(vector<int>& left, vector<int>& right, vector<int>& a) const {
	int i = 0;
	int j = 0;
	for (int k = 0; k < a.size(); ++k) {
		if (i < left.size() && (j==right.size() || left[i] < right[j])) {
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
	}
}
