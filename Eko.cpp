/*
    link to the problem: https://www.spoj.com/problems/EKO/
    
    problem statement:
    Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine
    that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

    Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that 
    height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact).
    Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, 
    and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, 
    while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

    Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible.
    Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.
    
    approach: Do binary search over the search space.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPossible(vector<ll> &heights, ll blade_height, const ll wood_needed)
{
    ll wood_taken = 0;
    for (int i = 0; i < (int)heights.size(); i++)
    {
        ll canTake = heights[i] - blade_height;
        wood_taken += (canTake > 0) ? canTake : 0;
    }
    return wood_taken >= wood_needed;
}

ll maxHeight(vector<ll> &heights, const ll wood_needed)
{
    const ll n = heights.size();
    ll maxi = heights[0];
    for (ll i = 1; i < n; i++)
    {
        maxi = max(maxi, heights[i]);
    }
    ll start = 1;
    ll end = maxi;
    ll ans = 0;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossible(heights, mid, wood_needed))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> heights(n);
    for (ll &x : heights)
    {
        cin >> x;
    }
    cout << maxHeight(heights, m) << "\n";
}
