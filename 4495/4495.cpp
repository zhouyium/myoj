#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int n;
	cin>>n;
	vector<int> v;
	
	for (int i=1; i<=n; i++) {
		string op;
		cin>>op;
		if (op=="insert") {
			//插入
			int x;
			cin>>x;
			v.push_back(x);
			cout<<v.size()<<"\n";
		} else if (op=="delete") {
			if (v.size()>0) {
				cout<<v[0]<<"\n";
				v.erase(v.begin());
			}
		} else {
			//MinEement 遍历找最小值
			if (0==v.size()) {
				continue;
			}
			int idx=0;
			int minx=1e9; 
			for (int j=0; j<v.size(); j++) {
				if (v[j]<minx) {
					minx=v[j];
					idx=j;
				}
			}
			cout<<minx<<"\n";
			v.erase(v.begin()+idx);
		}
	}
	
	return 0;
}
