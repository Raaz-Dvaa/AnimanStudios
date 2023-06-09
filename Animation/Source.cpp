#include "MyForm.h"

using namespace Animation;
[STAThreadAttribute]
void main(cli::array<System::String^>^ args)
{
	Application::Run(gcnew MyForm());
}