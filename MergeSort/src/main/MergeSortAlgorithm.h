#ifndef GTESTSETUP_MergeSortAlgorithm_H
#define GTESTSETUP_MergeSortAlgorithm_H

#include <vector>

class MergeSortAlgorithm {
	public:

		void sort(std::vector<int>& a) const;

	private:
		std::pair<std::vector<int>, std::vector<int>> divide(std::vector<int>& a) const;

		void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& a) const;
};

#endif
