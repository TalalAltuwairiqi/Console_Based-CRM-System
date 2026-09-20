#include <iostream>
#include<fstream>
#include"clsPerson.h";
#include"clsString.h";
#include "clsBankClient.h";
#include "clsInputValidate.h"; 
#include"clsUtility.h"; 
#include<iomanip>
#include "clsLoginScreen.h";

#include "clsCurrency.h"

using namespace std; 

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}


static void _PrintCurrncy(clsCurrency Currency)
{

    cout << "Currency Card : " << endl;
    cout << "Country : " << Currency.Country() << endl; 
    cout << "Code : " << Currency.CurrencyCode() << endl; 
    cout << "Name : " << Currency.CurrencyName() << endl; 
    cout << "Rate : " << Currency.Rate() << endl; 
    cout << "________________________________" << endl; 

}

int main()
{

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }



 

    
    



    system("pause>0");
    return 0;
}

