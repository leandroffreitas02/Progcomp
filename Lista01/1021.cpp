#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	float N; cin >> N;

	cout << fixed << setprecision(2);
	cout << "NOTAS:" << endl;
	N += 1e-3;

	vector<float> v = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.10, 0.05, 0.01};

	for(float x: v){
		int count = 0;

		while(N > x){
			N -= x;
			count++;
		}

		if(x == 1) cout << "MOEDAS:" << endl;
		if(x > 1) cout << count << " nota(s) de R$ " << x << endl;
		else cout << count << " moeda(s) de R$ " << x << endl;
	}


	return 0;
}
