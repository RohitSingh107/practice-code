#include<bits/stdc++.h>
using namespace std;

int visited[7] = {0,0,0,0,0,0,0};
int graph[7][7]= {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void DFS(int i){
    int j;
    cout<<i<<" ";
    visited[i] = 1;
    for(int j = 0; j<7; j++){
        for(int j = 0; j<7; j++){
            if(graph[i][j] == 1 && !visited[j]){
                DFS(j);
            }
        }
    }
}

int main(){

    DFS(2);    
    
    return 0;
}