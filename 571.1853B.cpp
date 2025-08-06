/*B. Fibonaccharsis
time limit per test2 seconds
memory limit per test256 megabytes
Ntarsis has received two integers 𝑛
 and 𝑘
 for his birthday. He wonders how many fibonacci-like sequences of length 𝑘
 can be formed with 𝑛
 as the 𝑘
-th element of the sequence.

A sequence of non-decreasing non-negative integers is considered fibonacci-like
if 𝑓𝑖=𝑓𝑖−1+𝑓𝑖−2 for all 𝑖>2 , where 𝑓𝑖 denotes the 𝑖 -th element in the
sequence. Note that 𝑓1 and 𝑓2 can be arbitrary.

For example, sequences such as [4,5,9,14]
 and [0,1,1]
 are considered fibonacci-like sequences, while [0,0,0,1,1]
, [1,2,1,3]
, and [−1,−1,−2]
 are not: the first two do not always satisfy 𝑓𝑖=𝑓𝑖−1+𝑓𝑖−2
, the latter does not satisfy that the elements are non-negative.

Impress Ntarsis by helping him with this task.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤2⋅105
), the number of test cases. The description of each test case is as follows.

Each test case contains two integers, 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105
, 3≤𝑘≤109
).

It is guaranteed the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case output an integer, the number of fibonacci-like sequences of
length 𝑘 such that the 𝑘 -th element in the sequence is 𝑛 . That is, output the
number of sequences 𝑓 of length 𝑘 so 𝑓 is a fibonacci-like sequence and 𝑓𝑘=𝑛 .
It can be shown this number is finite.

Example
InputCopy
8
22 4
3 9
55 11
42069 6
69420 4
69 1434
1 3
1 4
OutputCopy
4
0
1
1052
11571
0
1
0
Note
There are 4
 valid fibonacci-like sequences for 𝑛=22
, 𝑘=4
:

[6,8,14,22]
,
[4,9,13,22]
,
[2,10,12,22]
,
[0,11,11,22]
.
For 𝑛=3
, 𝑘=9
, it can be shown that there are no fibonacci-like sequences satisfying the
given conditions.

For 𝑛=55
, 𝑘=11
, [0,1,1,2,3,5,8,13,21,34,55]
 is the only fibonacci-like sequence.

*/

/*given
 * A non-negative integer n

* An integer k ≥ 3

You must count how many non-decreasing, non-negative sequences:

- Of length k

- Satisfying Fibonacci-like rule:
`f[i] = f[i - 1] + f[i - 2]` for all i > 2

- Such that the k-th value is n (f[k] == n)


How many integer solutions (a, b) ≥ 0 to:

`n = A*a + B*b`
where A = Fib(k-2) and B = Fib(k-1)

You are to count the number of valid (f1, f2) pairs that satisfy this.

Efficiently
want to count the number of integer solutions (a, b) ≥ 0 such that:
```
n = A*a + B*b
```

Loop over possible values of a:
```cpp
for a from 0 to floor(n / A):
    b = (n - A*a) / B
    if (n - A*a) % B == 0 => valid solution
```

use fast exponentiation:
```cpp
|F(n+1) F(n)  | = [ [1, 1], [1, 0] ]^n
|F(n)   F(n-1)|
````
*/

#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<long> f(2);
  f[0] = 0;
  f[1] = 1;
  while (f.back() < 1e7) {
    long n = f.size();
    f.push_back(f[n - 1] + f[n - 2]);
  }

  int t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    if (k >= static_cast<long>(f.size())) {
      std::cout << "0\n";
      continue;
    }

    long a = f[k - 2], b = f[k - 1];
    long cnt = 0;
    for (long u = 0; u < 1e6; ++u) {
      long diff = n - a * u;
      if (diff < b * u)
        break;
      cnt += (diff % b == 0);
    }

    std::cout << cnt << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1853/332661601
