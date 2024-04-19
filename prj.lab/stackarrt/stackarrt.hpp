#pragma once
#ifndef STACKARRT_H
#define STACKARRT_H

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iosfwd>
#include <stdexcept>

template <class T>
class StackArrT {
 public:
  StackArrT();
  StackArrT(const StackArrT& other);
  StackArrT(const T& head);
  StackArrT(StackArrT&& other) noexcept;
  ~StackArrT();

  StackArrT& operator=(const StackArrT& other);
  StackArrT& operator=(StackArrT&& other) noexcept;

  void Pop() noexcept;
  void Push(const T& value);
  void Clear() noexcept {
    size_ = 0;
    head_ = nullptr;
  };
  bool IsEmpty() const noexcept { return size_ == 0; };
  const T& Top() const;
  T& Top();

 private:
  T* data_ = nullptr;
  T* head_ = nullptr;
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
};

template <class T>
StackArrT<T>::StackArrT() : data_{nullptr}, head_{nullptr}, size_{0}, capacity_{0} {}

template <class T>
StackArrT<T>::StackArrT(const StackArrT<T>& other)
    : data_{new T[other.capacity_]},
      head_{data_ + other.size_ - 1},
      size_{other.size_},
      capacity_{other.capacity_} {
  std::copy(other.data_, other.data_ + other.capacity_, data_);
}

template <class T>
StackArrT<T>::StackArrT(const T& head)
    : data_{new T[1]}, head_{data_}, size_{1}, capacity_{1} {
  *head_ = head;
}

template <class T>
StackArrT<T>::StackArrT(StackArrT<T>&& other) noexcept
    : data_{other.data_},
      head_{other.head_},
      size_{other.size_},
      capacity_{other.capacity_} {
  other.data_ = nullptr;
  other.head_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <class T>
StackArrT<T>::~StackArrT() {
  delete[] data_;
  head_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <class T>
void StackArrT<T>::Pop() noexcept {
  if (this->IsEmpty()) {
    return;
  }
  size_ -= 1;
  head_ -= 1;
  if (head_ == 0) {
    head_ = nullptr;
  }
}

template <class T>
T& StackArrT<T>::Top() {
  if (!this->IsEmpty()) {
    return *head_;
  }
  throw(std::logic_error("Stack is empty! No Top-element!\n"));
}

template <class T>
const T& StackArrT<T>::Top() const {
  if (!IsEmpty()) {
    return *head_;
  }
  throw(std::logic_error("Stack is empty! No Top-element!\n"));
}

template <class T>
void StackArrT<T>::Push(const T& value) {
  if (this->IsEmpty()) {
    if (capacity_ == 0) {
      data_ = new T[1];
    }
    head_ = data_;
    *head_ = value;
    size_ = 1;
    capacity_ = std::max(static_cast<ptrdiff_t>(1), capacity_);
    return;
  }

  if (size_ == capacity_) {
    capacity_ =
        (capacity_ % 2 == 0) ? capacity_ / 2 * 3 : (capacity_ + 1) / 2 * 3;

    T* temp = new T[capacity_];
    std::copy(data_, data_ + size_, temp);

    delete[] data_;
    data_ = temp;
    head_ = data_ + size_;
    size_ += 1;
    *head_ = value;
    return;
  }
  head_ += 1;
  *head_ = value;
  size_ += 1;
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& other) {
  if (this == &other) {
    return *this;
  } else if (capacity_ >= other.capacity_) {
    std::copy(other.data_, other.data_ + other.capacity_, data_);
    size_ = other.size_;
    head_ = data_ + size_ - 1;
  } else {
    T* temp = new T[other.capacity_];
    delete[] data_;
    data_ = temp;
    size_ = other.size_;
    head_ = data_ + size_ - 1;
    std::copy(other.data_, other.data_ + other.capacity_, data_);
    return *this;
  }
  return *this;
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& other) noexcept {
  if (this != &other) {
    delete[] data_;
    data_ = other.data_;
    head_ = other.head_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.data_ = nullptr;
    other.head_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

#endif