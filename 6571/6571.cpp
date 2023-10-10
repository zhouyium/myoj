//6571: 天平与砝码（二）
//http://47.110.135.197/problem.php?id=6571
/*
n>20，比较大，用DFS必然超时
f[i][j] 考虑前i件物品，能否称出j的重量
对于第i个物品，我们有3个策略
1. 不选i，则f[i][j]=f[i-1][j]。也就是用上一个
2. 放左边，f[i][j]=f[i-1][j-w[i]]。 就是减少了重量
3. 放右边，f[i][j]=f[i-1][j+w[i]。增加重量 
注意，由于有放左边，-sum<=j<=sum。
这样，我们需要给j加上偏移sum，将 j 变为 [0, 2*sum] 
*/
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N = 1e2+10;
const int M = 2e5+10;//根据重量总和 
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
    		f[i][t]=f[i-1][t];//不选 
    		if (j-w[i]>=-sum) {
    			f[i][t] |= f[i-1][t-w[i]];//左边 
			}
			if (j+w[i]<=sum) {
				f[i][t] |= f[i-1][t+w[i]];//右边 
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

