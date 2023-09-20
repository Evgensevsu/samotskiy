#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct GameResult {
    int number;
    int attempts;
    time_t timestamp;
};

void printResults(const vector<GameResult>& results) {
    cout << "История игр:" << endl;
    for (const auto& result : results) {
        cout << "Число: " << result.number << ", попыток: " << result.attempts << ", дата: " << ctime(&result.timestamp);
    }
}

int main()
{
    srand(time(0)); // инициализация генератора случайных чисел

    char answer;
    vector<GameResult> results;

    do {
        int min, max;
        cout << "Введите диапазон чисел, из которых я буду загадывать число (минимум и максимум через пробел): ";
        cin >> min >> max;

        int number = rand() % (max - min + 1) + min; // генерация числа в диапазоне от min до max
        int attempts = 0;

        cout << "Загадано число от " << min << " до " << max << ". Попробуйте угадать его." << endl;

        do {
            int guess;
            cout << "Введите ваше предположение: ";
            cin >> guess;
            attempts++;
            if (guess < number) {
                cout << "Мое число больше." << endl;
            } else if (guess > number) {
                cout << "Мое число меньше." << endl;
            }
        } while (number != guess);

        cout << "Вы угадали число " << number << " за " << attempts << " попыток." << endl;
        results.push_back({number, attempts, time(0)});

        cout << "Хотите сыграть еще раз? (y/n) ";
        cin >> answer;
    } while (answer == 'y');

    printResults(results);

    cout << "Спасибо за игру!" << endl;

    return 0;
}