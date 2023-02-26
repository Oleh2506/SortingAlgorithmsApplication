#include "MainForm.h"
#include <algorithm>

using namespace SortingAlgorithmsApplication;

MainForm::MainForm(void) : currSortableArrayIdx_{ 1 }
{
	InitializeComponent();
	populateSortingAlgorithmsNamesArray();
	populateDropDownAlgorithmSelector();
}

MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}

	if (arr_) {
		delete arr_;
	}

	if (sortingAlgorithmsNames_) {
		delete sortingAlgorithmsNames_;
	}
}

void MainForm::populateSortingAlgorithmsNamesArray() {

	int numberOfAlgorithms{ 3 };
	sortingAlgorithmsNames_ = gcnew array<String^>(numberOfAlgorithms);

	sortingAlgorithmsNames_[0] = "Selection Sort";
	sortingAlgorithmsNames_[1] = "Heap Sort";
	sortingAlgorithmsNames_[2] = "Smooth Sort";
}

void MainForm::updateOutputTextBox() {
	int maxTextLength{ 2000 };
	if (outputRichTextBox->Text->Length > maxTextLength) {
		outputRichTextBox->Text = "";
	}
}

void MainForm::populateDropDownAlgorithmSelector() {

	for (int i{ 0 }; i < sortingAlgorithmsNames_->Length; ++i) {
		algorithmSelectorDropDown->Items->Add(sortingAlgorithmsNames_[i]);
	}

	algorithmSelectorDropDown->SelectedIndex = 0;
}

void MainForm::InitializeComponent(void)
{
	this->outputRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
	this->arraySizeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->algorithmSelectorDropDown = (gcnew System::Windows::Forms::ComboBox());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->btnReset = (gcnew System::Windows::Forms::Button());
	this->btnSort = (gcnew System::Windows::Forms::Button());
	this->visualizeCheckBox = (gcnew System::Windows::Forms::CheckBox());
	this->btnLoad = (gcnew System::Windows::Forms::Button());
	this->btnSave = (gcnew System::Windows::Forms::Button());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arraySizeNumericUpDown))->BeginInit();
	this->SuspendLayout();
	// 
	// outputRichTextBox
	// 
	this->outputRichTextBox->Location = System::Drawing::Point(306, 12);
	this->outputRichTextBox->Name = L"outputRichTextBox";
	this->outputRichTextBox->ReadOnly = true;
	this->outputRichTextBox->Size = System::Drawing::Size(612, 271);
	this->outputRichTextBox->TabIndex = 1;
	this->outputRichTextBox->Text = L"";
	this->outputRichTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::outputRichTextBox_TextChanged);
	// 
	// arraySizeNumericUpDown
	// 
	this->arraySizeNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
	this->arraySizeNumericUpDown->Location = System::Drawing::Point(99, 12);
	this->arraySizeNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
	this->arraySizeNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
	this->arraySizeNumericUpDown->Name = L"arraySizeNumericUpDown";
	this->arraySizeNumericUpDown->Size = System::Drawing::Size(188, 22);
	this->arraySizeNumericUpDown->TabIndex = 2;
	this->arraySizeNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Location = System::Drawing::Point(12, 14);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(81, 17);
	this->label1->TabIndex = 3;
	this->label1->Text = L"Array Size: ";
	// 
	// algorithmSelectorDropDown
	// 
	this->algorithmSelectorDropDown->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->algorithmSelectorDropDown->FormattingEnabled = true;
	this->algorithmSelectorDropDown->Location = System::Drawing::Point(99, 41);
	this->algorithmSelectorDropDown->Name = L"algorithmSelectorDropDown";
	this->algorithmSelectorDropDown->Size = System::Drawing::Size(188, 24);
	this->algorithmSelectorDropDown->TabIndex = 4;
	// 
	// label2
	// 
	this->label2->AutoSize = true;
	this->label2->Location = System::Drawing::Point(12, 44);
	this->label2->Name = L"label2";
	this->label2->Size = System::Drawing::Size(71, 17);
	this->label2->TabIndex = 5;
	this->label2->Text = L"Algorithm:";
	// 
	// btnReset
	// 
	this->btnReset->Location = System::Drawing::Point(15, 89);
	this->btnReset->Name = L"btnReset";
	this->btnReset->Size = System::Drawing::Size(272, 44);
	this->btnReset->TabIndex = 6;
	this->btnReset->Text = L"Generate Random Array";
	this->btnReset->UseVisualStyleBackColor = true;
	this->btnReset->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
	// 
	// btnSort
	// 
	this->btnSort->Enabled = false;
	this->btnSort->Location = System::Drawing::Point(15, 139);
	this->btnSort->Name = L"btnSort";
	this->btnSort->Size = System::Drawing::Size(177, 44);
	this->btnSort->TabIndex = 7;
	this->btnSort->Text = L"Sort";
	this->btnSort->UseVisualStyleBackColor = true;
	this->btnSort->Click += gcnew System::EventHandler(this, &MainForm::btnSort_Click);
	// 
	// visualizeCheckBox
	// 
	this->visualizeCheckBox->AutoSize = true;
	this->visualizeCheckBox->Location = System::Drawing::Point(198, 152);
	this->visualizeCheckBox->Name = L"visualizeCheckBox";
	this->visualizeCheckBox->Size = System::Drawing::Size(86, 21);
	this->visualizeCheckBox->TabIndex = 8;
	this->visualizeCheckBox->Text = L"Visualize";
	this->visualizeCheckBox->UseVisualStyleBackColor = true;
	// 
	// btnLoad
	// 
	this->btnLoad->Location = System::Drawing::Point(15, 189);
	this->btnLoad->Name = L"btnLoad";
	this->btnLoad->Size = System::Drawing::Size(272, 44);
	this->btnLoad->TabIndex = 9;
	this->btnLoad->Text = L"Load";
	this->btnLoad->UseVisualStyleBackColor = true;
	this->btnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnLoad_Click);
	// 
	// btnSave
	// 
	this->btnSave->Location = System::Drawing::Point(15, 239);
	this->btnSave->Name = L"btnSave";
	this->btnSave->Size = System::Drawing::Size(272, 44);
	this->btnSave->TabIndex = 10;
	this->btnSave->Text = L"Save";
	this->btnSave->UseVisualStyleBackColor = true;
	this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
	// 
	// MainForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(930, 297);
	this->Controls->Add(this->btnSave);
	this->Controls->Add(this->btnLoad);
	this->Controls->Add(this->visualizeCheckBox);
	this->Controls->Add(this->btnSort);
	this->Controls->Add(this->btnReset);
	this->Controls->Add(this->label2);
	this->Controls->Add(this->algorithmSelectorDropDown);
	this->Controls->Add(this->label1);
	this->Controls->Add(this->arraySizeNumericUpDown);
	this->Controls->Add(this->outputRichTextBox);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->MaximizeBox = false;
	this->Name = L"MainForm";
	this->ShowIcon = false;
	this->Text = L"SortingAlgorithmsApp";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arraySizeNumericUpDown))->EndInit();
	this->ResumeLayout(false);
	this->PerformLayout();

}

