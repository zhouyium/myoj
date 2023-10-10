#include <cstdio>
#include <deque>

using namespace std;
const int MAXN=1.5e5+4;
deque<int> dq[MAXN];

int main() {
	int n,q;
	while (scanf("%d%d", &n, &q)!=EOF) {
		//清空队列
		for (int i=1; i<=n; i++) {
			dq[i].clear(); 
		}
		for (int i=1; i<=q; i++) {
			int op;
			scanf("%d", &op);
			if (1==op) {
				int u,w,val;
				scanf("%d%d%d", &u, &w, &val);
				if (0==w) {
					//最前面
					dq[u].push_front(val);
				} else if (1==w) {
					dq[u].push_back(val);
				}
			} else if (2==op) {
				int u,w;
				scanf("%d%d", &u, &w);
				if (0==dq[u].size()) {
					printf("-1\n");
				} else {
					if (0==w) {
						printf("%d\n", dq[u].front());
						dq[u].pop_front();
					} else {
						printf("%d\n", dq[u].back());
						dq[u].pop_back();
					}
				}
			} else {
				int u,v,w;
				scanf("%d%d%d", &u, &v, &w);
				if (0==dq[v].size()) {
					continue;
				}
				if (0==w) {
					//顺序接
					while (dq[v].size()>0) {
						int t=dq[v].front();
						dq[v].pop_front();
						dq[u].push_back(t);
					}
				} else {
					//逆序接
					while (dq[v].size()>0) {
						int t=dq[v].back();
						dq[v].pop_back();
						dq[u].push_back(t);
					}
				}
			}
		}
	}
	
	return 0;
}
