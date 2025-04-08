/*C. Odd/Even Increments
time limit per test1 second
memory limit per test256 megabytes
Given an array 𝑎=[𝑎1,𝑎2,…,𝑎𝑛]
 of 𝑛
 positive integers, you can do operations of two types on it:

Add 1
 to every element with an odd index. In other words change the array as follows:
𝑎1:=𝑎1+1,𝑎3:=𝑎3+1,𝑎5:=𝑎5+1,…
.

Add 1
 to every element with an even index. In other words change the array as
follows: 𝑎2:=𝑎2+1,𝑎4:=𝑎4+1,𝑎6:=𝑎6+1,…
.
Determine if after any number of operations it is possible to make the final
array contain only even numbers or only odd numbers. In other words, determine
if you can make all elements of the array have the same parity after any number
of operations.

Note that you can do operations of both types any number of times (even none).
Operations of different types can be performed a different number of times.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤50
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤103
) — the elements of the array.

Note that after the performed operations the elements in the array can become
greater than 103
.

Output
Output 𝑡
 lines, each of which contains the answer to the corresponding test case. As an
answer, output "YES" if after any number of operations it is possible to make
the final array contain only even numbers or only odd numbers, and "NO"
otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
4
3
1 2 1
4
2 2 2 3
4
2 2 2 2
5
1000 1 1000 1 1000
OutputCopy
YES
NO
YES
YES
Note
For the first test case, we can increment the elements with an even index,
obtaining the array [1,3,1] , which contains only odd numbers, so the answer is
"YES".

For the second test case, we can show that after performing any number of
operations we won't be able to make all elements have the same parity, so the
answer is "NO".

For the third test case, all elements already have the same parity so the answer
is "YES".

For the fourth test case, we can perform one operation and increase all elements
at odd positions by 1 , thus obtaining the array [1001,1,1001,1,1001] , and all
elements become odd so the answer is "YES".
*/

/* Operation 1: Add 1 to every element at odd index (1-based).

Changes parity of elements at odd indices: even ↔ odd.

Doesn't affect even indices.

Operation 2: Add 1 to every element at even index (1-based).

Changes parity of elements at even indices: even ↔ odd.

Doesn't affect odd indices. */

/* Split elements at odd indices and check if they all have the same parity.

Split elements at even indices and check if they all have the same parity.

If both conditions are true → output "YES", else "NO".*/

#include <iostream>
#include <vector>
using namespace std;

bool check_parity(const vector<int> &a, int start) {
  int parity = a[start] % 2;
  for (int i = start; i < a.size(); i += 2) {
    if (a[i] % 2 != parity) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    // Check parity for elements at odd indices (0-based even indices)
    bool odd_index_check = check_parity(a, 0);

    // Check parity for elements at even indices (0-based odd indices)
    bool even_index_check = check_parity(a, 1);

    if (odd_index_check && even_index_check) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1669/314448884
