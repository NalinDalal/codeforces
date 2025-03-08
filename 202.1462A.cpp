/* A. Favorite Sequence
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp has a favorite sequence 𝑎[1…𝑛]
 consisting of 𝑛
 integers. He wrote it out on the whiteboard as follows:

he wrote the number 𝑎1
 to the left side (at the beginning of the whiteboard);
he wrote the number 𝑎2
 to the right side (at the end of the whiteboard);
then as far to the left as possible (but to the right from 𝑎1
), he wrote the number 𝑎3
;
then as far to the right as possible (but to the left from 𝑎2
), he wrote the number 𝑎4
;
Polycarp continued to act as well, until he wrote out the entire sequence on the
whiteboard. The beginning of the result looks like this (of course, if 𝑛≥4
).
For example, if 𝑛=7
 and 𝑎=[3,1,4,1,5,9,2]
, then Polycarp will write a sequence on the whiteboard [3,4,5,2,9,1,1]
.

You saw the sequence written on the whiteboard and now you want to restore
Polycarp's favorite sequence.

Input
The first line contains a single positive integer 𝑡
 (1≤𝑡≤300
) — the number of test cases in the test. Then 𝑡
 test cases follow.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤300
) — the length of the sequence written on the whiteboard.

The next line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
) — the sequence written on the whiteboard.

Output
Output 𝑡
 answers to the test cases. Each answer — is a sequence 𝑎
 that Polycarp wrote out on the whiteboard.

Example
InputCopy
6
7
3 4 5 2 9 1 1
4
9 2 7 1
11
8 4 3 1 2 7 8 7 9 4 2
1
42
2
11 7
8
1 1 1 1 1 1 1 1
OutputCopy
3 1 4 1 5 9 2
9 1 2 7
8 2 4 4 3 9 1 7 2 8 7
42
11 7
1 1 1 1 1 1 1 1
Note
In the first test case, the sequence 𝑎
 matches the sequence from the statement. The whiteboard states after each step
look like this:

[3]⇒[3,1]⇒[3,4,1]⇒[3,4,1,1]⇒[3,4,5,1,1]⇒[3,4,5,9,1,1]⇒[3,4,5,2,9,1,1]
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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    vector<int> b;
    int left = 0, right = n - 1;

    while (left <= right) {
      b.push_back(v[left++]); // Take from the start
      if (left <= right) {
        b.push_back(v[right--]); // Take from the end
      }
    }

    for (int x : b) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}

// no to restore the sequence
// input - a1,a2,a3,a4....
// Output - a1,a3.....a4,a2
// sub: https://codeforces.com/problemset/submission/1462/309485346
