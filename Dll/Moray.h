#pragma once
#include"Animals.h"
class DLL_API Moray : public Animals
{
	string Name;
	string Volier;
	string Class;
	map<int, string> Days;
public:
	Moray();
	Moray(const Moray& obj);
	~Moray();
	string Get_Name();
	string Get_Volier();
	string Get_Class();
	string Get_Days();
	bool Check_Day(string dannye);
	void Days_For_Entry(vector<int>& Result);
	Animals* Copy();
};

