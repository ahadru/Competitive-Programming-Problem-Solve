#include <bits/stdc++.h>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<"D: "<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<"D: "<<#a<<": "<<a<<","<<#b<<": "<<b<<endl
#define For(i,n) for(__typeof(n)i = 0 ; i < n ; i++)
#define For1(i,n) for(__typeof(n)i = 1 ; i <= n ; i++)
#define ForIT(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define M100 10000000
#define M10 1000000
#define M 100000
#define MS 10000
#define INF INT_MAX
using namespace std;

int l_bi_search(int arr[],int start, int end, int x){
    int mid;
    while(end >= start){
        mid = (end + start)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] > x){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    while(x>arr[mid]){
        mid++;
    }
    return mid;
}

int r_bi_search(int arr[],int start, int end, int x){
    int mid;
    while(end >= start){
        mid = (end + start)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] > x){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    while(x<arr[mid]){
        mid--;
    }
    return mid;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t; 
    scanf("%d",&t);
    int cases = 1;
    while(t--){
        int n, q;
        scanf("%d%d",&n,&q);
        int seq[n+1];
        int temp;
        for(int i = 0; i < n; i++){
            scanf("%d",&temp);
            seq[i] = temp;
        }
        printf("Case %d:\n",cases++);
        while(q--){
            int s,e;
            scanf("%d%d",&s,&e);
            //printf("Pos %d -> %d, Pos %d -> %d\n",s,l_bi_search(seq,0,n-1,s),e,r_bi_search(seq,0,n-1,e));
            int pos_s = l_bi_search(seq,0,n-1,s);
            int pos_e = r_bi_search(seq,0,n-1,e);
            int result = pos_e-pos_s+1;
            if(result < 0){
                printf("%d\n",0);
            }
            else{
                printf("%d\n",result);
            }
            
        }
    }
    return 0;
}