#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

void Stack::push(char c) {
    Node* new_top = new Node(c);
    new_top->down = top_;
    top_ = new_top;
}

char Stack::top() { 
    return top_->letter; 
}

void Stack::pop() {
    Node* new_top = top_->down;
    delete top_;
    top_ = new_top;
}

bool Stack::isEmpty() {
    return top_ == nullptr;
}
  
void Stack::clear() {
    while(!isEmpty()) {
        pop();
    }
}

std::ostream & operator<<(std::ostream & os, Stack const & s) {
    for (Node const * ptr = s.top_; ptr != nullptr; ptr = ptr->down) {
        os << ptr->letter << ',';
    }
    return os;
}

Stack::~Stack() {
    clear();
}

Stack & Stack::operator=(Stack other) {
    std::swap(top_, other.top_);
    return *this;
}

Stack::Stack(Stack const & other) {
    std::vector<char> letters;
    for (Node const * ptr = other.top_; ptr != nullptr; ptr = ptr->down) {
        letters.push_back(ptr->letter);
    }
    for (std::vector<char>::reverse_iterator it = letters.rbegin();
        it != letters.rend();
        ++it) {
        push(*it);
    }
}
