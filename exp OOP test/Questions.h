#pragma once
#include<iostream>
//#include<list>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Question{
public:
	string question;
	vector<string> answers;
	int numTrueAnswer;
	friend class Test;

	void print()	{
		cout << this->question << endl << endl;
		for (size_t i = 0; i < answers.size(); i++)		{
			cout << i + 1 << ". " << answers[i] << endl;
		}
	}

	void setQuestion()	{
		cout << "Новый вопрос: ";
		getline(cin, this->question);
	}

	void addAnswer()	{
		cout << "Новый ответ : ";
		string answ;
		getline(cin, answ);
		answers.push_back(answ);
	}

	void Save(ofstream& data) {
		data << question << endl;
		data << answers.size() << endl;
		for (size_t i = 0; i < answers.size(); i++)		{
			data << answers[i] << endl;
		}
		data << numTrueAnswer << endl;
	}

	void setNumTrueAnswer()	{
		cout << "Номер правильного ответа: ";
		cin >> numTrueAnswer;
		cin.ignore();
	}

	void editAnswer()	{
		for (size_t i = 0; i < answers.size(); i++)		{
			cout << i + 1 << ". " << answers[i] << endl;
		}
		int n;
		cin >> n;
		cin.ignore();
		cout << "Новый вопрос:";
		string answ;
		getline(cin, answ);
		answers[n - 1] = answ;
	}
};