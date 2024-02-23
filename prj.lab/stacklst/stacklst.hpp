#pragma once
#ifndef STACKLST_H
#define STACKLST_H

#include <complex/complex.hpp>

class StackLst {
 public:
  StackLst();
  StackLst(const StackLst& other);
  ~StackLst();
  StackLst& operator=(const StackLst& other);

  void push(Complex& value);
  void pop() noexcept;
  bool isEmpty() noexcept;
  const Complex& top() const;
  void clear() noexcept;

 private:
  struct Node {
    Complex data;
    Node* next = nullptr;
  };

  Node* head_{nullptr};
};

#endif