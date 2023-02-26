#pragma once

#include "SortEngine.h"
#include <cliext/vector>

using cliext::vector;

/// <summary>
/// ���� ��� ���������� ������ ���������� �������� ����������.
/// ������ ����������� ����  SortEngine.
/// </summary>
ref class SmoothSortEngine : public SortEngine
{
protected:
	// ������ ����� ��������, �� ������ ���������� � ������ ����������.
	vector<int> leoNums;

protected:
	/// <summary> ����� ��� �������� ����������� ���, �� ����� ������, ��� ������ ��������.
	/// ����� ������� ������� �������� ����� ����������� ��� currState. </summary>
	///	<param name = "currState"> �������� ���� ����������� ���. </param>
	void buildHeapPool(uint64_t *currState);

	/// <summary> ����� ��� ���������� ��������� ����� �� ����� ���������. 
	/// ������� �������� ����� currState. ������� �������� 
	/// mergedHeapsLeoNumIdx, ���� ������� �� ���������� ����� ��������� ������ ���. 
	/// ���� ������ �� ��������, �� mergedHeapsLeoNumIdx = -1. </summary>
	///	<param name = "currState"> �������� ���� ����������� ���. </param>
	/// <param name = "mergedHeapsLeoNumIdx"> ������ ����� ��������, ��� �������
	/// ��������� ��'������� ���, ���� ����� ���� ��������� ��'������� ���� ���. </param>
	void calculateNextState(uint64_t *currState, int* mergedHeapsLeoNumIdx);

	/// <summary> ����� ��� ���������� ������������ ����� �� ����� ���������. 
	/// ������� �������� ����� currState. </summary>
	///	<param name = "currState"> �������� ���� ����������� ���. </param>
	void calculatePrevState(uint64_t *currState);

	/// <summary> ����� ��� "������� ����" ������� ����. </summary>
	///	<param name = "heapLeoNumIdx"> ������ ����� ��������, ��� ������� ���������
	/// ������� ����. </param>
	/// <param name = "rootIdx"> ������ ������ ������� ����. </param>
	virtual void siftDown(int heapLeoNumIdx, int rootIdx);

	/// <summary> ����� ��� ����������� ������� ���������� ������ ����� ������ ���
	/// � ����������� ���. ������� �������� ������� ������������� ������ maxRootIdx
	/// �� �������� heapLeoNumIdx - ������ ����� ��������, ��� ������� ��������� ����, ���
	/// �������� ��������� �����. </summary>
	///	<param name = "currState"> �������� ���� ����������� ���. </param>
	/// <param name = "rootIdx"> ������ ������ �������� ����. </param>
	/// <param name = "heapLeoNumIdx"> ������ ����� ��������, ��� ������� ���������
	/// �������� ����. </param>
	/// <param name = "maxRootIdx"> ������ ���������� ������ ����� ������� ����������� ����. </param>
	virtual void findMaxAmongRoots(uint64_t currState, int rootIdx, int *heapLeoNumIdx, int *maxRootIdx);
	
	/// <summary> ����� ��� ���������� ��������� ��� ���������� ������� ����������� �����. 
	/// ����� ���������� �� ������� leoNums. </summary>
	void calculateLeoNums();

public:
	/// <summary> ����������� ����� SmoothSortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� �����������. </param>
	SmoothSortEngine(array<int>^% arr);

	/// <summary> ����� ��� ���������� ������ ���������� ������������ ����������. </summary>
	virtual void sort() override;
};

