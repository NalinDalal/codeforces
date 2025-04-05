/*A. Adjacent Digit Sums
time limit per test1 second
memory limit per test256 megabytes
You are given two numbers 𝑥,𝑦
. You need to determine if there exists an integer 𝑛
 such that 𝑆(𝑛)=𝑥
, 𝑆(𝑛+1)=𝑦
.

Here, 𝑆(𝑎)
 denotes the sum of the digits of the number 𝑎
 in the decimal numeral system.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains two integers 𝑥,𝑦
 (1≤𝑥≤1000,1≤𝑦≤1000
).

Output
For each test case, print "NO" if a suitable 𝑛
 does not exist. Otherwise, output "YES".

You can output each letter in any case (for example, "YES", "Yes", "yes", "yEs",
"yEs" will be recognized as a positive answer).

Example
InputCopy
7
1 2
77 77
997 999
999 1
1000 1
1 11
18 1
OutputCopy
Yes
No
No
Yes
No
No
Yes
Note
In the first test case, for example, 𝑛=100
 works. 𝑆(100)=1
, 𝑆(101)=2
.

In the second test case, it can be shown that 𝑆(𝑛)≠𝑆(𝑛+1)
 for all 𝑛
; therefore, the answer is No.

In the fourth test case, 𝑛=10111−1
 works, which is a number consisting of 111
 digits of 9
.



*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long x, y;
    scanf("%ld %ld", &x, &y);
    puts((y == x + 1) || ((x > y) && !((x - y + 1) % 9)) ? "Yes" : "No");
  }
}
// sub: https://codeforces.com/problemset/submission/2067/314158850
