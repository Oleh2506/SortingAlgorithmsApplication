#pragma once

/// <summary> ��������� ��� �����, ������������ ���� � ���������� ������. </summary>
interface class ISortEngine {
public:
	/// <summary> ����� ��� ���������� ������. </summary>
	/// <returns> ³����������� �����. </returns>
	void sort();

	/// <summary> ������, �� ������� ������� ������� ������������. </summary>
	/// <returns> ������� ������� ������������. </returns>
	long long getSwapsCount();

	/// <summary> ������, �� ������� ������� ������� ��������. </summary>
	/// <returns> ������� ������� ��������. </returns>
	long long getComparisonsCount();

	/// <summary> ����� ��� �������� ������ �� �������������. </summary>
	/// <returns> ������ ������� ��������, ���� ������ ������������� ������.
	/// ���� ����� ������� �������, �� ������� -1. </returns>
	int sortingTest();
};