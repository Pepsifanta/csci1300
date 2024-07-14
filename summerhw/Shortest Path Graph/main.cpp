#include <iostream>
#include "minimalSpanningTreeType.h"
using namespace std;

int main()
{
    msTreeType obj;
    obj.createSpanningGraph(); // directly ask for user input
    obj.minimalSpanning(0);  // The starting node is assumed to be 0
    obj.printTreeAndWeight();
    return 0;
}
