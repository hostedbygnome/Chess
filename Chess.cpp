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
	cout << "������ ����� �����? (1 --- ������, 2 --- �����): "; // ����
	cin >> choice1;
	if (choice1 != 2 && choice1 != 1)
		cout << "����� ������� ������ 1 ��� 2!" << endl;
	else if (choice1 == 1 || choice1 == 2)
		break;
	} while (choice1 != 1);
	if (choice1 == 2)
	{
		cout << "�� ��������" << endl;
		break;
	}

		
cout << "�������� ����� ������\n�) - 1\n�) - 2\n�) - 3\n�) - 4\n�) - 5\n�) - 6\n������ �: "; // ���� �� �������
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
			// �������� ����� � ���������
			do // x1
			{
				cout << "������� ���������� ���� �1 (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x1 > 8 || x1 < 1);

			do // y1
			{
				cout << "������� ���������� ���� �1 (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y1 > 8 || y1 < 1);

			do // x2
			{
				cout << "������� ���������� ���� �2 (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x2 > 8 || x2 < 1);

			do // y2
			{
				cout << "������� ���������� ���� �2 (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y2 > 8 || y2 < 1);

			for (int i = 0; i < 8; i++) // ��������� ���� �����
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
			// ����� ������ (����� �)
			SetColor(0, 15);
			cout << "����� ��� ������ �): ";
			if (field1 == field2)
				cout << "���� ������ �����";
			else
				cout << "���� ������� �����";
			SetColor(15, 0);
			cout << "\n\n";
			cout << "������ �1 - 'x' (�������), ������ �2 - 'o'(�����)" << endl;
			cout << "����� ������� ����� ������ ��������� ��������� �����" << endl;
			system("pause");
			cout << "��� � - ������ ����, ��� y - ����� �������";
			cout << "\n";
			// ��������� �����
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
			// ����� ������
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
			// �������� ����� � ���������
			do // ����� x1
			{
				cout << "������� ���������� ������ (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ����� y1
			{
				cout << "������� ���������� ����� (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y1 > 8 || y1 < 1);

			do // ������ x2
			{
				cout << "������� ���������� ���� (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x2 > 8 || x2 < 1);

			do // ������ y2
			{
				cout << "������� ���������� ����(y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y2 > 8 || y2 < 1);



			// ��������� �����
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
			// �������� �� ������, ����� ������ �)
			int check_x;
			int check_y;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			SetColor(0, 15);
			cout << "����� ��� ������ �): ";
			if (x2 == x1 || y2 == y1 || check_x == check_y)
				cout << "������ ��� ������� �����";
			else
				cout << "������ � ������������";
			SetColor(15, 0);
			cout << "\n\n";
			cout << "����� - 'x' (�������), ������ - 'o'(�����)" << endl;
			cout << "����� ������� ����� ������ ��������� ��������� ����� � ������ � �������" << endl;
			system("pause");
			cout << "��� � - ������ ����, ��� y - ����� �������";
			cout << "\n";
			// ����� ����� � ������
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
			// �������� ����� � ���������
			do // ���� x1
			{
				cout << "������� ���������� ���� (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ���� y1
			{
				cout << "������� ���������� ���� (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y1 > 8 || y1 < 1);

			do // ������ x2
			{
				cout << "������� ���������� ���� (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x2 > 8 || x2 < 1);

			do // ������ y2
			{
				cout << "������� ���������� ���� (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y2 > 8 || y2 < 1);



			// ��������� �����
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
			// �������� �� ������, ����� ������ �)
			int check_x;
			int check_y;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			SetColor(0, 15);
			cout << "����� ��� ������ �): ";
			if (check_x == 1 && check_y == 2 || check_x == 2 && check_y == 1)
				cout << "������ ��� ������� ����";
			else
				cout << "������ � ������������";
			cout << "\n\n";
			SetColor(15, 0);
			cout << "���� - 'x' (�������), ������ - 'o'(�����)" << endl;
			cout << "����� ������� ����� ������ ��������� ��������� ����� � ������ � �������" << endl;
			system("pause");
			cout << "��� � - ������ ����, ��� y - ����� �������";
			cout << "\n";
			// ����� ���� � ������
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
			// �������� ����� � ���������
			do // ����� x1
			{
				cout << "������� ���������� ����� (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ����� y1
			{
				cout << "������� ���������� ����� (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y1 > 8 || y1 < 1);

			do // ������ x2
			{
				cout << "������� ���������� ���� (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x2 > 8 || x2 < 1);

			do // ������ y2
			{
				cout << "������� ���������� ���� (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y2 > 8 || y2 < 1);



			// ��������� �����
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
			// �������� �� ��������� � ������� ����, ����� ������ �)
			int check_x;
			int check_y;
			check_x = x2 - x1;
			check_y = y2 - y1;
			SetColor(0, 15);
			cout << "����� ��� ������ �): ";
			if (x1 == x2 || y1 == y2)
				cout << "����� ������� �� ������ � ������� ����";
			else if (x1 != x2 || y1 != y2)
				cout << "� ������� ���� ������� �� ������ ������, �� ����  \n������ ��� �����: " << "x = " << x1 + check_x << ", y = " << y1 << "  \n��� ������ ��� �����: " << "x = " << x1 << ", y = " << y1 + check_y << " - �� ����� ������� �� ������� ����";
			
			SetColor(15, 0);
			cout << "\n\n";
			cout << "����� - 'x' (�������), ������ - 'o'(�����)" << endl;
			cout << "����� ������� ����� ������ ��������� ��������� ����� � ������ � �������" << endl;
			system("pause");
			cout << "��� � - ������ ����, ��� y - ����� �������";
			cout << "\n";
			// ����� ���� � ������
			if (x1 == x2 || y1 == y2)
			{
				cout << "\n������� �� ������ ����� � ������� ����  \n";
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
				cout << "\n---������� �� ������ ����� �� ������� ���� (�������� �������������� ���������)---\n\n";
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
				cout << "\n������ ��� 1-�� ������\n";
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
				cout << "\n������ ��� 2-�� ������\n";
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
			// �������� ����� � ���������
			do // ����� x1
			{
				cout << "������� ���������� ����� (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ����� y1
			{
				cout << "������� ���������� ����� (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y1 > 8 || y1 < 1);

			do // ������ x2
			{
				cout << "������� ���������� ���� (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x2 > 8 || x2 < 1);

			do // ������ y2
			{
				cout << "������� ���������� ���� (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y2 > 8 || y2 < 1);



			// ��������� �����
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
			// �������� �� ��������� � ������� ����, ����� ������ �)
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
			cout << "����� ��� ������ �): ";
			if (x1 == x2 || y1 == y2 || check_x == check_y)
				cout << "����� ������� �� ������ � ������� ����";
			else if (x1 != x2 || y1 != y2 || check_x != check_y)
			{
				cout << "� ������� ���� ������� �� ������ ������, �� ����  \n������ ��� �����: " << "x = " << x1 + check_x << ", y = " << y1 << "  \n��� ������ ��� �����: " << "x = " << x1 << ", y = " << y1 + check_y;
				if (x1 < x2)
					check_x1 += check_y1;
				else
					check_x1 -= check_y1;
				if (check_x1 > 8 || check_x1 < 1)
					cout << endl;
				else
					cout << "  \n��� ������ ��� �����: " << "x = " << check_x1 << ", y = " << y2;


				if (y1 < y2)
					check_y2 += check_x2;
				else
					check_y2 -= check_x2;
				if (check_y2 > 8 || check_y2 < 1)
					cout << endl;
				else
					cout << "  \n��� ������ ��� �����: " << "x = " << x2 << ", y = " << check_y2;
				cout << " - �� ����� ������� �� ������� ����";
			}

			SetColor(15, 0);
			cout << "\n\n";
			cout << "����� - 'x' (�������), ������ - 'o'(�����)" << endl;
			cout << "����� ������� ����� ������ ��������� ��������� ����� � ������ � �������" << endl;
			system("pause");
			cout << "��� � - ������ ����, ��� y - ����� �������";
			cout << "\n";
			// ����� ����� � ������
			if (x1 == x2 || y1 == y2 || check_x == check_y)
			{
				cout << "\n������� �� ������ ����� � ������� ����  \n";
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
				cout << "\n---������� �� ������ ����� �� ������� ���� (�������� �������������� ���������)---\n\n";
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
				cout << "\n������ ��� 1-�� ������\n";
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
				cout << "\n������ ��� 2-�� ������\n";
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
					cout << "\n������ ��� 3-�� ������\n";
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
					cout << "\n������ ��� 4-�� ������\n";
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
			// �������� ����� � ���������
			do // ���� x1
			{
				cout << "������� ���������� ����� (x1): ";
				cin >> x1;
				if (x1 > 8 || x1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x1 > 8 || x1 < 1);

			do // ���� y1
			{
				cout << "������� ���������� ����� (y1): ";
				cin >> y1;
				if (y1 > 8 || y1 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y1 > 8 || y1 < 1);

			do // ������ x2
			{
				cout << "������� ���������� ���� (x2): ";
				cin >> x2;
				if (x2 > 8 || x2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (x2 > 8 || x2 < 1);

			do // ������ y2
			{
				cout << "������� ���������� ���� (y2): ";
				cin >> y2;
				if (y2 > 8 || y2 < 1)
					cout << "����� ������� ����� ������ �� 1 �� 8\n";
			} while (y2 > 8 || y2 < 1);



			// ��������� �����
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
			// �������� �� ��������� � ������� ����, ����� ������ �)
			int check_x;
			int check_y;
			char slon;
			char field;
			check_x = abs(x2 - x1);
			check_y = abs(y2 - y1);
			int check_y1 = abs(y2 - y1);
			int check_x2 = abs(x2 - x1);
			// ����� ����� � ������
			for (int i = 0; i < 8; i++) // ��������� ���� �����
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
			// ����� ������ (����� e)
			SetColor(0, 15);
			cout << "��������� ����� �� ����: ";
			if (slon == field)
			{
				cout << "���� ������ �����, ������� ��������" << endl;
				int checked_x = 0;
				int checked_y = 0;
				int check_y5;
				int check_x5;
				for (int i = 1; i < 9; i++) // ����� ������ ������
				{
					for (int j = 1; j < 9; j++)
					{
						checked_y = i;
						checked_x = j;
						if (abs(x2 - checked_x) == abs(y2 - checked_y) && abs(checked_x - x1) == abs(checked_y - y1)) // �������� ������� �� "���������"
							break;

					}
					if (abs(x2 - checked_x) == abs(y2 - checked_y) && abs(checked_x - x1) == abs(checked_y - y1))
						break;

				}
				int checked_x1 = 0;
				int checked_y1 = 0;
				int check_y6;
				int check_x6;
				// ����� ������ ������
				for (int i = 1; i < 9; i++)// �������� ������� �� "���������" 2�� ������
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
					cout << "����� ��� ������ �): ����� ������� �� ������ � ������� ����";
				else
				{
					cout << "� ������� ���� ������� �� ������ ������, �� ����  \n������ ��� �����: " << "x = " << check_x5 << ", y = " << check_y5;
					if (abs(x2 - checked_x1) == abs(y2 - checked_y1) && abs(checked_x1 - x1) == abs(checked_y1 - y1) && checked_x1 != checked_x && checked_y1 != checked_y)
					{
						std::cout << "\n��� ������ ��� �����: " << "x = " << check_x6 << ", y = " << check_y6;
					}
						else
							cout << " ";
					cout << " - ������� �������� �� 2 ����";

				}
					
				SetColor(15, 0);
				cout << "\n\n";
				
				cout << "���� - 'x' (�������), ������ - 'o'(�����)" << endl;
				cout << "����� ������� ����� ������ ��������� ��������� ����� �� ������ � �������" << endl;
				system("pause");
				cout << "��� � - ������ ����, ��� y - ����� �������";
				cout << "\n";
				if (check_x == check_y)
				{
					cout << "\n������� �� ������ ����� � ������� ����  \n";
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

					cout << "\n---������� �� ������ ����� �� ������� ���� (�������� �������������� ���������)---\n\n";
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
					cout << "\n������ ��� 1 - �� ������\n"; // ����� �������
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
					// �������� ������� �� ���������
					if (!(abs(x2 - checked_x1) == abs(y2 - checked_y1) && abs(checked_x1 - x1) == abs(checked_y1 - y1) && checked_x1 != checked_x && checked_y1 != checked_y))
					{
						cout << endl;
					}
	
					else // ����� �������
					{
						cout << "\n������ ��� 2 - �� ������\n";
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
				cout << "����� ��� ������ �) ���� ������� �����, ������� ����������";
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