/*A. Add or XOR
time limit per test1 second
memory limit per test256 megabytes
r-906 & IA AI - Psychologic Disco
You are given two non-negative integers 𝑎,𝑏
. You can apply two types of operations on 𝑎
 any number of times and in any order:

𝑎←𝑎+1
. The cost of this operation is 𝑥
;
𝑎←𝑎⊕1
, where ⊕
 denotes the bitwise XOR operation. The cost of this operation is 𝑦
.
Now you are asked to make 𝑎=𝑏
. If it's possible, output the minimum cost; otherwise, report it.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of each test case contains four integers 𝑎,𝑏,𝑥,𝑦
 (1≤𝑎,𝑏≤100,1≤𝑥,𝑦≤107
) — the two integers given to you and the respective costs of two types of
operations.

Output
For each test case, output an integer — the minimum cost to make 𝑎=𝑏
, or −1
 if it is impossible.

Example
InputCopy
7
1 4 1 2
1 5 2 1
3 2 2 1
1 3 2 1
2 1 1 2
3 1 1 2
1 100 10000000 10000000
OutputCopy
3
6
1
3
-1
-1
990000000
Note
In the first test case, the optimal strategy is to apply 𝑎←𝑎+1
 three times. The total cost is 1+1+1=3
.

In the second test case, the optimal strategy is to apply 𝑎←𝑎+1
, 𝑎←𝑎⊕1
, 𝑎←𝑎+1
, 𝑎←𝑎⊕1
 in order. The total cost is 2+1+2+1=6
.

In the fifth test case, it can be proved that there isn't a way to make 𝑎=𝑏
.
*/

#include <climits>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    /*given a,b,x,y
     a<- a+1 {cost=x}
     a<- a xor 1 {cost=y}

     if it is possible to make a==b output the cost
     else output -1

     3 possibilities:
        1. (b-a)*x if a<=b
        2. xor then incr. y + (b - (a ^ 1)) * x if (a ^ 1) <= b
        3. Increment until we overshoot one less, then XOR to land exactly on b:
If (a + k) ^ 1 == b for some k >= 0, cost = k*x + y.
                */

    if (a > b) {
      cout << ((a ^ 1) == b ? y : -1) << endl;
    } else {
      long long c0 = b - a;
      long long c1 = (b + 1) / 2 - (a + 1) / 2;
      cout << ((y > x) ? (c0 * x) : ((c0 - c1) * x + c1 * y)) << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2119/335441441