void MainForm::generateRandomArray(int arrSize) {

	if (arr_) {
		delete arr_;
	}

	arr_ = gcnew array<int>(arrSize);

	int currMaxVal = kMaxVal_;
	int currMinVal = 0;

	Random^ randVal = gcnew Random();
	arr_[0] = randVal->Next(currMinVal, currMaxVal + 1);
	for (int i{ 1 }; i < arr_->Length; ++i) {
		arr_[i] = randVal->Next(currMinVal, currMaxVal + 1);
	}
}

bool MainForm::saveInitialArrayToFile(String^ fileName) {

	try {
		if (!IO::Directory::Exists(kInitialArraysFolder_)) {
			IO::Directory::CreateDirectory(kInitialArraysFolder_);
		}

		array<String^>^ files = IO::Directory::GetFiles(kInitialArraysFolder_);

		IO::StreamWriter^ sw = gcnew IO::StreamWriter(kInitialArraysFolder_ + fileName);
		sw->WriteLine("array size: " + Convert::ToString(arr_->Length));
		sw->WriteLine("initial array elements: ");

		for (int i{ 0 }; i < arr_->Length; ++i) {
			sw->WriteLine("array[" + Convert::ToString(i) + "]: \t" + Convert::ToString(arr_[i]));
		}
		sw->Close();
	}
	catch (Exception^) {
		MessageBox::Show("Unfortunately, initial array can't be written to file '" + fileName + "' in folder '" + kInitialArraysFolder_ + "'.", "Error");

		return false;
	}

	return true;
}

void MainForm::printGenerationMessage() {

	updateOutputTextBox();

	outputRichTextBox->Text += Convert::ToString(currSortableArrayIdx_) + ". \tArray of " +
		Convert::ToString(arr_->Length) + " random integers has been successfully generated.\n";
	int n{ 10 };
	printRandomConsecutiveElementsOfArray(n);
	outputRichTextBox->Text += "\n";
}

