#include "stacklst/stacklst.hpp"

StackLst::StackLst() : head_(nullptr) {}

StackLst::StackLst(const StackLst& other) : head_(nullptr) {
  Node* current = other.head_;
  while (current) {
    push(current->data);
    current = current->next;
  }
}

StackLst::~StackLst() {
  clear();
}

StackLst& StackLst::operator=(const StackLst& other) {
  if (this != &other) {
    clear();
    Node* current = other.head_;
    while (current) {
      push(current->data);
      current = current->next;
    }
  }
  return *this;
}

void StackLst::push(Complex& value) {
  Node* new_node = new Node{value, head_};
  head_ = new_node;
}

void StackLst::pop() noexcept {
  if (head_) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

bool StackLst::isEmpty() noexcept {
  return head_ == nullptr;
}

const Complex& StackLst::top() const {
  if (!head_) {
    throw std::out_of_range("Stack is empty");
  }
  return head_->data;
}

void StackLst::clear() noexcept {
  while (head_) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}
