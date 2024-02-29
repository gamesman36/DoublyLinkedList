#include <string>

struct Link {
    std::string value;
    Link* prev;
    Link* succ;
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} {}
};

Link* insert(Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;
    if (p->succ != nullptr) p->succ->prev = n;
    n->succ = p->succ;
    n->prev = p;
    p->succ = n;
    return n;
}

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Freia"});

    // Deallocate memory
    Link* current = norse_gods;
    while (current != nullptr) {
        Link* temp = current;
        current = current->succ;
        delete temp;
    }
}