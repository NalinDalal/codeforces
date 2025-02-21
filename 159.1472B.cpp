/* B. Fair Division
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob received 𝑛
 candies from their parents. Each candy weighs either 1 gram or 2 grams. Now
they want to divide all candies among themselves fairly so that the total weight
of Alice's candies is equal to the total weight of Bob's candies.

Check if they can do that.

Note that candies are not allowed to be cut in half.

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases. Then
𝑡 test cases follow.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤100) — the number of
candies that Alice and Bob received.

The next line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 — the weights of the candies. The
weight of each candy is either 1 or 2.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 105.

Output
For each test case, output on a separate line:

"YES", if all candies can be divided into two sets with the same weight;
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes,
Yes and YES will be recognized as positive).

Example
InputCopy
5
2
1 1
2
1 2
4
1 2 1 2
3
2 2 2
3
2 1 2
OutputCopy
YES
NO
YES
NO
NO
Note
In the first test case, Alice and Bob can each take one candy, then both will
have a total weight of 1.

In the second test case, any division will be unfair.

In the third test case, both Alice and Bob can take two candies, one of weight 1
and one of weight 2.

In the fourth test case, it is impossible to divide three identical candies
between two people.

In the fifth test case, any division will also be unfair.


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
    vector<int> a(n);

    int ones = 0, twos = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        ones++;
      else
        twos++;
    }

    bool possible = true;

    if (ones % 2 == 1)
      possible = false;
    else if (ones == 0 && twos % 2 == 1)
      possible = false;

    cout << (possible ? "YES" : "NO") << endl; // Add newline
  }
  return 0;
}

// a[i] is either 1 or 2, it's wt of candy
// alice wt=bob wt
// just sum them all, if sum is even, then YES
// else NO

// sub: https://codeforces.com/problemset/submission/1472/307172878
