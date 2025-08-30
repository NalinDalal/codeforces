/*E. Lost Soul
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integer arrays 𝑎
 and 𝑏
, each of length 𝑛
.

You may perform the following operation any number of times:

Choose an index 𝑖
 (1≤𝑖≤𝑛−1)
, and set 𝑎𝑖:=𝑏𝑖+1
, or set 𝑏𝑖:=𝑎𝑖+1
.
Before performing any operations, you are allowed to choose an index 𝑖
 (1≤𝑖≤𝑛)
 and remove both 𝑎𝑖
 and 𝑏𝑖
 from the arrays. This removal can be done at most once.

Let the number of matches between two arrays 𝑐
 and 𝑑
 of length 𝑚
 be the number of positions 𝑗
 (1≤𝑗≤𝑚)
 such that 𝑐𝑗=𝑑𝑗
.

Your task is to compute the maximum number of matches you can achieve.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases. The description of each test case follows.

The first line contains an integer 𝑛
 (2≤𝑛≤2⋅105)
 — the length of 𝑎
 and 𝑏
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛)
 — the elements of 𝑎
.

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤𝑛)
 — the elements of 𝑏
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the answer for the test case.

Example
InputCopy
10
4
1 3 1 4
4 3 2 2
6
2 1 5 3 6 4
3 2 4 5 1 6
2
1 2
2 1
6
2 5 1 3 6 4
3 5 2 3 4 6
4
1 3 2 2
2 1 3 4
8
3 1 4 6 2 2 5 7
4 2 3 7 1 1 6 5
10
5 1 2 7 3 9 4 10 6 8
6 2 3 6 4 10 5 1 7 9
5
3 2 4 1 5
2 4 5 1 3
7
2 2 6 4 1 3 5
3 1 6 5 1 4 2
5
4 1 3 2 5
3 2 1 5 4
OutputCopy
3
3
0
4
3
5
6
4
5
2
Note
In the first test case, we can do the following:

We will choose not to remove any index.
Choose index 3
, and set 𝑎3:=𝑏4
. The arrays become: 𝑎=[1,3,2,4]
, 𝑏=[4,3,2,2]
.
Choose index 1
, and set 𝑎1:=𝑏2
. The arrays become: 𝑎=[3,3,2,4]
, 𝑏=[4,3,2,2]
.
Choose index 1
, and set 𝑏1:=𝑎2
. The arrays become: 𝑎=[3,3,2,4]
, 𝑏=[3,3,2,2]
. Notice that you can perform 𝑎𝑖:=𝑏𝑖+1
 and 𝑏𝑖:=𝑎𝑖+1
 on the same index 𝑖
.
The number of matches is 3
. It can be shown that this is the maximum answer we can achieve.

In the second test case, we can do the following to achieve a maximum of 3
:

Let's choose to remove index 5
. The arrays become: 𝑎=[2,1,5,3,4]
, 𝑏=[3,2,4,5,6]
.
Choose index 4
, and set 𝑏4:=𝑎5
. The arrays become: 𝑎=[2,1,5,3,4]
, 𝑏=[3,2,4,4,6]
.
Choose index 3
, and set 𝑎3:=𝑏4
. The arrays become: 𝑎=[2,1,4,3,4]
, 𝑏=[3,2,4,4,6]
.
Choose index 2
, and set 𝑎2:=𝑏3
. The arrays become: 𝑎=[2,4,4,3,4]
, 𝑏=[3,2,4,4,6]
.
Choose index 1
, and set 𝑏1:=𝑎2
. The arrays become: 𝑎=[2,4,4,3,4]
, 𝑏=[4,2,4,4,6]
.
Choose index 2
, and set 𝑏2:=𝑎3
. The arrays become: 𝑎=[2,4,4,3,4]
, 𝑏=[4,4,4,4,6]
.
Choose index 1
, and set 𝑎1:=𝑏2
. The arrays become: 𝑎=[4,4,4,3,4]
, 𝑏=[4,4,4,4,6]
.
In the third test case, it can be shown that we can not get any matches.
Therefore, the answer is 0
.
*/

/*array a,b
 1. Pick index i (1 ≤ i ≤ n−1) and do either:
    - a[i] = b[i+1] => can turn a[i] into a future b value.
    - b[i] = a[i+1] => can turn b[i] into a future a value.

2. Optionally remove one index i from both arrays before doing operations.
    let's you to get rid of 1 problematic pair

We want to maximize the number of positions j such that a[j] == b[j].

3. The problem can be modeled as a "graph of values":
    - Each element points to the next element it can be replaced with.
    - We want to maximize matches → find longest chains that match.

4. Key Insight from Example:
    - The number of matches is at most n-1.
    - Sometimes removing a single element improves the result.
*/

/* 1. Count matches without removal:
```
int matches = 0;
for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) matches++;
}
```

2. Check if removing an element increases matches:
    - Removing index i allows "shifting" elements to match better.
    - In practice, the maximum matches is either the current count or n-1.

3. Greedy Observation:
    - Using operations optimally, you can often make all but one element match,
because each operation propagates a future value.
    - So answer = n, or answer = n-1 if some value is unmatchable.
*/

/*test case(){
 Count matches without removal.
 check last element

 Step 2: Initialize
seen = [false, false, false, false, false]; // size n+1
cnt = -1;


We will scan from p = n-2 = 2 down to 0.

If any a[i] != b[i], then after optimal operations, the answer = matches + 1.

Otherwise, the answer = n.
  }
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> a(n), b(n);
    for (long &x : a)
      cin >> x;
    for (long &x : b)
      cin >> x;

    vector<bool> seen(n + 1, false);

    if (a.back() == b.back()) {
      cout << n << "\n";
      continue;
    }

    long cnt = -1;
    for (long p = n - 2; cnt < 0 && p >= 0; p--) {
      if (a[p] == b[p] || a[p] == a[p + 1] || b[p] == b[p + 1] || seen[a[p]] ||
          seen[b[p]]) {
        cnt = p;
      }
      seen[a[p + 1]] = true;
      seen[b[p + 1]] = true;
    }

    cout << cnt + 1 << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2117/336205696
