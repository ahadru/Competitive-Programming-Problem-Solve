#include <bits/stdc++.h>
#define Mem0(arr) memset(arr,0,sizeof(arr))
#define Mem1(arr) memset(arr,1,sizeof(arr))
#define Dout(v) cout<<"Debug: "<<v<<endl
#define Dout2(a,b) cout<<"Debug: "<<a<<" "<<b<<endl
#define MAX100 1000000000
#define MAX10 100000000
#define MAX 10000000
#define MAX_S 100000
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    int cases = 0;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int total_status = n*m;
        int status[n+1][m+1];
        Mem0(status);
        int seat[m+1];
        Mem0(seat);
        int pro[n+1];
        for(int i = 1;i<=n;i++){
            pro[i] = i; 
        }
        int count = 0,seat_pos = 1,time_ = 0,pro_back = n+1;
        
        while(1){
            //cout<<"In While: ";
            //Dout(count);
            if(seat[seat_pos]){
                //cout<<"    In seat dokhol\n";
                pro[pro_back] = seat[seat_pos];
                seat[seat_pos] = 0;
                pro_back++;
            }
            if(pro_back-1 > 0){
                //cout<<"    If there someone: "<<"Pro:"<<pro[1]<<" seat:"<<seat_pos<<" "<<"STA:"<<status[pro[1]][seat_pos]<<" "<<"SIZE:"<<pro_back-1<<" PRO_B:"<<pro_back-1<<endl;
                if(status[pro[1]][seat_pos] == 0){
                    //cout<<"        If he not visit this seat\n";
                    status[pro[1]][seat_pos] = 1;
                    seat[seat_pos] = pro[1];
                    count++;
                    for(int i = 1;i<pro_back-1;i++){
                        pro[i] = pro[i+1];
                    }
                    pro_back--;
                }
                else{
                    //cout<<"            If he visited\n";
                    for(int i = 1; i < pro_back; i++){
                        //cout<<"                In for: "<<"Pro:"<<pro[i]<<" "<<"STA:"<<status[pro[i]][seat_pos]<<endl;
                        if(status[pro[i]][seat_pos] == 0){
                            status[pro[i]][seat_pos] = 1;
                            seat[seat_pos] = pro[i];
                            count++;
                            while(i<pro_back-1){
                                pro[i] = pro[i+1];
                                i++;
                            }
                            pro_back--;
                        }
                    }
                }    
            }
            seat_pos++;
            if(seat_pos > m){
                seat_pos = 1;
            }
            time_ += 5;
            if(count == total_status && pro_back-1 == n){
                break;
            }
        }
        cout<<"Case "<<++cases<<": "<<time_<<endl;
    }
    return 0;
}