#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H

// GRAPH TRAVERSAL ITEMS
template <typename T>
class VisitedVertex{
    public:
    T* itsVertex;
    bool visited;
    // T parent; // Will this be needed for the path???
    VisitedVertex(T* dataIn = nullptr){
    // VisitedVertex(T dataIn = nullptr){
        itsVertex = dataIn;
        visited = false;
    }

    bool operator == (VisitedVertex const & RHS){ return *itsVertex == *(RHS.itsVertex); }
    void MarkVisited(){ visited = true; }
    bool WasVisited() { return visited; }
};



// DEPTH FIRST SEARCH
template <typename T>
class Stack{
    private: 
    LL<T> list;

    public:
    void Push(T* in){
        T* asPtr = new T(*in); // deref in
        list.InsertEnd(asPtr); 
    }

    T* Pop(){
        if(IsEmpty()){ throw NotFound(); }
        T* hold = list.GetIndex( list.GetLength()-1 );
        list.RemoveEnd();
        return hold;
    }

    T* Top(){ if(IsEmpty()){throw NotFound();}  return list.GetIndex( list.GetLength()-1 ); }
    bool IsEmpty(){ return list.IsEmpty(); }
    void PrintStack(){ list.PrintList(); }
};


#endif