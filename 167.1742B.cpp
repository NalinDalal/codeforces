/* B. Increasing
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎 of 𝑛 positive integers. Determine if, by rearranging
the elements, you can make the array strictly increasing. In other words,
determine if it is possible to rearrange the elements such that 𝑎1<𝑎2<⋯<𝑎𝑛
holds.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤100) — the
length of the array.

The second line of each test case contains 𝑛 integers 𝑎𝑖 (1≤𝑎𝑖≤109) — the
elements of the array.

Output
For each test case, output "YES" (without quotes) if the array satisfies the
condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
3
4
1 1 1 1
5
8 7 1 3 4
1
5
OutputCopy
NO
YES
YES
Note
In the first test case any rearrangement will keep the array [1,1,1,1], which is
not strictly increasing. In the second test case, you can make the array
[1,3,4,7,8].
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    std::set<int> s;
    bool flag = true;
    while (n--) {
      long x;
      cin >> x;
      if (s.count(x)) {
        flag = false;
      }
      s.insert(x);
    }

    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

// https://codeforces.com/problemset/submission/1742/307431493
