#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include "complex/complex.hpp"

class QueueArr {
 public:
  QueueArr() = default;
  QueueArr(const QueueArr& other);
  QueueArr(const Complex& head);
  QueueArr& operator=(const QueueArr& other);
  ~QueueArr();

  void Pop() noexcept;
  void Push(const Complex& value);
  void Clear() noexcept {
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    capacity_ = 0;
  };
  bool IsEmpty() const noexcept { return size_ == 0; };
  const Complex& Top() const;
  Complex& Top();
  const Complex& Tail() const;
  Complex& Tail();

  void Print() const;

 private:
  Complex* data_ = nullptr;
  ptrdiff_t head_ = 0;
  ptrdiff_t tail_ = 0;
  ptrdiff_t size_ = 0;  // actual size
  ptrdiff_t capacity_ = 0;  // allocated size
};

#endif