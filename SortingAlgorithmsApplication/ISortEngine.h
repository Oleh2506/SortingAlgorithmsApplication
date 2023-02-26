#pragma once

/// <summary> Інтерфейс для класів, призначенням яких є сортування масивів. </summary>
interface class ISortEngine {
public:
	/// <summary> Метод для сортування масиву. </summary>
	/// <returns> Відсортований масив. </returns>
	void sort();

	/// <summary> Геттер, що повертає поточну кількість перестановок. </summary>
	/// <returns> Поточна кількість перестановок. </returns>
	long long getSwapsCount();

	/// <summary> Геттер, що повертає поточну кількість порівнянь. </summary>
	/// <returns> Поточна кількість порівнянь. </returns>
	long long getComparisonsCount();

	/// <summary> Метод для перевірки масиву на відсортованість. </summary>
	/// <returns> Індекс першого елементу, який порушує відсортованість масиву.
	/// Якщо такий елемент відсутній, то повертає -1. </returns>
	int sortingTest();
};