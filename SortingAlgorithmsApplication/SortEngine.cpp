#include "SortEngine.h"

long long SortEngine::getComparisonsCount() { return comparisonsCount_; }

long long SortEngine::getSwapsCount() { return swapsCount_; }

SortEngine::SortEngine(array<int>^% arr) : swapsCount_{ 0 }, comparisonsCount_{ 0 } {

	arr_ = arr;
}

int SortEngine::sortingTest() {
	
	int firstUnsortedIdx{ -1 };
	for (int i{ 1 }; i < arr_->Length; ++i) {
		if (arr_[i - 1] > arr_[i]) {
			return i;
		}
	}

	return firstUnsortedIdx;
}

void SortEngine::swap(int i, int j) {
	int temp = arr_[i];
	arr_[i] = arr_[j];
	arr_[j] = temp;
}