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
    char week[] = {'R','F','F','R','C','F','C'};
    int f,r,c;
    cin>>f>>r>>c;
    int rationalf = ((float)2/3) * f;
    int result = 0,weeks;
    //cout<<"    "<<rationalf<<" "<<r<<" "<<c<<endl;
    if(rationalf<=r && rationalf<=c){
        weeks = (f/3); 
    }
    else if(r<rationalf && r<c){
        weeks = (r/2); 
    }
    else{
        weeks = (c/2);
    }
    f -= weeks*3;
    r -= weeks*2;
    c -= weeks*2;
    result = weeks*7;
    //D(result);
    int weekStart;
    int r_tmp = 0;
    int r_tmp2 = 0;
    int fc,rc,cc;
    bool flag;
    for(int i = 0;i<7;i++){
        weekStart = i;
        r_tmp2 = 0;
        fc = f;
        rc = r;
        cc = c;
        flag = false;
        for(int j = 0;j<7;j++){
            switch (week[weekStart]){
            case 'F':
                if(fc == 0) flag = true;
                fc--;
                break;
            case 'R':
                if(rc == 0) flag = true;
                rc--;
                break;
            case 'C':
                if(cc == 0) flag = true;
                cc--;
                break;
            default:
                break;
            }
            if(flag) break;
            r_tmp2++;
            weekStart++;
            weekStart = weekStart%7;
        }
        r_tmp = max(r_tmp,r_tmp2);
        //D(r_tmp);
    }
    cout<<result+r_tmp<<endl;
    return 0;
}