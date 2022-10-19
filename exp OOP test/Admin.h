#pragma once
#include"User.h"

class Admin : public User	{
	void menu()override		{
		do {
			system("cls");
			cout << "Меню бога" << endl;
			cout << "1.Создать тест\n";
			cout << "2.Регистрация\n";
			cout << "3.Статистика\n";
			cout << "4.Выход\n";
			int c;
			cin >> c;
			cin.ignore();
			switch (c)	{
			case 1:
				createTest();
				break;
			case 2:
				Register();
				break;
			case 3:
				AdminStatistic();
				break;
			case 4:
				return;
			default:
				break;
			}
		} while (true);
	}
	void createTest()	{
		auto test = new Test;
		test->createTest();
	}

	void AdminStatistic()	{
		system("cls");
		string path = "logins.txt";
		ifstream name;
		name.open(path);
		string log;
		vector<string> logins;
		while (!name.eof())		{
			getline(name, login);
			logins.push_back(login);
		}
		name.close();
		for (size_t i = 0; i < logins.size(); i++)		{
			cout << i + 1 << "." << logins[i] << endl;
		}
		cout << "Выберите студента: " << endl;
		int ch;
		cin >> ch;
		ch = ch - 1;
		system("cls");
		cout << "Статистика по студенту : " << endl;
		string way = "Stats\\" + logins[ch] + ".txt";
		ifstream Stat;
		Stat.open(way);
		char result;
		while (Stat.get(result))		{
			cout << result;
		}
		Stat.close();
		system("pause");
	}
};

