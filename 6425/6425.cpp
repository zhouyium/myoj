//6425: �������������
//http://47.110.135.197/problem.php?id=6425
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=30;
//���붨��
LL a[N];
LL n,m;
vector<LL> ve;

/*
 * idx ��ǰ��������
 * sum ��ǰ����
 */
bool dfs(LL idx, LL sum) {
    if (sum==0) {
        return true;
    }
    if (idx<1) {
        return false;
    }
    //��������
    if (dfs(idx-1, sum-a[idx])) {
        return true;
    }
    //������
    if (dfs(idx-1, sum)) {
        return true;
    }
    //������ұ�
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
