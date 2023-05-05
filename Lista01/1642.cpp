#include<bits/stdc++.h>
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

const int MAX = 128;

int main(){ _

        while(1){
                int m; cin >> m;
                if(!m) return 0;

                string s; getline(cin, s);
                getline(cin, s);
                int n = s.size();

                int l = 0, r = 0, ans = -1;
                int count = 0;

                vector<int> v(MAX, 0);

                while(r < n){
                        while(count <= m && r < n){
                                if(!v[s[r]]) count++;
                                v[s[r]]++; 
                                r++;
                        }
                        if(count > m){
                                if(v[s[l]] > 0){
                                        v[s[l]]--;
                                        if(!v[s[l]]) count--;
                                }
                                l++;
                        }
                        ans = max(ans, r - l);
                }
                cout << ans << endl;
        }
}
