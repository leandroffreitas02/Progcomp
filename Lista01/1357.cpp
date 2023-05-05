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

	vector<string> b = {".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..."};


	int d; 
	char c;
	
	while(1){
		cin >> d;

		if(!d) return 0;

		cin >> c;

		if(c == 'S'){
			char s;
			vector<int> digits;


			for(int i = 0; i < d; i++){
				cin >> s;
				digits.pb(s - '0');
			}
			for(int i = 0; i < d; i++){
				cout << b[digits[i]][0] << b[digits[i]][1];
				if( i != d - 1) cout << ' ';
				else cout << endl;
			}
			for(int i = 0; i < d; i++){
				cout << b[digits[i]][2] << b[digits[i]][3];
				if(i != d - 1) cout << ' ';
				else cout << endl;
			}
			for(int i = 0; i < d; i++){
				cout << b[digits[i]][4] << b[digits[i]][5];
				if(i != d - 1) cout << ' ';
				else cout << endl;
			}
		}
		else if(c == 'B'){
			vector<string> aux(d);
			string s;
			for(int i = 0; i < d; i++){
				cin >> s;
				aux[i] += s;
			}
			for(int i = 0; i < d; i++){
				cin >> s;
				aux[i] += s;
			}
			for(int i = 0; i < d; i++){
				cin >> s;
				aux[i] += s;
			}
			vector<string>::iterator it;
			for(int i = 0 ; i < d; i++){
				it = find(b.begin(), b.end(), aux[i]);
				cout << it - b.begin();
			}
			cout << endl;
		}
	}

}
