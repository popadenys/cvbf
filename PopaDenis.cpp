#include<iostream>
using namespace std;

typedef struct termen {
                struct termen *next;
                int info;
                } element;

typedef struct
              {
               element *start,*current,*finalist;
               int length;
              } lista;

lista *L;

int show_me(lista *L) {
    if (L->length != 0) {
        element *carrier;
        carrier=L->start;
        while (carrier!=NULL) {
            cout<<carrier->info<<" ";
            carrier=carrier->next;
            }
        cout<<endl;
        return 1;
    } else {
        cout << "Empty" << endl;
    }
    return 0;
}

int add(lista **L,int value)  {
    if ((*L)->length == 0)  {
        element *new_one=new element;
        if (new_one!=NULL){
            new_one->info=value;
            new_one->next=NULL;
            (*L)->length=1;
            (*L)->start=(*L)->current=(*L)->finalist=new_one;
        }
        return 1;
    }
    element *new_one=new element;
    if (new_one!=NULL) {
        new_one->info=value;
        new_one->next=NULL;
        (*L)->length++;
        (*L)->finalist->next=new_one;
        (*L)->finalist=new_one;
    }
    return 1;
}

int serve(lista **L,int *old) {
    if((*L)->length == 0) {
        return 0;
    } else if ((*L)->length == 1) {
        (*old) = (*L)->start->info;
        (*L)->length = 0;
        delete (*L)->current;
        (*L)->current=(*L)->finalist=(*L)->start=NULL;
        return 1;
    } else {
        (*old) = (*L)->start->info;
        (*L)->length--;
        element * temp = (*L)->start;
        if ((*L)->current == (*L)->start) {
            (*L)->current = (*L)->start->next;
        }
        (*L)->start = (*L)->start->next;
        delete temp;
        return 1;
    }
}

lista *initlist(){
    lista *result=new lista;
    if (result!=NULL) {
        result->length=0;
        result->start=result->current=result->finalist=NULL;
    }
    return result;
}

int main() {
    L=initlist();
    for(int i = 1; i <= 10; i++) add(&L,i);
    show_me(L);
    for(int i = 0; i < 10; i++) {
        int old;
        serve(&L, &old);
        cout << "Removed " << old << endl;
        show_me(L);
    }
}
