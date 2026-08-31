#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 800010;

long long read() {
	char ch;
	long long ans = 0, f = 1;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}
int tot, head[N], to[N], pre[N];
int ansl[N], ansr[N], n;

void add(int u, int v) {
	to[++tot] = v;
	pre[tot] = head[u];
	head[u] = tot;
}

int dfs(int u, int fa, int l) {
	int lst = l, t = l;
	for (int i = head[u]; i; i = pre[i])
		if (to[i] != fa) {
			lst = dfs(to[i], u, t);
			t = lst + 1;
		}
	ansl[u] = l; ansr[u] = lst;
	return ansr[u];
}

int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; i++) printf("%d %d\n", ansl[i], ansr[i]);
	return 0;
}