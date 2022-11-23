#include "linked_list.hpp"
#include <iostream>
#include <memory>

int main() {

  auto l = structures::LinkedList<int>{}; //argumento de template int

  l.push_front(3);
  l.push_front(2);
  l.push_front(1);

  for (auto i = 0u; i < l.size(); ++i) {
    std::cout << l.nth(i) << '\n';
  }

  auto l2 = l;
  for (auto i = 0u; i < l2.size(); ++i) {
    std::cout << l2.nth(i) << '\n';
  }

  auto ls = structures::LinkedList<std::string>{}; //argumento de template string
  ls.push_front("victor");
  ls.push_front("maria");
  ls.push_front("joão");

    for (auto i = 0u; i < ls.size(); ++i) {
    std::cout << ls.nth(i) << '\n';
  }

  auto li = structures::LinkedList<std::unique_ptr<int>>{};  // lista de ponteiros pra testar o std::move

  li.push_front(std::make_unique<int>(3));
  li.push_front(std::make_unique<int>(2));
  li.push_front(std::make_unique<int>(1));

  for (auto i = 0u; i < li.size(); ++i) {
    std::cout << *(li.nth(i)) << '\n'; // desreferenciando ponteiro com *() para pegar somente o valor do ponteiro que é int
  }

}
