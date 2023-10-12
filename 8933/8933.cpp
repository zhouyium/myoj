#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

/*
��Ⱦɫ���̵�������һ�飬����Ҫ�Խ����ȥ1
����ΪҪ���������еĻ�ľͬɫ����������ɫ
*/
const int N=5e2+10;
LL f[N][N];
LL a[N];

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//��ʼ��
	memset(f, 0x3f, sizeof f);
	for(LL i=1;i<=n;i++){
		f[i][i]=1;
	}
	
	//����dp 
	for(LL len=2;len<=n;len++){
		for(LL i=1;i+len-1<=n;i++){
			LL j=i+len-1;
			if(a[i]==a[j]){
				f[i][j]=min(f[i+1][j],f[i][j-1]);
			}else{
				for(LL k=i;k<j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
	}
	
	cout<<f[1][n]-1<<"\n";
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

