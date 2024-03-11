#pragma once
#ifndef QUEUELSTSPR_HPP
#define QUEUELSTSPR_HPP

#include <cstddef>

class QueueLstPr {
 public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr&);
  QueueLstPr(QueueLstPr&&) noexcept;
  ~QueueLstPr();

  QueueLstPr& operator=(const QueueLstPr&);
  QueueLstPr& operator=(QueueLstPr&&) noexcept;

  bool IsEmpty() const noexcept;
  void Pop() noexcept;
  void Push(const float& val);
  float& Top();
  const float& Top() const;
  void Clear() noexcept;

  void Print();

 private:
  struct Node {
    float val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif