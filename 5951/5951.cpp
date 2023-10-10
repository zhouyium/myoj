//5951: �ж�һ�����Ƿ�����������
//http://47.110.135.197/problem.php?id=5951

#include <bits/stdc++.h>
using namespace std;
using LL=long long;
struct POINT {
    double x;
    double y;
};

double product(const POINT &p1,const POINT &p2, const POINT &p3) {
    //���ȸ����������p1p2��p1p3��������Ȼ���ټ�����
    //p1p2 ������ʾΪ (p2.x-p1.x,p2.y-p1.y)
    //p1p3 ������ʾΪ (p3.x-p1.x,p3.y-p1.y)
    return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}

bool isInTriangle(const POINT &p1,const POINT &p2, const POINT &p3,const POINT &o) {
    //��֤p1��p2��p3����ʱ��˳��
    if(product(p1, p2, p3)<0) return isInTriangle(p1,p3,p2,o);
    if(product(p1, p2, o)>0 && product(p2, p3, o)>0 && product(p3, p1, o)>0)
        return true;
    return false;
}

int main() {
    POINT p1,p2,p3,o;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> o.x >> o.y;
    bool flag = isInTriangle(p1,p2,p3,o);
    if(flag) puts("Yes");
    else puts("No");
}

