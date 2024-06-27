#include "SetOnSet.h"
#include <algorithm>
#include <ctime>
#include <cstring>
SetOnSet::SetOnSet() {};
SetOnSet::SetOnSet(const SetOnSet& anotherSetOnSet) {
	SetSet = anotherSetOnSet.SetSet;
};
SetOnSet::~SetOnSet() {
	SetSet.clear();
};
// проверка множества на пустоту
bool SetOnSet::empty_check() {
	return SetSet.empty();
};
// проверка принадлежности элемента множеству
bool SetOnSet::check_element(int value) {
	if (empty_check()) {
		return false;
	}
	return SetSet.find(value) != SetSet.end();
};
// добавление нового элемента в множество
bool SetOnSet::add_element(int value) {
	return SetSet.insert(value).second;
};
// создание множества
bool SetOnSet::create_set(int count, int min, int max) {
	if ((max - min + 1) <= count) {
		return false;
	}
	SetSet.clear();
	while (count)
	{
		int value = min + (rand() % static_cast<int>(max - min + 1));
		if (add_element(value)) {
			count--;
		};
	}
	return true;
};
// мощность множества
int SetOnSet::set_size() {
	return SetSet.size();
};
// вывод элементов множества
std::string SetOnSet::create_string_from_set(const char* divider) {
	if (empty_check()) {
		return "";
	}
	std::string result = "";
	for (const auto& element : SetSet) {
		result += std::to_string(element);
		result += divider;
	}
	result.erase(result.size() - strlen(divider));
	return result;
};
// €вл€етс€ ли первое подмножеством второго
bool SetOnSet::check_subset(SetOnSet& anotherSet) {
	if (empty_check()) {
		return true;
	};
	if (!empty_check() && anotherSet.empty_check()) {
		return false;
	}
	for (const auto& element : SetSet) {
		if (!anotherSet.check_element(element)) {
			return false;
		}
	}
	return true;
};
// равенство двух множеств
bool SetOnSet::equality_set(SetOnSet& anotherSet) {
	return check_subset(anotherSet) && anotherSet.check_subset(*this);
};
// объединение двух множеств
SetOnSet SetOnSet::set_union(SetOnSet anotherSet) {
	SetOnSet returnSet;
	for (const auto& element : SetSet) {
		returnSet.add_element(element);
	}
	for (const auto& element : anotherSet.SetSet) {
		returnSet.add_element(element);
	}
	return returnSet;
};
// пересечение двух множеств
SetOnSet SetOnSet::set_intersection(SetOnSet anotherSet) {
	SetOnSet returnSet;
	if (empty_check() || anotherSet.empty_check()) {
		return returnSet;
	};
	for (const auto& element : SetSet) {
		if (anotherSet.check_element(element)) {
			returnSet.add_element(element);
		};
	}
	return returnSet;
};
// разность множеств
SetOnSet SetOnSet::set_difference(SetOnSet anotherSet) {
	SetOnSet returnSet;
	if (empty_check()) {
		return returnSet;
	};
	for (const auto& element : SetSet) {
		if (!anotherSet.check_element(element)) {
			returnSet.add_element(element);
		};
	}
	return returnSet;
};
// симметрична€ разность
SetOnSet SetOnSet::set_symmetrical_difference(SetOnSet anotherSet) {
	return
		set_union(anotherSet).set_difference(set_intersection(anotherSet));
};