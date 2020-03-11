#include <bits/stdc++.h>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<a<<","<<#b<<": "<<b<<endl
#define For(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define ForIT(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define M100 10000005
#define M10 1000005
#define M 100005
#define MS 10005
using namespace std;

bool primes[M10+1];

void sieve(){
    M1(primes);
    for(int p = 2; p*p<=M10; p++){
        if(primes[p]){
            for(int i = p*p; i<=M10; i+=p){
                primes[i] = false;
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    primes[1] = false;
    int n;
    cin>>n;
    while(n--){
        long long int x;
        cin>>x;
        long long int p = sqrt(x);
        if(primes[p] && p*p == x){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}