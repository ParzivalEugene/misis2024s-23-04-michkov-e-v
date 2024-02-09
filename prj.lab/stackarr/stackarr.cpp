#include <stackarr/stackarr.hpp>

StackArr::StackArr() : data_(), size_(0), capacity_(0) {}
StackArr::StackArr(const StackArr& other)
    : data_(new Complex[other.capacity_]),
      size_(other.size_),
      capacity_(other.capacity_) {
  for (ptrdiff_t i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}
StackArr::~StackArr() { delete[] data_; }
StackArr& StackArr::operator=(const StackArr& other) {
  if (this != &other) {
    delete[] data_;
    data_ = new Complex[other.capacity_];
    size_ = other.size_;
    capacity_ = other.capacity_;
    for (ptrdiff_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  return *this;
}

void StackArr::push(Complex value) {
  if (size_ == capacity_) {
    ptrdiff_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
    Complex* new_data = new Complex[new_capacity];
    for (ptrdiff_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
  data_[size_++] = value;
}

void StackArr::pop() noexcept {
  if (size_ > 0) --size_;
}

bool StackArr::isEmpty() noexcept { return size_ == 0; }

const Complex& StackArr::top() const {
  if (size_ == 0) {
    throw std::out_of_range("Stack is empty");
  }
  return data_[size_ - 1];
}