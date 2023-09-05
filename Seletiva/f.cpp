#include <bits/stdc++.h>
using namespace std;

#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
double R, r;

bool solve(){
	if(r > R) return false;
	if(r > R/2) return n <= 1;

	double ang = asin(r/(R-r));
	return int(M_PI/ang + 0.000001) >= n;
}

int main(){ _

	cin >> n >> R >> r;

	cout << (solve() ? "YES" : "NO") << endl;

	return 0;
}
