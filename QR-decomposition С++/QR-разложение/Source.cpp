#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <clocale>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define _N 20
#define _M 20
int back = 0;
int high;
int low;
char ui;
int number1;
int number2;
const string filename = "����.txt";

//������ � �������
ofstream fout;
ifstream fin;

//��������� ������� �����
void printSpace(int n);
void instructions();
int askNumber(int low, int high);
int askNumber1(int low, int high);
int math(int low, int high);
int math1();
void clearFile();

class matrix {
public:
	matrix(int n, int m);
	~matrix();
	void print_slau();
	void print_x();
	void qr();
	void seta(int i, int j, float value);
	void setb(int i, float value);
private:
	float **a;
	float *b;
	float *x;
	int n, m;
};
// ------------------------------------------------------
// �����������
// ------------------------------------------------------
matrix::matrix(int N, int M) {
	int i;
	n = N; m = M;
	a = new float*[n];
	for (i = 0; i<n; i++) {
		a[i] = new float[m];
		for (int j = 0; j<m; j++) a[i][j] = 0;
	}
	b = new float[n];
	x = new float[n];
	for (i = 0; i<n; i++) { b[i] = 0; x[i] = 0; }
}
// ------------------------------------------------------
// ����������
// ------------------------------------------------------
matrix::~matrix() {
	for (int i = 0; i<n; i++) delete a[i];
	delete[] a;
	delete b; delete x;
}
// ------------------------------------------------------
// ����� ���� �� �����
// ------------------------------------------------------
void matrix::print_slau() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) printf("%.2f  ", a[i][j]);
		printf("| %.3f  ", b[i]);
		printf("\n");
	}
}
// ------------------------------------------------------
// ������ ������� � ������� �������
// ------------------------------------------------------
void matrix::print_x() {
	float max = 0, h;
	for (int i = 0; i<n; i++) {
		h = 0;
		for (int j = 0; j<n; j++) h = h + x[j] * a[i][j];
		if (max<fabs(b[i] - h)) max = fabs(b[i] - h);
		printf("x[%i]=%.3f  ", i, x[i]);
		if (i == 5) printf("\n");
	}
	printf("\n����. �������: %f\n", max);
}
// ------------------------------------------------------
// ���������� �������� ������� a[][]
// ------------------------------------------------------
void matrix::seta(int i, int j, float value) {
	a[i][j] = value;
}
// ------------------------------------------------------
// ���������� �������� ������� b[]
// ------------------------------------------------------
void matrix::setb(int i, float value) {
	b[i] = value;
}
// ------------------------------------------------------
// QR-��������
// ------------------------------------------------------
void matrix::qr() {
	int l, k;

	float c[_N][_M];
	float s[_N][_M];
	float akk, akl, alk, all, bk, bl;
	// ������ ���
	for (k = 0; k<n - 1; k++) {   // "�������" ��� (���������� ����������)
		for (l = k + 1; l<n; l++) {     // "�����" ���
			c[k][l] = a[k][k] / (sqrt(a[k][k] * a[k][k] + a[l][k] * a[l][k]));
			s[k][l] = a[l][k] / (sqrt(a[k][k] * a[k][k] + a[l][k] * a[l][k]));

			// ��������� ������� a[][] �� T[k][l]
			akk = a[k][k];  alk = a[l][k];  akl = a[k][l];  all = a[l][l];
			a[k][k] = akk*c[k][l] + alk*s[k][l];
			a[k][l] = akl*c[k][l] + all*s[k][l];
			a[l][k] = -akk*s[k][l] + alk*c[k][l];
			a[l][l] = -akl*s[k][l] + all*c[k][l];

			// ������ ��������� ������ ���������� �� T[k][l]
			bk = b[k]; bl = b[l];
			b[k] = bk*c[k][l] + bl*s[k][l];
			b[l] = -bk*s[k][l] + bl*c[k][l];
		}
	}
	// ������ ������� a[][] -- ������� ������������.

	// �������� ���
	float h;
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (l = (n - 1); l >= 1; l--) {
		h = b[l - 1];
		for (k = (l + 1); k <= n; k++) h = h - x[k - 1] * a[l - 1][k - 1];
		x[l - 1] = h / a[l - 1][l - 1];
	}
}

void printSpace(int n) {
	system("cls");
	for (int i = 0; i < n; i++)
		cout << endl;
}

void instructions()
{
	printSpace(10);
	cout << setw(114) << "QR-���������� ������� � ������������� ������� � ���� ������������ ��������� (��� ������������� �������) � \n" << setw(114) << "����������������� �������. QR-���������� �������� ������� ������ �� ������� ������ ����������� �������� � \n" << setw(80) << "����� ������� � QR-���������.\n\n";
	do {
		cout << setw(79) << "����� ��������� ����� � ���� - 0";
		back = _getch();
		printSpace(10);
	} while (back != 48);
}

