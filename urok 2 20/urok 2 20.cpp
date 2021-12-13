#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <time.h>
#include <stdio.h>
using namespace std;
struct date
{
	int day:7;
	int month:6;                     // раскоментить для установления размеров для числовый значений
	int year:12;
};
struct Person
{
	char Neme[25];
	char Surneme[50];
	char Otchestvo[50];
	date myBirthday;
};
int Proverkaday(int day, int mounth, int yers)
{
	int r;
	bool t;
	while (1)
	{
		if (yers % 4 != 0 || yers % 100 == 0)
		{
			t = false;
		}
		else
		{
			t = true;
		}
		switch (mounth)
		{

		case 1:
		{
			r = 31;
			break;
		}
		case 2:
		{
			if (t == true)
			{
				r = 29;
			}
			else
			{
				r = 28;
			}
			break;
		}
		case 3:
		{
			r = 31;
			break;
		}
		case 4:
		{
			r = 30;
			break;
		}
		case 5:
		{
			r = 31;
			break;
		}
		case 6:
		{
			r = 30;
			break;
		}
		case 7:
		{
			r = 31;
			break;
		}
		case 8:
		{
			r = 31;
			break;
		}
		case 9:
		{
			r = 30;
			break;
		}
		case 10:
		{
			r = 31;
			break;
		}
		case 11:
		{
			r = 30;
			break;
		}
		case 12:
		{
			r = 31;
			break;
		}
		default:
		{
			break;

		}
		}
		if ((mounth <= 12 && mounth > 0) && (day <= r && day > 0))
		{
			break;
		}
		else
		{
			cout << "Вы ввели неверные значения дня,месяца или года.\n";
			cout << "Введите день " << "\n";
			cin >> day;
			cout << "Введите месяц " << "\n";
			cin >> mounth;
			cout << "Введите год " << "\n";
			cin >> yers;
		}
	}
	return day, mounth, yers;
}
int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "Rus");
	date myBirthday;
	const int n = 2;                                                          // берем 10 , хотя можно и другое число
	int day;
	int mounth;
	int yers;
	cout << "Введите день сегодняшний выборов " << "\n";
	cin >> day;
	cout << "Введите месяц сегодняшний выборов " << "\n";
	cin >> mounth;
	cout << "Введите год сегодняшний выборов " << "\n";
	cin >> yers;
	Proverkaday(day, mounth, yers);
	Person spisok[n];
	int y;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cout << "Введите своё имя " << "\n";
			cin >> spisok[i].Neme;
			cout << "Введите свою фамилию " << "\n";
			cin >> spisok[i].Surneme;
			cout << "Введите своё отчество " << "\n";
			cin >> spisok[i].Otchestvo;
			cout << "Введите день своего рождения " << "\n";
			cin >> y;
			spisok[i].myBirthday.day=y;
			cout << "Введите месяц своего рождения " << "\n";
			cin >> y;
			spisok[i].myBirthday.month = y;
			cout << "Введите год своего рождения " << "\n";
			cin >> y;
			spisok[i].myBirthday.year = y;
			Proverkaday(spisok[i].myBirthday.day, spisok[i].myBirthday.month, spisok[i].myBirthday.year);
			while (1)
			{

				if (spisok[i].myBirthday.year < yers && spisok[i].myBirthday.year > 0)
				{
					break;

				}
				else
				{
					if (spisok[i].myBirthday.year == yers)
					{
						if (spisok[i].myBirthday.month < mounth)
						{
							break;
						}
						else
						{
							if (spisok[i].myBirthday.month == mounth)
							{
								if (spisok[i].myBirthday.day < day)
								{
									break;
								}
							}
						}
					}

				}
				cout << "Вы ввели неправельные данные о своем рождении.\n";
				cout << "Введите день своего рождения " << "\n";
				cin >> y;
				spisok[i].myBirthday.day = y;
				cout << "Введите месяц своего рождения " << "\n";
				cin >> y;
				spisok[i].myBirthday.month = y;
				cout << "Введите год своего рождения " << "\n";
				cin >> y;
				spisok[i].myBirthday.year = y;
				Proverkaday(spisok[i].myBirthday.day, spisok[i].myBirthday.month, spisok[i].myBirthday.year);
			}
			Proverkaday(spisok[i].myBirthday.day, spisok[i].myBirthday.month, spisok[i].myBirthday.year);
			if (yers - spisok[i].myBirthday.year > 18)
			{
				cout << "Вы успешно прошли регестрацию " << "\n";
				break;
			}
			else
			{
				if (yers - spisok[i].myBirthday.year == 18)
				{
					if (spisok[i].myBirthday.month < mounth)
					{
						cout << "Вы успешно прошли регестрацию " << "\n";
						break;
					}
					else
					{
						if (spisok[i].myBirthday.month == mounth)
						{
							if (spisok[i].myBirthday.day <= day)
							{
								cout << "Вы успешно прошли регестрацию " << "\n";
								break;
							}
							else
							{
								cout << "Вы являетесь несовершеннолетним и пока не можете принимать участие в выборах!!!Уступите место следующему избирателю." << "\n";
							}
						}
						else
						{
							cout << "Вы являетесь несовершеннолетним и пока не можете принимать участие в выборах!!!Уступите место следующему избирателю." << "\n";
						}
					}
				}
				else
				{
					cout << "Вы являетесь несовершеннолетним и пока не можете принимать участие в выборах!!!Уступите место следующему избирателю." << "\n";
				}
			}
		}
	}
	char* c3 = new char[50];
	int c2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < strlen(spisok[i].Surneme); j++)
		{
			if ((static_cast<int>(spisok[i].Surneme[j]) >= 65 && static_cast<int>(spisok[i].Surneme[j]) <= 90) && (static_cast<int>(spisok[i + 1].Surneme[j]) >= 65 && static_cast<int>(spisok[i + 1].Surneme[j]) <= 90))
			{

				if (static_cast<int>(spisok[i].Surneme[j]) < static_cast<int>(spisok[i + 1].Surneme[j]))
				{
					break;
				}
				if (static_cast<int>(spisok[i].Surneme[j]) > static_cast<int>(spisok[i + 1].Surneme[j]))
				{
					strcpy(c3, spisok[i].Surneme);
					strcpy(spisok[i].Surneme, spisok[i + 1].Surneme);
					strcpy(spisok[i + 1].Surneme, c3);

					strcpy(c3, spisok[i].Neme);
					strcpy(spisok[i].Neme, spisok[i + 1].Neme);
					strcpy(spisok[i + 1].Neme, c3);

					strcpy(c3, spisok[i].Otchestvo);
					strcpy(spisok[i].Otchestvo, spisok[i + 1].Otchestvo);
					strcpy(spisok[i + 1].Otchestvo, c3);

					c2 = spisok[i].myBirthday.day;
					spisok[i].myBirthday.day = spisok[i + 1].myBirthday.day;
					spisok[i + 1].myBirthday.day = c2;

					c2 = spisok[i].myBirthday.month;
					spisok[i].myBirthday.month = spisok[i + 1].myBirthday.month;
					spisok[i + 1].myBirthday.month = c2;

					c2 = spisok[i].myBirthday.year;
					spisok[i].myBirthday.year = spisok[i + 1].myBirthday.year;
					spisok[i + 1].myBirthday.year = c2;

					i = -1;
				}
			}
			if ((static_cast<int>(spisok[i].Surneme[j]) >= 65 && static_cast<int>(spisok[i].Surneme[j]) <= 90) && (static_cast<int>(spisok[i + 1].Surneme[j]) >= 97 && static_cast<int>(spisok[i + 1].Surneme[j]) <= 122))
			{

				if (static_cast<int>(spisok[i + 1].Surneme[j]) - static_cast<int>(spisok[i].Surneme[j]) > 32)
				{
					break;
				}
				if (static_cast<int>(spisok[i + 1].Surneme[j]) - static_cast<int>(spisok[i].Surneme[j]) < 32)
				{
					strcpy(c3, spisok[i].Surneme);
					strcpy(spisok[i].Surneme, spisok[i + 1].Surneme);
					strcpy(spisok[i + 1].Surneme, c3);

					strcpy(c3, spisok[i].Neme);
					strcpy(spisok[i].Neme, spisok[i + 1].Neme);
					strcpy(spisok[i + 1].Neme, c3);

					strcpy(c3, spisok[i].Otchestvo);
					strcpy(spisok[i].Otchestvo, spisok[i + 1].Otchestvo);
					strcpy(spisok[i + 1].Otchestvo, c3);

					c2 = spisok[i].myBirthday.day;
					spisok[i].myBirthday.day = spisok[i + 1].myBirthday.day;
					spisok[i + 1].myBirthday.day = c2;

					c2 = spisok[i].myBirthday.month;
					spisok[i].myBirthday.month = spisok[i + 1].myBirthday.month;
					spisok[i + 1].myBirthday.month = c2;

					c2 = spisok[i].myBirthday.year;
					spisok[i].myBirthday.year = spisok[i + 1].myBirthday.year;
					spisok[i + 1].myBirthday.year = c2;

					i = -1;
				}
			}
			if ((static_cast<int>(spisok[i].Surneme[j]) >= 97 && static_cast<int>(spisok[i].Surneme[j]) <= 122) && (static_cast<int>(spisok[i + 1].Surneme[j]) >= 65 && static_cast<int>(spisok[i + 1].Surneme[j]) <= 90))
			{

				if (static_cast<int>(spisok[i + 1].Surneme[j]) - static_cast<int>(spisok[i].Surneme[j]) > -32)
				{
					break;
				}
				if (static_cast<int>(spisok[i + 1].Surneme[j]) - static_cast<int>(spisok[i].Surneme[j]) < -32)
				{
					strcpy(c3, spisok[i].Surneme);
					strcpy(spisok[i].Surneme, spisok[i + 1].Surneme);
					strcpy(spisok[i + 1].Surneme, c3);

					strcpy(c3, spisok[i].Neme);
					strcpy(spisok[i].Neme, spisok[i + 1].Neme);
					strcpy(spisok[i + 1].Neme, c3);

					strcpy(c3, spisok[i].Otchestvo);
					strcpy(spisok[i].Otchestvo, spisok[i + 1].Otchestvo);
					strcpy(spisok[i + 1].Otchestvo, c3);

					c2 = spisok[i].myBirthday.day;
					spisok[i].myBirthday.day = spisok[i + 1].myBirthday.day;
					spisok[i + 1].myBirthday.day = c2;

					c2 = spisok[i].myBirthday.month;
					spisok[i].myBirthday.month = spisok[i + 1].myBirthday.month;
					spisok[i + 1].myBirthday.month = c2;

					c2 = spisok[i].myBirthday.year;
					spisok[i].myBirthday.year = spisok[i + 1].myBirthday.year;
					spisok[i + 1].myBirthday.year = c2;

					i = -1;
				}
			}
			if ((static_cast<int>(spisok[i].Surneme[j]) >= 97 && static_cast<int>(spisok[i].Surneme[j]) <= 122) && (static_cast<int>(spisok[i + 1].Surneme[j]) >= 97 && static_cast<int>(spisok[i + 1].Surneme[j]) <= 122))
			{

				if (static_cast<int>(spisok[i].Surneme[j]) < static_cast<int>(spisok[i + 1].Surneme[j]))
				{
					break;
				}
				if (static_cast<int>(spisok[i].Surneme[j]) > static_cast<int>(spisok[i + 1].Surneme[j]))
				{
					strcpy(c3, spisok[i].Surneme);
					strcpy(spisok[i].Surneme, spisok[i + 1].Surneme);
					strcpy(spisok[i + 1].Surneme, c3);

					strcpy(c3, spisok[i].Neme);
					strcpy(spisok[i].Neme, spisok[i + 1].Neme);
					strcpy(spisok[i + 1].Neme, c3);

					strcpy(c3, spisok[i].Otchestvo);
					strcpy(spisok[i].Otchestvo, spisok[i + 1].Otchestvo);
					strcpy(spisok[i + 1].Otchestvo, c3);

					c2 = spisok[i].myBirthday.day;
					spisok[i].myBirthday.day = spisok[i + 1].myBirthday.day;
					spisok[i + 1].myBirthday.day = c2;

					c2 = spisok[i].myBirthday.month;
					spisok[i].myBirthday.month = spisok[i + 1].myBirthday.month;
					spisok[i + 1].myBirthday.month = c2;

					c2 = spisok[i].myBirthday.year;
					spisok[i].myBirthday.year = spisok[i + 1].myBirthday.year;
					spisok[i + 1].myBirthday.year = c2;

					i = -1;
				}


			}

		}
	}
	/*system("cls");*/                      // если нужно очистить консоль раскоментить
	for (int i = 0; i < n; i++)
	{
		cout << "Избиратель №" << i + 1 << "\n";
		cout << spisok[i].Neme << " ";
		cout << spisok[i].Surneme << " ";
		cout << spisok[i].Otchestvo << "\n";
		cout << spisok[i].myBirthday.day << ".";
		cout << spisok[i].myBirthday.month << ".";
		cout << spisok[i].myBirthday.year << "\n";
	}

	return 0;
}