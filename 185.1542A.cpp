/*A. Odd Set
time limit per test1 second
memory limit per test256 megabytes
You are given a multiset (i. e. a set that can contain multiple equal integers)
containing 2𝑛 integers. Determine if you can split it into exactly 𝑛 pairs (i.
e. each element should be in exactly one pair) so that the sum of the two
elements in each pair is odd (i. e. when divided by 2 , the remainder is 1
).

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤100
).

The second line of each test case contains 2𝑛
 integers 𝑎1,𝑎2,…,𝑎2𝑛
 (0≤𝑎𝑖≤100
) — the numbers in the set.

Output
For each test case, print "Yes" if it can be split into exactly 𝑛
 pairs so that the sum of the two elements in each pair is odd, and "No"
otherwise. You can print each letter in any case.

Example
InputCopy
5
2
2 3 4 5
3
2 3 4 5 5 5
1
2 4
1
2 3
4
1 5 3 2 6 7 3 4
OutputCopy
Yes
No
No
Yes
No
Note
In the first test case, a possible way of splitting the set is (2,3)
, (4,5)
.

In the second, third and fifth test case, we can prove that there isn't any
possible way.

In the fourth test case, a possible way of splitting the set is (2,3)
.


*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int size = 2 * n;
    vector<int> v(size);
    int odd_count = 0, even_count = 0;
    for (int i = 0; i < size; i++) {
      cin >> v[i];
      if (v[i] % 2 == 0)
        even_count++;
      else
        odd_count++;
    }

    //"Yes" if it can be split into exactly n pairs so that the sum of the two
    // elements in each pair is odd, and "No" otherwise.

    if (odd_count == n && even_count == n)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1542/308390485
