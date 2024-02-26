#pragma once
#ifndef STACKARR_H
#define STACKARR_H

#include <complex/complex.hpp>

class StackArr {
 public:
  StackArr();
  StackArr(const StackArr& other);
  StackArr(const Complex& head);
  StackArr& operator=(const StackArr& other);
  ~StackArr();

  void Pop() noexcept;
  void Push(const Complex& value);
  void Clear() noexcept {
    size_ = 0;
    head_ = nullptr;
  };
  bool IsEmpty() const noexcept { return size_ == 0; };
  const Complex& Top() const;
  Complex& Top();

 private:
  Complex* data_ = nullptr;
  Complex* head_ = nullptr;
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
};

#endif