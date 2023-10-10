#include <iostream>
#include <queue>

using namespace std;
int main() {
	//freopen("5.out", "w", stdout);
	
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		int m;
		cin>>m;
		
		queue<int> q;
		for (int j=1; j<=m; j++) {
			q.push(j);
		}
		while (q.size()>3) {
			//�������ĳ���
			int cnt;
			int x;
			cnt=0;
			m=q.size();
			for (int j=1; j<=m; j++) {
				cnt++;
				x=q.front();
				q.pop();
				if (0!=cnt%2) {
					q.push(x);
				}
			}
			
			if (q.size()<=3) {
				break;
			}
			//������
			cnt=0;
			m=q.size();
			for (int j=1; j<=m; j++) {
				cnt++;
				x=q.front();
				q.pop();
				if (0!=cnt%3) {
					q.push(x);
				}
			}
		}
		
		//���
		while (q.size()!=1) {
			cout<<q.front()<<" ";
			q.pop();
		}
		cout<<q.front()<<"\n";
	}
	return 0;
}
