#include "DoubleLinkedList.h"
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {}


// Конструктор "копирования" – создание копии имеющегося списка
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &src) {
    head_ = tail_ = nullptr;
    count_ = 0;
    Node *temp = src.head_;
    while (temp != 0) {
        insertTail(temp->item_);
        temp = temp->next_;
    }
}


// Ok
// Вставить сформированный узел в хвост списка
void DoubleLinkedList::insertTail(Node *x) {
    x->prev_ = tail_;
    if (tail_ != nullptr) {
        // список был НЕ пуст – новый элемент будет и первым, и последним
        tail_->next_ = x;
    } else {
        // список был пуст – новый элемент будет и первым, и последним
        head_ = x;
    }
    tail_ = x;
    count_++;  // число элементов списка увеличилось
}

// Вставить сформированный узел в начало списка
void DoubleLinkedList::insertHead(Node *x) {   // x->prev_ == nullptr,  x->next_ == nullptr
    x->next_ = head_;
    if (head_ != nullptr) {
        // список был НЕ пуст – новый элемент будет и первым, и последним
        head_->prev_ = x;
    } else {
        // список был пуст – новый элемент будет и первым, и последним
        tail_ = x;
    }
    head_ = x;
    count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла
void DoubleLinkedList::deleteNode(Node *x) {
    if (x == nullptr) {
        throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
    }
    if (x->prev_ != nullptr) {
        // удаляется НЕ голова списка
        (x->prev_)->next_ = x->next_;
    } else {
        // удаляется голова списка,  второй элемент становится первым
        head_ = x->next_;
    }
    if (x->next_ != nullptr) {
        // удаляется НЕ хвост
        (x->next_)->prev_ = x->prev_;
    } else {
        // удаляется хвост
        tail_ = x->prev_;
    }
    delete x;      //
    count_--;     // число элементов списка уменьшилось
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
    x->item_ = item;
    return x;
}

// количество элементов списка
//  int DoubleLinkedList::сount()const{ return count_; }

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
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
}

int &DoubleLinkedList::tailItem() {
    if (tail_ != nullptr) {
        return tail_->item_;
    }
    throw ("tailItem - список пуст!");
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
    }
    deleteNode(head_);
    return 1;      // список был НЕ пуст, удаление головы
}

///https://www.javatpoint.com/program-to-delete-a-new-node-from-the-end-of-the-doubly-linked-list
// Удалить элемент из хвоста списка
bool DoubleLinkedList::deleteTail() {
    if (head_ != NULL) {
        if (head_ != tail_) {
            tail_ = tail_->prev_;
            tail_->next_ = NULL;
        } else {
            head_ = tail_ = NULL;
        }
    } else {
        return 0;
    }
}

bool DoubleLinkedList::deleteItem(const int item) {
    Node *node = searchNode(item);
    if (node != NULL) {
        deleteNode(node);
    } else {
        return false;
    }
    return true;
}

// Поиск записи с заданным значением
bool DoubleLinkedList::searchItem(int item) {   // возвращаем TRUE, если узел найден
    return (searchNode(item) != nullptr);
}

// Замена информации узла на новое
//https://www.cyberforum.ru/cpp-beginners/thread1313910.html
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew) {
    if (itemOld != itemNew) {
        auto oldNode = searchNode(itemOld);
/*        проверил всё  хорошо
 * 6. replaceNode(Node* x, int item) - replace the node value with a new one
 *          replaceNode(oldNode, 2);
 */
        auto newNode = searchNode(itemNew);

        if (oldNode == head_) {
            std::swap(oldNode->prev_, newNode->prev_);
            std::swap(oldNode->next_, newNode->next_);
            oldNode->prev_->next_ = oldNode;
            if (newNode != tail_) {
                std::swap(oldNode->next_->prev_, newNode->next_->prev_);
            } else {
                newNode->next_->prev_ = newNode;
            }
            head_ = newNode;
            tail_ = oldNode;
        } else if (newNode == tail_) {
            std::swap(oldNode->prev_, newNode->prev_);
            std::swap(oldNode->next_, newNode->next_);
            std::swap(oldNode->prev_->next_, newNode->prev_->next_);
            newNode->next_->prev_ = newNode;
            head_ = newNode;
        } else {
            std::swap(oldNode->prev_->next_, newNode->prev_->next_);
            std::swap(oldNode->prev_, newNode->prev_);
            std::swap(oldNode->next_->prev_, newNode->next_->prev_);
            std::swap(oldNode->next_, newNode->next_);

        }
        return true;
    } else {
        return false;
    }

}

// Вывод элементов списка в текстовом виде в стандартный выходной поток
void DoubleLinkedList::outAll() {
    Node *current = head_;       // Указатель на элемент
    while (current != nullptr) {
        std::cout << current->item_ << '\t';
        current = current->next_;  // Переход к следующему элементу
    }
    std::cout << std::endl;
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

std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list) {
    os << "count_: " << list.count_ << " head_: " << list.head_ << " tail_: " << list.tail_;
    return os;
}

bool DoubleLinkedList::operator<(const DoubleLinkedList &rhs) const {
    if (count_ < rhs.count_)
        return true;
    if (rhs.count_ < count_)
        return false;
    if (head_ < rhs.head_)
        return true;
    if (rhs.head_ < head_)
        return false;
    return tail_ < rhs.tail_;
}

bool DoubleLinkedList::operator>(const DoubleLinkedList &rhs) const {
    return rhs < *this;
}

bool DoubleLinkedList::operator<=(const DoubleLinkedList &rhs) const {
    return !(rhs < *this);
}

bool DoubleLinkedList::operator>=(const DoubleLinkedList &rhs) const {
    return !(*this < rhs);
}

bool DoubleLinkedList::operator==(const DoubleLinkedList &rhs) const {
    return count_ == rhs.count_ &&
           head_ == rhs.head_ &&
           tail_ == rhs.tail_;
}

bool DoubleLinkedList::operator!=(const DoubleLinkedList &rhs) const {
    return !(rhs == *this);
}

//void DoubleLinkedList::swap(DoubleLinkedList &rhs) noexcept {
//    Node *me = head_, *other = rhs.head_;
//    while (NULL != me && NULL != other) {
//        std::swap(*me, *other);
//        me = me->next_;
//        other = other->next_;
//    }
//
//}

