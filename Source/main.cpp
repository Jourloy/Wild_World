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
int playerOnMap = 0;

/* ������ �������� ���� */
#define __WORLD_HEIGHT__ 58

/* ������ �������� ���� */
#define __WORLD_WIDTH__ 50

/*
* ������ "��������" ����, � ����� ����� ���������� ����
* �������:
* 1 - ������ ���������
* 99 - ���������� ���������
*/
void startProgram() {
	system("cls");
	int timer = 0;
	Sleep(2000);
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                     00000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                 000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "             000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "      000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << " 8800000000                            2200000000  " << endl;
	cout << " 8800000088                            ::00000088  " << endl;
	cout << "   000000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "   000000      880000                    88000088  " << endl;
	cout << " 2200000022                              00000000  " << endl;
	cout << " 8800000000                            2200000000  " << endl;
	cout << " 8800000088                            ::00000088  " << endl;
	cout << "   000000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "     ''00    000000000000    88000000AA    88AA    " << endl;
	cout << "   ::0000    8800000000        558822      0000    " << endl;
	cout << "   000000      880000                    88000088  " << endl;
	cout << " 2200000022                              00000000  " << endl;
	cout << " 8800000000                            2200000000  " << endl;
	cout << " 8800000088                            ::00000088  " << endl;
	cout << "   000000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "               0000000088    0000000000            " << endl;
	cout << "             880000000088    0000000000    QQ      " << endl;
	cout << "     ''00    000000000000    88000000AA    88AA    " << endl;
	cout << "   ::0000    8800000000        558822      0000    " << endl;
	cout << "   000000      880000                    88000088  " << endl;
	cout << " 2200000022                              00000000  " << endl;
	cout << " 8800000000                            2200000000  " << endl;
	cout << " 8800000088                            ::00000088  " << endl;
	cout << "   000000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                                                   " << endl;
	cout << "                   000088    !!000000;;            " << endl;
	cout << "               !!00000088    0000000000            " << endl;
	cout << "               0000000088    0000000000            " << endl;
	cout << "             880000000088    0000000000    QQ      " << endl;
	cout << "     ''00    000000000000    88000000AA    88AA    " << endl;
	cout << "   ::0000    8800000000        558822      0000    " << endl;
	cout << "   000000      880000                    88000088  " << endl;
	cout << " 2200000022                              00000000  " << endl;
	cout << " 8800000000                            2200000000  " << endl;
	cout << " 8800000088                            ::00000088  " << endl;
	cout << "   000000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;
	Sleep(timer);
	system("cls");
	cout << "                                   AA              " << endl;
	cout << "                     88          8800              " << endl;
	cout << "                     00((      AA0000              " << endl;
	cout << "                   000088    !!000000;;            " << endl;
	cout << "               !!00000088    0000000000            " << endl;
	cout << "               0000000088    0000000000            " << endl;
	cout << "             880000000088    0000000000    QQ      " << endl;
	cout << "     ''00    000000000000    88000000AA    88AA    " << endl;
	cout << "   ::0000    8800000000        558822      0000    " << endl;
	cout << "   000000      880000                    88000088  " << endl;
	cout << " 2200000022                              00000000  " << endl;
	cout << " 8800000000                            2200000000  " << endl;
	cout << " 8800000088                            ::00000088  " << endl;
	cout << "   000000      00000000000000000088      880088    " << endl;
	cout << "             000000000000000000000000((            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           0000000000000000000000000000            " << endl;
	cout << "           88000000000000000000000000;;            " << endl;
	cout << "             0000000000000000000000AA              " << endl;
	cout << "               00000000000000000088                " << endl;
	cout << "                 00000000000000**                  " << endl;
	cout << "                   0000000088                      " << endl;
	cout << "                     0000++                        " << endl;

	cout << " --------------------------------------" << endl;
	cout << "| 1 - ������ ���� | 99 - ����� �� ���� |" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << "| �����: Jourloy (jourloy@yandex.ru)   |" << endl;
	cout << " --------------------------------------" << endl;

	int startProgramAnswer;

	do {
		cout << "\n�����: ";
		cin >> startProgramAnswer;

		if (startProgramAnswer != 1 && startProgramAnswer != 99) {
			cout << "�� ����� " << startProgramAnswer << ", �� ������ �������� ���!" << endl;
		}
	} while (startProgramAnswer != 1 && startProgramAnswer != 99);
	system("cls");

}

/*
* C�������� ��� �������� ��������� ������
*/
struct point {
	unsigned int is_live;
};

