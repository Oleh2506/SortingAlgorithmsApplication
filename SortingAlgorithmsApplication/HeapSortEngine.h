#pragma once

#include "SortEngine.h"

/// <summary>
/// ���� ��� ���������� ������ ���������� ������������ ����������.
/// ������ ����������� ����  SortEngine.
/// </summary>
ref class HeapSortEngine : public SortEngine
{
protected:
	/// <summary> "������� ����" ��� ���������� ���������� MaxHeap. </summary>
	/// <param name="heapSize"> ����� ����. </param>
	/// <param name="rootIdx"> ����� ����. </param>
	virtual void heapify(int heapSize, int rootIdx);

	/// <summary> ����� ��� ����������� ������� ����� ������� �������� � �������� rootIdx. </summary>
	///	<param name = "rootIdx"> ������ �������, ��� ����� �������� ����� �������. </param>
	/// <returns> ������ ����� ������� �������� � �������� rootIdx. </returns> 
	int getLeftChildIdx(int rootIdx);

	/// <summary> ����� ��� ����������� ������� ������� ������� �������� � �������� rootIdx. </summary>
	///	<param name = "rootIdx"> ������ �������, ��� ����� �������� ������ �������. </param>
	/// <returns> ������ ������� ������� �������� � �������� rootIdx. </returns> 
	int getRightChildIdx(int rootIdx);

	/// <summary> ����� ��� �������� ������ ���� (MaxHeap). </summary>
	void buildHeap();

public:
	/// <summary> ����������� ����� HeapSortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� �����������. </param>
	HeapSortEngine(array<int>^% arr);

	/// <summary> ����� ��� ���������� ������ ���������� ������������ ����������. </summary>
	virtual void sort() override;
};

