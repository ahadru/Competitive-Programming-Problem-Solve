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

bool primes[50];
void get_primes(){
    M1(primes);
    primes[1] = false;
    for(int p = 2; p<=50; ++p){
        if(primes[p]){
            for(int i = p*p; i<=50; i += p){
                primes[i] = false;
            }
        }
    }
}

vector<vector<int>> paths;
vector<int> path(17); 
int taken[17];
int N;

void solve(int n,int count){
    path[count] = n;
    if(N == count && primes[1+n]){
        paths.push_back(path);
    }
    for(int i = 2; i <= N; ++i){
        if(!taken[i] && primes[n+i]){
            taken[i] = 1;
            solve(i,count+1);
            taken[i] = 0;   
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    get_primes();
    int t = 0;
    while(scanf("%d", &N) != EOF){
        if (t++) putchar('\n');
        cout<<"Case "<<t<<":"<<endl;
        if(N == 1){
            cout<<1<<endl;
        }
        else if(N%2!=0) continue;
        else{
            taken[1] = 1;
            solve(1,1);
            int paths_size = paths.size();
            for(int i = 0; i < paths_size; ++i){
                for(int j = 1; j <= N; ++j){
                    cout<<paths[i][j];
                    if(j<N){
                        cout<<" ";
                    }
                }
                cout<<endl;
            }
            M0(taken);
            paths.clear();
        }
        
    }
    return 0;
}