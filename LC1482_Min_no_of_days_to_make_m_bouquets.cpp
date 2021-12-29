/*
    link to the problem: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
    
    PROBLEM STATEMENT:
    You are given an integer array bloomDay, an integer m and an integer k.
    You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
    The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
    Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

class Solution {
public:
    bool canWeMake(vector<int>& bloomDay, int m, int k, int day) {
        vector<bool> isBloomed(bloomDay.size(), false);
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                isBloomed[i] = true;
            }
        }
        
        int countofBouquet = 0, countOfBloomedAdjacent = 0;
        for (int i = 0; i < isBloomed.size(); i++) {
            if (!isBloomed[i]) {
                if (countOfBloomedAdjacent >= k) {
                    countofBouquet += countOfBloomedAdjacent / k;
                }
                countOfBloomedAdjacent = 0;
            }
            else {
                countOfBloomedAdjacent++;
            }
        }
        if (countOfBloomedAdjacent >= k) {
            countofBouquet += countOfBloomedAdjacent / k;
        }
        return countofBouquet >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < k * m) {
            return -1;
        }
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canWeMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
