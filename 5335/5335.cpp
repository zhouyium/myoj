//http://47.110.135.197/problem.php?id=5335
//构造字符串
#include <bits/stdc++.h>

using namespace std;

const int MAXN=26+2;
long long sz[MAXN];

int main() {
    int n;
    cin>>n;
    for (int i=0; i<26; i++) {
        cin>>sz[i];
    }

    long long ans=0;
    for (int i=0; i<26; i++) {
        ans += sz[i]/n;
    }

    cout<<ans<<"\n";

    return 0;
}