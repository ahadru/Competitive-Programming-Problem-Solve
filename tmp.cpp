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
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    // priority_queue<int> pq;
    // pq.push(2);
    // pq.push(3);
    // pq.push(2);
    // cout<<pq.size()<<endl;
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;

    // set<int> s;
    // map<int,int> m;
    // s.insert(2);
    // m.insert({2,4});

    // s.insert(3);
    // m.insert({3,4});

    // s.insert(6);
    // m.insert({6,4});

    // s.insert(1);
    // m.insert({1,3});

    // s.insert(1);
    // m.insert({1,4});
    // set<int>::iterator i;
    // for(i = s.begin(); i != s.end(); i++){
    //     cout<<*i<<" "<<m[*i]<<endl;
    // }
    // cout<<endl;

    map<string,bool> m;
    m.insert({"ahad", true});
    cout<<m["ahad"]<<endl;
    return 0;
}