#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // Для функции rand()
using namespace std;

const int M = 10;
const int R = 3;  // Коэффициент для разрешения коллизий

struct Car {
    string brand;
    int maxSpeed;
    int year;
};

int hashFunction(int key) {
    return key % M;
}

int resolveCollision(int index, int attempt) {
    return (index + R * attempt) % M;
}

void insert(vector<Car>& hashtable, const Car& car) {
    int key = car.year;
    int index = hashFunction(key);

    // Поиск незанятой позиции с помощью разрешения коллизий
    int attempt = 0;
    while (!hashtable[index].brand.empty()) {
        index = resolveCollision(index, attempt);
        attempt++;
    }

    hashtable[index] = car;
}

Car search(const vector<Car>& hashtable, int key) {
    int index = hashFunction(key);
    return hashtable[index];
}

int main() {
    setlocale(0, "RU");
    const int n = 8;
    std::vector<Car> cars(n);

    // Ввод элементов массива структур
    for (int i = 0; i < n; i++) {
        cout << "Введите марку автомобиля " << i + 1 << ": ";
        cin >> cars[i].brand;
        cout << "Введите максимальную скорость " << i + 1 << ": ";
        cin >> cars[i].maxSpeed;
        cout << "Введите год выпуска " << i + 1 << ": ";
        cin >> cars[i].year;
    }

    // Создание хеш-таблицы
    vector<Car> hashtable(M);

    // Вставка элементов в хеш-таблицу
    for (const Car& car : cars) {
        insert(hashtable, car);
    }

    // Вывод исходного массива
    cout << "Исходный массив структур:\n";
    for (int i = 0; i < n; i++) {
        cout << "Марка автомобиля " << i + 1 << ": " << cars[i].brand << endl;
        cout << "Максимальная скорость " << i + 1 << ": " << cars[i].maxSpeed << endl;
        cout << "Год выпуска " << i + 1 << ": " << cars[i].year << endl;
        cout << "-------------------------\n";
    }

    // Ввод ключа для поиска в хеш-таблице
    int searchKey;
    cout << "Введите ключ (год выпуска) для поиска в хеш-таблице: ";
    cin >> searchKey;

    // Поиск элемента в хеш-таблице
    Car foundCar = search(hashtable, searchKey);

    // Вывод найденной структуры
    cout << "Найденная структура:\n";
    cout << "Марка автомобиля: " << foundCar.brand << endl;
    cout << "Максимальная скорость: " << foundCar.maxSpeed << endl;
    cout << "Год выпуска: " << foundCar.year << endl;

    return 0;
}
