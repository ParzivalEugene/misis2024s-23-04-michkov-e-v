#include <stackarr/stackarr.hpp>

StackArr::StackArr() : data_(nullptr), size_(0), top_index_(-1) {}

StackArr::StackArr(const StackArr& other) : data_(new Complex[other.size_]), size_(other.size_), top_index_(other.top_index_) {
  for (ptrdiff_t i = 0; i <= top_index_; ++i) {
    data_[i] = other.data_[i];
  }
}

StackArr::~StackArr() {
  delete[] data_;
}

StackArr& StackArr::operator=(const StackArr& other) {
  if (this != &other) {
    delete[] data_;
    data_ = new Complex[other.size_];
    size_ = other.size_;
    top_index_ = other.top_index_;
    for (ptrdiff_t i = 0; i <= top_index_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  return *this;
}

void StackArr::push(Complex& value) {
  if (top_index_ + 1 == size_) {
    ptrdiff_t new_size = size_ == 0 ? 1 : size_ * 2;
    Complex* new_data = new Complex[new_size];
    for (ptrdiff_t i = 0; i <= top_index_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    size_ = new_size;
  }
  data_[++top_index_] = value;
}

void StackArr::pop() noexcept {
  if (top_index_ >= 0) {
    --top_index_;
  }
}

bool StackArr::isEmpty() noexcept {
  return top_index_ == -1;
}

const Complex& StackArr::top() const {
  return data_[top_index_];
}

void StackArr::clear() noexcept {
  top_index_ = -1;
}