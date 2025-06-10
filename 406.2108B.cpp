/*B. SUMdamental Decomposition
time limit per test1 second
memory limit per test256 megabytes

On a recent birthday, your best friend Maurice gave you a pair of numbers 𝑛
 and 𝑥
, and asked you to construct an array of positive numbers 𝑎
 of length 𝑛
 such that 𝑎1⊕𝑎2⊕⋯⊕𝑎𝑛=𝑥
 ∗
.

This task seemed too simple to you, and therefore you decided to give Maurice a
return gift by constructing an array among all such arrays that has the smallest
sum of its elements. You immediately thought of a suitable array; however, since
writing it down turned out to be too time-consuming, Maurice will have to settle
for just the sum of its elements.

∗
⊕
 denotes the bitwise XOR operation.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

Each test case consists of a single line containing a pair of numbers 𝑛
 and 𝑥
 (1≤𝑛≤109,0≤𝑥≤109
) — the numbers given to you by Maurice.

Output
For each test case, output your gift to Maurice — the sum of the elements of the
array that satisfies all the described properties. If a suitable array does not
exist, output −1
.

Example
InputCopy
8
2 1
3 6
1 0
2 0
5 0
2 27
15 43
12345678 9101112
OutputCopy
5
8
-1
2
8
27
55
21446778
Note
In the first test case, one of the suitable arrays is [2,3]
. It can be shown that it is impossible to achieve a smaller sum of array
elements.

In the second case, one of the suitable arrays is [1,3,4]
. It can also be shown that this is the optimal amount.



*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, x;
    cin >> n >> x;

    long b = 0, y = x;
    while (y) {
      b += (y % 2);
      y /= 2;
    }

    long ans = 0;
    if (n <= b) {
      ans = x;
    } else if ((n - b) % 2 == 0) {
      ans = x + (n - b);
    } else {
      if (x == 0) {
        ans = (n == 1 ? -1 : (n + 3));
      } else if (x == 1) {
        ans = n + 3;
      } else {
        ans = x + (n - b) + 1;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2108/323712298
