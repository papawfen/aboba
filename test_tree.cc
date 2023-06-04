#include <gtest/gtest.h>

#include <cstddef>
#include <iterator>
#include <map>
#include <string>

#include "s21_tree.h"

TEST(s21_tree_insert_check, test1) {
  s21::BinaryTree<int, int> st;
  std::map<int, int> st_original;
  std::pair<s21::BinaryTree<int, int>::Iterator, bool> it =
      st.insert(std::pair<int, int>(1, 111));
  std::pair<std::map<int, int>::iterator, bool> it_original =
      st_original.insert(std::pair<int, int>(1, 111));
  ASSERT_EQ(it.first->first, it_original.first->first);
  ASSERT_EQ(it.second, it_original.second);
  ASSERT_EQ(st.size(), st_original.size());

  it = st.insert(std::pair<int, int>(1, 111));
  it_original = st_original.insert(std::pair<int, int>(1, 111));
  ASSERT_EQ(it.first->first, it_original.first->first);
  ASSERT_EQ(it.second, it_original.second);
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_tree_size_check, test1) {
  s21::BinaryTree<int, int> st;
  std::map<int, int> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  st.insert(std::pair<int, int>(1, 111));
  st_original.insert(std::pair<int, int>(1, 111));
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_tree_size_check, test2) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  ASSERT_EQ(t.size(), t_original.size());

  t.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  ASSERT_EQ(t.size(), t_original.size());

  t.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  ASSERT_EQ(t.size(), t_original.size());

  t.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  ASSERT_EQ(t.size(), t_original.size());

  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  ASSERT_EQ(t.size(), t_original.size());

  t.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  ASSERT_EQ(t.size(), t_original.size());
}

TEST(s21_tree_contains_check, test1) {
  s21::BinaryTree<int, int> st;
  st.insert(std::pair<int, int>(1, 111));
  ASSERT_EQ(st.contains(1), true);
  ASSERT_EQ(st.contains(5), false);
}

TEST(s21_tree_empty_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  ASSERT_EQ(t.empty(), t_original.empty());

  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  ASSERT_EQ(t.empty(), t_original.empty());
}

