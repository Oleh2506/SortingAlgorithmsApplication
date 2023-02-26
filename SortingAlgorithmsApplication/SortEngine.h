#pragma once

#include "ISortEngine.h"

/// <summary>
/// ����������� ����, �� ���������� ��������� ISortEngine � ������ ������� ���� ������.
/// </summary>
ref class SortEngine abstract : ISortEngine
{
protected:
	// ����� ����� �����, ���� ���� �����������.
	array<int>^ arr_;
	// ������� ������� ������������.
	long long swapsCount_;
	// ������� ������� ��������.
	long long comparisonsCount_;

protected:
	/// <summary> ����� ��� ������������ ���� �������� ������. </summary>
	/// <param name = "i"> ������ �������� ���� ���������������. </param>
	/// <param name = "j"> ������ �������� ���� ���������������. </param>
	virtual void swap(int i, int j);

public:
	/// <summary> ����������� ����� SortEngine. </summary>
	/// <param name = "arr"> ��������� �� �����, ���� ���� ����������� ������� �������. </param>
	SortEngine(array<int>^% arr);

	/// <summary> ������, �� ������� ������� ������� ��������.
	/// ������� ����� ���������� ISortEngine. </summary>
	/// <returns> ������� ������� ��������. </returns>
	virtual long long getComparisonsCount();

	/// <summary> ������, �� ������� ������� ������� ������������.
	/// ������� ����� ���������� ISortEngine. </summary>
	/// <returns> ������� ������� ������������. </returns>
	virtual long long getSwapsCount();

	/// <summary> ����������� ����� ��� ���������� ������. </summary>
	virtual void sort() abstract;

	/// <summary> ����� ��� �������� ������ �� �������������. 
	/// ������� ����� ���������� ISortEngine. </summary>
	/// <returns> ������ ������� ��������, ���� ������ ����� ������������� ������.
	/// ���� ����� ������� �������, �� ������� -1. </returns>
	virtual int sortingTest();
};

