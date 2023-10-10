#include <cstdio>
#include <queue>
using namespace std;
int main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	//输入整数t
	int t;
	scanf("%d", &t);
	
	queue<int> q;
	int i, j;
	int m, n;//m表示队列的大小，n表示几个操作 
	char op;
	int data;
	for (i=0; i<t; i++) {
		//清队列
		while (q.empty() == false) {
			q.pop();
		} 
		
		//两个正整数
		scanf("%d %d", &m, &n);
		
		for (j=0; j<n; j++) {
			scanf(" %c", &op);
			if (op=='A') {
				//'A'操作
				if (q.empty()==true) {
					printf("E\n");
				} else {
					printf("%d\n", q.front());
				}
			} else if (op=='P') {
				//P
				scanf("%d", &data);
				if (q.size()>=m) {
					printf("F\n");
				} else {
					q.push(data);
				}
			} else if (op=='O') {
				if (q.empty()==true) {
					printf("E\n");
				} else {
					printf("%d\n", q.front());
					q.pop();
				}
			}
		}
		printf("\n");
	}
	return 0;
}
