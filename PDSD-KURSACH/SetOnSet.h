#ifndef PDSD_COURSEWORK_SETONSET_H
#define PDSD_COURSEWORK_SETONSET_H
#include <set>
#include <string>
class SetOnSet {
private:
	std::set<int> SetSet;
public:
	SetOnSet();
	SetOnSet(const SetOnSet& anotherSetOnSet);
	~SetOnSet();
	bool empty_check();
	bool check_element(int);
	bool add_element(int);
	bool create_set(int, int, int);
	int set_size();
	std::string create_string_from_set(const char*);
	bool check_subset(SetOnSet&);
	bool equality_set(SetOnSet&);
	SetOnSet set_union(SetOnSet);
	SetOnSet set_intersection(SetOnSet);
	SetOnSet set_difference(SetOnSet);
	SetOnSet set_symmetrical_difference(SetOnSet);
};
#endif //PDSD_COURSEWORK_SETONSET_H
