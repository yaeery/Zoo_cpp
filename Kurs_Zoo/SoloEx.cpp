#include "SoloEx.h"
#include "MainInfo.h"
using namespace std;
using namespace System::Drawing;
System::Void KursZoo::SoloEx::SoloEx_Load(System::Object^ sender, System::EventArgs^ e)
{
    checkedListBox1->CheckOnClick = true;
    checkedListBox2->CheckOnClick = true;
    Sort_Name();
    _Maininfo->Data_Transfer();
    for (int i = 0; i < _Maininfo->Names.size(); i++)
    {

        String^ _name =  gcnew String(_Maininfo->Names[i].c_str());
        checkedListBox1->Items->Add(_name);
        delete _name;
    }
}

System::Void KursZoo::SoloEx::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    checkedListBox1->Items->Clear();
    checkedListBox2->Items->Clear();
    textBox1->Clear();
    textBox2->Clear();
    this->Close();
}

System::Void KursZoo::SoloEx::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool Incorrect = false;
    if (checkedListBox1->CheckedItems->Count == 0)
    {
        Incorrect = true;
        label2->BackColor = label2->BackColor;
        label2->ForeColor= System::Drawing::Color::Red;
    }
    else
    {
        label2->BackColor = label2->BackColor;
        label2->ForeColor = System::Drawing::Color::White;
    }
    if (checkedListBox2->CheckedItems->Count == 0)
    {
        Incorrect = true;
        label3->BackColor = label3->BackColor;
        label3->ForeColor = System::Drawing::Color::Red;
    }
    else
    {
        label3->BackColor = label3->BackColor;
        label3->ForeColor = System::Drawing::Color::White;
    }
    if (textBox1->Text->Length == 0)
    {
        Incorrect = true;
        label4->BackColor = label4->BackColor;
        label4->ForeColor = System::Drawing::Color::Red;
    }
    else
    {
        label4->BackColor = label4->BackColor;
        label4->ForeColor = System::Drawing::Color::White;
    }
    bool Incorrect_PH = false;
    if (textBox2->Text->Length != 11)
    {
        Incorrect = true;
        Incorrect_PH = true;
        label5->BackColor = label5->BackColor;
        label5->ForeColor = System::Drawing::Color::Red;
    }
    else
    {
        string x = Conv(textBox2->Text);
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] < '0' || x[i] > '9')
            {
                label5->BackColor = label5->BackColor;
                label5->ForeColor = System::Drawing::Color::Red;
                Incorrect = true;
                Incorrect_PH = true;
                break;
            }
        }
        if (Incorrect_PH == false)
        {
            label5->BackColor = label5->BackColor;
            label5->ForeColor = System::Drawing::Color::White;
        }

    }
    if (Incorrect==false)
    {
        string stroka = "";
        for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++)
        {
            stroka = stroka + Conv(checkedListBox1->CheckedItems[i]->ToString()) + " ";
        }
        stroka += "\n";
        stroka += Conv(checkedListBox2->SelectedItem->ToString());
        stroka += "\n";
        stroka += Conv(textBox1->Text->ToString());
        stroka += "\n";
        stroka += Conv(textBox2->Text->ToString());
        stroka += "\n";
        stroka += "#########";
        stroka += "\n";
        Recording_In_File(stroka);
        checkedListBox1->Items->Clear();
        checkedListBox2->Items->Clear();
        textBox1->Clear();
        textBox2->Clear();
        this->Close();
    }
}

System::Void KursZoo::SoloEx::checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    vector<string> Days ={ "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
    string stroka = "";
    for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++)
    {
        stroka += Conv(checkedListBox1->CheckedIndices[i].ToString());
    }

    string s = Animals_In_Day(stroka);
    checkedListBox2->Items->Clear();
    for (int i = 0; i < s.size(); i++)
    {
        String^ _Day = gcnew String(Days[s[i] - '0' - 1].c_str());
        checkedListBox2->Items->Add(_Day);
        delete _Day;
    }
    Days.clear();
    stroka.clear();
}

System::Void KursZoo::SoloEx::checkedListBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    for (int i = 0; i < checkedListBox2->Items->Count; i++)
    {
        if (i == checkedListBox2->SelectedIndex)
        {
            continue;
        }
        checkedListBox2->SetItemChecked(i, false);
    }
}
