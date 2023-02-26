#include "SelectionSortEngine.h"

SelectionSortEngine::SelectionSortEngine(array<int>^% arr) : SortEngine(arr) {}

// Знаходження індексу найменшого елементу масиву в межах [left; right]
int SelectionSortEngine::getIdxOfMinElement(int left, int right) {
	int minIdx{ left };

	for (int i{ left + 1 }; i <= right; ++i) {
		++comparisonsCount_;
		if (arr_[i] < arr_[minIdx]) {
			minIdx = i;
		}
	}

	return minIdx;
}

void SelectionSortEngine::sort() {
	int currMinIdx{ 0 };

	for (int i{ 0 }; i < arr_->Length; ++i) {
		currMinIdx = getIdxOfMinElement(i, arr_->Length - 1);
		++swapsCount_;
		swap(i, currMinIdx);
	}
}