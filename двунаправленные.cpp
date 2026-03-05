//#include <iostream>
//using namespace std;
//
//struct list {
//    int info;
//    list* next;
//};
//
//
//list* make() {
//    list* beg = NULL;
//    list* p = NULL;
//    int x;
//    cin >> x;
//
//    if (x == 0) return NULL;
//
//    beg = new(list);
//    beg->info = x;
//    beg->next = NULL;
//    p = beg;
//
//    while (true) {
//        cin >> x;
//        if (x == 0) break;
//
//        list* r = new(list);
//        r->info = x;
//        r->next = NULL;
//        p->next = r;
//        p = r;
//    }
//    return beg;
//}
//
//
//void print(list* beg) {
//    list* p = beg;
//    while (p != NULL) {
//        cout << p->info << " ";
//        p = p->next;
//    }
//    cout << endl;
//}
//
//void add(list*& beg, list*& end, int value) {
//    list* new1 = new(list);
//    new1->info = value;
//    new1->next = NULL;
//
//    if (beg == NULL) {
//        beg = new1;
//        end = new1;
//    }
//    else {
//        end->next = new1;
//        end = new1;
//    }
//
//}
//
//list* positive(list* list1, list* list2) {
//    list* resbeg = NULL;
//    list* resend = NULL;
//
//    list* cur = list1;
//    while (cur != NULL) {
//        if (cur->info > 0) {
//            add(resbeg, resend, cur->info);
//        }
//        cur = cur->next;
//    }
//    cur = list2;
//    while (cur != NULL) {
//        if (cur->info > 0) {
//            add(resbeg, resend, cur->info);
//        }
//        cur = cur->next;
//    }
//    return resbeg;
//}
//
//int main() {
//    list* beg1 = make();
//    list* beg2 = make();
//    print(beg1);
//    print(beg2);
//    list* beg3 = positive(beg1, beg2);
//    print(beg3);
//}

#include <iostream>
using namespace std;
struct list {
	int info;
	list* next;
	list* prev;
};

void print(list* beg) {
	list* p = beg;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}

list* make() {
	list* beg = new(list);
	list* r, * p;
	int x;
	cin >> x;
	beg->info = x;
	p = beg;
	while (x != 0) {
		cin >> x;
		if (x != 0) {
			r = new(list);
			r->info = x;
			r->next = NULL;
			p->next = r;
			r->prev = p;
			p = r;
		}
	}
	return beg;
}

int maxi(list* beg) {
	list* p = beg;
	int max = beg->info;

	while (p != NULL) {
		if (p->info > max) max = p->info;
		p = p->next;
	}
	return max;
}

//bool sim(list* beg) {
//	list* left = beg;
//	list* right = beg;
//
//	while (right->next != NULL) {
//		right = right->next;
//		while (left != NULL) {
//			if (left->info != right->info) return false;
//			left = left->next;
//			right = right->prev;
//		}
//	}
//	return true;
//}

//int res(list* beg) {
//	int sum = 0;
//	list* left = beg;
//	list* right = beg;
//
//	while (right->next != NULL) {
//		right = right->next;
//	} 
//	while (left != NULL) {
//			sum += (left->info) * (right->info);
//			left = left->next;
//			right = right->prev;
//			
//	}
//	return sum;
//}

int search(list* beg) {
	list* left = beg;
	list* right = beg;
	int flower = NULL;
	while (right->next != NULL) {
		right = right->next;
	}
	while (left != NULL) {
		if (right->info % 2 == 0) { return right->info; }
		(right = right->prev);
	}
	return 0;
}

void replace(list* beg) {
	list* left = beg;
	list* right = beg;
	int flower = search(beg);

	while (right->next != NULL) {
		right = right->next;
	}
	while (left != NULL) {
		if (left->info % 10 == 5) left->info = flower;
		left = left->next;
	}
}

int main() {
	list* beg = make();
	print(beg);
	replace(beg);
	print(beg);
}
