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
	/// ���� ��� ���������� ����������� ������� ���������� ������.
	/// ̳����� ��������� panel, ���� ��������������� �� ��� ��� �����������
	/// ���������, ������� ��� ��������� � ������� ���� �������� ��
	/// �������� � ������������, �� ����������� � ������� ���������� ������.
	/// </summary>
	public ref class SortingVisualizerForm : public System::Windows::Forms::Form
	{
	private:
		// ������� �����, ���� ��������������� ��� ����������� �������� �������� �������
	    // ���������� ������.
		Graphics^ g_;
		// �����, ���� ���� �����������.
		array<int>^ arr_;
		// ����������� ��������, ����� ���� �������� ������� ������ arr_.
		int maxVal_;
		// ���� ������������ ������, ��� ���� ����������������� ��� ����������� �������
		// ������������ ��������.
		array<int>^ arrCopy_;
		// ����������, ���� ��� ����������� ��� ������������� ������ ������� ��������� �� ���
		// ���������� ������� ����������.
		float hCoefficient_;
		// ����������, ���� ��� ����������� ��� ������������� ������ ������� ��������� �� ���
		// ���������� ������� ����������.
		float wCoefficient_;

	/// <summary> ����������� ����� SortingVisualizerForm. </summary>
	public: SortingVisualizerForm(array<int>^% arr, int maxVal);

    /// <summary> ���������� hCoefficient_. </summary>
	/// <returns> ��������  hCoefficient_. </returns>
	private: float getHeightCoefficient();

	/// <summary> ���������� wCoefficient_. </summary>
	/// <returns> ��������  wCoefficient_. </returns>
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

	/// <summary> ����� ��� ���������� ����������� ������ ������� ���������. </summary>
	/// <param name = "brush"> ���� �������. </param>
	/// <param name = "idx"> ������ �������� ������, ���� ������������. </param>
	/// <param name = "val"> �������� �������� ������, ���� ������������. </param>
	private: void drawHill(Brush^ brush, int idx, int val);

	/// <summary> ����� ��� ���������� ����������� ������ ������ arr_. </summary>
	public: void visualizeArray();

    /// <summary> ����� ��� ���������� ����������� ������� ������������ ���� �������� ������. </summary>
	/// <param name = "i"> ������ �������� ���� ���������������. </param>
	/// <param name = "j"> ������ �������� ���� ���������������. </param>
	public: void visualizeSwap(int i, int j);

	/// <summary> ����� ��� ���������� ����������� ������� ��������� ���� �������� ������. </summary>
	/// <param name = "i"> ������ �������� ���� ����������� � ����� ���������. </param>
	/// <param name = "j"> ������ �������� ���� ����������� � ����� ���������. </param>
	public: void visualizeComparison(int i, int j);

	/// <summary> ����� ��� ���������� ����������� ������� �������� ������ �� �������������. </summary>
	/// <param name = "breakIdx"> ������ ������� ��������, ���� ������ ����� ������������� ������. </param>
	public: void visualizeSortingTest(int breakIdx);
	};
}
