//4409: 盒子包裹问题
//http://47.110.135.197/problem.php?id=4409

#include <bits/stdc++.h>
using namespace std;
using LL=long long;

void solve() {
	int n;
	cin >> n;
	vector<int> numbers;
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	
	unordered_map<int,int> counter;
	for(int i = 0; i < n; i++){
		counter[numbers[i]]++;
	}
	
	int result = 0;
	for(int i = 0; i < n; i++) {
		result = max(result, counter[numbers[i]]);
	}
	cout << result << "\n";	
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	LL n=12;
	for(int i=0;i<n;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif		
	
	return 0;
}
