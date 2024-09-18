#include "ComEx.h"

System::Void KursZoo::ComEx::ComEx_Load(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void KursZoo::ComEx::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Clear();
	textBox2->Clear();
	this->Close();
}

System::Void KursZoo::ComEx::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
      string FIO;
      string Number;
      bool Incorrect = false;
    if (textBox1->Text->Length == 0)
    {
        Incorrect = true;
        label4->BackColor = label4->BackColor;
        label4->ForeColor = System::Drawing::Color::Red;;
    }
    else
    {
        label4->BackColor = label4->BackColor;
        label4->ForeColor = System::Drawing::Color::White;
    }
    if (textBox2->Text->Length != 11)
    {
        Incorrect = true;
        label5->BackColor = label5->BackColor;
        label5->ForeColor = System::Drawing::Color::Red;;
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
                break;
            }
        }
        if (Incorrect == false)
        {
            label5->BackColor = label5->BackColor;
            label5->ForeColor = System::Drawing::Color::White;
        }
    }
    if (Incorrect == false)
    {
        FIO = Conv(textBox1->Text->ToString());
        Number = Conv(textBox2->Text->ToString());
        textBox1->Clear();
        textBox2->Clear();
        ComFormCh^ form = gcnew ComFormCh(FIO,Number,*_MainInfo);
        form->Show();
        this->Close();
    }
}
