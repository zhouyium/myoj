#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL n;
	cin>>n;
	
	//����һ����x�����ӣ��Ҽ���y��
	//�ܺ�x*(x+1)/2-3*y=n 
	//���� sum Ϊ�ܺͣ�cnt ���ҵķ��Ӻ� 
	//���ƺŴ���0 -> sum>n
	//���ƺ�Ϊ���� -> (sum-n)%3==0
	//���ƺŲ��ܴ���������ƺ� -> (sum-n)/3<=cnt 
	LL cnt=1, sum=1;
	while (!(sum>n && (sum-n)%3==0 && (sum-n)/3<=cnt)) {
		cnt++;
		sum+=cnt; 
	}
	
	cout<<(sum-n)/3<<" "<<cnt<<"\n";

	return 0;
}

