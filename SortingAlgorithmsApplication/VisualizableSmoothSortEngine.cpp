#include "VisualizableSmoothSortEngine.h"

VisualizableSmoothSortEngine::VisualizableSmoothSortEngine(array<int>^% arr, int maxVal) : SmoothSortEngine(arr) {
    svf_ = gcnew SortingAlgorithmsApplication::SortingVisualizerForm(arr, maxVal);

    calculateLeoNums();
}

VisualizableSmoothSortEngine::~VisualizableSmoothSortEngine() {
    delete svf_;
}

void VisualizableSmoothSortEngine::siftDown(int heapLeoNumIdx, int rootIdx) {
    int currNodeIdx = rootIdx;

    while (heapLeoNumIdx >= 2)
    {
        int maxIdx = currNodeIdx;
        int prevHeapLeoNumIdx{ heapLeoNumIdx };

        int rightChildIdx = currNodeIdx - 1;
        svf_->visualizeComparison(rightChildIdx, maxIdx);
        ++comparisonsCount_;
        if (arr_[rightChildIdx] > arr_[maxIdx]) {
            prevHeapLeoNumIdx = heapLeoNumIdx - 2;
            maxIdx = rightChildIdx;
        }

        int leftChildIdx = rightChildIdx - leoNums[heapLeoNumIdx - 2];
        svf_->visualizeComparison(rightChildIdx, maxIdx);
        ++comparisonsCount_;
        if (arr_[leftChildIdx] > arr_[maxIdx]) {
            prevHeapLeoNumIdx = heapLeoNumIdx - 1;
            maxIdx = leftChildIdx;
        }

        if (currNodeIdx != maxIdx) {
            ++swapsCount_;
            swap(currNodeIdx, maxIdx);
            svf_->visualizeSwap(currNodeIdx, maxIdx);
            heapLeoNumIdx = prevHeapLeoNumIdx;
            currNodeIdx = maxIdx;
        }
        else {
            break;
        }
    }
}

void VisualizableSmoothSortEngine::findMaxAmongRoots(uint64_t currState, int lastRootIdx, int* heapLeoNumIdx, int* maxRootIdx) {
    int currHeapLeoNumIdx{ 0 };
    while (!(currState & 1)) {
        currState >>= 1;
        currHeapLeoNumIdx++;
    }

    *maxRootIdx = lastRootIdx;
    *heapLeoNumIdx = currHeapLeoNumIdx;
    int currRootIdx{ lastRootIdx - leoNums[currHeapLeoNumIdx] };

    currState >>= 1;
    currHeapLeoNumIdx++;
    while (currState) {
        if (currState & 1) {
            ++comparisonsCount_;
            svf_->visualizeComparison(currRootIdx, *maxRootIdx);
            if (arr_[currRootIdx] > arr_[*maxRootIdx]) {
                *maxRootIdx = currRootIdx;
                *heapLeoNumIdx = currHeapLeoNumIdx;
            }
            currRootIdx -= leoNums[currHeapLeoNumIdx];
        }
        currState >>= 1;
        currHeapLeoNumIdx++;
    }
}

void VisualizableSmoothSortEngine::sort() {
    svf_->Show();

    svf_->visualizeArray();

    uint64_t currState{ 0 };
    buildHeapPool(&currState);

    for (int i{ (int)arr_->Length - 1 }; i >= 0; --i) {
        int heapLeoNumIdx{ -1 };
        int maxRootIdx{ 0 };
        findMaxAmongRoots(currState, i, &heapLeoNumIdx, &maxRootIdx);

        if (maxRootIdx != i) {
            ++swapsCount_;
            swap(i, maxRootIdx);
            svf_->visualizeSwap(i, maxRootIdx);
            siftDown(heapLeoNumIdx, maxRootIdx);
        }
        calculatePrevState(&currState);
    }

    svf_->visualizeSortingTest(sortingTest());

    svf_->Close();
}