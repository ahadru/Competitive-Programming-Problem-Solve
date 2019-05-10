#include <bits/stdc++.h>
using namespace std;

//Varible decalaration.......

void seg_sieve(int x,int y){
    int sq = (int)sqrt(y);
    int status[sq + 1];
    memset(status,0,sizeof(status));
    int primes[sq + 1];

    for(int i=4;i<=sq + 1; i+=2){
        status[i] = 1;
    }
    int j = 1;
    primes[0] = 2;
    for(int i=3;i<=sq + 1; i+=2){
        if(!status[i]){
            primes[j] = i;
            j++;
            for(int j = i*i;j<=sq + 1;j+=i){
                status[j] = 1;
            }
        }
    }
    status[1]=1;

    //printing primes
    //calculating prime segmentwise
    int dif = y - x +1;
    int solve_prime[dif];
    memset(solve_prime,0,sizeof(solve_prime));
    for(int k = 0; k < j; k++){
        int div = (x / primes[k]) * primes[k];
        while(div <= y){
            if(div >= x && div != primes[k]){
                solve_prime[div - x] = 1;
            }

            div += primes[k];
        }
    }

    for(int i = 0; i < dif; i++){
        if(solve_prime[i] == 0 & (i + x) != 1){
            cout<<i + x<<endl;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        seg_sieve(x,y);
    }
    return 0;
}
