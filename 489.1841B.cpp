/*B. Keep it Beautiful
time limit per test2 seconds
memory limit per test512 megabytes
The array [𝑎1,𝑎2,…,𝑎𝑘]
 is called beautiful if it is possible to remove several (maybe zero) elements
from the beginning of the array and insert all these elements to the back of the
array in the same order in such a way that the resulting array is sorted in
non-descending order.

In other words, the array [𝑎1,𝑎2,…,𝑎𝑘]
 is beautiful if there exists an integer 𝑖∈[0,𝑘−1]
 such that the array [𝑎𝑖+1,𝑎𝑖+2,…,𝑎𝑘−1,𝑎𝑘,𝑎1,𝑎2,…,𝑎𝑖]
 is sorted in non-descending order.

For example:

[3,7,7,9,2,3]
 is beautiful: we can remove four first elements and insert them to the back in
the same order, and we get the array [2,3,3,7,7,9] , which is sorted in
non-descending order; [1,2,3,4,5] is beautiful: we can remove zero first
elements and insert them to the back, and we get the array [1,2,3,4,5] , which
is sorted in non-descending order; [5,2,2,1] is not beautiful. Note that any
array consisting of zero elements or one element is beautiful.

You are given an array 𝑎
, which is initially empty. You have to process 𝑞
 queries to it. During the 𝑖
-th query, you will be given one integer 𝑥𝑖
, and you have to do the following:

if you can append the integer 𝑥𝑖
 to the back of the array 𝑎
 so that the array 𝑎
 stays beautiful, you have to append it;
otherwise, do nothing.
After each query, report whether you appended the given integer 𝑥𝑖
, or not.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two lines. The first line contains one integer 𝑞
 (1≤𝑞≤2⋅105
) — the number of queries. The second line contains 𝑞
 integers 𝑥1,𝑥2,…,𝑥𝑞
 (0≤𝑥𝑖≤109
).

Additional constraint on the input: the sum of 𝑞
 over all test cases does not exceed 2⋅105
).

Output
For each test case, print one string consisting of exactly 𝑞
 characters. The 𝑖
-th character of the string should be 1 if you appended the integer during the 𝑖
-th query; otherwise, it should be 0.

Example
InputCopy
3
9
3 7 7 9 2 4 6 3 4
5
1 1 1 1 1
5
3 2 1 2 3
OutputCopy
111110010
11111
11011
Note
Consider the first test case of the example. Initially, the array is []
.

trying to append an integer 3
. The array [3]
 is beautiful, so we append 3
;
trying to append an integer 7
. The array [3,7]
 is beautiful, so we append 7
;
trying to append an integer 7
. The array [3,7,7]
 is beautiful, so we append 7
;
trying to append an integer 9
. The array [3,7,7,9]
 is beautiful, so we append 9
;
trying to append an integer 2
. The array [3,7,7,9,2]
 is beautiful, so we append 2
;
trying to append an integer 4
. The array [3,7,7,9,2,4]
 is not beautiful, so we don't append 4
;
trying to append an integer 6
. The array [3,7,7,9,2,6]
 is not beautiful, so we don't append 6
;
trying to append an integer 3
. The array [3,7,7,9,2,3]
 is beautiful, so we append 3
;
trying to append an integer 4
. The array [3,7,7,9,2,3,4]
 is not beautiful, so we don't append 4
.
*/

// array is beautiful if if we rotate it to make non decreasing
/*start: the first element (a[0])

last: the last appended element

rotated: flag to check if we have already passed the drop point


*/
/*Appending Rules:

If not rotated:
    - Can append if x >= last  → normal increasing
    - Can append if x <= start → start of rotated part
    - Else → can't append

If rotated:
    - Can append if last <= x && x <= start
    - Else → can't append
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int q;
    cin >> q;
    vector<int> a;
    int start = -1, last = -1;
    bool rotated = false;
    string res;

    for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;

      if (a.empty()) {
        a.push_back(x);
        start = x;
        last = x;
        res += '1';
      } else if (!rotated) {
        if (x >= last) {
          a.push_back(x);
          last = x;
          res += '1';
        } else if (x <= start) {
          a.push_back(x);
          last = x;
          rotated = true;
          res += '1';
        } else {
          res += '0';
        }
      } else {
        if (x >= last && x <= start) {
          a.push_back(x);
          last = x;
          res += '1';
        } else {
          res += '0';
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1841/328355869
