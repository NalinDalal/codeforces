/*C. Dora and Search
time limit per test1 second
memory limit per test256 megabytes
As you know, the girl Dora is always looking for something. This time she was
given a permutation, and she wants to find such a subsegment of it that none of
the elements at its ends is either the minimum or the maximum of the entire
subsegment. More formally, you are asked to find the numbers 𝑙 and 𝑟 (1≤𝑙≤𝑟≤𝑛)
 such that 𝑎𝑙≠min(𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟)
, 𝑎𝑙≠max(𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟)
 and 𝑎𝑟≠min(𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟)
, 𝑎𝑟≠max(𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟)
.

A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in any order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 occurs twice in the array) and [1,3,4]
 is also not a permutation (𝑛=3
, but 4
 is present in the array).

Help Dora find such a subsegment, or tell her that such a subsegment does not
exist.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Description of the test cases
follows.

For each test case, the first line contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of permutation.

The second line contains 𝑛
 distinct integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of permutation.

It is guarented that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, output −1
 if the desired subsegment does not exist.

Otherwise, output two indexes 𝑙,𝑟
 such that [𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟]
 satisfies all conditions.

If there are several solutions, then output any of them.

Example
InputCopy
4
3
1 2 3
4
2 1 4 3
7
1 3 2 4 6 5 7
6
2 3 6 5 4 1
OutputCopy
-1
1 4
2 6
-1
Note
In the first and fourth test cases, it can be shown that there are no desired
subsegments.

In the second test case, the subsegment [1,4]
 satisfies all the conditions, because max(𝑎1,𝑎2,𝑎3,𝑎4)=4,min(𝑎1,𝑎2,𝑎3,𝑎4)=1
, as we see, all the conditions are met.

In the third test case, the subsegment [2,6]
 also satisfies all the conditions described.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;

  while (t--) {
    long n;
    cin >> n;

    vector<long> a(n);
    for (auto &x : a)
      cin >> x;

    long left = 0, right = n - 1;
    long mn = 1, mx = n;

    while (left < right) {
      if (a[left] == mn) {
        ++left;
        ++mn;
      } else if (a[right] == mn) {
        --right;
        ++mn;
      } else if (a[left] == mx) {
        ++left;
        --mx;
      } else if (a[right] == mx) {
        --right;
        --mx;
      } else {
        break;
      }
    }

    if (left < right)
      cout << left + 1 << " " << right + 1 << '\n';
    else
      cout << -1 << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1793/342207405
