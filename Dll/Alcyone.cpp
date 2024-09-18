#include "pch.h"
#include "Alcyone.h"
Alcyone::Alcyone()
{
	Name = "��������";
	Volier = "39";
	Class = "�����";
	Days.insert(make_pair(1, "�����������"));
	Days.insert(make_pair(2, "�������"));
	Days.insert(make_pair(3, "�����"));
	Days.insert(make_pair(4, "�������"));
	Days.insert(make_pair(5, "�������"));
	Days.insert(make_pair(6, "�������"));
	Days.insert(make_pair(7, "�����������"));
}
string Alcyone::Get_Name()
{
	return Name;
}
Alcyone ::~Alcyone() {}
string Alcyone::Get_Volier()
{
	return Volier;
}
string Alcyone::Get_Class()
{
	return Class;
}
string Alcyone::Get_Days()
{
	string x;
	map<int, string> ::iterator first = Days.begin();
	map<int, string> ::iterator second = Days.end();
	second--;
	x = x + first->second + " - " + second->second;
	return x;
}
bool Alcyone::Check_Day(string dannye)
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
void Alcyone::Days_For_Entry(vector<int>& Result)
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

Animals* Alcyone::Copy()
{
	return new Alcyone(*this);
}
Alcyone::Alcyone(const Alcyone& obj) :Animals(obj)
{
	Name = obj.Name;
	Class = obj.Class;
	Volier = obj.Volier;
	Days = obj.Days;
}