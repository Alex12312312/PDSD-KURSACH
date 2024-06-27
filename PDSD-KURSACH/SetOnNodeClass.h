#ifndef PDSD_COURSEWORK_SETONNODECLASS_H
#define PDSD_COURSEWORK_SETONNODECLASS_H
#include <ctime>
#include <stdlib.h>
#include <string>
class SetOnNodeClass
{
private:
	struct Node
	{
		Node* next;
		int value;
	};
	Node* head;
public:
	SetOnNodeClass();
	SetOnNodeClass(const SetOnNodeClass&);
	~SetOnNodeClass();
	bool empty_check();
	bool check_element(int);
	Node* add_element(int);
	Node* create_set(int, int, int);
	int set_size();
	std::string create_string_from_set(const char*);
	Node* delete_set();
	bool check_subset(SetOnNodeClass&);
	bool equality_set(SetOnNodeClass&);
	SetOnNodeClass set_union(SetOnNodeClass);
	SetOnNodeClass set_intersection(SetOnNodeClass);
	SetOnNodeClass set_difference(SetOnNodeClass);
	SetOnNodeClass set_symmetrical_difference(SetOnNodeClass);
};
#endif //PDSD_COURSEWORK_SETONNODECLASS_H