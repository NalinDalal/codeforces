/* https://codeforces.com/problemset/problem/271/A
A. Beautiful Year
time limit per test2 seconds
memory limit per test256 megabytes
It seems like the year of 2013 came only yesterday. Do you know a curious fact?
The year of 2013 is the first year after the old 1987 with only distinct digits.

Now you are suggested to solve the following problem: given a year number, find
the minimum year number which is strictly larger than the given one and has only
distinct digits.

Input
The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

Output
Print a single integer — the minimum year number that is strictly larger than y
and all it's digits are distinct. It is guaranteed that the answer exists.

Examples
Input
1987
Output
2013

Input
2013
Output
2014
*/

/* Increment the Year: Start with the year immediately after y, i.e., y + 1.
Check for Distinct Digits: For each year, check if all of its digits are
distinct. Stop when Found: As soon as we find a year with distinct digits, print
that year and stop.
*/

/* Convert the year to a string.
Convert the string into a set (which automatically removes duplicates).
If the length of the set is equal to the length of the string, the digits are
distinct.*/

/* Start with the year y + 1.
Check if the year has distinct digits.
If not, increment the year and repeat the check.
Once a year with distinct digits is found, print that year.*/
#include <iostream>
#include <set>

using namespace std;

bool hasDistinctDigits(int year) {
  string yearStr = to_string(year);
  set<char> digits(yearStr.begin(), yearStr.end());
  return digits.size() ==
         yearStr.size(); // If the size of the set is equal to the string
                         // length, the digits are distinct.
}

int main() {
  int y;
  cin >> y;

  // Start checking from y + 1
  y++;

  // Keep incrementing y until we find a year with distinct digits
  while (!hasDistinctDigits(y)) {
    y++;
  }

  // Output the result
  cout << y << endl;

  return 0;
}
