/* https://codeforces.com/problemset/problem/1862/B
B. Sequence Game
time limit per test2 seconds
memory limit per test256 megabytes
Tema and Vika are playing the following game.

First, Vika comes up with a sequence of positive integers 𝑎 of length 𝑚 and
writes it down on a piece of paper. Then she takes a new piece of paper and
writes down the sequence 𝑏 according to the following rule:

First, she writes down 𝑎1.Then, she writes down only those 𝑎𝑖 (2≤𝑖≤𝑚) such that
𝑎𝑖−1≤𝑎𝑖. Let the length of this sequence be denoted as 𝑛. For example, from the
sequence 𝑎=[4,3,2,6,3,3], Vika will obtain the sequence 𝑏=[4,6,3].

She then gives the piece of paper with the sequence 𝑏 to Tema. He, in turn,
tries to guess the sequence 𝑎.

Tema considers winning in such a game highly unlikely, but still wants to find
at least one sequence 𝑎 that could have been originally chosen by Vika. Help him
and output any such sequence.

Note that the length of the sequence you output should not exceed the input
sequence length by more than two times.

Input
Each test consists of multiple test cases. The first line of input data contains
a single integer 𝑡 (1≤𝑡≤104) — the number of test cases. This is followed by a
description of the test cases.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤2⋅105) — the
length of the sequence 𝑏.

The second line of each test case contains 𝑛 integers 𝑏1,𝑏2,𝑏3,…,𝑏𝑛 (1≤𝑏𝑖≤109) —
the elements of the sequence.

The sum of the values of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output two lines. In the first line, output a single integer
𝑚 — the length of the sequence (𝑛≤𝑚≤2⋅𝑛). In the second line, output 𝑚 integers
𝑎1,𝑎2,𝑎3,…,𝑎𝑚 (1≤𝑎𝑖≤109) — the assumed sequence that Vika could have written on
the first piece of paper.

If there are multiple suitable sequences, you can output any of them.

Example
Input
6
3
4 6 3
3
1 2 3
5
1 7 9 5 7
1
144
2
1 1
5
1 2 2 1 1
Output
6
4 3 2 6 3 3
3
1 2 3
6
1 7 9 3 5 7
1
144
2
1 1
6
1 2 2 1 1 1

Note
The first sample is explained in the problem statement.
In the second sample, Vika could have chosen the original sequence.


*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T; // Number of test cases
  while (T--) {
    int n;
    cin >> n; // Length of the array
    vector<int> arr(n), ans;

    // Input the array
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // Construct the answer
    ans.push_back(arr[0]); // Add the first element
    for (int i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1]) {
        ans.push_back(1); // Append 1 if current element is smaller
      }
      ans.push_back(arr[i]); // Append the current element
    }

    // Output the result
    cout << ans.size() << endl;
    for (int x : ans) {
      cout << x << " "; // Print all elements of the result
    }
    cout << endl;
  }
  return 0;
}
