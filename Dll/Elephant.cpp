#include "pch.h"
#include "Elephant.h"
Elephant::Elephant()
{
	Name = "Слон";
	Volier = "22";
	Class = "Млекопитающие";
	Days.insert(make_pair(1, "Понедельник"));
	Days.insert(make_pair(2, "Вторник"));
	Days.insert(make_pair(3, "Среда"));
	Days.insert(make_pair(4, "Четверг"));
	Days.insert(make_pair(5, "Пятница"));
	Days.insert(make_pair(6, "Суббота"));
}
string Elephant::Get_Name()
{
	return Name;
}
Elephant ::~Elephant() {}
string Elephant::Get_Volier()
{
	return Volier;
}
string Elephant::Get_Class()
{
	return Class;
}
string Elephant::Get_Days()
{
	string x;
	map<int, string> ::iterator first = Days.begin();
	map<int, string> ::iterator second = Days.end();
	second--;
	x = x + first->second + " - " + second->second;
	return x;
}
bool Elephant::Check_Day(string dannye)
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
void Elephant::Days_For_Entry(vector<int>& Result)
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

Animals* Elephant::Copy()
{
	return new Elephant(*this);
}
Elephant::Elephant(const Elephant& obj) :Animals(obj)
{
	Name = obj.Name;
	Class = obj.Class;
	Volier = obj.Volier;
	Days = obj.Days;
}