TEST(s21_tree_initializer_check, test1) {
  s21::BinaryTree<int, char> t(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  std::map<int, char> t_original(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  ASSERT_EQ(t.at(1), t_original.at(1));
  ASSERT_EQ(t.at(2), t_original.at(2));
  ASSERT_EQ(t.at(3), t_original.at(3));
  ASSERT_EQ(t.at(4), t_original.at(4));
  ASSERT_EQ(t.at(5), t_original.at(5));
  ASSERT_EQ(t.at(6), t_original.at(6));
  ASSERT_EQ(t.at(7), t_original.at(7));
  ASSERT_EQ(t.size(), t_original.size());
}

TEST(s21_tree_copy_check, test1) {
  s21::BinaryTree<int, char> t(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  std::map<int, char> t_original(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  s21::BinaryTree<int, char> t_1(t);
  std::map<int, char> t_original_1(t_original);
  ASSERT_EQ(t_1.at(1), t_original_1.at(1));
  ASSERT_EQ(t_1.at(2), t_original_1.at(2));
  ASSERT_EQ(t_1.at(3), t_original_1.at(3));
  ASSERT_EQ(t_1.at(4), t_original_1.at(4));
  ASSERT_EQ(t_1.at(5), t_original_1.at(5));
  ASSERT_EQ(t_1.at(6), t_original_1.at(6));
  ASSERT_EQ(t_1.at(7), t_original_1.at(7));
  ASSERT_EQ(t_1.size(), t_original_1.size());
}

TEST(s21_tree_oper_copy_check, test1) {
  s21::BinaryTree<int, char> t(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  std::map<int, char> t_original(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  s21::BinaryTree<int, char> t_1;
  t_1 = t;
  std::map<int, char> t_original_1;
  t_original_1 = t_original;
  ASSERT_EQ(t_1.at(1), t_original_1.at(1));
  ASSERT_EQ(t_1.at(2), t_original_1.at(2));
  ASSERT_EQ(t_1.at(3), t_original_1.at(3));
  ASSERT_EQ(t_1.at(4), t_original_1.at(4));
  ASSERT_EQ(t_1.at(5), t_original_1.at(5));
  ASSERT_EQ(t_1.at(6), t_original_1.at(6));
  ASSERT_EQ(t_1.at(7), t_original_1.at(7));
  ASSERT_EQ(t_1.size(), t_original_1.size());

  ASSERT_EQ(t.at(1), t_original.at(1));
  ASSERT_EQ(t.at(4), t_original.at(4));
  ASSERT_EQ(t.at(7), t_original.at(7));
  ASSERT_EQ(t.size(), t_original.size());
}

TEST(s21_tree_begin_check, test1) {
  s21::BinaryTree<int, char> t(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  std::map<int, char> t_original(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  s21::BinaryTree<int, char>::iterator it = t.begin();
  std::map<int, char>::iterator it_original = t_original.begin();
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
}

TEST(s21_tree_incpref_iter_check, test1) {
  s21::BinaryTree<int, char> t(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  std::map<int, char> t_original(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  s21::BinaryTree<int, char>::iterator it = t.begin();
  std::map<int, char>::iterator it_original = t_original.begin();
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
  ++it;
  ++it_original;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
  ++it;
  ++it_original;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
}

TEST(s21_tree_incpref_iter_check, test2) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();

  while (it_original != t_original.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
}

TEST(s21_tree_incpref_iter_check, test3) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();

  ASSERT_EQ(it->second, it_original->second);
}

TEST(s21_tree_incpref_iter_check, test4) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 136; i += 3) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();

  while (it_original != t_original.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
}

// TEST(s21_tree_incpref_iter_check, test5) {
//   s21::BinaryTree<int, int> t;
//   std::map<int, int> t_original;
//   for (int i = -27; i < 136; i += 3) {
//     t.insert(std::pair<int, int>(i, 111));
//     t_original.insert(std::pair<int, int>(i, 111));
//   }
//   s21::BinaryTree<int, int>::iterator it = t.end();
//   std::map<int, int>::iterator it_original = t_original.end();
//   ++it;
//   ++it_original;
//   // ASSERT_EQ(it->first, it_original->first);
//   // ASSERT_EQ(it->second, it_original->second);
//   ++it;
//   ++it_original;
//   ASSERT_EQ(it->first, it_original->first);
//   ASSERT_EQ(it->second, it_original->second);
// }

TEST(s21_tree_iter_incpost_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 136; i += 3) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();

  while (it_original != t_original.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    it++;
    it_original++;
  }
}

// TEST(s21_tree_iter_incpost_check, test2) {
//   s21::BinaryTree<int, int> t;
//   std::map<int, int> t_original;
//   for (int i = -27; i < 136; i += 3) {
//     t.insert(std::pair<int, int>(i, 111));
//     t_original.insert(std::pair<int, int>(i, 111));
//   }
//   s21::BinaryTree<int, int>::iterator it = t.begin();
//   std::map<int, int>::iterator it_original = t_original.begin();
//   ASSERT_EQ(it->first, it_original->first);
//   ASSERT_EQ(it->second, it_original->second);
//   t.erase(-27);
//   t_original.erase(-27);
//   // ASSERT_EQ(it->first, it_original->first);
//   // ASSERT_EQ(it->second, it_original->second);
//   //  it++;
//   it_original++;
//   // ASSERT_EQ(it->first, it_original->first);
//   // ASSERT_EQ(it->second, it_original->second);
//   // it++;
//   it_original++;
//   // ASSERT_EQ(it->first, it_original->first);
//   // ASSERT_EQ(it->second, it_original->second);
// }

TEST(s21_tree_decpref_iter_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();

  --it;
  --it_original;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
}

TEST(s21_tree_decpref_iter_check, test2) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();

  while (it_original != t_original.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
  }
}

TEST(s21_tree_decpref_iter_check, test3) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  --it;
  --it_original;
  --it;
  --it_original;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
  --it;
  --it_original;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
}

TEST(s21_tree_iter_decpost_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 136; i += 3) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();

  while (it_original != t_original.begin()) {
    it--;
    it_original--;
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
  }
}

TEST(s21_tree_decpost_iter_check, test2) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  s21::BinaryTree<int, int>::iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  it--;
  it_original--;
  it--;
  it_original--;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
  it--;
  it_original--;
  ASSERT_EQ(it->first, it_original->first);
  ASSERT_EQ(it->second, it_original->second);
}

TEST(s21_tree_insert_string_check, test1) {
  s21::BinaryTree<std::string, int> t;
  std::map<std::string, int> t_original;
  t.insert(std::pair<std::string, int>("2", 111));
  t.insert(std::pair<std::string, int>("1", 111));
  t_original.insert(std::pair<std::string, int>("2", 111));
  t_original.insert(std::pair<std::string, int>("1", 111));
  s21::BinaryTree<std::string, int>::Iterator it = t.begin();
  std::map<std::string, int>::iterator it_original = t_original.begin();
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at("1"));
  ASSERT_ANY_THROW(t_original.at("1"));
}

// TEST(s21_tree_insert_string_check, test2) {
//   struct Aboba {
//     std::string a;
//     double b;
//   };
//   Aboba t1{"aboba", 25.4};
//   Aboba t2{"bobab", 26.4};
//   s21::BinaryTree<Aboba, int> t;
//   std::map<Aboba, int> t_original;
//   t.insert(std::pair<Aboba, int>(t1, 111));
//   t.insert(std::pair<Aboba, int>(t2, 222));
//   t_original.insert(std::pair<Aboba, int>(t1, 111));
//   t_original.insert(std::pair<Aboba, int>(t2, 222));
//   t.erase(t1);
//   t_original.erase(t1);
//   ASSERT_EQ(t.size(), t_original.size());
//   ASSERT_ANY_THROW(t.at(t1));
//   ASSERT_ANY_THROW(t_original.at(t1));
// }

TEST(s21_tree_at_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  ASSERT_EQ(t.at(3), t_original.at(3));
  ASSERT_EQ(t.at(1), t_original.at(1));
  ASSERT_ANY_THROW(t.at(7));
  ASSERT_ANY_THROW(t_original.at(7));

  t.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  ASSERT_EQ(t.at(5), t_original.at(5));
  ASSERT_EQ(t.at(2), t_original.at(2));
  ASSERT_ANY_THROW(t.at(-2));
  ASSERT_ANY_THROW(t_original.at(-2));
}

TEST(s21_tree_erase_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test2) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(1));
  ASSERT_ANY_THROW(t_original.at(1));
}

