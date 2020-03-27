#include "Queue.h"
using namespace std;

Point Queue::getFirst() {
	if (!isEmpty()) {
		Point tmp = queue[0];
		queue.erase(queue.begin());
		return tmp;
	}
	else {
		return {NULL,NULL};
	}
}
Point PriorityQueue::getFirst() {
	if (!isEmpty()) {
		Point tmp = queue[0];
		queue.erase(queue.begin());
		return tmp;
	}
	else {
		return { NULL,NULL };
	}
}
double dist(Point el, Point end) {
	return sqrt(pow(el.x - end.x, 2) + pow(el.y - end.y, 2));
}
void PriorityQueue::push(Point el, Point end) {
	double distance = dist(el, end);

	int i;
	int x = queue.size();
	for (i = 0; i < x; i++) {
		if (distance < dist(queue[i], end)) {
			continue;
		}
		 queue.insert(queue.begin() + i, el); 
		 break;
	}
	if (i == queue.size()) {
		queue.push_back(el);
	}
}