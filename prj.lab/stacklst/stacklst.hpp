#pragma once
#ifndef STACKLST_H
#define STACKLST_H

#include <complex/complex.hpp>

class StackLst {
 public:
  StackLst() = default;
  StackLst(const StackLst& other);
  StackLst(const Complex& head);
  StackLst(StackLst&& other) noexcept;
  ~StackLst();

  StackLst& operator=(const StackLst& other);
  StackLst& operator=(StackLst&& other) noexcept;

  void Pop() noexcept;
  void Push(const Complex& value);
  Complex& Top();
  const Complex& Top() const;
  bool IsEmpty() const noexcept;
  void Clear() noexcept;

 private:
  struct Node {
    Complex data;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
};

#endif