#ifndef S21_TREE_H_
#define S21_TREE_H_
#include <cstddef>
#include <exception>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename Key, typename T>
class BinaryTree {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  struct NodeTree {
    value_type data_;
    NodeTree* parent_;
    NodeTree* left_;
    NodeTree* right_;
    int height_;
  };

  NodeTree* root_;
  NodeTree* empty_node_;
  size_t size_;

  class Iterator {
    public:
  friend class BinaryTree;
  Iterator(NodeTree* ptr_ = nullptr, NodeTree* ptr_empty_ = nullptr)
      : ptr_(ptr_), ptr_empty_(ptr_empty_) {}

  reference operator=(const_reference it) {
    ptr_ = it.ptr_;
    ptr_empty_ = it.ptr_empty_;
    return ptr_;
  }

  reference operator*() const noexcept {
    if (ptr_)
      return ptr_->data_;
    else
      return ptr_empty_->data_;
  }

  value_type* operator->() {
    if (ptr_)
      return &(ptr_->data_);
    else
      return &(ptr_empty_->data_);
  }

  Iterator& operator++() noexcept {
    if (!ptr_)
      ptr_ = ptr_empty_;
    else if (ptr_->right_) {
      ptr_ = ptr_->right_;
      while (ptr_->left_) ptr_ = ptr_->left_;
    } else {
      NodeTree* parent = ptr_->parent_;
      while (parent && ptr_ == parent->right_) {
        ptr_ = parent;
        parent = parent->parent_;
      }
      ptr_ = parent;
    }
    return *this;
  }

  Iterator operator++(int) noexcept {
    Iterator tmp(*this);
    operator++();
    return tmp;
  }

  Iterator& operator--() noexcept {
    if (!ptr_)
      ptr_ = ptr_empty_->parent_;
    else if (ptr_->left_) {
      ptr_ = ptr_->left_;
      while (ptr_->right_) ptr_ = ptr_->right_;
    } else {
      NodeTree* parent = ptr_->parent_;
      while (parent && ptr_ == parent->left_) {
        ptr_ = parent;
        parent = parent->parent_;
      }
      ptr_ = parent;
    }
    return *this;
  }

  Iterator operator--(int) noexcept {
    Iterator tmp(*this);
    operator--();
    return tmp;
  }

  bool operator==(const Iterator& it) const noexcept {
    return (ptr_ == it.ptr_);
  }

  bool operator!=(const Iterator& it) const noexcept {
    return (ptr_ != it.ptr_);
  }

