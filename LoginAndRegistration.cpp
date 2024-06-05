//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("..\..\RegistrationForm.cpp", MyRegistrationForm);
USEFORM("..\..\LoginForm.cpp", MyLoginForm);
USEFORM("..\..\MainForm.cpp", MyMainForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMyLoginForm), &MyLoginForm);
		Application->CreateForm(__classid(TMyRegistrationForm), &MyRegistrationForm);
		Application->CreateForm(__classid(TMyMainForm), &MyMainForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
