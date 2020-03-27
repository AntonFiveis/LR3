#include "Labirint.h"
#include <fstream>
using namespace std;

void Labirint::inputLabirint(istream& is=cin) {
	is >> n;
	labirint.resize(n);
	distance.resize(n, vector<int>(n,10000));
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
	dejikstra(start);
	
}


void Labirint::dejikstra(Point start) {
	distance[start.y][start.x] = 0;
	if (start.x + 1 < labirint[start.y].length() && labirint[start.y][start.x + 1] == ' ') {
		queue.push({ start.x+1,start.y });
	}
	if (start.y + 1 < n && labirint[start.y+1][start.x] == ' ') {
		queue.push({ start.x,start.y+1 });
	}
	if (start.x -1 >0 && labirint[start.y][start.x - 1] == ' ') {
		queue.push({ start.x-1,start.y });
	}
	if (start.y- 1 >0 && labirint[start.y-1][start.x] == ' ') {
		queue.push({ start.x,start.y-1 });
	}

}