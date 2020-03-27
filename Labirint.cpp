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
void Labirint::outputDist() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(10) << distance[i][j];
		}
		cout << endl;
	}
}