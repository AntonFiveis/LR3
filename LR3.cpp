#include <iostream>
#include "Labirint.h"
using namespace std;
int main()
{
    Labirint lab('f', { 1,5 });
    lab.outputWayToPoint({6,1});
}