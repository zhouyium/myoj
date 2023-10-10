//6425: 盾神与砝码称重
//http://47.110.135.197/problem.php?id=6425
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=30;
//砝码定义
LL a[N];
LL n,m;
vector<LL> ve;

/*
 * idx 当前砝码索引
 * sum 当前重量
 */
bool dfs(LL idx, LL sum) {
    if (sum==0) {
        return true;
    }
    if (idx<1) {
        return false;
    }
    //砝码放左边
    if (dfs(idx-1, sum-a[idx])) {
        return true;
    }
    //不放置
    if (dfs(idx-1, sum)) {
        return true;
    }
    //砝码放右边
    if (dfs(idx-1, sum+a[idx])) {
        return true;
    }
    return false;
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    cin>>n>>m;
    LL t_sum=0;
    for (LL i=1; i<=n; i++) {
        cin>>a[i];
        t_sum+=a[i];
    }
    for (LL i=1; i<=m; i++) {
        LL x;
        cin>>x;
        if (x>t_sum) {
        	cout<<"NO\n";
        	continue;
		}
        if (dfs(n, x)) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}
