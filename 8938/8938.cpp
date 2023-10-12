#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

/*
���ǿ��Թ̶�ÿ���� a_i������ a_i ��Ϊ���ֵ��
���� a_i Ϊ���ֵ�������������ô����ֻ���ҵ����� 
i �������Ĵ�������λ���Լ��ұ�����Ĵ�������λ�ü��ɣ�
�������� l_i �� r_i Ȼ�󣬸��ݳ˷�ԭ���� a_i Ϊ���ֵ
������������� (i-l_i)*(r_i-i)
���� l_i �� r_i �����õ���ջ����
����  \sum_{1<=i<=j<=n}max(a_i,a_{i+1},...,a_j)
=\sum_{i=1}^{n}(i-l_i)*(r_i-i)*a_i
*/

const int N=5e5+10;
LL a[N];
LL l[N];
LL r[N];
//����ջ
LL stk[N],top; 

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//��ʼ��
	for(LL i=0;i<=n;i++){
		l[i]=0;
		r[i]=n;
	}
	
	for(LL i=1;i<=n;i++){
		while(top>0 && a[stk[top]]<=a[i]){
			r[stk[top]]=i;
			top--;
		}
		if(top==0){
			l[i]=-1;
		}else{
			l[i]=stk[top];
		}
		stk[++top]=i;
	}
	
	LL ans=0;
	for(LL i=1;i<=n;i++){
		ans+=(i-l[i])*(r[i]-i)*a[i];
	}
	cout<<ans<<"\n";
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

