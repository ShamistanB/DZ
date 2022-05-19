#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <set>
#include <deque> 
#include <numeric>

using namespace std;


// ДЛЯ ПРОВЕРКИ 1 15 125 33 28 1473 156 145


set <int> set_n(int n) {
	
	set <int> S;    // создаём множество

	if (n != 0) {  // пока n не равно 0 , выполняем следующее условие
		
		S.insert(n % 10);  // для получения едениц 

		n /= 10;  // для получения десятков

	}
	return S;
}

int main() {

	setlocale(LC_ALL, "RUS");

	set <int> s1, s, s0, res;  // создаём множество
	
	int n, a;
	
	cout << "n = ";   
	
	cin >> n;   // вводим кол-во элементов
	
	cout << endl;


	cout << "Введите последовательность - ";

	for (int i = 1; i <= n; i++) {
	
		cin >> a;   // вводим значения
	
		s = set_n(a);   // передаём значения а в функцию и присваиваем к множеству
	
		if (a > 99 && a <= 999) {  // если число трёхзначное то вставляем значения в s0

			s0.insert(s.begin(), s.end());
		}

		if (a > 9 && a <= 99) {   // если число двузначное то вставляем значения в s1
	
			s1.insert(s.begin(), s.end());
		}
	}

	cout << endl << endl;
	
	set_difference(s1.begin(), s1.end(), s0.begin(), s0.end(), inserter(res, res.begin()));  // строит отсортированную последовательность из элементов, 
																							//имеющихся в первой последовательности но отсутствующих во второй и вставляет в res
	cout << "Цифры, которые встречаются только в двузначных числах - ";

	for (set<int>::iterator it = res.begin(); it != res.end(); it++) {   // выводим res

		cout << *it << " ";
	}

	cin.get();
	cin.get();
	return 0;
}