#include <bits/stdc++.h>
using namespace std;
 
int gx[] = {-1,0,1,0};
int gy[] = {0,1,0,-1};
 
char grid[1005][1005];
int visited[1005][1005];
int *result[1005][1005];

int* count__(pair<int,int> s,int xb,int yb){
    int *count_c = (int*)malloc(sizeof(int));
    int c = 0;
    queue< pair<int,int> > q;
    q.push(s);
    visited[s.first][s.second] = 1;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        if(grid[x][y] == 'C'){
            c++;
        }
        result[x][y] = count_c;
        for(int i = 0;i<4;i++){
            if(visited[x+gx[i]][y+gy[i]] == 0 && x+gx[i] >= 0 && x+gx[i] < xb && y+gy[i] >= 0 && y+gy[i] < yb && grid[x+gx[i]][y+gy[i]] != '#'){
                q.push({x+gx[i],y+gy[i]});
                visited[x+gx[i]][y+gy[i]] = 1;
            }
        }
    }
    *count_c = c;
    return count_c;
}
 
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int cases = 1;
    while(t--){
        int x,y,q;
        cin>>x>>y>>q;
        for(int i = 0;i<x;i++){
            for(int j = 0;j < y; j++){
                cin>>grid[i][j];
            }
        }
        printf("Case %d:\n",cases++);
        for(int i = 0;i < q; i++){
            int sx,sy;
            cin>>sx>>sy;
            if(grid[sx-1][sy-1] == '#'){
                int c = 0;
                for(int i = 0;i<4;i++){
                    int xx = sx-1+gx[i];
                    int yy = sy-1+gy[i];
                    if(xx>=0 && xx < x && yy >= 0 && yy < y && grid[xx][yy] != '#'){
                        if(visited[xx][yy] == 1){
                            c += *result[xx][yy];
                        }
                        else{
                            result[sx-1][sy-1] = count__({sx-1,sy-1},x,y);
                            cout<<*result[sx-1][sy-1]<<endl;
                        }
                    }
                }
            }
            else{
                if(visited[sx-1][sy-1] == 1){
                    cout<<*result[sx-1][sy-1]<<endl;
                }
                else{
                    result[sx-1][sy-1] = count__({sx-1,sy-1},x,y);
                    cout<<*result[sx-1][sy-1]<<endl;
                }
            }
        }
        memset(visited,0,sizeof visited);
    }
    return 0;
}
