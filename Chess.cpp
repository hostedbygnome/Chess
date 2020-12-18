#include <stdio.h>
#include <iostream>
#include <math.h>
#include <Windows.h>


using std::cout;
using std::cin;
using namespace std;

void SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
int main()
{
	setlocale(LC_ALL, "rus");
	char deck[8][8];
	SetColor(15, 0);
	
	int choice1 = 0;
	int choice = 0;
do
{

do	
{
	cout << "Начать выбор задач? (1 --- Начать, 2 --- Выйти): "; // меню
	cin >> choice1;
	if (choice1 != 2 && choice1 != 1)
		cout << "Можно вводить только 1 или 2!" << endl;
	else if (choice1 == 1 || choice1 == 2)
		break;
	} while (choice1 != 1);
	if (choice1 == 2)
	{
		cout << "До свидания" << endl;
		break;
	}

		
cout << "Выберите номер задачи\nа) - 1\nб) - 2\nв) - 3\nг) - 4\nд) - 5\nе) - 6\nЗадача №: "; // меню по задачам
cin >> choice;
switch (choice)
		{
		case 1:
		{

			int x1 = -5;
			int y1 = -5;
			int x2 = -5;
			int y2 = -5;
			char field1;
			char field2;
			// введение полей с проверкой
			do // x1
			{
				cout << "Введите координаты поля №1 (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x1 > 8 || x1 < 1);

			do // y1
			{
				cout << "Введите координаты поля №1 (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y1 > 8 || y1 < 1);

			do // x2
			{
				cout << "Введите координаты поля №2 (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x2 > 8 || x2 < 1);

			do // y2
			{
				cout << "Введите координаты поля №2 (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y2 > 8 || y2 < 1);

			for (int i = 0; i < 8; i++) // сравнение двух полей
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						if ((x1 - 1 == i) && (y1 - 1 == j))
						{
							field1 = 'x';
						}

						if ((x2 - 1 == i) && (y2 - 1 == j))
						{
							field2 = 'x';
						}

					}
					else
					{
						if ((x1 - 1 == i) && (y1 - 1 == j))
						{
							field1 = 'o';
						}

						if ((x2 - 1 == i) && (y2 - 1 == j))
						{
							field2 = 'o';
						}

					}
				}

			}
			cout << endl;
			// вывод ответа (буква а)
			SetColor(0, 15);
			cout << "Ответ под буквой а): ";
			if (field1 == field2)
				cout << "Поля одного цвета";
			else
				cout << "Поля разного цвета";
			SetColor(15, 0);
			cout << "\n\n";
			cout << "Клетка №1 - 'x' (красный), Клетка №2 - 'o'(синий)" << endl;
			cout << "После нажатия любой кнопки выведется шахматная доска" << endl;
			system("pause");
			cout << "Ось х - сверху вниз, Ось y - слева направо";
			cout << "\n";
			// шахматная доска
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						deck[i][j] = 'x';
					}
					else
					{
						deck[i][j] = 'o';
					}
				}

			}
			// вывод клеток
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (deck[i][j] == 'x')
					{
						if (x1 - 1 == i && y1 - 1 == j)
						{
							SetColor(4, 0);
							cout << 'x' << "  ";
							SetColor(0, 0);
						}
						else if (x2 - 1 == i && y2 - 1 == j)
						{
							SetColor(1, 0);
							cout << 'o' << "  ";
							SetColor(0, 0);
						}
						else
						{
							SetColor(0, 0);
							cout << deck[i][j] << "  ";
						}

					}
					else
					{
						if (x1 - 1 == i && y1 - 1 == j)
						{
							SetColor(4, 15);
							cout << 'x' << "  ";
							SetColor(15, 15);
						}
						else if (x2 - 1 == i && y2 - 1 == j)
						{
							SetColor(1, 15);
							cout << 'o' << "  ";
							SetColor(15, 15);
						}
						else
						{
							SetColor(15, 15);
							cout << deck[i][j] << "  ";
						}
					}

				}
				SetColor(15, 0);
				cout << endl;
				
			}
			SetColor(15, 0);
			cout << endl;
			cout << endl;
			cout << endl;
			
			break;
		}
		case 2:
		{
			int x1 = -5;
			int y1 = -5;
			int x2 = -5;
			int y2 = -5;
			char ferz;
			char field2;
			// введение полей с проверкой
			do // ферзь x1
			{
				cout << "Введите координаты ферзня (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ферзь y1
			{
				cout << "Введите координаты ферзя (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y1 > 8 || y1 < 1);

			do // клетка x2
			{
				cout << "Введите координаты поля (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x2 > 8 || x2 < 1);

			do // клетка y2
			{
				cout << "Введите координаты поля(y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y2 > 8 || y2 < 1);



			// шахматная доска
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						deck[i][j] = 'x';
					}
					else
					{
						deck[i][j] = 'o';
					}
				}

			}
			cout << endl;
			// проверка на угрозу, вывод ответа б)
			int check_x;
			int check_y;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			SetColor(0, 15);
			cout << "Ответ под буквой б): ";
			if (x2 == x1 || y2 == y1 || check_x == check_y)
				cout << "Клетка под угрозой ферзя";
			else
				cout << "Клетка в безопасности";
			SetColor(15, 0);
			cout << "\n\n";
			cout << "Ферзь - 'x' (красный), Клетка - 'o'(синий)" << endl;
			cout << "После нажатия любой кнопки выведется шахматная доска с ферзем и клеткой" << endl;
			system("pause");
			cout << "Ось х - сверху вниз, Ось y - слева направо";
			cout << "\n";
			// вывод ферзя и клетки
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (deck[i][j] == 'x')
					{
						if (x1 - 1 == i && y1 - 1 == j)
						{
							SetColor(4, 0);
							cout << 'x' << "  ";
							SetColor(0, 0);
						}
						else if (x2 - 1 == i && y2 - 1 == j)
						{
							SetColor(1, 0);
							cout << 'o' << "  ";
							SetColor(0, 0);
						}
						else
						{
							SetColor(0, 0);
							cout << deck[i][j] << "  ";
						}

					}
					else
					{
						if (x1 - 1 == i && y1 - 1 == j)
						{
							SetColor(4, 15);
							cout << 'x' << "  ";
							SetColor(15, 15);
						}
						else if (x2 - 1 == i && y2 - 1 == j)
						{
							SetColor(1, 15);
							cout << 'o' << "  ";
							SetColor(15, 15);
						}
						else
						{
							SetColor(15, 15);
							cout << deck[i][j] << "  ";
						}
					}

				}
				SetColor(15, 0);
				cout << endl;
			}
			
			break;
		}
		case 3:
		{
			int x1 = -5;
			int y1 = -5;
			int x2 = -5;
			int y2 = -5;
			char horse;
			char field2;
			// введение полей с проверкой
			do // конь x1
			{
				cout << "Введите координаты коня (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x1 > 8 || x1 < 1);

			do // конь y1
			{
				cout << "Введите координаты коня (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y1 > 8 || y1 < 1);

			do // клетка x2
			{
				cout << "Введите координаты поля (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x2 > 8 || x2 < 1);

			do // клетка y2
			{
				cout << "Введите координаты поля (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y2 > 8 || y2 < 1);



			// шахматная доска
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						deck[i][j] = 'x';
					}
					else
					{
						deck[i][j] = 'o';
					}
				}

			}
			cout << endl;
			// проверка на угрозу, вывод ответа в)
			int check_x;
			int check_y;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			SetColor(0, 15);
			cout << "Ответ под буквой в): ";
			if (check_x == 1 && check_y == 2 || check_x == 2 && check_y == 1)
				cout << "Клетка под угрозой коня";
			else
				cout << "Клетка в безопасности";
			cout << "\n\n";
			SetColor(15, 0);
			cout << "Конь - 'x' (красный), Клетка - 'o'(синий)" << endl;
			cout << "После нажатия любой кнопки выведется шахматная доска с ферзем и клеткой" << endl;
			system("pause");
			cout << "Ось х - сверху вниз, Ось y - слева направо";
			cout << "\n";
			// вывод коня и клетки
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (deck[i][j] == 'x')
					{
						if (x1 - 1 == i && y1 - 1 == j)
						{
							SetColor(4, 0);
							cout << 'x' << "  ";
							SetColor(0, 0);
						}
						else if (x2 - 1 == i && y2 - 1 == j)
						{
							SetColor(1, 0);
							cout << 'o' << "  ";
							SetColor(0, 0);
						}
						else
						{
							SetColor(0, 0);
							cout << deck[i][j] << "  ";
						}

					}
					else
					{
						if (x1 - 1 == i && y1 - 1 == j)
						{
							SetColor(4, 15);
							cout << 'x' << "  ";
							SetColor(15, 15);
						}
						else if (x2 - 1 == i && y2 - 1 == j)
						{
							SetColor(1, 15);
							cout << 'o' << "  ";
							SetColor(15, 15);
						}
						else
						{
							SetColor(15, 15);
							cout << deck[i][j] << "  ";
						}
					}

				}
				SetColor(15, 0);
				cout << endl;
			}
			
			break;
		}
		case 4:
		{
			int x1 = -5;
			int y1 = -5;
			int x2 = -5;
			int y2 = -5;
			char horse;
			char field2;
			// введение полей с проверкой
			do // ладья x1
			{
				cout << "Введите координаты ладьи (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ладья y1
			{
				cout << "Введите координаты ладьи (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y1 > 8 || y1 < 1);

			do // клетка x2
			{
				cout << "Введите координаты поля (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x2 > 8 || x2 < 1);

			do // клетка y2
			{
				cout << "Введите координаты поля (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y2 > 8 || y2 < 1);



			// шахматная доска
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						deck[i][j] = 'x';
					}
					else
					{
						deck[i][j] = 'o';
					}
				}

			}
			cout << endl;
			// проверка на попадание с первого хода, вывод ответа г)
			int check_x;
			int check_y;
			check_x = x2 - x1;
			check_y = y2 - y1;
			SetColor(0, 15);
			cout << "Ответ под буквой г): ";
			if (x1 == x2 || y1 == y2)
				cout << "Можно попасть на клетку с первого хода";
			else if (x1 != x2 || y1 != y2)
				cout << "С первого хода попасть на клетку нельзя, но если  \nпервый ход будет: " << "x = " << x1 + check_x << ", y = " << y1 << "  \nили первый ход будет: " << "x = " << x1 << ", y = " << y1 + check_y << " - то можно попасть со второго хода";
			
			SetColor(15, 0);
			cout << "\n\n";
			cout << "Ладья - 'x' (красный), Клетка - 'o'(синий)" << endl;
			cout << "После нажатия любой кнопки выведется шахматная доска с ладьей и клеткой" << endl;
			system("pause");
			cout << "Ось х - сверху вниз, Ось y - слева направо";
			cout << "\n";
			// вывод коня и клетки
			if (x1 == x2 || y1 == y2)
			{
				cout << "\nПопасть на клетку можно с первого хода  \n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
			}
			else if (x1 != x2 || y1 != y2)
			{
				cout << "\n---Попасть на клетку можно со второго хода (Показано первоначальное положение)---\n\n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
				cout << "\nПервый ход 1-ый способ\n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 + check_x - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 + check_x - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
				cout << endl;
				cout << "\nПервый ход 2-ой способ\n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 - 1 == i && y1 + check_y - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 - 1 == i && y1 + check_y - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
			}

			SetColor(15, 0);
			break;
		}
		case 5:
		{
			int x1 = -5;
			int y1 = -5;
			int x2 = -5;
			int y2 = -5;
			char horse;
			char field2;
			// введение полей с проверкой
			do // ферзь x1
			{
				cout << "Введите координаты ферзя (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ферзь y1
			{
				cout << "Введите координаты ферзя (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y1 > 8 || y1 < 1);

			do // клетка x2
			{
				cout << "Введите координаты поля (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x2 > 8 || x2 < 1);

			do // клетка y2
			{
				cout << "Введите координаты поля (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y2 > 8 || y2 < 1);



			// шахматная доска
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						deck[i][j] = 'x';
					}
					else
					{
						deck[i][j] = 'o';
					}
				}

			}
			cout << endl;
			// проверка на попадание с первого хода, вывод ответа д)
			int check_x;
			int check_y;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			int check_x3 = x2 - x1;
			int check_y3 = y2 - y1;
			int check_y1 = abs(y2 - y1);
			int check_x2 = abs(x2 - x1);
			int check_x1 = x1;
			int check_y2 = y1;
			SetColor(0, 15);
			cout << "Ответ под буквой д): ";
			if (x1 == x2 || y1 == y2 || check_x == check_y)
				cout << "Можно попасть на клетку с первого хода";
			else if (x1 != x2 || y1 != y2 || check_x != check_y)
			{
				cout << "С первого хода попасть на клетку нельзя, но если  \nпервый ход будет: " << "x = " << x1 + check_x << ", y = " << y1 << "  \nили первый ход будет: " << "x = " << x1 << ", y = " << y1 + check_y;
				if (x1 < x2)
					check_x1 += check_y1;
				else
					check_x1 -= check_y1;
				if (check_x1 > 8 || check_x1 < 1)
					cout << endl;
				else
					cout << "  \nили первый ход будет: " << "x = " << check_x1 << ", y = " << y2;


				if (y1 < y2)
					check_y2 += check_x2;
				else
					check_y2 -= check_x2;
				if (check_y2 > 8 || check_y2 < 1)
					cout << endl;
				else
					cout << "  \nили первый ход будет: " << "x = " << x2 << ", y = " << check_y2;
				cout << " - то можно попасть со второго хода";
			}

			SetColor(15, 0);
			cout << "\n\n";
			cout << "Ферзь - 'x' (красный), Клетка - 'o'(синий)" << endl;
			cout << "После нажатия любой кнопки выведется шахматная доска с ферзем и клеткой" << endl;
			system("pause");
			cout << "Ось х - сверху вниз, Ось y - слева направо";
			cout << "\n";
			// вывод ферзя и клетки
			if (x1 == x2 || y1 == y2 || check_x == check_y)
			{
				cout << "\nПопасть на клетку можно с первого хода  \n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
				SetColor(15, 0);
				break;
			}
			else if (x1 != x2 || y1 != y2 || check_x != check_y)
			{
				cout << "\n---Попасть на клетку можно со второго хода (Показано первоначальное положение)---\n\n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
				cout << "\nПервый ход 1-ый способ\n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 + check_x3 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 + check_x3 - 1 == i && y1 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
				cout << endl;
				cout << "\nПервый ход 2-ой способ\n";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (deck[i][j] == 'x')
						{
							if (x1 - 1 == i && y1 + check_y3 - 1 == j)
							{
								SetColor(4, 0);
								cout << 'x' << "  ";
								SetColor(0, 0);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 0);
								cout << 'o' << "  ";
								SetColor(0, 0);
							}
							else
							{
								SetColor(0, 0);
								cout << deck[i][j] << "  ";
							}

						}
						else
						{
							if (x1 - 1 == i && y1 + check_y3 - 1 == j)
							{
								SetColor(4, 15);
								cout << 'x' << "  ";
								SetColor(15, 15);
							}
							else if (x2 - 1 == i && y2 - 1 == j)
							{
								SetColor(1, 15);
								cout << 'o' << "  ";
								SetColor(15, 15);
							}
							else
							{
								SetColor(15, 15);
								cout << deck[i][j] << "  ";
							}
						}

					}
					SetColor(15, 0);
					cout << endl;
				}
				cout << endl;
				if (check_x1 > 8 || check_x1 < 1)
					cout << endl;
				else
				{
					cout << "\nПервый ход 3-ий способ\n";
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							if (deck[i][j] == 'x')
							{
								if (check_x1 - 1 == i && y2 - 1 == j)
								{
									SetColor(4, 0);
									cout << 'x' << "  ";
									SetColor(0, 0);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 0);
									cout << 'o' << "  ";
									SetColor(0, 0);
								}
								else
								{
									SetColor(0, 0);
									cout << deck[i][j] << "  ";
								}

							}
							else
							{
								if (check_x1 - 1 == i && y2 - 1 == j)
								{
									SetColor(4, 15);
									cout << 'x' << "  ";
									SetColor(15, 15);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 15);
									cout << 'o' << "  ";
									SetColor(15, 15);
								}
								else
								{
									SetColor(15, 15);
									cout << deck[i][j] << "  ";
								}
							}

						}
						SetColor(15, 0);
						cout << endl;
					}
				}
				if (check_y2 > 8 || check_y2 < 1)
					cout << endl;
				else
				{
					cout << "\nПервый ход 4-ый способ\n";
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							if (deck[i][j] == 'x')
							{
								if (x2 - 1 == i && check_y2 - 1 == j)
								{
									SetColor(4, 0);
									cout << 'x' << "  ";
									SetColor(0, 0);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 0);
									cout << 'o' << "  ";
									SetColor(0, 0);
								}
								else
								{
									SetColor(0, 0);
									cout << deck[i][j] << "  ";
								}

							}
							else
							{
								if (x2 - 1 == i && check_y2 - 1 == j)
								{
									SetColor(4, 15);
									cout << 'x' << "  ";
									SetColor(15, 15);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 15);
									cout << 'o' << "  ";
									SetColor(15, 15);
								}
								else
								{
									SetColor(15, 15);
									cout << deck[i][j] << "  ";
								}
							}

						}
						SetColor(15, 0);
						cout << endl;
					}
				}

			}

			SetColor(15, 0);
			break;

		}
		case 6:
		{
			int x1 = -5;
			int y1 = -5;
			int x2 = -5;
			int y2 = -5;
			// введение полей с проверкой
			do // слон x1
			{
				cout << "Введите координаты слона (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x1 > 8 || x1 < 1);

			do // слон y1
			{
				cout << "Введите координаты слона (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y1 > 8 || y1 < 1);

			do // клетка x2
			{
				cout << "Введите координаты поля (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (x2 > 8 || x2 < 1);

			do // клетка y2
			{
				cout << "Введите координаты поля (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "Можно вводить числа только от 1 до 8\n";
			} while (y2 > 8 || y2 < 1);



			// шахматная доска
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						deck[i][j] = 'x';
					}
					else
					{
						deck[i][j] = 'o';
					}
				}

			}
			cout << endl;
			// проверка на попадание с первого хода, вывод ответа е)
			int check_x;
			int check_y;
			char slon;
			char field;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			int check_y1 = abs(y2 - y1);
			int check_x2 = abs(x2 - x1);
			// вывод слона и клетки
			for (int i = 0; i < 8; i++) // сравнение двух полей
			{
				for (int j = 0; j < 8; j++)
				{
					if (((i == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 0) && (j % 2 == 1) && (j != 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j == 0)) || ((i % 2 == 1) && (j % 2 == 0) && (j != 0)))
					{
						if ((x1 - 1 == i) && (y1 - 1 == j))
						{
							slon = 'x';
						}

						if ((x2 - 1 == i) && (y2 - 1 == j))
						{
							field = 'x';
						}

					}
					else
					{
						if ((x1 - 1 == i) && (y1 - 1 == j))
						{
							slon = 'o';
						}

						if ((x2 - 1 == i) && (y2 - 1 == j))
						{
							field = 'o';
						}

					}
				}

			}
			cout << endl;
			// вывод ответа (буква e)
			SetColor(0, 15);
			cout << "Сравнение полей на цвет: ";
			if (slon == field)
			{
				cout << "Поля одного цвета, решение возможно" << endl;
				int checked_x = 0;
				int checked_y = 0;
				int check_y5;
				int check_x5;
				for (int i = 1; i < 9; i++) // поиск нужных клеток
				{
					for (int j = 1; j < 9; j++)
					{
						checked_y = i;
						checked_x = j;
						if (abs(x2 - checked_x) == abs(y2 - checked_y) && abs(checked_x - x1) == abs(checked_y - y1)) // проверка условия на "диагональ"
							break;

					}
					if (abs(x2 - checked_x) == abs(y2 - checked_y) && abs(checked_x - x1) == abs(checked_y - y1))
						break;

				}
				int checked_x1 = 0;
				int checked_y1 = 0;
				int check_y6;
				int check_x6;
				// поиск нужных клеток
				for (int i = 1; i < 9; i++)// проверка условия на "диагональ" 2ой способ
				{
					for (int j = 1; j < 9; j++)
					{
						checked_y1 = i;
						checked_x1 = j;
						if (abs(x2 - checked_x1) == abs(y2 - checked_y1) && abs(checked_x1 - x1) == abs(checked_y1 - y1) && checked_x1 != checked_x && checked_y1 != checked_y)
							break;

					}
					if (abs(x2 - checked_x1) == abs(y2 - checked_y1) && abs(checked_x1 - x1) == abs(checked_y1 - y1) && checked_x1 != checked_x && checked_y1 != checked_y)
						break;

				}

				check_y5 = checked_y;
				check_x5 = checked_x;
				check_y6 = checked_y1;
				check_x6 = checked_x1;
				SetColor(0, 15);
				if (check_x == check_y)
					cout << "Ответ под буквой е): Можно попасть на клетку с первого хода";
				else
				{
					cout << "С первого хода попасть на клетку нельзя, но если  \nпервый ход будет: " << "x = " << check_x5 << ", y = " << check_y5;
					if (abs(x2 - checked_x1) == abs(y2 - checked_y1) && abs(checked_x1 - x1) == abs(checked_y1 - y1) && checked_x1 != checked_x && checked_y1 != checked_y)
					{
						std::cout << "\nили первый ход будет: " << "x = " << check_x6 << ", y = " << check_y6;
					}
						else
							cout << " ";
					cout << " - решение возможно за 2 хода";

				}
					
				SetColor(15, 0);
				cout << "\n\n";
				
				cout << "Слон - 'x' (красный), Клетка - 'o'(синий)" << endl;
				cout << "После нажатия любой кнопки выведется шахматная доска со слоном и клеткой" << endl;
				system("pause");
				cout << "Ось х - сверху вниз, Ось y - слева направо";
				cout << "\n";
				if (check_x == check_y)
				{
					cout << "\nПопасть на клетку можно с первого хода  \n";
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							if (deck[i][j] == 'x')
							{
								if (x1 - 1 == i && y1 - 1 == j)
								{
									SetColor(4, 0);
									cout << 'x' << "  ";
									SetColor(0, 0);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 0);
									cout << 'o' << "  ";
									SetColor(0, 0);
								}
								else
								{
									SetColor(0, 0);
									cout << deck[i][j] << "  ";
								}

							}
							else
							{
								if (x1 - 1 == i && y1 - 1 == j)
								{
									SetColor(4, 15);
									cout << 'x' << "  ";
									SetColor(15, 15);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 15);
									cout << 'o' << "  ";
									SetColor(15, 15);
								}
								else
								{
									SetColor(15, 15);
									cout << deck[i][j] << "  ";
								}
							}

						}
						SetColor(15, 0);
						cout << endl;
					}
					cout << endl;

				}
				else if (check_x != check_y)
				{

					cout << "\n---Попасть на клетку можно со второго хода (Показано первоначальное положение)---\n\n";
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							if (deck[i][j] == 'x')
							{
								if (x1 - 1 == i && y1 - 1 == j)
								{
									SetColor(4, 0);
									cout << 'x' << "  ";
									SetColor(0, 0);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 0);
									cout << 'o' << "  ";
									SetColor(0, 0);
								}
								else
								{
									SetColor(0, 0);
									cout << deck[i][j] << "  ";
								}

							}
							else
							{
								if (x1 - 1 == i && y1 - 1 == j)
								{
									SetColor(4, 15);
									cout << 'x' << "  ";
									SetColor(15, 15);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 15);
									cout << 'o' << "  ";
									SetColor(15, 15);
								}
								else
								{
									SetColor(15, 15);
									cout << deck[i][j] << "  ";
								}
							}

						}
						SetColor(15, 0);
						cout << endl;
					}
					cout << "\nПервый ход 1 - ый способ\n"; // вывод способа
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							if (deck[i][j] == 'x')
							{
								if (check_x5 - 1 == i && check_y5 - 1 == j)
								{
									SetColor(4, 0);
									cout << 'x' << "  ";
									SetColor(0, 0);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 0);
									cout << 'o' << "  ";
									SetColor(0, 0);
								}
								else
								{
									SetColor(0, 0);
									cout << deck[i][j] << "  ";
								}

							}
							else
							{
								if (check_x5 - 1 == i && check_y5 - 1 == j)
								{
									SetColor(4, 15);
									cout << 'x' << "  ";
									SetColor(15, 15);
								}
								else if (x2 - 1 == i && y2 - 1 == j)
								{
									SetColor(1, 15);
									cout << 'o' << "  ";
									SetColor(15, 15);
								}
								else
								{
									SetColor(15, 15);
									cout << deck[i][j] << "  ";
								}
							}

						}
						SetColor(15, 0);
						cout << endl;
					}
					// проверка условия на диагональ
					if (!(abs(x2 - checked_x1) == abs(y2 - checked_y1) && abs(checked_x1 - x1) == abs(checked_y1 - y1) && checked_x1 != checked_x && checked_y1 != checked_y))
					{
						cout << endl;
					}
	
					else // вывод способа
					{
						cout << "\nПервый ход 2 - ой способ\n";
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; j++)
							{
								if (deck[i][j] == 'x')
								{
									if (check_x6 - 1 == i && check_y6 - 1 == j)
									{
										SetColor(4, 0);
										cout << 'x' << "  ";
										SetColor(0, 0);
									}
									else if (x2 - 1 == i && y2 - 1 == j)
									{
										SetColor(1, 0);
										cout << 'o' << "  ";
										SetColor(0, 0);
									}
									else
									{
										SetColor(0, 0);
										cout << deck[i][j] << "  ";
									}

								}
								else
								{
									if (check_x6 - 1 == i && check_y6 - 1 == j)
									{
										SetColor(4, 15);
										cout << 'x' << "  ";
										SetColor(15, 15);
									}
									else if (x2 - 1 == i && y2 - 1 == j)
									{
										SetColor(1, 15);
										cout << 'o' << "  ";
										SetColor(15, 15);
									}
									else
									{
										SetColor(15, 15);
										cout << deck[i][j] << "  ";
									}
								}

							}
							SetColor(15, 0);
							cout << endl;
						}

					}
					

				}
			}
			else
				cout << "Ответ под буквой д) поля разного цвета, решение невозможно";
			cout << "\n\n";
			SetColor(15, 0);
			break;

		}
		default:
		{
			break;
		}

		}
		cout << endl;
}while (choice1 == 1);
	return 0;
}