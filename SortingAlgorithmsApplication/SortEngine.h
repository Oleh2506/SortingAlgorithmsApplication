#pragma once

#include "ISortEngine.h"

/// <summary>
/// Абстрактний клас, що імплементує інтерфейс ISortEngine і реалізує частину його методів.
/// </summary>
ref class SortEngine abstract : ISortEngine
{
protected:
	// Масив цілих чисел, який буде відсортовано.
	array<int>^ arr_;
	// Поточна кількість перестановок.
	long long swapsCount_;
	// Поточна кількість порівнянь.
	long long comparisonsCount_;

protected:
	/// <summary> Метод для перестановки двох елементів масиву. </summary>
	/// <param name = "i"> Індекс елементу який переставляється. </param>
	/// <param name = "j"> Індекс елементу який переставляється. </param>
	virtual void swap(int i, int j);

public:
	/// <summary> Конструктор класу SortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано обраним методом. </param>
	SortEngine(array<int>^% arr);

	/// <summary> Геттер, що повертає поточну кількість порівнянь.
	/// Реалізаує метод інтерфейсу ISortEngine. </summary>
	/// <returns> Поточна кількість порівнянь. </returns>
	virtual long long getComparisonsCount();

	/// <summary> Геттер, що повертає поточну кількість перестановок.
	/// Реалізаує метод інтерфейсу ISortEngine. </summary>
	/// <returns> Поточна кількість перестановок. </returns>
	virtual long long getSwapsCount();

	/// <summary> Абстрактний метод для сортування масиву. </summary>
	virtual void sort() abstract;

	/// <summary> Метод для перевірки масиву на відсортованість. 
	/// Реалізаує метод інтерфейсу ISortEngine. </summary>
	/// <returns> Індекс першого елементу, який порушує умову відсортованості масиву.
	/// Якщо такий елемент відсутній, то повертає -1. </returns>
	virtual int sortingTest();
};

