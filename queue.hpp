#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  int data;
  int priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  T head;
  T tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  q.head = nullptr;
  q.tail = nullptr;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  value->priority = priority;
 T pRev = nullptr;
 T pHelp = q.head;
 if(isEmpty(q)){
   q.head = value;
   q.tail = value;
 }
 else{
   while(value->priority >= pHelp->priority){
     if(pHelp->next == nullptr)
     break;
     pRev = pHelp;
     pHelp = pHelp->next;
   }
   if(pHelp == q.head && value->priority < pHelp->priority){
     value->next = pHelp;
     q.head = value;
   } 
   else if(pHelp == q.tail && value->priority > pHelp->priority){
     pHelp->next = value;
     q.tail = value;
   }
   else {
     pRev->next = value;
     value->next = pHelp;
   }
 }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  T pDel;
  if(queue(T) = 0){
    pDel = nullptr;
  } else if(q.head == nullptr){
    pDel = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else {
    pDel = q.head;
    q.head = q.head->next;
    pDel->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
