#include "Queue.h"
using namespace std;
template<class T>
T Queue<T>::getFirst() {
	if (!isEmpty()) {
		T tmp = queue[0];
		queue.erase(queue.begin());
		return tmp;
	}
	else {
		return NULL;
	}
}

