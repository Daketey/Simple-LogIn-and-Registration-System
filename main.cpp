#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int main()
{
	int choice;
	cout << "\n1. Do you want to Register? \n2. Do you want to Login? \n\n3. Please enter your choice here: ";
	cin >> choice;

	if (choice == 1)
	{
		string username, password;

		cout << "Please select a username of your choice: ";
		cin >> username;
		cout << "Please select a password of your choice: ";
		cin >> password;


		ofstream file;

		file.open(username + ".txt");
        file << username << endl << password;
        file.close();

		main();
	}

	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "Login Failed! Please try again.\n" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Login Succesfull! Continue...\n" << endl;
			system("PAUSE");
			return 1;
		}
	}
}