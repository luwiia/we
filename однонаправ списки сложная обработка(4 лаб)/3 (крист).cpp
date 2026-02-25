#include <iostream>
#include <cstddef>
using namespace std;

struct list {
    int info;
    list* next;
};


list* make() {
    list* beg = NULL;
    list* p = NULL;
    int x;
    cin >> x;

    if (x == 0) return NULL;

    beg = new(list);
    beg->info = x;
    beg->next = NULL;
    p = beg;

    while (true) {
        cin >> x;
        if (x == 0) break;

        list* r = new(list);
        r->info = x;
        r->next = NULL;
        p->next = r;
        p = r;
    }
    return beg;
}


void print(list* beg) {
    list* p = beg;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

bool perfect(int n) {
    if (n <= 1) return false;
    
    int sum = 0;
    
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            sum += i;  
        }
    }
    
    return (sum == n);
}

list* insert(list* beg) {
    list* fake = new(list);
    fake->next = beg;
    
    list* prev = fake;  // предыдущий элемент
    list* curr = beg;    // текущий элемент
    
    while (curr != NULL && curr->next != NULL) {
        if (perfect(curr->info) && perfect(curr->next->info)) {  
            list* new_elem = new(list);
            new_elem->info = 11;

            new_elem->next = curr->next;
            curr->next = new_elem;
            
            prev = new_elem;
            curr = new_elem->next; 
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    list* new_beg = fake->next;
    delete fake;
    return new_beg;
}



int main() {
    list* beg = make();
    print(beg);
    beg = insert(beg);
    print(beg);
}

//6 28 12 0 -> 6 11 28 12 
