#include "dynarr.hpp"

DynArr::DynArr(const ptrdiff_t size)
    : size_{size}, capacity_{2 * size}, data_{nullptr} {
  data_ = new float[2 * size];
  if (size <= 0) {
    throw std::invalid_argument("Size should be a positive number");
  } else {
    for (float* idx = data_; idx < data_ + capacity_; idx++) {
      *idx = 0;
    }
  }
}

DynArr::DynArr(const DynArr& rhs)
    : data_{nullptr}, size_{rhs.size_}, capacity_{rhs.capacity_} {
  data_ = new float[capacity_];
  std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
}

DynArr::DynArr(std::initializer_list<float> il) {
  size_ = il.size();
  capacity_ = 2 * il.size();
  data_ = new float[capacity_];
  for (auto i = il.begin(); i < il.end(); i++) {
    *(data_ + (i - il.begin())) = *(i);
  }
}

DynArr::~DynArr() {
  delete[] data_;
  data_ = nullptr;
}

float& DynArr::operator[](const ptrdiff_t idx) {
  if (idx < 0)
    throw std::invalid_argument("Index shouldn't be a negative number");
  else if (idx >= size_)
    throw std::out_of_range("Index out of range");
  return *(data_ + idx);
}
const float& DynArr::operator[](const ptrdiff_t idx) const {
  if (idx < 0)
    throw std::invalid_argument("Index shouldn't be a negative number");
  else if (idx >= size_)
    throw std::out_of_range("Index out of range");
  return *(data_ + idx);
}

DynArr& DynArr::operator=(const DynArr& rhs) {
  if (this == &rhs) {
    return *this;
  }
  this->Resize(rhs.size_);
  for (float* i = data_; i < data_ + capacity_; i++)
    *(i) = *(rhs.data_ + (i - data_));
  return *this;
}

void DynArr::Resize(const ptrdiff_t size) {
  if (size <= 0)
    throw std::invalid_argument("Size should be a positive number");
  else if (size < size_) {
    for (float* i = data_; i < data_ + size_; i++) {
      if (i >= data_ + size) *i = 0;
    }
  } else if (size > capacity_) {
    float* temp = new float[2 * size];
    for (float* i = temp; i < temp + 2 * size; i++) {
      if (i - temp < size_)
        *i = *(data_ + (i - temp));
      else
        *i = 0;
    }
    delete[] data_;
    data_ = temp;
    capacity_ = 2 * size;
  }
  size_ = size;
}

std::ostream& operator<<(std::ostream& ostrm, const DynArr& rhs) {
  return rhs.Print(ostrm);
}

std::ostream& DynArr::Print(std::ostream& ostrm) const {
  for (float* i = data_; i < data_ + size_; i++) ostrm << (*i) << ' ';
  ostrm << '\n';
  return ostrm;
}