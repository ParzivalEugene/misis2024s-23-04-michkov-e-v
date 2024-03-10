#include "queuearr/queuearr.hpp"

#include <algorithm>

QueueArr::QueueArr(const QueueArr& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  head_ = 0;
  tail_ = 0;
  data_ = new Complex[capacity_];
  for (std::size_t i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

QueueArr::QueueArr(const Complex& head) {
  size_ = 1;
  capacity_ = 8;
  head_ = 0;
  tail_ = 0;
  data_ = new Complex[capacity_];
  data_[0] = head;
}

QueueArr::QueueArr(QueueArr&& other) noexcept {
  data_ = other.data_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  head_ = other.head_;
  tail_ = other.tail_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
  other.head_ = 0;
  other.tail_ = 0;
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    capacity_ = std::max(size_, (ptrdiff_t)8);
    head_ = 0;
    tail_ = 0;
    data_ = new Complex[capacity_];
    for (std::size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[(other.head_ + i) % other.capacity_];
    }
  }
  return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& other) noexcept {
  if (this != &other) {
    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    head_ = other.head_;
    tail_ = other.tail_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    other.head_ = 0;
    other.tail_ = 0;
  }
  return *this;
}

QueueArr::~QueueArr() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  head_ = 0;
  tail_ = 0;
}

void QueueArr::Pop() noexcept {
  if (size_ > 0) {
    head_ = (head_ + 1) % capacity_;
    --size_;
  }
}

void QueueArr::Push(const Complex& value) {
  if (size_ == 0) {
    head_ = 0;
    tail_ = 0;
    capacity_ = 8;
    data_ = new Complex[capacity_];
    data_[0] = value;
    ++size_;
    return;
  }
  if (size_ == capacity_) {
    capacity_ *= 2;
    Complex* new_data = new Complex[capacity_];
    for (std::size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[(head_ + i) % capacity_];
    }
    delete[] data_;
    data_ = new_data;
    head_ = 0;
    tail_ = size_;
    data_[tail_] = value;
    ++size_;
    return;
  }
  tail_ = (tail_ + 1) % capacity_;
  data_[tail_] = value;
  ++size_;
}

const Complex& QueueArr::Top() const {
  if (size_ == 0) {
    throw std::out_of_range("QueueArr<Complex>::Top(): empty queue");
  }
  return data_[head_];
}

Complex& QueueArr::Top() {
  if (size_ == 0) {
    throw std::out_of_range("QueueArr<Complex>::Top(): empty queue");
  }
  return data_[head_];
}

const Complex& QueueArr::Tail() const {
  if (size_ == 0) {
    throw std::out_of_range("QueueArr<Complex>::Tail(): empty queue");
  }
  return data_[tail_];
}

Complex& QueueArr::Tail() {
  if (size_ == 0) {
    throw std::out_of_range("QueueArr<Complex>::Tail(): empty queue");
  }
  return data_[tail_];
}

void QueueArr::Print() const {
  std::cout << "QueueArr (size: " << size_ << ", capacity: " << capacity_
            << ", head:" << head_ << ", tail:" << tail_ << ")"
            << ": [";

  for (std::size_t i = 0; i < capacity_; ++i) {
    std::cout << data_[i] << ", ";
  }
  std::cout << "] ---> ";

  for (std::size_t i = 0; i < size_; ++i) {
    std::cout << data_[(head_ + i) % capacity_] << " -> ";
  }
  std::cout << "nullptr" << std::endl;
}