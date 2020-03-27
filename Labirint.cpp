#include "Labirint.h"
#include <fstream>
#include <iomanip>
using namespace std;

void Labirint::inputLabirint(istream& is=cin) {
	is >> n;

	labirint.resize(n);
	distance.resize(n, vector<int>(n,INF));
	is.get();
	for (int i = 0; i < n; i++) {
		getline(is, labirint[i]);
	}
}
Labirint::Labirint(char ans, Point start) {

	if (ans == 'f') {
		string tmp;
		getline(cin,tmp);
		ifstream inF(tmp);
		inputLabirint(inF);
	}
	else {
		inputLabirint();
	}
	distance[start.y][start.x] = 0;
	dejikstra(start);
	
}
Labirint::Labirint(char ans, Point start,Point end) {

	if (ans == 'f') {
		string tmp;
		getline(cin, tmp);
		ifstream inF(tmp);
		inputLabirint(inF);
	}
	else {
		inputLabirint();
	}
	distance[start.y][start.x] = 0;
	AStar(start, end);

}

void Labirint::dejikstra(Point start) {
	if (start.x + 1 < labirint[start.y].length() && labirint[start.y][start.x + 1] == ' ') {
		if (distance[start.y][start.x + 1] > distance[start.y][start.x] + 1) {
			queue.push({ start.x + 1,start.y });
			distance[start.y][start.x + 1] = distance[start.y][start.x] + 1;
		}
	}
	if (start.y + 1 < n && labirint[start.y+1][start.x] == ' ') {
		if (distance[start.y+1][start.x ] > distance[start.y][start.x] + 1) {
			queue.push({ start.x ,start.y+1 });
			distance[start.y+1][start.x] = distance[start.y][start.x] + 1;
		}
	}
	if (start.x -1 >=0 && labirint[start.y][start.x - 1] == ' ') {
		if (distance[start.y][start.x - 1] > distance[start.y][start.x] + 1) {
			queue.push({ start.x - 1,start.y });
			distance[start.y][start.x - 1] = distance[start.y][start.x] + 1;
		}
		
	}
	if (start.y- 1 >=0 && labirint[start.y-1][start.x] == ' ') {
		if (distance[start.y-1][start.x] > distance[start.y][start.x] + 1) {
			queue.push({ start.x,start.y-1 });
			distance[start.y-1][start.x] = distance[start.y][start.x] + 1;
		}
	}
	
	if (!queue.isEmpty()){
		Point tmp = queue.getFirst();
		dejikstra(tmp);
	}
	
}
void Labirint::AStar(Point start,Point end) {
	if (start.x == end.x&&start.y==end.y) {
		return;
	}
	if (start.x + 1 < labirint[start.y].length() && labirint[start.y][start.x + 1] == ' ') {
		if (distance[start.y][start.x + 1] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x + 1,start.y },end);
			distance[start.y][start.x + 1] = distance[start.y][start.x] + 1;
		}
	}
	if (start.y + 1 < n && labirint[start.y + 1][start.x] == ' ') {
		if (distance[start.y + 1][start.x] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x ,start.y + 1 },end);
			distance[start.y + 1][start.x] = distance[start.y][start.x] + 1;
		}
	}
	if (start.x - 1 >= 0 && labirint[start.y][start.x - 1] == ' ') {
		if (distance[start.y][start.x - 1] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x - 1,start.y },end);
			distance[start.y][start.x - 1] = distance[start.y][start.x] + 1;
		}

	}
	if (start.y - 1 >= 0 && labirint[start.y - 1][start.x] == ' ') {
		if (distance[start.y - 1][start.x] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x,start.y - 1 },end);
			distance[start.y - 1][start.x] = distance[start.y][start.x] + 1;
		}
	}

	if (!queue1.isEmpty()) {
		Point tmp = queue1.getFirst();
		AStar(tmp,end);
	}

}
void Labirint::outputWay() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << labirint[i][j];
		}
		cout << endl;
	}
}
void Labirint::FindAndoutputWayToPoint(Point end) {
	labirint[end.y][end.x] = distance[end.y ][end.x] + 'a';
	if (distance[end.y + 1][end.x]+1 == distance[end.y][end.x]) {
		
		FindAndoutputWayToPoint({ end.x,end.y +1 });
	}
	else if (distance[end.y - 1][end.x]+1 == distance[end.y][end.x]) {
		FindAndoutputWayToPoint({ end.x,end.y - 1 });

	}
	else if (distance[end.y][end.x+1] + 1 == distance[end.y][end.x]) {
		FindAndoutputWayToPoint({ end.x+1,end.y });
	}
	else if (distance[end.y][end.x-1] + 1 == distance[end.y][end.x]) {
		FindAndoutputWayToPoint({ end.x-1,end.y });
	}
	else {
		outputWay();
		clearWay();
	}
}

void Labirint::clearWay() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < labirint[i].length(); j++) {
			if (labirint[i][j] != ' ' && labirint[i][j] != 'X') {
				labirint[i][j] = ' ';
			}
		}
	}
}
