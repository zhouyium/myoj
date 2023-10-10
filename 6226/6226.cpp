//6226: Acowdemia III
//http://47.110.135.197/problem.php?id=6226

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int N,M; 
	cin >> N >> M;
	vector<string> G(N); 
	for (string& row: G) {
		cin >> row;	
	}
	
	auto exists_cow = [&](int i, int j) { 
		return 0 <= i && i < N && 0 <= j && j < M && G[i][j] == 'C';
	};
	
	set<vector<pair<int,int>>> pairs;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (G[i][j] == 'G') {
				vector<pair<int,int>> v;
				int dx[]{1,0,-1,0};
				int dy[]{0,1,0,-1};
				for (int d = 0; d < 4; ++d) {
					int ii = i+dx[d], jj = j+dy[d];
					if (exists_cow(ii,jj)) v.emplace_back(ii,jj);
				}
				if (v.size() > 2) {
					++ans;
					continue;
				}
				if (v.size() == 2) {
					sort(begin(v),end(v));
					pairs.insert(v);
				}
			}			
		}
	}
	
	cout << pairs.size()+ans << "\n";
	
	return 0;
}

