/*
  link to the problem: https://www.spoj.com/problems/AGGRCOW/
  
  problem statement: 
  Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
  His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
  To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance 
  between any two of them is as large as possible. What is the largest minimum distance?
  
  approach: Do binary search over the search space.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPossible(vector<ll>& positions, ll gap, ll total_cows) {
	//putting first cow at pos[0]
	ll cnt = 1;
	ll prevPos = positions[0];
	for (int i = 1; i < (int) positions.size(); i++) {
        if (positions[i] >= prevPos + gap) {
            //we can put a cow here
            cnt++;
            prevPos = positions[i];
        }
        if (cnt == total_cows) {
            return true;
        }
    }
    return false;
}

ll aggcows(ll n, vector<ll>& positions, ll cows) {
	sort(positions.begin(), positions.end());
	ll mini = positions[0];
	ll maxi = positions[n - 1];
	ll start = 1, end = maxi - mini + 1;
	ll ans = 0;
	while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (isPossible(positions, mid, cows)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

            
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, cows;
        cin >> n >> cows;
        vector<ll> positions(n);
        for (auto &x: positions) cin >> x;
        cout << aggcows(n, positions, cows) << "\n";
    } 
    return 0;
}
