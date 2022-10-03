/* D5

Modified Numbers and Queries

Number of Distinct Islands

P.S:-Find the sum of all the numbers between the range l and r. Here each number is represented by the sum of its prime factors.

Note : For example, 6 is represented by 5 because 6 has two prime factors 2 and 3 and 2 + 3 = 5.

Example 1:
Input: l = 1, r = 2
Output: 3
Explanation: 1->1, 2->2 and 1+2=3.

Example 2:
Input: l = 1, r = 6
Output: 18
Explanation: 1->1, 2->2, 3->3, 4->2
5->5, 6->2+3=5, 1+2+3+2+5+5 = 18.



Constraints:
1 <= l <= r <=104

Expected Time Complexity: O(nloglogn)
Expected Auxiliary Space: O(n)
*/



//--------------------------------------------------------------SOLUTION--------------------------------------------------

//Sieve Of Eratosthenes can be used to solve this problem.

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:

    int primeFactor(int n)
    {
        int x = 0;
        if (n == 1 || n == 2 || n == 3) {
            return n;
        }
        set<int> s;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                s.insert(i);
                n = n / i;
            }
        }
        vector<int> v(s.begin(), s.end());
        for (int i = 0; i < v.size(); i++) {
            x += v[i];
        }
        return x;
    }

    int sumOfAll(int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += primeFactor(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        Solution ob;
        cout << ob.sumOfAll(l, r) << endl;
    }
    return 0;
}

// } Driver Code Ends