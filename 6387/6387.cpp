#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+10;
LL h[N], in[N];
const int M=2e5+10;
LL e[M], ne[M], idx;
LL que[M];
LL hh, tt;
LL n;

void add(LL a, LL b) {
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    //更新入度
    in[b]++;
}

bool top_sort() {
    //队列初始化
    hh=0; tt=-1;

    //将所有入度为0的加入队列
    for (LL i=1; i<=n; i++) {
        if (in[i]==0) {
            que[++tt]=i;
        }
    }

    while (hh<=tt) {
        LL u=que[hh];
        hh++;

        //遍历u的所有边
        for (LL i=h[u]; i!=-1; i=ne[i]) {
            LL v=e[i];
            in[v]--;
            if (in[v]==0) {
                que[++tt]=v;
            }
        }
    }

    //判断是否是DAG
    return tt==n-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //freopen("1.in", "r", stdin);

    memset(h, -1, sizeof h);

    LL m;
    cin>>n>>m;
    for (LL i=1; i<=m; i++) {
        LL a,b;
        cin>>a>>b;
        add(a,b);
    }

    if (top_sort()) {
        for (LL i=0; i<n; i++) {
            cout<<que[i]<<" ";
        }
    } else {
        cout<<"-1";
    }
    cout<<"\n";

    return 0;
}
