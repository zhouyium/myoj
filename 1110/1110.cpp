#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5E5+10;
int pri[N];  //保存质数, pri[0]用来保存数组数量
bool visit[N];  //访问标志位
void Prime(int n){
    visit[1]=true;
    for (int i = 2;i <=n; i++) {
        //cout<<" i = "<<i<<"\n";
        if (!visit[i]) {
            pri[++pri[0]] = i;      //纪录素数， 这个pri[0] 相当于 cnt，用来计数
        }
        for (int j = 1; j <=pri[0] && i*pri[j] <=n; j++) {
            //cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<pri[j]<<" i*pri[j] = "<<i*pri[j]<<"\n";
            visit[i*pri[j]] = 1;
            if (i % pri[j] == 0) {
                break;
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
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	Prime(2e5);
	LL x,y;
	cin>>x>>y;
	LL tot=0;
	for (LL i=x; i<=y; i++) {
		if (visit[i]==false) {
			tot++;
		}
	}
	cout<<tot<<"\n";

	return 0;
}

