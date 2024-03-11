#include <stackarr/stackarr.hpp>

StackArr::StackArr() : data_{nullptr}, head_{nullptr}, size_{0}, capacity_{0} {}

StackArr::StackArr(const StackArr& other)
    : data_{new Complex[other.capacity_]},
      head_{data_ + other.size_ - 1},
      size_{other.size_},
      capacity_{other.capacity_} {
  std::copy(other.data_, other.data_ + other.capacity_, data_);
}

StackArr::StackArr(const Complex& head)
    : data_{new Complex[1]}, head_{data_}, size_{1}, capacity_{1} {
  *head_ = head;
}

StackArr::StackArr(StackArr&& other) noexcept
    : data_{other.data_},
      head_{other.head_},
      size_{other.size_},
      capacity_{other.capacity_} {
  other.data_ = nullptr;
  other.head_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

StackArr::~StackArr() {
  delete[] data_;
  head_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

void StackArr::Pop() noexcept {
  if (this->IsEmpty()) {
    return;
  }
  size_ -= 1;
  head_ -= 1;
  if (head_ == 0) {
    head_ = nullptr;
  }
}

Complex& StackArr::Top() {
  if (!this->IsEmpty()) {
    return *head_;
  }
  throw(std::logic_error("Stack is empty! No Top-element!\n"));
}

const Complex& StackArr::Top() const {
  if (!IsEmpty()) {
    return *head_;
  }
  throw(std::logic_error("Stack is empty! No Top-element!\n"));
}

void StackArr::Push(const Complex& value) {
  if (this->IsEmpty()) {
    if (capacity_ == 0) {
      data_ = new Complex[1];
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

    Complex* temp = new Complex[capacity_];
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

StackArr& StackArr::operator=(const StackArr& other) {
  if (this == &other) {
    return *this;
  } else if (capacity_ >= other.capacity_) {
    std::copy(other.data_, other.data_ + other.capacity_, data_);
    size_ = other.size_;
    head_ = data_ + size_ - 1;
  } else {
    Complex* temp = new Complex[other.capacity_];
    delete[] data_;
    data_ = temp;
    size_ = other.size_;
    head_ = data_ + size_ - 1;
    std::copy(other.data_, other.data_ + other.capacity_, data_);
    return *this;
  }
  return *this;
}

StackArr& StackArr::operator=(StackArr&& other) noexcept {
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