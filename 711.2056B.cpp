/*B. Find the Permutation
time limit per test1.5 seconds
memory limit per test256 megabytes

You are given an undirected graph with 𝑛
 vertices, labeled from 1
 to 𝑛
. This graph encodes a hidden permutation∗
 𝑝
 of size 𝑛
. The graph is constructed as follows:

For every pair of integers 1≤𝑖<𝑗≤𝑛
, an undirected edge is added between vertex 𝑝𝑖
 and vertex 𝑝𝑗
 if and only if 𝑝𝑖<𝑝𝑗
. Note that the edge is not added between vertices 𝑖
 and 𝑗
, but between the vertices of their respective elements. Refer to the notes
section for better understanding. Your task is to reconstruct and output the
permutation 𝑝 . It can be proven that permutation 𝑝 can be uniquely determined.

∗
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤1000
).

The 𝑖
-th of the next 𝑛
 lines contains a string of 𝑛
 characters 𝑔𝑖,1𝑔𝑖,2…𝑔𝑖,𝑛
 (𝑔𝑖,𝑗=𝟶
 or 𝑔𝑖,𝑗=𝟷
) — the adjacency matrix. 𝑔𝑖,𝑗=𝟷
 if and only if there is an edge between vertex 𝑖
 and vertex 𝑗
.

It is guaranteed that there exists a permutation 𝑝
 which generates the given graph. It is also guaranteed that the graph is
undirected and has no self-loops, meaning 𝑔𝑖,𝑗=𝑔𝑗,𝑖 and 𝑔𝑖,𝑖=𝟶
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 1000
.

Output
For each test case, output 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 representing the reconstructed permutation.

Example
InputCopy
3
1
0
5
00101
00101
11001
00001
11110
6
000000
000000
000000
000000
000000
000000
OutputCopy
1
4 2 1 3 5
6 5 4 3 2 1
Note
In the first case 𝑝=[1]
. Since there are no pairs 1≤𝑖<𝑗≤𝑛
, there are no edges in the graph.

The graph in the second case is shown below. For example, when we choose 𝑖=3
 and 𝑗=4
, we add an edge between vertices 𝑝𝑖=1
 and 𝑝𝑗=3
, because 𝑝𝑖<𝑝𝑗
. However, when we choose 𝑖=2
 and 𝑗=3
, 𝑝𝑖=2
 and 𝑝𝑗=1
, so 𝑝𝑖<𝑝𝑗
 doesn't hold. Therefore, we don't add an edge between 2
 and 1
.



In the third case, there are no edges in the graph, so there are no pairs of
integers 1≤𝑖<𝑗≤𝑛 such that 𝑝𝑖<𝑝𝑗 . Therefore, 𝑝=[6,5,4,3,2,1]
.
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v(n);

    for (long p = 0; p < n; p++) {
      std::string s;
      std::cin >> s;
      long dist = 0;

      for (long u = 0; u < s.size(); u++) {
        dist += (s[u] == '0') * (u < p) + (s[u] == '1') * (u > p);
      }

      v[n - 1 - dist] = p + 1;
    }

    // Output using std::cout
    for (long p = 0; p < n; p++) {
      std::cout << v[p] << " ";
    }
    std::cout << "\n";
  }
}
// sub: https://codeforces.com/problemset/submission/2056/339969942
