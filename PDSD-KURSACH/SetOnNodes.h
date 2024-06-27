#pragma once
struct Node {
	int value;
	Node* next;
};
// создание пустого множества
Node* create_empty_set();
// проверка на пустоту множества
bool empty_check(Node*);
// проверка принадлежности элемента множеству
bool check_element(Node*, int);
// добавление нового элемента в множество
Node* add_element(Node*, int);
// создание множества
Node* create_set(int, int, int);
// мощность множества
int set_size(Node*);
// вывод элементов множества
std::string create_string_from_set(Node*, const char*);
// удаление множества
Node* delete_set(Node*);
// является ли первое подмножеством второго
bool check_subset(Node*, Node*);
// равенство двух множеств
bool equality_set(Node*, Node*);
// объединение двух множеств
Node* set_union(Node*, Node*);
// пересечение двух множеств
Node* set_intersection(Node*, Node*);
// разность множеств
Node* set_difference(Node*, Node*);
// симметричная разность
Node* set_symmetrical_difference(Node*, Node*);
