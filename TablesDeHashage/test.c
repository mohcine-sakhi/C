#include <stdio.h>
#include <stdlib.h>

typedef struct Point Point;
struct Point {
    int x;
    int y;
};

int main(int argc, int *argv[]){

    Point p1, p2;
    
    p1.x = 1;
    p1.y = 1;

    p2 = p1;

    printf("P1 (%d, %d)\n", p1.x, p1.y);
    printf("P2 (%d, %d)\n", p2.x, p2.y);
    
    if(p1 == p2){
        printf("OK");
    }else{
        printf("KO !!");
    }

    
    return 0;
}