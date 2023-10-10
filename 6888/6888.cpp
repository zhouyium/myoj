#include <bits/stdc++.h>
using namespace std;
using LL=long long;

string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("09.in", "r", stdin);
    freopen("09.out", "w", stdout);
    
    LL n,K;
    cin>>n>>K;
    cin>>s;
    s = '?'+s;

    LL res=0;
    LL last=-1;//记录上一个字符位置
    priority_queue<LL, vector<LL>, greater<LL>> q;
    for (LL i=1; i<=n; i++) {
        if (s[i]=='Z' && last==-1) {
            last=i;
            continue;
        } else if (s[i]=='Z') {
            //保存连续Z的长度
            q.push(i-last-1);
            last=i;
        }
    }

    while (q.size() && K-q.top()>=0) {
        res+=4;
        K-=q.top();
        q.pop();
    }

    cout<<res<<"\n";

    return 0;
}
