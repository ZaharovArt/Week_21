﻿// Week_21_Task_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

char* ReplaceWord(char* text, char* str1, char* str2);

int main()
{
    setlocale(LC_ALL, "ru");
    FILE* file;
    char* buffer = new char [125];
    char* str1 = new char[20];
    char* str2 = new char[20];
    int stroki = 0;

    if ((fopen_s(&file, "text.txt", "r")) != NULL)
        cout << "Не удалось открыть файл!" << endl;
    else {
        cout << "Файл text.txt открыт для чтения." << endl;
        cout << "Содержание файла." << endl;

        while (!feof(file)) {
            fgets(buffer, 250, file);
            cout << buffer;
            stroki++;
        }

        if (!(fclose(file) == 0)) {
            cout << "Файл закрыт с ошибкой!";
        }
        cout << endl;
    }

    cout << "количество строк = " << stroki;

    char** text = new char* [stroki];
   
    cout << endl;
    if ((fopen_s(&file, "text.txt", "r")) != NULL)
        cout << "Не удалось открыть файл!";
    else {
        int i = 0;
        while (!feof(file)) {
            char* buf = new char [250];
            fgets(buf, 250, file);
            text[i] = buf;
            i++;
        }
        cout << endl;
    }

    if (!(fclose(file) == 0)) {
        cout << "Файл закрыт с ошибкой!";
    }

    cout << "Введите слово которое нужно заменить:";
    cin >> str1;
    cout << "Введите слово на которое нужно заменить:";
    cin >> str2;
    cout << endl;

    char** text2 = new char* [stroki];
    for (int i = 0; i < stroki; i++) {
        text2[i] = new char[strlen(ReplaceWord(text[i], str1, str2))];
    }

    for (int i = 0; i < stroki; i++) {
        text2[i] = ReplaceWord(text[i],str1,str2);
    }
   
    cout << "Измененные данные :";
    cout << endl;
    for (int i = 0; i < stroki; i++) {
        cout << text2[i];
    }
    if ((fopen_s(&file, "text.txt", "w")) != NULL)
        cout << "Не удалось открыть файл!";
    else {
        for (int i = 0; i < stroki; i++) {
            fprintf(file, text2[i]);
           
        }
    }

    if (!(fclose(file) == 0)) {
        cout << "Файл закрыт с ошибкой!";
    }
}



char* ReplaceWord(char* text, char* str1, char* str2) {

    char* find_word = strstr(text, str1);
    if (find_word) {
        char* new_text = new char[strlen(text) - strlen(str1) + strlen(str2) + 1];
        int i = 0;
        for (; i < find_word - text; i++) {
            new_text[i] = text[i];
        }
        for (; i < find_word - text + strlen(str2); i++) {
            new_text[i] = str2[i - (find_word - text)];
        }
        for (int j = 0; i < strlen(text) - strlen(str1) + strlen(str2) + 1; i++, j++) {
            new_text[i] = text[(find_word - text + strlen(str1)) + j];
        }
        return new_text;
    }
    else return text;
}
