#pragma once

#include "SelectionSortEngine.h"
#include "SortingVisualizerForm.h"

/// <summary>
/// Клас для сортування масиву алгоритмом сортування вибором.
/// Сортування супроводжується візуалізацією за допомогою SortingVisualizerForm.
/// Наслідує клас SelectionSortEngine.
/// </summary>
ref class VisualizableSelectionSortEngine : public SelectionSortEngine
{
private:
	// Атрибут VisualizableSelectionSortEngine для візуалізації процесу сортування.
	SortingAlgorithmsApplication::SortingVisualizerForm^ svf_;

public:
	/// <summary> Деструктор класу VisualizableSelectionSortEngine. </summary>
	~VisualizableSelectionSortEngine();

protected:
	/// <summary> Метод для знаходження індексу найменщого елементу arr_ 
	/// серед елементів з індексами від left до right включно. 
	/// Процес пошуку супроводжуватиметься візуалізацією. </summary>
	///	<param name = "left"> Індекс елементу, з якого починається пошук мінімального. </param>
	/// <param name = "right"> Індекс елементу, на якому завершується пошук мінімального. </param>
	/// <returns> Індексу найменщого елементу arr_ 
	/// серед елементів з індексами від left до right включно. </returns>
	virtual int getIdxOfMinElement(int left, int right) override;

public:
	/// <summary> Конструктор класу VisualizableSelectionSortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано. </param>
	/// <param name = "maxVal"> Найбільше значення, якого може набувати елемент масиву arr. </param>
	VisualizableSelectionSortEngine(array<int>^% arr, int maxVal);
	
	/// <summary> Метод для сортування масиву алгоритмом сортування вибором.
	/// Процес сортування буде супроводжуватися анімацією. </summary>
	/// <returns> Відсортований масив arr_. </returns>
	virtual void sort() override; 
};

