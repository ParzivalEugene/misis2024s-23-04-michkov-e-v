#include "bitset.hpp"

BitSet::BitSet(const int32_t size) : size_(size) {
  data_ = new bool[size_];
  Fill(false);
}

BitSet::BitSet(const BitSet& rhs) noexcept {
  size_ = rhs.size_;
  data_ = new bool[size_];
  for (int32_t i = 0; i < size_; ++i) {
    data_[i] = rhs.data_[i];
  }
}

BitSet::BitSet(BitSet&& rhs) noexcept {
  size_ = rhs.size_;
  data_ = rhs.data_;
  rhs.size_ = 0;
  rhs.data_ = nullptr;
}

BitSet& BitSet::operator=(const BitSet& rhs) noexcept {
  if (this != &rhs) {
    delete[] data_;
    size_ = rhs.size_;
    data_ = new bool[size_];
    for (int32_t i = 0; i < size_; ++i) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}

BitSet& BitSet::operator=(BitSet&& rhs) noexcept {
  if (this != &rhs) {
    delete[] data_;
    size_ = rhs.size_;
    data_ = rhs.data_;
    rhs.size_ = 0;
    rhs.data_ = nullptr;
  }
  return *this;
}

bool BitSet::operator==(const BitSet& rhs) const noexcept {
  if (size_ != rhs.size_) {
    return false;
  }

  for (int32_t i = 0; i < size_; ++i) {
    if (data_[i] != rhs.data_[i]) {
      return false;
    }
  }
  return true;
}

bool BitSet::operator!=(const BitSet& rhs) const noexcept {
  return !(*this == rhs);
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
  if (size_ != rhs.size_) {
    throw std::invalid_argument("BitSet::operator&=: different sizes");
  }

  for (int32_t i = 0; i < size_; ++i) {
    data_[i] &= rhs.data_[i];
  }
  return *this;
}

BitSet& BitSet::operator|=(const BitSet& rhs) {
  if (size_ != rhs.size_) {
    throw std::invalid_argument("BitSet::operator&=: different sizes");
  }

  for (int32_t i = 0; i < size_; ++i) {
    data_[i] |= rhs.data_[i];
  }
  return *this;
}

BitSet& BitSet::operator^=(const BitSet& rhs) {
  if (size_ != rhs.size_) {
    throw std::invalid_argument("BitSet::operator&=: different sizes");
  }

  for (int32_t i = 0; i < size_; ++i) {
    data_[i] ^= rhs.data_[i];
  }
  return *this;
}

BitSet BitSet::operator~() {
  BitSet result(size_);
  for (int32_t i = 0; i < size_; ++i) {
    result.Set(i, !data_[i]);
  }
  return result;
}

void BitSet::Resize(const int32_t size) {
  if (size <= 0) {
    throw std::invalid_argument("BitSet::Resize: size <= 0");
  }

  bool* new_data = new bool[size];
  for (int32_t i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }
  if (size_ < size) {
    for (int32_t i = size_; i < size; ++i) {
      new_data[i] = false;
    }
  }

  delete[] data_;
  data_ = new_data;
  size_ = size;
}

bool BitSet::Get(const int32_t idx) const {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("BitSet::Get: out of range");
  }
  return data_[idx];
}

void BitSet::Set(const int32_t idx, const bool val) {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("BitSet::Set: out of range");
  }
  data_[idx] = val;
}

void BitSet::Fill(const bool val) noexcept {
  for (int32_t i = 0; i < size_; ++i) {
    data_[i] = val;
  }
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::invalid_argument("operator&: different sizes");
  }

  BitSet result(lhs.Size());
  for (int32_t i = 0; i < lhs.Size(); ++i) {
    result.Set(i, lhs.Get(i) & rhs.Get(i));
  }
  return result;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::invalid_argument("operator|: different sizes");
  }

  BitSet result(lhs.Size());
  for (int32_t i = 0; i < lhs.Size(); ++i) {
    result.Set(i, lhs.Get(i) | rhs.Get(i));
  }
  return result;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::invalid_argument("operator^: different sizes");
  }

  BitSet result(lhs.Size());
  for (int32_t i = 0; i < lhs.Size(); ++i) {
    result.Set(i, lhs.Get(i) ^ rhs.Get(i));
  }
  return result;
}

int32_t BitSet::operator[](const int32_t idx) { return Get(idx); }

std::ostream& BitSet::WriteTxt(std::ostream& os) {
  for (int32_t i = 0; i < size_; ++i) {
    os << data_[i];
  }
  return os;
}

std::ostream& BitSet::WriteBinary(std::ostream& os) {
  for (int32_t i = 0; i < size_; ++i) {
    os.write(reinterpret_cast<char*>(&data_[i]), sizeof(data_[i]));
  }
  return os;
}

std::istream& BitSet::ReadTxt(std::istream& is) {
  std::string str;
  is >> str;
  size_ = str.size();
  data_ = new bool[size_];
  for (int32_t i = 0; i < size_; ++i) {
    data_[i] = str[i] - '0';
  }
  return is;
}

std::istream& BitSet::ReadBinary(std::istream& is) {
  is.read(reinterpret_cast<char*>(data_), sizeof(data_));
  return is;
}

std::ostream& operator<<(std::ostream& os, const BitSet& bs) {
  for (int32_t i = 0; i < bs.Size(); ++i) {
    os << bs.Get(i);
  }
  return os;
}

std::istream& operator>>(std::istream& is, BitSet& bs) {
  std::string str;
  is >> str;
  bs.Resize(str.size());
  for (int32_t i = 0; i < bs.Size(); ++i) {
    bs.Set(i, str[i] - '0');
  }
  return is;
}

// custom methods

BitSet::BitSet(const std::string& str) : size_(str.size()) {
  data_ = new bool[size_];
  for (int32_t i = 0; i < size_; ++i) {
    data_[i] = str[i] - '0';
  }
}

std::string BitSet::toString() const {
  std::string str;
  for (int32_t i = 0; i < size_; ++i) {
    str += data_[i] ? '1' : '0';
  }
  return str;
}