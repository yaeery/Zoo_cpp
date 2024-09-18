#pragma once
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllimport)
#else
#define DLL_API __declspec(dllexport)
#endif

#include"DB.h"

DLL_API void Create(void);
DLL_API string Get_Name(int index);
DLL_API string Get_Volier(int index);
DLL_API string Get_Class(int index);
DLL_API string Get_Days(int index);
DLL_API int Get_Size();
DLL_API void Sort_Name();
DLL_API void Sort_Volier();
DLL_API void Sort_Class();
DLL_API bool Check_Days(int index, string stroka);
DLL_API string Animals_In_Day(string Incl_Days);
DLL_API void Recording_In_File(string stroka);
DLL_API string Random_Ex();
DLL_API void  Recording_In_File_Com(string stroka);
DLL_API void Distructor();
DLL_API LONG_PTR Memory(wchar_t** s_array, int& s_len);