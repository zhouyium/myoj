//http://47.110.135.197/problem.php?id=6012
//6012: 扩展欧几里得算法
#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL exgcd(LL a, LL b, LL &x, LL &y){//返回gcd(a,b) 并求出解(引用带回)
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    LL x1,y1,gcd;
    gcd = exgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - a/b*y1;
    return gcd; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//freopen("2.in", "r", stdin);
	//freopen("2.out", "w", stdout);
	
    LL n;
    cin>>n;
    while (n--){
        LL a,b,x,y;
        cin>>a>>b;
        exgcd(a,b,x,y);
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}
