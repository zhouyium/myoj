//http://47.110.135.197/problem.php?id=4291
//4291: ѧϰϵ�� ���� 01�������⣨0-1 knapsack problem�� 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2+10;
LL w[N];//ÿ����Ʒ����
LL v[N];//ÿ����Ʒ��ֵ
LL dp[N];//��������Ϊi��ʱ��������ܼ�ֵ
const int M=10;
LL path[N][M];

void show_path(LL i, LL j) {
	while (i && j) {
		if (path[i][j]) {
			cout<<i<<" ";
			j-=w[i];
		}
		i--;
	}
	cout<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    LL W;//������
    LL n;
    cin>>W>>n;
    for (LL i=1; i<=n; i++) {
        cin>>w[i]>>v[i];
    }

    //01����
    for (LL i=1; i<=n; i++) {
        for (LL j=W; j>=w[i]; j--) {
			if (dp[j]<dp[j-w[i]]+v[i]) {
				path[i][j]=1;//��¼·��
				dp[j]=dp[j-w[i]]+v[i];
			}
        }
    }

    cout<<dp[W]<<"\n";
    
    for (LL i=1; i<=n; i++) {
    	for (LL j=1; j<=W; j++) {
    		cout<<path[i][j]<<" ";
		}
		cout<<"\n";
	}
    show_path(n,W);
    
    return 0;
}
