#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <clocale>
#include <cmath>
#include <fstream>
#include <string>

#define epsilon 0.0001;

using namespace std;

int decision;

const string filename = "forNum.txt";

double function1(double x, double y);
double function2(double x, double y);
double func11(double x, double y);
double func12(double x, double y);
double func21(double x, double y);
double func22(double x, double y);
void ober_matr(double a[2][2]);
void nuton(double x, double y);

void information();
void clearFile();
int prog(); 
int progg();
bool checkIsDigit(char *str);

ofstream write;
ifstream read;

int main() {
	setlocale(LC_ALL, "Russian");
	do
	{
		main:
		system("cls");
		cout << "Решение сиситемы нелинейных уравнений модифицированным методом Ньютона \n";
		cout << "Если вы хотите начать расчет - нажмите s \n";
		cout << "Если вы хотите считать данные из файла нажмите r \n";
		cout << "Если вы хотите очистить файл нажмите с \n";
		cout << "Если вы хотите получить справку нажмите i \n";
		cout << "Если вы хотите выйти нажмите e \n";
		decision = _getch();
		switch (decision)
		{
		case 105: {
			information();
			break;
		}
		case 115: {
			prog();
			break;
		}
		case 114:
		{
			progg();
			break;
		}
		case 99: {
			clearFile();
			break;
		}
		case 101:
		{
			system("cls");
			cout << "Программа завершена";
			Sleep(3000);
			return 0;
		}
		default:
		{
			system("cls");
			cout << "Ошибка";
			Sleep(1500);
			system("cls");
		}
		}
	} while (1);
}
int prog()
{
	double x, y;
	system("cls");
	bool isBreak = false;
	do {
		cout << "x = ";
		char num_ch[100];
		cin >> num_ch;
		for (int i = 0; num_ch[i] != '\0'; i++)
		{
			if (num_ch[i] < 48 || num_ch[i]>57)
				isBreak = true;
			else {
				isBreak = false;
				x = atoi(num_ch);
			}
		}
	} while (isBreak == true);
	do {
		cout << "y = ";
		char num_ch[100];
		cin >> num_ch;
		for (int i = 0; num_ch[i] != '\0'; i++)
		{
			if (num_ch[i] < 48 || num_ch[i]>57)
				isBreak = true;
			else {
				isBreak = false;
				y = atoi(num_ch);
			}
		}
	} while (isBreak == true);
	write.open(filename);
	write << x << endl << y;
	write.close();
	nuton(x, y);
	cout << endl;
	do {
		cout << "Для выхода в меню нажмите е";
		decision = _getch();
		system("cls");
	} while (decision != 101);
	return 0;
}
int progg()
{
	double x, y;
	read.open(filename);
	read >> x;
	read >> y;
	read.close();
	if (x == NULL)
	{
		system("cls");
		cout <<  "Значения отсутствуют \n";
		Sleep(2000);
	}
	else {
		system("cls");
		cout <<"x = " << x << endl << "y = " << y;
		do {
			cout << "\n"  << "Произвести расчет по значениям? (y/n)";
			decision = _getch();
		} while (decision != 121 && decision != 110);
		if (decision == 121)
		{
		nuton(x, y);
		cout << endl;
		do {
			cout << "Для выхода в меню нажмите е";
			decision = _getch();
			system("cls");
		} while (decision != 101);
		}
		else
		{
			system("cls");
			return 0;
		}
	}
}

	double function1(double x, double y)
	{
		return sin(x + y) - 1.2*x;
	}

	double function2(double x, double y)
	{
		return x*x + y*y - 1;
	}

	double func11(double x, double y)
	{
		return cos(x + y) - 1.2;
	}

	double func12(double x, double y)
	{
		return cos(x + y);
	}

	double func21(double x, double y)
	{
		return 2 * x;
	}

	double func22(double x, double y)
	{
		return 2 * y;
	}

	void ober_matr(double a[2][2])
	{
		double det, aa;
		det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		aa = a[0][0];
		a[0][0] = a[1][1] / det;
		a[1][1] = aa / det;
		aa = a[0][1];
		a[0][1] = -a[0][1] / det;
		a[1][0] = -a[1][0] / det;
	}

	void nuton(double x, double y)
	{
		int i = 1;
		double a[2][2], dx, dy, b[2], norm;
		do
		{
			a[0][0] = func11(x, y);
			a[0][1] = func12(x, y);
			a[1][0] = func21(x, y);
			a[1][1] = func22(x, y);
			ober_matr(a);
			dx = -a[0][0] * function1(x, y) + -a[0][1] * function2(x, y);
			dy = -a[1][0] * function1(x, y) + -a[1][1] * function2(x, y);
			x = x + dx;
			y = y + dy;
			b[0] = function1(x, y);
			b[1] = function2(x, y);
			norm = sqrt(b[0] * b[0] + b[1] * b[1]);
			i++;
		} while (norm >= 0.0001);
		system("cls");
		cout << "Корни уравнения системы:" << endl<< x << endl << y << endl;
	}
	

void information()
{
	system("cls");
	cout << "Метод Ньютона яаляется наиболе распространенным методом решения сиситем уравнений. Он задается следующим алгоритмом: \n" << "1. Задаем относительную погрешность е, число уравнений n, максимальное число итераций m и вектор начальных приближений xi. \n" << "2. Используя разложение в ряд Тэйлора формируется матрица Якоби, необходимая для рачета приращений при малом изменений переменных. \n" << "Поскольку аналитическое дифференцирование в общем случае нежелательно, в матрице Якоби частные производные заменяются приближенными кончено - разностными значениями. \n";
	do {
		cout << "Для выхода в меню нажмите e \n";
		decision = _getch();
	} while (decision != 101);
}

void clearFile()
{
	double x, y;
	x = NULL;
	y = NULL;
	write.open(filename);
	write << x << endl << y;
	write.close();
	system("cls");
	cout << "Файл очищен";
	Sleep(1500);
	system("cls");
}

bool checkIsDigit(char *str)
{
	while (*str != 0)
	{
		if (!isdigit(*str++))
		return false;
	}
	return true;
}