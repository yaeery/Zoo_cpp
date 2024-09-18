#include "MainInfo.h"
MainInfo::MainInfo() {}
void MainInfo::Data_Transfer()
{
    Names.clear();
    Classes.clear();
    Days.clear();
    Voliers.clear();
    for (int i = 0; i < Get_Size(); i++)
    {
        if (Stroka.size() > 0)
        {
            if (Check_Days(i, Stroka) == true)
            {
                Names.push_back(Get_Name(i));
                Classes.push_back(Get_Class(i));
                Days.push_back(Get_Days(i));
                Voliers.push_back(Get_Volier(i));
            }
        }
        else
        {
            Names.push_back(Get_Name(i));
            Classes.push_back(Get_Class(i));
            Days.push_back(Get_Days(i));
            Voliers.push_back(Get_Volier(i));
        }
    }
}
MainInfo:: ~MainInfo()
{
    Names.clear();
    Classes.clear();
    Days.clear();
    Voliers.clear();
}
