#include "pch.h"
#include "DB.h"
DB::DB() {}
DB::~DB()
{
	for (int i = 0; i < Vec.size(); i++)
	{
		delete Vec[i];
	}
}

vector<Animals*>&  DB::Get_Vec()
{
	return Vec;
}
void  DB::Set_Vec()
{
	Vec.push_back(new Rhinoceros());
	Vec.push_back(new Elephant());
	Vec.push_back(new Moray());
	Vec.push_back(new Penguin());
	Vec.push_back(new Python());
	Vec.push_back(new Alcyone());
	Vec.push_back(new Triton());

}
void  DB::Sort_Name()
{
	sort(Vec.begin(), Vec.end(), [](Animals* first, Animals* second) {return first->Get_Name() < second->Get_Name(); }); //первый алгоритм 
}
void  DB::Sort_Volier()
{
	sort(Vec.begin(), Vec.end(), [](Animals* first, Animals* second) {return stoi(first->Get_Volier()) < stoi(second->Get_Volier()); });
}
void  DB::Sort_Class()
{
	sort(Vec.begin(), Vec.end(), [](Animals* first, Animals* second) {return first->Get_Class() < second->Get_Class(); });
}
DB::DB(const DB& obj)
{
	for (int i = 0; i < Vec.size(); i++)
	{
		Vec.push_back(obj.Vec[i]->Copy());
	}
}
DB* DB::Copy()
{
	return new DB(*this);
}

DB& DB::operator= (const DB& new_)
{
	if (this == &new_)
	{
		return *this;
	}

	for (vector<Animals*>::const_iterator it = this->Vec.begin(); it != this->Vec.end(); ++it)
	{
		delete (*it);
	}
	this->Vec.clear();

	for (vector<Animals*>::const_iterator it = new_.Vec.begin(); it != new_.Vec.end(); ++it)
	{
		this->Vec.push_back((*it)->Copy());
	}

	return *this;
}