void MainForm::printRandomConsecutiveElementsOfArray(int n) {
	if (arr_->Length > n) {
		Random^ rand = gcnew Random();
		
		int idx{ rand->Next(0, arr_->Length - n + 1) };
		outputRichTextBox->Text += "\tarray[" + Convert::ToString(idx) + "] ... array[" + Convert::ToString(idx + n - 1) + "]:\n\t";

		for (int i{ 0 }; i < n; ++i) {
			outputRichTextBox->Text += Convert::ToString(arr_[idx]) + " ";
			++idx;
		}
	}
	else {
		outputRichTextBox->Text += "\tall elements of array:\n\t";
		for (int i{ 0 }; i < arr_->Length; ++i) {
			outputRichTextBox->Text += Convert::ToString(arr_[i]) + " ";
		}
	}
	outputRichTextBox->Text += "\n";
}

void MainForm::printSortingMessage(bool initialArrayWasWrittenToFile, bool sortedArrayWasWrittenToFile, long long compsCount, long long swapsCount) {

	updateOutputTextBox();

	outputRichTextBox->Text += Convert::ToString(currSortableArrayIdx_) + ". \tArray of " +
	Convert::ToString(arr_->Length) + " random integers has been successfully sorted.\n";

	if (initialArrayWasWrittenToFile) {
		outputRichTextBox->Text += "\tInitial array has been written to file \"" + generateInitialArrayFileName() + "\".\n";
	}
	if (sortedArrayWasWrittenToFile) {
		outputRichTextBox->Text += "\tSorted array has been written to file \"" + generateSortedArrayFileName() + "\".\n";
	}
	int n{ 10 };
	printRandomConsecutiveElementsOfArray(n);
	outputRichTextBox->Text += "\tsorting algorithm: \t" + Convert::ToString(sortingAlgorithmsNames_[algorithmSelectorDropDown->SelectedIndex]) + 
	"\n\tcomparisons: \t" + Convert::ToString(compsCount) + "\n\tswaps: \t\t" + Convert::ToString(swapsCount) + "\n\n";
}

bool MainForm::saveSortedArrayToFile(String^ fileName, long long compsCount, long long swapsCount) {

	try {
		if (!IO::Directory::Exists(kSortedArraysFolder_)) {
			IO::Directory::CreateDirectory(kSortedArraysFolder_);
		}

		IO::StreamWriter^ sw = gcnew IO::StreamWriter(kSortedArraysFolder_ + fileName);

		sw->WriteLine("sorting algorithm: " + sortingAlgorithmsNames_[algorithmSelectorDropDown->SelectedIndex]);
		sw->WriteLine("comparisons: \t" + Convert::ToString(compsCount));
		sw->WriteLine("swaps: \t\t" + Convert::ToString(swapsCount));
		sw->WriteLine("array size: \t" + System::Convert::ToString(arr_->Length));
		sw->WriteLine("sorted array elements: ");

		for (int i{ 0 }; i < arr_->Length; ++i) {
			sw->WriteLine("array[" + Convert::ToString(i) + "]: \t" + Convert::ToString(arr_[i]));
		}
		sw->Close();
	}
	catch (Exception^) {
		MessageBox::Show("Unfortunately, sorted array can't be written to file '" + fileName + "' in folder '" + kSortedArraysFolder_ + "'.", "Error");

		return false;
	}

	return true;
}

String^ MainForm::generateInitialArrayFileName() {
	return "initial_array_" + Convert::ToString(currSortableArrayIdx_) + ".txt";
}

ISortEngine^ MainForm::getConditionalSortEngine() {

	ISortEngine^ se;
	bool visualized = (visualizeCheckBox->Enabled && visualizeCheckBox->Checked);


	for (int i{ 0 }; i < sortingAlgorithmsNames_->Length; ++i) {

	}
	switch (algorithmSelectorDropDown->SelectedIndex)
	{
	case 0: {
		if (visualized) {
			se = gcnew VisualizableSelectionSortEngine(arr_, kMaxVal_);
		}
		else {
			se = gcnew SelectionSortEngine(arr_);
		}
		break;
	}
	case 1: {
		if (visualized) {
			se = gcnew VisualizableHeapSortEngine(arr_, kMaxVal_);
		}
		else {
			se = gcnew HeapSortEngine(arr_);
		}
		break;
	}
	case 2: {
		if (visualized) {
			se = gcnew VisualizableSmoothSortEngine(arr_, kMaxVal_);
		}
		else {
			se = gcnew SmoothSortEngine(arr_);
		}
		break;
	}
	default:
		break;
	}

	return se;
}

