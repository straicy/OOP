#include "Function.h"

Function* Function::head = nullptr;

Function::Function() {
    next = head;
    head = this;
}

Function::~Function() {}

void Function::printList() {
    Function* p = head;
    cout << "\n=== �� ������� � ������ ===\n";
    while (p != nullptr) {
        p->show();
        p = p->next;
    }
}
