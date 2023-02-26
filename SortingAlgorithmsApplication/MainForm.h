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
	/// ���� ��� ����������� ���������� ��������������� ���������� 
	/// �������� SortingAlgorithmsApplication.
	/// ̳����� ��������� NumericUpDown arraySizeNumericUpDown 
	/// ��� �������� ������ ������ ������������.
	/// ̳����� ������ btnReset ��� ��������� ������ ��������� ������, 
	/// �� ���������� � ���������� ����� �����.
	/// ̳����� ������ btnSort ��� ���������� ������ ������� ����������.
	/// ̳����� ��������� ComboBox algorithmSelectorDropDown 
	/// ��� ������� ������ ���������� (SelectionSort, HeapSort, SmoothSort).
	/// ̳����� ��������� CheckBox visualizeCheckBox ��� ����, 
	/// ��� ������, �� ������� ����������� ������ ���������� ������.
	/// ̳����� ��������� RichTextBox outputRichTextBox 
	/// ��� ������ ���������� ��� ������ ��������� ������ �� ����������.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		// ����� ����� �����, �� ���� ����������� ���������� �����, 
		// ���� ��������� ������ btnReset, � ����������� ������� �������.
		array<int>^ arr_;
		// �������� ������� ��������, ����� ���� ������ ������� ������ arr_.
		literal int kMaxVal_ = 50000;
		// �����, �� ��������������� ��� ���������� ��� ������, �� ���� ����������.
		int currSortableArrayIdx_;
		// ����� �����, � ��� ����������� ������� �����, 
		// �� ������ ������ ���������� ����� ����� ����� ����������� �� ��� ������.
		literal String^ kInitialArraysFolder_ = "initial_arrays\\";
		// ����� �����, � ��� ����������� ������� �����, 
		// �� ������ ���������� ������ ����� �����, ��� ������, ������� ����� ����������,
		// ������� ������������ �� ������� ��������, ��������� � ������ ����������.
		literal String^ kSortedArraysFolder_ = "sorted_arrays\\";
		// ����� �����-���� ������ ����������.
		array<String^>^ sortingAlgorithmsNames_;
	private: System::Windows::Forms::Button^ btnLoad;
	private: System::Windows::Forms::Button^ btnSave;

		   // ������������ ����� ������, �� ����� ������� ���� ���������� ���� �������������.
		literal int maxVisualizableArrSize_ = 200;

	public:
		/// <summary> ����������� ����� MainForm. </summary>
		MainForm(void);

	private:
		/// <summary> �����, �� �������� ����� sortingAlgorithmsNames_ ������� � ������� 
		/// ��������� ����������. </summary>
		void populateSortingAlgorithmsNamesArray();

	private:
		/// <summary> ����� ��� ���������� ���������� algorithmSelectorDropDown
		/// ���������� ������ sortingAlgorithms_. </summary>
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
	/// <summary> ����� ��� ������� ���������� �� ������ btnReset.
	/// ������ ����� ���������� ����� ����� arr_. 
	/// �������� �������� ����������� � ��������� outputRichTextBox. 
	/// ����� ������ �� ��������� visualizeCheckBox, ���� ��������� ������ > maxVisusalizableArrSize_.
	/// ������ ���������� ������ �� ��������� visualizeCheckBox. </summary>
	private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e);

	/// <summary> ����� ��������� ����������� ��� ��������� arr_ 
	/// � outputRichTextBox, �� ������ ����� ������ �� ������� �������� currSortableArrayIdx_. </summary>
	private: void printGenerationMessage();
	
    /// <summary> ����� ��������� n ���������� �������� ������ arr_, ���� arr_->Length > n.
	/// ������ ���������� ����� �����. </summary>
	private: void printRandomConsecutiveElementsOfArray(int n);

	/// <summary> ����� ��� ��������� ������ arr_ ������ arrSize.
	/// ������� �������� ������ arr_ ������������ ��������� ���� �������� � ����� �� 0 �� kMaxVal_.
	/// ����� ���'���, ��� ������ arr_ �� ���������, ���� arr_ != nullptr. </summary>
	/// <param name = "arrSize"> ��������� ������ ��� ���������. </param>
	private: void generateRandomArray(int arrSize);

	/// <summary> ����� ��� ���������� ������ ������ arr_ �� ������ ������ arr_ �� ���������� � ��������� ����.
	/// ��������� ���� ���������� � ����� � ������ initialArraysFolder_. </summary>
	/// <param name = "fileName"> ����� ���������� �����, � ���� ���� �������� ����� ������ ��
	/// ��� ����� �� ����������. </param>
	/// <returns> true, ���� ���� ������� ��������, ������ - false. </returns>
	private: bool saveInitialArrayToFile(String^ fileName);

	/// <summary> ����� ��� ���������� ������ ������ arr_, ������ ������ arr_ 
	/// ���� ����������, ����� ������ ����������, ������� ������������ �� ��������, 
	/// ��������� � ������ ����������, � ��������� ����.
	/// ��������� ���� ���������� � ����� � ������ sortedArrayFolder_. </summary>
	/// <param name = "fileName"> ����� ���������� �����, � ���� ���� �������� ���. </param>
	/// <param name = "compsCount"> ʳ������ ��������, ��������� � ������ ����������. </param>
	/// <param name = "swapsCount"> ʳ������ ������������, ��������� � ������ ����������. </param>
	/// <returns> true, ���� ���� ������� ��������, ������ - false. </returns>
	private: bool saveSortedArrayToFile(String^ fileName, long long compsCount, long long swapsCount);

	/// <summary> ����� ��� ��������� ����� ��������� �����, � ����� ��������������
	/// ����� �� ����������. </summary>
	/// <returns> ����� ��������� �����, � ���� ���� �������� ����� �� ����������. </returns>
	private: String^ generateInitialArrayFileName();

    /// <summary> ����� ��� ��������� ����������� ��� ���������� arr_ 
	/// �� ��������� ����� � ��������� outputRichTextBox. </summary>
	///	<param name = "compsCount"> ʳ������ ��������, ��������� � ������ ����������. </param>
	/// <param name = "swapsCount"> ʳ������ ������������, ��������� � ������ ����������. </param> 
	///	<param name = "initialArrayWasWrittenToFile"> �����, �� ���������� ���� ������ ���� ������ �������� � ����. </param>
	/// <param name = "sortedArrayWasWrittenToFile"> �����, �� ������������ ���� ������ ���� ������ �������� � ����. </param>   
	private: void printSortingMessage(bool initialArrayWasWrittenToFile, bool sortedArrayWasWrittenToFile, long long compsCount, long long swapsCount);

	/// <summary> ����� ��� ������� ���������� �� ������ btnSort.
	/// ������ ���������� ����� �� ���������� �����.
	/// ����� ����� ���������� ����� ����� arr_. 
	/// ������ ������������ ����� �� ���������� �����.
	/// �������� �������� ����������� � ��������� outputRichTextBox. </summary>
	private: System::Void btnSort_Click(System::Object^ sender, System::EventArgs^ e);

    /// <summary> �����, ���� ������� ��'��� �����, �� ���������� ���������
	/// ISortEngine, �������� �� �����, �������� ������������. </summary>
	/// <returns> ��'��� �����, �� ���������� ��������� ISortEngine, �� �������
	/// ������, �� ������ ������������. </returns>
	private: ISortEngine^ getConditionalSortEngine();

	/// <summary> �����, ���� ����� outputRichTextBox �� ������, ���� 
	/// ������� ��������� ������� �������� 2000. </summary>
	private: void updateOutputTextBox();

    /// <summary> ����� ��� ��������� ����� ��������� �����, � ����� ��������������
	/// ����� ���� ����������. </summary>
	/// <returns> ����� ��������� �����, � ���� ���� �������� ����� ���� ����������. </returns>
	private: String^ generateSortedArrayFileName();

    /// <summary> ����� ��� ������� ��䳿 "���� ������" ���������� outputRichTextBox.
	/// ���������� ����� ��������� outputRichTextBox � ���� ���������. </summary>
	private: System::Void outputRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e);

	private: void printLoadingMessage();

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);

	private: void printSavingMessage();
};
}
