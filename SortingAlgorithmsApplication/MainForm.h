#pragma once

#include "SelectionSortEngine.h"
#include "HeapSortEngine.h"
#include "SmoothSortEngine.h"
#include "VisualizableSelectionSortEngine.h"
#include "VisualizableHeapSortEngine.h"
#include "VisualizableSmoothSortEngine.h"
#include "ISortEngine.h"

namespace SortingAlgorithmsApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Клас для відображення графічного користувацького інтерфейсу 
	/// програми SortingAlgorithmsApplication.
	/// Містить компонент NumericUpDown arraySizeNumericUpDown 
	/// для введення розміру масиву користувачем.
	/// Містить кнопку btnReset для генерації масиву введеного розміру, 
	/// що складається з випадкових цілих чисел.
	/// Містить кнопку btnSort для сортування масиву обраним алгоритмом.
	/// Містить компонент ComboBox algorithmSelectorDropDown 
	/// для обрання методу сортування (SelectionSort, HeapSort, SmoothSort).
	/// Містить компонент CheckBox visualizeCheckBox для того, 
	/// щоб обрати, чи потрібно візуалізувати процес сортування масиву.
	/// Містить компонент RichTextBox outputRichTextBox 
	/// для виводу інформації про процес генерації масиву та сортування.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		// Масив цілих чисел, що буде згенеровано випадковим чином, 
		// якщо натиснути кнопку btnReset, і відсортовано обраним методом.
		array<int>^ arr_;
		// Найбільше можливе значення, якого може набути елемент масиву arr_.
		literal int kMaxVal_ = 50000;
		// Змінна, що використовується для індексації тих масивів, що були відсортовані.
		int currSortableArrayIdx_;
		// Назва папки, в якій зберігаються текстові файли, 
		// що містять масиви випадкових цілих чисел перед сортуванням та їхні розміри.
		literal String^ kInitialArraysFolder_ = "initial_arrays\\";
		// Назва папки, в якій зберігаються текстові файли, 
		// що містять відсортовані масиви цілих чисел, їхні розміри, обраний метод сортування,
		// кількість перестановок та кількість порівнянь, здійснених в процесі сортування.
		literal String^ kSortedArraysFolder_ = "sorted_arrays\\";
		// Масив рядків-назв методів сортування.
		array<String^>^ sortingAlgorithmsNames_;
	private: System::Windows::Forms::Button^ btnLoad;
	private: System::Windows::Forms::Button^ btnSave;

		   // Максимальний розмір масиву, за якого процесу його сортування може візуалізуватися.
		literal int maxVisualizableArrSize_ = 200;

	public:
		/// <summary> Конструктор класу MainForm. </summary>
		MainForm(void);

	private:
		/// <summary> Метод, що заповнює масив sortingAlgorithmsNames_ рядками з назвами 
		/// алгоритмів сортування. </summary>
		void populateSortingAlgorithmsNamesArray();

	private:
		/// <summary> Метод для заповнення компоненту algorithmSelectorDropDown
		/// елементами масиву sortingAlgorithms_. </summary>
		void populateDropDownAlgorithmSelector();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm();

	protected:

	protected:

	private: System::Windows::Forms::RichTextBox^ outputRichTextBox;
	private: System::Windows::Forms::NumericUpDown^ arraySizeNumericUpDown;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ algorithmSelectorDropDown;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnReset;
	private: System::Windows::Forms::Button^ btnSort;
	private: System::Windows::Forms::CheckBox^ visualizeCheckBox;

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
	/// <summary> Метод для обробки натискання на кнопку btnReset.
	/// Генерує масив випадкових цілих чисел arr_. 
	/// Виводить відповідне повідомлення в компонент outputRichTextBox. 
	/// Блокує доступ до прапоряця visualizeCheckBox, якщо розмірність масиву > maxVisusalizableArrSize_.
	/// Інакше розблоковує доступ до прапоряця visualizeCheckBox. </summary>
	private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e);

	/// <summary> Метод виведення повідомлення про генерацію arr_ 
	/// в outputRichTextBox, що містить розмір масиву та поточне значення currSortableArrayIdx_. </summary>
	private: void printGenerationMessage();
	
    /// <summary> Метод виведення n послідовних елементів масиву arr_, якщо arr_->Length > n.
	/// Інакше виводиться увесь масив. </summary>
	private: void printRandomConsecutiveElementsOfArray(int n);

	/// <summary> Метод для генерації масиву arr_ розміру arrSize.
	/// Кожному елементу масиву arr_ присвоюється випадкове ціле значення в межах від 0 до kMaxVal_.
	/// Очищує пам'ять, яку займав arr_ до генерації, якщо arr_ != nullptr. </summary>
	/// <param name = "arrSize"> Розмірність масиву для генерації. </param>
	private: void generateRandomArray(int arrSize);

	/// <summary> Метод для збереження розміру масиву arr_ та самого масиву arr_ до сортування в текстовий файл.
	/// Текстовий файл зберігається в папку з назвою initialArraysFolder_. </summary>
	/// <param name = "fileName"> Назва текстового файлу, в який буде записано розмір масиву та
	/// сам масив до сортування. </param>
	/// <returns> true, якщо файл вдалося зберегти, інакше - false. </returns>
	private: bool saveInitialArrayToFile(String^ fileName);

	/// <summary> Метод для збереження розміру масиву arr_, самого масиву arr_ 
	/// після сортування, назви методу сортування, кількості перестановок та порівнянь, 
	/// здійснених в процесі сортування, в текстовий файл.
	/// Текстовий файл зберігається в папку з назвою sortedArrayFolder_. </summary>
	/// <param name = "fileName"> Назва текстового файлу, в який буде записано дані. </param>
	/// <param name = "compsCount"> Кількість порівнянь, здійснених в процесі сортування. </param>
	/// <param name = "swapsCount"> Кількість перестановок, здійснених в процесі сортування. </param>
	/// <returns> true, якщо файл вдалося зберегти, інакше - false. </returns>
	private: bool saveSortedArrayToFile(String^ fileName, long long compsCount, long long swapsCount);

	/// <summary> Метод для генерації назви поточного файлу, в якому зберігатиметься
	/// масив до сортування. </summary>
	/// <returns> Назва поточного файлу, в який буде записано масив ДО сортування. </returns>
	private: String^ generateInitialArrayFileName();

    /// <summary> Метод для виведення повідомлення про сортування arr_ 
	/// та відповідних даних в компонент outputRichTextBox. </summary>
	///	<param name = "compsCount"> Кількість порівнянь, здійснених в процесі сортування. </param>
	/// <param name = "swapsCount"> Кількість перестановок, здійснених в процесі сортування. </param> 
	///	<param name = "initialArrayWasWrittenToFile"> Вказує, чи початковий стан масиву було успішно записано у файл. </param>
	/// <param name = "sortedArrayWasWrittenToFile"> Вказує, чи відсортований стан масиву було успішно записано у файл. </param>   
	private: void printSortingMessage(bool initialArrayWasWrittenToFile, bool sortedArrayWasWrittenToFile, long long compsCount, long long swapsCount);

	/// <summary> Метод для обробки натискання на кнопку btnSort.
	/// Записує початковий масив до текстового файлу.
	/// Сортує масив випадкових цілих чисел arr_. 
	/// Записує відсортований масив до текстового файлу.
	/// Виводить відповідне повідомлення в компонент outputRichTextBox. </summary>
	private: System::Void btnSort_Click(System::Object^ sender, System::EventArgs^ e);

    /// <summary> Метод, який повертає об'єкт класу, що імплементує інтерфейс
	/// ISortEngine, відповідно до даних, введених користувачем. </summary>
	/// <returns> Об'єкт класу, що імплементує інтерфейс ISortEngine, що відповідає
	/// умовам, які введені користувачем. </returns>
	private: ISortEngine^ getConditionalSortEngine();

	/// <summary> Метод, який очищує outputRichTextBox від тексту, якщо 
	/// кількість записаних символів перевищує 2000. </summary>
	private: void updateOutputTextBox();

    /// <summary> Метод для генерації назви поточного файлу, в якому зберігатиметься
	/// масив після сортування. </summary>
	/// <returns> Назва поточного файлу, в який буде записано масив після сортування. </returns>
	private: String^ generateSortedArrayFileName();

    /// <summary> Метод для обробки події "зміна тексту" компоненту outputRichTextBox.
	/// Встановлює смугу прокрутку outputRichTextBox в нижнє положення. </summary>
	private: System::Void outputRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e);

	private: void printLoadingMessage();

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);

	private: void printSavingMessage();
};
}
