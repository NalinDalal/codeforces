/*B. Two Large Bags
time limit per test1 second
memory limit per test256 megabytes

You have two large bags of numbers. Initially, the first bag contains 𝑛
 numbers: 𝑎1,𝑎2,…,𝑎𝑛
, while the second bag is empty. You are allowed to perform the following
operations:

Choose any number from the first bag and move it to the second bag.
Choose a number from the first bag that is also present in the second bag and
increase it by one. You can perform an unlimited number of operations of both
types, in any order. Is it possible to make the contents of the first and second
bags identical?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤1000
) — the length of the array 𝑎
. It is guaranteed that 𝑛
 is an even number.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛2
 over all test cases does not exceed 106
.

Output
For each test case, print "YES" if it is possible to equalize the contents of
the bags. Otherwise, output "NO".

You can output each letter in any case (for example, "YES", "Yes", "yes", "yEs",
"yEs" will be recognized as a positive answer).

Example
InputCopy
9
2
1 1
2
2 1
4
1 1 4 4
4
3 4 3 3
4
2 3 4 4
6
3 3 4 5 3 3
6
2 2 2 4 4 4
8
1 1 1 1 1 1 1 4
10
9 9 9 10 10 10 10 10 10 10
OutputCopy
Yes
No
Yes
Yes
No
Yes
No
Yes
Yes
Note
Let's analyze the sixth test case: we will show the sequence of operations that
leads to the equality of the bags. Initially, the first bag consists of the
numbers (3,3,4,5,3,3) , and the second bag is empty.

In the first operation, move the number 3
 from the first bag to the second. State: (3,4,5,3,3)
 and (3)
.
In the second operation, increase the number 3
 from the first bag by one. This operation is possible because the second bag
contains the number 3 . State: (4,4,5,3,3) and (3)
.
In the third operation, move the number 4
 from the first bag to the second. State: (4,5,3,3)
 and (3,4)
.
In the fourth operation, increase the number 4
 from the first bag by one. State: (5,5,3,3)
 and (3,4)
.
In the fifth operation, move the number 5
 from the first bag to the second. State: (5,3,3)
 and (3,4,5)
.
In the sixth operation, increase the number 3
 from the first bag by one. State: (5,3,4)
 and (3,4,5)
.
As we can see, as a result of these operations, it is possible to make the
contents of the bags equal, so the answer exists.
*/

#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    std::vector<long> v(n + 1);
    for (long p = 0; p < n; ++p) {
      long x;
      std::cin >> x;
      ++v[x];
    }

    bool ans = (n % 2 == 0);
    for (long p = 1; ans && p <= n; ++p) {
      if (!v[p])
        continue;
      else if (v[p] == 1)
        ans = false;
      else if (p < n)
        v[p + 1] += v[p] - 2;
    }

    if (v.back() % 2)
      ans = false;
    std::cout << (ans ? "Yes\n" : "No\n");
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2067/343891508
