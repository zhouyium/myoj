//https://nanti.jisuanke.com/t/T3421

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e2+10;
string a[MAXN]; 
int n,m;

void bomb(int x, int y) {
	//cout<<"x="<<x<<",y="<<y<<"\n";
	//����ǵ���
	int dx[]={ 0, 1, 1, 1, 0, -1, -1, -1};
	int dy[]={-1,-1, 0, 1, 1,  1,  0, -1};
	if (a[x][y]=='0') {
		return;
	}
	
	a[x][y]='2';//�Լ���ը 
	//��8������
	for (int i=0; i<8; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		//������Ϸ�
		if (nx>=0&&nx<n&&ny>=0&&ny<m) {
			if (a[nx][ny]=='0') {
				a[nx][ny]='2';
			} else if (a[nx][ny]=='1') {
				bomb(nx, ny);
			}
		}
	}
}
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	int x,y;
	cin>>x>>y;
	//����string���㿪ʼ 
	x--;
	y--;
	
	if (a[x][y]=='1') {
		bomb(x, y);
	}
	
	//���
	for (int i=0; i<n; i++)  {
		cout<<a[i]<<"\n";
	}

	return 0;
}

