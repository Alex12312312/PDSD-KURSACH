#include "SetOnList.h"
#include <algorithm>
#include <ctime>
#include <cstring>
SetOnList::SetOnList() {};
SetOnList::SetOnList(const SetOnList& anotherSetOnList) {
	SetList = anotherSetOnList.SetList;
};
SetOnList::~SetOnList() {
	SetList.clear();
};
// �������� ��������� �� �������
bool SetOnList::empty_check() {
	return SetList.empty();
};
// �������� �������������� �������� ���������
bool SetOnList::check_element(int value) {
	if (empty_check()) {
		return false;
	}
	return std::find(SetList.begin(), SetList.end(), value) != SetList.end();
};
// ���������� ������ �������� � ���������
bool SetOnList::add_element(int value) {
	if (check_element(value)) {
		return false;
	}
	SetList.push_front(value);
	return true;
};
// �������� ���������
bool SetOnList::create_set(int count, int min, int max) {
	if ((max - min + 1) <= count) {
		return false;
	}
	SetList.clear();
	while (count)
	{
		int value = min + (rand() % static_cast<int>(max - min + 1));
		if (add_element(value)) {
			count--;
		};
	}
	return true;
};
// �������� ���������
int SetOnList::set_size() {
	return SetList.size();
};
// ����� ��������� ���������
std::string SetOnList::create_string_from_set(const char* divider) {
	if (empty_check()) {
		return "";
	}
	std::string result = "";
	for (const auto& element : SetList) {
		result += std::to_string(element);
		result += divider;
	}
	result.erase(result.size() - strlen(divider));
	return result;
};
// �������� �� ������ ������������� �������
bool SetOnList::check_subset(SetOnList& anotherSet) {
	if (empty_check()) {
		return true;
	};
	if (!empty_check() && anotherSet.empty_check()) {
		return false;
	}
	for (const auto& element : SetList) {
		if (!anotherSet.check_element(element)) {
			return false;
		}
	}
	return true;
};
// ��������� ���� ��������
bool SetOnList::equality_set(SetOnList& anotherSet) {
	return check_subset(anotherSet) && anotherSet.check_subset(*this);
};
// ����������� ���� ��������
SetOnList SetOnList::set_union(SetOnList anotherSet) {
	SetOnList returnSet;
	for (const auto& element : SetList) {
		returnSet.add_element(element);
	}
	for (const auto& element : anotherSet.SetList) {
		returnSet.add_element(element);
	}
	return returnSet;
};
// ����������� ���� ��������
SetOnList SetOnList::set_intersection(SetOnList anotherSet) {
	SetOnList returnSet;
	if (empty_check() || anotherSet.empty_check()) {
		return returnSet;
	};
	for (const auto& element : SetList) {
		if (anotherSet.check_element(element)) {
			returnSet.add_element(element);
		};
	}
	return returnSet;
};
// �������� ��������
SetOnList SetOnList::set_difference(SetOnList anotherSet) {
	SetOnList returnSet;
	if (empty_check()) {
		return returnSet;
	};
	for (const auto& element : SetList) {
		if (!anotherSet.check_element(element)) {
			returnSet.add_element(element);
		};
	}
	return returnSet;
};
// ������������ ��������
SetOnList SetOnList::set_symmetrical_difference(SetOnList anotherSet) {
	return
		set_union(anotherSet).set_difference(set_intersection(anotherSet));
};