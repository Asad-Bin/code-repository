//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int n, x;

    cin >> n;
    vector<int> boss(n+1);

    for(int K=1; K<n; K++){
        cin >> x;

        boss[x]++;
    }

    for(int K=1; K<=n; K++) cout << boss[K] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

