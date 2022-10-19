#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<map>
#include<string>
#include<conio.h>
#include<stdlib.h>

#include"User.h"
#include"Test.h"

#include"Admin.h"
#include"Student.h"

using namespace std;


class Prog
{
	User* user;

public:
	void Register()	{
		system("cls");
		string login;
		cout << "Введите логин: " << endl;
		getline(cin, login);
		string path = "logins.txt";
		ifstream name;
		name.open(path);
		string log;
		while (!name.eof()){
			string Verify;
			getline(name, Verify);
			if (Verify == login){
				cout << "Такой логин уже есть " << endl;
				exit(1);
			}
		}
		name.close();
		cout << "Введите пароль : " << endl;
		string pa;
		hash<string> Pass;
		int c = 0;
		do{
			c = _getch();
			if (c != 13){
				pa += c;
				cout << "*";
			}
		} while (c != 13);
		int hashPass = Pass(pa);
		ofstream out;
		out.open("Accounts.txt", ios_base::app);
		out << login << endl;
		out << hashPass << endl;
		out.close();
		ofstream lo;
		lo.open("Logins.txt", ios_base::app);
		lo << endl << login;
		lo.close();
	}

	void menu()	{
		do {
			system("cls");
			cout << "1.Вход\n";
			cout << "2.Регистрация\n";
			cout << "3.Выход\n";
			int c;
			cin >> c;
			cin.ignore();
			switch (c)
			{
			case 1:
				Login();
				break;
			case 2:
				Register();
				break;
			case 3:
				exit(0);
			default:
				break;
			}
		} while (true);
	}
	void Login(){
		system("cls");
		string login;
		cout << "Введите логин: " << endl;
		getline(cin, login);
		cout << "Введите пароль: " << endl;
		string pa;
		hash<string> Pass;
		int c = 0;
		do{
			c = _getch();
			if (c != 13){
				pa += c;
				cout << "x";
			}
		} while (c != 13);
		int hashPass = Pass(pa);
		ifstream in;
		in.open("Accounts.txt");
		int p;
		string l;
		while (in >> l >> p){
			if (login == l && hashPass == p){
				if (login == "admin"){
					user = new Admin;
				}
				else{
					user = new Student;
				}
				in.close();
				break;
			}
		}
		user->login = login;
		user->menu();
	}
};
