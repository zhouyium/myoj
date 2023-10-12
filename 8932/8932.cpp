#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;

const int N=2e6+10;

priority_queue<LL> que;//���ȶ���

void solve() {
	LL n,m;
	cin>>n>>m;
	
	LL ans=0;
	LL sum=0;//��ѹ����ÿ������Ĳ���ֵ�ܺ�
	for(LL i=1;i<=n;i++){
		LL x;
		cin>>x;
		
		sum+=x;//���Ŀǰ��ѹ����һ������Ĳ���ֵ�ܺ�
		ans+=sum;//�ۼƲ���ֵ
		
		que.push(x);//�������ȶ���
		if(i>m){
			//���������Դ�����
			LL y=que.top();//ȡ�����ֵ
            que.pop();//�����ȶ����е���
            ans-=y;//ȥ�����������������Ĳ���ֵ
            sum-=y;//���»�ѹ����ÿ���������ֵ���ܺ�
		}
	}
	
	//������ֵ���Ķ�����ֱ������������
	while(que.size()){
		LL y=que.top();
		que.pop();
		sum-=y;//���»�ѹ����ÿ������Ĳ���ֵ�ܺ�
		ans+=sum;//�ۼƲ���ֵ
	}
	
	cout<<ans<<"\n";
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);
#endif

	int T=1;
	//cin>>T;
	for (int i=1; i<=T; i++) {
		//cout<<i<<"\n";
	    solve();
	}
	return 0;
}

