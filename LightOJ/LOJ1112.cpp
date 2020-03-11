// 1112 - Curious Robin Hood
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <iterator>
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<a<<","<<#b<<": "<<b<<endl
#define M100 1000000000
#define M10 100000000
#define M 10000000
#define MS 100000
using namespace std;

int tree[MS];
int arr[MS];
int MaxIdx;

int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx,int value){
    while(idx<=MaxIdx){
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cases = 1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        MaxIdx = n; 
        M0(tree);
        for(int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
			update(i, arr[i]);
		}
        int status;
        printf("Case %d:\n",cases++);
        while(q--){
            scanf("%d",&status);
            if(status == 1){
                int idx;
                scanf("%d",&idx); idx++;
                printf("%d\n",arr[idx]);
                update(idx,-arr[idx]);
                arr[idx] = 0;
            }
            else if(status == 2){
                int idx,val;
                scanf("%d%d",&idx,&val); idx++;
                update(idx,val);
                arr[idx] += val;
            }
            else{
                int i,j;
                scanf("%d%d",&i,&j); j++;
                printf("%d\n",read(j)-read(i));
            }
        }
    }
    return 0;
}