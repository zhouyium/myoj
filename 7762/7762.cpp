#include <bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e6+10;
LL h[N];
LL dfn[N], low[N], bridge[N];
const int M=2*N;
LL e[M], ne[M], idx;
LL cnt;

void init(LL n) {
	for (LL i=0; i<=n; i++) {
		h[i] = -1;
	}
	cnt=0;
}

void add(LL a, LL b) {
	e[idx] = b;
	ne[idx]= h[a];
	h[a]   = idx++;
}

// x ����ǰ�������ĸ��ڵ㣬in_edge �������Ӧ����ţ�tot��
void tarjan(LL x, LL in_edge) {
    // ������֮ǰ���ȳ�ʼ���ڵ� x ��ʱ�����׷��ֵ
    dfn[x] = low[x] = ++cnt;
    // ͨ�� h ������ȡ�ڵ� x ��ֱ�����ӵĵ�һ�����ڽڵ�����
    // ͨ�� ne ������������ȡʣ�µ���ڵ� x ֱ�����ӵĽڵ�����
    for (LL i = h[x]; i!=-1; i = ne[i]) {
        // ��ʱ��i ����ڵ� y �����
        LL y = e[i];
        // �����ǰ�ڵ� y û�б����ʹ�
        if (!dfn[y]) {
            // �ݹ������� y Ϊ��������
            tarjan(y, i);
            // ���� x ��׷��ֵ
            low[x] = min(low[x], low[y]);
            // �ŵ��ж�����
            if (low[y] > dfn[x]) {
                bridge[i] = bridge[i ^ 1] = true; // ��ǵ�ǰ�ڵ��Ƿ�Ϊ�ţ���������ģ�
			}
        } else if (i != (in_edge ^ 1)) {// ��ǰ�ڵ㱻���ʹ����� y ���� x �ġ����ڵ㡱����������ģ�
            low[x] = min(low[x], dfn[y]);
    	}
    }
}

int main() {
	LL n,m;
	scanf("%lld%lld", &n, &m);
	
	init(n);
	for(LL i=1; i<=m; ++i) {
		LL a,b; 
		scanf("%lld%lld", &a, &b);
		add(a,b);
	}

	tarjan(1, 0);
	for (LL i=1; i<=n; ++i) {
		printf("%lld ", dfn[i]);  //�������ÿ����� dfn ֵ 
	}
	printf("\n");
	for(LL i=1; i<=n; ++i) {
		printf("%lld ", low[i]);  //�������ÿ����� low ֵ 
	}
	printf("\n");

	return 0;
}
