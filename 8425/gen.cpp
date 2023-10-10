#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>

using namespace std;

const int N=1e6+10;
int tree[N];

int random(int l, int r) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

void creatTree(int n) {
	for (int i = 0; i < n; ++i) {
		tree[i] = i + 1;
	}
	int root = random(0, n - 1);
	swap(tree[root], tree[n - 1]);
	int nxt_idx = n - 2;
	queue<int> Que;
	cout << n << "\n";
	
#if 0	
	//生成点权 
	for (int i = 0; i < n; ++i) {
		cout << random(-1024, 1024) << ' ';
	}
	cout << "\n";
#endif
	
	Que.push(tree[n - 1]);
	while (!Que.empty()) {
		int now = Que.front();
		Que.pop();
		int cnt = random(2, 2); // 将子节点范围取做（2，2）就生成了二叉树 
		for (int i = 0; i < cnt; ++i) {
			int tmp_idx = random(0, nxt_idx); 
			swap(tree[tmp_idx], tree[nxt_idx]);
			cout << now << ' ' << tree[nxt_idx] << "\n";
			Que.push(tree[nxt_idx]);
			nxt_idx--;
			if (nxt_idx == -1) break;
		}
		if (nxt_idx == -1) break;
	}
}

int main()
{
	creatTree(10);
	return 0;
}

