// Week_21_Task-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
   
    setlocale(LC_ALL, "ru");
    FILE* File1;
    FILE* File2;
    char buffer[250];
    int c;
    int str = 0;

    if ((fopen_s(&File1, "File1.txt", "r")) != NULL)
        cout << "Не удалось открыть файл!";
    else {
        cout << "Файл File1.txt открыт для чтения." << endl;;
        while (!feof(File1)) {
            fgets(buffer, 250, File1);
            str++;
        }
    }

    if (fclose(File1) == 0) {
        cout << "Файл File1.txt закрыт." << endl;;
    }
    else {
        cout << "Не удалось закрыть файл File1.txt!" << endl;;
    };

    if ((fopen_s(&File2, "File2.txt", "w")) != NULL) {
        cout << "Не удалось открыть файл - File2.txt для записи !" << endl;
    }
    else if ((fopen_s(&File1, "File1.txt", "r")) != NULL) {
        cout << "Не удалось открыть файл - File1.txt для чтения!"<< endl;
    }
    else {
        cout << "Файл - File1.txt открыт для чтения." << endl;;
        cout << "Файл - File2.txt открыт для записи." <<endl;;
        for (int i = 0; i < str - 1; i++) {
            fgets(buffer, 250, File1);
            fputs(buffer, File2);
        }
    }

    if (fclose(File1) == 0) {
        cout << "File1.txt  закрыт." << endl;;
    }
    else {
        cout << "Не удалось закрыть файл File1.txt!"<<endl;
    };
    if (fclose(File2) == 0) {
        cout << "File2.txt  закрыт." << endl;
    }
    else {
        cout << "Не удалось закрыть файл File2.txt!" << endl;;
    };

}



