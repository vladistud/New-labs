#include <iostream>

using namespace std;

const char* getJapaneseEra(int year) {
    if (year >= 1868 && year < 1912) return "Мэйдзи";
    if (year >= 1912 && year < 1926) return "Тайсё";
    if (year >= 1926 && year < 1989) return "Сёва";
    if (year >= 1989 && year < 2019) return "Хэйсэй";
    if (year >= 2019) return "Рэйва";
    return "Неизвестная эпоха";
}

const char* getZodiacSign(int month) {
    switch (month) {
        case 1: return "Козерог / Водолей";
        case 2: return "Водолей / Рыбы";
        case 3: return "Рыбы / Овен";
        case 4: return "Овен / Телец";
        case 5: return "Телец / Близнецы";
        case 6: return "Близнецы / Рак";
        case 7: return "Рак / Лев";
        case 8: return "Лев / Дева";
        case 9: return "Дева / Весы";
        case 10: return "Весы / Скорпион";
        case 11: return "Скорпион / Стрелец";
        case 12: return "Стрелец / Козерог";
        default: return "Неизвестный месяц";
    }
}

int main() {
    int year, month;

    cout << "Введите год: ";
    cin >> year;
    cout << "Название эпохи в Японии: " << getJapaneseEra(year) << endl;

    cout << "Введите номер месяца (1-12): ";
    cin >> month;
    cout << "Знак Зодиака: " << getZodiacSign(month) << endl;

    return 0;
}
