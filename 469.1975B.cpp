/*B. 378QAQ and Mocha's Array
time limit per test1 second
memory limit per test256 megabytes
Mocha likes arrays, so before her departure, 378QAQ gave her an array 𝑎
 consisting of 𝑛
 positive integers as a gift.

Mocha thinks that 𝑎
 is beautiful if there exist two numbers 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
, 𝑖≠𝑗
) such that for all 𝑘
 (1≤𝑘≤𝑛
), 𝑎𝑘
 is divisible†
 by either 𝑎𝑖
 or 𝑎𝑗
.

Determine whether 𝑎
 is beautiful.

†
 𝑥
 is divisible by 𝑦
 if there exists an integer 𝑧
 such that 𝑥=𝑦⋅𝑧
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output "Yes" if array 𝑎
 is beautiful, and output "No" otherwise.

You can output "Yes" and "No" in any case (for example, strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive response).

Example
InputCopy
4
3
7 3 8
5
7 1 9 3 5
5
4 12 2 6 3
5
7 49 9 3 1000000000
OutputCopy
No
Yes
Yes
No
Note
In the first test case, any two numbers in the array are coprime, so the answer
is "No".

In the second test case, we can pick 𝑖=2
 and 𝑗=1
. Since every number in the array is divisible by 𝑎𝑖=1
, the answer is "Yes".

In the third test case, we can pick 𝑖=3
 and 𝑗=5
. 2
 and 4
 is divisible by 𝑎𝑖=2
 while 3
, 6
 and 12
 is divisible by 𝑎𝑗=3
, so the answer is "Yes".



*/
#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p];
    }
    long a = 1e9 + 7;
    for (long p = 0; p < n; p++) {
      a = (v[p] < a ? v[p] : a);
    }
    long b = 1e9 + 7;
    for (long p = 0; p < n; p++) {
      if (v[p] % a == 0) {
        continue;
      }
      b = (v[p] < b ? v[p] : b);
    }

    bool ans = true;
    for (long p = 0; ans && p < n; p++) {
      if ((v[p] % a) && (v[p] % b)) {
        ans = false;
      }
    }

    std::cout << (ans ? "Yes" : "No") << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1975/327262856
