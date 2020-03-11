#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <list>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<v<<","<<#b<<": "<<b<<endl
#define M100 1000000000
#define M10 100000000
#define M 10000000
#define MS 100000
using namespace std;
#define NIL -1

bool visited[100000];
int disc[100000];
int low[100000];
int parent[100000];
bool ap[100000];

class Graph{
    int V;
    list<int> *adj;
public:
    int AP_N = 0;
    Graph(int v){
        V = v;
        adj = new list<int>[v+1];
    }
    void AP(int u,bool visited[],int disc[],int low[],int parent[],bool ap[]);
    void add_edge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void Graph::AP(int u,bool visited[],int disc[],int low[],int parent[],bool ap[]){
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u]=low[u] = ++time;

    list<int>::iterator i;
    for(i = adj[u].begin();i != adj[u].end();i++){
        int v = *i;
        if(!visited[v]){
            children++;
            parent[v] = u;
            AP(v,visited,disc,low,parent,ap);

            low[u] = min(low[u],low[v]);

            if(parent[u] == NIL &&  children > 1){
                if(!ap[u]){
                    ap[u] = true;
                    AP_N++;
                }
            }
            if(parent[u] != NIL && low[v] >= disc[u]){
                if(!ap[u]){
                    ap[u] = true;
                    AP_N++;
                }
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u],disc[v]);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cases = 1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        Graph g(n);
        for(int i = 0;i < m; i++){
            int u,v;
            cin>>u>>v;
            g.add_edge(u,v);
        }
        M0(visited);
        M1_(disc);
        M1_(low);
        M1_(parent);
        M0(ap);
        for(int i = 1;i <= n; i++){
            if(!visited[i]){
                g.AP(i,visited,disc,low,parent,ap);
            }
        }
        printf("Case %d: %d\n",cases++,g.AP_N);
    }
    return 0;
}