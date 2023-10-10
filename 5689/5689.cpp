//http://47.110.135.197/problem.php?id=5689
//5689: ƽ���
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
ll a[MAXN];
ll sumL[MAXN];//ƽ�����i��ʱ����ߵ�Ԫ���ܺ� 
ll sumR[MAXN];//ƽ�����i��ʱ���ұߵ�Ԫ���ܺ� 

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("12.in", "r", stdin);
	//freopen("12.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=a[i-1];
	}
	
	//������ߵ����� 
	for (int k=1; k<=n; k++) {
		sumL[k]=sumL[k-1]+a[k-1]-a[0];
	}
	//�����ұߵ�����
	for (int k=n; k>=1; k--) {
		sumR[k]=sumR[k+1]+a[n]-a[k];
	}
	
	ll ans=2e9;
	for (int i=1; i<=n; i++) {
		ans=min(ans, abs(sumL[i]-sumR[i]));
	}
	
	cout<<ans<<"\n";

	return 0;
}

