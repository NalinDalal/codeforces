/*C. Polycarp Recovers the Permutation
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp wrote on a whiteboard an array 𝑝
 of length 𝑛
, which is a permutation of numbers from 1
 to 𝑛
. In other words, in 𝑝
 each number from 1
 to 𝑛
 occurs exactly once.

He also prepared a resulting array 𝑎
, which is initially empty (that is, it has a length of 0
).

After that, he did exactly 𝑛
 steps. Each step looked like this:

Look at the leftmost and rightmost elements of 𝑝
, and pick the smaller of the two.
If you picked the leftmost element of 𝑝
, append it to the left of 𝑎
; otherwise, if you picked the rightmost element of 𝑝
, append it to the right of 𝑎
.
The picked element is erased from 𝑝
.
Note that on the last step, 𝑝
 has a length of 1
 and its minimum element is both leftmost and rightmost. In this case, Polycarp
can choose what role the minimum element plays. In other words, this element can
be added to 𝑎 both on the left and on the right (at the discretion of Polycarp).

Let's look at an example. Let 𝑛=4
, 𝑝=[3,1,4,2]
. Initially 𝑎=[]
. Then:

During the first step, the minimum is on the right (with a value of 2
), so after this step, 𝑝=[3,1,4]
 and 𝑎=[2]
 (he added the value 2
 to the right).
During the second step, the minimum is on the left (with a value of 3
), so after this step, 𝑝=[1,4]
 and 𝑎=[3,2]
 (he added the value 3
 to the left).
During the third step, the minimum is on the left (with a value of 1
), so after this step, 𝑝=[4]
 and 𝑎=[1,3,2]
 (he added the value 1
 to the left).
During the fourth step, the minimum is both left and right (this value is 4
). Let's say Polycarp chose the right option. After this step, 𝑝=[]
 and 𝑎=[1,3,2,4]
 (he added the value 4
 to the right).
Thus, a possible value of 𝑎
 after 𝑛
 steps could be 𝑎=[1,3,2,4]
.

You are given the final value of the resulting array 𝑎
. Find any possible initial value for 𝑝
 that can result the given 𝑎
, or determine that there is no solution.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases in the test.

Each test case consists of two lines. The first of them contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array 𝑎
. The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of the array 𝑎
. All elements of the 𝑎
 array are distinct numbers.

It is guaranteed that the sum of the values 𝑛
 over all test cases in the test does not exceed 2⋅105
.

Output
Print 𝑡
 lines, each of the lines must contain the answer to the corresponding set of
input data: numbers 𝑝1,𝑝2,…,𝑝𝑛 — any of the possible initial values of the array
𝑝 , which will lead to the given array 𝑎 . All elements of 𝑝 are distinct
integers from 1 to 𝑛 . Thus, if there are several solutions, print any. If there
is no solution, then print -1 on the line.

Example
InputCopy
4
4
1 3 2 4
1
1
5
1 3 5 4 2
3
3 2 1
OutputCopy
3 1 4 2
1
-1
2 3 1
Note
The first test case in the example is clarified in the main section of the
problem statement. There may be other correct answers for this test set.

In the second test case, 𝑛=1
. Thus, there is only one permutation that can be the answer: 𝑝=[1]
. Indeed, this is the answer to this test case.

In the third test case of the example, no matter what permutation you take as 𝑝
, after applying the 𝑛
 steps, the result will differ from 𝑎=[1,3,5,4,2]
.
*/

/*given with final array a, find original array p
 Start with permutation p of size n.

Repeatedly pick the smaller of leftmost / rightmost in p.

If smaller = leftmost → push to left of a.

If smaller = rightmost → push to right of a.

Remove it from p.

Repeat until empty.

We are given only the final a. Need to find a possible p or output -1.
*/
/*Read n and array a.

If neither a[0] == 1 nor a[n-1] == 1 → print -1.

Else:

If a[0] == 1: output a as-is.
the maximum element (n) must always end up on one of the ends in a, so p must be
reconstructible from that Else (so a[n-1] == 1): output [a[n-1], a[0], a[1],
..., a[n-2]].
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    if (a[0] != n && a.back() != n) {
      cout << -1 << "\n";
      continue;
    }

    deque<int> d;
    int left = 0, right = n - 1;
    while (left <= right) {
      if (a[left] < a[right]) {
        d.push_front(a[left]);
        left++;
      } else {
        d.push_back(a[right]);
        right--;
      }
    }

    for (int i = 0; i < (int)d.size(); i++) {
      cout << d[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1611/337486229
