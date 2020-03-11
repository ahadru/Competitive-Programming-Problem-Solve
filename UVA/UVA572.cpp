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

int gx[] = {-1,-1,-1,0,+1,+1,+1,0};
int gy[] = {-1,0,+1,+1,+1,0,-1,-1};

char grid[102][102];
int visited[102][102];
int m,n;

void fill(int i,int j){
    if(grid[i][j] == '*' || visited[i][j] == 1){
        return;
    }
    else{
        visited[i][j] = 1;
        if(i+gx[0]>=0 && i+gx[0]<m && j+gy[0]>=0&&j+gy[0]<n){
            fill(i+gx[0],j+gy[0]);
        }
        if(i+gx[1]>=0 && i+gx[1]<m && j+gy[1]>=0&&j+gy[1]<n){
            fill(i+gx[1],j+gy[1]);
        }
        if(i+gx[2]>=0 && i+gx[2]<m && j+gy[2]>=0&&j+gy[2]<n){
            fill(i+gx[2],j+gy[2]);
        }
        if(i+gx[3]>=0 && i+gx[3]<m && j+gy[3]>=0&&j+gy[3]<n){
            fill(i+gx[3],j+gy[3]);
        }
        if(i+gx[4]>=0 && i+gx[4]<m && j+gy[4]>=0&&j+gy[4]<n){
            fill(i+gx[4],j+gy[4]);
        }
        if(i+gx[5]>=0 && i+gx[5]<m && j+gy[5]>=0&&j+gy[5]<n){
            fill(i+gx[5],j+gy[5]);
        }
        if(i+gx[6]>=0 && i+gx[6]<m && j+gy[6]>=0&&j+gy[6]<n){
            fill(i+gx[6],j+gy[6]);
        }
        if(i+gx[7]>=0 && i+gx[7]<m && j+gy[7]>=0&&j+gy[7]<n){
            fill(i+gx[7],j+gy[7]);
        }
    }
}

int flood_fill(){
    int count = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j] == '@' && visited[i][j] == 0){
                fill(i,j);
                count++;
            }
        }
    }
    return count;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(1){
        cin>>m>>n;
        M0(visited);
        if(m == 0)break;
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>grid[i][j];
            }
        }
        cout<<flood_fill()<<endl;

    }
    return 0;
}