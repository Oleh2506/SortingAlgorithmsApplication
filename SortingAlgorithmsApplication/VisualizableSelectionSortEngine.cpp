#include "VisualizableSelectionSortEngine.h"

VisualizableSelectionSortEngine::VisualizableSelectionSortEngine(array<int>^% arr, int maxVal) : SelectionSortEngine(arr) {
	
	svf_ = gcnew SortingAlgorithmsApplication::SortingVisualizerForm(arr, maxVal);
}

VisualizableSelectionSortEngine::~VisualizableSelectionSortEngine() {
	delete svf_;
}

int VisualizableSelectionSortEngine::getIdxOfMinElement(int left, int right) {
	int minIdx{ left };

	for (int i{ left + 1 }; i <= right; ++i) {
		++comparisonsCount_;
		svf_->visualizeComparison(i, minIdx);
		if (arr_[i] < arr_[minIdx]) {
			minIdx = i;
		}
	}

	return minIdx;
}

void VisualizableSelectionSortEngine::sort() {
	svf_->Show();

	svf_->visualizeArray();

	int currMinIdx{ 0 };

	for (int i{ 0 }; i < arr_->Length; ++i) {
		currMinIdx = getIdxOfMinElement(i, arr_->Length - 1);

		++swapsCount_;
		swap(i, currMinIdx);
		svf_->visualizeSwap(i, currMinIdx);
	}

	svf_->visualizeSortingTest(sortingTest());

	svf_->Close();
}