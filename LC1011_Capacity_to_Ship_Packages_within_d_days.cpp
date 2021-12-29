/*
    link to the problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

    PROBLEM STATEMENT:
    A conveyor belt has packages that must be shipped from one port to another within days days.
    The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on 
    the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
    
    approach: Same as allocation of pages problem.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int> &weights, const int mid, const int days) 
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < (int)weights.size(); i++)
    {
        sum += weights[i];
        if (sum > mid)
        {
            cnt++;
            sum = weights[i];
        }
    }
    return cnt <= days;
}

int shipWithinDays(const vector<int> &weights, const int days)
{
    const int n = weights.size();
    int sum_of_weights = 0, maxWeight = INT_MIN + 1;
    for (auto x : weights)
    {
        maxWeight = max(maxWeight, x);
        sum_of_weights += x;
    }
    int low = maxWeight;
    int high = sum_of_weights;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        
        if (isPossible(weights, mid, days))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main() 
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, days;
        cin >> n >> days;
        vector<int> weights(n);
        for (auto& x: weights) cin >> x;
        cout << shipWithinDays(weights, days) << "\n";
    }
    return 0;
}
