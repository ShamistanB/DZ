#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque> // подключение библиотеки дека

using namespace std;

// ДЛЯ ПРОВЕРКИ - 3 10 9 13 6 13 9 10 15 13

int main() {

	setlocale(LC_ALL, "RUS");

	int n; // количество элементов в векторе

	cout << "Введите количество элементов в векторе - ";

	cin >> n;

	int x; //вспомогательная для вектора

	cout << "Введите Х - ";

	int X; // кратность
	
	cin >> X;
	
	deque<int> vec; //объявление вектора 

	cout << "Введите элементы вектора - ";

	for (int i = 0; i < n; i++) { //заполнение вектора 

		cin >> x;

		vec.push_back(x);

	}
	
	for (int i = 0; i < vec.size(); i++) { //удаление элемнтов кратных Х в векторе 

		if (vec[i] % X == 0) {

			vec.erase(vec.begin() + i);
		}
	}
	
	cout << endl;

	cout << "Удалены все элементы кратные Х : ";

	for (deque<int>::iterator i = vec.begin(); i != vec.end(); i++) { // вывод новых элементов в векторе

		cout << *i << " ";
	}
	
	cout << endl << endl;;

	int c = 5;

	for (int i = 0; i < vec.size(); i++) { //вставляем новый элемент после после каждого максимального элемента

		if (vec[i] == *max_element(vec.begin(), vec.end())) {

			vec.insert(vec.begin() + i + 1, c);
		}

	}

	cout << "Вставляем новый элемент после после каждого максимального элемента : ";

	for (deque<int>::iterator i = vec.begin(); i != vec.end(); i++) { // вывод новых элементов в векторе

		cout << *i << " ";
	}

	cout << endl << endl;

	cout << "Все нечетные элементы заменяем на минимальный : ";

	for (int i = 0; i < vec.size(); i++) { //нечётные элементы заменяем на минимальные

		if (vec[i] % 2 != 0) {

			vec[i] = *min_element(vec.begin(), vec.end());

		}

	}

	for (deque<int>::iterator i = vec.begin(); i != vec.end(); i++) { // вывод новых элементов в векторе

		cout << *i << " ";
	}

	cout << endl;

	cin.get();
	cin.get();
	return 0;
}