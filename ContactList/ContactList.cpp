#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void Help();
void ShowAllContacts();
void EditContact();
void AddContact();
void DeleteContact();
void Print(string Text);

int Position = 0;
string Message;
string Name[10];
string Number[10];

int main()
{
	string Command;

	while (true)
	{
		system("cls");
		if (Message != "")
		{
			Print(Message + "\n\n");
			Message.clear();
		}

		Print("Please Insert Your Command! \n");
		Print("Also You Can Type <help> To See Available Commands \n\n");

		cin >> Command;
		system("cls");

		if (Command == "help")
			Help();
		else if (Command == "create")
			AddContact();
		else if (Command == "contacts")
			ShowAllContacts();
		else if (Command == "edit")
			EditContact();
		else if (Command == "delete")
			DeleteContact();
		else if (Command == "exit")
			return 0;
		else
			Message = "*** You Entered A Wrong Command ***";
	}

	return 0;
}


void AddContact()
{
	if (Position > 9)
	{
		Message = "*** Your Contact List Is Full ! ***";
		return;
	}

	string AddName;
	string AddNumber;
	Print("Create New Contact \n\n\n\n");
	Print("Please Insert Contact Name : \n");

	cin >> AddName;
	
	for (int i = 0; i < Name->length(); i++)
	{
		if (AddName == Name[i])
		{
			Message = "*** Sorry,There Is A Contact With This Name In Contact List Now ***";
			return;
		}
	}

	/*for each (string item in Name)
	{
		if (AddName == item)
		{
			Message = "*** Sorry,There Is A Contact With This Name In Contact List Now ***";
			return;
		}
	}*/

	Print("\nPlease Insert Contact Phone Number : \n");
	cin >> AddNumber;

	Name[Position] = AddName;
	Number[Position] = AddNumber;

	Position++;

	Message = "*** Your Contact Was Added To Contact List Successfuly ***";
}

void ShowAllContacts()
{
	Print("Contact List :  \n\n\n\n");
	Print("Index\t\t\tName\t\t\tPhone Number\n\n");

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1;
		Print("\t\t\t" + Name[i] + "\t\t\t" + Number[i] + "\n");
	}

	getchar();
	getchar();
}

void EditContact()
{
	string FindName;
	string EditName;
	string EditNumber;
	int EditPosition = -1;

	Print("Edit Contact : \n\n\n\n");
	Print("Insert Your Contact Name To Edit: \n");

	cin >> FindName;
	Print("\n");

	for (int i = 0; i < 9; i++)
	{
		if (FindName == Name[i])
		{
			EditPosition = i;
			break;
		}
	}

	if (EditPosition == -1)
	{
		Message = "*** There is No Contact With This Name ***";
		return;
	}

	Print("Please Insert New Name : \n");
	cin >> EditName;
	Print("\nPlease Insert New Phone Number : \n");
	cin >> EditNumber;

	Name[EditPosition] = EditName;
	Number[EditPosition] = EditNumber;

	Message = "*** Your Contact Was Edited Successfuly ***";
}

void DeleteContact()
{
	string FindName;
	int DeletePosition = -1;
	Print("Delete Contact :  \n\n\n\n");
	Print("Insert Your Contact Name To Delete: \n");
	cin >> FindName;
	Print("\n");

	for (int i = 0; i < 9; i++)
	{
		if (FindName == Name[i])
		{
			DeletePosition = i;
			break;
		}
	}

	if (DeletePosition == -1)
	{
		Message = "*** There Is No Contact With This Name ***";
		return;
	}

	Name[DeletePosition].clear();
	Number[DeletePosition].clear();

	if ((Position - DeletePosition) != 1)
	{
		for (int i = (DeletePosition + 1); i < Position; i++)
		{
			Name[i - 1] = Name[i];
			Number[i - 1] = Number[i];
		}
	}

	Position--;

	Name[Position].clear();
	Number[Position].clear();

	Message = "*** Your Contact Was Deleted Successfuly ***";
}

void Help()
{
	Print("Commands List : \n\n\n\n");
	string CommandList[6][2] = { {"create","Add A New Contact"},{"edit","Edit A Contact"},{"delete","Remove A Contact"},{"contacts","Show Contact List"},{"help","Show Available Commands"},{"exit","Close The Program"} };
	for (int i = 0; i < 6; i++)
	{
		Print("You Can Use <" + CommandList[i][0] + "> To " + CommandList[i][1] + "\n");
	}

	getchar();
	getchar();
}

void Print(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		cout << Text[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	/*for each (char C in Text)
	{
		cout << C;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}*/
}