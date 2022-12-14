/* D13

Number of Islands

P.S:- You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

Example 1:
Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011

Example 2:
Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010

Constraints:
1 <= n,m <= 100
1 <= k <= 1000

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

*/


//--------------------------------------------------------------SOLUTION-----------------------------------------------





//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    void dfs( vector<vector<int>>& v, int l, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || v[i][j] != l)
            return ;

        v[i][j] += 1;
        dfs(v, l, i + 1, j, n, m);
        dfs(v, l, i, j + 1, n, m);
        dfs(v, l, i - 1, j, n, m);
        dfs(v, l, i, j - 1, n, m);

    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        vector<int> ans;
        vector<vector<int>> v(n, vector<int> (m, 0));

        int l = 1;
        for (auto &it : operators) {
            v[it[0]][it[1]] = l;
            int ct = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                {
                    if (v[i][j] == l) {
                        dfs(v, l, i, j, n, m);
                        ct++;
                    }
                }

            }
            l++;
            ans.push_back(ct);


        }

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++) {
            vector<int> temp;
            for (int j = 0; j < 2; j++) {
                int x; cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)cout << x << " ";
        cout << "\n";
    }
}

// } Driver Code Ends