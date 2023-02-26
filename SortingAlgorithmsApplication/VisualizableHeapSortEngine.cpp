#include "VisualizableHeapSortEngine.h"

VisualizableHeapSortEngine::VisualizableHeapSortEngine(array<int>^% arr, int maxVal) : HeapSortEngine(arr) {
	
	svf_ = gcnew SortingAlgorithmsApplication::SortingVisualizerForm(arr, maxVal);
}

VisualizableHeapSortEngine::~VisualizableHeapSortEngine() {
	delete svf_;
}

void VisualizableHeapSortEngine::heapify(int heapSize, int rootIdx) {
	int maxIdx{ rootIdx };

	while (heapSize > rootIdx) {
		int leftChildIdx{ getLeftChildIdx(rootIdx) };
		if (leftChildIdx < heapSize) {
			svf_->visualizeComparison(leftChildIdx, maxIdx);
			++comparisonsCount_;
			if (arr_[leftChildIdx] > arr_[maxIdx]) {
				maxIdx = leftChildIdx;
			}
		}

		int rightChildIdx{ getRightChildIdx(rootIdx) };
		if (rightChildIdx < heapSize) {
			svf_->visualizeComparison(rightChildIdx, maxIdx);
			++comparisonsCount_;
			if (arr_[rightChildIdx] > arr_[maxIdx]) {
				maxIdx = rightChildIdx;
			}
		}

		if (maxIdx != rootIdx) {
			++swapsCount_;
			swap(maxIdx, rootIdx);
			svf_->visualizeSwap(maxIdx, rootIdx);

			rootIdx = maxIdx;
		}
		else {
			break;
		}
	}
}

void VisualizableHeapSortEngine::sort() {
	svf_->Show();

	svf_->visualizeArray();

	buildHeap();

	for (int i{ arr_->Length - 1 }; i > 0; --i) {
		++swapsCount_;
		swap(i, 0);
		svf_->visualizeSwap(i, 0);

		heapify(i, 0);
	}

	svf_->visualizeSortingTest(sortingTest());

	svf_->Close();
}