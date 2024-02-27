#include "queuearr/queuearr.hpp"

QueueArr::QueueArr(const QueueArr& other) {
  for (std::size_t i = 0; i < other.size_; ++i) {
    data_[i] = other.data_[i];
  }
  size_ = other.size_;
  capacity_ = other.capacity_;
  head_ = other.head_;
  tail_ = other.tail_;
}

QueueArr::QueueArr(const Complex& head)
    : data_{new Complex[16]},
      head_{data_},
      tail_{data_},
      size_{8},
      capacity_{16} {
  *head_ = head;
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
  if (this == &other) {
    return *this;
  }
  delete[] data_;
  data_ = new Complex[other.size_];
  for (std::size_t i = 0; i < other.size_; ++i) {
    data_[i] = other.data_[i];
  }
  size_ = other.size_;
  capacity_ = other.capacity_;
  head_ = other.head_;
  tail_ = other.tail_;
  return *this;
}

QueueArr::~QueueArr() { delete[] data_; }

void QueueArr::Pop() noexcept {
  if (size_ == 0) {
    return;
  }
  if (size_ == 1) {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
    return;
  }
  if (size_ * 2 <= capacity_) {
    Complex* new_data = new Complex[capacity_ / 2];
    for (std::size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    head_ = data_;
    tail_ = &data_[size_];
    capacity_ /= 2;
  }
  head_ = &data_[1];
  --size_;
}

void QueueArr::Push(const Complex& value) {
  if (size_ == 0) {
    data_ = new Complex[8];
    head_ = data_;
    tail_ = data_;
    *head_ = value;
    *tail_ = value;
    ++tail_;
    size_ = 8;
    capacity_ = 16;
    return;
  }
  if (size_ == capacity_) {
    Complex* new_data = new Complex[capacity_ * 2];
    for (std::size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    head_ = data_;
    tail_ = &data_[size_];
    capacity_ *= 2;
  }
  *tail_ = value;
  ++tail_;
  ++size_;
}

const Complex& QueueArr::Top() const {
  if (size_ == 0) {
    throw std::out_of_range("Queue is empty");
  }
  return *head_;
}

Complex& QueueArr::Top() {
  if (size_ == 0) {
    throw std::out_of_range("Queue is empty");
  }
  return *head_;
}

const Complex& QueueArr::Tail() const {
  if (size_ == 0) {
    throw std::out_of_range("Queue is empty");
  }
  return *(tail_ - 1);
}

Complex& QueueArr::Tail() {
  if (size_ == 0) {
    throw std::out_of_range("Queue is empty");
  }
  return *(tail_ - 1);
}

void QueueArr::Print() const {
  std::cout << "QueueArr (size: " << size_ << ", head:" << *head_
            << ", tail:" << *(tail_ - 1) << ")"
            << ": [";
  for (std::size_t i = 0; i < size_; ++i) {
    std::cout << data_[i] << ", ";
  }
  std::cout << "]\n";
}