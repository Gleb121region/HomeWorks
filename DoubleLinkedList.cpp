#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
DoubleLinkedList::DoubleLinkedList() {
    head_ = tail_ = NULL;
    count_ = 0;
}

DoubleLinkedList::DoubleLinkedList(int count, DoubleLinkedList::Node *head, DoubleLinkedList::Node *tail) : count_(
        count), head_(head), tail_(tail) {}

// Конструктор "копирования" – создание копии имеющегося списка
// https://wiki.dieg.info/dvusvjaznyj_spisok !!!!!
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &doubleLinkedList) {
    head_ = tail_ = NULL;
    count_ = 0;
    DoubleLinkedList doubleLinkedList1;
    Node *temp = doubleLinkedList.head_;
    while (temp != nullptr) {
        insertTail(temp->item_);
        temp = temp->next_;
    }
}


// Вставить сформированный узел в хвост списка
void DoubleLinkedList::insertTail(Node *x) {
    x->prev_ = tail_;
    if (tail_ != nullptr) {
        tail_->next_;
    } else {
        head_ = x;
    }
    tail_ = x;
    count_++;
}

// Вставить сформированный узел в начало списка
void DoubleLinkedList::insertHead(Node *x) {
    x->next_ = head_;
    if (head_ != nullptr) {
        head_->prev_;
    } else {
        tail_ = x;
    }
    head_ = x;
    count_++;
}

// Удаление заданного узла
void DoubleLinkedList::deleteNode(Node *x) {
    if (x != nullptr) {
        x->prev_ != nullptr ? (x->prev_)->next_ : head_ = x->next_;
        x->next_ != nullptr ? (x->next_)->prev_ : tail_ = x->prev_;
        delete x;
        count_--;
    } else {
        throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
    }
}

// Поиск узла (адрес) с заданным значением
DoubleLinkedList::Node *DoubleLinkedList::searchNode(int item) {
    Node *x = head_;
    while (x != nullptr && x->item_ != item) {
        x = x->next_;
    }
    return x;
}

// Замена информации узла на новое
DoubleLinkedList::Node *DoubleLinkedList::replaceNode(DoubleLinkedList::Node *x, int item) {
    // !!!                                      !!!
    // !!! Здесь долна быть реализация метода   !!!
    // !!!                                      !!!
    return x; // !!!!!
}

// количество элементов списка
//  int DoubleLinkedList::getCount()const{ return count_; }

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const {
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

int &DoubleLinkedList::headItem() {
    if (head_ != nullptr) {
        return head_->item_;
    }
    throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const {
    if (tail_ == nullptr) throw ("tailItem - список пуст!");
    return tail_->item_;
}

int &DoubleLinkedList::tailItem() {
    if (tail_ == nullptr) throw ("tailItem - список пуст!");
    return tail_->item_;
}

// Вставить элемент в голову списка
void DoubleLinkedList::insertHead(int item) {   // создаем новый элемент списка и добавляем в голову
    insertHead(new Node(item));
}


// Вставить элемент в хвост списка
void DoubleLinkedList::insertTail(int item) {   // создаем новый элемент списка и добавляем в хвост
    insertTail(new Node(item));
}

// Удалить элемент с головы списка
bool DoubleLinkedList::deleteHead() {
    if (head_ == nullptr) {
        return 0;  // список пуст, удалений нет
    } else {
        deleteNode(head_);
        return 1;      // список был НЕ пуст, удаление головы
    }
}

// Удалить элемент из хвоста списка
bool DoubleLinkedList::deleteTail() {
    // !!!                                      !!!
    // !!! Здесь долна быть реализация метода   !!!
    // !!!                                      !!!
    return 0; // !!! удалить после реализации метода  !!!
}

// Удаление узла с заданным значением
bool DoubleLinkedList::deleteItem(const int item) {
    // !!!                                      !!!
    // !!! Здесь долна быть реализация метода   !!!
    // !!!                                      !!!
    return 0; // !!! удалить после реализации метода  !!!
}

// Поиск записи с заданным значением
bool DoubleLinkedList::searchItem(int item) {   // возвращаем TRUE, если узел найден
    return (searchNode(item) != nullptr);
}


// Замена информации узла на новое
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew) {
    // !!!                                      !!!
    // !!! Здесь долна быть реализация метода   !!!
    // !!!                                      !!!
    return 0; // !!! удалить после реализации метода  !!!
}

// Вывод элементов списка в текстовом виде в стандартный выходной поток
void DoubleLinkedList::outAll() {
    Node *current = head_;       // Указатель на элемент
    while (current != nullptr) {
        cout << current->item_ << ' ';
        current = current->next_;  // Переход к следующему элементу
    }
    cout << endl;
}

// Деструктор списка
DoubleLinkedList::~DoubleLinkedList() {
    Node *current = nullptr;   // указатель на элемент, подлежащий удалению
    Node *next = head_;        // указатель на следующий элемент
    while (next != nullptr) {  // пока есть еще элементы в списке
        current = next;
        next = next->next_;    // переход к следующему элементу
        delete current;        // освобождение памяти
    }
}

bool DoubleLinkedList::operator==(const DoubleLinkedList &rhs) const {
    return count_ == rhs.count_ &&
           head_ == rhs.head_ &&
           tail_ == rhs.tail_;
}

bool DoubleLinkedList::operator!=(const DoubleLinkedList &rhs) const {
    return !(rhs == *this);
}

ostream &operator<<(ostream &os, const DoubleLinkedList &list) {
    os << "count_: " << list.count_ << " head_: " << list.head_ << " tail_: " << list.tail_;
    return os;
}

void DoubleLinkedList::setCount(int count) {
    count_ = count;
}

DoubleLinkedList::Node *DoubleLinkedList::getHead() const {
    return head_;
}

void DoubleLinkedList::setHead(DoubleLinkedList::Node *head) {
    head_ = head;
}

DoubleLinkedList::Node *DoubleLinkedList::getTail() const {
    return tail_;
}

void DoubleLinkedList::setTail(DoubleLinkedList::Node *tail) {
    tail_ = tail;
}
