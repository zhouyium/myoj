//6635: Ӫ���ƻ�
//http://47.110.135.197/problem.php?id=6635 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E5+10;
LL a[N];
LL f[N];//f[i]��ʾǰi����Ʒ������ṩ������ 
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	//�����������ַ��������ֻѡ�������֡�
	f[1]=0;//��ѡ��һ�� 
	f[2]=a[1];//ѡ��һ�� 
	for (LL i=3; i<=n+1; i++) {
		f[i]=f[i-1];//��i����ѡ 
		f[i]=max(f[i], f[i-2]+a[i-1]);//ѡ��һ�� 
		f[i]=max(f[i], f[i-3]+a[i-1]+a[i-2]);//ѡ������ 
	}
	cout<<f[n+1]<<"\n";

	return 0;
}

