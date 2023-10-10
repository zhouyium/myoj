#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=1e3+10;
LL w[N],v[N];
const int F=5e4+10;
LL f[F]; //f[i]��ʾ������Ϊi��ʱ���Ӧ��������� 

void solve() {
	LL n,W,K;
	cin>>n>>W>>K;
	for (LL i=1;i<=n;i++) {
		cin>>w[i]>>v[i];
	}
	
	//��ʼ����-1��ʾ�ڱ� 
	for (LL i=1;i<=W;i++) {
		f[i]=-1;
	}
	
	//01
	f[0]=0; 
	for (LL i=1;i<=n;i++) {
		for (LL j=W;j>=w[i];j--) {
			if (f[j-w[i]]!=-1) {
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			}
		}
	}
	
	//�Ҵ�
	LL ans=-9e18;
	for (LL i=0;i<=W;i++) {//i��ʾ���� 
		if (f[i]==-1) {
			continue;
		}
		ans=max(ans,f[i]-(W-i)*K);
	}
	cout<<ans<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	freopen("05.in", "r", stdin);
	freopen("05.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

