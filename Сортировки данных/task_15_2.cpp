//15 ������� 
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



ifstream in("input.txt");//������� ��� �����
ofstream out("output.txt");//������� ��� ������

int **massiv(int n) { //������
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++) //��������� ������
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
		}
	return a;//������� �������� a
}

void vsort(int **a, int n) { //���������� ���������
	int j; int l;//��������� ���������� 
	for (int k = 1; k < 2 * n - 2; k++) {
		vector<int> b; //�������� ���������������� �������
		for (int i = 0; i < n; i++) //���������� ���������������� �������
			if (k - i < n && k - i >= 0)
				b.push_back(a[i][k - i]);
		for (int i = 1; i < b.size(); i++) { //���������� �������
			j = i;
			while (j > 0 && b[j] < b[j - 1]) {
				swap(b[j], b[j - 1]);// ������ �������
				j--;//���������� �� 1
			}
		}
		l = 0;//������������ �������� l
		for (int i = 0; i < n; i++)
			if (k - i < n && k - i >= 0) {
				a[i][k - i] = b[l];
				l++;//���������� 1
			}
		b.clear(); //������� ���������������� �������
	}
}

int main() {
	setlocale(LC_ALL, "RUS"); //������������� ������� ����������
	int n; in >> n; int k = 0;
	int **a = massiv(n); //������ ������
	vsort(a, n);//����� �������
	for (int i = 0; i < n; i++) { //����� �������
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	in.close();
	out.close();
	system("pause");//��������� �����
}