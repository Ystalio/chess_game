#include <stdlib.h>
#include "struct_piece.h"

int** allocation_2Dtab(int size1, int size2){
    int **p,i;
    p = malloc(size1 * sizeof(*p));
    if(p == NULL){exit(1);}//No allocation before no free allocation necessary

    for(i=0;i<size1;i++){
        p[i] = malloc(size2 * sizeof(**p));
        if(p[i]==NULL){
            for(i=i-1;i>=0;i--){
                free(p[i]); //If bug begin in the middle of the allocation it's necessary to free the allocation already done
            }
            free(p);    //p is allocated so it's necessary to free it
            exit(1);
        }
    }
    return p;
}

Echiquier** allocation_struct_echiquier(int nb_echiquier){
	Echiquier** allocated_memory_for_echiquier;
	int i;
	allocated_memory_for_echiquier = (Echiquier**)malloc(nb_echiquier * sizeof(*allocated_memory_for_echiquier));
	if(allocated_memory_for_echiquier==NULL){
		exit(1);
	}
	for(i=0;i<nb_echiquier;i++){
		allocated_memory_for_echiquier[i]=(Echiquier*)malloc(sizeof(**allocated_memory_for_echiquier));
		if(allocated_memory_for_echiquier[i]==NULL){
			for(i=i-1;i>=0;i--){
				free(allocated_memory_for_echiquier[i]);
			}
			free(allocated_memory_for_echiquier);
			exit(1);
		}
	}
	return allocated_memory_for_echiquier;	
}


typedef struct Historic_Echiquier{
	Echiquier E_memory;
	struct Historic_Echiquier *next;
}Historic_Echiquier;
