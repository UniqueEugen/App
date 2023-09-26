#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
int who;
struct birthdays {
    int date = 0;
    int mounth = 0;
    int year = 0;
};//сnруктура дней рождения
struct positions {
    string name_of_position = "0";
    int id_of_position = 0;
    float koef = 0;
};//структура должностей
struct ids {
    int number;
    int hours;
    int age;
};//структура таб.номера и отр. часов
struct logins {
    string login;
    string password;
    int type = 9;
    bool blocked = true;
}; //структура логинов
struct employee
{
    string surname;
    struct logins login;
    string name;
    string second_name;
    struct birthdays birthday;
    struct positions position;
    struct ids id;

};
// структура сотрудников

vector <employee> empV;
struct employee emp;
int counter = 0;
int kk = 0;
bool flag = false;
void inFile()
{


    ofstream login;
    login.open("logins.txt", ofstream::out);
    if (!login.is_open())
    {
        cout << "Ошибка" << endl;
    }
    else
    {
        for (int i = 0; i < counter; i++)
        {
            login << empV[i].name << "\n";
            login << empV[i].surname << "\n";
            login << empV[i].second_name << "\n";
            login << empV[i].id.age << "\n";
            login << empV[i].id.hours << "\n";
            login << empV[i].id.number << "\n";
            login << empV[i].birthday.date << "\n";
            login << empV[i].birthday.mounth << "\n";
            login << empV[i].birthday.year << "\n";
            login << empV[i].position.id_of_position << "\n";
            login << empV[i].position.koef << "\n";
            login << empV[i].position.name_of_position << "\n";
            login << empV[i].login.login << "\n";
            login << empV[i].login.password << "\n";
            login << empV[i].login.type << "\n";
            login << empV[i].login.blocked << "\n";

        }
    }
    login.close();
}
bool outFile()
{
    bool i = true;
    ifstream login;

    string k;
    getline(login, k);
    getline(login, emp.name);
    getline(login, emp.surname);
    getline(login, emp.second_name);
    login >> emp.id.age;
    login >> emp.id.hours;
    login >> emp.id.number;
    login >> emp.birthday.date;
    login >> emp.birthday.mounth;
    login >> emp.birthday.year;
    login >> emp.position.id_of_position;
    login >> emp.position.koef;
    getline(login, emp.position.name_of_position);
    getline(login, emp.login.login);
    getline(login, emp.login.password);
    login >> emp.login.type;
    login >> emp.login.blocked;
    login >> emp.login.blocked;
    if (login.eof())  i=false;
    return (i);
}
void inVector()
{
    ifstream login;
    login.open("logins.txt");
    if (!(login.is_open()))
    {
        // вызов метода is_open()
        cout << "Файл не открыт!\n\n" << endl;
    }
    else
    {
        while (1)
        {
            getline(login, emp.name);
            getline(login, emp.surname);
            getline(login, emp.second_name);
            login >> emp.id.age;
            login >> emp.id.hours;
            login >> emp.id.number;
            login >> emp.birthday.date;
            login >> emp.birthday.mounth;
            login >> emp.birthday.year;
            login >> emp.position.id_of_position;
            login >> emp.position.koef;
            getline(login, emp.position.name_of_position);
            getline(login, emp.position.name_of_position);
            getline(login, emp.login.login);
            getline(login, emp.login.password);
            login >> emp.login.type;
            login >> emp.login.blocked;

            if (login.eof())  break;
            empV.push_back(emp);
            counter++;
        }

        login.close();
    }
}
int moduleInLog()
{

    int i;
    bool logs = true;

    cout << "\a\t\t\t\tЗдаров будь Посетитель! Кем являешся ты?" << endl;
    cout << "\t\t\t\t1.Я администратор!\n\t\t\t\t2.Я рядовой сотрудник!\n\t\t\t\t3.Да никто я, извините!" << endl;
    cin >> i;
    system("cls");
    int kout = 0;
    while (kout != 3) {
        if (i == 1 or i == 2)
        {

            //logs = inLog();
            if (logs == false) {
                system("cls");
                cout << "Неверный логин или пароль" << endl;
                kout++;
                if (kout == 3) {

                }
                else {
                    cout << "Осталось попыток:" << (3 - kout) << endl;
                }
            }
            else {
                kout = 3;
            }
        }

        else
        {
            if (i == 3) {
                inFile();
                return(0);
            }
            else
            {
                cout << "\t\t\t\tЧто-то неверное ввел ты! Попробуй еще!\n\n" << endl;
            }

        }
    }
    if (logs == true)
    {
        i = 1;
    }
    else {
        i = 2;
    }
    return(i);
}
void File_not_inicialized()
{
    cout << "Файл не содержит данных" << endl;
    emp.name = "Name";
    emp.surname = "Surname";
    emp.second_name = "SecName";
    emp.login.blocked = true;
    emp.login.login = "login";
    emp.login.password = "password";
    emp.login.type = 1;
    emp.birthday.date = 0;
    emp.birthday.mounth = 0;
    emp.birthday.year = 0;
    emp.id.age = 0;
    emp.id.number = 0;
    emp.id.hours = 0;
    emp.position.id_of_position = 0;
    emp.position.koef = 0;
    emp.position.name_of_position = "0";
    ofstream login;
    login.open("logins.txt", ofstream::out);
    if (!login.is_open())
    {
        cout << "Ошибка" << endl;
    }
    else
    {
        login << emp.name << "\n";
        login << emp.surname << "\n";
        login << emp.second_name << "\n";
        login << emp.id.age << "\n";
        login << emp.id.hours << "\n";
        login << emp.id.number << "\n";
        login << emp.birthday.date << "\n";
        login << emp.birthday.mounth << "\n";
        login << emp.birthday.year << "\n";
        login << emp.position.id_of_position << "\n";
        login << emp.position.koef << "\n";
        login << emp.position.name_of_position << "\n";
        login << emp.login.login << "\n";
        login << emp.login.password << "\n";
        login << emp.login.type << "\n";
        login << emp.login.blocked << "\n";
    }
    login.close();
}
int ReallyGoodFile(){
    int Y = 0;
    char b;
    fstream login;
    login.open("logins.txt");
    while (!login.eof()) {
        login.read(&b, 1);
        Y++;
        if (Y == 2) break;
    }
    login.close();
    return (Y);
}

void checkFile()
{
    fstream login;
    login.open("logins.txt", fstream::app);
    if (!login.is_open())
    {
        cout << "Ошибка с файлом" << endl;
    }

    login.close();
    int Y = ReallyGoodFile();
    if (Y <= 1)
    {
        File_not_inicialized();
    }
}
void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int empAmount = 0;
    int YesOrNot = 0;
    int i = 0;
    bool ttry, logs = false;
    bool metka = true;
    setlocale(LC_ALL, "Russian");
    checkFile();
    inVector();
    while (1)
    {
        i = moduleInLog();
        if (i == 1)
        {
           // logs = true;
        }
        else {
            if (i == 0) {
                break;
            }
            else
            {
               // logs = false;
            }

        }
        system("cls");
        //if (logs != false)
        {
            //if (who == 1)
            {
                //metka = admin();
            }
            //else
            {
                //metka = user();
            }
        }
    };
}


