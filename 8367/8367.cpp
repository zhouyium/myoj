#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=2E5+10;
LL a[N];
LL f[N][2];
//f[i][0]��ʾ�Ե�i����Ϊ��β����������
//f[i][1]��ʾ�Ե�i����Ϊ��β��������С��
/*
1.�������ȫ����������ô���;�����������Ԫ�صĺ� sum
2.������������и������ȿ���û�л�ʱ�����ǿ���������������� max��
�л�ʱ����Ҫ����������������Ҫ��������ɾ��һ�θ���������ʣ�������Ͳ��ܸ���
��Ҫʣ���������������ôɾ������һ�θ�����Ӧ����С��Ҳ������С�������min
3.�������min�Ǹ�������������ֻ��Ҫ�Ƚ� max ��sum-min��ֵ˭��Ϳ����ˣ�
���min����������ô���ֵһ����sum�����sum==min��˵����С�����������鱾��
���ʱ��Ӧ����max���
*/

void solve() {
	LL n;
	cin>>n;
	
	LL sum=0;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	//������ 
	LL maxx=-9e18;
	f[0][0]=-9e18;
	for(LL i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0]+a[i], a[i]);
		maxx=max(maxx, f[i][0]);
	}
	
	//����С��
	LL minx=9e18;
	f[0][1]=9e18;
	for(LL i=1;i<=n;i++){
		f[i][1]=min(f[i-1][1]+a[i], a[i]);
		minx=min(minx, f[i][1]);
	}

	LL mx=sum-minx;
	if(mx==0){
		mx=sum;
	}
	cout<<max(maxx,mx)<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}


