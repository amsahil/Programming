/* D2

Sort an array of 0s, 1s and 2s.
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order.

Input:
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated
into ascending order.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2
*/


//--------------------------------------------------------------SOLUTION--------------------------------------------------


//By Dutch Flag Algorithm(TUF)

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // Dutch Flag Algorithm

        int lo = 0;
        int hi = n - 1;
        int mid = 0;

        while (mid <= hi) {
            switch (a[mid]) {

            // If the element is 0
            case 0:
                swap(a[lo++], a[mid++]);
                break;

            // If the element is 1 .
            case 1:
                mid++;
                break;

            // If the element is 2
            case 2:
                swap(a[mid], a[hi--]);
                break;
            }
        }
    }

};