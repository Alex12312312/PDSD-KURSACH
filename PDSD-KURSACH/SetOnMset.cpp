#include "SetOnMset.h"
#include <algorithm>
#include <ctime>
#include <cstring>
SetOnMset::SetOnMset() {};
SetOnMset::SetOnMset(const SetOnMset& anotherSetOnMset) {
	SetMset = anotherSetOnMset.SetMset;
};
SetOnMset::~SetOnMset() {
	SetMset.clear();
};
// �������� ��������� �� �������
bool SetOnMset::empty_check() {
	return SetMset.empty();
};
// �������� �������������� �������� ���������
bool SetOnMset::check_element(int value) {
	if (empty_check()) {
		return false;
	}
	return SetMset.find(value) != SetMset.end();
};
// ���������� ������ �������� � ���������
void SetOnMset::add_element(int value) {
	SetMset.insert(value);
};
// �������� ���������
bool SetOnMset::create_set(int count, int min, int max) {
	if ((max - min + 1) <= count) {
		return false;
	}
	SetMset.clear();
	for (int i = 0; i < count; i++) {
		int value = min + (rand() % static_cast<int>(max - min + 1));
		while (check_element(value)) {
			value = min + (rand() % static_cast<int>(max - min + 1));
		}
		add_element(value);
	}
	return true;
};
// �������� ���������
int SetOnMset::set_size() {
	return SetMset.size();
};
// ����� ��������� ���������
std::string SetOnMset::create_string_from_set(const char* divider) {
	if (empty_check()) {
		return "";
	}
	std::string result = "";
	for (const auto& element : SetMset) {
		result += std::to_string(element);
		result += divider;
	}
	result.erase(result.size() - strlen(divider));
	return result;
};
// �������� �� ������ ������������� �������
bool SetOnMset::check_subset(SetOnMset& anotherSet) {
	if (empty_check()) {
		return true;
	};
	if (!empty_check() && anotherSet.empty_check()) {
		return false;
	}
	for (const auto& element : SetMset) {
		if (!anotherSet.check_element(element)) {
			return false;
		}
	}
	return true;
};
// ��������� ���� ��������
bool SetOnMset::equality_set(SetOnMset& anotherSet) {
	return check_subset(anotherSet) && anotherSet.check_subset(*this);
};
// ����������� ���� ��������
SetOnMset SetOnMset::set_union(SetOnMset anotherSet) {
	SetOnMset returnSet;
	for (const auto& element : SetMset) {
		returnSet.add_element(element);
	}
	for (const auto& element : anotherSet.SetMset) {
		returnSet.add_element(element);
	}
	return returnSet;
};
// ����������� ���� ��������
SetOnMset SetOnMset::set_intersection(SetOnMset anotherSet) {
	SetOnMset returnSet;
	if (empty_check() || anotherSet.empty_check()) {
		return returnSet;
	};
	for (const auto& element : SetMset) {
		if (anotherSet.check_element(element)) {
			returnSet.add_element(element);
		};
	}
	return returnSet;
};
// �������� ��������
SetOnMset SetOnMset::set_difference(SetOnMset anotherSet) {
	SetOnMset returnSet;
	if (empty_check()) {
		return returnSet;
	};
	for (const auto& element : SetMset) {
		if (!anotherSet.check_element(element)) {
			returnSet.add_element(element);
		};
	}
	return returnSet;
};
// ������������ ��������
SetOnMset SetOnMset::set_symmetrical_difference(SetOnMset anotherSet) {
	return
		set_union(anotherSet).set_difference(set_intersection(anotherSet));
};