#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	setlocale(LC_ALL, "RUS");

	vector<int> vec = { 10,2,3,10,4,5,10,5,6,10,1,6,7,10 }; // создание и заполнение вектора 

	for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {

		cout << *i << " ";

	}

	cout << endl;

	int Max = *max_element(vec.begin(), vec.end()); // для нахождения максимального элемента в векторе 

	int k = count(vec.begin(), vec.end(), Max);   // для нахождения количества максимальных элементов в векторе 


	cout << "Максимальный элемент - " << Max << endl;

	cout << "Количество максимальных элементов - " << k << endl;

	cin.get();
	cin.get();
	return 0;
}