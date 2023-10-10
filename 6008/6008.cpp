//https://codeforces.com/contest/1458/problem/A
//A. Row GCD
#include <bits/stdc++.h>

using namespace std;

//����ύ��OJ����Ҫ���� __LOCAL
//#define __LOCAL

typedef long long ll;
const int MAXN=2e5+4;
ll a[MAXN], b[MAXN];

int main() {
#ifndef __LOCAL
    //�ⲿ�ִ�����Ҫ�ύ��OJ�����ص��Բ�ʹ��
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
	freopen("03.in", "r", stdin);
	freopen("03.out", "w", stdout);
	
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }

    ll g=0;
    for (int i=2; i<=n; i++) {
        g=__gcd(g, abs(a[i]-a[i-1]));
    }

    for (int i=1; i<=m; i++) {
        cin>>b[i];
        ll ans=__gcd(a[1]+b[i], g);
        cout<<ans<<" ";
    }

    cout<<"\n";

#ifdef __LOCAL
    //�ⲿ�ִ��벻��Ҫ�ύ��OJ�����ص���ʹ��
    system("pause");
#endif
    return 0;
}