TEST(s21_tree_erase_check, test3) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test4) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test5) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(1));
  ASSERT_ANY_THROW(t_original.at(1));
}

TEST(s21_tree_erase_check, test6) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  s21::BinaryTree<int, int>::Iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();
  --it;
  --it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test7) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();
  --it;
  --it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test8) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test9) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(1));
  ASSERT_ANY_THROW(t_original.at(1));
}

TEST(s21_tree_erase_check, test10) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();
  --it;
  --it_original;
  --it;
  --it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(1));
  ASSERT_ANY_THROW(t_original.at(1));
}

TEST(s21_tree_erase_check, test11) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  --it;
  --it_original;
  --it;
  --it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(5));
  ASSERT_ANY_THROW(t_original.at(5));
}

TEST(s21_tree_erase_check, test12) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test13) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test14) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(6));
  ASSERT_ANY_THROW(t_original.at(6));
}

TEST(s21_tree_erase_check, test15) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test16) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test17) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  s21::BinaryTree<int, int>::Iterator it = t.begin();
  std::map<int, int>::iterator it_original = t_original.begin();
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  ++it;
  ++it_original;
  ASSERT_EQ(it->first, it_original->first);

  t.erase(it);
  t_original.erase(it_original);
  ASSERT_EQ(t.size(), t_original.size());

  ASSERT_ANY_THROW(t.at(5));
  ASSERT_ANY_THROW(t_original.at(5));
}

TEST(s21_tree_erase_check, test18) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t.erase(6);
  t_original.erase(6);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(6));
  ASSERT_ANY_THROW(t_original.at(6));
}

TEST(s21_tree_erase_check, test19) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t.erase(8);
  t_original.erase(8);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(8));
  ASSERT_ANY_THROW(t_original.at(8));
}

TEST(s21_tree_erase_check, test20) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t.erase(3);
  t_original.erase(3);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test21) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t.erase(7);
  t_original.erase(7);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(7));
  ASSERT_ANY_THROW(t_original.at(7));
}

TEST(s21_tree_erase_check, test22) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(8, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t.erase(7);
  t_original.erase(7);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(7));
  ASSERT_ANY_THROW(t_original.at(7));
}

TEST(s21_tree_erase_check, test23) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(8, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t.erase(8);
  t_original.erase(8);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(8));
  ASSERT_ANY_THROW(t_original.at(8));
}

TEST(s21_tree_erase_check, test24) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(8, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t.erase(2);
  t_original.erase(2);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test25) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(8, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t.erase(4);
  t_original.erase(4);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test26) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(4);
  t_original.erase(4);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test27) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(2);
  t_original.erase(2);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test28) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(3);
  t_original.erase(3);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test29) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t.erase(4);
  t_original.erase(4);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test30) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t.erase(6);
  t_original.erase(6);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(6));
  ASSERT_ANY_THROW(t_original.at(6));
}

