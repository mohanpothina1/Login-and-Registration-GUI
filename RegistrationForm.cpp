//---------------------------------------------------------------------------

#include <fmx.h>
#include<fstream>
#pragma hdrstop

#include "RegistrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TMyRegistrationForm::TMyRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyRegistrationForm::saveButtonClick(TObject *Sender)
{
	fstream myFile;
	myFile.open("registeredUsers.txt",ios::app);
	if(myFile.is_open()){
		AnsiString name = nameEdit->Text;
		AnsiString age = ageEdit->Text;
		AnsiString username = usernameEdit->Text;
		AnsiString password = passwordEdit->Text;

		myFile<<name<<","<<age<<","<<username<<","<<password<<"\n";

		myFile.close();
		this->Close();
	}
}
//---------------------------------------------------------------------------
