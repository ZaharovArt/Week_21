// Week_21_Task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дан текстовый файл. Посчитать сколько раз в нем встречается заданное пользователем слово.

#include <iostream>
#include <string>
using namespace std;
int howManyWords(char* text, char* word);
int main()
{
    setlocale(LC_ALL, "ru");

    system("chcp 1251>nul");

    FILE* file;
    char* buffer = new char[250];
    char* word = new char[20];
    int i = 0;

    if ((fopen_s(&file, "text.txt", "r")) != NULL)
        cout << "Не удалось открыть файл!";
    else {
        cout << "Файл text.txt открыт для чтения." << endl;


        while (!feof(file)) {
            fgets(buffer, 250, file);
            cout << buffer;
        }
    }

    cout << endl;
    if ((fopen_s(&file, "text.txt", "r")) != NULL)
        cout << "Не удалось открыть файл!";
    else {
        cout << "Файл text.txt открыт для чтения." << endl;

        cout << endl;
        cout << "Введите слово:";
        cin >> word;


        while (!feof(file)) {
            fgets(buffer, 250, file);
            i += howManyWords(buffer, word);
        }
    }
    cout << "Введенное слово встречается " << i << " раз"<<endl;

    if (fclose(file) == 0) {
        cout << "Файл text.txt  закрыт." << endl;;
    }
    else {
        cout << "Не удалось закрыть файл text.txt!" << endl;
    };
}
    int howManyWords(char* string, char* word) {

        if (strstr(string, word)) {
            return 1 + howManyWords(strstr(string, word) + strlen(word), word);
        }
        else return 0;

    }


    


    

    
