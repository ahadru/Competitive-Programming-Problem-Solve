#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define D(v) cerr<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<v<<","<<#b<<": "<<b<<endl
#define M100 1000000000
#define M10 100000000
#define M 10000000
#define MS 100000
using namespace std;

int ox[1002],nt[1002],wt[1002];
int dp[22][80][801];

int solve(){
    
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int oxs,nts;
        cin>>oxs>>nts;
        int n;
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>ox[i]>>nt[i]>>wt[i];
        }

    }
    return 0;
}