/*A. 2023
time limit per test1 second
memory limit per test256 megabytes
In a sequence 𝑎
, whose product was equal to 2023
, 𝑘
 numbers were removed, leaving a sequence 𝑏
 of length 𝑛
. Given the resulting sequence 𝑏
, find any suitable sequence 𝑎
 and output which 𝑘
 elements were removed from it, or state that such a sequence could not have
existed.

Notice that you are not guaranteed that such array exists.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤100 ) — the number of test cases. This is followed by a
description of the test cases.

The first line of each test case contains two integers 𝑛
 (1≤𝑛,𝑘≤5
) — the size of sequence 𝑏
 and the number of numbers removed from sequence 𝑎
.

The second line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2023
) — the remaining sequence. The values of 𝑏𝑖
 might not be divisors of 2023
.

Output
For each test case, output "YES" if the sequence 𝑎
 exists, and in the following line output 𝑘
 non-negative integers that were removed from the sequence 𝑎
. If the sequence 𝑎
 does not exist, output "NO" in a single line.

You can output the answer in any case (uppercase or lowercase). For example, the
strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

Example
InputCopy
7
2 2
5 2
3 1
7 17 7
4 2
1 289 1 1
3 1
7 17 17
1 1
289
1 1
2023
1 3
1
OutputCopy
NO
NO
YES
7 1
YES
1
YES
7
YES
1
YES
7 17 17
Note
In third test case product is equal to 289⋅7=2023
.

In fourth test case product is already equal to 2023
.

In seventh test case product is equal to 7⋅17⋅17=2023
.
*/

/*originally a was vector,
 product of element of a was 2023
 now k num from it removed , leaving b vector
 find if a really existed,
 if yes -> print "YES" and any valid set of removed elements
 else -> print "NO"
 2023=7*17*17
 prod(a)=2023
 compute

 For a to exist:

2023 % prod(b) == 0 (i.e., prod(b) must divide 2023).
Otherwise → impossible.

The missing k elements must multiply to 2023 / prod(b).

If k=1 → just put the whole leftover as one element.

If k>1 → we can always pad with 1s because multiplying by 1 doesn’t change the
product.prod(b)
*/
/*Read n, k, and sequence b.

2. Compute p = ∏ b[i].

3. If 2023 % p != 0 → print NO.

4. Otherwise, compute missing = 2023 / p.
- If missing == 1 and k >= 1: we can output 1 followed by (k-1) ones.
- Else: output missing plus (k-1) ones.

5. Done.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long p = 1;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      p *= b[i];
    }
    if (2023 % p != 0) {
      cout << "NO\n";
      continue;
    }

    long long missing = 2023 / p;
    cout << "YES\n";
    cout << missing;
    for (int i = 1; i < k; i++)
      cout << " 1";
    cout << "\n";
  }
  return 0;
}
