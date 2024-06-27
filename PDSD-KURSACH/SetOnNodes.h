#pragma once
struct Node {
	int value;
	Node* next;
};
// �������� ������� ���������
Node* create_empty_set();
// �������� �� ������� ���������
bool empty_check(Node*);
// �������� �������������� �������� ���������
bool check_element(Node*, int);
// ���������� ������ �������� � ���������
Node* add_element(Node*, int);
// �������� ���������
Node* create_set(int, int, int);
// �������� ���������
int set_size(Node*);
// ����� ��������� ���������
std::string create_string_from_set(Node*, const char*);
// �������� ���������
Node* delete_set(Node*);
// �������� �� ������ ������������� �������
bool check_subset(Node*, Node*);
// ��������� ���� ��������
bool equality_set(Node*, Node*);
// ����������� ���� ��������
Node* set_union(Node*, Node*);
// ����������� ���� ��������
Node* set_intersection(Node*, Node*);
// �������� ��������
Node* set_difference(Node*, Node*);
// ������������ ��������
Node* set_symmetrical_difference(Node*, Node*);
