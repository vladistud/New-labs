#include <iostream>
#include <fstream>

using namespace std;

// Структура "Покупатель"
struct Buyer {
    char surname[30];
    char name[30];
    char patronymic[30];
    char address[50];
    char phone[20];
    char creditCard[20];
};

// Функция для вывода всех записей из файла
void displayFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    Buyer buyer;
    cout << "\nСодержимое файла:\n";
    while (file.read((char*)&buyer, sizeof(Buyer))) {
        cout << buyer.surname << " " << buyer.name << " " << buyer.patronymic << " | "
             << buyer.address << " | " << buyer.phone << " | " << buyer.creditCard << endl;
    }
    file.close();
}

// Функция для удаления первых 3 элементов
void removeFirstThree(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    // Считаем количество записей
    file.seekg(0, ios::end);
    int count = file.tellg() / sizeof(Buyer);
    if (count <= 3) {
        cout << "В файле менее 4 записей, удаление невозможно!" << endl;
        file.close();
        return;
    }

    file.seekg(3 * sizeof(Buyer), ios::beg); // Пропускаем первые 3 записи

    ofstream tempFile("temp.bin", ios::binary);
    Buyer buyer;

    while (file.read((char*)&buyer, sizeof(Buyer))) {
        tempFile.write((char*)&buyer, sizeof(Buyer));
    }

    file.close();
    tempFile.close();

    remove(filename);
    rename("temp.bin", filename);
}

// Функция для добавления 3 новых записей
void addThreeBuyers(const char* filename) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Buyer newBuyers[3];

    cout << "\nВведите данные для 3 новых покупателей:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Покупатель " << i + 1 << ":\n";
        cout << "Фамилия: ";
        cin >> newBuyers[i].surname;
        cout << "Имя: ";
        cin >> newBuyers[i].name;
        cout << "Отчество: ";
        cin >> newBuyers[i].patronymic;
        cout << "Адрес: ";
        cin.ignore();
        cin.getline(newBuyers[i].address, 50);
        cout << "Телефон: ";
        cin >> newBuyers[i].phone;
        cout << "Кредитная карта: ";
        cin >> newBuyers[i].creditCard;

        file.write((char*)&newBuyers[i], sizeof(Buyer));
    }

    file.close();
}

int main() {
    const char* filename = "buyers.bin";

    cout << "Удаление первых 3 записей...\n";
    removeFirstThree(filename);

    cout << "Добавление 3 новых записей...\n";
    addThreeBuyers(filename);

    displayFile(filename);

    return 0;
}

Код на C++:

#include <iostream>
#include <fstream>

using namespace std;

// Структура "Покупатель"
struct Buyer {
    char surname[30];
    char name[30];
    char patronymic[30];
    char address[50];
    char phone[20];
    char creditCard[20];
};

// Функция для вывода всех записей из файла
void displayFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    Buyer buyer;
    cout << "\nСодержимое файла:\n";
    while (file.read((char*)&buyer, sizeof(Buyer))) {
        cout << buyer.surname << " " << buyer.name << " " << buyer.patronymic << " | "
             << buyer.address << " | " << buyer.phone << " | " << buyer.creditCard << endl;
    }
    file.close();
}

// Функция для удаления первых 3 элементов
void removeFirstThree(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    // Считаем количество записей
    file.seekg(0, ios::end);
    int count = file.tellg() / sizeof(Buyer);
    if (count <= 3) {
        cout << "В файле менее 4 записей, удаление невозможно!" << endl;
        file.close();
        return;
    }

    file.seekg(3 * sizeof(Buyer), ios::beg); // Пропускаем первые 3 записи

    ofstream tempFile("temp.bin", ios::binary);
    Buyer buyer;

    while (file.read((char*)&buyer, sizeof(Buyer))) {
        tempFile.write((char*)&buyer, sizeof(Buyer));
    }

    file.close();
    tempFile.close();

    remove(filename);
    rename("temp.bin", filename);
}

// Функция для добавления 3 новых записей
void addThreeBuyers(const char* filename) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Buyer newBuyers[3];

    cout << "\nВведите данные для 3 новых покупателей:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Покупатель " << i + 1 << ":\n";
        cout << "Фамилия: ";
        cin >> newBuyers[i].surname;
        cout << "Имя: ";
        cin >> newBuyers[i].name;
        cout << "Отчество: ";
        cin >> newBuyers[i].patronymic;
        cout << "Адрес: ";
        cin.ignore();
        cin.getline(newBuyers[i].address, 50);
        cout << "Телефон: ";
        cin >> newBuyers[i].phone;
        cout << "Кредитная карта: ";
        cin >> newBuyers[i].creditCard;

        file.write((char*)&newBuyers[i], sizeof(Buyer));
    }

    file.close();
}

int main() {
    const char* filename = "buyers.bin";

    cout << "Удаление первых 3 записей...\n";
    removeFirstThree(filename);

    cout << "Добавление 3 новых записей...\n";
    addThreeBuyers(filename);

    displayFile(filename);

    return 0;
}


---

Анализ выполнения программы

1. Определение структуры "Покупатель"

Создаётся структура Buyer, содержащая:

Фамилию, имя, отчество (char surname[30], name[30], patronymic[30])

Домашний адрес (char address[50])

Номер телефона (char phone[20])

Номер кредитной карты (char creditCard[20])



2. Вывод содержимого файла

Функция displayFile(filename) открывает файл в бинарном режиме.

Считывает все записи и выводит их на экран.

Если файл отсутствует, выводит сообщение об ошибке.


3. Удаление первых 3 записей

Функция removeFirstThree(filename):

Открывает файл и определяет количество записей.

Если записей менее 4, удаление невозможно.

Читает данные, пропуская первые три записи.

Записывает оставшиеся записи во временный файл temp.bin.

Заменяет старый файл новым.



4. Добавление 3 новых покупателей

Функция addThreeBuyers(filename):

Открывает файл в режиме добавления (ios::app).

Запрашивает данные трёх новых покупателей.

Записывает их в файл.



5. Основной алгоритм в main()

Вызывается removeFirstThree() для удаления первых трёх записей.

Вызывается addThreeBuyers() для добавления новых покупателей.

Вызывается displayFile() для вывода итогового содержимого файла.


6. Завершение работы

После выполнения всех операций программа завершает выполнение.



