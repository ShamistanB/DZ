// ���� ������. ������� ��� ������.
#include<iostream>
#include <string>

using namespace std;

struct tree { // ��������� ������
	int dual; // �������� ����
	tree* right; // ������ ����
	tree* left; // ����� ����
};

tree * node(int x) { // ������� �������� ���� 
	 tree * n = new tree; // ��������� ������
	 n->dual  = x; // �������� ���� �
	 n-> left = n-> right = NULL; // ����� � ������ ���� ����
	 return n; // ����������� �������� ����
}

void create(tree*& tr, int n) { //������� �������� �������� ����������������� ������ 
	int x; // ���������� ���������� 
	if (n > 0) { // ���� n ������ ���� 
		cout << "�������:  "; // ����� �� �����
		cin >> x; // ���� 
		tr = node(x); // �������� ����
		int nl = n / 2; // ���������� ���-�� ��������� � ����� �����
		int nr = n - nl - 1; // ���������� ���-�� ��������� � ������ �����
		create(tr->left, nl); // ����������� ����� ��� ����� �����
		create(tr->right, nr); // ����������� ����� ��� ����� ������
	}
}

void preorder(tree* tr){ // ������� ������� ������
	if (tr){ // ���� tr �� ����
		cout << tr->dual << " "; // ����� ��������
		preorder(tr->left);  // ����������� ����� �� ����� �����
		preorder(tr->right); // ����������� ����� �� ������ �����
	}
}
 
void printLeaf(tree* tr) { // ������� ������ ������� 
	if ((tr->left == NULL) && (tr->right == NULL)) // ���� � ���� ��� �����
		cout << "����:" << tr->dual << "\n"; // ������� 
	else { // ����� 
		if (tr->left) printLeaf(tr->left); // ����� ����������� ������� ��� ����� �����
		if (tr->right) printLeaf(tr->right); // ����� ����������� ������� ��� ������ �����
	}
}

int main() {
	setlocale(LC_ALL, "RUS"); // ����������� ������� ���������
	int n; // ���������� ���������� 
	cout << "n = "; // ����� �� �����
	cin >> n; // ���� n
	tree* tr = NULL; // ���������� ������ 
	create(tr, n); // ����� ������� ���������� ������
	preorder(tr);  // ������ �����
	cout << endl; 
	printLeaf(tr); // ����� ������� ������ ������� 
	return 0;
}
