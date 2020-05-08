#include<bits/stdc++.h> 
#define M0(a) memset(a,0,sizeof a)
#define M1(a) memset(a,1,sizeof a)
#define M1_(a) memset(a,-1,sizeof a)
#define D(v) cerr<<"D: "<<#v<<": "<<v<<endl
#define D2(a,b) cerr<<#a<<": "<<a<<","<<#b<<": "<<b<<endl
#define For(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define ForIT(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define M100 10000000
#define M10 1000000
#define M 100000
#define MS 10000
using namespace std; 

char arr[107]; 
int r; 
int n;
vector<char> hold_data; 

void combination(int pos) 
{ 
	//D(pos);
	// D(hold_data.size());
	// D(r);
	// //if(pos == n) return;
	//D(n);
	if(hold_data.size() == r){
		//cout<<"Hello\n";
		for(int i = 0; i < hold_data.size(); ++i){
			printf("%c", hold_data[i]);
		}
		puts("");
		return;
	}
	
	for(int i = pos; i < n; ++i){
		//cout<<"Hello\n";
		hold_data.push_back(arr[i]);
		combination(i+1);
		hold_data.pop_back();
		while(arr[i]==arr[i+1] && i+1 < n )i++;
	}
} 

// Driver code 
int main() 
{ 
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
    while(scanf("%s %d",arr, &r) == 2){
		n = strlen(arr);
        sort(arr,arr+n);
		hold_data.clear();
		//D(n);
		//printf("D: %s\n",arr);
		//D(r);
        combination(0); 
    }
} 
