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
    instance.addVertex(&one);
    instance.addVertex(&two);
    instance.addVertex(&three);
    instance.addVertex(&four);
    instance.addEdge(&three, &five);
    instance.addEdge(&one, &two);
    instance.addEdge(&one, &three);
    // Vertex<int> i = instance.nodes.GetIndex(1);
    // cout << "hi" << endl;
    // cout << i.info << endl;
    instance.PrintVerticies();

    // instance.addEdge(1, 3);


    cout << "Ones edges: "; (instance.outEdges(&one)).PrintList(); cout << endl;
    cout << "Length of edges " << (instance.outEdges(&one)).Length(); cout << endl;
    cout << "One has two edge: " << instance.hasEdge(&one, &two) << endl;
    cout << "One has five edge: " << instance.hasEdge(&one, &five) << endl;

    instance.removeVertex(&two);
    cout << endl << "Removed vertex two: " << endl; 
    cout << "One has two edge: " << instance.hasEdge(&one, &two) << endl;
    instance.removeVertex(&one);
    cout << endl << "Removed vertex one: " << endl; 

    instance.removeVertex(&five);
    cout << endl << "Removed vertex five: " << endl; 

    instance.PrintVerticies();
    
    // LL<int> tester;
    // tester.InsertEnd(5);
    // tester.PrintListr();
    
    
//     int userChoice = 0;
    
//     while(userChoice != 9){
//         cout << "Press 1 to add a vertex to graph." << endl;
//         cout << "Press 2 to remove a vertex from graph." << endl;
//         cout << "Press 3 to add an edge to graph." << endl;
//         cout << "Press 4 to remove an edge from graph." << endl;
//         cout << "Press 5 to find an edge in graph." << endl;
//         cout << "Press 6 to find out edges of a vertex." << endl;
//         cout << "Press 7 to find in edges of a vertex." << endl;
//         cout << "Press 8 to print adjacency list." << endl;
//         cout << "Press 9 to quit." << endl;
//         cin >> userChoice;
//         while(userChoice < 1 || userChoice > 9){
//             cout << "Please enter a number 1-9: ";
//             cin >> userChoice;
//         }

//         switch (userChoice)
//         {
//         case 1:{
//             cout << "Enter vertex to add: ";
//             int vertexAdd;
//             cin >> vertexAdd;
//             instance.addVertex(&vertexAdd);
//             break;
//         }
//         case 2:{
//             cout << "Enter vertex to remove: ";
//             int vertexRemove;
//             cin >> vertexRemove;
//             instance.RemoveVertex(&vertexRemove);
//             break;
//         }
//         case 3:{
//             cout << "Enter starting vertex: ";
//             int start;
//             cin >> start;
//             cout << "Enter ending vertex: ";
//             int end;
//             cin >> end;
//             instance.addEdge(start, end);
//             break;
//         }
//         case 4:{
//             cout << "Enter starting vertex: ";
//             int start;
//             cin >> start;
//             cout << "Enter ending vertex: ";
//             int end;
//             cin >> end;
//             instance.removeEdge(start, end);
//             break;
//         }
//         case 5:{
//             cout << "Enter starting vertex: ";
//             int start;
//             cin >> start;
//             cout << "Enter ending vertex: ";
//             int end;
//             cin >> end;
//             if(instance.hasEdge(start, end) == true){
//                 cout << "That edge is in the graph!" << endl;
//             }
//             else{
//                 cout << "That egde is not in the graph." << endl;
//             }
//             break;
//         }
//         case 6:{
//             cout << "Enter the vertex to find the out edges of: ";
//             int userVertex;
//             cin >> userVertex;
//             cout << "Out edges of " << userVertex << ": " << endl;
//             instance.outEdges(userVertex).PrintList();
//             break;
//         }
//         case 7:{
//             cout << "Enter the vertex to find the in edges of: ";
//             int userVertex;
//             cin >> userVertex;
//             cout << "In edges of " << userVertex << ": " << endl;
//             instance.inEdges(userVertex).PrintList();
//             break;
//         }
//         case 8:{
//             instance.PrintVerticies();
//             break;
//         }
//         }
//     }
    
//     cout << endl << "Ending program..." << endl;
//     return 0;
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