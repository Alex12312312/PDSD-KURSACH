#include "SetOnQueue.h"
#include <algorithm>
#include <time.h>
#include "string.h"
SetOnQueue::SetOnQueue() {};
SetOnQueue::SetOnQueue(const SetOnQueue& anotherSetOnQueue) {
	SetQueue = anotherSetOnQueue.SetQueue;
};
SetOnQueue::~SetOnQueue() {
	int queueSize = SetQueue.size();
	for (int i = 0; i < queueSize; i++) {
		SetQueue.pop();
	}
};
// проверка множества на пустоту
bool SetOnQueue::empty_check() {
	return SetQueue.empty();
};
// проверка принадлежности элемента множеству
bool SetOnQueue::check_element(int value) {
	if (empty_check()) {
		return false;
	}
	for (int i = 0; i < SetQueue.size(); i++) {
		SetQueue.push(SetQueue.front());
		if (SetQueue.front() == value) {
			SetQueue.pop();
			return true;
		}
		SetQueue.pop();
	}
	return false;
};
// добавление нового элемента в множество
bool SetOnQueue::add_element(int value) {
	int testTime = clock();
	if (check_element(value)) {
		return false;
	}
	int endTime = clock() - testTime;
	SetQueue.push(value);
	return true;
};
// создание множества
bool SetOnQueue::create_set(int count, int min, int max) {
	if ((max - min + 1) <= count) {
		return false;
	}
	int queueSize = SetQueue.size();
	for (int i = 0; i < queueSize; i++) {
		SetQueue.pop();
	}
	while (count)
	{
		int value = min + (rand() % (max - min + 1));
		if (add_element(value)) {
			count--;
		};
	}
	return true;
};
// мощность множества
int SetOnQueue::set_size() {
	return SetQueue.size();
};
// вывод элементов множества
std::string SetOnQueue::create_string_from_set(const char* divider) {
	std::queue<int> newQueue;
	if (empty_check()) {
		return "";
	}
	std::string result = "";
	for (int i = 0; i < SetQueue.size(); i++) {
		result += std::to_string(SetQueue.front());
		SetQueue.push(SetQueue.front());
		SetQueue.pop();
		result += divider;
	}
	result.erase(result.size() - strlen(divider));
	return result;
};
// €вл€етс€ ли первое подмножеством второго
bool SetOnQueue::check_subset(SetOnQueue& anotherSet) {
	if (empty_check()) {
		return true;
	};
	if (!empty_check() && anotherSet.empty_check()) {
		return false;
	}
	for (int i = 0; i < SetQueue.size(); i++) {
		SetQueue.push(SetQueue.front());
		if (!anotherSet.check_element(SetQueue.front())) {
			SetQueue.pop();
			return false;
		}
		SetQueue.pop();
	}
	return true;
};
// равенство двух множеств
bool SetOnQueue::equality_set(SetOnQueue& anotherSet) {
	return check_subset(anotherSet) && anotherSet.check_subset(*this);
};
// объединение двух множеств
SetOnQueue SetOnQueue::set_union(SetOnQueue anotherSet) {
	SetOnQueue returnSet;
	for (int i = 0; i < SetQueue.size(); i++) {
		SetQueue.push(SetQueue.front());
		returnSet.add_element(SetQueue.front());
		SetQueue.pop();
	}
	for (int i = 0; i < anotherSet.SetQueue.size(); i++) {
		anotherSet.SetQueue.push(SetQueue.front());
		returnSet.add_element(anotherSet.SetQueue.front());
		anotherSet.SetQueue.pop();
	}
	return returnSet;
};
// пересечение двух множеств
SetOnQueue SetOnQueue::set_intersection(SetOnQueue anotherSet) {
	SetOnQueue returnSet;
	if (empty_check() || anotherSet.empty_check()) {
		return returnSet;
	};
	for (int i = 0; i < SetQueue.size(); i++) {
		SetQueue.push(SetQueue.front());
		if (anotherSet.check_element(SetQueue.front())) {
			returnSet.add_element(SetQueue.front());
		};
		SetQueue.pop();
	}
	return returnSet;
};
// разность множеств
SetOnQueue SetOnQueue::set_difference(SetOnQueue anotherSet) {
	SetOnQueue returnSet;
		if (empty_check()) {
			return returnSet;
		};
	for (int i = 0; i < SetQueue.size(); i++) {
		SetQueue.push(SetQueue.front());
		if (!anotherSet.check_element(SetQueue.front())) {
			returnSet.add_element(SetQueue.front());
		};
		SetQueue.pop();
	}
	return returnSet;
};
// симметрична€ разность
SetOnQueue SetOnQueue::set_symmetrical_difference(SetOnQueue anotherSet) {
	return set_union(anotherSet).set_difference(set_intersection(anotherSet));
};