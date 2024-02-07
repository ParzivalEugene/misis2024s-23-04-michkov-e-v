#include "dynarr.hpp"

#include <algorithm>
#include <stdexcept>

DynArr::DynArr(const ptrdiff_t size)
    : size_(size), capacity_(size), data_(new float[size]) {}

ptrdiff_t DynArr::Size() const noexcept { return size_; }

void DynArr::Resize(const ptrdiff_t size) {
  if (size > capacity_) {
    float* new_data = new float[size];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
  }
  size_ = size;
}

float& DynArr::operator[](const ptrdiff_t idx) {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[idx];
}

const float& DynArr::operator[](const ptrdiff_t idx) const {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[idx];
}
