//http://47.110.135.197/problem.php?id=4291
//4291: 学习系列 —— 01背包问题（0-1 knapsack problem） 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2+10;
LL w[N];//每个物品重量
LL v[N];//每个物品价值
LL dp[N];//背包重量为i的时候获得最大总价值
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
    
    LL W;//总重量
    LL n;
    cin>>W>>n;
    for (LL i=1; i<=n; i++) {
        cin>>w[i]>>v[i];
    }

    //01背包
    for (LL i=1; i<=n; i++) {
        for (LL j=W; j>=w[i]; j--) {
			if (dp[j]<dp[j-w[i]]+v[i]) {
				path[i][j]=1;//记录路径
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
