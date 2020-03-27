#include <iostream>
#include "Labirint.h"
using namespace std;
int main()
{
    int y1, y2, x1, x2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Dejikstra(d) or A*(A):";
    char ans;
    cin >> ans;
    cin.get();
    Labirint lab(ans, { x1,y1 }, {x2, y2});
    lab.FindAndoutputWayToPoint({ x2, y2 });
}