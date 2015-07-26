#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Struct_Piece.h"
#include "allocation_mem.h"


int compare_chessboard(EchiquierSave *actual_plan,EchiquierSave *other_plan);
int get_nb_occurrences(EchiquierSave* actual_plan,Historic list);
enum joueur convert_piececolor_to_joueur(enum  piececolor piece_color);
unsigned int h_funct(void *chained_list, int size_chain);

void init_chessboard(EchiquierSave *mychess);

int three_plan_chess(Historic_elements **list , Echiquier *E){
	EchiquierSave echiquier_plan;
	init_chessboard(&echiquier_plan);
	int h_value,i,j;
	int occurrence = 1;
	
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			echiquier_plan.t[i][j]=E->t[i][j].t;
			echiquier_plan.c[i][j]=E->t[i][j].c;
		}
	}
	echiquier_plan.joueur = E->joueur;
	echiquier_plan.en_passant=en_passant_test(E);

	h_value = h_funct(&echiquier_plan,sizeof(EchiquierSave)) % SIZE_TAB_HASH;	
	if(list[h_value]!=NULL){
		occurrence=get_nb_occurrences(&echiquier_plan,list[h_value]);
	}
	if(occurrence==1){
	list[h_value] = save_echiquier(list[h_value],&echiquier_plan,occurrence);
	}
	else if(occurrence==2){
		list[h_value]->nb_occur=2;
	}
	if(occurrence==3){
		return 1;
	}
	return 0;
}

void init_chessboard(EchiquierSave *mychess){
	memset(mychess,0,sizeof(EchiquierSave));
	return;
}

unsigned int h_funct(void *chained_list, int size_chain){
	int i;
	unsigned int h=0;
	unsigned char *my_chain = chained_list;
	for(i=0;i<size_chain;i++){
		h = (h + my_chain[i])*3+11;		
	}
	return h;
}

int get_nb_occurrences(EchiquierSave* actual_plan,Historic_elements *list){
	int count_occur=1;
	
	int compare_chess = compare_chessboard(actual_plan,&list->E_memory);
	while(list->next!=NULL){
		if(!compare_chess){
			count_occur=count_occur + list->nb_occur;	
		}
		list=list->next;
	}
	if(list->next==NULL){
		if(!compare_chess){
			count_occur=count_occur + list->nb_occur;
		}
	}
	return count_occur;
}

int compare_chessboard(EchiquierSave *actual_plan,EchiquierSave *other_plan){
	return memcmp(actual_plan, other_plan,sizeof(EchiquierSave));
}

Passant en_passant_test(Echiquier *E){
	Passant en_passant_test_return = {0,0};
	enum joueur en_passant_left,en_passant_right;
	en_passant_left=convert_piececolor_to_joueur(E->t[E->last_move.posx-1][E->last_move.posy].c);
	en_passant_right = convert_piececolor_to_joueur(E->t[E->last_move.posx+1][E->last_move.posy].c);

	if(E->t[E->last_move.posx][E->last_move.posy].t == pion){
		if(E->t[E->last_move.posx][E->last_move.posy].m==1){
			if(E->last_move.posy==3 || E->last_move.posy==4){
				if(en_passant_left==E->joueur){
					en_passant_test_return.left=1;
				}
				if(en_passant_right==E->joueur){
					en_passant_test_return.right=1;
				}
			}
		}
	}
	return en_passant_test_return;
}


Historic save_echiquier(Historic liste, EchiquierSave *E, int occurrence){
	Historic new_echiquier = malloc(sizeof(Historic_elements));
	if(new_echiquier==NULL){fprintf(stderr,"error allocation memory");exit(1);}
	new_echiquier->E_memory = *E;
	new_echiquier->next=NULL;
	new_echiquier->nb_occur=occurrence;
	if(liste==NULL){return new_echiquier;}
	else{
		Historic temp = liste;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_echiquier;
		return liste;
	}
}
