#include "MemLeacksForm.h"

System::Void KursZoo::MemLeacksForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void KursZoo::MemLeacksForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	delete _MainInfo;
	Distructor();
	wchar_t* s_array = 0;
	int s_len = 0;
	Memory(&s_array, s_len);
	String^ s = gcnew String(s_array);
	richTextBox1->Text = s;
}
