#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define D(v) cerr<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<v<<","<<#b<<": "<<b<<endl
#define M100 1000000000
#define M10 100000000
#define M 10000000
#define MS 100000
using namespace std;

int h;
vector<int> houses[25];
int dp[25][3];

int solve(int n,int col){
    if(n == h){
        return 0;
    }
    if(dp[n][col]>0){
        return dp[n][col];
    }
    else{
        int w1,w2;
        if(col == 0){
            w1 = solve(n+1,1) + houses[n][col];
            w2 = solve(n+1,2) + houses[n][col];
        }
        else if(col == 1){
            w1 = solve(n+1,0) + houses[n][col];
            w2 = solve(n+1,2) + houses[n][col];
        }
        else{
            w1 = solve(n+1,0) + houses[n][col];
            w2 = solve(n+1,1) + houses[n][col];
        }
        return dp[n][col] = min(w1,w2);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cases = 1;
    cin>>n;
    while(n--){
        cin>>h;
        for(int i = 0;i<h;i++){
            int a,b,c;
            cin>>a>>b>>c;
            houses[i] = {a,b,c};
        }
        M0(dp);   
        printf("Case %d: ",cases++);
        cout<<min(min(solve(0,0),solve(0,1)),solve(0,2))<<endl;
    }
    return 0;
}