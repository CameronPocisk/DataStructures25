#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H

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