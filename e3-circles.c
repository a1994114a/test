#include <stdio.h>
#include <stdlib.h>

#define NUM_CIRCLES 2

typedef struct {
        
    int x;
    int y;
    float radius;    
    
} CircleType;

void print_circle(CircleType *c) {

    printf("Circle centered at (%d,%d) with a radius of %0.1f.\n", 
            c->x, c->y, c->radius);

}

int main() {

    //pointer variable on stack, array on heap
    CircleType *circles1 = (CircleType*) calloc(NUM_CIRCLES, 
                                            sizeof(CircleType));

    circles1->x = 2;
    circles1->y = 3;
    circles1->radius = 6.4;

    (circles1+1)->x = 1;
    circles1[1].y = 1;    
    (*(circles1+1)).radius = 10.1;

    for(int i = 0; i < NUM_CIRCLES; i++) {
        print_circle(circles1 + i);
    }

    free(circles1);    

    printf("\n\n");


    //array of pointers on stack, individual structs on heap
    CircleType *circles2[NUM_CIRCLES];

    circles2[0] = (CircleType*) calloc(1, sizeof(CircleType));
    (*circles2)->x = 4;
    (*circles2)->y = 7;
    (*circles2)->radius = 2.4;

    circles2[1] = (CircleType*) calloc(1, sizeof(CircleType));
    ((*circles2)+1)->x = 2;
    ((*circles2)[1]).y = 8;    
    (*(*circles2+1)).radius = 10.1;

    for(int i = 0; i < NUM_CIRCLES; i++) {
        print_circle((*circles2) + i);
    }
    printf("\n\n");

    free(circles2[0]);
    free(circles2[1]);


    //pointer on stack, array of pointers on heap 
    //(to individual structs on heap)
    CircleType **circles3 = calloc(NUM_CIRCLES, 
                                sizeof(CircleType*));
    
    circles3[0] = (CircleType*) calloc(1, sizeof(CircleType));
    (circles3[0])->x = 6;
    (circles3[0])->y = 3;
    (circles3[0])->radius = 3.5;

    *(circles3+1) = (CircleType*) calloc(1, sizeof(CircleType));
    (*(circles3[1])).x = 1;
    (*(circles3[1])).y = 6;
    (*(circles3[1])).radius = 1.5;

    for(int i = 0; i < NUM_CIRCLES; i++) {
        print_circle(circles3[i]);
    }
    printf("\n\n");

    free(circles3[0]);
    free(circles3[1]);
    free(circles3);

    return 0;
}
