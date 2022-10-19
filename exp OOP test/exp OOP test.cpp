#pragma once
#include <Windows.h>
#include "Prog.h"

int main()	{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Prog go;
	go.menu();
}
