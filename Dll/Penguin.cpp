#include "pch.h"
#include "Penguin.h"
Penguin::Penguin()
{
	Name = "�������";
	Volier = "2";
	Class = "�����";
	Days.insert(make_pair(1, "�����������"));
	Days.insert(make_pair(2, "�������"));
	Days.insert(make_pair(3, "�����"));
	Days.insert(make_pair(4, "�������"));
}
string Penguin::Get_Name()
{
	return Name;
}
Penguin ::~Penguin() {}
string Penguin::Get_Volier()
{
	return Volier;
}
string Penguin::Get_Class()
{
	return Class;
}
string Penguin::Get_Days()
{
	string x;
	map<int, string> ::iterator first = Days.begin();
	map<int, string> ::iterator second = Days.end();
	second--;
	x = x + first->second + " - " + second->second;
	return x;
}
bool Penguin::Check_Day(string dannye)
{
	vector<int> Days_Vectora;
	vector<int> Days_Dannie;
	vector<int> Itog;
	for (map<int, string>::iterator it = Days.begin(); it != Days.end(); it++)
	{
		Days_Vectora.push_back((*it).first);
	}
	for_each(dannye.begin(), dannye.end(), [&Days_Dannie](char x) {Days_Dannie.push_back((x)-'0'); });//������ ��������
	set_intersection(Days_Vectora.begin(), Days_Vectora.end(), Days_Dannie.begin(), Days_Dannie.end(), inserter(Itog, Itog.begin())); // �������� ��� �����������
	if (Itog.size() == dannye.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Penguin::Days_For_Entry(vector<int>& Result)
{
	vector<int> Vector;
	vector<int> x;
	for (int i = 0; i < Days.size(); i++)
	{
		Vector.push_back(i + 1);
	}
	set_intersection(Result.begin(), Result.end(), Vector.begin(), Vector.end(), inserter(x, x.begin()));
	Result.swap(x);	//������ ��������
}

Animals* Penguin::Copy()
{
	return new Penguin(*this);
}
Penguin::Penguin(const Penguin& obj) :Animals(obj)
{
	Name = obj.Name;
	Class = obj.Class;
	Volier = obj.Volier;
	Days = obj.Days;
}