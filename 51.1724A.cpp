/* https://codeforces.com/problemset/problem/1742/A
A. Sum
time limit per test1 second
memory limit per test256 megabytes
You are given three integers 𝑎, 𝑏, and 𝑐. Determine if one of them is the sum of
the other two.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤9261) — the number of test
cases.

The description of each test case consists of three integers 𝑎, 𝑏, 𝑐
(0≤𝑎,𝑏,𝑐≤20).

Output
For each test case, output "YES" if one of the numbers is the sum of the other
two, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
7
1 4 3
2 5 8
9 11 20
0 0 0
20 20 20
4 12 3
15 7 8
OutputCopy
YES
NO
YES
YES
NO
NO
YES
Note
In the first test case, 1+3=4.
In the second test case, none of the numbers is the sum of the other two.
In the third test case, 9+11=20.*/

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || b + c == a || c + a == b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
