/* A. Find Minimum Operations
time limit per test1 second
memory limit per test256 megabytes
You are given two integers 𝑛
 and 𝑘
.

In one operation, you can subtract any power of 𝑘
 from 𝑛
. Formally, in one operation, you can replace 𝑛
 by (𝑛−𝑘𝑥)
 for any non-negative integer 𝑥
.

Find the minimum number of operations required to make 𝑛
 equal to 0
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛,𝑘≤109
).

Output
For each test case, output the minimum number of operations on a new line.

Example
InputCopy
6
5 2
3 5
16 4
100 3
6492 10
10 1
OutputCopy
2
3
1
4
21
10
Note
In the first test case, 𝑛=5
 and 𝑘=2
. We can perform the following sequence of operations:

Subtract 20=1
 from 5
. The current value of 𝑛
 becomes 5−1=4
.
Subtract 22=4
 from 4
. The current value of 𝑛
 becomes 4−4=0
.
It can be shown that there is no way to make 𝑛
 equal to 0
 in less than 2
 operations. Thus, 2
 is the answer.

In the second test case, 𝑛=3
 and 𝑘=5
. We can perform the following sequence of operations:

Subtract 50=1
 from 3
. The current value of 𝑛
 becomes 3−1=2
.
Subtract 50=1
 from 2
. The current value of 𝑛
 becomes 2−1=1
.
Subtract 50=1
 from 1
. The current value of 𝑛
 becomes 1−1=0
.
It can be shown that there is no way to make 𝑛
 equal to 0
 in less than 3
 operations. Thus, 3
 is the answer.


*/

/*#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    // replace n by (n-k^x) x is power of k
    // now the thing is x can vary for any whole no
    // find min no of operation to make n=0
    int ans = 0;
    // check if n is base to k exist
    /*  if (log n to base k == 0)
        return 1;
      else {
        // find the base where it's less than n
        // then subtract that opr++
        // and repeat
      }


    while (n > 0) {
      int power = 0;
      // Find the largest power of k such that k^power <= n
      while (pow(k, power + 1) <= n) {
        power++;
      }
      // Subtract k^power from n
      n -= pow(k, power);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, k;
    std::cin >> n >> k;

    if (k == 1) {
      std::cout << n << std::endl;
      continue;
    }
    int cnt = 0;
    while (n) {
      cnt += n % k;
      n /= k;
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2020/317540267
