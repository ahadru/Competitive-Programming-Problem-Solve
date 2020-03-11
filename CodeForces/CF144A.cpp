#include <bits/stdc++.h>
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
    int data;
    int m, l, max__ = 0, min__ = 101;
    for (int i = 0; i < n; i++){
        cin >> data;
        if (data > max__){
            max__ = data;
            m = i;
        }
        if (data <= min__){
            min__ = data;
            l = i;
        }
    }
    int swap = 0;
    if (m < l){
        swap = m + n - 1 - l;
    }
    else{
        swap = m + n - 2 - l;
    }
    cout<<swap<<endl;
    return 0;
}
