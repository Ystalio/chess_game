#include <stdlib.h>
#include <stdio.h>
#include "Struct_Piece.h"
#include "allocation_mem.h"


int three_plan_chess(Historic_elements **liste, Echiquier *E){
	Passant en_passant;
	EchiquierSave echiquier_plan;
	int h_value;

	echiquier_plan.t = E->t;
	echiquier_plan.joueur = E->joueur;
	echiquier_plan.en_passant=en_passant_test(E);

	h_value = h_funct(&echiquier_plan);	
	liste[h_value] = save_echiquier(liste[h_value],&echiquier_plan);
}


Passant en_passant_test(Echiquier *E){
	Passant en_passant_test_return = {0,0};
	if(E->t[E->last_move.posx][E->last_move.posy].t == pion){
		if(E->t[E->last_move.posx][E->last_move.posy].m==1){
			if(E->last_move.posy==3 || E->last_move.posy==4){
				if(E->t[E->last_move.posx-1][E->last_move.posy].t==E->joueur){
					en_passant_test_return.left=1;
				}
				if(E->t[E->last_move.posx+1][E->last_move.posy].t==E->joueur){
					en_passant_test_return.right=1;
				}
			}
		}
	}
	return en_passant_test_return;
}


Historic save_echiquier(Historic liste, EchiquierSave *E){
	Historic new_echiquier = malloc(sizeof(*Historic));
	if(new_echiquier==NULL){fprintf(stderr,"error allocation memory");exit(1);}
	new_echiquier->E_memory = *E;
	new_echiquier->next=NULL;
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
