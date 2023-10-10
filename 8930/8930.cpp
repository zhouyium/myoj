#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=1e5+10;
LL tong[N];//tong[i]��ʾ��i��Ľڵ��� 

LL qpow(LL a,LL b,LL p){
	//a^b mod p
	LL res=1;
	while(b){
		if(b%2==1){
			res=(res*a)%p; 
		}
		//ż��
		a=(a*a)%p; 
		b/=2;
	}
	return res;
}

void solve() {
	LL n;
	cin>>n;

	LL mx=0;//����Ĳ�
	for(LL i=1;i<=n;i++){
		//ʹ��Ͱ����ͳ�Ƹ���ڵ���
		LL x;
		cin>>x;
		tong[x]++;
		mx=max(mx,x);
	}
	
	LL ans=1;
	for(LL i=2;i<=mx;i++){//ʹ�ó˷�ԭ������ܵķ�����
		ans*=qpow(tong[i-1],tong[i],MO);
		ans%=MO;
	}
	cout<<ans<<"\n";
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
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

