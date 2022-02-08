// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
//#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


const int MX = 2e5;
int ara[MX+5], cnt[MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, n, k;
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        
        debug("start");
        
        memset(cnt, 0, sizeof cnt);
        for(int K = 0; K < n ; K++){
            cin >> ara[K];
            cnt[ara[K]]++;
        }
        
        for(int K = 2; K <= n; K++) cnt[K] += cnt[K-1];
        
        int ans = n, ans1 = 1, ans2 = n;
        for(int K = 1; K <= n; K++){
            int sum, l = K, r = n, last = -1, mid;
            while(l <= r){
                mid = (l+r)/2;
                
                sum = 2*cnt[mid]-2*cnt[K-1] - cnt[n];
                
                if(sum >= k){
                    r = mid-1;
                    last = mid;
                }
                else{
                    l = mid+1;
                }
            }
            
            debug(K, last, ans);
            if(last != -1 && last-K+1 < ans){
                ans = last-K+1;
                ans1 = K;
                ans2 = last;
            }
        }
        
        cout << ans1 << ' ' << ans2 << "\n";
        
        int last = 0, c = 0;
        k--;
        for(int K = 0; k && K < n; K++){
            if(ara[K] >= ans1 && ara[K] <= ans2) c++;
            
            if(c > K-c-last+1){
                cout << last+1 << ' ' << K+1 << "\n";
                c = 0;
                last = K+1;
                k--;
            }
            
            //debug(K, ara[K], c, last);
        }
        
        cout << last+1 << ' ' << n << "\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































