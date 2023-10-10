//6573: 两个闹钟
//http://47.110.135.197/problem.php?id=6573
/*
根据题意可得
第一个闹钟的方程是：a+px
第一个闹钟的方程是：b+qy
要有解，必须满足 a+px=b+qy 
那么就是很标准的一个扩展欧几里德算法题。 
*/
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

LL exgcd(LL a, LL b, LL &x, LL &y) { // 扩展欧几里得模板
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    LL a,b,p,q;
    cin>>a>>b>>p>>q;
    LL x, y;
    LL gcd = exgcd(p, q, x, y);
    if((b - a) % gcd) {
        cout << "Impossible\n";
        return 0;
    }
    x *= (b- a) / gcd; // x扩大倍数，求出我们需要的方程解
    LL cc = q / gcd;
    x = (x % cc + cc) % cc; // x变为最小非负数解
    y = (a + x * p - b) / q; // 通过方程解出x对应y
    while(y < 0) { // 求出x，y都大于等于0的一组最小解
        x += cc; // x = x0 + q/gcd * k
        y = (a + x * p - b) / q;
    }
    cout << a + x * p<<"\n";
    return 0;
}
