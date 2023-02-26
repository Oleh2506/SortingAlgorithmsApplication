#pragma once

#include "SortEngine.h"
#include <cliext/vector>

using cliext::vector;

/// <summary>
/// Клас для сортування масиву алгоритмом плавного сортування.
/// Наслідує абстрактний клас  SortEngine.
/// </summary>
ref class SmoothSortEngine : public SortEngine
{
protected:
	// Вектор чисел Леонардо, які будуть використані в процесі сортування.
	vector<int> leoNums;

protected:
	/// <summary> Метод для побудови послідовності куп, які мають розміри, рівні числам Леонардо.
	/// Також оновлює поточне значення стану послідовності куп currState. </summary>
	///	<param name = "currState"> Поточний стан послідовності куп. </param>
	void buildHeapPool(uint64_t *currState);

	/// <summary> Метод для розрахунку натупного стану на основі поточного. 
	/// Оновлює значення змінної currState. Оновлює значення 
	/// mergedHeapsLeoNumIdx, якщо перехід до наступного стану передбачає злиття куп. 
	/// Якщо злиття не відбулося, то mergedHeapsLeoNumIdx = -1. </summary>
	///	<param name = "currState"> Поточний стан послідовності куп. </param>
	/// <param name = "mergedHeapsLeoNumIdx"> Індекс числа Леонардо, яке дорівнює
	/// розмірності об'єднаних куп, якщо новий стан передбачає об'єднання двох куп. </param>
	void calculateNextState(uint64_t *currState, int* mergedHeapsLeoNumIdx);

	/// <summary> Метод для розрахунку попереднього стану на основі поточного. 
	/// Оновлює значення змінної currState. </summary>
	///	<param name = "currState"> Поточний стан послідовності куп. </param>
	void calculatePrevState(uint64_t *currState);

	/// <summary> Метод для "просійки вниз" поточної купи. </summary>
	///	<param name = "heapLeoNumIdx"> Індекс числа Леонардо, яке дорівнює розмірності
	/// поточної купи. </param>
	/// <param name = "rootIdx"> Індекс кореню поточної купи. </param>
	virtual void siftDown(int heapLeoNumIdx, int rootIdx);

	/// <summary> Метод для знаходження індексу найбільшого кореню серед коренів куп
	/// з послідовності куп. Оновлює значення індексу максимального кореню maxRootIdx
	/// та значення heapLeoNumIdx - індекс числа Леонардо, яке дорівнює розмірності купи, якій
	/// належить найбільший корінь. </summary>
	///	<param name = "currState"> Поточний стан послідовності куп. </param>
	/// <param name = "rootIdx"> Індекс кореню останньої купи. </param>
	/// <param name = "heapLeoNumIdx"> Індекс числа Леонардо, яке дорівнює розмірності
	/// останньої купи. </param>
	/// <param name = "maxRootIdx"> Індекс найбільшого кореню серед поточної послідовності купи. </param>
	virtual void findMaxAmongRoots(uint64_t currState, int rootIdx, int *heapLeoNumIdx, int *maxRootIdx);
	
	/// <summary> Метод для разрахунку достатньої для сортування кількості Леонардових чисел. 
	/// Числа заносяться до вектору leoNums. </summary>
	void calculateLeoNums();

public:
	/// <summary> Конструктор класу SmoothSortEngine. </summary>
	/// <param name = "arr"> Посилання на масив, який буде відсортовано. </param>
	SmoothSortEngine(array<int>^% arr);

	/// <summary> Метод для сортування масиву алгоритмом пірамідального сортування. </summary>
	virtual void sort() override;
};

