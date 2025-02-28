/*B. Triple
time limit per test1 second
memory limit per test256 megabytes
Given an array 𝑎
 of 𝑛
 elements, print any value that appears at least three times or print -1 if
there is no such value.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print any value that appears at least three times or print
-1 if there is no such value.

Example
InputCopy
7
1
1
3
2 2 2
7
2 2 3 3 4 2 2
8
1 4 3 4 3 2 4 1
9
1 1 1 2 2 2 3 3 3
5
1 5 2 4 3
4
4 4 4 4
OutputCopy
-1
2
2
4
3
-1
4
Note
In the first test case there is just a single element, so it can't occur at
least three times and the answer is -1.

In the second test case, all three elements of the array are equal to 2
, so 2
 occurs three times, and so the answer is 2
.

For the third test case, 2
 occurs four times, so the answer is 2
.

For the fourth test case, 4
 occurs three times, so the answer is 4
.

For the fifth test case, 1
, 2
 and 3
 all occur at least three times, so they are all valid outputs.

For the sixth test case, all elements are distinct, so none of them occurs at
least three times and the answer is -1.


*/
#include <algorithm>
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
    // print value that appears atleast 3 times else print -1
    sort(v.begin(), v.end());
    int found_value = -1;

    // Iterate through the array to find a value that appears at least three
    // times
    for (int i = 0; i < n - 2;
         i++) { // Stop at n-2 to ensure there's enough space for a triplet
      if (v[i] ==
          v[i + 2]) { // Check if current element is the start of a triplet
        found_value = v[i];
        break;
      }
    }

    // Output the result
    cout << found_value << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1669/308388165
