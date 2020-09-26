//http://47.110.135.197/problem.php?id=5334
//5334: 开关
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+4;
char sz[MAXN];

int main() {
    int n;
    cin>>n>>sz;

    //0表示关
    //1表示开
    //由后向前遍历数据
    unsigned long long ans=0;
    bool flag=true;
    for (int i=n-1; i>=0; i--) {
        if ((true==flag && '1'==sz[i]) || (false==flag && '0'==sz[i])) {
            flag = !flag;
            ans++;
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}