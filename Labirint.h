#pragma once
#include "Queue.h"
#include <vector>
#include <iostream>
#include <string>

struct Point {
	int x;
	int y;
};

class Labirint {
private:
	int n;
	std::vector<std::string> labirint;
	std::vector<std::vector<Point>> parent;
	std::vector<std::vector<int>> distance;
	std::vector<bool> visited;
	Queue < Point> queue;
	void dejikstra(Point);
	void inputLabirint(std::istream&);
public:
	Labirint(char,Point);

	
	~Labirint();
};
