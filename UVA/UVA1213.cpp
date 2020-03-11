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

int primes[1201];
vector<int> prime_set;
int to[1201];

void seive(){
    M1(primes);
    primes[1]= 0;
    for(int p = 2; p<=1200; ++p){
        if(primes[p]){
            prime_set.push_back(p);
            for(int i = p*p; i<= 1200; i+=p){
                primes[i] = 0;
            }
        }
    }
}



int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    seive();
    
    return 0;
}