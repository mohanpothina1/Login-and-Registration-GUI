//---------------------------------------------------------------------------

#include <fmx.h>
#include "LoginForm.h"
 #include "RegistrationForm.h"
 /*

						 */
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyMainForm *MyMainForm;
//---------------------------------------------------------------------------
__fastcall TMyMainForm::TMyMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyMainForm::loginNavigationButtonClick(TObject *Sender)
{
    MyLoginForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMyMainForm::registrationNavigationButtonClick(TObject *Sender)
{
	MyRegistrationForm->Show();
}
//---------------------------------------------------------------------------
