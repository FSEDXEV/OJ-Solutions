/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3071
        Name: Theatre Square
        Date: 27/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll n, m, a, ans;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>m>>a;
	cout<<(n / a + ((n % a == 0ll) ? 0ll : 1ll)) * (m / a + ((m % a == 0ll) ? 0ll : 1ll))<<endl;
	
	return 0;
}
