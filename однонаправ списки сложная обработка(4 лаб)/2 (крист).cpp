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

bool prime(int n) {
    bool flag = 1;
 
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            flag = 0;
        }
    }

    return flag;
}

list* del(list* beg){;
    
    while (beg!=NULL && prime(beg->info)){
        list *temp = beg;
        beg = beg->next;
        delete temp;
    }
    
    if (beg==NULL) return NULL;
    
    list *curr = beg;
    while (curr->next!=NULL){
        if (prime(curr->next->info)){
            list *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else curr = curr->next;
    }
    return beg;
}




int main() {
    list* beg = make();
    print(beg);
    beg = del(beg);
    print(beg);
}
