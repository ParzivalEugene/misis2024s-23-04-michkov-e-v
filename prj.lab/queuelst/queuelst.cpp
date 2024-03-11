#include "queuelst/queuelst.hpp"

#include <stdexcept>

QueueLst::QueueLst(const QueueLst& other) {
  Node* current = other.head_;
  while (current) {
    Push(current->val);
    current = current->next;
  }
}

QueueLst::QueueLst(QueueLst&& other) noexcept {
  head_ = other.head_;
  tail_ = other.tail_;
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

QueueLst& QueueLst::operator=(const QueueLst& other) {
  if (this != &other) {
    Clear();
    Node* current = other.head_;
    while (current) {
      Push(current->val);
      current = current->next;
    }
  }
  return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& other) noexcept {
  if (this != &other) {
    Clear();
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
  return *this;
}

bool QueueLst::IsEmpty() const noexcept { return nullptr == head_; }

QueueLst::~QueueLst() noexcept { Clear(); }

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;
    head_ = head_->next;
    delete deleted;
  }
  if (IsEmpty()) {
    tail_ = nullptr;
  }
}

void QueueLst::Push(const Complex& val) {
  if (IsEmpty()) {
    tail_ = new Node{val};
    head_ = tail_;
  } else {
    tail_->next = new Node{val};
    tail_ = tail_->next;
  }
}

Complex& QueueLst::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

const Complex& QueueLst::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}