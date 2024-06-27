#ifndef PDSD_COURSEWORK_SETONLIST_H
#define PDSD_COURSEWORK_SETONLIST_H
#include <list>
#include <string>
class SetOnList {
private:
	std::list<int> SetList;
public:
	SetOnList();
	SetOnList(const SetOnList& anotherSetOnList);
	~SetOnList();
	bool empty_check();
	bool check_element(int);
	bool add_element(int);
	bool create_set(int, int, int);
	int set_size();
	std::string create_string_from_set(const char*);
	bool check_subset(SetOnList&);
	bool equality_set(SetOnList&);
	SetOnList set_union(SetOnList);
	SetOnList set_intersection(SetOnList);
	SetOnList set_difference(SetOnList);
	SetOnList set_symmetrical_difference(SetOnList);
};
#endif //PDSD_COURSEWORK_SETONLIST_H