TEST(s21_tree_erase_check, test31) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t.erase(5);
  t_original.erase(5);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(5));
  ASSERT_ANY_THROW(t_original.at(5));
}

TEST(s21_tree_erase_check, test32) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(4);
  t_original.erase(4);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test33) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(2);
  t_original.erase(2);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test34) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(3);
  t_original.erase(3);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test35) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(4);
  t_original.erase(4);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_erase_check, test36) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t.erase(6);
  t_original.erase(6);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(6));
  ASSERT_ANY_THROW(t_original.at(6));
}

TEST(s21_tree_erase_check, test37) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(0, 111));
  t.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t.erase(1);
  t_original.erase(1);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(1));
  ASSERT_ANY_THROW(t_original.at(1));
}

TEST(s21_tree_erase_check, test38) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(0, 111));
  t.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t.erase(12);
  t_original.erase(12);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(12));
  ASSERT_ANY_THROW(t_original.at(12));
}

TEST(s21_tree_erase_check, test39) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(0, 111));
  t.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t.erase(2);
  t_original.erase(2);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test40) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(11, 111));
  t.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(11, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t.erase(2);
  t_original.erase(2);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(2));
  ASSERT_ANY_THROW(t_original.at(2));
}

TEST(s21_tree_erase_check, test41) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(11, 111));
  t.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(11, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t.erase(12);
  t_original.erase(12);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(12));
  ASSERT_ANY_THROW(t_original.at(12));
}

TEST(s21_tree_erase_check, test42) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(11, 111));
  t.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(11, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t.erase(10);
  t_original.erase(10);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(10));
  ASSERT_ANY_THROW(t_original.at(10));
}

TEST(s21_tree_erase_check, test43) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(11, 111));
  t.insert(std::pair<int, int>(19, 111));
  t.insert(std::pair<int, int>(15, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(11, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(15, 111));
  t.erase(12);
  t_original.erase(12);
  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(12));
  ASSERT_ANY_THROW(t_original.at(12));
}

TEST(s21_tree_erase_check, test44) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t.erase(6);
  t.erase(8);
  t.erase(7);
  t.erase(5);
  t.erase(4);
  t.erase(3);
  t_original.erase(6);
  t_original.erase(8);
  t_original.erase(7);
  t_original.erase(5);
  t_original.erase(4);
  t_original.erase(3);

  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(3));
  ASSERT_ANY_THROW(t_original.at(3));
}

TEST(s21_tree_erase_check, test45) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(6, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t.erase(5);
  t.erase(6);
  t.erase(8);
  t.erase(7);
  t.erase(3);
  t.erase(2);
  t_original.erase(5);
  t_original.erase(6);
  t_original.erase(8);
  t_original.erase(7);
  t_original.erase(3);
  t_original.erase(2);

  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(6));
  ASSERT_ANY_THROW(t_original.at(6));
}

TEST(s21_tree_erase_check, test46) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 36; ++i) {
    t.insert(std::pair<int, int>(i, 111));
    t_original.insert(std::pair<int, int>(i, 111));
  }
  for (int i = -22; i < 29; i += 3) {
    t.erase(i);
    t_original.erase(i);
  }

  ASSERT_EQ(t.size(), t_original.size());
}

