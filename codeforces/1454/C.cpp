//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
 
#include <bits/stdc++.h>
 
using namespace std;
 
// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
 
// constants...
const double PI = acos(-1);
const int MOD = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e18+5;
 
// defines...
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
 
// structs...
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
 
// functions...
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)*b);
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;
 
    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }
 
    return ans;
}


void task()
{
	// Code here...
	
	int t, n, ara[200005];
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int K=0; K<n; K++) cin >> ara[K];
		
		if(n==1){
			cout << 0 << "\n";
			continue;
		}
		else if(n==2){
			if(ara[0]==ara[1]) cout << 0 << "\n";
			else cout << 1 << "\n";
			continue;
		}
		
		vector<vi> v(n+1);
		
		for(int K=0; K<n; K++){
			v[ara[K]].PB(K);
		}
		
		for(int K=1; K<=n; K++){
			sort(all(v[K]));
		}
		
		
		int ans = MXI, cnt;
		for(int K=1; K<=n; K++){
			if(sz(v[K])==n){
				ans = 0;
				break;
			}
			
			cnt = sz(v[K])+1;
			
			if(sz(v[K])>0 && v[K][0]==0) cnt--;
			if(sz(v[K])>0 && v[K].back()==n-1) cnt--;
			
			for(int L=1; L<sz(v[K]); L++){
				if(v[K][L]==v[K][L-1]+1) cnt--;
			}
			
			if(sz(v[K])!=0) ans = min(ans, cnt);
		}
		
		cout << ans << "\n";
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	task();
 
    return 0;
}
