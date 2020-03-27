#include <iostream>
#include "Labirint.h"
using namespace std;
int main()
{
    int y1, y2, x1, x2;
    //cin >> x1 >> y1 >> x2 >> y2;
    //cin.get();
    Labirint lab('f', { 1,1 }, {5, 10});
    lab.FindAndoutputWayToPoint({ 5, 10 });
}