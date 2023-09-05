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

bool prime(int n){
    if(n <= 1) return false;

    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int func(int n){
    string s = to_string(n);

    if(s.size() < 2) return -1;
    if(prime(n)) return n;

    int ret = -1;

    for(int i = 0; i < s.size(); i++){
        string s1 = s;
        s1.erase(s1.begin() + i);
        
        int n1 = stoi(s1);
        
        ret = func(n1);

        if(ret != -1) return ret;
    }
    return -1;
}

int main(){ _

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        cout << func(n) << endl;
    }

}