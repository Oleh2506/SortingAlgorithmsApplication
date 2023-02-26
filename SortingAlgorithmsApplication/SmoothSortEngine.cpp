#include "SmoothSortEngine.h"

SmoothSortEngine::SmoothSortEngine(array<int>^% arr) : SortEngine(arr) {
    calculateLeoNums();
}

void SmoothSortEngine::calculateLeoNums() {
    int leo1{ 1 }, leo2{ 1 };

    while (leo1 <= arr_->Length) {
        leoNums.push_back(leo1);

        int temp = leo1;
        leo1 = leo2;
        leo2 += (temp + 1);
    }
}

void SmoothSortEngine::calculateNextState(uint64_t *currState, int *mergedHeapsLeoNumIdx) {

    *mergedHeapsLeoNumIdx = -1;

    // виняткова ситуація
    if ((*currState & 7) == 5) { // currState = x0101 (в двійковому представленні)
        *currState += 3;         // currState = x1000
        *mergedHeapsLeoNumIdx = 3;
    }
    else { // пошук двох послідовних одиничних бітів
        uint64_t firstTwoSideBySideBits = *currState;
        int idx = 0;

        // поки firstTwoSideBySideBits != 0 та firstTwoSideBySideBits != x011
        while (firstTwoSideBySideBits && (firstTwoSideBySideBits & 3) != 3) { 
            firstTwoSideBySideBits >>= 1;
            idx++;
        }

        if ((firstTwoSideBySideBits & 3) == 3) { // firstTwoSideBySideBits = x011
            *currState += (uint64_t(1) << idx);  // currState = x100x
            *mergedHeapsLeoNumIdx = idx + 2;
        }
        else {
            if (*currState & 1) { // currState = x001
                *currState |= 2;  // currState = x011
            }
            else {                // currState = xx00
                *currState |= 1;  // currState = xx01
            }
        }
    }
}

void SmoothSortEngine::calculatePrevState(uint64_t *currState) {

    if ((*currState & 15) == 8) { // currState = x1000
        *currState -= 3;          // currState = x0101
    }
    else {
        if (*currState & 1) {            // currState = xxx1
            if ((*currState & 3) == 3) { // currState = x011
                *currState ^= 2;         // currState = x001
            }
            else {                       // currState = xx01
                *currState ^= 1;         // currState = xx00
            }
        }
        else { // пошук першого одиничного біта
            uint64_t firstSingleBit = *currState;
            int idx = 0;

            // поки firstSingleBit != 0 та firstSingleBit != x001
            while (firstSingleBit && !(firstSingleBit & 1)) {
                firstSingleBit >>= 1;
                idx++;
            }

            if (firstSingleBit) {                         // currState = xx1000 (наприклад)
                *currState ^= (uint64_t(1) << idx);
                *currState |= (uint64_t(1) << (idx - 1));
                *currState |= (uint64_t(1) << (idx - 2)); // currState = xx0110
            }
            else {
                *currState = 0;
            }
        }
    }
}

void SmoothSortEngine::siftDown(int heapLeoNumIdx, int rootIdx) {
    int currNodeIdx = rootIdx;

    while (heapLeoNumIdx >= 2)
    {
        int maxIdx = currNodeIdx;
        int prevHeapLeoNumIdx{ heapLeoNumIdx };

        int rightChildIdx = currNodeIdx - 1;
        ++comparisonsCount_;
        if (arr_[rightChildIdx] > arr_[maxIdx]) {
            prevHeapLeoNumIdx = heapLeoNumIdx - 2;
            maxIdx = rightChildIdx;
        }

        int leftChildIdx = rightChildIdx - leoNums[heapLeoNumIdx - 2];
        ++comparisonsCount_;
        if (arr_[leftChildIdx] > arr_[maxIdx]) {
            prevHeapLeoNumIdx = heapLeoNumIdx - 1;
            maxIdx = leftChildIdx;
        }

        if (currNodeIdx != maxIdx) {
            ++swapsCount_;
            swap(currNodeIdx, maxIdx);
            heapLeoNumIdx = prevHeapLeoNumIdx;
            currNodeIdx = maxIdx;
        }
        else {
            break;
        }
    }
}

void SmoothSortEngine::buildHeapPool(uint64_t *currState) {
    for (int i{ 0 }; i < arr_->Length; ++i) {

        int currHeapLeoNumIdx{ -1 };
        calculateNextState(currState, &currHeapLeoNumIdx);

        if (currHeapLeoNumIdx != -1) {
            siftDown(currHeapLeoNumIdx, i);
        }
    }
}

void SmoothSortEngine::findMaxAmongRoots(uint64_t currState, int lastRootIdx, int* heapLeoNumIdx, int* maxRootIdx) {
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

void SmoothSortEngine::sort() {

    uint64_t currState{ 0 };
    buildHeapPool(&currState);

    for (int i{ (int)arr_->Length - 1 }; i >= 0; --i) {
        int heapLeoNumIdx{ -1 };
        int maxRootIdx{ 0 };
        findMaxAmongRoots(currState, i, &heapLeoNumIdx, &maxRootIdx);

        if (maxRootIdx != i) {
            ++swapsCount_;
            swap(i, maxRootIdx);
            siftDown(heapLeoNumIdx, maxRootIdx);
        }
        calculatePrevState(&currState);
    }
}