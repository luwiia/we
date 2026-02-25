//4
#include <iostream>
#include <cstddef>
using namespace std;

struct list {
    int info;
    list* next;
};

// Функция для подсчета количества цифр '2' в числе
int countTwos(int n) {
    int count = 0;
    // Работаем с абсолютным значением, чтобы обрабатывать отрицательные числа
    int num = (n < 0) ? -n : n;
    
    while (num > 0) {
        if (num % 10 == 2) {
            count++;
        }
        num /= 10;
    }
    return count;
}

// Функция для проверки, оканчивается ли число на 2
bool endsWithTwo(int n) {
    int num = (n < 0) ? -n : n;  // берем абсолютное значение
    return (num % 10 == 2);
}

// Функция создания списка из массива (только элементы с ровно двумя '2')
list* createFromArray(int arr[], int size) {
    list* beg = NULL;
    list* p = NULL;
    
    for (int i = 0; i < size; i++) {
        if (countTwos(arr[i]) == 2) {
            list* r = new list;
            r->info = arr[i];
            r->next = NULL;
            
            if (beg == NULL) {
                beg = r;
                p = r;
            } else {
                p->next = r;
                p = r;
            }
        }
    }
    
    return beg;
}

// Функция для вывода списка
void print(list* beg) {
    if (beg == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    
    list* p = beg;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

// Функция для удаления элементов, оканчивающихся на 2
list* removeEndingWithTwo(list* beg) {
    if (beg == NULL) return NULL;
    
    // Удаляем элементы в начале списка, оканчивающиеся на 2
    while (beg != NULL && endsWithTwo(beg->info)) {
        list* temp = beg;
        beg = beg->next;
        delete temp;
    }
    
    if (beg == NULL) return NULL;
    
    // Удаляем остальные элементы, оканчивающиеся на 2
    list* curr = beg;
    while (curr->next != NULL) {
        if (endsWithTwo(curr->next->info)) {
            list* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    
    return beg;
}

int main() {
    // Пример массива
    int arr[] = {122, 222, 322, 12, 212, 22, 32, 224, 252, 262};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Создаем список из элементов с ровно двумя '2'
    list* myList = createFromArray(arr, size);
    
    cout << "Список из элементов с ровно двумя '2': ";
    print(myList);
    
    // Удаляем элементы, оканчивающиеся на 2
    myList = removeEndingWithTwo(myList);
    
    cout << "После удаления элементов, оканчивающихся на 2: ";
    print(myList);
    
    return 0;
}




//5
#include <iostream>
#include <cstddef>
#include <cmath>
using namespace std;

struct list {
    int info;
    list* next;
};

// Функция для создания списка (как в предыдущих задачах)
list* make() {
    list* beg = NULL;
    list* p = NULL;
    int x;
    cin >> x;

    if (x == 0) return NULL;

    beg = new list;
    beg->info = x;
    beg->next = NULL;
    p = beg;

    while (true) {
        cin >> x;
        if (x == 0) break;

        list* r = new list;
        r->info = x;
        r->next = NULL;
        p->next = r;
        p = r;
    }
    return beg;
}

// Функция для вывода списка
void print(list* beg) {
    if (beg == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    
    list* p = beg;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

// Функция для подсчета количества цифр '7' в числе
int countSevens(int n) {
    int count = 0;
    // Работаем с абсолютным значением для отрицательных чисел
    int num = (n < 0) ? -n : n;
    
    // Особый случай для числа 0
    if (num == 0) return 0;
    
    while (num > 0) {
        if (num % 10 == 7) {
            count++;
        }
        num /= 10;
    }
    return count;
}

// Функция для проверки, состоит ли число только из цифр 7
bool isAllSevens(int n) {
    int num = (n < 0) ? -n : n;
    
    // Число 0 не состоит из семерок
    if (num == 0) return false;
    
    while (num > 0) {
        if (num % 10 != 7) {
            return false;  // нашли цифру, не равную 7
        }
        num /= 10;
    }
    return true;  // все цифры равны 7
}

// Функция для проверки, есть ли в списке элементы, состоящие только из 7
bool hasAllSevens(list* beg) {
    list* current = beg;
    while (current != NULL) {
        if (isAllSevens(current->info)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Функция для создания нового списка из элементов с ровно тремя цифрами 7
list* createListWithThreeSevens(list* beg) {
    list* newBeg = NULL;
    list* newLast = NULL;
    
    list* current = beg;
    while (current != NULL) {
        if (countSevens(current->info) == 3) {
            // Создаем новый элемент
            list* newNode = new list;
            newNode->info = current->info;
            newNode->next = NULL;
            
            // Добавляем в новый список
            if (newBeg == NULL) {
                newBeg = newNode;
                newLast = newNode;
            } else {
                newLast->next = newNode;
                newLast = newNode;
            }
        }
        current = current->next;
    }
    
    return newBeg;
}

int main() {
    cout << "Введите элементы списка (0 для завершения):" << endl;
    list* originalList = make();
    
    cout << "Исходный список: ";
    print(originalList);
    
    // Проверяем, есть ли элементы, состоящие только из 7
    if (hasAllSevens(originalList)) {
        cout << "В списке есть элементы, состоящие только из цифры 7." << endl;
        cout << "Новый список не создается." << endl;
    } else {
        cout << "В списке нет элементов, состоящих только из цифры 7." << endl;
        cout << "Создаем новый список из элементов с тремя цифрами 7." << endl;
        
        list* newList = createListWithThreeSevens(originalList);
        
        cout << "Новый список: ";
        print(newList);
    }
    
    return 0;
}





//6
#include <iostream>
#include <cstddef>
using namespace std;

struct list {
    int info;
    list* next;
};

// Функция для создания списка
list* make() {
    list* beg = NULL;
    list* p = NULL;
    int x;
    cin >> x;

    if (x == 0) return NULL;

    beg = new list;
    beg->info = x;
    beg->next = NULL;
    p = beg;

    while (true) {
        cin >> x;
        if (x == 0) break;

        list* r = new list;
        r->info = x;
        r->next = NULL;
        p->next = r;
        p = r;
    }
    return beg;
}

// Функция для вывода списка
void printList(list* beg) {
    if (beg == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    
    list* p = beg;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

// Функция для вывода массива
void printArray(int arr[], int size) {
    if (size == 0) {
        cout << "Массив пуст" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для подсчета количества делителей числа, кратных 5
int countDivisorsMultipleOf5(int n) {
    int count = 0;
    int num = (n < 0) ? -n : n;  // работаем с абсолютным значением
    
    for (int i = 5; i <= num; i += 5) {  // перебираем только числа, кратные 5
        if (num % i == 0) {
            count++;
        }
    }
    
    return count;
}

// Оптимизированная версия (быстрее)
int countDivisorsMultipleOf5Optimized(int n) {
    int count = 0;
    int num = (n < 0) ? -n : n;
    
    // Находим все делители числа
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            // Проверяем первый делитель
            if (i % 5 == 0 && i != 0) {
                count++;
            }
            // Проверяем парный делитель (если он отличается)
            if (i != num / i) {
                if ((num / i) % 5 == 0 && (num / i) != 0) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

// Функция для построения массива из элементов списка с ровно тремя делителями, кратными 5
int* buildArrayFromList(list* beg, int& arraySize) {
    // Сначала подсчитываем, сколько элементов подходят
    arraySize = 0;
    list* current = beg;
    
    while (current != NULL) {
        if (countDivisorsMultipleOf5(current->info) == 3) {
            arraySize++;
        }
        current = current->next;
    }
    
    // Создаем массив нужного размера
    int* arr = new int[arraySize];
    
    // Заполняем массив подходящими элементами
    int index = 0;
    current = beg;
    while (current != NULL) {
        if (countDivisorsMultipleOf5(current->info) == 3) {
            arr[index++] = current->info;
        }
        current = current->next;
    }
    
    return arr;
}

// Функция для проверки, является ли массив возрастающим
bool isIncreasing(int arr[], int size) {
    if (size <= 1) return true;  // пустой массив или из 1 элемента считаем возрастающим
    
    for (int i = 1; i < size; i++) {
        if (arr[i] <= arr[i-1]) {  // строго возрастающий (если нужно нестрого, замените <= на <)
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Введите элементы списка (0 для завершения):" << endl;
    list* myList = make();
    
    cout << "Исходный список: ";
    printList(myList);
    
    // Строим массив из элементов с ровно тремя делителями, кратными 5
    int arraySize;
    int* myArray = buildArrayFromList(myList, arraySize);
    
    cout << "Массив из элементов с ровно тремя делителями, кратными 5: ";
    printArray(myArray, arraySize);
    
    // Проверяем массив на возрастание
    if (isIncreasing(myArray, arraySize)) {
        cout << "Массив является возрастающим." << endl;
    } else {
        cout << "Массив НЕ является возрастающим." << endl;
    }
    
    // Освобождаем память
    delete[] myArray;
    
    return 0;
}




//7
#include <iostream>
#include <cstddef>
using namespace std;

struct list {
    int info;
    list* next;
};

// Функция для создания списка
list* make() {
    list* beg = NULL;
    list* p = NULL;
    int x;
    cin >> x;

    if (x == 0) return NULL;

    beg = new list;
    beg->info = x;
    beg->next = NULL;
    p = beg;

    while (true) {
        cin >> x;
        if (x == 0) break;

        list* r = new list;
        r->info = x;
        r->next = NULL;
        p->next = r;
        p = r;
    }
    return beg;
}

// Функция для вывода списка
void print(list* beg) {
    if (beg == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    
    list* p = beg;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

// Функция для добавления элемента в конец списка
void addToList(list*& beg, list*& end, int value) {
    list* newNode = new list;
    newNode->info = value;
    newNode->next = NULL;
    
    if (beg == NULL) {
        beg = newNode;
        end = newNode;
    } else {
        end->next = newNode;
        end = newNode;
    }
}

// Функция для получения третьего списка из положительных элементов двух списков
list* getPositiveElements(list* list1, list* list2) {
    list* resultBeg = NULL;
    list* resultEnd = NULL;
    
    // Проходим по первому списку
    list* current = list1;
    while (current != NULL) {
        if (current->info > 0) {
            addToList(resultBeg, resultEnd, current->info);
        }
        current = current->next;
    }
    
    // Проходим по второму списку
    current = list2;
    while (current != NULL) {
        if (current->info > 0) {
            addToList(resultBeg, resultEnd, current->info);
        }
        current = current->next;
    }
    
    return resultBeg;
}

// Альтернативная функция без использования end (проще, но менее эффективна)
list* getPositiveElementsSimple(list* list1, list* list2) {
    list* result = NULL;
    list* last = NULL;
    
    // Вспомогательная функция для добавления в конец
    auto addElement = [&result, &last](int value) {
        list* newNode = new list;
        newNode->info = value;
        newNode->next = NULL;
        
        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    };
    
    // Проходим по первому списку
    list* current = list1;
    while (current != NULL) {
        if (current->info > 0) {
            addElement(current->info);
        }
        current = current->next;
    }
    
    // Проходим по второму списку
    current = list2;
    while (current != NULL) {
        if (current->info > 0) {
            addElement(current->info);
        }
        current = current->next;
    }
    
    return result;
}

// Функция для освобождения памяти списка
void deleteList(list* beg) {
    while (beg != NULL) {
        list* temp = beg;
        beg = beg->next;
        delete temp;
    }
}

int main() {
    cout << "Создание первого списка:" << endl;
    cout << "Введите элементы (0 для завершения): ";
    list* list1 = make();
    
    cout << "Создание второго списка:" << endl;
    cout << "Введите элементы (0 для завершения): ";
    list* list2 = make();
    
    cout << "\nПервый список: ";
    print(list1);
    
    cout << "Второй список: ";
    print(list2);
    
    // Получаем третий список из положительных элементов
    list* list3 = getPositiveElements(list1, list2);
    
    cout << "\nТретий список (только положительные элементы): ";
    print(list3);
    
    // Освобождаем память (если нужно)
    // deleteList(list1);
    // deleteList(list2);
    // deleteList(list3);
    
    return 0;
}
