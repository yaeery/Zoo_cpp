#include "pch.h"
#include "Moray.h"
Moray::Moray()
{
	Name = "Мурена";
	Volier = "34";
	Class = "Рыбы";
	Days.insert(make_pair(1, "Понедельник"));
	Days.insert(make_pair(2, "Вторник"));
	Days.insert(make_pair(3, "Среда"));
}
string Moray::Get_Name()
{
	return Name;
}
Moray ::~Moray() {}
string Moray::Get_Volier()
{
	return Volier;
}
string Moray::Get_Class()
{
	return Class;
}
string Moray::Get_Days()
{
	string x;
	map<int, string> ::iterator first = Days.begin();
	map<int, string> ::iterator second = Days.end();
	second--;
	x = x + first->second + " - " + second->second;
	return x;
}
bool Moray::Check_Day(string dannye)
{
	vector<int> Days_Vectora;
	vector<int> Days_Dannie;
	vector<int> Itog;
	for (map<int, string>::iterator it = Days.begin(); it != Days.end(); it++)
	{
		Days_Vectora.push_back((*it).first);
	}
	for_each(dannye.begin(), dannye.end(), [&Days_Dannie](char x) {Days_Dannie.push_back((x)-'0'); });//Второй алгоритм
	set_intersection(Days_Vectora.begin(), Days_Vectora.end(), Days_Dannie.begin(), Days_Dannie.end(), inserter(Itog, Itog.begin())); // операция над множествами
	if (Itog.size() == dannye.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Moray::Days_For_Entry(vector<int>& Result)
{
	vector<int> Vector;
	vector<int> x;
	for (int i = 0; i < Days.size(); i++)
	{
		Vector.push_back(i + 1);
	}
	set_intersection(Result.begin(), Result.end(), Vector.begin(), Vector.end(), inserter(x, x.begin()));
	Result.swap(x);	//третий алгоритм
}

Animals* Moray::Copy()
{
	return new Moray(*this);
}
Moray::Moray(const Moray& obj) :Animals(obj)
{
	Name = obj.Name;
	Class = obj.Class;
	Volier = obj.Volier;
	Days = obj.Days;
}