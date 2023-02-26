#pragma once

#include "SmoothSortEngine.h"
#include "SortingVisualizerForm.h"
#include <cliext/vector>

using cliext::vector;

/// <summary>
/// ���� ��� ���������� ������ ���������� �������� ����������.
/// ���������� �������������� ����������� �� ��������� SortingVisualizerForm.
/// ������ ���� SmoothSortEngine.
/// </summary>
ref class VisualizableSmoothSortEngine : public SmoothSortEngine
{
private:
	// ������� VisualizableHeapSortEngine ��� ���������� ������� ����������.
	SortingAlgorithmsApplication::SortingVisualizerForm^ svf_;

public:
	/// <summary> ���������� ����� VisualizableSmoothSortEngine. </summary>
	~VisualizableSmoothSortEngine();

protected:
	/// <summary> ����� ��� "������� ����" ������� ����.
	/// ������ "�������" �������������������� �����������. </summary>
	///	<param name = "heapLeoNumIdx"> ������ ����� ��������, ��� ������� ���������
	/// ������� ����. </param>
	/// <param name = "rootIdx"> ������ ������ ������� ����. </param>
	virtual void siftDown(int heapLeoNumIdx, int rootIdx) override;

	/// <summary> ����� ��� ����������� ������� ���������� ������ ����� ������ ���
	/// � ����������� ���. ������� �������� ������� ������������� ������ maxRootIdx
	/// �� �������� heapLeoNumIdx - ������ ����� ��������, ��� ������� ��������� ����, ���
	/// �������� ��������� �����.
	/// ������ ������ �������������������� �����������. </summary>
	///	<param name = "currState"> �������� ���� ����������� ���. </param>
	/// <param name = "rootIdx"> ������ ������ �������� ����. </param>
	/// <param name = "heapLeoNumIdx"> ������ ����� ��������, ��� ������� ���������
	/// �������� ����. </param>
	/// <param name = "maxRootIdx"> ������ ���������� ������ ����� ������� ����������� ����. </param>
	virtual void findMaxAmongRoots(uint64_t currState, int rootIdx, int* heapLeoNumIdx, int* maxRootIdx) override;

public:
	/// <summary> ����������� ����� VisualizableSmoothSortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� �����������. </param>
	/// <param name = "maxVal"> �������� ��������, ����� ���� �������� ������� ������ arr. </param>
	VisualizableSmoothSortEngine(array<int>^% arr, int maxVal);

	/// <summary> ����� ��� ���������� ������ ���������� �������� ����������.
	/// ������ ���������� ���� ���������������� ��������. </summary>
	virtual void sort() override;
};

