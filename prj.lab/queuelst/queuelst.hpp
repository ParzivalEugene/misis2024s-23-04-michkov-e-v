#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <complex/complex.hpp>
#include <cstddef>

class QueueLst {
 public:
  QueueLst() = default;
  QueueLst(const QueueLst&);
  QueueLst(QueueLst&&) noexcept;
  QueueLst& operator=(const QueueLst&);
  QueueLst& operator=(QueueLst&&) noexcept;
  ~QueueLst();

  bool IsEmpty() const noexcept;
  void Pop() noexcept;
  void Push(const Complex& val);
  Complex& Top();
  const Complex& Top() const;
  void Clear() noexcept;

 private:
  struct Node {
    Complex val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif