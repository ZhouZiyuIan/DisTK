#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int n, m;
ll k, x, y;
ll a[200005], b[200005];
ll pa[200005], pb[200005], pc[200005];

int cmp(const void *x, const void *y) {
    ll a = *(ll *)x;
    ll b = *(ll *)y;
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int main() {
    scanf("%d%d%lld", &n, &m, &k);
    scanf("%lld%lld", &x, &y);

    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &b[i]);

    qsort(a, n, sizeof(ll), cmp);
    qsort(b, m, sizeof(ll), cmp);

    for (int i = 0; i < n; i++)
        pa[i + 1] = pa[i] + a[i];

    for (int i = 0; i < m; i++) {
        pb[i + 1] = pb[i] + b[i];
        pc[i + 1] = pc[i] + (b[i] + k - 1) / k;
    }

    ll z = x + k * y;
    int ans = 0;

    for (int i = 0; i <= m; i++) {
        if (pc[i] > y) break;

        ll r = z - pb[i];
        if (r < 0) continue;

        int l = 0, h = n;
        while (l < h) {
            int md = (l + h + 1) >> 1
            if (pa[md] <= r) l = md;
            else h = md - 1;
        }
        if (i + l > ans) {
        	ans = i + l;
		}
    }
    printf("%d\n", ans);
}
