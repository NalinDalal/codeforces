/* https://codeforces.com/problemset/problem/1789/A
A. Serval and Mocha's Array
time limit per test1 second
memory limit per test256 megabytes

Mocha likes arrays, and Serval gave her an array consisting of positive integers
as a gift.Mocha thinks that for an array of positive integers 𝑎, it is good iff
the greatest common divisor of all the elements in 𝑎 is no more than its length.
And for an array of at least 2 positive integers, it is beautiful iff all of its
prefixes whose length is no less than 2 are good.

For example:
[3,6] is not good, because gcd(3,6)=3 is greater than its length 2.
[1,2,4] is both good and beautiful, because all of its prefixes whose length is
no less than 2, which are [1,2] and [1,2,4], are both good. [3,6,1] is good but
not beautiful, because [3,6] is not good.

Now Mocha gives you the gift array 𝑎 of 𝑛 positive integers, and she wants to
know whether array 𝑎 could become beautiful by reordering the elements in 𝑎. It
is allowed to keep the array 𝑎 unchanged.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (2≤𝑛≤100) — the
length of array 𝑎.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛
(1≤𝑎1,𝑎2,…,𝑎𝑛≤106) — the elements of array 𝑎.

Output
For each test case, print Yes if it is possible to reorder the elements in 𝑎 to
make it beautiful, and print No if not.

You can output Yes and No in any case (for example, strings yEs, yes, Yes and
YES will be recognized as a positive response).

Example
InputCopy
6
2
3 6
3
1 2 4
3
3 6 1
3
15 35 21
4
35 10 35 14
5
1261 227821 143 4171 1941
OutputCopy
No
Yes
Yes
No
Yes
Yes

Note
In the first test case, neither [3,6] nor [6,3] are beautiful, so it's
impossible to obtain a beautiful array by reordering the elements in 𝑎. In the
second test case, [1,2,4] is already beautiful. Keeping the array 𝑎 unchanged
can obtain a beautiful array.
*/

// good logic-> hcf of array<array.length
// but i think it's for like increase for each element; it is beautiful iff all
// of its prefixes whose length is no less than 2 are good Sort the array to
// process prefixes in order Start with the first element Compute GCD of the
// prefix Check if GCD exceeds the length of the prefix If all prefixes satisfy
// the condition, the array is beautiful
#include <cstdio>
#include <vector>

long gcd(long a, long b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &a[p]);
    }
    bool res(false);
    for (long p = 0; !res && p < n; p++) {
      for (long q = p + 1; !res && q < n; q++) {
        if (gcd(a[p], a[q]) <= 2) {
          res = true;
        }
      }
    }

    puts(res ? "Yes" : "No");
  }
}
// sub: https://codeforces.com/problemset/submission/1789/301286225
