#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<wtypes.h>
#include<oleauto.h>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

#define DLL_API __declspec(dllexport)
class DLL_API Animals
{
	string Name;
	string Volier;
	string Class;
	map<int, string> Days;
public:
	Animals();
	Animals(const Animals& obj);
	virtual ~Animals();
	virtual string Get_Name();
	virtual string Get_Volier();
	virtual string Get_Class();
	virtual string Get_Days();
	virtual bool Check_Day(string stroka);
	virtual void Days_For_Entry(vector<int>& Result);
	virtual  Animals* Copy();
};

