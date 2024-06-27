#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "SetOnNodes.h"
// создание пустого множества
Node* create_empty_set() {
	return nullptr;
}
// проверка на пустоту множества
bool empty_check(Node* address) {
	return address == nullptr;
}
// проверка принадлежности элемента множеству
bool check_element(Node* address, int number) {
	if (empty_check(address)) {
		return false;
	}
	Node* current = address;
	while (current != nullptr) {
		if (current->value == number) {
			return true;
		}
		else {
			current = current->next;
		}
	}
	return false;
}
// добавление нового элемента в множество
Node* add_element(Node* address, int number) {
	if (check_element(address, number)) {
		return address;
	}
	Node* new_node = new Node;
	new_node->next = address;
	new_node->value = number;
	address = new_node;
	return address;
}
// создание множества
Node * create_set(int count_num, int min, int max) {
	if ((max - min + 1) <= count_num) {
		return nullptr;
	}
	Node* address = create_empty_set();
	Node* previous_address;
	while (count_num) {
		int number = min + (rand() % static_cast<int>(max - min + 1));
		previous_address = address;
		address = add_element(address, number);
		if (previous_address != address) {
			count_num--;
		}
	}
	return address;
}
// мощность множества
int set_size(Node* address) {
	int lenght = 0;
	while (address != nullptr) {
		lenght++;
		address = address->next;
	}
	return lenght;
}
// вывод элементов множества
std::string create_string_from_set(Node* address, const char* divider) {
	if (empty_check(address)) {
		return "";
	}
	std::string result = "";
	while (address != nullptr) {
		result += std::to_string(address->value);
		result += divider;
		address = address->next;
	}
	result.erase(result.size() - strlen(divider));
	return result;
}
// удаление множества
Node* delete_set(Node* address) {
	if (empty_check(address)) {
		return nullptr;
	}
	while (address != nullptr) {
		Node* current = address;
		address = address->next;
		delete current;
	}
	address = nullptr;
	return address;
}
// является ли первое подмножеством второго
bool check_subset(Node* address_1, Node* address_2) {
	if (empty_check(address_1)) {
		return true;
	}
	if (!empty_check(address_1) && empty_check(address_2)) {
		return false;
	}
	if (set_size(address_1) > set_size(address_2)) {
		return false;
	}
	Node* temp = address_1;
	while (temp != nullptr) {
		if (!check_element(address_2, temp->value)) {
			return false;
		}
		temp = temp->next;
	}
	return true;
}
// равенство двух множеств
bool equality_set(Node* address_1, Node* address_2) {
	return check_subset(address_1, address_2) && check_subset(address_2,
		address_1);
}
// объединение двух множеств
Node* set_union(Node* address_1, Node* address_2) {
	Node* new_set = create_empty_set();
	Node* temp = address_1;
	while (temp != nullptr) {
		new_set = add_element(new_set, temp->value);
		temp = temp->next;
	}
	temp = address_2;
	while (temp != nullptr) {
		new_set = add_element(new_set, temp->value);
		temp = temp->next;
	}
	return new_set;
}
// пересечение двух множеств
Node* set_intersection(Node* address_1, Node* address_2) {
	Node* new_set = create_empty_set();
	if (empty_check(address_1) || empty_check(address_2)) {
		return new_set;
	}
	Node* temp = address_1;
	while (temp != nullptr) {
		auto element = temp->value;
		if (check_element(address_2, element)) {
			new_set = add_element(new_set, element);
		}
		temp = temp->next;
	}
	return new_set;
}
// разность множеств
Node* set_difference(Node* address_1, Node* address_2) {
	Node* new_set = create_empty_set();
	if (empty_check(address_1)) {
		return new_set;
	}
	Node * temp = address_1;
	while (temp != nullptr) {
		auto element = temp->value;
		if (!check_element(address_2, element)) {
			new_set = add_element(new_set, element);
		}
		temp = temp->next;
	}
	return new_set;
}
// симметричная разность
Node* set_symmetrical_difference(Node* address_1, Node* address_2) {
	return set_difference(set_union(address_1, address_2),
		set_intersection(address_1, address_2));
}