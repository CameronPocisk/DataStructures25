#include "AdjGraph.h"
// #include "LinkedListT.h"
// #include "LinkedListT.cpp"
#include <iostream>

using namespace std;

int main(){

    AdjGraph<int> DFSGraph;

    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;
    
    // Create the following graph (needs direction?)
    //     / 2  --  4
    //  1
    //     \ 3  --  5   --  6

    DFSGraph.addVertex(&one);
    DFSGraph.addVertex(&two);
    DFSGraph.addVertex(&three);
    DFSGraph.addVertex(&four);
    DFSGraph.addVertex(&five);
    DFSGraph.addVertex(&six);

    DFSGraph.addEdge(&one, &two);
    DFSGraph.addEdge(&one, &three);

    DFSGraph.addEdge(&two, &four);

    DFSGraph.PrintVerticies();

    DFSGraph.addEdge(&three, &five);
    DFSGraph.addEdge(&five, &six);

    DFSGraph.DFS(&one, &six);

    return 0;
}

// g++ -c DFSTest.cpp 
// g++ -o main.exe DFSTest.o
// ./main.exe