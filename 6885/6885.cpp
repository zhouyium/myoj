//�����ÿһλҪ���伸�����ӣ�Ȼ��̰�ĵĴӴ�С����(ÿ���������ζֵ��ķź���)
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=2e5+10;
LL a[N];
LL b[11];
LL c[11];
LL ans[11][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    freopen("09.in", "r", stdin);
    freopen("09.out", "w", stdout);

    LL n;
    cin>>n;
    for (LL i=1; i<=n; i++) {
        cin>>a[i];
        b[i%10]++;//����
    }
    sort(a+1, a+n+1,greater<LL>());

    LL cnt=0;
    for (LL i=9; i>=0; i--) {//�ȷŴ��
        for (LL j=b[i]; j>=1; j--) {
            ans[i][j]=a[++cnt];
        }
    }

    for (LL i=1; i<=n; i++) {
        LL t=i%10;
        cout<<ans[t][++c[t]]<<" ";
    }
    cout<<"\n";

    return 0;
}
