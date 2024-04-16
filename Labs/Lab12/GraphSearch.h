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

// QUEUE FOR BFS
template <typename T>
class Queue{
    private:
        LL<T> data;

    public:
        void Enqueue(T* in){
            data.InsertEnd(in);
        }

        T* Dequeue(){
        if(data.IsEmpty()) {
            throw UnderflowError();
        }
        T* hold = data.GetIndex(0);
        data.RemoveFront();
        return hold;
        }

        // bool IsFull(){return index >= 52;}
        bool IsEmpty(){return data.IsEmpty();}
        void PrintQueue(){ data.PrintList();}
};

#endif