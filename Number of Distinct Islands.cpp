/* D4

Number of Distinct Islands

P.S:-Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of
     connected 1s (horizontally or vertically) forms an island.
     Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).


Example 1:
Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we
have only 1 distinct island.

Example 2:
Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.



Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
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
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();

        unordered_set<string> ilands;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1) {
                    string land = findIland(grid, r, c, n, m);
                    //  cout << land << "\n";
                    ilands.insert(land);
                }
            }
        }

        return ilands.size();
    }

    string findIland(vector<vector<int>>& grid, int r, int c, int& n, int& m) {
        if ((r >= n) || r < 0 || (c >= m) || c < 0 || (grid[r][c] == 0))
            return "";

        grid[r][c] = 0;

        string iland = "1";

        //up
        iland += ("u" + findIland(grid, r - 1, c, n, m));

        //right
        iland += ("r" + findIland(grid, r, c + 1, n, m));

        //down
        iland += ("d" + findIland(grid, r + 1, c, n, m));

        //left
        iland += ("l" + findIland(grid, r, c - 1, n, m));

        //  cout << iland << "\n";
        return iland;


    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends