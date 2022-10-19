#pragma once
#include"Questions.h"

class Test
{
public:
	string Category;
	string name;
	vector<Question> questions;

	Test() {}
	Question addQuestion()	{
		Question q;
		q.setQuestion();
		bool continue_ = false;
		do		{
			q.addAnswer();
			cout << "1-Правильно, 0-Неправильно :";
			cin >> continue_;
			cin.ignore();
		} while (continue_);
		q.setNumTrueAnswer();
		return q;
	}

	void SetTestName()	{
		cout << "Имя теста:";
		getline(cin, name);
	}
	void SetCategoryName()	{
		cout << "Название категории :";
		getline(cin, Category);
		string path = "Categorys.txt";
		ifstream ca;
		ca.open(path, ios_base::app);
		string categ;
		int h = 0;
		while (!ca.eof())	{
			ca >> categ;
			if (categ == Category) {
				h = h + 1;
			}
		}
		ca.close();
		if (h != 1) {
			string path = "Categorys.txt";
			ofstream ca;
			ca.open("Categorys.txt", ios_base::app);
			ca << this->Category << endl;
			ca.close();
		}
	}

	void createTest()	{
		ofstream data;
		SetCategoryName();
		SetTestName();
		bool continue_ = false;
		do		{
			questions.push_back(addQuestion());
			cout << "Продолжить создавать вопросы ?";
			cout << "1-Да , 0-Нет :";
			cin >> continue_;
			cin.ignore();
		} 
		while (continue_);
		ofstream out("testName.txt", ios::app);
		out << this->name << endl;
		out.close();
		string cat = "categorys\\" + this->name + ".txt";
		data.open(cat);
		data << this->name << endl;
		data << this->questions.size() << endl;
		for (size_t i = 0; i < questions.size(); i++)		{
			questions[i].Save(data);
		}
		data.close();
	}

	void print()	{
		cout << "Тесты: " << this->name << endl;
		for (size_t i = 0; i < questions.size(); i++){
			cout << endl << i + 1 << " Вопрос : ";
			questions[i].print();
			cout << endl;
		}
	}
};

