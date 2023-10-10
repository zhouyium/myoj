//6573: ��������
//http://47.110.135.197/problem.php?id=6573
/*
��������ɵ�
��һ�����ӵķ����ǣ�a+px
��һ�����ӵķ����ǣ�b+qy
Ҫ�н⣬�������� a+px=b+qy 
��ô���Ǻܱ�׼��һ����չŷ������㷨�⡣ 
*/
#include <bits/stdc++.h>
using namespace std;
using LL=long long;

LL exgcd(LL a, LL b, LL &x, LL &y) { // ��չŷ�����ģ��
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
    x *= (b- a) / gcd; // x�����������������Ҫ�ķ��̽�
    LL cc = q / gcd;
    x = (x % cc + cc) % cc; // x��Ϊ��С�Ǹ�����
    y = (a + x * p - b) / q; // ͨ�����̽��x��Ӧy
    while(y < 0) { // ���x��y�����ڵ���0��һ����С��
        x += cc; // x = x0 + q/gcd * k
        y = (a + x * p - b) / q;
    }
    cout << a + x * p<<"\n";
    return 0;
}
