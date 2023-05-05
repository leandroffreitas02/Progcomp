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

	int n;

	while(cin >> n){

		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool fq = true, fs = true, fpq = true;
		
		while(n--){
			int a, b; cin >> a >> b;

			if(a == 1){
				q.push(b);
				s.push(b);
				pq.push(b);
			}
			else{
				if(b != q.front()) fq = false;
				if(b != s.top()) fs = false;
				if(b != pq.top()) fpq = false;
				q.pop(); s.pop(); pq.pop();
			}
		}
		if(!fq && !fs && !fpq) cout << "impossible" << endl;
		else if((fq && fs) || (fq && fpq) || (fs && fpq)) cout << "not sure" << endl;
		else if(fq) cout << "queue" << endl;
		else if(fs) cout << "stack" << endl;
		else if(fpq) cout << "priority queue" << endl;
	}

	return 0;
}
