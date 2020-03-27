#pragma once
#include "Queue.h"
#include <vector>
#include <iostream>
#include <string>
#define INF 1000000

class Labirint {
private:
	int n;
	std::vector<std::string> labirint;
	std::vector<std::vector<Point>> parent;
	std::vector<std::vector<int>> distance;
	Queue  queue;
	PriorityQueue queue1;
	void dejikstra(Point);
	void inputLabirint(std::istream&);
	void outputWay();
	void clearWay();
	void AStar(Point start, Point end);
public:
	Labirint(char,Point);
	Labirint(char, Point, Point);
	void FindAndoutputWayToPoint(Point);

	~Labirint() {};
};
