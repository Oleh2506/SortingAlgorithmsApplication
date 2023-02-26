#pragma once

#include "SmoothSortEngine.h"
#include "SortingVisualizerForm.h"
#include <cliext/vector>

using cliext::vector;

/// <summary>
/// Клас для сортування масиву алгоритмом плавного сортування.
/// Сортування супроводжується візуалізацією за допомогою SortingVisualizerForm.
/// Наслідує клас SmoothSortEngine.
/// </summary>
ref class VisualizableSmoothSortEngine : public SmoothSortEngine
{
private:
	// Атрибут VisualizableHeapSortEngine для візуалізації процесу сортування.
	SortingAlgorithmsApplication::SortingVisualizerForm^ svf_;

public:
	/// <summary> Деструктор класу VisualizableSmoothSortEngine. </summary>
	~VisualizableSmoothSortEngine();

protected:
	/// <summary> Метод для "просійки вниз" поточної купи.
	/// Процес "просійки" супроводжуватиметься візуалізацією. </summary>
	///	<param name = "heapLeoNumIdx"> Індекс числа Леонардо, яке дорівнює розмірності
	/// поточної купи. </param>
	/// <param name = "rootIdx"> Індекс кореню поточної купи. </param>
	virtual void siftDown(int heapLeoNumIdx, int rootIdx) override;

	/// <summary> Метод для знаходження індексу найбільшого кореню серед коренів куп
	/// з послідовності куп. Оновлює значення індексу максимального кореню maxRootIdx
	/// та значення heapLeoNumIdx - індекс числа Леонардо, яке дорівнює розмірності купи, якій
	/// належить найбільший корінь.
	/// Процес пошуку супроводжуватиметься візуалізацією. </summary>
	///	<param name = "currState"> Поточний стан послідовності куп. </param>
	/// <param name = "rootIdx"> Індекс кореню останньої купи. </param>
	/// <param name = "heapLeoNumIdx"> Індекс числа Леонардо, яке дорівнює розмірності
	/// останньої купи. </param>
	/// <param name = "maxRootIdx"> Індекс найбільшого кореню серед поточної послідовності купи. </param>
	virtual void findMaxAmongRoots(uint64_t currState, int rootIdx, int* heapLeoNumIdx, int* maxRootIdx) override;

public:
	/// <summary> Конструктор класу VisualizableSmoothSortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано. </param>
	/// <param name = "maxVal"> Найбільше значення, якого може набувати елемент масиву arr. </param>
	VisualizableSmoothSortEngine(array<int>^% arr, int maxVal);

	/// <summary> Метод для сортування масиву алгоритмом плавного сортування.
	/// Процес сортування буде супроводжуватися анімацією. </summary>
	virtual void sort() override;
};

