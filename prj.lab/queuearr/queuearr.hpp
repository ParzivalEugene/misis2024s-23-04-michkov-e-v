#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include "complex/complex.hpp"

class QueueArr {
 public:
  QueueArr();
  QueueArr(const QueueArr& other);
  QueueArr(const Complex& head);
  QueueArr& operator=(const QueueArr& other);
  ~QueueArr();

  void Pop() noexcept;
  void Push(const Complex& value);
  void Clear() noexcept {
    size_ = 0;
    head_ = nullptr;
  };
  bool IsEmpty() const noexcept { return size_ == 0; };
  const Complex& Top() const;
  Complex& Top();
  const Complex& Tail() const;
  Complex& Tail();

 private:
  Complex* data_ = nullptr;
  Complex* head_ = nullptr;
  Complex* tail_ = nullptr;
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
};

#endif