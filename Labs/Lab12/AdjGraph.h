#ifndef ADJGRAPH_H
#define ADJGRAPH_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "GraphSearch.h"

using namespace std;

// Each Vertex has the data in the node and and LL of edges.
template <typename T>
class Vertex{
    public:
    T* info;
    LL<T> edges; // Pointer to LL of edges of type T

    Vertex(){}
    Vertex(T* in){info = in;}

    operator string() const{
        string asString = string(info);
        return asString; }
    
    bool operator !=(const Vertex<T> &right)const { return info != right.info; }
    bool operator ==(const Vertex<T> &right)const { return info == right.info; }

};

template <typename T>
class AdjGraph{
    private:
        LL<Vertex<T> > nodes; //Pointer to the verticies stored as class Vertex
            
    public:
        AdjGraph(){;}//numIn is starting not neded?

    void addVertex(T* toAdd){
        Vertex<T>* asVertex = new Vertex<T>(toAdd);
        nodes.InsertEnd(asVertex);
    }

    void removeVertex(T* toRemove){
        // Make sure to remove all connenctions to this Vertex as well
        // Make helper to remove edge from Vertex is present

        for(int i = 0; i < nodes.GetLength(); i++){
            Vertex<T>* curVertex = nodes.GetIndex(i); // should be correct syntax
            try{
                removeEdge(curVertex->info, toRemove);
            }
            catch(NotFound &e){}// did not find so do nothing 
        }

        //Once connections are gone, remove from Vertex LL
        Vertex<T>* asVertex = new Vertex<T>(toRemove);
        try{
            nodes.RemoveItem(asVertex);
        }catch(NotFound &e){
            cerr << e.what() << endl;
        }
    }

    void addEdge(T* target, T* edge){
        // Get Vetex that we are adding to
        Vertex<T>* asVertex = new Vertex<T>(target);

        Vertex<T>* targetNode = nodes.GetValue(asVertex);
        // Insert edge to LL
        targetNode->edges.InsertEnd(edge);
        // delete asVertex;
        // cout << "Bruh"<< *targetNode->edges->GetValue(edge) << endl;
    }
    
    void removeEdge(T* target, T* edge){
        // Get to Vertex that needs removing
        Vertex<T>* asVertex = new Vertex<T>(target);
        Vertex<T>* targetNode = nodes.GetValue(asVertex);
        // Remove the edge from the Vertex
        targetNode->edges.RemoveItem(edge); //Throws Not Found if not found

        delete asVertex;
    }

    bool hasEdge(T* target, T* edge){
        // Get to Vertex that needs checking
        Vertex<T>* asVertex = new Vertex<T>(target);
        Vertex<T>* cur = nodes.GetValue(asVertex);

        try{
            cur->edges.GetValue(edge);
            return true; // If it doesnt throw error, return true
        }
        catch(NotFound &e){
            return false;
        }
    }
        
    
    LL<T> outEdges(T* target){
        LL<T> hold; //Return list of the edges Vertex has (simple one)
        Vertex<T>* asVertex = new Vertex<T>(target);
        Vertex<T>* current = nodes.GetValue(asVertex);
        for(int i = 0; i < current->edges.GetLength(); i++) {
            hold.InsertEnd(current->edges.GetIndex(i));
        }

        return hold;
        // Return Vertex's edges
    }
    
    LL<T> inEdges(T* target){
        LL<T> hold; // Create the LL to add to
            for (int i = 0; i < nodes.GetLength(); i++) {
                Vertex<T>* current = nodes.GetIndex(i);
                for (int j = 0; j < current->edges.GetLength(); j++) {
                    if (current->edges.GetIndex(j) == target) {
                        hold.InsertEnd(current->edges.GetIndex(i));
                        break;
                    }
                }
            }
        return hold;
    }
    
    void PrintVerticies(){
        // nodes.PrintList(); // May not work
        for(int i = 0; i < nodes.GetLength(); i++){
            Vertex<T>* hold = nodes.GetIndex(i);
            cout << *(hold->info) << ", ";
        }
        cout << endl;

        // for(int i = 0; i < nodes.GetLength(); i++){   //For printing it like how they tell us to (dont know if it works)
        //     Vertex<T> hold = nodes.GetIndex(i);
        //     cout << hold.info;
        //     for(int j = 0; j < hold.edges.GetLength(); j++){
        //         Vertex<T> holdEdge = hold.edges.GetIndex(j);
        //         cout << " -> " << holdEdge.info;
        //     }
        //     cout << endl;
        // }
    }

    void DFS(T* startVal, T* targetVal){
        cout << "Printing DFS order from " << *startVal << " to " << *targetVal << endl;

        // Get to starting Veretx
        Vertex<T>* asVertex = new Vertex<T>(startVal);
        Vertex<T>* curNode = nodes.GetValue(asVertex);

        cout << "got starting node: " << *(curNode->info) << endl;
        cout << "Edges are "; curNode->edges.PrintList(); cout << endl;

        // Make a stack of the verticies with data on seen or not
        Stack< VisitedVertex< Vertex<T> > > visitedStack;


        VisitedVertex<Vertex<T> > curVisited(curNode);
        curVisited.MarkVisited();

        visitedStack.Push(&curVisited);

        cout << "Top of stack: " << *(visitedStack.Top()->itsVertex->info) << endl;

        while(!visitedStack.IsEmpty() && *(visitedStack.Top()->itsVertex->info) != *targetVal){

            // Pop current node and mark as visited
            VisitedVertex<Vertex<T> >* loopVisited = visitedStack.Pop();
            loopVisited->MarkVisited();
            
            // Push all non visited children onto the stack
            // 
            break;
        }
        

        cout << "Out of while, curnode info: " << *(curNode->info) << endl;
        

    }
};



#endif