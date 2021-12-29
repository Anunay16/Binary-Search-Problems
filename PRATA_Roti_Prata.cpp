/*
    link to the problem: https://www.spoj.com/problems/PRATA/
    
    PROBLEM STATEMENT: 
    IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members 
    are asked to go to food connection and get P(P<=1000) pratas packed for the function. The stall has L cooks(L<=50) and each 
    cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes,
    1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one
    prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 
    pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to
    know the minimum time to get the order done. Please write a program to help him out.
    
    THINKING APPROACH:
    total parata needed: P; user input
    total cooks: L; user input
    l1 l2 l3 l4 : 4 cooks (say), where Li is the rank of the corresponding cook
    time intervals to make pratas: R...2R...3R....
    min time to cook all the paratas??

    search space min: 1
    search space max???
    max rank of a cook is 8 (given constraints)
    say we have to cook 3 paratas
    so: 8 + 16 + 24 = 48 = sum of AP series upto P terms with common diff 8
    search space max will be: (P/2)*[2 * 8 + (p - 1) * 8] = (p/2)*(8*p + 8) = 4*p*(p + 1)

    now, the problem is to figure out whether P paratas can be made within 'mid' time??
    we can find how many paratas can me made all total by all cooks and then compare with 
    how much do we need. We will require two loops.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPossible(const vector<ll>& cook_ranks, const ll time, const ll paratas_needed) {
    ll canBeMade = 0;
    for (auto& rank: cook_ranks) {
        ll canBeMadeByThis = 0;
        ll timeForThis = 0;
        ll multiplier = 1;
        while (true) {
            timeForThis += (rank * multiplier);
            multiplier++;
            if (timeForThis <= time) {
                canBeMadeByThis++;
            }
            else break;
        }
        canBeMade += canBeMadeByThis;
    }
    return canBeMade >= paratas_needed;
}

ll getMinTime(const ll paratas_needed, const vector<ll>& cook_ranks) {
    const ll n = cook_ranks.size();
    ll start = 1;
    ll end = 4 * paratas_needed * (paratas_needed + 1);
    ll ans = 0;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (isPossible(cook_ranks, mid, paratas_needed)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll P, L;
        cin >> P >> L;
        vector<ll> cooks(L);
        for (auto& x: cooks) cin >> x;
        cout << getMinTime(P, cooks) << "\n";
    }
}
