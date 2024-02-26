#include <stacklst/stacklst.hpp>

bool StackLst::IsEmpty() const noexcept { return head_ == nullptr; }

const Complex& StackLst::Top() const {
  if (!IsEmpty()) {
    return head_->data;
  }
  throw(std::logic_error("The stack is currently empty!"));
}

Complex& StackLst::Top() {
  if (!IsEmpty()) {
    return head_->data;
  }
  throw(std::logic_error("The stack is currently empty!"));
}

void StackLst::Push(const Complex& value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = head_;
  head_ = new_node;
}

void StackLst::Pop() noexcept {
  if (IsEmpty()) return;

  Node* temp_node = head_;
  head_ = temp_node->next;
  delete temp_node;
}

StackLst::StackLst(const Complex& other) : head_{new Node} {
  head_->data = other;
}

StackLst::StackLst(const StackLst& other) : head_{nullptr} {
  if (!other.IsEmpty()) {
    head_ = new Node;
    head_->data = other.head_->data;
    Node* temp = other.head_;
    Node* prev = head_;
    while (temp->next != nullptr) {
      temp = temp->next;
      Node* curr = new Node;
      prev->next = curr;
      curr->data = temp->data;
      prev = curr;
    }
  }
}

StackLst& StackLst::operator=(const StackLst& other) {
  Node* curr = head_;
  Node* curr_other = other.head_;
  while (curr_other != nullptr) {
    if (curr->next == nullptr) {
      curr->next = new Node;
    }
    curr->data = curr_other->data;

    curr = curr->next;
    curr_other = curr_other->next;
  }
  if (curr_other == nullptr && curr != nullptr) {
    while (curr->next != nullptr) {
      Node* temp = curr->next;
      delete curr;
      curr = temp;
    }
    head_->next = nullptr;
  }
  return *this;
}

StackLst::~StackLst() {
  while (head_ != nullptr) {
    Node* temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

void StackLst::Clear() noexcept {
  while (head_ != nullptr) {
    Node* temp = head_->next;
    delete head_;
    head_ = temp;
  }
}