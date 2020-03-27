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
	if (!isEmpty()) {
		for (i = 0;i<queue.size()&& dist(queue[i], end) < distance; i++);
		if (i == queue.size())
			queue.push_back(el);
		else
			queue.insert(queue.begin() + i, el);
	}
	else
		queue.push_back(el);
}