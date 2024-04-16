#include "AdjGraph.h"
// #include "LinkedListT.h"
// #include "LinkedListT.cpp"
#include <iostream>

using namespace std;

int main(){

    AdjGraph<int> instance;
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;

    // int what = 1;
    // int* whatPtr = &what;
    // instance.addVertex(&one);
    // instance.addVertex(&two);
    // instance.addVertex(&three);
    // instance.addVertex(&four);
    // instance.addEdge(&three, &five);
    // instance.addEdge(&one, &two);
    // instance.addEdge(&one, &three);
    // // Vertex<int> i = instance.nodes.GetIndex(1);
    // // cout << "hi" << endl;
    // // cout << i.info << endl;
    // instance.PrintVerticies();

    // // instance.addEdge(1, 3);


    // cout << "Ones edges: "; (instance.outEdges(&one)).PrintList(); cout << endl;
    // cout << "Length of edges " << (instance.outEdges(&one)).GetLength(); cout << endl;
    // cout << "One has two edge: " << instance.hasEdge(&one, &two) << endl;
    // cout << "One has five edge: " << instance.hasEdge(&one, &five) << endl;

    // instance.removeVertex(&two);
    // cout << endl << "Removed vertex two: " << endl; 
    // cout << "One has two edge: " << instance.hasEdge(&one, &two) << endl;
    // instance.removeVertex(&one);
    // cout << endl << "Removed vertex one: " << endl; 

    // instance.removeVertex(&five);
    // cout << endl << "Removed vertex five: " << endl; 

    // instance.PrintVerticies();
    
    // LL<int> tester;
    // tester.InsertEnd(5);
    // tester.PrintListr();
    
    
    int userChoice = 0;
    
    while(userChoice != 11){
        cout << "Enter 1 to add a vertex to graph." << endl;
        cout << "Enter 2 to remove a vertex from graph." << endl;
        cout << "Enter 3 to add an edge to graph." << endl;
        cout << "Enter 4 to remove an edge from graph." << endl;
        cout << "Enter 5 to find an edge in graph." << endl;
        cout << "Enter 6 to find out edges of a vertex." << endl;
        cout << "Enter 7 to find in edges of a vertex." << endl;
        cout << "Enter 8 to print adjacency list." << endl;
        cout << "Enter 9 to test DFS." << endl;
        cout << "Enter 10 to test BFS." << endl;
        cout << "Enter 11 to quit." << endl;
        cin >> userChoice;
        while(userChoice < 1 || userChoice > 11){
            cout << "Please enter a number 1-11: ";
            cin >> userChoice;
        }

        switch (userChoice)
        {
        case 1:{
            cout << "Enter vertex to add: ";
            int hold;
            cin >> hold;
            int* vertexAdd = new int(hold);
            instance.addVertex(vertexAdd);
            break;
        }
        case 2:{
            cout << "Enter vertex to remove: ";
            int vertexRemove;
            cin >> vertexRemove;
            instance.removeVertex(&vertexRemove);
            break;
        }
        case 3:{
            int sHold;
            int eHold;
            cout << "Enter starting vertex: ";
            cin >> sHold;
            int* userStart = new int(sHold);
            cout << "Enter ending vertex: ";
            cin >> eHold;
            int* userEnd = new int(eHold);
            instance.addEdge(userStart, userEnd);
            break;
        }
        case 4:{
            cout << "Enter starting vertex: ";
            int start;
            cin >> start;
            cout << "Enter ending vertex: ";
            int end;
            cin >> end;
            instance.removeEdge(&start, &end);
            break;
        }
        case 5:{
            cout << "Enter starting vertex: ";
            int start;
            cin >> start;
            cout << "Enter ending vertex: ";
            int end;
            cin >> end;
            if(instance.hasEdge(&start, &end) == true){
                cout << "That edge is in the graph!" << endl;
            }
            else{
                cout << "That egde is not in the graph." << endl;
            }
            break;
        }
        case 6:{
            cout << "Enter the vertex to find the out edges of: ";
            int userVertex;
            cin >> userVertex;
            cout << "Out edges of " << userVertex << ": " << endl;
            instance.outEdges(&userVertex).PrintList();
            break;
        }
        case 7:{
            cout << "Enter the vertex to find the in edges of: ";
            int userVertex;
            cin >> userVertex;
            cout << "In edges of " << userVertex << ": " << endl;
            instance.inEdges(&userVertex).PrintList();
            break;
        }
        case 8:{
            instance.PrintVerticies();
            break;
        }
        case 9:{
            cout << "Enter start value: ";
            int userStart;
            cin >> userStart;
            cout << "Enter end value: ";
            int userEnd;
            cin >> userEnd;
            instance.DFS(&userStart, &userEnd);
            break;
        }
        case 10:{
            cout << "Enter start value: ";
            int userStart;
            cin >> userStart;
            cout << "Enter end value: ";
            int userEnd;
            cin >> userEnd;
            instance.BFS(&userStart, &userEnd);
            break;
        }
        }
    }
    
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