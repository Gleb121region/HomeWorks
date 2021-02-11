#include "DoubleLinkedList.h"
#include <iostream>

int main() {
    std::cout << "start:";
    std::cout << "\n1.Copy constructor:\n";

    std::cout << "Create  new Object";
    DoubleLinkedList list;   // Создание пустого списка
    list.insertHead(2);      // Добавление элементов
    list.insertHead(3);
    list.insertHead(1);
    list.insertTail(1);

    DoubleLinkedList doubleLinkedList = {list};
    doubleLinkedList.outAll();

//    // https://ru.wikipedia.org/wiki/Copy-and-swap
    DoubleLinkedList testlist2;
    testlist2.insertTail(1);
    testlist2.insertTail(2);
    testlist2.insertTail(3);
    testlist2.insertTail(4);
    DoubleLinkedList testList1;
    testList1.insertTail(8);
    testList1.insertTail(7);
    testList1.insertTail(6);
    testList1.insertTail(5);
    std::cout << "testList1  was ->";
    testList1.outAll();
    std::cout << "testlist2  was ->";
    testlist2.outAll();

    std::cout << "\n2.Copy-and-swap:\n";
    testList1 = testlist2;
    std::cout << "testList1  now ->";
    testList1.outAll();
    std::cout << "testlist2  now ->";
    testlist2.outAll();

    std::cout << "\n5. insertTail(Node* x) - inserts the generated node into the tail of the list:\n";
    DoubleLinkedList test;
    test.insertTail(1);
    test.insertTail(12);
    test.insertTail(32);
    test.insertTail(44);
    test.insertTail(88);
    test.insertTail(11);
    test.outAll();

    std::cout << "\n6. replaceNode(Node* x, int item) - replace the node value with a new one:\n";

    std::cout << "\n7. deleteTail() - removes a node from the tail of the list:\n";
    std::cout << "Was:";
    test.outAll();
    std::cout << "Now:";
    test.deleteTail();
    test.outAll();
    std::cout
            << "\n8. DeleteItem(const int item, bool all = false) - delete the node( or nodes) with the specified value\n";
    std::cout << "Was:";
    test.outAll();
    test.deleteItem(1);
    std::cout << "Now:";
    test.outAll();
    std::cout
            << "\n9. replaceItem(int itemOld, int itemNew, bool all = false) -replace the value of the node (or nodes) with the new one\n";
    test.replaceItem(32, 44);
    std::cout << "hooray\n";
    test.outAll();

    std::cout << "\n10. Overloaded output operator < < (friendly function):\n";
    std::cout << testList1;

    std::cout << "\n11. Overloaded comparison operator == (class method):\n";
    if (testList1 == testlist2) {
        std::cout << "\tsimilar\t";
    } else {
        std::cout << "\tdifferent\t";
    }

    std::cout << "\n12.Method for adding parameter list items to the end of the source list:\n";
    testList1.addT(testlist2);
    testList1.outAll();

    std::cout << "end.";
    return 0;
}