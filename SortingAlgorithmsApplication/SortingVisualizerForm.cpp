#include "SortingVisualizerForm.h"

using namespace SortingAlgorithmsApplication;

SortingVisualizerForm::SortingVisualizerForm(array<int>^% arr, int maxVal) : maxVal_{ maxVal } {

	InitializeComponent();

	arr_ = arr;
	arrCopy_ = gcnew array<int>(arr_->Length);
	arr_->CopyTo(arrCopy_, 0);
	hCoefficient_ = getHeightCoefficient();
	wCoefficient_ = getWidthCoefficient();
	g_ = this->panel->CreateGraphics();
}

SortingVisualizerForm::~SortingVisualizerForm()
{
	if (components)
	{
		delete components;
	}

	if (arrCopy_) {
		delete arrCopy_;
	}

	if (g_) {
		delete g_;
	}
}

float SortingVisualizerForm::getHeightCoefficient() {
	return static_cast<float>(panel->Height) / static_cast<float>(maxVal_);
}

float SortingVisualizerForm::getWidthCoefficient() {
	return static_cast<float>(panel->Width) / static_cast<float>(arr_->Length);
}

void SortingVisualizerForm::InitializeComponent(void)
{
	this->panel = (gcnew System::Windows::Forms::Panel());
	this->SuspendLayout();
	// 
	// panel
	// 
	this->panel->Location = System::Drawing::Point(-1, 1);
	this->panel->Name = L"panel";
	this->panel->Size = System::Drawing::Size(1170, 700);
	this->panel->TabIndex = 0;
	// 
	// SortingVisualizerForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::SystemColors::Desktop;
	this->ClientSize = System::Drawing::Size(1169, 702);
	this->Controls->Add(this->panel);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = L"SortingVisualizerForm";
	this->ShowIcon = false;
	this->Text = L"SortingVisualizerForm";
	this->ResumeLayout(false);

}

void SortingVisualizerForm::drawHill(Brush^ brush, int idx, int val) {

	g_->FillRectangle(brush, idx * wCoefficient_, panel->Height - hCoefficient_ * val, wCoefficient_, static_cast<float>(panel->Height));
	g_->DrawRectangle(gcnew Pen(Brushes::Black), idx * wCoefficient_, panel->Height - hCoefficient_ * val, wCoefficient_, static_cast<float>(panel->Height));
}

void SortingVisualizerForm::visualizeArray() {

	g_->FillRectangle(Brushes::Black, 0, 0, panel->Width, panel->Height);

	for (int i = 0; i < arr_->Length; ++i) {
		drawHill(Brushes::White, i, arr_[i]);
	}
}

void SortingVisualizerForm::visualizeSwap(int i, int j) {

	drawHill(Brushes::Red, i, arrCopy_[i]);
	drawHill(Brushes::Red, j, arrCopy_[j]);

	int temp = arrCopy_[i];
	arrCopy_[i] = arrCopy_[j];
	arrCopy_[j] = temp;

	sleep_for(1.0s / arr_->Length);

	g_->FillRectangle(Brushes::Black, i * wCoefficient_, 0.0, wCoefficient_, static_cast<float>(panel->Height));
	g_->FillRectangle(Brushes::Black, j * wCoefficient_, 0.0, wCoefficient_, static_cast<float>(panel->Height));

	sleep_for(1ns);

	drawHill(Brushes::White, i, arr_[i]);
	drawHill(Brushes::White, j, arr_[j]);
}

void SortingVisualizerForm::visualizeComparison(int i, int j) {

	drawHill(Brushes::Yellow, i, arr_[i]);
	drawHill(Brushes::Yellow, j, arr_[j]);

	sleep_for(1.0s / arr_->Length);

	drawHill(Brushes::White, i, arr_[i]);
	drawHill(Brushes::White, j, arr_[j]);
}

void SortingVisualizerForm::visualizeSortingTest(int breakIdx) {

	sleep_for(0.5s);

	if (breakIdx == -1) {
		for (int i = 0; i < arr_->Length; ++i) {
			drawHill(Brushes::LawnGreen, i, arr_[i]);
			sleep_for(0.001s);
		}
	}
	else {
		int currIdx{ 0 };

		while (currIdx != breakIdx) {
			drawHill(Brushes::LawnGreen, currIdx, arr_[currIdx]);
			++currIdx;
			sleep_for(0.001s);
		}

		drawHill(Brushes::Red, currIdx, arr_[currIdx]);
	}

	sleep_for(0.5s);
}