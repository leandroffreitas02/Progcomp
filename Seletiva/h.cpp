#include <bits/stdc++.h>
using namespace std;

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

int main(){ _
	int ans;

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			int x; cin >> x;

			if(x){
				ans = abs(3 - i - 1) + abs(3 - j - 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
