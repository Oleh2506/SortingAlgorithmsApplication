#pragma once

#include <chrono>
#include <thread>

namespace SortingAlgorithmsApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::this_thread;
	using namespace std::chrono_literals;

	/// <summary>
	/// Клас для графічного відображення процесу сортування масиву.
	/// Містить компонент panel, який використовується як тло для відображення
	/// гістограми, стовпці якої рухаються і змінюють колір відповідно до
	/// порівнянь і перестановок, які відбуваються в процесу сортування масиву.
	/// </summary>
	public ref class SortingVisualizerForm : public System::Windows::Forms::Form
	{
	private:
		// Атрибут класу, який використовується для відображення графічної складової процесу
	    // сортування масиву.
		Graphics^ g_;
		// Масив, який буде сортуватися.
		array<int>^ arr_;
		// Максимальне значення, якого може набувати елемент масиву arr_.
		int maxVal_;
		// Копія оригінального масиву, яка буде використовуватися для відображення процесу
		// перестановок елементів.
		array<int>^ arrCopy_;
		// Коефіцієнт, який буе використано для масштабування висоти стовпця гістограми під час
		// візуалізації процесу сортування.
		float hCoefficient_;
		// Коефіцієнт, який буе використано для масштабування ширини стовпця гістограми під час
		// візуалізації процесу сортування.
		float wCoefficient_;

	/// <summary> Конструктор класу SortingVisualizerForm. </summary>
	public: SortingVisualizerForm(array<int>^% arr, int maxVal);

    /// <summary> Розрахунок hCoefficient_. </summary>
	/// <returns> Значення  hCoefficient_. </returns>
	private: float getHeightCoefficient();

	/// <summary> Розрахунок wCoefficient_. </summary>
	/// <returns> Значення  wCoefficient_. </returns>
	private: float getWidthCoefficient();

	public:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SortingVisualizerForm();

	private: System::Windows::Forms::Panel^ panel;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);

#pragma endregion

	/// <summary> Метод для графічного відображення одного стовпця гістограми. </summary>
	/// <param name = "brush"> Колір стовпця. </param>
	/// <param name = "idx"> Індекс елементу масиву, який відображається. </param>
	/// <param name = "val"> Значення елементу масиву, який відображається. </param>
	private: void drawHill(Brush^ brush, int idx, int val);

	/// <summary> Метод для графічного відображення всього масиву arr_. </summary>
	public: void visualizeArray();

    /// <summary> Метод для графічного відображення процесу перестановки двох елементів масиву. </summary>
	/// <param name = "i"> Індекс елементу який переставляється. </param>
	/// <param name = "j"> Індекс елементу який переставляється. </param>
	public: void visualizeSwap(int i, int j);

	/// <summary> Метод для графічного відображення процесу порівняння двох елементів масиву. </summary>
	/// <param name = "i"> Індекс елементу який порівнюється з іншим елементом. </param>
	/// <param name = "j"> Індекс елементу який порівнюється з іншим елементом. </param>
	public: void visualizeComparison(int i, int j);

	/// <summary> Метод для графічного відображення процесу перевірки масиву на відсортованість. </summary>
	/// <param name = "breakIdx"> Індекс першого елементу, який порушує умову відсортованості масиву. </param>
	public: void visualizeSortingTest(int breakIdx);
	};
}
