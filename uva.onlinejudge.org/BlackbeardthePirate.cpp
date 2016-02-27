/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=772&page=show_problem&problem=1878
        Name: Blackbeard the Pirate
        Date: 25/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, DP[11][1<<11], total, dis[11][11], dis2[55][55], limit, dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
ii points[11];
string mat[55];
bool vis[55][55];
queue<ii> q;

void bfs (int origin) {
	memset(vis, 0, sizeof vis);
	vis[points[origin].F][points[origin].S] = true;
	dis2[points[origin].F][points[origin].S] = 0;
	dis[origin][origin] = 0;
	q.push(points[origin]);
	ii u;
	int x, y;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int di=0; di<8; di+=2) {
			x = u.F + dx[di];
			y = u.S + dy[di];
			if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mat[x][y] != '~' && mat[x][y] != '#') {
				dis2[x][y] = dis2[u.F][u.S] + 1;
				if (mat[x][y] != '.') dis[origin][mat[x][y]-'0'] = dis2[x][y];
				q.push(ii(x, y));
				vis[x][y] = true;
			}
		}
	}
}

int dp (int u, int bm) {
	if (DP[u][bm] != -1) return DP[u][bm];
	if (bm == limit) return DP[u][bm] = dis[u][0];
	int aux = INT_MAX;
	for (int v=0; v<total; v++) if ((bm & (1<<v)) == 0) aux = min(aux, dp(v, bm|(1<<v)) + dis[u][v]);
	return DP[u][bm] = aux;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) cin>>mat[i];
		total = 1;
		bool possible = true;
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (mat[i][j] == '@') {
				mat[i][j] = '0';
				points[0] = ii(i, j);
			} else if (mat[i][j] == '!') {
				mat[i][j] = '0'+total;
				points[total++] = ii(i, j);
			} else if (mat[i][j] == '*') {
				for (int di=0; di<8; di++) {
					int x = i + dx[di];
					int y = j + dy[di];
					if (x >= 0 && x < n && y >= 0 && y < m) {
						if (mat[x][y] == '!' || mat[x][y] == '@') possible = false;
						if (mat[x][y] != '*') mat[x][y] = '#';
					}
				}
			}
		}
		for (i=0; i<total; i++) for (j=0; j<total; j++) dis[i][j] = INF;
		for (i=0; i<total; i++) bfs(i);
		for (i=1; i<total; i++) if (dis[0][i] == INF) possible = false;
		if (!possible) cout<<-1<<endl;
		else {
			memset(DP, -1, sizeof DP);
			limit = (1<<total)-1;
			cout<<dp(0, 1)<<endl;
		}
	}
	
	return 0;
}
