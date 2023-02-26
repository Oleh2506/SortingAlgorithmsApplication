#pragma once

#include "HeapSortEngine.h"
#include "SortingVisualizerForm.h"

/// <summary>
/// Клас для сортування масиву алгоритмом пірамідального сортування.
/// Сортування супроводжується візуалізацією за допомогою SortingVisualizerForm.
/// Наслідує клас HeapSortEngine.
/// </summary>
ref class VisualizableHeapSortEngine : public HeapSortEngine
{
private:
	// Атрибут VisualizableHeapSortEngine для візуалізації процесу сортування.
	SortingAlgorithmsApplication::SortingVisualizerForm^ svf_;

public:
	/// <summary> Деструктор класу VisualizableHeapSortEngine. </summary>
	~VisualizableHeapSortEngine();

protected:
	/// <summary> "Просійка вниз" для дотримання властивості MaxHeap. 
	/// Процес "просійки" буде супроводжуватися анімацією. </summary>
	/// <param name="heapSize"> Розмір купи. </param>
	/// <param name="rootIdx"> Корінь купи. </param>
	/// <returns> Повне бінарне дерево, в якому елемент, що мав індекс rootIdx займе
	/// місце відповідно до властивості MaxHeap. </returns> 
	virtual void heapify(int heapSize, int rootIdx) override;

public:
	/// <summary> Конструктор класу VisualizableHeapSortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано. </param>
	/// <param name = "maxVal"> Найбільше значення, якого може набувати елемент масиву arr. </param>
	VisualizableHeapSortEngine(array<int>^% arr, int maxVal);

	/// <summary> Метод для сортування масиву алгоритмом пірамідального сортування.
	/// Процес сортування буде супроводжуватися анімацією. </summary>
	virtual void sort() override;
};