String^ MainForm::generateSortedArrayFileName() {
	return "sorted_array_" + Convert::ToString(currSortableArrayIdx_) + ".txt";
}

System::Void MainForm::btnSort_Click(System::Object^ sender, System::EventArgs^ e) {
	
	bool initialArrayWasWrittenToFile{ saveInitialArrayToFile(generateInitialArrayFileName()) };

	ISortEngine^ se = getConditionalSortEngine();
	se->sort();

	bool sortedArrayWasWrittenToFile{ saveSortedArrayToFile(generateSortedArrayFileName(), se->getComparisonsCount(), se->getSwapsCount()) };

	printSortingMessage(initialArrayWasWrittenToFile, sortedArrayWasWrittenToFile, se->getComparisonsCount(), se->getSwapsCount());

	if (se) {
		delete se;
	}

	++currSortableArrayIdx_;
}

System::Void MainForm::outputRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	outputRichTextBox->SelectionStart = outputRichTextBox->Text->Length;
	outputRichTextBox->ScrollToCaret();
}

System::Void MainForm::btnReset_Click(System::Object^ sender, System::EventArgs^ e) {
	
	int arrSize{ arraySizeNumericUpDown->Value };

	generateRandomArray(arrSize);

	printGenerationMessage();

	if (!btnSort->Enabled) {
		btnSort->Enabled = true;
	}

	if (arr_->Length > maxVisualizableArrSize_) {
		visualizeCheckBox->Enabled = false;
	}
	else {
		visualizeCheckBox->Enabled = true;
	}
}

void MainForm::printLoadingMessage() {

	updateOutputTextBox();

	outputRichTextBox->Text += Convert::ToString(currSortableArrayIdx_) + ". \tArray of " +
		Convert::ToString(arr_->Length) + " integers has been successfully loaded.\n";
	int n{ 10 };
	printRandomConsecutiveElementsOfArray(n);
	outputRichTextBox->Text += "\n";
}

System::Void MainForm::btnLoad_Click(System::Object^ sender, System::EventArgs^ e) {

	OpenFileDialog^ dlg = gcnew OpenFileDialog;
	dlg->InitialDirectory = "c:\\";
	dlg->Title = "Open text file";
	dlg->FilterIndex = 2;
	dlg->RestoreDirectory = true;
	dlg->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";

	try  {
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			IO::StreamReader^ sr = IO::File::OpenText(dlg->FileName);

			if (arr_) {
				delete arr_;
			}

			arr_ = gcnew array<int>(Convert::ToInt32(sr->ReadLine()));

			for (int i{ 0 }; i < arr_->Length; ++i) {
				int temp = Convert::ToInt32(sr->ReadLine());
				if (temp >= 0 && temp <= kMaxVal_) {
					arr_[i] = temp;
				}
				else {
					throw;
				}
			}

			sr->Close();

			printLoadingMessage();

			if (!btnSort->Enabled) {
				btnSort->Enabled = true;
			}

			if (arr_->Length > maxVisualizableArrSize_) {
				visualizeCheckBox->Enabled = false;
			}
			else {
				visualizeCheckBox->Enabled = true;
			}
		}
	}
	catch (Exception^) {
		MessageBox::Show("Can\'t read from file.", "Error");
	}
}

System::Void MainForm::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {

	SaveFileDialog^ dlg = gcnew SaveFileDialog();
	dlg->InitialDirectory = "c:\\";
	dlg->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	dlg->FilterIndex = 2;
	dlg->RestoreDirectory = true;
	dlg->Title = "Write array to text file";
	dlg->DefaultExt = "txt";

	try {
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			IO::StreamWriter^ sw = gcnew IO::StreamWriter(dlg->FileName);

			if (arr_) {
				sw->WriteLine("array size: " + Convert::ToString(arr_->Length));
				sw->WriteLine("array elements: ");

				for (int i{ 0 }; i < arr_->Length; ++i) {
					sw->WriteLine("array[" + Convert::ToString(i) + "]: \t" + Convert::ToString(arr_[i]));
				}

				printSavingMessage();
			}
			else {
				sw->WriteLine("array is undefined");
			}

			sw->Close();
		}
	}
	catch (Exception^) {
		MessageBox::Show("Can\'t save to file.", "Error");
	}
}

void MainForm::printSavingMessage() {

	updateOutputTextBox();

	outputRichTextBox->Text += Convert::ToString(currSortableArrayIdx_) + ". \tArray of " +
		Convert::ToString(arr_->Length) + " integers has been successfully saved to text file.\n";
	int n{ 10 };
	printRandomConsecutiveElementsOfArray(n);
	outputRichTextBox->Text += "\n";
}