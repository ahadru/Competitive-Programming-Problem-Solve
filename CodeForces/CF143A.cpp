#include <bits/stdc++.h>
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
bool is_not_equal(int a,int b,int c,int d){
    int arr[] = {0,0,0,0,0,0,0,0,0,0};
    arr[a] = 1;
    arr[b] = 1;
    arr[c] = 1;
    arr[d] = 1;
    if(((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]) < 4) || (arr[0] == 1)){
        return false;
    }   
    else{
        return true;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    int x1,x2,y1,y2;
    y1 = r1 - x1;
    y2 = c2 - y1;
    x2 = r2 - y2;
    bool flag = false;
    for(int i = 1;i < 10; i++ ){
        x1 = i;
        y1 = r1 - x1;
        y2 = c2 - y1;
        x2 = r2 - y2;
        if(d1 == (x1 + y2) && d2 == (y1+x2)){
            if(is_not_equal(x1,y1,x2,y2)){
                flag = true;
                cout<<x1<<" "<<y1<<"\n"<<x2<<" "<<y2<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
    return 0;
}