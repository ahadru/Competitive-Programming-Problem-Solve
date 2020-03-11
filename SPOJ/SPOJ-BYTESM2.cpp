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

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int h,w;
        cin>>h>>w;
        int pil[h][w];
        int result[h+1][w];
        for(int i = 0;i<h;i++){
            for(int j = 0;j < w;j++){
                cin>>pil[i][j];
            }
        }
        int r = 0;
        M0(result);
        for(int i = h-1;i>=0;i--){
            for(int j= 0;j<w;j++){
                if(j == 0)
                    result[i][j] = max(result[i+1][j],result[i+1][j+1]) + pil[i][j];
                else if( j == w-1)
                    result[i][j] = max(result[i+1][j-1],result[i+1][j]) + pil[i][j];
                else
                    result[i][j] = max(result[i+1][j-1],max(result[i+1][j],result[i+1][j+1])) + pil[i][j];     

                if(i == 0){
                    r = max(r,result[i][j]);
                }     
            }
        }
        cout<<r<<endl;
    }
    return 0;
}