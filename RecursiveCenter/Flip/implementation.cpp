#include "header.hpp"

void Flip(Node * n) {
  while(n != nullptr) {
    n->on = !(n->on);
    n = n->next;
  }
}
