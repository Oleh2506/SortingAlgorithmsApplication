#pragma once

#include "SortEngine.h"

/// <summary>
/// Клас для сортування масиву алгоритмом пірамідального сортування.
/// Наслідує абстрактний клас  SortEngine.
/// </summary>
ref class HeapSortEngine : public SortEngine
{
protected:
	/// <summary> "Просійка вниз" для дотримання властивості MaxHeap. </summary>
	/// <param name="heapSize"> Розмір купи. </param>
	/// <param name="rootIdx"> Корінь купи. </param>
	virtual void heapify(int heapSize, int rootIdx);

	/// <summary> Метод для знаходження індексу лівого нащадка елементу з індексом rootIdx. </summary>
	///	<param name = "rootIdx"> Індекс елемену, для якого шукається лівого нащадок. </param>
	/// <returns> Індекс лівого нащадка елементу з індексом rootIdx. </returns> 
	int getLeftChildIdx(int rootIdx);

	/// <summary> Метод для знаходження індексу правого нащадка елементу з індексом rootIdx. </summary>
	///	<param name = "rootIdx"> Індекс елемену, для якого шукається правий нащадок. </param>
	/// <returns> Індекс правого нащадка елементу з індексом rootIdx. </returns> 
	int getRightChildIdx(int rootIdx);

	/// <summary> Метод для побудови бінарної купи (MaxHeap). </summary>
	void buildHeap();

public:
	/// <summary> Конструктор класу HeapSortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано. </param>
	HeapSortEngine(array<int>^% arr);

	/// <summary> Метод для сортування масиву алгоритмом пірамідального сортування. </summary>
	virtual void sort() override;
};

