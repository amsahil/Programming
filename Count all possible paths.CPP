/* D6

Count all possible paths from top left to bottom right

P.S:- The task is to count all the possible paths from top left to bottom right of a m X n matrix
 with the constraints that from each cell you can either move only to right or down.

Example 1:
Input: m = 2, n = 2
Output: 2
Explanation: Two possible ways are
RD and DR.

Example 2:
Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are
RRDD, DDRR, RDDR, DRRD, RDRD, DRDR.

Constraints:
1 <= m <=100
1 <= n <=100

Expected Time Complexity: O(m*n)
Expected Auxiliary Space: O(m*n)
*/



//--------------------------------------------------------------SOLUTION--------------------------------------------------

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long int numberOfPaths(int m, int n) {
        // code here

        vector<vector<long long>>mat(m, vector<long long>(n, 0));
        int mod = 1e9 + 7;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0)mat[i][j] = 1;
                else if (j == 0)mat[i][j] = 1;
                else mat[i][j] = (mat[i - 1][j] + mat[i][j - 1]) % mod;
            }
        }
        return mat[m - 1][n - 1] % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends