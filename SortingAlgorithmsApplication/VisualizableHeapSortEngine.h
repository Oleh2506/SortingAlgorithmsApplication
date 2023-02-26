#pragma once

#include "HeapSortEngine.h"
#include "SortingVisualizerForm.h"

/// <summary>
/// ���� ��� ���������� ������ ���������� ������������ ����������.
/// ���������� �������������� ����������� �� ��������� SortingVisualizerForm.
/// ������ ���� HeapSortEngine.
/// </summary>
ref class VisualizableHeapSortEngine : public HeapSortEngine
{
private:
	// ������� VisualizableHeapSortEngine ��� ���������� ������� ����������.
	SortingAlgorithmsApplication::SortingVisualizerForm^ svf_;

public:
	/// <summary> ���������� ����� VisualizableHeapSortEngine. </summary>
	~VisualizableHeapSortEngine();

protected:
	/// <summary> "������� ����" ��� ���������� ���������� MaxHeap. 
	/// ������ "�������" ���� ���������������� ��������. </summary>
	/// <param name="heapSize"> ����� ����. </param>
	/// <param name="rootIdx"> ����� ����. </param>
	/// <returns> ����� ������ ������, � ����� �������, �� ��� ������ rootIdx �����
	/// ���� �������� �� ���������� MaxHeap. </returns> 
	virtual void heapify(int heapSize, int rootIdx) override;

public:
	/// <summary> ����������� ����� VisualizableHeapSortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� �����������. </param>
	/// <param name = "maxVal"> �������� ��������, ����� ���� �������� ������� ������ arr. </param>
	VisualizableHeapSortEngine(array<int>^% arr, int maxVal);

	/// <summary> ����� ��� ���������� ������ ���������� ������������ ����������.
	/// ������ ���������� ���� ���������������� ��������. </summary>
	virtual void sort() override;
};

