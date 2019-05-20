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

/* Ширина игрового поля */
#define __WORLD_HEIGHT__ 58

/* Высота игрового поля */
#define __WORLD_WIDTH__ 50

/*
* Запуск "логотипа" игры, а также показ начального меню
* Команды:
* 1 - Запуск программы
* 99 - Завершение программы
*/
void startProgram() {
	int timer = 150;

	cout << "" << endl;
	cout << "" << endl;
	Sleep(timer);
	cout << "___________________________________AA_____________ " << endl;
	Sleep(timer);
	cout << "_____________________88__________8800_____________ " << endl;
	Sleep(timer);
	cout << "_____________________00((______AA0000_____________ " << endl;
	Sleep(timer);
	cout << "___________________000088____!!000000;;___________ " << endl;
	Sleep(timer);
	cout << "_______________!!00000088____0000000000___________ " << endl;
	Sleep(timer);
	cout << "_______________0000000088____0000000000___________ " << endl;
	Sleep(timer);
	cout << "_____________880000000088____0000000000____QQ_____ " << endl;
	Sleep(timer);
	cout << "_____''00____000000000000____88000000AA____88AA___ " << endl;
	Sleep(timer);
	cout << "___::0000____8800000000________558822______0000___ " << endl;
	Sleep(timer);
	cout << "___000000______880000____________________88000088_ " << endl;
	Sleep(timer);
	cout << "_2200000022______________________________00000000_ " << endl;
	Sleep(timer);
	cout << "_8800000000____________________________2200000000_ " << endl;
	Sleep(timer);
	cout << "_8800000088____________________________::00000088_ " << endl;
	Sleep(timer);
	cout << "___000000______00000000000000000088______880088___ " << endl;
	Sleep(timer);
	cout << "_____________000000000000000000000000((___________ " << endl;
	Sleep(timer);
	cout << "___________0000000000000000000000000000___________ " << endl;
	Sleep(timer);
	cout << "___________0000000000000000000000000000___________ " << endl;
	Sleep(timer);
	cout << "___________0000000000000000000000000000___________ " << endl;
	Sleep(timer);
	cout << "___________0000000000000000000000000000___________ " << endl;
	Sleep(timer);
	cout << "___________88000000000000000000000000;;___________ " << endl;
	Sleep(timer);
	cout << "_____________0000000000000000000000AA_____________ " << endl;
	Sleep(timer);
	cout << "_______________00000000000000000088_______________ " << endl;
	Sleep(timer);
	cout << "_________________00000000000000**_________________ " << endl;
	Sleep(timer);
	cout << "___________________0000000088_____________________ " << endl;
	Sleep(timer);
	cout << "_____________________0000++_______________________ " << endl;
	Sleep(timer);
	cout << "" << endl;
	cout << "" << endl;
	Sleep(2000);
	system("cls");

	cout << " --------------------------------------" << endl;
	cout << "| 1 - Начать игру | 99 - Выход из игры |" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << "| Версия игры: 0.1                     |" << endl;
	cout << "| Автор: Jourloy (jourloy@yandex.ru)   |" << endl;
	cout << " --------------------------------------" << endl;
	int startProgramAnswer = 0;

	while (startProgramAnswer != 1 or startProgramAnswer != 99) {
		cout << "\nОтвет: ";
		cin >> startProgramAnswer;

		if (startProgramAnswer != 1 or startProgramAnswer != 99) {
			cout << "Вы ввели " << startProgramAnswer << ", но такого варианта нет!" << endl;
		}
	}
	system("cls");

}

// Cтруктура для хранения состояние клетки
struct point {
	unsigned int is_live;
};

/*
 * Создание карты при помощи случайных чисел
 */
void init_world(point world[][__WORLD_HEIGHT__], int user, int Xcapital, int Ycapital, int bots)
{
	int i, j;
	int Xbot; 
	int Ybot;

	i = rand() % 59;
	j = rand() % 51;

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

	world[Ycapital][Xcapital].is_live = 1;
}

/*
 * Вывод на экран игрового поля
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
 * Получение координат соседей точки (окрестность мура 1 порядка)
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
 * Количество живых соседей у клетки с координатами x, y
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
 * Копирование игрового мира. Используется для сохранения предыдущего поколения
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
 * Сгенерировать следующее поколение игрового мира
 */
