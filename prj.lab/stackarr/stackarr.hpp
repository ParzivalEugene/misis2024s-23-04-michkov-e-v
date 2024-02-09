#pragma once
#ifndef STACKARR_H
#define STACKARR_H

#include <complex/complex.hpp>

class StackArr {
 public:
  StackArr();
  StackArr(const StackArr& other);
  ~StackArr();
  StackArr& operator=(const StackArr& other);

  void push(Complex value);
  void pop() noexcept;
  bool isEmpty() noexcept;
  const Complex& top() const;

 private:
  Complex* data_;
  ptrdiff_t size_;
  ptrdiff_t capacity_;
};

#endif