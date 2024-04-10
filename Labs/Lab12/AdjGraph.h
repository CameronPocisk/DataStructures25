#ifndef ADJGRAPH_H
#define ADJGRAPH_H

#include <iostream>
#include <string>
#include "LinkedListT.h"

using namespace std;

// Each Vertex has the data in the node and and LL of edges.
template <typename T>
class Vertex{
    public:
    T info;
    LL<T> edges; // LL of edges of type T

    Vertex(){}
    Vertex(T in){info = in;}

    operator string() const{
        string asString = string(info);
        return asString; }
};

template <typename T>
class AdjGraph{
    private:
        LL<Vertex<T>> nodes;
    
        Vertex<T> getToTarget(T toFind){ return nodes.GetValue(&toFind); }
        
    public:
        AdjGraph(){
            ; //numIn is starting not neded?
        }


    void addVertex(T toAdd){
        // Node<T>* newNode = new Node<T>(in);
        Vertex<T> asVertex(toAdd);
        // cout << "vertex insert info: " << asVertex.info << endl;
        nodes.InsertEnd(asVertex);

        // cout << "reaching end" << end;
    }

    void RemoveVertex(T toRemove){
        // Make sure to remove all connenctions to this Vertex as wsell
        // Make helper to remove edge from Vertex is present
        for(int i = 0; i < nodes.Length(); i++){
            int curVertex = nodes.GetIndex(i);
            removeEdge(curVertex, toRemove);
        }

        //Once connections are gone, remove from Vertex LL
        nodes.RemoveItem(toRemove); 
    }
    void addEdge(T target, T edge){
        // Get Vetex that we are adding to
        Vertex<T> targetNode = nodes.GetValue(target);
        // Insert edge to LL
        targetNode.edges.InsertEnd(edge);
    }
    void removeEdge(T target, T edge){
        // Get to Vertex that needs removing
        Vertex<T> targetNode = nodes.GetValue(target);
        // Remove the edge from the Vertex
        targetNode.edges.RemoveItem(edge);
    }
    bool hasEdge(T target, T edge){
        // Get to Vertex that needs checking
        Vertex<T> cur = getToTarget(target);

        try{
            cur.edges.GetValue(edge);
            return true; // If it doesnt throw error, return true
        }
        catch(NotFound &e){
            return false;
        }
    }
        
    
    LL<T> outEdges(T target){
        LL<T> hold; //Return list of the edges Vertex has (simple one)
        Vertex<T> current = getToTarget(target);
        for(int i = 0; i < current.edges.Length(); i++) {
            hold.InsertEnd(current.edges.GetIndex(i));
        }

        return hold;
        // Return Vertex's edges
    }
    
    LL<T> inEdges(T target){
        LL<T> hold; // Create the LL to add to
            for (int i = 0; i < nodes.Length(); i++) {
                Vertex<T> current = nodes.GetIndex(i);
                for (int j = 0; j < current.edges.Length(); j++) {
                    if (current.edges.GetIndex(j) == target) {
                        hold.InsertEnd(current.edges.GetIndex(i));
                        break;
                    }
                }
            }
        return hold;
    }
    
    void PrintVerticies(){
        // nodes.PrintList(); // May not work
        for(int i = 0; i < nodes.Length(); i++){
            Vertex<T> hold = nodes.GetIndex(i);
            cout << hold.info << ", ";
        }
        cout << endl;
    }
};





#endif