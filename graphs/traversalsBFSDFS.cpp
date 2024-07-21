#include<iostream>
using namespace std;
#include<queue>

void BFS( int G[][7] , int start , int n){
    int i = start , j;
    queue<int> q;
    int visited[7] = {0};
    cout << i << endl;
    visited[i] = 1;
    q.push(i);

    while(!q.empty()){
        i = q.front();
        q.pop();
        for(j=1 ; j< n; j++ ) {
            if(G[i][j]==1 && visited[j]==0){
                cout << j << endl;
                visited[j]=1;
                q.push(j);
            }
        }
    }
}
void DFS( int G[][7] , int start , int n){
    static int visited[7] = {0}; 
    if(visited[start]==0){
        cout << start << endl;
        visited[start] =1 ;
        for(int i=1 ; i< n; i++ ) {
            if(G[start][i] == 1 && visited[i]==0) DFS( G ,  i ,  n);
        }
    }
}
int main () {
    int G[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    DFS(G,1,7);

    return 0;
}