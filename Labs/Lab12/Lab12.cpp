#include "AdjGraph.h"
// #include "LinkedListT.h"
// #include "LinkedListT.cpp"
#include <iostream>

using namespace std;

int main(){

    AdjGraph<int> instance;
    // int what = 1;
    // int* whatPtr = &what;
    instance.addVertex(1);
    instance.addVertex(3);
    instance.addVertex(2);
    instance.addVertex(5);

    instance.PrintVerticies();

    instance.addEdge(1, 3);


    (instance.outEdges(1)).PrintList();
    cout << "Length of edges " << (instance.outEdges(1)).Length();
    
    // LL<int> tester;
    // tester.InsertEnd(5);
    // tester.PrintListr();
    
    /*
    int userChoice = 0;
    
    while(userChoice != 9){
        cout << "Press 1 to add a vertex to graph." << endl;
        cout << "Press 2 to remove a vertex from graph." << endl;
        cout << "Press 3 to add an edge to graph." << endl;
        cout << "Press 4 to remove an edge from graph." << endl;
        cout << "Press 5 to find an edge in graph." << endl;
        cout << "Press 6 to find out edges of a vertex." << endl;
        cout << "Press 7 to find in edges of a vertex." << endl;
        cout << "Press 8 to print adjacency list." << endl;
        cout << "Press 9 to quit." << endl;
        cin >> userChoice;
        while(userChoice < 1 && userChoice > 9){
            cout << "Please enter a number 1-9: "
            cin >> userChoice;
        }

        switch (userChoice)
        {
        case 1:
            cout << "Enter vertex to add: ";
            int vertexAdd;
            cin >> vertexAdd;
            instance.addVertex(vertexAdd);
            break;
        case 2:
            cout << "Enter vertex to remove: ";
            int vertexRemove;
            cin >> vertexRem;
            instance.RemoveVertex(vertexRem);
            break;
        case 3:
            cout << "Enter starting vertex: ";
            int start;
            cin >> start;
            cout << "Enter ending vertex: ";
            int end;
            cin >> end;
            instance.addEdge(start, end);
            break;
        case 4:
            cout << "Enter starting vertex: ";
            int start;
            cin >> start;
            cout << "Enter ending vertex: ";
            int end;
            cin >> end;
            instance.removeEdge(start, end);
            break;
        case 5:
            cout << "Enter starting vertex: ";
            int start;
            cin >> start;
            cout << "Enter ending vertex: ";
            int end;
            cin >> end;
            if(instance.hasEdge(start, end) == true){
                cout << "That edge is in the graph!" << endl;
            }
            else{
                cout << "That egde is not in the graph." << endl;
            }
            break;
        case 6:
            cout << "Enter the vertex to find the out edges of: ";
            int userVertex;
            cin >> userVertex;
            cout << "Out edges of " << userVertex << ": " << endl;
            cout << instance.outEdges(userVertex).PrintList(); << endl;
            break;
        case 7:
            cout << "Enter the vertex to find the in edges of: ";
            int userVertex;
            cin >> userVertex;
            cout << "In edges of " << userVertex << ": " << endl;
            cout << instance.inEdges(userVertex) << endl;
            break;
        case 8:
            instance.PrintVerticies();
            break;
        }
    }
    */
    cout << endl << "Ending program..." << endl;
    return 0;
}

// Linker proof
// g++ -c Lab12.cpp 
// g++ -o main.exe Lab12.o
// ./main.exe

// desired call testing
// g++ -c Lab12.cpp AdjGraph.cpp
// g++ -o main.exe Lab12.o AdjGraph.o
// ./main.exe

// desired call testing
// g++ -c Lab12.cpp LinkedListT.cpp
// g++ -o main.exe Lab12.o LinkedListT.o
// ./main.exe

// Full test
// g++ -c Lab12.cpp AdjGraph.cpp LinkedListT.cpp
// g++ -o main.exe Lab12.o AdjGraph.o LinkedListT.o
// ./main.exe