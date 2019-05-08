#include <bits/stdc++.h>
using namespace std;

//Varible decalaration.......

bool status[100000000];

void sieve(){
    int N = 100000000;
    int sq = (int)sqrt(N);
    for(int i=4;i<=N;i+=2){
        status[i] = 1;
    } 
    for(int i = 3; i<=sq+2; i+=2){
        if(!status[i]){
            for(int j = i*i;j<=N; j+=i){
                status[j] = 1;
            }
        }
    }
    int c = 1;
    cout<<2<<endl;
    for(int i = 3;i<=N;i+=2){
        if(!status[i]){
            c++;
            if(c%100 == 1){
                cout<<i<<endl;
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();

    return 0;
}