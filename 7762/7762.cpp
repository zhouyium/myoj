#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e6+10;
LL h[N];
LL dfn[N], low[N], bridge[N];
const int M=2*N;
LL e[M], ne[M], idx;
LL cnt;

void init(LL n) {
	for (LL i=0; i<=n; i++) {
		h[i] = -1;
	}
	cnt=0;
}

void add(LL a, LL b) {
	e[idx] = b;
	ne[idx]= h[a];
	h[a]   = idx++;
}

// x 代表当前搜索树的根节点，in_edge 代表其对应的序号（tot）
void tarjan(LL x, LL in_edge) {
    // 在搜索之前，先初始化节点 x 的时间戳与追溯值
    dfn[x] = low[x] = ++cnt;
    // 通过 h 变量获取节点 x 的直接连接的第一个相邻节点的序号
    // 通过 ne 变量，迭代获取剩下的与节点 x 直接连接的节点的序号
    for (LL i = h[x]; i!=-1; i = ne[i]) {
        // 此时，i 代表节点 y 的序号
        LL y = e[i];
        // 如果当前节点 y 没有被访问过
        if (!dfn[y]) {
            // 递归搜索以 y 为跟的子树
            tarjan(y, i);
            // 计算 x 的追溯值
            low[x] = min(low[x], low[y]);
            // 桥的判定法则
            if (low[y] > dfn[x]) {
                bridge[i] = bridge[i ^ 1] = true; // 标记当前节点是否为桥（具体见下文）
			}
        } else if (i != (in_edge ^ 1)) {// 当前节点被访问过，且 y 不是 x 的“父节点”（具体见下文）
            low[x] = min(low[x], dfn[y]);
    	}
    }
}

int main() {
	LL n,m;
	scanf("%lld%lld", &n, &m);
	
	init(n);
	for(LL i=1; i<=m; ++i) {
		LL a,b; 
		scanf("%lld%lld", &a, &b);
		add(a,b);
	}

	tarjan(1, 0);
	for (LL i=1; i<=n; ++i) {
		printf("%lld ", dfn[i]);  //依次输出每个点的 dfn 值 
	}
	printf("\n");
	for(LL i=1; i<=n; ++i) {
		printf("%lld ", low[i]);  //依次输出每个点的 low 值 
	}
	printf("\n");

	return 0;
}
