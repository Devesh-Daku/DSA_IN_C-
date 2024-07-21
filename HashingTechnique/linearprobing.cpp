#include <iostream>
using namespace std;
#define SIZE 10
int hash_(int key){
    return key%SIZE;
}
int probe(int H[] , int key){
    int index = hash_(key);
    int i=0;
    while ( H[(index + i)%SIZE]!=0) i++;
    return (index+i)%SIZE ;
}
void Insert(int H[] , int key){
    int index = hash_(key);
    if(H[index] !=0 ){
        index = probe(H,key);
    }
    H[index] = key;
}
int Search( int H[] , int key){
    int index = hash_(key);
    int i=0; // something is bothering me here 
    while(H[(index+i)%SIZE]) i++;
    return (index+1)%SIZE;
}
int main (){
    int HT[10] = {0};
    Insert(HT ,12);
    Insert(HT ,25);
    Insert(HT ,35);
    Insert(HT ,26);
    cout << Search(HT ,26)<<endl;
    for(int i=0 ; i< SIZE; i++ ) {
        cout << HT[i]<<" ";
    }
    cout << endl;
    return 0;
}