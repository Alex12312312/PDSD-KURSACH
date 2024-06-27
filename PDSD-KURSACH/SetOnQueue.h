#ifndef PDSD_COURSEWORK_SetOnQueue_H
#define PDSD_COURSEWORK_SetOnQueue_H
#include "string"
#include "queue"
class SetOnQueue {
private:
	std::queue<int> SetQueue;
public:
	SetOnQueue();
	SetOnQueue(const SetOnQueue& anotherSetOnQueue);
	~SetOnQueue();
	bool empty_check();
	bool check_element(int);
	bool add_element(int);
	bool create_set(int, int, int);
	int set_size();
	std::string create_string_from_set(const char*);
	bool check_subset(SetOnQueue&);
	bool equality_set(SetOnQueue&);
	SetOnQueue set_union(SetOnQueue);
	SetOnQueue set_intersection(SetOnQueue);
	SetOnQueue set_difference(SetOnQueue);
	SetOnQueue set_symmetrical_difference(SetOnQueue);
};
#endif //PDSD_COURSEWORK_SetOnQueue_H
