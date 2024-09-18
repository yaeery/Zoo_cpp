#pragma once
#include<string>
#include<vector>
#include"Conv.h"
#include "../Dll/Dll.h"
#include "MainForm.h"
#pragma comment(lib, "..\\bin\\Dll.lib")

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
static public class MainInfo
{
public:
    vector<string> Names;
    vector<string> Voliers;
    vector<string> Classes;
    vector<string> Days;
    string Stroka;

    MainInfo();
    ~MainInfo();
    void Data_Transfer();
};

