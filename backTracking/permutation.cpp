#include<iostream>
using namespace std;

void Perm(char s[] , int k){
    static int A[10] = {0};
    static char Res[10] ;
    if(s[k]=='\0') {
        Res[k] = '\0';
        for(int i=0 ; i< 3; i++ ) {
            cout<<s[i] << " ";
        }
        cout << endl;
    }
    else {
        
        for(int i=0 ; s[i]='\0' ; i++ ) {       
            if(A[i]==0){    
                Res[k] = s[i];   
                A[i] = 1;     
                Perm(s,k+1);     
                A[i] = 0;
            }    
        }
    }
}

int main (){
    char c[] = {'a' , 'b' , 'c'};
    Perm( c , 0);
    return 0;
}