int math(int low, int high)
{
	int n, m;
	int i;
	printSpace(10);
	int choose = askNumber(1, 20);
	n = choose;
	number1 = n;
	printSpace(10);
	int choose1 = askNumber1(1, 20);
	m = choose1;
	number2 = m;
	fout.open(filename);
	fout << number1 << " " << number2;
	fout.close();
	printSpace(10);
	matrix A(n, m);
	for (i = 0; i<n; i++) for (int j = 0; j<m; j++) A.seta(i, j, i + j);
	for (i = 0; i<n; i++) A.setb(i, 1);
	cout << setw(90) << "������� ���� ������� �������� (QR-����������)\n\n";
	cout << setw(90) << "===============�������� �������==============\n";
	A.print_slau();
	cout << setw(90) << "================������� �������===============\n";
	A.qr();
	A.print_x();
	cout << setw(90) << "\n\n";
	do {
		cout << setw(80) << "����� ��������� ����� � ���� - 0";
		back = _getch();
		printSpace(10);
	} while (back != 48);
	return 0;
}
int math1()
{
	fin.open(filename);
	fin >> number1;
	fin >> number2;
	int n = number1;
	int m = number2;
	fin.close();
	if (n == 0)
	{
		printSpace(10);
		cout << setw(81) << "�������� ��� n � m ����������� \n";
	}
	else
	{
		printSpace(10);
		cout << setw(75) << "���������� ��������� = " << n;
		cout << "\n" << setw(76) <<"���������� ����������� = " << m;
		do {
			cout << "\n" << setw(82) << "���������� ������ �� ���������? (y/n)";
			ui = _getch();
		} while (ui != 121 && ui != 110);
		if (ui == 121)
		{
			int i;
			matrix A(n, m);
			for (i = 0; i < n; i++) for (int j = 0; j < m; j++) A.seta(i, j, i + j);
			for (i = 0; i < n; i++) A.setb(i, 1);
			cout << "\n" << setw(90) << "������� ���� ������� �������� (QR-����������)\n\n";
			cout << setw(90) << "===============�������� �������==============\n";
			A.print_slau();
			cout << setw(90) << "================������� �������===============\n";
			A.qr();
			A.print_x();
			cout << setw(90) << "\n\n";
		}
		else 
		{
			printSpace(10);
			return 0;
		}
		
	}
	do {
		cout << setw(80) << "����� ��������� ����� � ���� - 0";
		back = _getch();
		printSpace(10);
	} while (back != 48);
	return 0;
}
// ------------------------------------------------------
// Main
// ------------------------------------------------------
int main() {
	system("color F0");
	setlocale(LC_ALL, "Russian");
	printSpace(10);
	do
	{
	stop:
		cout << setw(95) << "!!!�������������� �������� ��������. ����� ����������!!!\n\n";
		cout << setw(82) << "����� ���������� - ������� enter\n";
		cout << setw(78) << "����� ����� - ������� esq";
		int action = _getch();
		printSpace(10);
		if (action == 13)
		{
			do
			{
				cout << setw(81) << "����� �������� ������� - ������� i \n";
				cout << setw(80) << "����� ������ ������� - ������� r \n";
				cout << setw(81) << "����� ������� �� ����� - ������� f \n";
				cout << setw(81) << "����� �������� ���� - ������� b \n\n";
				cout << setw(86) << "����� ��������� ����� � ������� ���� - ������� 0";

				int choose = _getch();

				switch (choose)
				{
				case 98: {
					clearFile();
					break;
				}
				case 105: {
					instructions();
					break;
				}
				case 114: {
					math(1, 20);
					break;
				}
				case 48:
				{
					printSpace(10);
					goto stop;
				}
				case 102:
				{
					math1();
					break;
				}
				default: {
					printSpace(10);
					cout << setw(67) << "�� ��������!";
					Sleep(2000);
					printSpace(10);
				}
				}
			} while (1);
		}
		else if (action == 27)
		{
			printSpace(10);
			cout << setw(72) << "�� ����� ������!!!";
			Sleep(2000);
			return 0;
		}
		else {
			printSpace(10);
			cout << setw(67) << "�� ��������!";
			Sleep(2000);
			printSpace(10);
		}
	} while (1);
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

int askNumber(int low, int high)
{
	int number;
	do {
		cout << setw(86) << "����������, ������� ���������� �������� ��� n (����� ���������)" << " (" << low << " - " << high << "): ";
		char num_ch[100];
		cin >> num_ch;
		if (checkIsDigit(num_ch))
			number = atoi(num_ch);
		else number = -1;
	} while (number > high || number < low);
	return number;
}

int askNumber1(int low, int high)
{
	int number;
	do {
		cout << setw(86) << "����������, ������� ���������� �������� ��� m (����� �����������)" << " (" << low << " - " << high << "): ";
		char num_ch[100];
		cin >> num_ch;
		if (checkIsDigit(num_ch))
			number = atoi(num_ch);
		else number = -1;
	} while (number > high || number < low);
	return number;
}

// ������� �����
void clearFile()
{
	system("cls");
	for (int i = 0; i < 10; i++)
		cout << endl;
	number1 = 0;
	number2 = 0;
	fout.open(filename);
	fout << number1;
	fout << number2;
	fout.close();
}