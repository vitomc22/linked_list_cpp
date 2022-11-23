#ifndef STRUCTURES_LINKED_LIST_HPP
#define STRUCTURES_LINKED_LIST_HPP

#include <algorithm>
#include <memory>
#include <utility>

namespace structures {

template <typename T>
class LinkedList {

  struct Node {

    Node(T value, std::unique_ptr<Node> next = nullptr)
        : value{std::move(value)}, next{std::move(next)} {}

    T value;
    std::unique_ptr<Node> next;
    ;
  };

public:
  LinkedList() = default;

  LinkedList(LinkedList const& other){ // construtor de cópia da lista
    for (auto i = other.size() - 1; i >= 0; --i){
        push_front(other.nth(i));
    }
  }

  int size() const { return size_; }

  void push_front(T value) {

    head = std::make_unique<Node>(std::move(value), std::move(head));
    size_++;
  }

  T const& nth(int n) const{

    auto elem = head.get(); //retorna ponteiro cru para visualização do objeto de head

    for (auto i = 0u; i< n; ++i){
        elem = elem->next.get();
    }
    return elem->value;

  }

private:
  std::unique_ptr<Node> head;
  int size_{0};
};

} // namespace structures

#endif
