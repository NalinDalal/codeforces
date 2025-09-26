/*E. Alternating String
time limit per test2 seconds
memory limit per test256 megabytes
Sakurako really loves alternating strings. She calls a string 𝑠
 of lowercase Latin letters an alternating string if characters in the even
positions are the same, if characters in the odd positions are the same, and the
length of the string is even.

For example, the strings 'abab' and 'gg' are alternating, while the strings
'aba' and 'ggwp' are not.

As a good friend, you decided to gift such a string, but you couldn't find one.
Luckily, you can perform two types of operations on the string:

Choose an index 𝑖
 and delete the 𝑖
-th character from the string, which will reduce the length of the string by 1
. This type of operation can be performed no more than 1
 time;
Choose an index 𝑖
 and replace 𝑠𝑖
 with any other letter.
Since you are in a hurry, you need to determine the minimum number of operations
required to make the string an alternating one.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains a single number 𝑛
 (1≤𝑛≤2⋅105
)  — the length of the string.

The second line of each test case contains a string 𝑠
, consisting of lowercase Latin letters.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of operations
required to turn the string 𝑠 into an alternating one.

Example
InputCopy
10
1
a
2
ca
3
aab
5
ababa
6
acdada
9
ejibmyyju
6
bbccbc
6
abacba
5
bcbca
5
dcbdb
OutputCopy
1
0
1
1
2
6
2
3
1
1
Note
For the string ababa, you can delete the first character to get baba, which is
an alternating string.

For the string acdada, you can change the first two characters to get dadada,
which is an alternating string.
*/
/*If n is odd:

We must delete one char → compute replacements under both partitions (original
vs shifted). Take min + 1 (for the deletion).

If n is even:

Option 1: replacements under original partition.

Option 2: replacements under shifted partition + 1 (deletion).

Take min.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto solve = [&]() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    // prefix[i][c] = count of character c at positions 0,2,4,... up to i (for
    // prefix)
    vector<vector<int>> prefix(n, vector<int>(26, 0));
    vector<vector<int>> suffix(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
      if (i >= 2)
        prefix[i] = prefix[i - 2];
      prefix[i][str[i] - 'a']++;
    }

    for (int i = n - 1; i >= 0; i--) {
      if (i + 2 < n)
        suffix[i] = suffix[i + 2];
      suffix[i][str[i] - 'a']++;
    }

    auto getCost = [&](int deleteIndex) {
      vector<vector<int>> cnt(2, vector<int>(26, 0));

      for (int c = 0; c < 26; c++) {
        // positions starting with 0
        if (deleteIndex >= 2)
          cnt[0][c] += prefix[deleteIndex - 2][c];
        if (deleteIndex + 1 < n)
          cnt[0][c] += suffix[deleteIndex + 1][c];

        // positions starting with 1
        if (deleteIndex >= 1)
          cnt[1][c] += prefix[deleteIndex - 1][c];
        if (deleteIndex + 2 < n)
          cnt[1][c] += suffix[deleteIndex + 2][c];
      }

      // special case: no deletion
      if (deleteIndex == n) {
        cnt[0] = prefix[n - 2];
        cnt[1] = prefix[n - 1];
      }

      int totalCost = 0;
      for (int i = 0; i < 2; i++) {
        int maxCount = *max_element(cnt[i].begin(), cnt[i].end());
        int sumCount = accumulate(cnt[i].begin(), cnt[i].end(), 0);
        totalCost += sumCount - maxCount; // replacements needed
      }
      return totalCost;
    };

    int result;
    if (n % 2 == 0) {
      // even length, no deletion required
      result = getCost(n);
    } else {
      // odd length, try deleting each character
      result = n;
      for (int i = 0; i < n; i++) {
        result = min(result, getCost(i) + 1); // +1 for the deletion
      }
    }

    cout << result << '\n';
  };

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2008/340564329
