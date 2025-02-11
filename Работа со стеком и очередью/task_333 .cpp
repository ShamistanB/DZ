// ������� �������, ���������� �����. ������� �� ������� ��� �����, ����������� � ��������� ������.
#include <iostream> 
using namespace std;


struct queue { // ��������� �������
	string value; // �������� �������� ��������
	queue* next; // �������� �� ��������� ������� �������
};

void push(queue*& h, queue*& z, string x) { // ������� ���������� �������� � ����� �������
	queue* r = new queue; // ��������� ��������� �������
	r->value = x; // ��������� ��� ��������
	r->next = NULL; // ���� ������� ������ ���������
	if (!h && !z) { // ���� ������� �����
		h = z = r; // ��� � ������ � ����� �������
	}
	else {		z->next = r; // r - ��������� �����
		z = r; // ������ r - �����
	}
}

string pop(queue*& h, queue*& z) { // ������� �������� �������� �� �������
	queue* r = h; // ������� ��������� �� ������
	string i = h->value; // ��������� �������� ������
	h = h->next; // �������� ��������� �� ��������� �������
	if (!h) // ���� ������� ��������� ������� �� �������
		z = NULL;
	delete r; // ������� ������ �������
	return i; // ���������� ��������
}

int main() {
	setlocale(LC_ALL, "RUS"); // ����������� ������� ���������� 
	int n; // ���������� ���������� 
	string lastword = ""; // ������ ���������� �����
	string text = ""; // ���������� ������
	bool flag = false; // ���������� �����
	queue* sell = NULL;// ������ �������
	queue* drill = NULL; // ������ �������
	cout << "n = "; // ���� ���������� ����
	cin >> n; // ���� �����
	for (int i = 0; i != n; i++) { // �������� �� ����� �������
		cout << "a[" << i << "] = ";
		cin >> text; // ���� ���������� ��������
		push(sell, drill, text); // ���������� ��� � ����� �������
		if (i == n - 1) // ���� ��� ��������� �����
			lastword = text; // �� ��������� ���
	}

	cout << "����� �������: ";  // ����� ����� �������
	for (int i = 0; i != n; i++) { // �������� �� ����� ������� 
		text = pop(sell, drill); // ��������� ��������� �������� �������
		if (!(text == lastword)) // ���� ��� �� ����� ���������� �����
			cout << text << " "; // ������� ���
	}
	system("pause"); // ��������� �����
	return 0; // ����������� 
}