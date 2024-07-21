#include "./linkedList.h"
#define HASHKEY 10

class HeapChain : public LinkedList {
    private: 
        LinkedList L[HASHKEY];
        int hash_(int key){return key%HASHKEY;}
    public :
        void InsertChain(int);
        void SearchChain(int);
};
void HeapChain :: InsertChain( int key){
    int index = hash_(key);
    L[index].InsertSortedList(key);
}
void HeapChain :: SearchChain( int key){
    int index = hash_(key) ;
    Node*p = L[index].first;
    while(p){
        if(p->data >= key ) break;
        p = p->next;
    }
    if(p && p->data == key ) {
        cout << "key found"<< endl;
    }
    else {
        cout << "key not found" << endl;
    }
}
int main (){
    HeapChain H ;    
    H.InsertChain(12 );
    H.InsertChain(122);
    H.InsertChain(42 );
    H.SearchChain(132);
    return 0;
}
