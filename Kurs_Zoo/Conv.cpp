#include "Conv.h"
using namespace System::Runtime::InteropServices;
std::string Conv(System::String^ stroka)
{
	std::string x;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(stroka)).ToPointer();
	x = chars;
	//Marshal::FreeHGlobal(IntPtr((void*)chars));
	//delete chars;
	return x;
}
