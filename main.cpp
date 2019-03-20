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
#define __WORLD_HEIGHT__ 5

/* Высота игрового поля */
#define __WORLD_WIDTH__ 5

void startProgram() {
	int timer = 150;
	int startProgramAnswer;

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
	cout << "| Версия игры: 0.1.0001                |" << endl;
	cout << "| Автор: Jourloy (jourloy@yandex.ru)   |" << endl;
	cout << " --------------------------------------" << endl;
	cout << "\nОтвет: ";
	cin >> startProgramAnswer;
	if (startProgramAnswer == 99) {
		exit(0);
	}
	system("cls");

}

// Cтруктура для хранения состояние клетки
struct point {
	unsigned int is_live;
};

/*
 * Инициализация первого поколения игры псевдослучайными значениями
 */
int init_world(point world[][__WORLD_HEIGHT__], int user, int Xcapital, int Ycapital, int bots) //TODO: Невозможна генерация бота надо мной
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
 * Вывести на экран игровое поле
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

/*
* Проверка всех клеток на занятность
*/
int testWorld(point world[][__WORLD_HEIGHT__]) {

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
	return playerOnMap;
}

int main() {
	int checkPlayers;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	startProgram();

	int Xcapital, Ycapital;
	int user, users, bots;

	srand(time(NULL));

	system("cls");
	cout << "Введите количество игроков (Доступно - 1): ";
	cin >> users;
	system("cls");
	cout << "Введите количество ботов (Доступно - 1): ";
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
	cout << "Выберите клетку-столицу" << endl;
	cout << "Координата Х: ";
	cin >> Xcapital;
	Xcapital -= 1;
	cout << "Координата Y: ";
	cin >> Ycapital;
	Ycapital -= 1;

	system("cls");
	point world[__WORLD_WIDTH__][__WORLD_HEIGHT__];
	point prev_world[__WORLD_WIDTH__][__WORLD_HEIGHT__];

	init_world(world, user, Xcapital, Ycapital, bots);
	while (true) {
		int livePlayers = testWorld(world);

		if (livePlayers == 1) {
			checkPlayers = 0;
		}
		else if (livePlayers == 2) {
			system("cls");
			cout << "Игра окончена";
			exit(0);
		}
		else if (livePlayers == 60) {
			int checkPlayers = 1;
		}

		int whileStop = 0;
		int DirectBot = 0;

		string answer = "";
		int mode = 1;
		system("cls");
		print_world(world);
		cout << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "|             Перемещение и захват территорий             " << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "В - занять верхнюю точку     ВВ - перевести курсор выше   " << endl;
		cout << "Н - занять нижнюю точку      НН - перевести курсор ниже   " << endl;
		cout << "Л - занять левую точку       ЛЛ - перевести курсор левее  " << endl;
		cout << "П - занять правую точку      ПП - перевести курсор правее " << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "                        Информация                       " << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "Курсор сейчас на: " << endl;
		cout << "X: " << Xcapital + 1<< " | Y: " << Ycapital + 1<< endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "КЦ - завершить ход" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "Ответ: ";
		cin >> answer;
		if (answer == "В" || answer == "Н" || answer == "Л" || answer == "П") {
			copy_world(world, prev_world);
			next_generation(world, prev_world, answer, Xcapital, Ycapital, mode, Xbot, Ybot, DirectBot, whileStop);
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
			if (checkPlayers != 0) { //TODO:Бот не играет (не связано с добавлением проверки игроков на карте
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
		}
	}
	system("pause");
}