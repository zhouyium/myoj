//http://47.110.135.197/problem.php?id=7509
//7509: [CSES Problem Set] Sum of Two Values

#include <bits/stdc++.h>
using namespace std;

set<int> A;
map<int, int> M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    int n, x, a;
    bool ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if(A.lower_bound(x - a) != A.end()){
            if(*A.lower_bound(x - a) == x - a){
                ans = 1;
                cout << i << " " << M[x - a];
                break;
            }
        }
        A.insert(a);
        M[a] = i;
    }
    if(!ans) cout << "IMPOSSIBLE\n";
    return 0;
}

