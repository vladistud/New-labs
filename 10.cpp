#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Функция для проверки, содержит ли строка цифры
bool containsDigit(const char* str) {
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            return true;
        }
        str++;
    }
    return false;
}

// Функция для копирования строк без цифр из F1 в F2
void copyLinesWithoutDigits(const char* f1, const char* f2) {
    ifstream file1(f1);
    ofstream file2(f2);

    if (!file1 || !file2) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    char line[256];
    
    while (file1.getline(line, 256)) {
        if (!containsDigit(line)) {
            file2 << line << endl;
        }
    }

    file1.close();
    file2.close();
}

// Функция для подсчёта строк, начинающихся с 'А'
int countLinesStartingWithA(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return 0;
    }

    char line[256];
    int count = 0;

    while (file.getline(line, 256)) {
        if (line[0] == 'А' || line[0] == 'A') {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    const char* f1 = "F1.txt";
    const char* f2 = "F2.txt";

    cout << "Копирование строк без цифр из F1 в F2...\n";
    copyLinesWithoutDigits(f1, f2);

    int count = countLinesStartingWithA(f2);
    cout << "Количество строк, начинающихся на 'А' в F2: " << count << endl;

    return 0;
}


Код на C++:

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Функция для проверки, содержит ли строка цифры
bool containsDigit(const char* str) {
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            return true;
        }
        str++;
    }
    return false;
}

// Функция для копирования строк без цифр из F1 в F2
void copyLinesWithoutDigits(const char* f1, const char* f2) {
    ifstream file1(f1);
    ofstream file2(f2);

    if (!file1 || !file2) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    char line[256];
    
    while (file1.getline(line, 256)) {
        if (!containsDigit(line)) {
            file2 << line << endl;
        }
    }

    file1.close();
    file2.close();
}

// Функция для подсчёта строк, начинающихся с 'А'
int countLinesStartingWithA(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return 0;
    }

    char line[256];
    int count = 0;

    while (file.getline(line, 256)) {
        if (line[0] == 'А' || line[0] == 'A') {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    const char* f1 = "F1.txt";
    const char* f2 = "F2.txt";

    cout << "Копирование строк без цифр из F1 в F2...\n";
    copyLinesWithoutDigits(f1, f2);

    int count = countLinesStartingWithA(f2);
    cout << "Количество строк, начинающихся на 'А' в F2: " << count << endl;

    return 0;
}


---

Анализ выполнения программы

1. Проверка наличия цифр в строке

Функция containsDigit(const char* str):

Проходит по символам строки.

Если встречает цифру ('0' – '9'), возвращает true.

Если цифр нет, возвращает false.



2. Копирование строк без цифр в F2

Функция copyLinesWithoutDigits(f1, f2):

Открывает файлы F1 и F2.

Читает F1 построчно.

Если строка не содержит цифр (через containsDigit()), записывает её в F2.

Закрывает оба файла.



3. Подсчёт строк, начинающихся с 'А'

Функция countLinesStartingWithA(filename):

Открывает файл F2.

Читает его построчно.

Проверяет первый символ строки:

Если это 'А' (русская) или 'A' (английская), увеличивает счётчик.


Закрывает файл.

Возвращает количество таких строк.



4. Основной алгоритм в main()

Вызывает copyLinesWithoutDigits(f1, f2) для копирования строк без цифр.

Вызывает countLinesStartingWithA(f2) и выводит количество строк, начинающихся на 'А'.

Завершает работу.



