#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

#include <ostream>

class DoubleLinkedList {
private:
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

        int getItem() const {
            return item_;
        }

        void setItem(int item) {
            item_ = item;
        }

        Node *getNext() const {
            return next_;
        }

        void setNext(Node *next) {
            next_ = next;
        }

        Node *getPrev() const {
            return prev_;
        }

        void setPrev(Node *prev) {
            prev_ = prev;
        }
    };

    int count_;         // счетчик числа элементов
    Node *head_;        // первый элемент списка
    Node *tail_;        // последний элемент списка

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

    // Конструктор "по умолчанию" - создание пустого списка
    // https://docs.microsoft.com/ru-ru/cpp/cpp/constructors-cpp?view=msvc-160
    DoubleLinkedList();

    // Конструктор "копирования" – создание копии имеющегося списка
    DoubleLinkedList(const DoubleLinkedList &doubleLinkedList);

    DoubleLinkedList(int count, Node *head, Node *tail);


    // количество элементов списка
    int getCount() const { return count_; }

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

    bool operator==(const DoubleLinkedList &rhs) const;

    bool operator!=(const DoubleLinkedList &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list);

    void setCount(int count);

    Node *getHead() const;

    void setHead(Node *head);

    Node *getTail() const;

    void setTail(Node *tail);

//    Copy-and-swap
    DoubleLinkedList& operator=(const DoubleLinkedList &doubleLinkedList) {
        if(this != &doubleLinkedList)
            DoubleLinkedList(doubleLinkedList).swap(*this);
        return *this;
    }

    void swap(DoubleLinkedList &doubleLinkedList) noexcept;

};

#endif

