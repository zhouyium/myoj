#include <bits/stdc++.h>

using namespace std;
using LL=long long;

const int N = 2e5 + 10, M = 2 * N;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL h[N], e[M], ne[M], w[M], idx;
LL a[N], n , m;
LL x, y, z;
LL dist[N][2][2];
bool st[N][2][2];

struct NODE {
    LL ver, cur, rev, w;
    bool operator < (const NODE &t) const
    {
        return w > t.w;
    }
};

void add(LL a, LL b)  // Ìí¼ÓÒ»Ìõ±ßa->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1][a[1]][0] = 0;
    priority_queue<NODE> q;
    q.push({1, a[1], 0, 0});

    while(q.size()) {
        auto t = q.top();
        q.pop();

        LL ver = t.ver, cur = t.cur, rev = t.rev, w = t.w;
        if(st[ver][cur][rev]) continue;
        st[ver][cur][rev] = true;

        for(LL i = h[ver]; ~i ; i = ne[i]) {
            LL j = e[i];
            if(cur == (a[j]^rev)) {
                if(dist[j][cur][rev] > dist[ver][cur][rev] + x) {
                    dist[j][cur][rev] = dist[ver][cur][rev] + x;
                    q.push({j, cur, rev, dist[j][cur][rev]});
                }
                if(dist[j][cur ^ 1][rev ^ 1] > dist[ver][cur][rev] + z + y) {
                    dist[j][cur ^ 1][rev ^ 1] = dist[ver][cur][rev] + z + y;
                    q.push({j, cur ^ 1, rev ^ 1, dist[j][cur ^ 1][rev ^ 1]});
                }
            }
            if(cur != a[j] ^ rev) {
                if(dist[j][cur ^ 1][rev] > dist[ver][cur][rev] + y) {
                    dist[j][cur ^ 1][rev] = dist[ver][cur][rev] + y;
                    q.push({j, cur ^ 1, rev, dist[j][cur ^ 1][rev]});
                }
                if(dist[j][cur][rev ^ 1] > dist[ver][cur][rev] + z + x) {
                    dist[j][cur][rev ^ 1] = dist[ver][cur][rev] + z + x;
                    q.push({j, cur, rev ^ 1, dist[j][cur][rev ^ 1]});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(h, -1, sizeof h);
    cin >> n >> m;
    cin >> x >> y >> z;
    for(LL i = 1; i <= n ; i ++ ) {
        cin >> a[i];
    }
    for(LL i = 1; i <= m  ; i ++ ) {
        LL a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dijkstra();
    
    LL res = INF;
    for(LL i = 0 ; i < 2 ; i ++ )
        for(LL j = 0 ; j < 2 ; j ++ )
            res = min(res, dist[n][i][j]);
    cout << res << "\n";

    return 0;
}
