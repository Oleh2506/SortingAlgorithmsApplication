#pragma once

#include "SelectionSortEngine.h"
#include "SortingVisualizerForm.h"

/// <summary>
/// ���� ��� ���������� ������ ���������� ���������� �������.
/// ���������� �������������� ����������� �� ��������� SortingVisualizerForm.
/// ������ ���� SelectionSortEngine.
/// </summary>
ref class VisualizableSelectionSortEngine : public SelectionSortEngine
{
private:
	// ������� VisualizableSelectionSortEngine ��� ���������� ������� ����������.
	SortingAlgorithmsApplication::SortingVisualizerForm^ svf_;

public:
	/// <summary> ���������� ����� VisualizableSelectionSortEngine. </summary>
	~VisualizableSelectionSortEngine();

protected:
	/// <summary> ����� ��� ����������� ������� ���������� �������� arr_ 
	/// ����� �������� � ��������� �� left �� right �������. 
	/// ������ ������ �������������������� �����������. </summary>
	///	<param name = "left"> ������ ��������, � ����� ���������� ����� ����������. </param>
	/// <param name = "right"> ������ ��������, �� ����� ����������� ����� ����������. </param>
	/// <returns> ������� ���������� �������� arr_ 
	/// ����� �������� � ��������� �� left �� right �������. </returns>
	virtual int getIdxOfMinElement(int left, int right) override;

public:
	/// <summary> ����������� ����� VisualizableSelectionSortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� �����������. </param>
	/// <param name = "maxVal"> �������� ��������, ����� ���� �������� ������� ������ arr. </param>
	VisualizableSelectionSortEngine(array<int>^% arr, int maxVal);
	
	/// <summary> ����� ��� ���������� ������ ���������� ���������� �������.
	/// ������ ���������� ���� ���������������� ��������. </summary>
	/// <returns> ³����������� ����� arr_. </returns>
	virtual void sort() override; 
};

