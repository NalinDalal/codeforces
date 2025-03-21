/*A. Sakurako's Exam
time limit per test1 second
memory limit per test256 megabytes
Today, Sakurako has a math exam. The teacher gave the array, consisting of 𝑎
 ones and 𝑏
 twos.

In an array, Sakurako must place either a '+' or a '-' in front of each element
so that the sum of all elements in the array equals 0
.

Sakurako is not sure if it is possible to solve this problem, so determine
whether there is a way to assign signs such that the sum of all elements in the
array equals 0
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
)  — the number of test cases.

The only line of each test case contains two integers 𝑎
 and 𝑏
 (0≤𝑎,𝑏<10
)  — the number of '1's and the number of '2's in the array.

Output
For each test case, output "Yes" if you can make the sum of the entire array
equal to 0 , and "No" otherwise.

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
5
0 1
0 3
2 0
2 3
3 1
OutputCopy
NO
NO
YES
YES
NO
Note
𝑎=0
, 𝑏=1
: This means the array is [2]
 — it is impossible to add the signs '+' or '-' to get 0
 as a result;
𝑎=0
, 𝑏=3
: This means the array is [2,2,2]
 — it is impossible to add the signs '+' or '-' to get 0
 as a result;
𝑎=2
, 𝑏=0
: This means the array is [1,1]
 — it is possible to add the signs '+' or '-' to get 0
 as a result (+1−1=0
);
𝑎=2
, 𝑏=3
: This means the array is [1,1,2,2,2]
 — it is possible to add the signs '+' or '-' to get 0
 as a result (+1+1−2−2+2=0
);


*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << (((a % 2) || (b % 2 && a < 2)) ? "NO" : "YES") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2008/311663121
