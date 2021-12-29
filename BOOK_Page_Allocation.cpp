/*
    link to the problem: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
    
    PROBLEM STATEMENT:
    You are given N number of books. Every ith book has Ai number of pages and are arranged in sorted order.
    You have to allocate contagious books to M number of students. There can be many ways or permutations to do so. 
    In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, 
    the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of 
    those in all the other permutations and print this minimum value.
    Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int> &pages, const int load, const int students)
{
    // load denotes the no of pages allocated to a student
    const int n = pages.size();
    int sum = 0, cnt = 1;
    int i = 0;
    while (i < n)
    {
        if (sum + pages[i] <= load)
        {
            sum += pages[i];
        }
        else
        {
            cnt++;
            sum = pages[i];
        }
        i++;
    }
    return cnt <= students;
}

int findPages(const vector<int> &pages, const int students)
{
    // first take the sum and max of the pages array
    const int n = pages.size();
    int sum_of_full = 0;
    int maxi = INT_MIN + 1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, pages[i]);
        sum_of_full += pages[i];
    }

    int low = maxi;
    int high = sum_of_full;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (isPossible(pages, mid, students))
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
        int n, m;
        cin >> n >> m;
        vector<int> pages(n);
        for (auto &x : pages)
            cin >> x;
        cout << findPages(pages, m) << "\n";
    }
    return 0;
}
// time complexity: O(N*log(sum(pages)))
