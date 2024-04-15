#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H

// GRAPH TRAVERSAL ITEMS
template <typename T>
class VisitedVertex{
    public:
    T* data;
    bool visited;
    // T parent; // Will this be needed for the path???

    VisitedVertex(T* dataIn = nullptr){
    // VisitedVertex(T dataIn = nullptr){
        data = dataIn;
        visited = false;
    }
    bool operator == (VisitedVertex const & RHS){ return *data == *(RHS.data); }
    void MarkVisited(){ visited = true; }
    bool WasVisited() { return visited; }
};



// DEPTH FIRST SEARCH
template <typename T>
class Stack{
    private: 
    LL<T> data;

    public:
    void Push(T* in){
        T* asPtr = new T(in);
        data.InsertEnd(asPtr); 
    }
    T* Pop(){
        if(IsEmpty()){ throw NotFound(); }
        T* hold = data.GetIndex( data.GetLength()-1 );
        data.RemoveItem(hold);
        return hold;
    }

    T* Top(){ if(IsEmpty()){throw NotFound();}  return data.GetIndex(data.length()); }
    bool IsEmpty(){ return data.IsEmpty(); }
    void PrintStack(){ data.PrintList(); }
};


#endif