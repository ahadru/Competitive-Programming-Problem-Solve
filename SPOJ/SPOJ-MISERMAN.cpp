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
    #define _M 10000000
    #define MS 100000
    using namespace std;

    int main(){
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        int N,M;
        cin>>N>>M;
        int fare[N][M];
        int result[N+1][M];
        for(int i = 0;i<N;i++){
            for(int j = 0;j < M;j++){
                cin>>fare[i][j];
            }
        }
        int r = __INT_MAX__;
        M0(result);
        for(int i = N-1;i>=0;i--){
            for(int j= 0;j<M;j++){
                if(j == 0)
                    result[i][j] = min(result[i+1][j],result[i+1][j+1]) + fare[i][j];
                else if( j == M-1)
                    result[i][j] = min(result[i+1][j-1],result[i+1][j]) + fare[i][j];
                else
                    result[i][j] = min(result[i+1][j-1],min(result[i+1][j],result[i+1][j+1])) + fare[i][j];     

                if(i == 0){
                    r = min(r,result[i][j]);
                }     
            }
        }
        cout<<r<<endl;

        // cout<<"-------\n";
        // for(int i = 0;i<N;i++){
        //     for(int j = 0;j < M;j++){
        //         cout<<fare[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"and\n";
        // for(int i = 0;i<N;i++){
        //     for(int j = 0;j < M;j++){
        //         cout<<result[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return 0;
    }