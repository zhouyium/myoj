//https://iai.sh.cn/problem/642
//航海探险
//二维带权并查集 
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=4e5+10;
LL n, m;
LL gx[N], wx[N];//x轴 
LL gy[N], wy[N];//y轴 

LL parentx(LL x) {
	if (gx[x] == x) {
		return x;
	}
	LL g = gx[x];
	gx[x] = parentx(gx[x]);
	wx[x] = wx[x] + wx[g];
	return gx[x];
}

LL parenty(LL x) {
	if (gy[x] == x) {
		return x;
	}
	LL g = gy[x];
	gy[x] = parenty(gy[x]);
	wy[x] = wy[x] + wy[g];
	return gy[x];
}

LL disx(LL x, LL y) {
	LL px = parentx(x);
	LL py = parentx(y);
	if (px != py) {
		return -1;
	}
	return abs(wx[x] - wx[y]);
}

LL disy(LL x, LL y) {
	LL px = parenty(x);
	LL py = parenty(y);
	if (px != py) {
		return -1;
	}
	return abs(wy[x] - wy[y]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("09.in", "r", stdin);
	//freopen("09.out", "w", stdout);
	cin>>n>>m;
	for (LL i = 1; i <= n; i++) {
		gx[i] = i, gy[i] = i;
	}

	char c;
	LL a, b;
	LL e;	
	for (LL i = 1; i <= m; i++) {
		cin>>c;
		if (c == '?') {
			cin>>a>>b;
			LL dx = disx(a, b);
			LL dy = disy(a, b);
			if (dx == -1 || dy == -1) {
				cout<<"?\n";
			} else {
				cout<<dx+dy<<"\n";
			}
		} else {
			cin>>a>>b>>e;
			if (c == 'E') {
				LL p1 = parentx(a);
				LL p2 = parentx(b);
				if (p1 != p2) {
					wx[p1] = e - wx[a] + wx[b];
					gx[p1] = p2;
					p1 = parenty(a);
					p2 = parenty(b);
					wy[p1] = wy[b] - wy[a];
					gy[p1] = p2;
				}
			} else if (c == 'W') {
				LL p1 = parentx(a);
				LL p2 = parentx(b);
				if (p1 != p2) {
					wx[p2] = e - wx[b] + wx[a];
					gx[p2] = p1;
					p1 = parenty(a);
					p2 = parenty(b);
					wy[p1] = wy[b] - wy[a];
					gy[p1] = p2;
				}
			} else if (c == 'N') {
				LL p1 = parenty(a);
				LL p2 = parenty(b);
				if (p1 != p2) {
					wy[p1] = e - wy[a] + wy[b];
					gy[p1] = p2;
					p1 = parentx(a);
					p2 = parentx(b);
					wx[p1] = wx[b] - wx[a];
					gx[p1] = p2;
				}
			} else {
				LL p1 = parenty(a);
				LL p2 = parenty(b);
				if (p1 != p2) {
					wy[p2] = e - wy[b] + wy[a];
					gy[p2] = p1;
					p1 = parentx(a);
					p2 = parentx(b);
					wx[p1] = wx[b] - wx[a];
					gx[p1] = p2;
				}
			}
		}
	}

	return 0;
}