/*
 * �������� ����� ��� ������ ��������� �����
 */
void init_world(point world[][__WORLD_HEIGHT__], int user, int Xcapital, int Ycapital, int bots)
{
	int i, j;
	int Xbot;
	int Ybot;

	i = rand() % __WORLD_HEIGHT__ + 1;
	j = rand() % __WORLD_WIDTH__ + 1;

	if (i == Xcapital) {
		while (i == Xcapital) {
			i = rand() % 59;
		}
	}

	if (j == Ycapital) {
		while (j == Ycapital) {
			j = rand() % 51;
		}
	}

	if (bots) {
		Xbot = i;
		Ybot = j;

		for (i = 0; i < __WORLD_WIDTH__; i++) {
			for (j = 0; j < __WORLD_HEIGHT__; j++) {
				if (i == Xbot) {
					if (j == Ybot) {
						world[i][j].is_live = 2;
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
	}


	world[Ycapital][Xcapital].is_live = 1;
}

/*
 * ����� �� ����� �������� ����
*/
void print_world(point world[][__WORLD_HEIGHT__])
{
	AnsiOut ao;
	unsigned int i, j;
	cout << "    001|002|003|004|005|006|007|008|009|010|011|012|013|014|015|016|017|018|019|020|021|022|023|024|025|026|027|028|029|030|031|032|033|034|035|036|037|038|039|040|041|042|043|044|045|046|047|048|049|050|051|052|053|054|055|056|057|058" << endl;
	for (i = 0; i < __WORLD_WIDTH__; i++) {
		if (i + 1 < 10) {
			cout << i + 1 << "  |";
		}
		else if (i + 1 < 100) {
			cout << i + 1 << " |";
		}
		for (j = 0; j < __WORLD_HEIGHT__; j++) {
			cout << ' ';
			if (world[i][j].is_live == 1) {
				ao.textAttr(ANSI_LRED);
				cout << '1';
				ao.textAttrDefault();
			}
			else if (world[i][j].is_live == 2) {
				ao.textAttr(ANSI_LBLUE);
				cout << '2';
				ao.textAttrDefault();
			}
			else {
				cout << '_';
			}
			cout << "  ";
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
void next_generation(point world[][__WORLD_HEIGHT__], point prev_world[][__WORLD_HEIGHT__], string answer, int Xcapital, int Ycapital, int mode, int Xbot, int Ybot, int DirectBot, int whileStop)
{
	unsigned int i, j;
	point p;
	string k;

	if (mode == 1) {
		if (answer == "�") {
			p = prev_world[Ycapital - 1][Xcapital];
			if (p.is_live == 0) {
				world[Ycapital - 1][Xcapital].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "������ �����?"; //Here
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
				cout << "������ �����?"; 
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
				cout << "������ �����?";
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
				cout << "������ �����?";
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
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int checkPlayers, Xcapital, Ycapital, user, users, bots;
	int bonusLive = 0;
	int bonusEat = 0;
	int politics = 0;

	startProgram();

	srand(time(NULL));

	user = 1;
	bots = 1;
	users = 1;

	cout << " --------------------------------------" << endl;
	cout << "|          ����� ������ ����           |" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << "| 1 - ���� � ����� | 2 - ���� � ������ |" << endl;
	cout << " --------------------------------------" << endl;

	system("cls");

	Xcapital = rand() % 59;
	Ycapital = rand() % 51;

	system("cls");
	point world[__WORLD_WIDTH__][__WORLD_HEIGHT__];
	point prev_world[__WORLD_WIDTH__][__WORLD_HEIGHT__];

	init_world(world, user, Xcapital, Ycapital, bots);

	int population = 1000;
	int eat = 2000;
	int prevPointOfFirstPl;
	int politicsOff = 0;

	while (true) {

		unsigned int i, j;

		for (i = 0; i < __WORLD_WIDTH__; i++) {
			for (j = 0; j < __WORLD_HEIGHT__; j++) {
				if (world[i][j].is_live == 1) {
					playerOnMap = 1;
				}
				else if (world[i][j].is_live == 2 && playerOnMap == 0) {
					playerOnMap = 2;
				}
				else if (world[i][j].is_live == 2 && playerOnMap == 1) {
					playerOnMap = 60;
				}
			}
		}

		if (playerOnMap == 1) {
			checkPlayers = 0;
		}
		else if (playerOnMap == 2) {
			system("cls");
			cout << "���� ��������";
			exit(0);
		}
		else if (playerOnMap == 60) {
			int checkPlayers = 1;
		}

		int whileStop = 0;
		int DirectBot = 0;

		string answer = "";
		int mode = 1;
		system("cls");

		unsigned int q, w;

		int pointOfFirstPl = 0;
		int pointOfSecondPl = 0;
		for (q = 0; q < __WORLD_WIDTH__; q++) {
			for (w = 0; w < __WORLD_HEIGHT__; w++) {
				if (world[q][w].is_live == 1) {
					pointOfFirstPl += 1;
				}
				else if (world[q][w].is_live == 2) {
					pointOfSecondPl += 1;
				}
			}
		}

		if (pointOfFirstPl != 1) {
			if (prevPointOfFirstPl < pointOfFirstPl) {
				population = population - 800 * prevPointOfFirstPl;
			}
		}

		prevPointOfFirstPl = pointOfFirstPl;

		print_world(world);
		cout << "  -------------------------------------------------------------------------------------------------------------------  " << endl;
		cout << " /                                                       ����                                                        \\ " << endl;
		cout << "|----------------------------------------------------------|----------------------------------------------------------|" << endl;
		cout << "|             ����������� � ������ ����������              |                  �������� ������ ������                  |" << endl;
		cout << "|--------------------------\\ /-----------------------------|---------------------------------------------/------------|" << endl;
		cout << "| � - ������ ������� �����  |  �� - ��������� ������ ����  | �� - ����������� ���������� ��������� ����� | �� - ����� |" << endl;
		cout << "| � - ������ ������ �����   |  �� - ��������� ������ ����  | �� - ����������� ���������� ������� (�)     | �������    |" << endl;
		cout << "| � - ������ ����� �����    |  �� - ��������� ������ ����� | �� - ����������� ���������� ��� (�)         \\------------|" << endl;
		cout << "| � - ������ ������ �����   |  �� - ��������� ������ ������| �� - ����������� ���������� �������� (�)                 |" << endl;
		cout << "|--------------------------/ \\-----------------------------| �� - ����������� ���������� ������� (�)                  |" << endl;
		cout << "|                  �������������� �������                  |----------------------------------------------------------|" << endl;
		cout << "|----------------------------------------------------------| �������� �������� ���� �������� � ����������� ��         |" << endl;
		cout << "\\ �� - ��������� ���                                       | ���������� ������� (������) ��� ����� ���������          /" << endl;
		cout << " ---------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "����������:" << endl;
		cout << "������ ������ ��: " << endl;
		cout << "X: " << Xcapital + 1 << " | Y: " << Ycapital + 1 << endl;
		cout << "���������� ����� ������� (������): ";
		cout << pointOfFirstPl << endl;
		cout << "���������: " << population;
		if (bonusLive != 0) {
			cout << "(+ " << bonusLive << ")" << endl;
		}
		else {
			cout << endl;
		}
		int eatMinus = population * 2;
		int eatPlus = population * 3 + bonusEat;
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "������:" << endl;
		cout << "���: " << eat;
		if (bonusEat > 0) {
			cout << "(+" << bonusEat << " )" << endl;
		}
		else {
			cout << endl;
		}
		cout << "�����: ";
		cin >> answer;
		if (answer == "��" || politics == 1) {
			bonusLive = 400 + 100 * pointOfFirstPl;
			politics = 1;
		} 
		else if (answer == "��" || politics == 3) {
			bonusEat = 600 + 100 * pointOfFirstPl;
			politics = 3;
		} 
		else if (answer == "��") {
			politicsOff = 1;
		}
		if (answer == "�" || answer == "�" || answer == "�" || answer == "�") {
			if (population - 800 * prevPointOfFirstPl > 1) {
				copy_world(world, prev_world);
				next_generation(world, prev_world, answer, Xcapital, Ycapital, mode, Xbot, Ybot, DirectBot, whileStop);
			}
		}
		if (answer == "��" || answer == "��" || answer == "��" || answer == "��") {
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
		else if (answer == "��") {
			population = population + 990 + 10 * pointOfFirstPl + bonusLive;
			eat = eat - population * 2;
			eat = eat + population * 3 + bonusEat;
			
			if (politicsOff == 1) {
				politics = 0;
				politicsOff = 0;
			}

			if (politics != 1) {
				bonusLive = 0;
			}
			if (politics != 2) {

			}
			if (politics != 3) {
				bonusEat = 0;
			}
		}
	}
	system("pause");
}