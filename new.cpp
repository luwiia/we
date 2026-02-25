#include <iostream>
#include <cmath>
using namespace std;

struct list{
    int info;
    list* next;
};

//////////////////////////////////////////////////
// создание списка (как у тебя)
list* make(){
    list* beg = NULL;
    list* p = NULL;
    int x;
    cin >> x;

    if (x == 0) return NULL;

    beg = new(list);
    beg->info = x;
    beg->next = NULL;
    p = beg;

    while (true){
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

//////////////////////////////////////////////////
// вывод
void print(list* beg){
    list* p = beg;
    while (p!=NULL){
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

//////////////////////////////////////////////////
// служебные функции

int sumDigits(int x){
    x = abs(x);
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int findMin(list* beg){
    int min = beg->info;
    list* p = beg;
    while(p){
        if (p->info < min)
            min = p->info;
        p = p->next;
    }
    return min;
}

bool isPrime(int x){
    if (x < 2) return false;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}

bool isPerfect(int x){
    if (x < 2) return false;
    int sum = 1;
    for(int i=2;i<=x/2;i++)
        if(x%i==0) sum+=i;
    return sum==x;
}

int count2(int x){
    x = abs(x);
    int c=0;
    while(x){
        if(x%10==2) c++;
        x/=10;
    }
    return c;
}

bool only7(int x){
    x = abs(x);
    if(x==0) return false;
    while(x){
        if(x%10!=7) return false;
        x/=10;
    }
    return true;
}

int count7(int x){
    x = abs(x);
    int c=0;
    while(x){
        if(x%10==7) c++;
        x/=10;
    }
    return c;
}

//////////////////////////////////////////////////
// ЗАДАЧА 1
// вставить минимум перед элементами с четной суммой цифр

list* task1(list* beg){

    if(!beg) return beg;

    int min = findMin(beg);

    list* p = beg;
    list* prev = NULL;

    while(p){

        if(sumDigits(p->info)%2==0){

            list* r = new(list);
            r->info = min;

            if(prev==NULL){
                r->next = beg;
                beg = r;
                prev = r;
            }
            else{
                prev->next = r;
                r->next = p;
                prev = r;
            }
        }

        prev = p;
        p = p->next;
    }

    return beg;
}

//////////////////////////////////////////////////
// ЗАДАЧА 2
// удалить простые числа

list* task2(list* beg){

    while(beg && isPrime(beg->info)){
        list* temp = beg;
        beg = beg->next;
        delete temp;
    }

    list* p = beg;

    while(p && p->next){
        if(isPrime(p->next->info)){
            list* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        else
            p = p->next;
    }

    return beg;
}

//////////////////////////////////////////////////
// ЗАДАЧА 3
// вставить 11 между совершенными

list* task3(list* beg){

    list* p = beg;

    while(p && p->next){

        if(isPerfect(p->info) && isPerfect(p->next->info)){

            list* r = new(list);
            r->info = 11;

            r->next = p->next;
            p->next = r;

            p = r->next;
        }
        else
            p = p->next;
    }

    return beg;
}

//////////////////////////////////////////////////
// ЗАДАЧА 4
// удалить элементы заканчивающиеся на 2

list* task4(list* beg){

    while(beg && abs(beg->info)%10==2){
        list* temp = beg;
        beg = beg->next;
        delete temp;
    }

    list* p = beg;

    while(p && p->next){

        if(abs(p->next->info)%10==2){
            list* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        else
            p = p->next;
    }

    return beg;
}

//////////////////////////////////////////////////
// ЗАДАЧА 5
// создать новый список с 3 цифрами 7

list* task5(list* beg){

    list* result = NULL;
    list* last = NULL;

    bool exist=false;

    list* p = beg;

    while(p){
        if(only7(p->info)){
            exist=true;
            break;
        }
        p=p->next;
    }

    if(exist) return result;

    p = beg;

    while(p){

        if(count7(p->info)==3){

            list* r = new(list);
            r->info = p->info;
            r->next = NULL;

            if(!result){
                result=r;
                last=r;
            }
            else{
                last->next=r;
                last=r;
            }
        }

        p=p->next;
    }

    return result;
}

//////////////////////////////////////////////////
// MAIN

int main(){

    cout << "input list (0 end):" << endl;

    list* beg = make();

    cout << "original:" << endl;
    print(beg);

    beg = task1(beg);
    cout << "task1:" << endl;
    print(beg);

    beg = task2(beg);
    cout << "task2:" << endl;
    print(beg);

    beg = task3(beg);
    cout << "task3:" << endl;
    print(beg);

    beg = task4(beg);
    cout << "task4:" << endl;
    print(beg);

    list* beg2 = task5(beg);
    cout << "task5 new list:" << endl;
    print(beg2);

}
