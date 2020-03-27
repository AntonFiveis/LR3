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
	void dejikstra(Point);
	void inputLabirint(std::istream&);
	void outputWay();
public:
	Labirint(char,Point);
	void FindAndoutputWayToPoint(Point);
	void outputWay();
	~Labirint() {};
};
