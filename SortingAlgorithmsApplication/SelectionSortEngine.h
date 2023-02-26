#pragma once

#include "SortEngine.h"

/// <summary>
/// ���� ��� ���������� ������ ���������� ���������� �������.
/// ������ ����������� ����  SortEngine.
/// </summary>
ref class SelectionSortEngine : public SortEngine
{

protected:
	/// <summary> ����� ��� ����������� ������� ���������� �������� arr_ 
	/// ����� �������� � ��������� �� left �� right �������. </summary>
	///	<param name = "left"> ������ ��������, � ����� ���������� ����� ����������. </param>
	/// <param name = "right"> ������ ��������, �� ����� ����������� ����� ����������. </param>
	/// <returns> ������� ���������� �������� arr_ 
	/// ����� �������� � ��������� �� left �� right �������. </returns> 
	virtual int getIdxOfMinElement(int left, int right);

public:
	/// <summary> ����������� ����� SelectionSortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� �����������. </param>
	SelectionSortEngine(array<int>^% arr);

	/// <summary> ����� ��� ���������� ������ ���������� ���������� �������. </summary>
	virtual void sort() override;
};
