#include <stdlib.h>

int** allocation_2Dtab(int size1, int size2){
    int **p,i;
    p = malloc(size1 * sizeof(*p));
    if(p == NULL){exit(1);}//No allocation before no free allocation necessary

    for(i=0;i<size1;i++){
        p[i] = malloc(size2 * sizeof(**p));
        if(p[i]==NULL){
            for(i=i-1;i>=0;i--){
                free(p[i]); //If bug begin in the middle of allocation it's necessary to free the allocation already done
            }
            free(p);    //p is allocated so it's necessary to free it
            exit(1);
        }
    }
    return p;
}
