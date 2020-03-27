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