void next_generation(point world[][__WORLD_HEIGHT__], point prev_world[][__WORLD_HEIGHT__], string answer, int Xcapital, int Ycapital, int mode, int Xbot, int Ybot, int DirectBot, int whileStop)
{
	unsigned int i, j;
	point p;
	string k;

	if (mode == 1) {
		if (answer == "В") {
			p = prev_world[Ycapital-1][Xcapital];
			if(p.is_live == 0) {
				world[Ycapital - 1][Xcapital].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "Начать войну?"; //TODO: Почему здесь CHAR? Нужно вывести длинную строку!
				cin >> k;
				if (k == "Да") {
					world[Ycapital - 1][Xcapital].is_live = 1;
				}
				else {
					world[Ycapital - 1][Xcapital].is_live = 0;
				}
			}
			else {
				cout << "Ход пропущен" << endl;
				system("pause");
			}
		}
		else if (answer == "Л") {
			p = prev_world[Ycapital][Xcapital - 1];
			if (p.is_live == 0) {
				world[Ycapital][Xcapital - 1].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "Начать войну?"; //TODO: Почему здесь CHAR? Нужно вывести длинную строку!
				cin >> k;
				if (k == "Да") {
					world[Ycapital][Xcapital - 1].is_live = 1;
				}
				else {
					world[Ycapital][Xcapital - 1].is_live = 0;
				}
			}
			else {
				cout << "Ход пропущен" << endl;
				system("pause");
			}
		}
		else if (answer == "П") {
			p = prev_world[Ycapital][Xcapital + 1];
			if (p.is_live == 0) {
				world[Ycapital][Xcapital + 1].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "Начать войну?"; //TODO: Почему здесь CHAR? Нужно вывести длинную строку!
				cin >> k;
				if (k == "Да") {
					world[Ycapital][Xcapital + 1].is_live = 1;
				}
				else {
					world[Ycapital][Xcapital + 1].is_live = 0;
				}
			}
			else {
				cout << "Ход пропущен" << endl;
				system("pause");
			}
		}
		else if (answer == "Н") {
			p = prev_world[Ycapital + 1][Xcapital];
			if (p.is_live == 0) {
				world[Ycapital + 1][Xcapital].is_live = 1;
			}
			else if (p.is_live == 2) {
				cout << "Начать войну?"; //TODO: Почему здесь CHAR? Нужно вывести длинную строку!
				cin >> k;
				if (k == "Да") {
					world[Ycapital + 1][Xcapital].is_live = 1;
				}
				else {
					world[Ycapital + 1][Xcapital].is_live = 0;
				}
			}
			else {
				cout << "Ход пропущен" << endl;
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
					k = "Да";
				}
				else {
					k = "Нет";
				}
				if (k == "Да") {
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
					k = "Да";
				}
				else {
					k = "Нет";
				}
				if (k == "Да") {
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
					k = "Да";
				}
				else {
					k = "Нет";
				}
				if (k == "Да") {
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
					k = "Да";
				}
				else {
					k = "Нет";
				}
				if (k == "Да") {
					world[Ybot + 1][Xbot].is_live = 2;
				}
				else {
					world[Ybot + 1][Xbot].is_live = 0;
				}
			}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int checkPlayers, Xcapital, Ycapital, user, users, bots;

	startProgram();

	srand(time(NULL));

	user = 1;
	bots = 1;
	users = 1;

	cout << " --------------------------------------" << endl;
	cout << "|          Выбор режима игры           |" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << "| 1 - Игра с другом |                  |" << endl;
	cout << " --------------------------------------" << endl;

	system("cls");

	Xcapital = rand() % 59;
	Ycapital = rand() % 51;

	system("cls");
	point world[__WORLD_WIDTH__][__WORLD_HEIGHT__];
	point prev_world[__WORLD_WIDTH__][__WORLD_HEIGHT__];

	init_world(world, user, Xcapital, Ycapital, bots);

	int population = 0;
	population = 1000;
	int prevPointOfFirstPl;

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
			cout << "Игра окончена";
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
		cout << " ---------------------------------------------------------" << endl;
		cout << "             Перемещение и захват территорий             " << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "В - занять верхнюю точку     ВВ - перевести курсор выше   " << endl;
		cout << "Н - занять нижнюю точку      НН - перевести курсор ниже   " << endl;
		cout << "Л - занять левую точку       ЛЛ - перевести курсор левее  " << endl;
		cout << "П - занять правую точку      ПП - перевести курсор правее " << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "                        Информация                       " << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "Курсор сейчас на: " << endl;
		cout << "X: " << Xcapital + 1<< " | Y: " << Ycapital + 1<< endl;
		cout << "Количество ваших городов:" << endl;
		cout << pointOfFirstPl << endl;
		cout << "Население:" << endl;
		cout << population << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "КЦ - завершить ход" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "Ответ: ";
		cin >> answer;
		if (answer == "В" || answer == "Н" || answer == "Л" || answer == "П") {
			if (population - 800 * prevPointOfFirstPl > 1) {
				copy_world(world, prev_world);
				next_generation(world, prev_world, answer, Xcapital, Ycapital, mode, Xbot, Ybot, DirectBot, whileStop);
			}
		}
		else if (answer == "ВВ" || answer == "НН" || answer == "ЛЛ" || answer == "ПП") {
			point p;
			if (answer == "ВВ") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital - 1][Xcapital];
				if (p.is_live == 1) {
					Ycapital = Ycapital - 1;
				} 
			}
			else if (answer == "ЛЛ") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital][Xcapital - 1];
				if (p.is_live == 1) {
					Xcapital = Xcapital - 1;
				}
			}
			else if (answer == "НН") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital + 1][Xcapital];
				if (p.is_live == 1) {
					Ycapital = Ycapital + 1;
				}
			}
			else if (answer == "ПП") {
				copy_world(world, prev_world);
				p = prev_world[Ycapital][Xcapital];
				if (p.is_live == 1) {
					Xcapital = Xcapital + 1;
				}
			}
		}
		else if (answer == "КЦ") {
			population = population + 990 + 10 * pointOfFirstPl;
		}
	}
	system("pause");
}
