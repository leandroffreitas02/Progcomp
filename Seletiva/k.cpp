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

vector<bool> missing(26, true);

int main(){ _

	int k; cin >> k;

	string s; cin >> s;

	for(char c: s) if(c != '?'){
		int aux = c - 'a';
		missing[aux] = false;
	}

	stack<char> q;

	for(int i = 0; i < k; i++) if(missing[i]){
		q.push(i + 'a');
	}

	int l, r;

	l = r = s.size()/2 + s.size()%2 - 1;

	r += !(s.size()%2);

	while(r < s.size()){
		if(s[l] == '?' && s[r] == '?' && !q.empty()){
			s[l] = q.top();
			s[r] = q.top();
			q.pop();
		}
		else if(s[l] == '?' && s[r] == '?' && q.empty()){
			s[l] = 'a';
			s[r] = 'a';
		}
		else if(s[l] == '?' && s[r] != '?')
			s[l] = s[r];

		else if(s[r] == '?' && s[l] != '?')
			s[r] = s[l];

		else if(s[l] != s[r]){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}

		l--, r++;
	}
	cout << (q.empty() ? s : "IMPOSSIBLE") << endl;

	return 0;
}
