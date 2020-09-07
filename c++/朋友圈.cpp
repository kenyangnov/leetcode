#include <iostream>

using namespace std;

const int maxn = 100001;
int leader[maxn];

int getLeader(int x){
    int r = leader[x];
    while(r!=leader[r]){
        r = leader[r];
    }
    int cur = x, temp;
    while(cur!=leader[cur]){
        temp = leader[cur];
        leader[cur] = r;
        cur = temp;
    }
    return r;
}

void join(int x, int y){
    int a = leader[x];
    int b = leader[y];
    if(a<b){
        leader[b] = a;
    } else{
        leader[a] = b;
    }
}

int main(){
    int n, m, k, r, t;
    for(int i=0; i<maxn; i++){
        leader[i]=i;
    }
    cin>>n>>m;
    while(m--){
        cin>>k>>r;
        while(--k){
            cin>>t;
            join(r, t);
        }
    }
    int ret=1, p[maxn];
    memset(p, 0, sizeof(p));
    for(int i=0; i<=n; i++){
        int r = getLeader(i);
        p[r]++;
        ret = ret>p[r]?ret:p[r];
    }
    cout<<ret<<endl;
    system("pause");
    return 0;
}