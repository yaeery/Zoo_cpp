#include "DaysForm.h"
#include<vector>
using namespace std;

System::Void KursZoo::DaysForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    vector<int> vec;
    for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++)
    {
        vec.push_back(checkedListBox1->CheckedIndices[i] + 1);
    }
    if (vec.size() == 0)
    {
        for (int i = 0; i < 7; i++)
        {
            vec.push_back(i + 1);
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        _MainInfo->Stroka += to_string(vec[i]);
    }
    vec.clear();
    checkedListBox1->Items->Clear();
    this->Close();
}

System::Void KursZoo::DaysForm::DaysForm_Load(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void KursZoo::DaysForm::checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void KursZoo::DaysForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
}
