#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=5e5+10;
LL a[N];
LL b[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++){
		cin>>b[i];
	}
	
	//���� 
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	LL sum=0; 
	//����a���飬��b���ҵ�λ�� 
	LL bp=1;//b����ָ�� 
	for(LL i=1;i<=n;i++){
		//�ҵ���һ��b[bp]>a[i] 
		while(bp<=n && a[i]>=b[bp]){
			bp++;
		}
		sum+=a[i]*(bp-1);
	}
	//����b���飬��a���ҵ�λ��
	LL ap=1;//a����ָ��
	for(LL i=1;i<=n;i++) {
		while(ap<=n && b[i]>a[ap]){
			ap++;
		}
		sum+=b[i]*(ap-1);
	}
	
	cout<<sum<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("04.in", "r", stdin);
	//freopen("04.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

