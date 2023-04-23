// Week_21_Task_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "ru");
    FILE* file;
    char buffer[250];
    int max_str=0;
    int str_len = 0;
    if (fopen_s(&file,"text.txt", "r") != 0) {
        cout << "Не удалось открыть файл text.txt"<<endl;
    }
    else {
        cout << "Файл text.txt открыт для чтения." << endl;

        while (!feof(file)) {
            fgets(buffer, 250, file);
            str_len = strlen(buffer);
            if (str_len > max_str) {
                max_str = str_len;
            }
            if (buffer[str_len - 1] == '\n') {
                buffer[str_len - 1] = '\0';

            }
            cout << buffer << " - " << str_len-1 << " симв." << endl;
        }
        cout << " длинна самой длинной строки - " << max_str-1 << " симв." << endl;
    }

    if (fclose(file) == 0) {
        cout << " Файл text.txt закрыт."<<endl;
    }
    else {
        cout << " Не удалось закрыть файл text.txt"<<endl;
    }

    return 0;
}