 private:
  NodeTree* ptr_;
  NodeTree* ptr_empty_;
  };

Iterator begin() noexcept {
  NodeTree* min_node = FindMinNode(root_);
  NodeTree* empty = empty_node_;
  return Iterator(min_node, empty);
}


Iterator end() noexcept {
  NodeTree* empty = empty_node_;
  return Iterator(nullptr, empty);
}

BinaryTree() : root_(nullptr), size_(0) {
  empty_node_ = new NodeTree{value_type(), root_, nullptr, nullptr, 0};
}

BinaryTree(
    std::initializer_list<value_type> const& items)
    : BinaryTree() {
  for (const auto& element : items) insert(element);
  empty_node_->parent_ = FindMaxNode(root_);
}


BinaryTree(const BinaryTree& tree)
    : BinaryTree() {
  *this = tree;
}


BinaryTree(BinaryTree&& tree)
    : BinaryTree() {
  swap(tree);
}

~BinaryTree() {
  clear();
  delete empty_node_;
}


BinaryTree<key_type, mapped_type>& operator=(
    const BinaryTree& tree) {
  if (this != &tree) {
    clear();
    root_ = CopyNode(tree.root_);
    empty_node_->parent_ = FindMaxNode(root_);
  }
  return *this;
}

BinaryTree<key_type, mapped_type>& operator=(
    BinaryTree&& tree) {
  swap(tree);
  return *this;
}

NodeTree* CopyNode(NodeTree* node) {
  if (!node) return nullptr;
  NodeTree* new_node =
      new NodeTree{node->data_, nullptr, nullptr, nullptr, node->height_};
  ++size_;
  new_node->left_ = CopyNode(node->left_);
  new_node->right_ = CopyNode(node->right_);
  return new_node;
}


const mapped_type& at(
    const key_type& key) const {
  NodeTree* current = root_;
  while (current) {
    if (current->data_.first == key) {
      return current->data_.second;
    }
    if (key < current->data_.first) {
      current = current->left_;
    } else {
      current = current->right_;
    }
  }
  throw std::out_of_range("key not found");
}


mapped_type& operator[](
    const key_type& key) {
  root_ =
      InsertNode(root_, std::pair<key_type, mapped_type>(key, mapped_type()));
  empty_node_->parent_ = FindMaxNode(root_);
  NodeTree* find_node = FindNode(root_, key);
  return find_node->data_.second;
}


bool empty() const noexcept {
  return size_ == 0;
}


size_type size() const noexcept {
  return size_;
}

size_type max_size() const noexcept {
    const int to_balance = 8;
    return std::numeric_limits<std::ptrdiff_t>::max() /
           (sizeof(NodeTree) + to_balance);
}

void clear() {
  DeleteNode(root_);
  empty_node_->parent_ = nullptr;
}


std::pair<Iterator, bool> insert(const value_type& value) {
  NodeTree* node = FindNode(root_, value.first);
  Iterator it;
  if (node) {
    it.ptr_ = node;
    return std::pair<Iterator, bool>(it, false);
  }
  root_ = InsertNode(root_, value);
  empty_node_->parent_ = FindMaxNode(root_);
  node = FindNode(root_, value.first);
  it.ptr_ = node;
  return std::pair<Iterator, bool>(it, true);
}

std::pair<Iterator, bool> insert(const key_type& key,
                                               const mapped_type& obj) {
  NodeTree* node = FindNode(root_, key);
  Iterator it;
  if (node) {
    it.ptr_ = node;
    return std::pair<Iterator, bool>(it, false);
  }
  root_ = InsertNode(root_, std::pair<key_type, mapped_type>(key, obj));
  empty_node_->parent_ = FindMaxNode(root_);
  node = FindNode(root_, key);
  it.ptr_ = node;
  return std::pair<Iterator, bool>(it, true);
}


bool contains(const key_type& key) const {
  NodeTree* current = root_;
  while (current) {
    if (current->data_.first == key) {
      return true;
    }
    if (key < current->data_.first) {
      current = current->left_;
    } else {
      current = current->right_;
    }
  }
  return false;
}


void DeleteNode(NodeTree* node) {
  if (node) {
    DeleteNode(node->left_);
    DeleteNode(node->right_);
    delete node;
  }
}


NodeTree* FindMinNode(NodeTree* node) {
  if (!node) return nullptr;
  return node->left_ ? FindMinNode(node->left_) : node;
}

NodeTree* FindMaxNode(NodeTree* node) {
  if (!node) return nullptr;
  return node->right_ ? FindMaxNode(node->right_) : node;
}


NodeTree* FindNode(NodeTree* node,
                                            const key_type& key) {
  if (!(node) || key == node->data_.first) return node;
  if (key < node->data_.first)
    return FindNode(node->left_, key);
  else
    return FindNode(node->right_, key);
}


NodeTree* SearchKeyOrNode(NodeTree* node,
                                                   const key_type& key) {
  NodeTree* find_node = nullptr;
  NodeTree* current = node;
  while ((current) && (key != current->data_.first)) {
    find_node = current;
    if (key < current->data_.first)
      current = current->left_;
    else
      current = current->right_;
  }
  if (current) find_node = current;
  return find_node;
}


NodeTree* InsertNode(NodeTree* node,
                                              const value_type& value) {
  if (!node) {
    ++size_;
    return new NodeTree{value, nullptr, nullptr, nullptr, 1};
  }
  NodeTree* tmp = SearchKeyOrNode(node, value.first);
  if (value.first == tmp->data_.first) return node;

  ++size_;
  if (value.first < tmp->data_.first)
    tmp->left_ = new NodeTree{value, tmp, nullptr, nullptr, 1};
  else
    tmp->right_ = new NodeTree{value, tmp, nullptr, nullptr, 1};
  UpdateHeight(tmp);
  return BalanceUntilRoot(tmp);
}


NodeTree* DeleteMinNode(NodeTree* node) {
  if (!node) return nullptr;
  NodeTree* min_node = FindMinNode(node);
  NodeTree* parent = min_node->parent_;
  if (min_node == node) {
    if (node->right_) {
      parent->right_ = node->right_;
      node = node->right_;
    } else {
      parent->right_ = nullptr;
      node = nullptr;
    }
  } else {
    if (min_node->right_) {
      NodeTree* tmp = min_node->right_;
      tmp->parent_ = parent;
      parent->left_ = tmp;
    } else {
      parent->left_ = nullptr;
    }
  }
  delete min_node;
  --size_;
  if (!node) return nullptr;
  while (parent) {
    UpdateHeight(parent);
    parent = parent->parent_;
  }
  return Balance(node);
}


void erase(const key_type& key) {
  root_ = RemoveNode(root_, key);
  empty_node_->parent_ = FindMaxNode(root_);
}


void erase(Iterator pos) {
  key_type deleted_key = pos->first;
  root_ = RemoveNode(root_, deleted_key);
  empty_node_->parent_ = FindMaxNode(root_);
}


void swap(BinaryTree& tree) {
  if (this != &tree) {
    NodeTree* tmp_root = root_;
    NodeTree* tmp_empty = empty_node_;
    size_type tmp_size = size_;
    root_ = tree.root_;
    empty_node_ = tree.empty_node_;
    size_ = tree.size_;
    tree.root_ = tmp_root;
    tree.empty_node_ = tmp_empty;
    tree.size_ = tmp_size;
  }
}


void merge(BinaryTree& tree) {
  if (this != &tree) {
    Iterator it = tree.begin();
    bool insert_key = false;
    key_type tmp_del = key_type();
    key_type tmp_next = key_type();
    while (it != tree.end()) {
      insert_key =
          insert(std::pair<key_type, mapped_type>(it->first, it->second))
              .second;
      if (insert_key) {
        tmp_del = it->first;
        ++it;
        tmp_next = it->first;
        tree.erase(tmp_del);
        it.ptr_ = FindNode(tree.root_, tmp_next);
      } else
        ++it;
    }
  }
}

NodeTree* RemoveNode(NodeTree* node,
                                              const key_type& key) {
  if (!node) return nullptr;
  NodeTree* del_node = FindNode(node, key);
  NodeTree* parent;
  if (!del_node)
    return node;
  else {
    parent = del_node->parent_;
    bool is_root = (del_node == node);
    bool is_left = ((parent != nullptr) && (del_node == parent->left_));
    // 0 child
    if ((!(del_node->left_)) && (!(del_node->right_))) {
      if (is_root) {
        node = nullptr;
      } else if (is_left) {
        parent->left_ = nullptr;
      } else {
        parent->right_ = nullptr;
      }
      --size_;
      delete del_node;
    }
    // 1 child
    else if (!del_node->left_) {
      if (is_root) {
        node = del_node->right_;
      } else if (is_left) {
        parent->left_ = del_node->right_;
      } else {
        parent->right_ = del_node->right_;
      }
      del_node->right_->parent_ = parent;
      --size_;
      delete del_node;
    } else if (!del_node->right_) {
      if (is_root) {
        node = del_node->left_;
      } else if (is_left) {
        parent->left_ = del_node->left_;
      } else {
        parent->right_ = del_node->left_;
      }
      del_node->left_->parent_ = parent;
      --size_;
      delete del_node;
    } else {
      // 2 childs
      NodeTree* tmp = FindMinNode(del_node->right_);
      NodeTree* min_node = new NodeTree{tmp->data_, parent, del_node->left_,
                                        del_node->right_, del_node->height_};
      min_node->right_ = DeleteMinNode(del_node->right_);
      if (min_node->right_) min_node->right_->parent_ = min_node;

      del_node->left_->parent_ = min_node;
      if (parent) {
        if (parent->left_ == del_node)
          parent->left_ = min_node;
        else
          parent->right_ = min_node;
      } else
        node = min_node;
      delete del_node;
      UpdateHeight(min_node);
    }
  }
  if (!node) return nullptr;
  if (parent) UpdateHeight(parent);
  return parent ? BalanceUntilRoot(parent) : Balance(node);
}

int GetHeight(NodeTree* node) const {
  return node ? node->height_ : 0;
}

int BalanceFactor(NodeTree* node) const {
  return node ? GetHeight(node->right_) - GetHeight(node->left_) : 0;
}

void UpdateHeight(NodeTree* node) {
  const int leftHeight = GetHeight(node->left_);
  const int rightHeight = GetHeight(node->right_);
  if (leftHeight > rightHeight)
    node->height_ = leftHeight + 1;
  else
    node->height_ = rightHeight + 1;
}


NodeTree* RotateLeft(NodeTree* node) {
  NodeTree* tmp_parent = node->parent_;
  NodeTree* tmp = node->right_;
  node->right_ = tmp->left_;
  if (tmp->left_) tmp->left_->parent_ = node;
  tmp->left_ = node;
  node->parent_ = tmp;
  tmp->parent_ = tmp_parent;
  if (tmp_parent) {
    if (tmp_parent->right_ == node)
      tmp_parent->right_ = tmp;
    else
      tmp_parent->left_ = tmp;
  }
  UpdateHeight(node);
  UpdateHeight(tmp);
  return tmp;
}


NodeTree* RotateRight(NodeTree* node) {
  NodeTree* tmp_parent = node->parent_;
  NodeTree* tmp = node->left_;
  node->left_ = tmp->right_;
  if (tmp->right_) tmp->right_->parent_ = node;
  tmp->right_ = node;
  node->parent_ = tmp;
  tmp->parent_ = tmp_parent;
  if (tmp_parent) {
    if (tmp_parent->left_ == node)
      tmp_parent->left_ = tmp;
    else
      tmp_parent->right_ = tmp;
  }
  UpdateHeight(node);
  UpdateHeight(tmp);
  return tmp;
}

NodeTree* Balance(NodeTree* node) {
  UpdateHeight(node);
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right_) < 0) {
      node->right_ = RotateRight(node->right_);
    }
    return RotateLeft(node);
  }
  if (BalanceFactor(node) == -2) {
    if (BalanceFactor(node->left_) > 0) {
      node->left_ = RotateLeft(node->left_);
    }
    return RotateRight(node);
  }
  return node;
}

NodeTree* BalanceUntilRoot(NodeTree* node) {
  NodeTree* parent = node->parent_;
  while (parent) {
    if (parent->parent_) {
      if (parent == parent->parent_->left_)
        parent->parent_->left_ = Balance(parent);
      else
        parent->parent_->right_ = Balance(parent);
      parent = parent->parent_;
    } else
      return Balance(parent);
  }
  return Balance(node);
}

};

// #include "s21_tree.inl"

}  // namespace s21

#endif  // S21_TREE_H_