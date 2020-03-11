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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cases = 1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        set< pair<int,int> > set1;
        for(int i = 1;i<=n;i++){
            int id;
            scanf("%d",&id);
            set1.insert({i,id});
        }
        set<pair<int,int>>::iterator it = set1.begin();
        for(int i = 0; i<q;i++){
            char ch;
            int tmp;
            scanf("%c%d",&ch,&tmp);
            if(ch == 'c'){
                cout<<it;
                pair<int,int> p =  
            }
            else{

            }
        }
    }
    return 0;
}