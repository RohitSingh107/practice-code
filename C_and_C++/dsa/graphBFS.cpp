#include<bits/stdc++.h>
using namespace std;

class Graph{
    int numVertices;
    list<int> * adjLists;
    vector<bool> visited;
    public:
        Graph(int vertices){
            numVertices = vertices;
            adjLists = new list<int>[vertices];
        }

        void addEdge(int u, int v){
            adjLists[u].push_back(v);
            adjLists[v].push_back(u);
        }

        void BFS(int src){
            // visited = new bool[numVertices];
            visited.assign(numVertices, false);
            list<int> queue;

            visited[src] = true;
            queue.push_back(src);
            list<int>::iterator i;
            while(!queue.empty()){
                int currVertex = queue.front();
                cout<<currVertex<<" ";
                queue.pop_front();

                for(i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i){
                    int adjVertex = *i;
                    if(!visited[adjVertex]){
                        visited[adjVertex] = true;
                        queue.push_back(adjVertex);
                    }
                }
            }
        }
};

int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.addEdge(3,0);
    g.addEdge(4,2);

    g.BFS(2);
    
    return 0;
}