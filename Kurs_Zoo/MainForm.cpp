#include "MainForm.h"
#include "DaysForm.h"
#include "SoloEx.h"
#include "ComEx.h"
#include "MemLeacksForm.h"
using namespace System;
using namespace System::Windows::Forms;

MainInfo* _MainInfo;
struct Leaks
{
	~Leaks()
	{
		_CrtDumpMemoryLeaks();
	}
};

[STAThreadAttribute]
void main(cli::array<String^>^ args)
{
	Leaks leaks;
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	KursZoo::MainForm form;
	Application::Run(% form);
}
System::Void KursZoo::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	_MainInfo = new MainInfo();
	Create();
	String^ name = gcnew String("Название");
	dataGridView1->Columns->Add("fir", name);
	delete name;
	name = gcnew String("Тип");
	dataGridView1->Columns->Add("sec", name);
	delete name;
	name = gcnew String("День недели");
	dataGridView1->Columns->Add("thi", name);
	delete name;
	name = gcnew String("Вольер");
	dataGridView1->Columns->Add("fou", name);
	delete name;
}

System::Void KursZoo::MainForm::button1_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	Sort_Name();
	Filling_Grid();	
}
System::Void KursZoo::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Sort_Class();
	Filling_Grid();
}
System::Void KursZoo::MainForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	Sort_Volier();
	Filling_Grid();
}
System::Void KursZoo::MainForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	DaysForm^ form = gcnew DaysForm(*_MainInfo);
	form->ShowDialog();
	Filling_Grid();
	_MainInfo->Stroka = "";
}
System::Void KursZoo::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	SoloEx^ form = gcnew SoloEx(*_MainInfo);
	form->Show();
}
System::Void KursZoo::MainForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	ComEx^ form = gcnew ComEx(*_MainInfo);
	form->Show();
}
System::Void KursZoo::MainForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	//_MainInfo->Names.clear();
	//_MainInfo->Voliers.clear();
	//_MainInfo->Classes.clear();
	//delete _MainInfo;
	////_MainInfo->Days.clear();
	//Distructor();
	//Application::Exit();
}
System::Void KursZoo::MainForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	MemLeacksForm^ form = gcnew MemLeacksForm(*_MainInfo);
	form->Show();
}
void KursZoo::MainForm::Filling_Grid()
{
	dataGridView1->Rows->Clear();
	_MainInfo->Data_Transfer();
	if (_MainInfo->Names.size() > 0)
	{
		for (int i = 0; i < _MainInfo->Names.size(); i++)
		{
			String^ _name = gcnew String(_MainInfo->Names[i].c_str());
			String^ _class = gcnew String(_MainInfo->Classes[i].c_str());
			String^ _day = gcnew String(_MainInfo->Days[i].c_str());
			String^ _volier = gcnew String(_MainInfo->Voliers[i].c_str());
			dataGridView1->Rows->Add(_name, _class, _day, _volier);
			delete _name;
			delete _class;
			delete _day;
			delete _volier;
		}
	}
}