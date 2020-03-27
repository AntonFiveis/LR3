#pragma once
#include <vector>
template<class T>
class Queue
{
private:
	std::vector<T> queue;
public:
	bool isEmpty() { return queue.empty(); }
	T getFirst();
	void push(T el) {queue.push_back(el)};
};


