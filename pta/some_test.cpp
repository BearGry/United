#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

struct node {
    int x, y;
};

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};
int st_x, st_y, ed_x, ed_y;
int n, m, l = 0, r = 0;
int e_map[600][600], vis[600][600];
char s[600];

int min1(int p, int q) { return p < q ? p : q; }
int max1(int p, int q) { return p > q ? p : q; }
int abs1(int p) { return p > 0 ? p : -p; }

queue<node> q;

bool pd(int x, int y) {
    return (x > 0) && (x <= n) && (y > 0) && (y <= m);
}

bool check(int mid) {
    memset(vis, false, sizeof(vis));
    node ht;
    ht.x = st_x;
    ht.y = st_y;
    q.push(ht);

    if (e_map[st_x][st_y] < mid) return false;

    vis[st_x][st_y] = true;
    while (!q.empty()) {
        node k = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int x1 = k.x + dx[i];
            int y1 = k.y + dy[i];
            if (!pd(x1, y1)) continue;
            if (vis[x1][y1] == true) continue;
            if (e_map[x1][y1] >= mid) {
                vis[x1][y1] = true;
                node zk;
                zk.x = x1;
                zk.y = y1;
                q.push(zk);
            }
        }
    }
    return vis[ed_x][ed_y];
}

void init() {
    while (!q.empty()) {
        node k = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int x1 = k.x + dx[i];
            int y1 = k.y + dy[i];
            if (!pd(x1, y1)) continue;
            if (e_map[x1][y1] != -1) continue;
            e_map[x1][y1] = e_map[k.x][k.y] + 1;
            r = max1(r, e_map[x1][y1]);
            node zr;
            zr.x = x1;
            zr.y = y1;
            q.push(zr);
        }
    }
}

int main() {
    memset(e_map, -1, sizeof(e_map));
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == 'V') {
                st_x = i;
                st_y = j;
            }
            if (s[j - 1] == 'J') {
                ed_x = i;
                ed_y = j;
            }
            if (s[j - 1] == '+') {
                e_map[i][j] = 0;
                node rs;
                rs.x = i;
                rs.y = j;
                q.push(rs);
            }
        }
    }

    init();

    // 二分查找
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    printf("%d", l);
    return 0;
}
