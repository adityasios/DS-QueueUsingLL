//
//  main.c
//  QueueUsingLL
//
//  Created by inncrewin on 26/12/23.
//

#include <stdio.h>
#include  <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
struct Node * f = NULL;
struct Node * r = NULL;

void display(void);

void enqueue(int );
int isFull(void);

int dequeue(void);



int main(int argc, const char * argv[]) {
    enqueue(2);
    enqueue(4);
    display();
    printf("Dequeue Data = %d\n",dequeue());
    display();
    printf("Dequeue Data = %d\n",dequeue());
    printf("Dequeue Data = %d\n",dequeue());
//    dequeue();
//    dequeue();
    return 0;
}
void enqueue(int data){
    struct Node * t =  (struct Node * )malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue isFull\n");return;
    }
    t->data = data;
    t->next = NULL;
    if(!f){
        f=t;
        r=t;
    }else{
        r->next = t;
        r=t;
    }
}

int dequeue(void){
    if(f==NULL){
        printf("Queue isEmpty\n");return -1;
    }
    struct Node * t = f;
    f=f->next;
    int data = t->data;
    free(t);
    return data;
}


void display(void){
    struct Node * t =  f;
    while (t) {
        printf("%d\n",t->data);
        t=t->next;
    }
}


