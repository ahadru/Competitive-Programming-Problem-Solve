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

bool subset[25][100];
bool taken[25];

int is_possible(int set[],int n,int sum){
    M0(taken);
    M0(subset);
    int set_2[n];
    for(int i = 0; i<= n; i++){
        subset[i][0] = true;
        if(i < n){
            set_2[n-i-1] = set[i];
        }
    }
    //sort(set,set+n);
    // For(i,n) cout<<set_2[i]<<" ";
    // cout<<endl;
    for(int i = 1; i<= sum; i++){
        subset[0][i] = false;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sum; j++){
            if(j < set_2[i-1]){
                subset[i][j] = subset[i-1][j];
            }
            else{
                subset[i][j] = subset[i-1][j] || subset[i-1][j-set_2[i-1]];
            }
        } 
    } 


    cout<<"  ";
    for(int i = 0;i<=sum;i++) printf("%4d", i);
    cout<<endl;
    for (int i = 0; i <= n; i++) { 
        if(i > 0) cout<<set_2[i-1]<<" ";
        else cout<<"  ";
        for (int j = 0; j <= sum; j++) 
            printf ("%4d", subset[i][j]); 
        printf("\n"); 
	}


    int result = 0;
    for(int i = sum; i>0;i--){
        if(subset[n][i]){
            result = i;
            break;
        }
    }
    int i = n,j = result;
    //D2(i,j);
    while(i != 0){
        if(subset[i-1][j] == 0){
            taken[set_2[i-1]] = 1;
            i--;j -= set_2[i];
            //cout<<"1if"<<endl;
        }
        else if(j >= set_2[i-1] && subset[i][j-set_2[i-1]]){
            taken[set_2[i-1]] = 1;
            i--;j -= set_2[i];
            //cout<<"2if"<<endl;
        }
        else{
            i--;
            //cout<<"else\n";
        }
    }
    return result;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int sum;
    while(cin>>sum){
        int n;
        cin>>n;
        int set[n];
        for(int i = 0;i<n;i++){
            cin>>set[i];
        }
        int result = is_possible(set,n,sum);
        for(int i = 0;i<n;i++){
            if(taken[set[i]]) cout<<set[i]<<" ";
        }
        cout<<"sum:"<<result<<endl;
    }
    return 0;
}