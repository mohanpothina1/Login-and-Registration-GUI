//---------------------------------------------------------------------------

#include <fmx.h>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#pragma hdrstop
using namespace std;
#include "LoginForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
__fastcall TMyLoginForm::TMyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
vector<string> parseCommaDelimitedString(string line){
	vector<string> result;
	stringstream s_stream(line);

	while(s_stream.good()){
		string substr;
		getline(s_stream,substr,',');
		result.push_back(substr);
	}

	return result;
}

const char* convertToCharPtr(AnsiString ansiStr){
	return ansiStr.c_str();
}

void __fastcall TMyLoginForm::loginButtonClick(TObject *Sender)
{
	fstream myFile;

	myFile.open("registeredUsers.txt", ios::in);

	if(myFile.is_open()){
		string line;

		while(getline(myFile,line)){
					vector<string> parsedLine = parseCommaDelimitedString(line);
					const char* username = parsedLine.at(2).c_str();

//					AnsiString editUsername = usernameEdit->Text;
//					const char* usernameString = editUsername.c_str();

					if(strcmp(username, convertToCharPtr(usernameEdit->Text))==0){
						const char* password = parsedLine.at(3).c_str();

//						AnsiString editPassword = passwordEdit->Text;
//						const char* passwordString = editPassword.c_str();

						if(strcmp(password, convertToCharPtr(passwordEdit->Text))==0)
							messageLabel->Text = "Success";
							else
								messageLabel->Text = "Wrong Password!";
					}

		}
	}
}
//---------------------------------------------------------------------------
