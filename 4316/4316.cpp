#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e5+10;
LL a[N];//�ֽ�
LL f[N];//����ǰi������ʱ������iʱ����������

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	f[0]=0;
	f[1]=a[1];//���ٵ�1�� 
	f[2]=a[2];//���ٵ�2�� 
	for(LL i=3;i<=n;i++){
		//���ٵ�i�� 
		//���һ������������ϴ�� 
		f[i]=max(f[i-2],f[i-3])+a[i];
	}
	cout<<max(f[n],f[n-1])<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	int T=1;
	cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

