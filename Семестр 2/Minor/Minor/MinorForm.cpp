#include "MinorForm.h"
#include "Game.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Minor::MinorForm form;
	Application::Run(% form);
}