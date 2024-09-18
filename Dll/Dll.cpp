#include "pch.h"
#include "framework.h"
#include "Dll.h"
#include<fstream>
#include "ctime"
#include <Objbase.h>
#include<strsafe.h>

DB db;
int* Check = new int; //-контроль утечек 4 байта
void DLL_API Create(void)
{
     db.Set_Vec();
}
string DLL_API Get_Name(int index)
{
    return db.Get_Vec()[index]->Get_Name().c_str();
}
string DLL_API Get_Volier(int index)
{
    return db.Get_Vec()[index]->Get_Volier().c_str();
}
string DLL_API Get_Class(int index)
{
    return db.Get_Vec()[index]->Get_Class().c_str();
}
string DLL_API Get_Days(int index)
{
    return db.Get_Vec()[index]->Get_Days().c_str();
}
int DLL_API Get_Size()
{
    return db.Get_Vec().size();
}
void DLL_API Sort_Name()
{
    db.Sort_Name();
}
void DLL_API Sort_Volier()
{
    db.Sort_Volier();
}
void DLL_API Sort_Class()
{
    db.Sort_Class();
}
bool DLL_API Check_Days(int index, string stroka)
{
    return  db.Get_Vec()[index]->Check_Day(stroka);
}
string DLL_API Animals_In_Day(string Incl_Days)
{
    vector<int> Result{ 1,2,3,4,5,6,7 };
    string Return;
    for (int i = 0; i < Incl_Days.size(); i++)
    {
        db.Get_Vec()[Incl_Days[i] - '0']->Days_For_Entry(Result);
    }
    for (int i = 0; i < Result.size(); i++)
    {
        Return += to_string(Result[i]);
    }
    return Return;
}
string DLL_API Random_Ex()
{
    int position = rand() % (db.Get_Vec().size() - 2) + 1;;
    vector<int> Vector;
    for (int i = 0; i < db.Get_Vec().size(); i++)
    {
        Vector.push_back(i);
    }
    pair<vector<int>::iterator, vector<int>::iterator> result_bound = equal_range(Vector.begin(), Vector.end(), position);//equal_range
    string s = to_string(*result_bound.first);
    s = s + to_string(*result_bound.second);

    return s;
}
void Recording_In_File(string stroka)
{
    string Old;
    fstream file;
    file.open("../Excursion_Solo.txt");
    string infile;
    for (;;)
    {
        getline(file, infile);
        if (file.eof())
        {
            infile.clear();
            break;
        }
        Old = Old + infile + "\n";
    }
    file.close();
    Old += stroka;
    file.open("../Excursion_Solo.txt");
    file << Old;
    file.close();
    Old.clear();
    infile.clear();
}
void DLL_API Recording_In_File_Com(string stroka)
{
    string Old;
    fstream file;
    file.open("../Excursion_Common.txt");
    string infile;
    for (;;)
    {
        getline(file, infile);
        if (file.eof())
        {
            infile.clear();
            break;
        }
        Old = Old + infile + "\n";
    }
    file.close();
    Old += stroka;
    file.open("../Excursion_Common.txt");
    file << Old;
    file.close();
    Old.clear();
    infile.clear();
}

DLL_API LONG_PTR Memory(wchar_t** s_array, int& s_len) {
    HANDLE hLogFile;
    hLogFile = CreateFile(L"log.txt", GENERIC_WRITE,
        FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, NULL);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, hLogFile);
    _CrtDumpMemoryLeaks();
    CloseHandle(hLogFile);
    wifstream in(L"log.txt");
    wstring  ws((istreambuf_iterator<wchar_t >(in)), istreambuf_iterator<wchar_t>());
    wchar_t* n_sarr = (wchar_t*)CoTaskMemAlloc((ws.size() + 1) * sizeof(wchar_t*));
    ZeroMemory((n_sarr), (ws.size() + 1) * sizeof(wchar_t));
    StringCchCatW(n_sarr, ws.size() + 1, ws.data());

    *s_array = n_sarr;
    s_len = ws.size() + 1;
    return 1;
}


DLL_API void Distructor()
{
    db.~DB();
}
