#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція, яка перевіряє наявність пар "no" або "on"
bool CheckPair(const char* str) {
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
            return true; // Знайдена пара "no" або "on"
        }
    }
    return false; // Пара не знайдена
}

// Функція, яка замінює кожну пару "no" на "***"
char* ReplaceNoWithStars(const char* str) {
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1]; // Виділяємо достатньо місця для результату
    char* t = tmp;
    tmp[0] = '\0';

    for (size_t i = 0; i < len; i++) {
        if (str[i] == 'n' && str[i + 1] == 'o') {
            strcat(t, "***");
            t += 3;
            i++; // Пропускаємо наступний символ, оскільки вже обробили пару "no"
        }
        else {
            *t++ = str[i];
            *t = '\0';
        }
    }

    return tmp; // Повертаємо змінений рядок без змін у вихідному
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Викликаємо функцію перевірки наявності пар
    bool hasPair = CheckPair(str);
    cout << "String contains pairs 'no' or 'on': " << (hasPair ? "Yes" : "No") << endl;

    // Викликаємо функцію заміни пар "no"
    char* modifiedStr = ReplaceNoWithStars(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; // Звільняємо пам'ять
    return 0;
}
