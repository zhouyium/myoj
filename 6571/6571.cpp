//6571: ��ƽ�����루����
//http://47.110.135.197/problem.php?id=6571
/*
n>20���Ƚϴ���DFS��Ȼ��ʱ
f[i][j] ����ǰi����Ʒ���ܷ�Ƴ�j������
���ڵ�i����Ʒ��������3������
1. ��ѡi����f[i][j]=f[i-1][j]��Ҳ��������һ��
2. ����ߣ�f[i][j]=f[i-1][j-w[i]]�� ���Ǽ���������
3. ���ұߣ�f[i][j]=f[i-1][j+w[i]���������� 
ע�⣬�����з���ߣ�-sum<=j<=sum��
������������Ҫ��j����ƫ��sum���� j ��Ϊ [0, 2*sum] 
*/
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N = 1e2+10;
const int M = 2e5+10;//���������ܺ� 
const int BIAS = M/2;
bool f[N][M];
LL w[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//freopen("12.in", "r", stdin);
	//freopen("12.out", "w", stdout);

	LL n;
	cin>>n;
	LL sum=0;
	for (LL i=1; i<=n; i++) {
		cin>>w[i];
		sum+=w[i];
	}
    
    f[0][BIAS] = 1;
    for (LL i=1;i<=n;i++) {
    	for (LL j=-sum; j<=sum; j++) {
    		LL t=j+BIAS;
    		f[i][t]=f[i-1][t];//��ѡ 
    		if (j-w[i]>=-sum) {
    			f[i][t] |= f[i-1][t-w[i]];//��� 
			}
			if (j+w[i]<=sum) {
				f[i][t] |= f[i-1][t+w[i]];//�ұ� 
			}
		}
	}
    
    int res = 0;
    for(int i = BIAS+1; i <= sum + BIAS; i ++) {
        if (f[n][i]) {
            res++;
		}
	}
    cout<<res<<"\n";

    return 0;
}

