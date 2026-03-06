#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber(string St)
	{
		string AccNFrom = clsInputValidate::ReadStringWithMessage(St);
		while (!clsBankClient::IsClientExist(AccNFrom))
		{
			cout << "Account Number Dosen't Exist , enter another one  : " << endl;
			AccNFrom = clsInputValidate::ReadString();
		}
	
		return AccNFrom;
	}
	
	static int _ReadBalance(clsBankClient Client)
	{
		int Balance = clsInputValidate::ReadIntNumber();
		while(Balance > Client.AccountBalance)
		{
			cout << "Balance not in range : ";
			Balance = clsInputValidate::ReadIntNumber();
		}
		return Balance;
	}

public:

	static void ShowTransferScreen()
	{
		
		_DrawScreenHeader("Transfer Screen");

		
		string AccNFrom = _ReadAccountNumber("Enter Account Number to Transfer from : ");
		clsBankClient Client1 = clsBankClient::Find(AccNFrom);
		clsBankClient::PrintCardTransfer(Client1);

		string AccNTo = _ReadAccountNumber("Enter Account Number to transfer to : ");
		clsBankClient Client2 = clsBankClient::Find(AccNTo);
		clsBankClient::PrintCardTransfer(Client2);


		int Balance = _ReadBalance(Client1);

		Client1.Withdraw(Balance);
		Client2.Deposit(Balance);
		


	}

		

};

