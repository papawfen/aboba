#ifndef S21_TREE_H_
#define S21_TREE_H_
#include <cstddef>
#include <exception>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename Key, typename T>
class BinaryTree {
 private:
  struct NodeTree;

 public:
  class Iterator;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using size_type = size_t;

  BinaryTree();
  BinaryTree(std::initializer_list<value_type> const& items);
  BinaryTree(const BinaryTree& tree);
  BinaryTree(BinaryTree&& tree);
  ~BinaryTree();
  BinaryTree& operator=(const BinaryTree& tree);
  BinaryTree& operator=(BinaryTree&& tree);
  const mapped_type& at(const key_type& key) const;
  mapped_type& operator[](const key_type& key);

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  bool contains(const key_type& key) const;

  void erase(const key_type& key);  // перегрузка
  void erase(iterator pos);         // основной по заданию

  void swap(BinaryTree& tree);
  void merge(BinaryTree& tree);

 private:
  int GetHeight(NodeTree* node) const;
  int BalanceFactor(NodeTree* node) const;
  void UpdateHeight(NodeTree* node);
  NodeTree* RotateRight(NodeTree* node);
  NodeTree* RotateLeft(NodeTree* node);
  NodeTree* Balance(NodeTree* node);
  NodeTree* BalanceUntilRoot(NodeTree* node);
  void DeleteNode(NodeTree* node);
  NodeTree* FindMinNode(NodeTree* node);
  NodeTree* FindMaxNode(NodeTree* node);
  NodeTree* DeleteMinNode(NodeTree* node);
  NodeTree* RemoveNode(NodeTree* node, const key_type& key);
  NodeTree* FindNode(NodeTree* node, const key_type& key);
  NodeTree* SearchKeyOrNode(NodeTree* node, const key_type& key);
  NodeTree* InsertNode(NodeTree* node, const value_type& value);
  NodeTree* CopyNode(NodeTree* node);

  struct NodeTree {
    value_type data_;
    NodeTree* parent_;
    NodeTree* left_;
    NodeTree* right_;
    int height_;
  };
  NodeTree* root_;
  NodeTree* empty_node_;
  size_type size_;
};

#include "s21_tree.inl"

}  // namespace s21

#endif  // S21_TREE_H_