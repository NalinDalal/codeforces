/*B. Shrinking Array
time limit per test2 seconds
memory limit per test256 megabytes
Let's call an array 𝑏
 beautiful if it consists of at least two elements and there exists a position 𝑖
 such that |𝑏𝑖−𝑏𝑖+1|≤1
 (where |𝑥|
 is the absolute value of 𝑥
).

You are given an array 𝑎
, and as long as it consists of at least two elements, you can perform the
following operation:

Choose two adjacent positions 𝑖
 and 𝑖+1
 in the array 𝑎
.
Choose an integer 𝑥
 such that min(𝑎𝑖,𝑎𝑖+1)≤𝑥≤max(𝑎𝑖,𝑎𝑖+1)
.
Remove the numbers 𝑎𝑖
 and 𝑎𝑖+1
 from the array, and insert the number 𝑥
 in their place. Obviously, the size of the array will decrease by 1
.
Calculate the minimum number of operations required to make the array beautiful,
or report that it is impossible.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤200
) — the number of test cases.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤1000
) — the size of the array 𝑎
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
) — the array 𝑎
 itself.

Output
For each test case, output one integer — the minimum number of operations needed
to make the array 𝑎 beautiful, or −1 if it is impossible to make it beautiful.

Example
InputCopy
4
4
1 3 3 7
2
6 9
4
3 1 3 7
4
1 3 5 2
OutputCopy
0
-1
1
1
Note
In the first test case, the given array is already beautiful, as |𝑎2−𝑎3|=|3−3|=0
.

In the second test case, it is impossible to make the array beautiful, as
applying the operation would reduce its size to less than two.

In the third test case, you can, for example, choose 𝑎1
 and 𝑎2
 and replace them with the number 2
. The resulting array [2,3,7]
 is beautiful.

In the fourth test case, you can, for example, choose 𝑎2
 and 𝑎3
 and replace them with the number 3
. The resulting array [1,3,2]
 is beautiful.
*/
// v is beautiful if there xists a position i such that
//|v[i]-v[i+1]|<=1
// choose two position i, i+1
// find a num `x` that lies b/w min(v[i],v[i+1]) and max(v[i],v[i+1])
// remove v[i] and v[i+1] and put x in thier place
// output min operation required to make it beautiful
// else output -1
/*If already beautiful → 0

Else if n == 2 → -1 (cannot fix)

Else (n ≥ 3) → 1 (you can always merge something to create a valid pair)*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    long pprev;
    scanf("%ld", &pprev);
    long prev;
    scanf("%ld", &prev);
    int ans =
        (prev == pprev || prev == pprev + 1 || prev == pprev - 1) ? 0 : -1;
    for (long p = 2; p < n; p++) {
      long x;
      scanf("%ld", &x);
      if (ans < 0) {
        if (pprev < prev && prev > x) {
          ans = 1;
        } else if (pprev > prev && prev < x) {
          ans = 1;
        }
      }

      if (ans) {
        if (pprev == prev || prev == x) {
          ans = 0;
        } else if (prev == pprev - 1 || prev == pprev + 1) {
          ans = 0;
        } else if (prev == x - 1 || prev == x + 1) {
          ans = 0;
        }
      }

      pprev = prev;
      prev = x;
    }

    printf("%d\n", ans);
  }
}
// sub: https://codeforces.com/problemset/submission/2112/338553227
