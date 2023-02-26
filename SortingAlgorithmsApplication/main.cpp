#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew SortingAlgorithmsApplication::MainForm);

	return 0;
}