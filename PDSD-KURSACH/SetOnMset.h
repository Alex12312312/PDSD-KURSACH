#ifndef PDSD_COURSEWORK_SETONMSET_H
#define PDSD_COURSEWORK_SETONMSET_H
#include <set>
#include "string"
class SetOnMset {
private:
	std::multiset<int> SetMset;

public:
	SetOnMset();
	SetOnMset(const SetOnMset& anotherSetOnMset);
	~SetOnMset();
	bool empty_check();
	bool check_element(int);
	void add_element(int);
	bool create_set(int, int, int);
	int set_size();
	std::string create_string_from_set(const char*);
	bool check_subset(SetOnMset&);
	bool equality_set(SetOnMset&);
	SetOnMset set_union(SetOnMset);
	SetOnMset set_intersection(SetOnMset);
	SetOnMset set_difference(SetOnMset);
	SetOnMset set_symmetrical_difference(SetOnMset);
};
#endif //PDSD_COURSEWORK_SetOnMset_H