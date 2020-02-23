//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 30 04 2020

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

// defines...
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b))
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

void task()
{
    ll n, m, ans=0;

    cin >> n >> m;

    if(m%n!=0 || (n==1 && m%2!=0 && m%3!=0 && m!=1)){
        cout << "-1\n";
        return ;
    }
    else{
        n = m / n;
    }

    while(1){
        if(n%3==0){
            ans++;
            n /= 3;
        }
        else break;
    }

    while(1){
        if(n%2==0){
            ans++;
            n /= 2;
        }
        else break;
    }

    if(n!=1) cout << "-1\n";
    else cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
