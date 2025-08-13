/*A. Sasha and the Beautiful Array
time limit per test1 second
memory limit per test256 megabytes
Sasha decided to give his girlfriend an array 𝑎1,𝑎2,…,𝑎𝑛
. He found out that his girlfriend evaluates the beauty of the array as the sum
of the values (𝑎𝑖−𝑎𝑖−1) for all integers 𝑖 from 2 to 𝑛
.

Help Sasha and tell him the maximum beauty of the array 𝑎
 that he can obtain, if he can rearrange its elements in any way.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

Output
For each test case, output a single integer — the maximum beauty of the array 𝑎
 that can be obtained.

Example
InputCopy
5
3
2 1 3
3
69 69 69
5
100 54 80 43 90
4
3 4 3 3
2
2 1
OutputCopy
2
0
57
1
1
Note
In the first test case, the elements of the array 𝑎
 can be rearranged to make 𝑎=[1,2,3]
. Then its beauty will be equal to (𝑎2−𝑎1)+(𝑎3−𝑎2)=(2−1)+(3−2)=2
.

In the second test case, there is no need to rearrange the elements of the array
𝑎 . Then its beauty will be equal to 0
.
*/

// given an array of size n
// create another array of size n-1, where
// v[i]=a[i+1]-a[i]; original condition-> a[i]-a[i-1]
// find sum of this array
// now if we sort the array then the sum will become maximum
// screw that, just do this:
/*for(long p = 0; p < n; p++){
            long x; scanf("%ld", &x);
            mn = (mn < x) ? mn : x;
            mx = (mx > x) ? mx : x;
        }

        printf("%ld\n", mx - mn);
*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long mn = 1e9 + 7, mx = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      mn = (mn < x) ? mn : x;
      mx = (mx > x) ? mx : x;
    }
    cout << (mx - mn) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1929/333740846
