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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> str;
        map<string,int> is_taken;
        map<string,int>::iterator it;
        int swap_count = 0;
        for(int i = 0; i < n; ++i){
            string a;
            cin>>a;
            str.push_back(a);
            it = is_taken.find(a);
            if(it == is_taken.end()){
                is_taken.insert({a,0});
            }
            else{
                is_taken[a] = 2;
                swap_count++;
            }
        }
        cout<<swap_count<<endl;
        for(int i = 0; i < str.size();i++){
            if(!is_taken[str[i]]){
                cout<<str[i]<<endl;
            }
            else{
                if(is_taken[str[i]] == 2){
                    cout<<str[i]<<endl;
                    is_taken[str[i]] = 1;
                }
                else{
                    string tmp_s = str[i];
                    for(int i = 0; i <= 9; ++i){
                        tmp_s[0] = 48+i;
                        if(is_taken.find(tmp_s) == is_taken.end()){
                            cout<<tmp_s<<endl;
                            is_taken.insert({tmp_s,0});
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}