#include "HeapSortEngine.h"

HeapSortEngine::HeapSortEngine(array<int>^% arr) : SortEngine(arr) {}

int HeapSortEngine::getRightChildIdx(int rootIdx) {
	return (2 * rootIdx + 2);
}

int HeapSortEngine::getLeftChildIdx(int rootIdx) {
	return (2 * rootIdx + 1);
}

void HeapSortEngine::heapify(int heapSize, int rootIdx) {
	int maxIdx{ rootIdx };

	while (heapSize > rootIdx) {
		int leftChildIdx{ getLeftChildIdx(rootIdx) };
		if (leftChildIdx < heapSize) {
			++comparisonsCount_;
			if (arr_[leftChildIdx] > arr_[maxIdx]) {
				maxIdx = leftChildIdx;
			}
		}

		int rightChildIdx{ getRightChildIdx(rootIdx) };
		if (rightChildIdx < heapSize) {
			++comparisonsCount_;
			if (arr_[rightChildIdx] > arr_[maxIdx]) {
				maxIdx = rightChildIdx;
			}
		}

		if (maxIdx != rootIdx) {
			++swapsCount_;
			swap(maxIdx, rootIdx);

			rootIdx = maxIdx;
		}
		else {
			break;
		}
	}
}

void HeapSortEngine::buildHeap() {
	for (int i{ arr_->Length / 2 - 1 }; i >= 0; --i) {
		heapify(arr_->Length, i);
	}
}

void HeapSortEngine::sort() {

	buildHeap();

	for (int i{ arr_->Length - 1 }; i > 0; --i) {
		++swapsCount_;
		swap(i, 0);

		heapify(i, 0);
	}
}