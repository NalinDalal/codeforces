// https://codeforces.com/problemset/problem/1675/B
/*B. Make It Increasing
time limit per test2 seconds
memory limit per test256 megabytes
Given 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛. You can perform the following operation on them:

select any element 𝑎𝑖 (1≤𝑖≤𝑛) and divide it by 2 (round down).
In other words, you can replace any selected element 𝑎𝑖 with the value ⌊𝑎𝑖2⌋
(where ⌊𝑥⌋ is – round down the real number 𝑥). Output the minimum number of
operations that must be done for a sequence of integers to become strictly
increasing (that is, for the condition 𝑎1<𝑎2<⋯<𝑎𝑛 to be satisfied). Or determine
that it is impossible to obtain such a sequence. Note that elements cannot be
swapped. The only possible operation is described above.

For example, let 𝑛=3 and a sequence of numbers [3,6,5] be given. Then it is
enough to perform two operations on it:

Write the number ⌊62⌋=3 instead of the number 𝑎2=6 and get the sequence [3,3,5];
Then replace 𝑎1=3 with ⌊32⌋=1 and get the sequence [1,3,5].
The resulting sequence is strictly increasing because 1<3<5.

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤104) — the number of test
cases in the input.

The descriptions of the test cases follow.
The first line of each test case contains a single integer 𝑛 (1≤𝑛≤30).

The second line of each test case contains exactly 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛
(0≤𝑎𝑖≤2⋅109).

Output
For each test case, print a single number on a separate line — the minimum
number of operations to perform on the sequence to make it strictly increasing.
If a strictly increasing sequence cannot be obtained, print "-1".

Example
InputCopy
7
3
3 6 5
4
5 3 2 1
5
1 2 3 4 5
1
1000000000
4
2 8 7 5
5
8 26 5 21 10
2
5 14
OutputCopy
2
-1
0
0
4
11
0

Note
The first test case is analyzed in the statement.
In the second test case, it is impossible to obtain a strictly increasing
sequence. In the third test case, the sequence is already strictly increasing.
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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int ans = 0;
    bool possible = true;

    // Making the array strictly increasing
    for (int i = n - 2; i >= 0; i--) { // Start from second last element
      while (v[i] >= v[i + 1]) {
        if (v[i] == 0) { // If reduced to 0, it's impossible
          possible = false;
          break;
        }
        v[i] /= 2;
        ans++;
      }
      if (!possible)
        break;
    }

    cout << (possible ? ans : -1) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1675/303483258
