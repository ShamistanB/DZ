#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <deque> 

using namespace std;


void PrintVector(vector<int>& arr) {

	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)

		cout << *it << " ";

	cout << "\n";
}

int main() {

	setlocale(LC_ALL, "RUS");

	vector<int> l1 = { 2,6,8,9,2,4,5,6,9,10,12 };  // заполняем вектор

	cout << "Вывод 1 последовательности :" << endl;

	for (vector<int>::iterator i = l1.begin(); i != l1.end(); i++) {  // вывод вектора на экран

		cout << *i << " ";
	}

	cout << endl;

	list<int> l2 = { 4,2,8,4 };     // заполняем список

	cout << "Вывод 2 последовательности :" << endl;

	for (list<int>::iterator i = l2.begin(); i != l2.end(); i++) {  // вывод вектора на экран

		cout << *i << " ";

	}

	l1.erase(remove_if(l1.begin(), l1.end(), [l2](auto it) {

		return !bool(find(l2.begin(), l2.end(), it) == l2.end());

		}),l1.end());

	cout << endl;

	cout << "Полученная новая 1 послдеовательность : ";

	PrintVector(l1); // печатаем полученный вектор 

	int X; // дл кратности

	cout << "Введите Х : ";

	cin >> X;

	int x = 1; // новый элемент 

	cout << "Полученная новая 2 последоватлеьность :" << endl;

	for (list<int>::iterator i = l2.begin(); i != l2.end(); i++) {

		if (*i % X == 0)      // если кратна Х , то вставляем х

		l2.insert(i, x);	
	}

	for (list<int>::iterator i = l2.begin(); i != l2.end(); i++) {  // вывод вектора на экран

		cout << *i << " ";

	}

	cout << endl;

	cout << "Последовательности отсортированные и добавленные в одну последовательность : " << endl;

	unique_copy(begin(l1), end(l1), back_inserter(l2));    // передаём все элементы первого вектора в список

	l2.sort();  // сортируем

	for (list<int>::iterator i = l2.begin(); i != l2.end(); i++) {  // вывод вектора на экран

		cout << *i << " ";

	}
	
	cin.get();
	cin.get();
	return 0;
}