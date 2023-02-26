#pragma once

#include "SortEngine.h"

/// <summary>
/// Клас для сортування масиву алгоритмом сортування вибором.
/// Наслідує абстрактний клас  SortEngine.
/// </summary>
ref class SelectionSortEngine : public SortEngine
{

protected:
	/// <summary> Метод для знаходження індексу найменщого елементу arr_ 
	/// серед елементів з індексами від left до right включно. </summary>
	///	<param name = "left"> Індекс елементу, з якого починається пошук мінімального. </param>
	/// <param name = "right"> Індекс елементу, на якому завершується пошук мінімального. </param>
	/// <returns> Індексу найменщого елементу arr_ 
	/// серед елементів з індексами від left до right включно. </returns> 
	virtual int getIdxOfMinElement(int left, int right);

public:
	/// <summary> Конструктор класу SelectionSortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано. </param>
	SelectionSortEngine(array<int>^% arr);

	/// <summary> Метод для сортування масиву алгоритмом сортування вибором. </summary>
	virtual void sort() override;
};
