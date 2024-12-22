// https://codeforces.com/problemset/problem/228/A
/* A. Is your horseshoe on the other hoof?
time limit per test2 seconds
memory limit per test256 megabytes
Valera the Horse is going to the party with friends. He has been following the
fashion trends for a while, and he knows that it is very popular to wear all
horseshoes of different color. Valera has got four horseshoes left from the last
year, but maybe some of them have the same color. In this case he needs to go to
the store and buy some few more horseshoes, not to lose face in front of his
stylish comrades.

Fortunately, the store sells horseshoes of all colors under the sun and Valera
has enough money to buy any four of them. However, in order to save the money,
he would like to spend as little money as possible, so you need to help Valera
and determine what is the minimum number of horseshoes he needs to buy to wear
four horseshoes of different colors to a party.

Input
The first line contains four space-separated integers s1, s2, s3, s4
(1 ≤ s1, s2, s3, s4 ≤ 109) — the colors of horseshoes Valera has.

Consider all possible colors indexed with integers.

Output
Print a single integer — the minimum number of horseshoes Valera needs to buy.

Examples
InputCopy
1 7 3 3
OutputCopy
1
InputCopy
7 7 7 7
OutputCopy
3
*/

// different color horseshoe for every leg
// find min number of horseshoe to buy

// Create a Set: Insert the four integers into a set. The set will only keep
// unique values. Count Unique Colors: The size of the set will tell us how many
// different colors Valera already has. Calculate Missing Horseshoes: Subtract
// the size of the set from 4 to find out how many more horseshoes Valera needs
// to buy

#include <iostream>
#include <set>
using namespace std;

int main() {
  // Read input: four space-separated integers representing horseshoe colors
  int s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;

  // Store the horseshoe colors in a set to automatically handle duplicates
  set<int> unique_colors;
  unique_colors.insert(s1);
  unique_colors.insert(s2);
  unique_colors.insert(s3);
  unique_colors.insert(s4);

  // The number of new horseshoes Valera needs to buy is 4 - the size of the set
  cout << 4 - unique_colors.size() << endl;

  return 0;
}
