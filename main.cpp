#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include "ansiout.h"
#include <ctime> 

#ifdef _WIN32
#include <Windows.h>
#define msleep(x) Sleep(x)
#else
#include <unistd.h>
#define msleep(x) usleep(x * 1000)
#endif


using namespace std;

int Xbot, Ybot;

/* ������ �������� ���� */
#define __WORLD_HEIGHT__ 5

/* ������ �������� ���� */
#define __WORLD_WIDTH__ 5

// C�������� ��� �������� ��������� ������
struct point {
	unsigned int is_live;
};

/*
 * ������������� ������� ��������� ���� ���������������� ����������
 */
int init_world(point world[][__WORLD_HEIGHT__], int user, int Xcapital, int Ycapital, int bots) //TODO: ���������� ��������� ���� ���� ����
{
	if (user == 1 && bots == 1) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 10000);

		unsigned int i, j;
		unsigned int a = 0;
		
		for (i = 0; i < __WORLD_WIDTH__; i++) {
			for (j = 0; j < __WORLD_HEIGHT__; j++) {
				unsigned int num = dis(gen);
				if (num % 2 == 0) {
					if (a == 0 && i != Ycapital && j != Xcapital) {
						Xbot = j;
						Ybot = i;
						world[i][j].is_live = 2;
						a = 1;
					}
					else {
						world[i][j].is_live = 0;
					}
				}
				else {
					world[i][j].is_live = 0;
				}
			}
		}
		world[Ycapital][Xcapital].is_live = 1;
	}
	return Xbot, Ybot;
}

/*
 * ������� �� ����� ������� ����
*/
void print_world(point world[][__WORLD_HEIGHT__])
{
	AnsiOut ao;
	unsigned int i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			if (world[i][j].is_live == 1) {
				ao.textAttr(ANSI_LRED);
				cout << 'A';
				ao.textAttrDefault();
			}
			else if (world[i][j].is_live == 2) {
				ao.textAttr(ANSI_LBLUE);
				cout << 'B';
				ao.textAttrDefault();
			}
			else {
				cout << '~';
			}
			cout << ' ';
		}
		cout << endl;
	}
}

/*
 * ��������� ��������� ������� ����� (����������� ���� 1 �������)
*/
void read_point_neighbors(signed int nb[][2], int Xcapital, int Ycapital)
{
	unsigned int i, j;
	unsigned int k = 0;

	for (i = Xcapital - 1; i <= Xcapital + 1; i++) {
		for (j = Ycapital - 1; j <= Ycapital + 1; j++) {
			if (i == Xcapital && j == Ycapital) {
				continue;
			}
			nb[k][0] = i;
			nb[k][1] = j;
			k++;
		}
	}
}

/*
 * ���������� ����� ������� � ������ � ������������ x, y
 */
unsigned int count_live_neighbors(point world[][__WORLD_HEIGHT__], int Xcapital, int Ycapital)
{
	unsigned int count = 0;
	unsigned int i;
	signed int nb[8][2];
	signed int _x, _y;

	read_point_neighbors(nb, Xcapital, Ycapital);

	for (i = 0; i < 8; i++) {
		_x = nb[i][0];
		_y = nb[i][1];

		if (_x < 0 || _y < 0) {
			continue;
		}
		if (_x >= __WORLD_WIDTH__ || _y >= __WORLD_HEIGHT__) {
			continue;
		}

		if (world[_x][_y].is_live != 0) {
			count++;
		}
	}

	return count;
}

