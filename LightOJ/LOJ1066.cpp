#include <bits/stdc++.h>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<a<<","<<#b<<": "<<b<<endl
#define For(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define ForIT(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define M100 10000000
#define M10 1000000
#define M 100000
#define MS 10000
using namespace std;

int fx[] = {-1,0,1,0};
int fy[] = {0,1,0,-1};
char grid[12][12];
int visited[12][12];

int dfs(int x1,int y1,int x2,int y2){
    if(grid[x1][y1] == '.' || ){
        for(int i = 0;i<3; ++i){
            if(visited[x1+fx[i]][y1+fy[i]] == 0 && grid[x1+fx[i]][y1+fy[i]] == '.'){
                int c = dfs(x1+fx[i],y1+fy[i],x2,y2);
            }
        }
    }

}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int cases = 1;
    while(t--){
        int n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin>>grid[i][j];
            }
        }

    }
    return 0;
}