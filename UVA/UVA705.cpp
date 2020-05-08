#include <bits/stdc++.h>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<"D: "<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<"D: "<<#a<<": "<<a<<","<<#b<<": "<<b<<endl
#define For(i,n) for(__typeof(n)i = 0 ; i < n ; i++)
#define For1(i,n) for(__typeof(n)i = 1 ; i <= n ; i++)
#define ForIT(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define M100 10000000
#define M10 1000000
#define M 100000
#define MS 10000
using namespace std;

int fx[] = {-1,-1,0,1,1,1,0,-1};
int fy[] = {0,1,1,1,0,-1,-1,-1};

string grid[26];
int visited[26][26];

int dim;

void bfs(pair<int,int> pos){
    queue<pair<int,int>> q;
    visited[pos.first][pos.second] = 1;
    q.push(pos);
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        int x = u.first, y = u.second;
		int xx,yy;
        for(int i = 0; i < 8; i++){
			xx = x+fx[i];
			yy = y+fy[i];
            if(xx >= 0 && xx < dim && yy >= 0 && yy < dim && grid[xx][yy] == '1' && visited[xx][yy] == 0){
                visited[xx][yy] = 1;
                q.push({xx,yy});
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int c = 0;
    while(cin>>dim){
        c++;
        for(int i = 0; i < dim; i++){
            cin>>grid[i];
        }
        //cout<<"Input Done\n";
        int result = 0;
        M0(visited);
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
				//cout<<"{"<<i<<","<<j<<" "<<grid[i][j]<<"}";
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    //cout<<"c\n";
                    bfs({i,j});
                    result++;
                }
            }
			//cout<<endl;
        }
        printf("Image number %d contains %d war eagles.\n",c,result);
    }
    return 0;
}