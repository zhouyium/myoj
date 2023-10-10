#include <cstdio>
#include <queue>
using namespace std;
int main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	//��������t
	int t;
	scanf("%d", &t);
	
	queue<int> q;
	int i, j;
	int m, n;//m��ʾ���еĴ�С��n��ʾ�������� 
	char op;
	int data;
	for (i=0; i<t; i++) {
		//�����
		while (q.empty() == false) {
			q.pop();
		} 
		
		//����������
		scanf("%d %d", &m, &n);
		
		for (j=0; j<n; j++) {
			scanf(" %c", &op);
			if (op=='A') {
				//'A'����
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
