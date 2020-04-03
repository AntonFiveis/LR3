#pragma once
#include <vector>
struct Point {
	int x;
	int y;
};
class Queue
{
private:
	std::vector<Point> queue;
public:
	bool isEmpty() { return queue.size()==0; }
	Point getFirst();
	void push(Point el) { queue.push_back(el); };
};

class PriorityQueue  {
private:
	std::vector<Point> queue;
public:
	bool isEmpty() { return queue.size() == 0; }
	Point getFirst();
	void push(Point el,Point end);
};
double dist(Point, Point);

