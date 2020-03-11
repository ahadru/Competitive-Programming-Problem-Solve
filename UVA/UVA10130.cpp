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

int knapsack(vector<int> val,vector<int> wt,int W){
    int DP[val.size()+1][W+1];
    for(int i=0; i<=val.size();i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0){
                DP[i][j] = 0;
                continue;
            }
            if(j >= wt[i-1]){
                DP[i][j] = max(DP[i-1][j], val[i-1] + DP[i-1][j - wt[i-1]]);
            }
            else{
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    return DP[val.size()][W];
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
     while(t--){
         int n;
         cin>>n;
         vector<int> val;
         vector<int> wt;
         for(int i = 0;i<n;i++){
             int p,w;
             cin>>p>>w;
             val.push_back(p);
             wt.push_back(w);
         }
         int m;
         cin>>m;
         int result = 0;
         int m_wt;
         while(m--){
             cin>>m_wt;
             result += knapsack(val,wt,m_wt);
         }
         cout<<result<<endl;
     }
    return 0;
}