#include "ComFormCh.h"
System::Void KursZoo::ComFormCh::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    Recording_Into_File();
    this->Close();
}

void KursZoo::ComFormCh::Recording_Into_File()
{
    Main_String += "\n";
    Main_String += label2->Text;
    Main_String += "\n";
    Main_String += label3->Text;
    Main_String += "\n";
    Main_String += "#########";
    Main_String += "\n";
    string Return = Conv(Main_String->ToString());
    Recording_In_File_Com(Return);
    Main_String = "";
}

System::Void KursZoo::ComFormCh::ComFormCh_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ name = ("Название");
    dataGridView1->Columns->Add("fir", name);
    delete name;
    label2->Text = FIO->ToString();
    label3->Text = Phone_Number->ToString();
    _MainInfo->Data_Transfer();
    string x = Random_Ex();

    for (int i = 0; i < x.size(); i++)
    {
        String^ _name =  gcnew String((_MainInfo->Names[x[i] - '0']).c_str());
        dataGridView1->Rows->Add(_name);
        Main_String = Main_String + _name + " ";
        delete _name;
    }
}
