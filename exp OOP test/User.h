#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include"Test.h"

using namespace std;

class User{
protected:
	int hashPass;
	int mark;
public:
	string login;
	virtual void menu() = 0;

	void Register()	{

		cout << "¬ведите логин : " << endl;
		getline(cin, login);
		cout << "¬ведите пароль : " << endl;
		string pa;
		hash<string> Pass;
		getline(cin, pa);
		int hashPass = Pass(pa);
		ofstream out;
		out.open("Accounts.txt", ios_base::app);
		out << login << endl;
		out << hashPass << endl;
		out.close();

	}
	void Login()	{
		cout << "¬ведите логин : " << endl;
		getline(cin, login);
		cout << "¬ведите пароль : " << endl;
		string pa;
		hash<string> Pass;
		getline(cin, pa);
		int hashPass = Pass(pa);
		ifstream out;
		out.open("Accounts.txt");
		int p;
		string l;
		while (cin >> l >> p)		{
			if (login == l && hashPass == p);
		}
	}
};
