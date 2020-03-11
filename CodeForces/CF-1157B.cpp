#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <string.h>
#define M0(a) memset(a, 0, sizeof a)
#define M1(a) memset(a, 1, sizeof a)
#define M1_(a) memset(a, -1, sizeof a)
#define D(v) cerr << #v << ": " << v << endl
#define D2(a, b) cerr << #a << ": " << a << "," << #b << ": " << b << endl
#define M100 1000000000
#define M10 100000000
#define M 10000000
#define MS 100000
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    string a;
    cin >> a;
    int f[10];
    for (int i = 1; i <= 9; i++){
        cin >> f[i];
    }
    for(int  i = 0; i < n; i++){
        if(f[a[i] - '0'] > (a[i]-'0')){
            while(i < n && f[a[i] - '0'] >= (a[i]-'0')){
                a[i] = f[a[i]-'0'] + '0';
                i++;
            }
            break;
        }
    }
    cout<<a<<endl;
    return 0;
}