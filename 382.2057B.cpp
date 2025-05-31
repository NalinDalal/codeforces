/* B. Gorilla and the Exam
time limit per test1 second
memory limit per test256 megabytes
Due to a shortage of teachers in the senior class of the "T-generation", it was
decided to have a huge male gorilla conduct exams for the students. However, it
is not that simple; to prove his competence, he needs to solve the following
problem.

For an array 𝑏
, we define the function 𝑓(𝑏)
 as the smallest number of the following operations required to make the array 𝑏
 empty:

take two integers 𝑙
 and 𝑟
, such that 𝑙≤𝑟
, and let 𝑥
 be the min(𝑏𝑙,𝑏𝑙+1,…,𝑏𝑟)
; then
remove all such 𝑏𝑖
 that 𝑙≤𝑖≤𝑟
 and 𝑏𝑖=𝑥
 from the array, the deleted elements are removed, the indices are renumerated.
You are given an array 𝑎
 of length 𝑛
 and an integer 𝑘
. No more than 𝑘
 times, you can choose any index 𝑖
 (1≤𝑖≤𝑛
) and any integer 𝑝
, and replace 𝑎𝑖
 with 𝑝
.

Help the gorilla to determine the smallest value of 𝑓(𝑎)
 that can be achieved after such replacements.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test cases
follows.

The first line of each set of input data contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤105
, 0≤𝑘≤𝑛
) — the length of the array 𝑎
 and the maximum number of changes, respectively.

The second line of each set of input data contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the array 𝑎
 itself.

It is guaranteed that the sum of the values of 𝑛
 across all sets of input data does not exceed 105
.

Output
For each set of input data, output a single integer on a separate line — the
smallest possible value of 𝑓(𝑎)
.

Example
InputCopy
6
1 0
48843
3 1
2 3 2
5 3
1 2 3 4 5
7 0
4 7 1 3 2 4 1
11 4
3 2 1 4 4 3 4 2 1 3 3
5 5
1 2 3 4 5
OutputCopy
1
1
2
5
2
1
Note
In the first set of input data, 𝑓([48843])=1
, since the array consists of a single number, and thus it can be removed in one
operation. In the second set of input data, you can change the second number to
2 , resulting in the array [2,2,2] , where 𝑓([2,2,2])=1 , since you can take the
entire array as a subarray, the minimum on it is 2 , so we will remove all the 2
s from the array, and the array will become empty.


*/
#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &a, int k) {
  unordered_map<int, int> valueToCount;
  for (int ai : a) {
    valueToCount[ai]++;
  }

  vector<int> counts;
  for (auto &[val, freq] : valueToCount) {
    counts.push_back(freq);
  }

  sort(counts.begin(), counts.end());

  int result = valueToCount.size();
  for (int count : counts) {
    if (k >= count && result > 1) {
      k -= count;
      --result;
    }
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    cout << solve(a, k) << '\n';
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2057/322127960
