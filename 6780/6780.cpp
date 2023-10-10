#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e6+10;
LL ne[N];

void kmp_next(const string &p) {
    ne[0]=-1;
    LL i=0, j=-1;
    while (i<p.size()) {
        if (j<0 || p[i]==p[j]) {
            ne[++i]=++j;
        } else {
            j=ne[j];
        }
    }
}

LL kmp(const string &s, const string &p) {
    LL cnt=0;
    LL i=0,j=0;
    while (i<s.size()) {
        if (j<0 || s[i]==p[j]) {
            i++;
            j++;
        } else {
            j=ne[j];
        }
        if (j==p.size()) {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    string s,p;
    cin>>s>>p;
    //cout<<p.size()<<"\n"<<s.size()<<"\n";
    //cout<<p<<"\n"<<s<<"\n";
    kmp_next(p);
    cout<<kmp(s, p)<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    LL T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