TEST(s21_tree_erase_check, test47) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(7, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(5, 111));
  t.insert(std::pair<int, int>(8, 111));
  t.insert(std::pair<int, int>(6, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(7, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(5, 111));
  t_original.insert(std::pair<int, int>(8, 111));
  t_original.insert(std::pair<int, int>(6, 111));
  t.erase(4);
  t_original.erase(4);

  ASSERT_EQ(t.size(), t_original.size());
  ASSERT_ANY_THROW(t.at(4));
  ASSERT_ANY_THROW(t_original.at(4));
}

TEST(s21_tree_max_size_check, test1) {
  s21::BinaryTree<double, int> t;
  std::map<double, int> t_original;
  for (double i = -27.555; i < 36.999; i += 1.337) {
    t.insert(std::pair<double, int>(i, 111));
    t_original.insert(std::pair<double, int>(i, 111));
  }
  ASSERT_EQ(t.max_size(), t_original.max_size());
}

TEST(s21_tree_max_size_check, test2) {
  s21::BinaryTree<long long int, char> t;
  std::map<long long int, char> t_original;
  ASSERT_EQ(t.max_size(), t_original.max_size());
}

TEST(s21_tree_max_size_check, test3) {
  s21::BinaryTree<std::string, char> t;
  std::map<std::string, char> t_original;
  ASSERT_EQ(t.max_size(), t_original.max_size());
}

TEST(s21_tree_swap_check, test1) {
  s21::BinaryTree<int, int> t_1, t_2;
  std::map<int, int> t_original_1, t_original_2;
  for (int i = -27; i < 36; ++i) {
    t_1.insert(std::pair<int, int>(i, 85));
    t_original_1.insert(std::pair<int, int>(i, 85));
  }
  for (int i = -7; i < 12; ++i) {
    t_2.insert(std::pair<int, int>(i, 17));
    t_original_2.insert(std::pair<int, int>(i, 17));
  }
  t_1.swap(t_2);
  t_original_1.swap(t_original_2);

  s21::BinaryTree<int, int>::iterator it = t_1.begin();
  std::map<int, int>::iterator it_original = t_original_1.begin();

  while (it_original != t_original_1.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
  it = t_2.begin();
  it_original = t_original_2.begin();
  while (it_original != t_original_2.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }

  ASSERT_EQ(t_1.size(), t_original_1.size());
  ASSERT_EQ(t_2.size(), t_original_2.size());
}

TEST(s21_tree_constr_move_check, test1) {
  s21::BinaryTree<int, int> t_1;
  std::map<int, int> t_original_1;
  for (int i = -27; i < 36; ++i) {
    t_1.insert(std::pair<int, int>(i, 85));
    t_original_1.insert(std::pair<int, int>(i, 85));
  }

  s21::BinaryTree<int, int> t_2(std::move(t_1));
  std::map<int, int> t_original_2(std::move(t_original_1));

  s21::BinaryTree<int, int>::iterator it = t_1.begin();
  std::map<int, int>::iterator it_original = t_original_1.begin();

  while (it_original != t_original_1.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
  it = t_2.begin();
  it_original = t_original_2.begin();
  while (it_original != t_original_2.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }

  ASSERT_EQ(t_1.size(), t_original_1.size());
  ASSERT_EQ(t_2.size(), t_original_2.size());
}

TEST(s21_tree_oper_move_check, test1) {
  s21::BinaryTree<int, int> t_1;
  std::map<int, int> t_original_1;
  for (int i = -27; i < 36; ++i) {
    t_1.insert(std::pair<int, int>(i, 85));
    t_original_1.insert(std::pair<int, int>(i, 85));
  }

  s21::BinaryTree<int, int> t_2;
  t_2 = (std::move(t_1));
  std::map<int, int> t_original_2;
  t_original_2 = (std::move(t_original_1));

  s21::BinaryTree<int, int>::iterator it = t_1.begin();
  std::map<int, int>::iterator it_original = t_original_1.begin();

  while (it_original != t_original_1.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
  it = t_2.begin();
  it_original = t_original_2.begin();
  while (it_original != t_original_2.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }

  ASSERT_EQ(t_1.size(), t_original_1.size());
  ASSERT_EQ(t_2.size(), t_original_2.size());
}

TEST(s21_tree_brackets_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  ASSERT_EQ(t[1], t_original[1]);
  t[2] = 5;
  t_original[2] = 5;
  ASSERT_EQ(t[2], t_original[2]);
}

TEST(s21_tree_brackets_check, test2) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  ASSERT_EQ(t[1], t_original[1]);
  t[0] = 50;
  t_original[0] = 50;
  t[3] = 55;
  t_original[3] = 55;
  t[-1] = 555;
  t_original[-1] = 555;
  t[8] = 505;
  t_original[8] = 505;
  t[2] = 5050;
  t_original[2] = 5050;
  ASSERT_EQ(t[2], t_original[2]);
  ASSERT_EQ(t[-1], t_original[-1]);
  ASSERT_EQ(t[8], t_original[8]);
  ASSERT_EQ(t[3], t_original[3]);
  ASSERT_EQ(t[0], t_original[0]);
}

TEST(s21_tree_brackets_check, test3) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  t.insert(std::pair<int, int>(9, 111));
  t.insert(std::pair<int, int>(2, 111));
  t.insert(std::pair<int, int>(12, 111));
  t.insert(std::pair<int, int>(1, 111));
  t.insert(std::pair<int, int>(4, 111));
  t.insert(std::pair<int, int>(10, 111));
  t.insert(std::pair<int, int>(17, 111));
  t.insert(std::pair<int, int>(3, 111));
  t.insert(std::pair<int, int>(11, 111));
  t.insert(std::pair<int, int>(19, 111));
  t.insert(std::pair<int, int>(15, 111));
  t_original.insert(std::pair<int, int>(9, 111));
  t_original.insert(std::pair<int, int>(2, 111));
  t_original.insert(std::pair<int, int>(12, 111));
  t_original.insert(std::pair<int, int>(1, 111));
  t_original.insert(std::pair<int, int>(4, 111));
  t_original.insert(std::pair<int, int>(10, 111));
  t_original.insert(std::pair<int, int>(17, 111));
  t_original.insert(std::pair<int, int>(3, 111));
  t_original.insert(std::pair<int, int>(11, 111));
  t_original.insert(std::pair<int, int>(19, 111));
  t_original.insert(std::pair<int, int>(15, 111));
  t[9] = 50;
  t_original[9] = 50;
  t[2] = 55;
  t_original[2] = 55;
  t[12] = 555;
  t_original[12] = 555;
  t[1] = 505;
  t_original[1] = 505;
  t[19] = 5050;
  t_original[19] = 5050;
  ASSERT_EQ(t[10], t_original[10]);
  ASSERT_EQ(t[17], t_original[17]);
  ASSERT_EQ(t[9], t_original[9]);
  ASSERT_EQ(t[2], t_original[2]);
  ASSERT_EQ(t[12], t_original[12]);
  ASSERT_EQ(t[1], t_original[1]);
  ASSERT_EQ(t[19], t_original[19]);
  ASSERT_EQ(t[33], t_original[33]);
  ASSERT_EQ(t.size(), t_original.size());
}

TEST(s21_tree_merge_check, test1) {
  s21::BinaryTree<int, char> t_1(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});
  std::map<int, char> t_original_1(
      {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}});

  s21::BinaryTree<int, char> t_2({{11, 'a'},
                                  {12, 'b'},
                                  {13, 'c'},
                                  {14, 'd'},
                                  {15, 'e'},
                                  {16, 'f'},
                                  {7, 'g'}});
  std::map<int, char> t_original_2({{11, 'a'},
                                    {12, 'b'},
                                    {13, 'c'},
                                    {14, 'd'},
                                    {15, 'e'},
                                    {16, 'f'},
                                    {7, 'g'}});

  t_1.merge(t_2);
  t_original_1.merge(t_original_2);

  s21::BinaryTree<int, char>::iterator it = t_1.begin();
  std::map<int, char>::iterator it_original = t_original_1.begin();
  while (it_original != t_original_1.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
  it = t_2.begin();
  it_original = t_original_2.begin();
  while (it_original != t_original_2.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }

  ASSERT_EQ(t_1.size(), t_original_1.size());
  ASSERT_EQ(t_2.size(), t_original_2.size());
}

TEST(s21_tree_merge_check, test2) {
  s21::BinaryTree<int, int> t_1, t_2;
  std::map<int, int> t_original_1, t_original_2;
  for (int i = -27; i < 36; ++i) {
    t_1.insert(std::pair<int, int>(i, 85));
    t_original_1.insert(std::pair<int, int>(i, 85));
  }
  for (int i = -7; i < 12; ++i) {
    t_2.insert(std::pair<int, int>(i, 17));
    t_original_2.insert(std::pair<int, int>(i, 17));
  }
  t_1.merge(t_2);
  t_original_1.merge(t_original_2);

  s21::BinaryTree<int, int>::iterator it = t_1.begin();
  std::map<int, int>::iterator it_original = t_original_1.begin();

  while (it_original != t_original_1.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }
  it = t_2.begin();
  it_original = t_original_2.begin();
  while (it_original != t_original_2.end()) {
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
    ++it;
    ++it_original;
  }

  ASSERT_EQ(t_1.size(), t_original_1.size());
  ASSERT_EQ(t_2.size(), t_original_2.size());
}

TEST(s21_tree_insert_key_obj_check, test1) {
  s21::BinaryTree<int, int> t;
  std::map<int, int> t_original;
  for (int i = -27; i < 136; i += 3) {
    t.insert(i, i * 5);
    t_original.insert(std::pair<int, int>(i, i * 5));
  }
  s21::BinaryTree<int, int>::iterator it = t.end();
  std::map<int, int>::iterator it_original = t_original.end();

  while (it_original != t_original.begin()) {
    it--;
    it_original--;
    ASSERT_EQ(it->first, it_original->first);
    ASSERT_EQ(it->second, it_original->second);
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
