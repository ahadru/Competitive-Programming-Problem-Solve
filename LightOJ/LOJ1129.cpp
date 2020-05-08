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

const int ALPHABET_SIZE = 10;

struct Trie{
    struct Trie *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct Trie *getNode(){
    struct Trie *newNode  = new Trie;
    newNode->isLeaf = false;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

bool check(struct Trie *root, string key){
    struct Trie *pCrawl = root;
    bool re = false;
    bool isCreateNeNode = false;
    for(int i = 0; i < key.size(); i++){
        int index = key[i] - '0';
        if(!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
            isCreateNeNode = true;
        }
        pCrawl = pCrawl->children[index];
        if(pCrawl->isLeaf){
            re = true;
        }
    }
    pCrawl->isLeaf = true;
    if(re | !isCreateNeNode){
        return true;
    }
    else{
        return false;
    }
}

void del(struct Trie *cur){
    for(int i=0; i<ALPHABET_SIZE; i++)
        if(cur->children[i])
            del(cur->children[i]);
    delete(cur);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cases = 1;
    while(t--){
        int n;
        scanf("%d",&n);
        bool re = false;
        struct Trie *root = getNode();
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            //bool abc = check(root,str);
            re = re | check(root,str);
            //D(abc);
        }
        if(re) printf("Case %d: NO\n",cases++);
        else printf("Case %d: YES\n",cases++);
        del(root);
    }
    return 0;
}