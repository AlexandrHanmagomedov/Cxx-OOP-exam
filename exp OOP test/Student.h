#pragma once
#include "User.h"

class Student : public User	{
		void testing()	{
		ifstream in("testName.txt");
		string testN;
		vector<string> tn;
		int TrueAnswers = 0;
		while (getline(in, testN))		{
			tn.push_back(testN);
		}
		in.close();
		for (size_t i = 0; i < tn.size(); i++)		{
			cout << i + 1 << " " << tn[i] << endl;
		}
		int c;
		cin >> c;
		cin.ignore();
		auto test = new Test;
		in.open("categorys\\" + tn[c - 1] + ".txt");
		getline(in, test->name);
		int lenQ;
		in >> lenQ;
		string buff;
		getline(in, buff);

		system("cls");
		for (size_t i = 0; i < lenQ; i++)		{
			Question q;
			getline(in, q.question);
			int lenA;
			in >> lenA;
			getline(in, buff);
			for (size_t i = 0; i < lenA; i++)			{
				string ans;
				getline(in, ans);
				q.answers.push_back(ans);
			}
			test->questions.push_back(q);
			in >> q.numTrueAnswer;
			getline(in, buff);

			test->print();

			cout << endl << "Введите " << i + 1 << " ответ : ";

			int answer;
			cin >> answer;
			if (answer == q.numTrueAnswer) TrueAnswers++;

			system("cls");
		}
		in.close();
		mark = (12 / test->questions.size()) * TrueAnswers;
		cout << "Ваша оценка : " << mark << endl;
		ofstream Stat("Stats\\" + login + ".txt", ios_base::app);
		Stat << test->name << endl;
		Stat << mark << endl;
		Stat << endl;
		Stat.close();
		system("pause");
	}

	void Statistic()	{

		system("cls");
		cout << "Ваш результат : " << endl;
		string path = "Stats\\" + login + ".txt";
		ifstream Stat;
		Stat.open(path);
		char result;
		while (Stat.get(result)){
			cout << result;
		}
		Stat.close();
		system("pause");
	}

	void menu()override	{
		do {
			system("cls");
			cout << "Меню студента" << endl;
			cout << "1.Тестирование\n";
			cout << "2.Статистика\n";
			cout << "3.Выход\n";
			int c;
			cin >> c;
			cin.ignore();
			switch (c)
			{
			case 1:
				testing();
				break;
			case 2:
				Statistic();
				break;
			case 3:
				return;
			default:
				break;
			}
		} while (true);
	}
};

