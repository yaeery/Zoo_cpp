#pragma once
#include"Animals.h"
#include"Rhinoceros.h"
#include"Elephant.h"
#include"Triton.h"
#include"Python.h"
#include"Penguin.h"
#include"Alcyone.h"
#include"Moray.h"
class DB
{
	vector<Animals*> Vec;
public:
	vector<Animals*>& Get_Vec();
	void Set_Vec();
	DB();
	~DB();
	void Sort_Name();
	void Sort_Volier();
	void Sort_Class();
	DB(const DB& obj);
	DB* Copy();
	DB& operator= (const DB& new_);

};