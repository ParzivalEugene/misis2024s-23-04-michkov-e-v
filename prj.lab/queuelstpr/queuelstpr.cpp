#include "queuelstpr/queuelstpr.hpp"

#include <iostream>
#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& other) {
  Node* current = other.head_;
  while (current) {
    Push(current->val);
    current = current->next;
  }
}

QueueLstPr::QueueLstPr(QueueLstPr&& other) noexcept {
  head_ = other.head_;
  tail_ = other.tail_;
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& other) {
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

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& other) noexcept {
  if (this != &other) {
    Clear();
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept { return head_ == nullptr; }

QueueLstPr::~QueueLstPr() noexcept { Clear(); }

void QueueLstPr::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;
    head_ = head_->next;
    delete deleted;
  }
  if (IsEmpty()) {
    tail_ = nullptr;
  }
}

void QueueLstPr::Push(const float& val) {
  if (IsEmpty()) {
    tail_ = new Node{val};
    head_ = tail_;
  } else {
    Node* current = head_;
    Node* prev = nullptr;
    while (current && current->val < val) {
      prev = current;
      current = current->next;
    }
    if (prev) {
      prev->next = new Node{val, current};
    } else {
      head_ = new Node{val, head_};
    }
  }
}

float& QueueLstPr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstPr - try get top form empty queue.");
  }
  return head_->val;
}

const float& QueueLstPr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstPr - try get top form empty queue.");
  }
  return head_->val;
}

void QueueLstPr::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}

void QueueLstPr::Print() {
  Node* current = head_;
  while (current) {
    std::cout << current->val << " -> ";
    current = current->next;
  }
  std::cout << '\n';
}