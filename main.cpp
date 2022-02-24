#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol418;

/*
Input:
rows = 2, cols = 8, sentence = ["hello", "world"]
Output:
1
Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
*/
tuple<vector<string>, int, int, int>
testFixture1()
{
  auto words = vector<string>{"hello", "world"};

  return make_tuple(words, 2, 8, 1);
}

/*
Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
Output:
2
Explanation:
a-bcd-
e-a---
bcd-e-
*/

tuple<vector<string>, int, int, int>
testFixture2()
{
  auto words = vector<string>{"a", "bcd", "e"};

  return make_tuple(words, 3, 6, 2);
}

/*
Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
Output:
1
Explanation:
I-had
apple
pie-I
had--
*/
tuple<vector<string>, int, int, int>
testFixture3()
{
  auto words = vector<string>{"I", "had", "apple", "pie"};

  return make_tuple(words, 4, 5, 1);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<3>(f)) << endl;
  auto result = Solution::countTimes(get<0>(f), get<1>(f), get<2>(f));
  cout << "result: " << to_string(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<3>(f)) << endl;
  auto result = Solution::countTimes(get<0>(f), get<1>(f), get<2>(f));
  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << to_string(get<3>(f)) << endl;
  auto result = Solution::countTimes(get<0>(f), get<1>(f), get<2>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}