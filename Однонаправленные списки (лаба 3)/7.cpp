#include <iostream>
using namespace std;

struct list{
    int info;
    list* next;
};

list* make(){
    list* beg = new(list);
    int x;
    cin >> x;
    beg->info=x;
    list *p = beg;
    while (x!=0){
        cin >> x;
        if (x!=0){
            list* r = new(list);
            r->info = x;
            r->next = NULL;
            p->next = r;
            p = r;
        }
    }
    return beg;
}

void print(list* beg){
    list* p = beg;
    while (p!=NULL){
        cout << "elem: " << p->info << endl;
        p = p->next;
    }
}

list* del(list* beg){
    if (beg==NULL || beg->next==NULL) return beg;
    
    if (beg->info > 0 && beg->next->info % 2 == 0) {
        list* temp = beg;
        beg = beg->next;
        delete temp;
    }
    
    if (beg == NULL || beg->next == NULL) return beg;
    
    list* p = beg;
    while (p->next != NULL && p->next->next != NULL) {
        if (p->next->info > 0 && p->next->next->info % 2 == 0) {
            list* temp = p->next;
            p->next = p->next->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
    
    return beg;
}
        

int main() {
	list* beg = make();
	print(beg);
	beg = del(beg);
	print(beg);

}
