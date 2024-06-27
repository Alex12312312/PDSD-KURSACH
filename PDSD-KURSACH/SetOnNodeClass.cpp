#include "SetOnNodeClass.h"
#include <cstdlib>
#include <string>
#include <ctime>
#include <string.h>
SetOnNodeClass::SetOnNodeClass() { head = nullptr; }
SetOnNodeClass::SetOnNodeClass(const SetOnNodeClass& anotherSetOnNodeClass)
{
	head = nullptr;
	Node* current = anotherSetOnNodeClass.head;
	while (current != nullptr)
	{
		head = add_element(current->value);
		current = current->next;
	}
}
SetOnNodeClass::~SetOnNodeClass()
{
	//delete_set();
}
// проверка на пустоту множества
bool SetOnNodeClass::empty_check() {
	return head == nullptr;
}
// проверка принадлежности элемента множеству
bool SetOnNodeClass::check_element(int number) {
	if (empty_check()) {
		return false;
	}
	Node* current = head;
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
SetOnNodeClass::Node* SetOnNodeClass::add_element(int number) {
	if (check_element(number)) {
		return head;
	}
	Node* new_node = new Node;
	new_node->next = head;
	new_node->value = number;
	head = new_node;
	return head;
}
// создание множества
SetOnNodeClass::Node* SetOnNodeClass::create_set(int count_num, int min, int
	max) {
	if ((max - min + 1) <= count_num) {
		return nullptr;
	}
	delete_set();
	Node* head = nullptr;
	Node* previous_address;
	while (count_num) {
		int number = min + (rand() % static_cast<int>(max - min + 1));
		previous_address = head;
		head = add_element(number);
		if (previous_address != head) {
			count_num--;
		}
	}
	return head;
}
// мощность множества
int SetOnNodeClass::set_size() {
	int lenght = 0;
	Node* temp = head;
	while (temp != nullptr) {
		lenght++;
		temp = temp->next;
	}
	return lenght;
}
// вывод элментов множества
std::string SetOnNodeClass::create_string_from_set(const char* divider) {
	if (empty_check()) {
		return "";
	}
	std::string result = "";
	Node* temp = head;
	while (temp != nullptr) {
		result += std::to_string(temp->value);
		result += divider;
		temp = temp->next;
	}
	result.erase(result.size() - strlen(divider));
	return result;
}
// удаление множества
SetOnNodeClass::Node* SetOnNodeClass::delete_set() {
	if (empty_check()) {
		return nullptr;
	}
	while (head != nullptr) {
		Node* current = head;
		head = head->next;
		delete current;
	}
	head = nullptr;
	return head;
}
// является ли первое подмножеством второго
bool SetOnNodeClass::check_subset(SetOnNodeClass& another_SetOnNodeClass) {
	if (empty_check()) {
		return true;
	}
	if (!empty_check() && another_SetOnNodeClass.empty_check()) {
		return false;
	}
	if (set_size() > another_SetOnNodeClass.set_size()) {
		return false;
	}
	Node* temp = head;
	while (temp != nullptr) {
		if (!another_SetOnNodeClass.check_element(temp->value)) {
			return false;
		}
		temp = temp->next;
	}
	return true;
}
// равенство двух множеств
bool SetOnNodeClass::equality_set(SetOnNodeClass& another_SetOnNodeClass) {
	return check_subset(another_SetOnNodeClass) &&
		another_SetOnNodeClass.check_subset(*this);
}
// объединение двух множеств
SetOnNodeClass SetOnNodeClass::set_union(SetOnNodeClass
	another_SetOnNodeClass) {
	SetOnNodeClass new_SetOnNodeClass = SetOnNodeClass();
	Node* temp = head;
	while (temp != nullptr) {
		new_SetOnNodeClass.head = new_SetOnNodeClass.add_element(temp -> value);
		temp = temp->next;
	}
	temp = another_SetOnNodeClass.head;
	while (temp != nullptr) {
		new_SetOnNodeClass.head = new_SetOnNodeClass.add_element(temp -> value);
		temp = temp->next;
	}
	return new_SetOnNodeClass;
}
// пересечение двух множеств
SetOnNodeClass SetOnNodeClass::set_intersection(SetOnNodeClass
	another_SetOnNodeClass) {
	SetOnNodeClass new_SetOnNodeClass = SetOnNodeClass();
	if (empty_check() || another_SetOnNodeClass.empty_check()) {
		return new_SetOnNodeClass;
	}
	Node* temp = head;
	while (temp != nullptr) {
		auto element = temp->value;
			if (another_SetOnNodeClass.check_element(element)) {
				new_SetOnNodeClass.head =
					new_SetOnNodeClass.add_element(element);
			}
		temp = temp->next;
	}
	return new_SetOnNodeClass;
}
// разность множеств
SetOnNodeClass SetOnNodeClass::set_difference(SetOnNodeClass
	another_SetOnNodeClass) {
	SetOnNodeClass new_SetOnNodeClass = SetOnNodeClass();
	if (empty_check()) {
		return new_SetOnNodeClass;
	}
	Node* temp = head;
	while (temp != nullptr) {
		auto element = temp->value;
		if (!another_SetOnNodeClass.check_element(element)) {
			new_SetOnNodeClass.head =
				new_SetOnNodeClass.add_element(element);
		}
		temp = temp->next;
	}
	return new_SetOnNodeClass;
}
// симметричная разность
SetOnNodeClass SetOnNodeClass::set_symmetrical_difference(SetOnNodeClass
	another_SetOnNodeClass) {
	return
		set_union(another_SetOnNodeClass).set_difference(set_intersection(another_SetOnNodeClass));
}