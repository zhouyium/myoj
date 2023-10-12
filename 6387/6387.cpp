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
    //�������
    in[b]++;
}

bool top_sort() {
    //���г�ʼ��
    hh=0; tt=-1;

    //���������Ϊ0�ļ������
    for (LL i=1; i<=n; i++) {
        if (in[i]==0) {
            que[++tt]=i;
        }
    }

    while (hh<=tt) {
        LL u=que[hh];
        hh++;

        //����u�����б�
        for (LL i=h[u]; i!=-1; i=ne[i]) {
            LL v=e[i];
            in[v]--;
            if (in[v]==0) {
                que[++tt]=v;
            }
        }
    }

    //�ж��Ƿ���DAG
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