/*
 * ����������� �������� ����. ������������ ��� ���������� ����������� ���������
*/
void copy_world(point src[][__WORLD_HEIGHT__], point dest[][__WORLD_HEIGHT__])
{
	unsigned int i, j;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

/*
 * ������������� ��������� ��������� �������� ����
 */
void next_generation(point world[][__WORLD_HEIGHT__], point prev_world[][__WORLD_HEIGHT__], string answer, int Xcapital, int Ycapital, int mode, int Xbot, int Ybot, int DirectBot, int whileStop) //TODO: �� ���� ������� ������ ��� ��� ����� �����
{
	unsigned int i, j;
	unsigned int live_nb;
	point p;
	string k;

	if (mode == 1) {
		if (answer == "�") {
			p = prev_world[Ycapital-1][Xcapital];
			if(p.is_live == 0) {
				world[Ycapital - 1][Xcapital].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "������ �����?"; //TODO: ������ ����� CHAR? ����� ������� ������� ������!
				cin >> k;
				if (k == "��") {
					world[Ycapital - 1][Xcapital].is_live = 1;
				}
				else {
					world[Ycapital - 1][Xcapital].is_live = 0;
				}
			}
			else {
				cout << "��� ��������" << endl;
				system("pause");
			}
		}
		else if (answer == "�") {
			p = prev_world[Ycapital][Xcapital - 1];
			if (p.is_live == 0) {
				world[Ycapital][Xcapital - 1].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "������ �����?"; //TODO: ������ ����� CHAR? ����� ������� ������� ������!
				cin >> k;
				if (k == "��") {
					world[Ycapital][Xcapital - 1].is_live = 1;
				}
				else {
					world[Ycapital][Xcapital - 1].is_live = 0;
				}
			}
			else {
				cout << "��� ��������" << endl;
				system("pause");
			}
		}
		else if (answer == "�") {
			p = prev_world[Ycapital][Xcapital + 1];
			if (p.is_live == 0) {
				world[Ycapital][Xcapital + 1].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "������ �����?"; //TODO: ������ ����� CHAR? ����� ������� ������� ������!
				cin >> k;
				if (k == "��") {
					world[Ycapital][Xcapital + 1].is_live = 1;
				}
				else {
					world[Ycapital][Xcapital + 1].is_live = 0;
				}
			}
			else {
				cout << "��� ��������" << endl;
				system("pause");
			}
		}
		else if (answer == "�") {
			p = prev_world[Ycapital + 1][Xcapital];
			if (p.is_live == 0) {
				world[Ycapital + 1][Xcapital].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "������ �����?"; //TODO: ������ ����� CHAR? ����� ������� ������� ������!
				cin >> k;
				if (k == "��") {
					world[Ycapital + 1][Xcapital].is_live = 1;
				}
				else {
					world[Ycapital + 1][Xcapital].is_live = 0;
				}
			}
			else {
				cout << "��� ��������" << endl;
				system("pause");
			}
		}
	}
	else if (mode == 2) {
		if (DirectBot == 2) {
			p = prev_world[Ybot - 1][Xbot];
			if (p.is_live == 0) {
				world[Ybot - 1][Xbot].is_live = 2;
			}
			else if (p.is_live == 1) {
				int war = rand() % 3;
				if (war == 1) {
					k = "��";
				}
				else {
					k = "���";
				}
				if (k == "��") {
					world[Ybot - 1][Xbot].is_live = 2;
				}
				else {
					world[Ybot - 1][Xbot].is_live = 0;
				}
			}
		}
		else if (DirectBot == 1) {
			p = prev_world[Ybot][Xbot - 1];
			if (p.is_live == 0) {
				world[Ybot][Xbot - 1].is_live = 2;
			}
			else if (p.is_live == 1) {
				int war = rand() % 3;
				if (war == 1) {
					k = "��";
				}
				else {
					k = "���";
				}
				if (k == "��") {
					world[Ybot][Xbot - 1].is_live = 2;
				}
				else {
					world[Ybot][Xbot - 1].is_live = 0;
				}
			}
		}
		else if (DirectBot == 3) {
			p = prev_world[Ybot][Xbot + 1];
			if (p.is_live == 0) {
				world[Ybot][Xbot + 1].is_live = 2;
			}
			else if (p.is_live == 1) {
				int war = rand() % 3;
				if (war == 1) {
					k = "��";
				}
				else {
					k = "���";
				}
				if (k == "��") {
					world[Ybot][Xbot + 1].is_live = 2;
				}
				else {
					world[Ybot][Xbot + 1].is_live = 0;
				}
			}
		}
		else if (DirectBot == 4) {
			p = prev_world[Ybot + 1][Xbot];
			if (p.is_live == 0) {
				world[Ybot + 1][Xbot].is_live = 2;
			}
			else if (p.is_live == 1) {
				int war = rand() % 3;
				if (war == 1) {
					k = "��";
				}
				else {
					k = "���";
				}
				if (k == "��") {
					world[Ybot + 1][Xbot].is_live = 2;
				}
				else {
					world[Ybot + 1][Xbot].is_live = 0;
				}
			}
		}
	}

	for (i = 0; i < __WORLD_WIDTH__; i++) {
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			
			/*
			p = prev_world[i][j];
			live_nb = count_live_neighbors(prev_world, i, j);

			if (p.is_live == 0) {
				if (live_nb == 3) {
					world[i][j].is_live = 1;
				}
			}
			else {
				if (live_nb < 2 || live_nb > 3) {
					world[i][j].is_live = 0;
				}
			}
			*/
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int Xcapital, Ycapital;
	int user, users, bots;

	srand(time(NULL));

	cout << "������� ���������� ������� (�������� - 1): ";
	cin >> users;
	cout << "������� ���������� ����� (�������� - 1): ";
	cin >> bots;

	system("cls");
	user = 1;
	cout << " --------------" << endl;
	cout << "| #  1 2 3 4 5 | <-- X" << endl;
	cout << "|              |" << endl;
	cout << "| 1  ~ ~ ~ ~ ~ |" << endl;
	cout << "| 2  ~ ~ ~ ~ ~ |" << endl;
	cout << "| 3  ~ ~ ~ ~ ~ |" << endl;
	cout << "| 4  ~ ~ ~ ~ ~ |" << endl;
	cout << "| 5  ~ ~ ~ ~ ~ |" << endl;
	cout << " --------------" << endl;
	cout << "  ^" << endl;
	cout << "  |" << endl;
	cout << "  Y\n\n" << endl;
	cout << "�������� ������-�������" << endl;
	cout << "���������� �: ";
	cin >> Xcapital;
	Xcapital -= 1;
	cout << "���������� Y: ";
	cin >> Ycapital;
	Ycapital -= 1;

	system("cls");
	point world[__WORLD_WIDTH__][__WORLD_HEIGHT__];
	point prev_world[__WORLD_WIDTH__][__WORLD_HEIGHT__];

	init_world(world, user, Xcapital, Ycapital, bots);
	while (true) {
		int whileStop = 0;
		int DirectBot = 0;

		string answer = "";
		int mode = 1;
		system("cls");
		print_world(world);
		cout << "\n-----------------------------------------------------------------------" << endl;
		cout << "� - ������ ������� �����     �� - ��������� ������ ����\n� - ������ ������ �����     �� - ��������� ������ ����\n� - ������ ����� �����     �� - ��������� ������ �����\n� - ������ ������ �����     �� - ��������� ������ ������" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "������ ������ ��: " << endl;
		cout << "X: " << Xcapital + 1<< " | Y: " << Ycapital + 1<< endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "�����: ";
		cin >> answer;
		if (answer == "�" || answer == "�" || answer == "�" || answer == "�") {
			copy_world(world, prev_world);
			next_generation(world, prev_world, answer, Xcapital, Ycapital, mode, Xbot, Ybot, DirectBot, whileStop);
			//
			mode = 2;
			int Zet = Xbot;
			int Tez = Ybot;
			Xbot = Zet;
			Ybot = Tez;
			int direction = rand() % 3;
			if (direction == 1) {
				int amount = rand() % 3;
				if (amount == 1) {
					DirectBot = 1;
				}
				else {
					DirectBot = 3;
				}
			}
			else {
				int amount = rand() % 3;
				if (amount == 1) {
					DirectBot = 2;
				}
				else {
					DirectBot = 4;
				}
			}
			copy_world(world, prev_world);
			next_generation(world, prev_world, answer, Xcapital, Ycapital, mode, Xbot, Ybot, DirectBot, whileStop);
		}
		else if (answer == "��" || answer == "��" || answer == "��" || answer == "��") {
			point p;
			if (answer == "��") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital - 1][Xcapital];
				if (p.is_live == 1) {
					Ycapital = Ycapital - 1;
				} 
			}
			else if (answer == "��") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital][Xcapital - 1];
				if (p.is_live == 1) {
					Xcapital = Xcapital - 1;
				}
			}
			else if (answer == "��") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital + 1][Xcapital];
				if (p.is_live == 1) {
					Ycapital = Ycapital + 1;
				}
			}
			else if (answer == "��") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital][Xcapital];
				if (p.is_live == 1) {
					Xcapital = Xcapital + 1;
				}
			}
		}
	}
	system("pause");
}
//TODO: ������� ���� "�����" ���� � ���� �����