#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // инициализация генератора случайных чисел

    char answer;
    do {
        int min = 1;
        int max = 1000;
        int guess;
        int attempts = 0;

        cout << "Загадайте число от 1 до 1000, а я попробую его угадать." << endl;

        do {
            guess = rand() % (max - min + 1) + min; // генерация числа в диапазоне от min до max
            cout << "Это число " << guess << "? (y/n) ";
            cin >> answer;
            attempts++;
            if (answer == 'n') {
                cout << "Мое число больше или меньше загаданного?" << endl;
                cout << "Введите 'b' если ваше число больше, 'l' если меньше: ";
                cin >> answer;
                if (answer == 'b') {
                    min = guess + 1;
                } else if (answer == 'l') {
                    max = guess - 1;
                } else {
                    cout << "Некорректный ответ. Попробуйте еще раз." << endl;
                    attempts--;
                }
            } else if (answer != 'y') {
                cout << "Некорректный ответ. Попробуйте еще раз." << endl;
                attempts--;
            }
        } while (answer != 'y');

        cout << "Я угадал число " << guess << " за " << attempts << " попыток." << endl;
        cout << "Хотите сыграть еще раз? (y/n) ";
        cin >> answer;
    } while (answer == 'y');

    cout << "Спасибо за игру!" << endl;

    return 0;
}