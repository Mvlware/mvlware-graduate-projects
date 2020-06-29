#include <iostream>
#include <math.h>
#include <clocale>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

//������ � �������
ofstream out;
ifstream in;

// ����������
int M, F, T, i, sum, action;
int * A;
int * B;
double C, S, D, Y;
const double PI = 3.14159265;
const string filename = "znach.txt";

// ��������� �������
int math();
void space(int n);
bool checkIsDigit(char *str);
int math1();
void clearFile();
void reference();

int main() {
	system("color F1");
	setlocale(LC_ALL, "Russian");

	do
	{
		space(10);
		cout << setw(72) << "������������� ������ \n\n\n";
		cout << setw(76) << "��� ��������� ������� ������� a \n";
		cout << setw(75) << "��� ������ ������� ������� b \n";
		cout << setw(80) << "��� ���������� ������ �� ����� ������� c \n";
		cout << setw(74) << "��� ������� ����� ������� d \n";
		cout << setw(71) << "��� ������ ������� e \n";
		action = _getch();
		switch (action)
		{
			case 97: {
				reference();
				break;
			}
			case 98: {
				math();
				break;
			}
			case 99:
			{
				math1();
				break;
			}
			case 100: {
				clearFile();
				break;
			}
			case 101:
			{
				space(10);
				cout << setw(72) << "��������� ���������";
				Sleep(2000);
				return 0;
			}
			default:
			{
				space(10);
				cout << setw(67) << "������";
				Sleep(1500);
				space(10);
			}
		}
	} while (1);
}

int math()
{
	space(10);
	do {
		cout << setw(70) << "������� ����� �������� M = ";
		char num_ch[100];
		cin >> num_ch;
		if (checkIsDigit(num_ch))
			M = atoi(num_ch);
		else M = -1;
	} while (M < 0);
	A = new int[M];
	B = new int[M];
	for (i = 0; i < M; i++) {
		space(10);
		do {
			cout << setw(62) << "������� � [" << i << "] = ";
			char num_ch[100];
			cin >> num_ch;
			if (checkIsDigit(num_ch))
				A[i] = atoi(num_ch);
			else A[i] = -1;
		} while (A[i] < 0);
	}
	for (int i = 0; i < M; i++) {
		space(10);
		do {
			cout << setw(62) << "������� B [" << i << "] = ";
			char num_ch[100];
			cin >> num_ch;
			if (checkIsDigit(num_ch))
				B[i] = atoi(num_ch);
			else B[i] = -1;
		} while (B[i] < 0);
	}
	space(10);
	do {
		cout << setw(68) << "������� ������� F = ";
		char num_ch[100];
		cin >> num_ch;
		if (checkIsDigit(num_ch))
			F = atoi(num_ch);
		else F = -1;
	} while (F < 0);
	space(10);
	do {
		cout << setw(67) << "������� ����� T = ";
		char num_ch[100];
		cin >> num_ch;
		if (checkIsDigit(num_ch))
			T = atoi(num_ch);
		else T = -1;
	} while (T < 0);
	C = 2 * PI*F*T;
	S = 0;
	for (i = 0; i < M; i++) {
		D = C*i;
		S = S + (A[i] * cos(D) + B[i] * sin(D));
		sum = sum + A[i];
	}
	out.open(filename);
	out << M << "\n";
	for (i = 0; i < M; i++) {
		out << A[i] << "\n";
	}
	for (i = 0; i < M; i++) {
		out << B[i] << "\n";
	}
	out << F << "\n" << T << "\n";
	out.close();
	Y = sum / 2 + S;
	space(10);
	cout << setw(63) << "Y(T) = " << Y << "\n\n";
	
	do {
		cout << setw(77) << "��� ������ � ���� ������� e \n";
		action = _getch();
	} while (action != 101);
	return 0;
}
int math1()
{
	space(10);
	in.open(filename);
	in >> M;
	if (M == NULL) {
		cout << setw(67)<< "�������� ���";
		Sleep(2000);
	}
	else {
		for (i = 0; i < M; i++)
		{
			in >> A[i];
		}
		for (i = 0; i < M; i++)
		{
			in >> B[i];
		}
		in >> F;
		in >> T;
		in.close();
		space(10);
		cout << setw(71) << "����� �������� = " << M << endl;
		for (i = 0; i < M; i++) {
			cout << setw(65) << "������� A[" << i << "] = " << A[i] << endl;
		}
		for (i = 0; i < M; i++) {
			cout << setw(65) << "������� B[" << i << "] = " << B[i]<< endl;
		}
		cout << setw(68) << "������� = " << F << endl;
		cout << setw(67) << "����� = " << T << endl;
		do {
			cout << "\n" << setw(82) << "���������� ������ �� ���������? (y/n)";
			action = _getch();
		} while (action != 121 && action!= 110);
		if (action == 121)
		{
		C = 2 * PI*F*T;
		S = 0;
		for (i = 0; i < M; i++) {
			D = C*i;
			S = S + (A[i] * cos(D) + B[i] * sin(D));
			sum = sum + A[i];
		}
		Y = sum / 2 + S;
		space(10);
		cout << setw(63) << "Y(T) = " << Y << "\n\n";
		}
		else
		{
			space(10);
			return 0;
		}
		do {
			cout << setw(77) << "��� ������ � ���� ������� e \n";
			action = _getch();
		} while (action != 101);
	}
	return 0;
}

void space(int n) {
	system("cls");
	for (int i = 0; i < n; i++)
		cout << endl;
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

void clearFile()
{
	in.open(filename);
	in >> M;
	in.close();
	for (i = 0; i < M; i++) {
		A[i] = NULL;
		B[i] = NULL;
	}
	M = NULL;
	F = NULL;
	T = NULL;
	out.open(filename);
	out << M << "\n";
	for (i = 0; i < M; i++) {
		out <<A[i] << "\n";
	}
	for (i = 0; i < M; i++) {
		out << B[i] << "\n";
	}
	out <<  F << "\n"<< T << "\n";
	out.close();
}

void reference()
{
	space(10);
	cout << setw(120) << "������������� ������ - ��������� ��������� ������� ����� ����� ������������ �� ������������� ������������ (��������). \n" << setw(119) <<"������������� ������ ����� ������ ��� ��������������� ��������, ��� � �������������� ��� �������� ������������������ \n"<< setw(75) << "������������� �������. \n\n";
	do {
		cout << setw(77) << "��� ������ � ���� ������� e \n";
		action = _getch();
	} while (action != 101);
}