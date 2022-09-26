// Staples1_for_cable_journal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// 22-07-2022_DZ_char_mass.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//3. Поиск и выделение
// Написать функцию, принимающую в качестве параметров две строки
// и возвращающую копию первого параметра, все вхождения второго параметра
// в которой взяты в ( ) - скобки.
// например, если параметрами были строки  "abracadabra" и "ab"
// то вернуть надо "(ab)racad(ab)ra"
//https://www.stackfinder.ru/questions/34387181/find-char-element-in-array-of-char-in-c
// https://ru.stackoverflow.com/questions/717340/%D0%9A%D0%B0%D0%BA-%D0%B8%D0%BD%D0%B8%D1%86%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D1%82%D1%8C-vectorchar-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%BE%D0%B9
// Код взят отсюда
// нихрена не доделал с итераторами надо как то по другому


#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include<Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()

{
	setlocale(LC_ALL, "Russian");
	//логика удаление скобок
	string str1;
	string lisp_1; // начало строки лиспа
	string lisp_2; // середина строки лиспа
	string lisp_3; // конец строки лиспа
	int count_1{ 0 };
	int count_2{ 0 };
	ifstream file;            // создать поточный объект file
	file.open("test_journal.txt");    // открыть файл на чтение
	if (!file) return 1;      // возврат по ошибке отрытия
	char str[40];             // статический буфер строки
	// Считывать и отображать строки в цикле, пока не eof

	while (!file.getline(str, sizeof(str)).eof())
	{
		cout << str << endl;     // вывод прочитанной строки на экран
		count_1++;					// кол-во элементов в файле + одна строка сверху пустая
	}
	cout << "count_1 = " << count_1 << endl; // счетчик для вывода на консоль
	//cout << "Откройте файл output.txt пересохраните его в *.lsp" << endl;
	//cin.sync();
//cin.get();
	ifstream input("test_journal.txt"); //Открываешь первый файл для чтения
	string string_buf; //Строка-буфер
	ofstream output("output.lsp"); //Открываешь второй файл для записи

	while (getline(input, string_buf))  //Считываешь из файла строку (пока не EOF)End Of File
	{
		//пока до скобочки берёт
		if ((getline(input, string_buf, '(')) && !string_buf.empty()) // пока буфер не пустой
		{
			str1=string_buf; 
			//int pos = str1.find(")");  //Ищем "friend" в str
			//str1.erase(pos, 1);
		}
		cout << str1 << endl;
		output << str1 << endl;  //И записываешь эту строку в выходной файл	
		count_2++;
	}
	//cout << "count_2 = " << count_2 << endl;
	

	//) << endl;  //записываем заключительную строку в выходной файл	
	// ОБЯЗАТЕЛЬНО ОСТАВЛЯТЬ ПУСТУЮ СТРОКУ В ТЕКСТОВОМ ФАЙЛЕ В НАЧАЛЕ
	// ЗАПРЕЩЕНО ОСТАВЛЯТЬ ПУСТЫЕ СТРОКИ В ТЕКСТОВОМ ФАЙЛЕ В КОНЦЕ
	input.close();
	output.close();
	system("pause");
	return 0;
	return 0;
	// решение работает с одним символом
	/*int index = 0;
	while ((index = s.find(substr1, index)) != string::npos) {
		cout << index << endl;
		index += substr1.length();
	}*/
}