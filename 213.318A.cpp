/*A. Even Odds
time limit per test1 second
memory limit per test256 megabytes
Being a nonconformist, Volodya is displeased with the current state of things,
particularly with the order of natural numbers (natural number is positive
integer number). He is determined to rearrange them. But there are too many
natural numbers, so Volodya decided to start with the first n. He writes down
the following sequence of numbers: firstly all odd integers from 1 to n (in
ascending order), then all even integers from 1 to n (also in ascending order).
Help our hero to find out which number will stand at the position number k.

Input
The only line of input contains integers n and k (1 ≤ k ≤ n ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in C++.
It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print the number that will stand at the position number k after Volodya's
manipulations.

Examples
InputCopy
10 3
OutputCopy
5
InputCopy
7 7
OutputCopy
6
Note
In the first sample Volodya's sequence will look like this: {1, 3, 5, 7, 9, 2,
4, 6, 8, 10}. The third place in the sequence is therefore occupied by the
number 5.

*/

#include <iostream>
using namespace std;

/*int main() {
  int n, k;
  cin >> n >> k;

  // now write all odd no from 1 to n in ascending order
  // then all even no from 1 to n in ascending order
  // then return the kth no in array
  vector<int> ans;

  // Append all odd numbers first
  for (int i = 1; i <= n; i += 2) {
    ans.push_back(i);
  }

  // Append all even numbers next
  for (int i = 2; i <= n; i += 2) {
    ans.push_back(i);
  }

  // Output the k-th element (1-based index)
  cout << ans[k - 1] << endl;

  return 0;
}*/

// sub: https://codeforces.com/problemset/submission/318/309937091 -> tle
#include <iostream>

int main() {
  long long n, k;
  cin >> n >> k;

  long long oddCount = (n + 1) / 2; // Number of odd numbers from 1 to n

  if (k <= oddCount) {
    cout << (2 * k - 1) << endl; // k-th odd number
  } else {
    cout << (2 * (k - oddCount)) << endl; // k-th even number
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/318/309937284
