#include <initializer_list>
#include <iostream>
#include <set>

#include "tree.h"

namespace s21 {
template <class Key>
class multiset : public BinaryTree<Key, Key> {
 public:
  using Nodetree = typename BinaryTree<Key, Key>::NodeTree;
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  multiset() : BinaryTree<Key, Key>::BinaryTree() {}

  multiset(std::initializer_list<value_type> const& items)
      : BinaryTree<Key, Key>::BinaryTree() {
    // typename std::initializer_list<value_type>::iterator it = items.begin();
    // while (it != items.end()) {
    //   insert(std::pair<int, int>(*it, *it));
    //   ++it;
    // }
    for (auto& it : items) {
      this->insert(std::pair<value_type, value_type>(it, it));
    }
  }
  multiset(const multiset& ms) : BinaryTree<Key, Key>::BinaryTree(ms) {}
  multiset(multiset&& ms) noexcept
      : BinaryTree<Key, Key>::BinaryTree(std::move(ms)) {}

  ~multiset() {}

  // size_type max_size() const {
  //   const int to_balance = 8;
  //   return std::numeric_limits<std::ptrdiff_t>::max() /
  //          (sizeof(Nodetree) + to_balance);
  // }

  // typename BinaryTree<Key, Key>::Iterator insert(const value_type& value) {
  //   if (this->empty()) {
  //     this->root_->data_ = std::pair<value_type, value_type>(value, key_++);
  //     (this->size_)++;
  //   } else {
  //     Nodetree* noname = this->root_;
  //     while (noname->left_ || noname->right_) {
  //       if (value >= noname->data_) {
  //         if (noname->right_ && (Iterator(noname->right_) != this->end())) {
  //           noname = noname->right_;
  //         } else
  //           break;
  //       } else if (value < noname->data_) {
  //         if (noname->left_) {
  //           noname = noname->left_;
  //         } else
  //           break;
  //       }
  //     }
  //     new_metod_for_insert(noname, value);
  //   }
  // }

  //  private:
  // int key_ = 0;
  // void new_metod_for_insert(Nodetree* noname, const value_type& value) {
  //   Nodetree* nod = new Nodetree();
  //   nod->data_ = value;
  //   nod->parent_ = noname;
  //   nod->left_ = nod->right_ = nullptr;
  //   if (nod->data_ >= noname->data_) {
  //     noname->right_ = nod;
  //   } else {
  //     noname->left_ = nod;
  //   }
  //   ++(this->size_);
  // }

  // NodeTree* InsertNode(NodeTree* node, const value_type& value) {
  //   if (!node) {
  //     ++size_;
  //     return new NodeTree{value, nullptr, nullptr, nullptr, 1};
  //   }
  //   NodeTree* tmp = SearchKeyOrNode(node, value.first);
  //   if (value.first == tmp->data_.first) return node;

  //   ++size_;
  //   if (value.first < tmp->data_.first)
  //     tmp->left_ = new NodeTree{value, tmp, nullptr, nullptr, 1};
  //   else
  //     tmp->right_ = new NodeTree{value, tmp, nullptr, nullptr, 1};
  //   UpdateHeight(tmp);
  //   return BalanceUntilRoot(tmp);
  // }
};
}  //  namespace s21

//  //  returns an iterator to the first element not less than the given key
//  iterator lower_bound(const Key& key) {}
//  //  returns an iterator to the first element greater than the given key
//  iterator upper_bound(const Key& key) {}

// -----------------------------------------------------------------------//

//  //  erases element at pos
//      void erase(iterator pos) {}
//  //  swaps the contents
//  void swap(multiset& other) {}
//  //  splices nodes from another container
//  void merge(multiset& other) {}

//  //  returns the number of elements matching specific key
//  size_type count(const Key& key) {}

//  //  returns range of elements matching a specific key
//  std::pair<iterator, iterator> equal_range(const Key& key) {}
