//6225: Acowdemia II
//http://47.110.135.197/problem.php?id=6225
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E3+10;
string member[MAXN];
string publication[MAXN];
string ans[MAXN];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	LL n,K;
	cin>>K>>n;
	//��ȡ��Ա���� 
	map<string, LL> M;
	for (LL i=0; i<n; i++) {
		cin>>member[i];
		M[member[i]] = i;
	}
	
	//��ʼ��ans����
	for (LL i=0; i<n; i++) {
		for (LL j=0; j<n; j++) {
			ans[i].push_back('?');
		}
		ans[i][i]='B';
	}
	
	//��ȡ���� 
	for (LL i=0; i<K; i++) {
		for (LL j=0; j<n; j++) {
			cin>>publication[j];
		}
		
		for (LL x=0; x<n; x++) {
			bool flag=true;
			for (LL y=x+1; y<n; y++) {
				if (publication[y-1]>publication[y]) {
					flag=false;
				}
				if (false==flag) {
					LL a=M[publication[x]];
					LL b=M[publication[y]];
					ans[a][b]='0';
					ans[b][a]='1';
				}
			}
		}
	}
	
	//���
	for (LL i=0; i<n; i++)  {
		cout<<ans[i]<<"\n";
	}

	return 0;
}

