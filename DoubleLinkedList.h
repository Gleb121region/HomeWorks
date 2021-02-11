#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

#include <ostream>
#include <iostream>

//  DoubleLinkedList.h - Дважды связный список целых чисел
//
class DoubleLinkedList {
private:
    // Тип  Node используется для описания элемента списка, связанного со
    // следующим с помощью поля next_ и предшествующим с помощью поле prev_
    struct Node         // может использоваться  только в классе DoubleLinkedList
    {
        int item_;        // значение элемента списка
        Node *next_;      // указатель на следующий элемент списка
        Node *prev_;      // указатель на предшествующий элемент списка

        // Конструктор для создания нового элемента списка.
        Node(int item, Node *next = nullptr, Node *prev = nullptr) : item_(item), next_(next), prev_(prev) {}
    };

    int count_{};         // счетчик числа элементов
    Node *head_{};        // первый элемент списка
    Node *tail_{};        // последний элемент списка

    // Доступ к головному узлу списка
    Node *head() const { return head_; }

    // Доступ к хвостовому узлу списка
    Node *tail() const { return tail_; }

    // Всавить сформированный узел в хвост списка
    void insertTail(Node *x);

    // Вставить сформированный узел в начало списка
    void insertHead(Node *x); // (int item);

    // Удаление заданного узла
    void deleteNode(Node *x);

    // Поиск узла (адрес) с заданным значением
    Node *searchNode(int item);

    // Замена информации узла на новое
    Node *replaceNode(Node *x, int item);

public:
    //https://stackoverflow.com/questions/18779543/constructor-for-a-linked-DoubleLinkedList
    // Конструктор "по умолчанию" - создание пустого списка
    DoubleLinkedList() : count_(0), head_(0), tail_(0) {
    }

    //https://wiki.dieg.info/dvusvjaznyj_spisok
    // Конструктор "копирования" – создание копии имеющегося списка
    DoubleLinkedList(const DoubleLinkedList &k);

    //https://stackoverflow.com/questions/51314325/assignment-operator-for-doubly-linked-list-c
    //2. Copy-and-SWAP ...
    DoubleLinkedList &operator=(DoubleLinkedList &rhs) {
        std::swap(head_, rhs.head_);
        std::swap(tail_, rhs.tail_);
        return *this;
    }

    //https://www.cyberforum.ru/cpp-beginners/thread1966885.html
    //3. Конструктор перемещения
    DoubleLinkedList(DoubleLinkedList &&other)
    noexcept: count_(other.count_), head_(other.head_), tail_(other.tail_) {
        other.count_ = 0;
        other.head_ = nullptr;
        other.tail_ = nullptr;
    }

    //https://ravesli.com/urok-191-konstruktor-peremeshheniya-i-operator-prisvaivaniya-peremeshheniem/#toc-1
    //4. Оператор перемещающего присваивания
    DoubleLinkedList &operator=(DoubleLinkedList &&x) {
        if (&x == this)
            return *this;
        delete head_;
        delete tail_;
        head_ = x.head_;
        x.head_ = nullptr;
        tail_ = x.tail_;
        x.tail_ = nullptr;
        return *this;
    }

    // количество элементов списка
    int сount() const { return count_; }

    // Доступ к информации головного узла списка
    int headItem() const;

    int &headItem();

    // Доступ к информации хвостового узла списка
    int tailItem() const;

    int &tailItem();

    // Вставить элемент в голову списка
    void insertHead(int item);

    // Вставить элемент в хвост списка
    void insertTail(int item);

    // Удалить элемент с головы списка
    bool deleteHead();

    // Удалить элемент из хвоста списка
    bool deleteTail();

    // Удаление узла с заданным значением
    bool deleteItem(const int item);

    // Поиск записи с заданным значением
    bool searchItem(int item);

    // Замена информации узла на новое
    bool replaceItem(int itemOld, int itemNew);

    // Вывод элементов списка в текстовом виде в стандартный выходной поток
    void outAll();

    // Деструктор списка
    virtual ~DoubleLinkedList();

    friend std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &DoubleLinkedList);

    bool operator<(const DoubleLinkedList &rhs) const;

    bool operator>(const DoubleLinkedList &rhs) const;

    bool operator<=(const DoubleLinkedList &rhs) const;

    bool operator>=(const DoubleLinkedList &rhs) const;

    bool operator==(const DoubleLinkedList &rhs) const;

    bool operator!=(const DoubleLinkedList &rhs) const;

    void addT(DoubleLinkedList src) {
            int size = src.count_;
            for (int i = 0; i < size; i++) {
                this->insertTail(src.head_->item_);
                src.deleteHead();
            }
    }

//    DoubleLinkedList &operator=(const DoubleLinkedList &doubleLinkedList) {
//        if (this != &doubleLinkedList)
//            DoubleLinkedList(doubleLinkedList).swap(*this);
//        return *this;
//    }
//    void swap(DoubleLinkedList &rhs) noexcept;



};

#endif

