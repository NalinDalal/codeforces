// https://codeforces.com/problemset/problem/486/A
/* A. Calculating Function
time limit per test1 second
memory limit per test256 megabytes
For a positive integer n let's define a function f:

f(n) =  - 1 + 2 - 3 + .. + (-1)^n*n

Your task is to calculate f(n) for a given integer n.

Input
The single line contains the positive integer n (1 ≤ n ≤ 1015).

Output
Print f(n) in a single line.

Examples
InputCopy
4
OutputCopy
2
InputCopy
5
OutputCopy
-3
Note
f(4) =  - 1 + 2 - 3 + 4 = 2

f(5) =  - 1 + 2 - 3 + 4 - 5 =  - 3

*/

/* #include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define itr(i, a, b) for (int i = int(a); i < int(b); i++)
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); // Fix: changed 'cin.tie(o)' to 'cin.tie(0)'

  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (-1) ^ i * i;
  }
  cout << ans << el;
  return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define itr(i, a, b) for (int i = int(a); i < int(b); i++)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    ans += (i % 2 == 0 ? i : -i); // Alternate sign based on odd/even index
  }

  cout << ans << el; // Output the result
  return 0;
}
*/
// optimisation:
/*collectively sum the even and odd then take their difference
S odd​ =k 2 where 𝑘=⌊ n+1​/2 ⌋.
S even =k⋅(k+1) where k=⌊ n/2 ⌋.
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  // Calculate the count of odd and even numbers
  int odd_count = (n + 1) / 2; // Count of odd numbers
  int even_count = n / 2;      // Count of even numbers

  // Calculate the sum of odd and even numbers
  int odd_sum = odd_count * odd_count;          // Sum of odd numbers
  int even_sum = even_count * (even_count + 1); // Sum of even numbers

  // Result is even_sum - odd_sum
  int ans = even_sum - odd_sum;

  cout << ans << el; // Output the result
  return 0;
}
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long n, a;
  cin >> n;
  if (n % 2 == 0)
    a = n / 2;
  else
    a = ((n + 1) / 2) * (-1);
  cout << a << endl;
  return 0;
}
