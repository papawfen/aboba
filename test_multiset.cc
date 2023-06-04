#include <gtest/gtest.h>

#include "s21_multiset.h"

TEST(multiset_tests, test1) {
  s21::multiset<int> my_ms;
  std::multiset<int> orig_ms;
  ASSERT_EQ(my_ms.size(), orig_ms.size());
}
TEST(multiset_tests, test2) {
  s21::multiset<int> my_ms;
  s21::multiset<int> copy_my_ms(my_ms);
  std::multiset<int> orig_ms;
  std::multiset<int> copy_orig_ms(orig_ms);
  ASSERT_EQ(copy_my_ms.size(), copy_orig_ms.size());
}
TEST(multiset_tests, test3) {
  s21::multiset<int> my_ms;
  s21::multiset<int> copy_my_ms(std::move(my_ms));
  std::multiset<int> orig_ms;
  std::multiset<int> copy_orig_ms(std::move(orig_ms));
  ASSERT_EQ(copy_my_ms.size(), copy_orig_ms.size());
}
TEST(multiset_tests, test4) {
  s21::multiset<int> my_ms;
  std::multiset<int> orig_ms;
  my_ms.insert(std::pair<int, int>(1, 3));
  my_ms.insert(std::pair<int, int>(2, 5));
  my_ms.insert(std::pair<int, int>(3, 2));
  my_ms.insert(std::pair<int, int>(4, 7));
  my_ms.insert(std::pair<int, int>(5, 4));
  my_ms.insert(std::pair<int, int>(6, 3));
  orig_ms.insert(3);
  orig_ms.insert(5);
  orig_ms.insert(2);
  orig_ms.insert(7);
  orig_ms.insert(4);
  orig_ms.insert(3);
  ASSERT_EQ(my_ms.size(), orig_ms.size());
}
TEST(multiset_tests, test5) {
  s21::multiset<int> const my_ms;
  s21::multiset<int> copy_my_ms(std::move(my_ms));
  std::multiset<int> const orig_ms;
  std::multiset<int> copy_orig_ms(std::move(orig_ms));
  ASSERT_EQ(copy_my_ms.size(), copy_orig_ms.size());
}
TEST(multiset_tests, test6) {
  s21::multiset<int> my_ms{1, 2, 3, 4, 5, 6, 7};
  s21::multiset<int> new_my_ms = my_ms;
  s21::multiset<int> orig_ms{1, 2, 3, 4, 5, 6, 7};
  s21::multiset<int> new_orig_ms = orig_ms;
  ASSERT_EQ(new_my_ms.size(), new_orig_ms.size());
}
TEST(multiset_tests, test8) {
  s21::multiset<int> my_ms;
  std::multiset<int> orig_ms;
  my_ms.insert(std::pair<int, int>(1, 3));
  my_ms.insert(std::pair<int, int>(2, 5));
  my_ms.insert(std::pair<int, int>(3, 2));
  my_ms.insert(std::pair<int, int>(4, 7));
  my_ms.insert(std::pair<int, int>(5, 4));
  my_ms.insert(std::pair<int, int>(6, 3));
  orig_ms.insert(3);
  orig_ms.insert(5);
  orig_ms.insert(2);
  orig_ms.insert(7);
  orig_ms.insert(4);
  orig_ms.insert(3);
  my_ms.begin() == orig_ms.begin();
  // ASSERT_EQ(_ms.begin(), *orig_ms.begin());
}
TEST(multiset_tests, test9) {
  s21::multiset<int> my_ms{1, 2, 3, 4, 5, 6};
  std::multiset<int> orig_ms{1, 2, 3, 4, 5, 6};
  std::cout << my_ms.max_size() << "  __  " << orig_ms.max_size() << std::endl;
  ASSERT_EQ(my_ms.max_size(), orig_ms.max_size());
}
TEST(multiset_tests, test10) {}
TEST(multiset_tests, test11) {}
TEST(multiset_tests, test12) {}
TEST(multiset_tests, test13) {}
TEST(multiset_tests, test14) {}
TEST(multiset_tests, test15) {}
TEST(multiset_tests, test16) {}
TEST(multiset_tests, test17) {}
TEST(multiset_tests, test18) {}
TEST(multiset_tests, test19) {}
TEST(multiset_tests, test20) {}
TEST(multiset_tests, test21) {}
TEST(multiset_tests, test22) {}
TEST(multiset_tests, test23) {}
TEST(multiset_tests, test24) {}

// TEST(multiset_tests, test2) {
//   s21::multiset<int> my_ms;
//   std::multiset<int> orig_ms;
//   my_ms.insert(3);
//   orig_ms.insert(3);
//   ASSERT_EQ(my_ms.size(), orig_ms.size());
// }
// TEST(multiset_tests, test2) {
//   s21::multiset<int> my_ms;
//   std::multiset<int> orig_ms;
//   ASSERT_EQ(my_ms.max_size(), orig_ms.max_size());
// }
