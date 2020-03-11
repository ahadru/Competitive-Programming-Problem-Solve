#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <list>
#include <set>
#define M0(a) memset(a, 0, sizeof a)
#define M1(a) memset(a, 1, sizeof a)
#define M1_(a) memset(a, -1, sizeof a)
#define D(v) cerr << #v << ": " << v << endl
#define D2(a, b) cerr << #a << ": " << v << "," << #b << ": " << b << endl
#define M100 1000000000
#define M10 100000000
#define M 10000000
#define MS 100000
using namespace std;
vector<int>adj[100000];
vector<int>bridge[100000];
bool visited[100000];
int disc[100000],fin[100000],low[100000],child[100000],parent[100000],tim=0;
int nodes[100000]={0},cnt=0,total=0;
set<int>st;
void dfs(int s)
{
    visited[s]=true;
    tim++;
    disc[s]=tim;
    low[s]=disc[s];
    for(int i=0;i<adj[s].size();i++){
        int x=adj[s][i];
        if(!visited[x]){
            parent[x]=s;
            child[s]++;
            dfs(x);
            if(low[x]>disc[s]){
                int u,v;
                u=min(x,s);
                v=max(x,s);
                bridge[u].push_back(v);
                total++;
            }
            low[s]=min(low[x],low[s]);
        }
        else if(x!=parent[s]){
            if(disc[x]<low[s]) low[s]=disc[x];
        }
    }
}
int power(int x,int y)
{
   int n=1,i;
   for(i=0;i<y;i++)
      n*=x;
   return n;
}
int toInteger(string s)
{
    int num=0,i,l,x;
    l=s.size();
    for(i=0;i<l;i++){
        x=s[i]-48;
        num+=x*power(10,l-i-1);
    }
    return num;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n,i,j,u,v,k,l;
    string blnk;
    char s[100];
    cin>>t;
    for(i=1;i<=t;i++){
        getline(cin,blnk);
        cin>>n;
        memset(visited,0,sizeof(visited));
        memset(low,-1,sizeof(low));
        memset(disc,0,sizeof(disc));
        memset(child,0,sizeof(child));
        memset(parent,-1,sizeof(parent));
        st.clear();
        tim=0,total=0;
        for(j=0;j<n+10;j++)
            adj[j].clear();
        for(j=0;j<n+10;j++)
            bridge[j].clear();

        for(j=0;j<n;j++){
            cin>>u;
            cin>>s;
            char *token=strtok(s,"( )");
            k=toInteger(token);
            for(l=0;l<k;l++){
                cin>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for(j=0;j<n;j++){
            if(!visited[j])
                dfs(j);
        }
        for(j=0;j<n;j++)
            sort(bridge[j].begin(),bridge[j].end());
        printf("Case %d:\n",i);
        printf("%d critical links\n",total);
        for(j=0;j<n;j++){
            if(bridge[j].size()>0){
                for(k=0;k<bridge[j].size();k++)
                    printf("%d - %d\n",j,bridge[j][k]);
            }
        }
    }
    return 0;
}