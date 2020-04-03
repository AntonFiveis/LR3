#include "Labirint.h"
#include <fstream>
#include <iomanip>
using namespace std;

void Labirint::inputLabirint(istream& is=cin) {
	
	for (int i = 0; !is.eof(); i++) {
		string temp;
		getline(is, temp);
		labirint.push_back(temp);
	}
	n = labirint.size();
	m = labirint[0].length();
	distance.resize(n, vector<int>(labirint[0].length(), INF));
}

Labirint::Labirint(char ans, Point start, Point end) {

	string tmp;
	getline(cin, tmp);
	ifstream inF(tmp);
	inputLabirint(inF);
	parent.resize(n, vector<Point>(m));
	parent[start.y][start.x] = { -1,-1 };
	distance[start.y][start.x] = 0;
	if(ans=='A')
	AStar(start, end);
	else
	dejikstra(start);
}

void Labirint::dejikstra(Point start) {
	if (start.x + 2 < m &&start.y+1<n&& labirint[start.y+1][start.x + 2] == ' ') {
		if (distance[start.y+1][start.x + 2] > distance[start.y][start.x] + 1) {
			queue.push({ start.x + 2,start.y +1});
			distance[start.y+1][start.x + 2] = distance[start.y][start.x] + 1;
			parent[start.y + 1][start.x + 2] = { start.x,start.y };
		}
	}
	if (start.x+2< m&&start.y - 1 >0 && labirint[start.y-1][start.x+2] == ' ') {
		if (distance[start.y - 1][start.x + 2] > distance[start.y][start.x] + 1) {
			queue.push({ start.x+2 ,start.y-1 });
			distance[start.y - 1][start.x + 2] = distance[start.y][start.x] + 1;
			parent[start.y - 1][start.x + 2] = { start.x,start.y };
		}
	}
	if (start.x -2 >0&&start.y+1<n && labirint[start.y+1][start.x - 2] == ' ') {
		if (distance[start.y + 1][start.x - 2] > distance[start.y][start.x] + 1) {
			queue.push({ start.x - 2,start.y+1 });
			distance[start.y + 1][start.x - 2] = distance[start.y][start.x] + 1;
			parent[start.y + 1][start.x - 2] = { start.x,start.y };
		}
		
	}
	if (start.x- 2 >=0&&start.y-1>0 && labirint[start.y-1][start.x-2] == ' ') {
		if (distance[start.y-1][start.x-2] > distance[start.y][start.x] + 1) {
			queue.push({ start.x-2,start.y-1 });
			distance[start.y-1][start.x-2] = distance[start.y][start.x] + 1;
			parent[start.y - 1][start.x - 2] = { start.x,start.y };
		}
	}
	if (start.y + 2 < n && start.x + 1 < m && labirint[start.y + 2][start.x + 1] == ' ') {
		if (distance[start.y + 2][start.x + 1] > distance[start.y][start.x] + 1) {
			queue.push({ start.x + 1,start.y + 2 });
			distance[start.y + 2][start.x + 1] = distance[start.y][start.x] + 1;
			parent[start.y + 2][start.x + 1] = { start.x,start.y };
		}
	}
	if (start.y + 2 < n && start.x - 1 > 0 && labirint[start.y + 2][start.x -1] == ' ') {
		if (distance[start.y +2][start.x-1] > distance[start.y][start.x] + 1) {
			queue.push({ start.x - 1 ,start.y +2 });
			distance[start.y +2][start.x -1] = distance[start.y][start.x] + 1;
			parent[start.y + 2][start.x - 1] = { start.x,start.y };
		}
	}
	if (start.y - 2 > 0 && start.x + 1 < m && labirint[start.y -2][start.x + 1] == ' ') {
		if (distance[start.y -2][start.x +1] > distance[start.y][start.x] + 1) {
			queue.push({ start.x + 1,start.y-2 });
			distance[start.y -2][start.x +1] = distance[start.y][start.x] + 1;
			parent[start.y - 2][start.x + 1] = { start.x,start.y };
		}

	}
	if (start.y - 2 > 0 && start.x - 1 > 0 && labirint[start.y - 2][start.x-1] == ' ') {
		if (distance[start.y - 2][start.x - 1] > distance[start.y][start.x] + 1) {
			queue.push({ start.x - 1,start.y - 2 });
			distance[start.y - 2][start.x - 1] = distance[start.y][start.x] + 1;
			parent[start.y -2][start.x - 1] = { start.x,start.y };
		}
	}
	//cout << start.x << ' ' << start.y << endl;
	
	if (!queue.isEmpty()){
		Point tmp = queue.getFirst();
		dejikstra(tmp);
	}
	
}
void Labirint::AStar(Point start,Point end) {
	if (start.x == end.x&&start.y==end.y) {
		return;
	}
	if (start.x + 2 < m && start.y + 1 < n && labirint[start.y + 1][start.x + 2] == ' ') {
		if (distance[start.y + 1][start.x + 2] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x + 2,start.y + 1 },end);
			distance[start.y + 1][start.x + 2] = distance[start.y][start.x] + 1;
			parent[start.y + 1][start.x + 2] = { start.x,start.y };
		}
	}
	if (start.x + 2 < m && start.y - 1 > 0 && labirint[start.y - 1][start.x + 2] == ' ') {
		if (distance[start.y - 1][start.x + 2] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x + 2 ,start.y - 1 },end);
			distance[start.y - 1][start.x + 2] = distance[start.y][start.x] + 1;
			parent[start.y - 1][start.x + 2] = { start.x,start.y };
		}
	}
	if (start.x - 2 > 0 && start.y + 1 < n && labirint[start.y + 1][start.x - 2] == ' ') {
		if (distance[start.y + 1][start.x - 2] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x - 2,start.y + 1 },end);
			distance[start.y + 1][start.x - 2] = distance[start.y][start.x] + 1;
			parent[start.y + 1][start.x - 2] = { start.x,start.y };
		}

	}
	if (start.x - 2 >= 0 && start.y - 1 > 0 && labirint[start.y - 1][start.x - 2] == ' ') {
		if (distance[start.y - 1][start.x - 2] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x - 2,start.y - 1 },end);
			distance[start.y - 1][start.x - 2] = distance[start.y][start.x] + 1;
			parent[start.y - 1][start.x - 2] = { start.x,start.y };
		}
	}
	if (start.y + 2 < n && start.x + 1 < m && labirint[start.y + 2][start.x + 1] == ' ') {
		if (distance[start.y + 2][start.x + 1] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x + 1,start.y + 2 },end);
			distance[start.y + 2][start.x + 1] = distance[start.y][start.x] + 1;
			parent[start.y + 2][start.x + 1] = { start.x,start.y };
		}
	}
	if (start.y + 2 < n && start.x - 1 > 0 && labirint[start.y + 2][start.x - 1] == ' ') {
		if (distance[start.y + 2][start.x - 1] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x - 1 ,start.y + 2 },end);
			distance[start.y + 2][start.x - 1] = distance[start.y][start.x] + 1;
			parent[start.y + 2][start.x - 1] = { start.x,start.y };
		}
	}
	if (start.y - 2 > 0 && start.x + 1 < m && labirint[start.y - 2][start.x + 1] == ' ') {
		if (distance[start.y - 2][start.x + 1] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x + 1,start.y - 2 },end);
			distance[start.y - 2][start.x + 1] = distance[start.y][start.x] + 1;
			parent[start.y - 2][start.x + 1] = { start.x,start.y };
		}

	}
	if (start.y - 2 > 0 && start.x - 1 > 0 && labirint[start.y - 2][start.x - 1] == ' ') {
		if (distance[start.y - 2][start.x - 1] > distance[start.y][start.x] + 1) {
			queue1.push({ start.x - 1,start.y - 2 },end);
			distance[start.y - 2][start.x - 1] = distance[start.y][start.x] + 1;
			parent[start.y - 2][start.x - 1] = { start.x,start.y };
		}
	}

	if (!queue1.isEmpty()) {
		Point tmp = queue1.getFirst();
		AStar(tmp,end);
	}

}
void Labirint::outputWay() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < labirint[i].length(); j++) {
			cout << setw(2) << labirint[i][j];
		}
		cout << endl;
	}
}
void Labirint::FindAndoutputWayToPoint(Point end) {
	if (distance[end.y][end.x] != INF)

		while (end.x != -1 && end.y != -1) {
			labirint[end.y][end.x] = distance[end.y][end.x] + 'a';
			end = parent[end.y][end.x];
		}
	outputWay();
	clearWay();
}
void Labirint::outputDistance() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < distance[i].size(); j++) {
			if (distance[i][j] != INF)
				cout << setw(2) << distance[i][j];
			else
				cout << setw(2) << 0;
		}
		cout << endl;
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
