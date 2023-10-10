//http://47.110.135.197/problem.php?id=6175
//6175: 植树

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=40;

LL n;
LL x[N], y[N], r[N];
LL tree[N];
bool vis[N];
LL ans;

bool dis(LL a, LL b) {
	//判断两棵树圆心的距离是否小于两棵树的半径和
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<(r[a]+r[b])*(r[a]+r[b]);
}

void plant(int i,int area,int cnt){
    if(i==n){
        //最后一棵树
        if(area>ans){
            //记录最大面积
            ans=area;
        }
        return;
    }
    plant(i+1,area,cnt);
    for(int j=1;j<=cnt;j++){
        //
        if(dis(i, tree[j])){
            //两树圆心距离小于两棵树的半径和
            return ;
        }
    }
    //选择种植的树，记录下标
    tree[cnt]=i;
    plant(i+1,area+r[i]*r[i],cnt+1);
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);

	cin>>n;
	for (LL i=1; i<=n; i++) {
		cin>>x[i]>>y[i]>>r[i];
	}
	plant(1, 0, 0);
  //dfs(0, 0);
	cout<<ans<<"\n";
	
	return 0;
}

