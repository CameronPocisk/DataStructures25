#include "AdjGraph.h"
#include <iostream>

using namespace std;

void addDouble(int* first, int* second, AdjGraph<int> graph){
    graph.addEdge(first, second);
    graph.addEdge(second, first);
}

int main(){

    AdjGraph<int> graphSearch;

    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;
    int seven = 7;
    
    // Create the following graph (needs direction?)
    //     / 2  --  5-- 7
    //  1  - 3   -/
    //     \ 4  --  5

    graphSearch.addVertex(&one);
    graphSearch.addVertex(&two);
    graphSearch.addVertex(&three);
    graphSearch.addVertex(&four);
    graphSearch.addVertex(&five);
    graphSearch.addVertex(&six);
    graphSearch.addVertex(&seven);
    graphSearch.PrintVerticies();

    // Add edges both ways
    addDouble(&one, &two, graphSearch);
    addDouble(&one, &three, graphSearch);
    addDouble(&one, &four, graphSearch);

    addDouble(&two, &five, graphSearch);
    addDouble(&three, &five, graphSearch);

    addDouble(&five, &seven, graphSearch);

    addDouble(&four, &six, graphSearch);


    graphSearch.DFS(&four, &six);
    graphSearch.BFS(&two, &six);


    return 0;
}

// g++ -c GraphSearchTest.cpp 
// g++ -o main.exe GraphSearchTest.o
// ./main.exe