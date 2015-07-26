#ifndef ALLOCATION_MEM_H
#define ALLOCATION_MEM_H

typedef struct Passant{
	int right;
	int left;
}Passant;

typedef struct EchiquierSave{
	enum piecetype t[LARGEUR][LARGEUR];
	enum piececolor c[LARGEUR][LARGEUR];
	enum joueur joueur;
	Passant en_passant;
}EchiquierSave;


typedef struct Historic_elements{
	EchiquierSave E_memory;
	struct Historic_elements *next;
	int nb_occur;
}Historic_elements;

typedef struct Historic_elements *Historic;

Passant en_passant_test(Echiquier *E);
Historic save_echiquier(Historic liste, EchiquierSave *E,int occurrence);
int three_plan_chess(Historic_elements **list, Echiquier *E);
int get_nb_occurrences(EchiquierSave *actual_plan,Historic list);

#endif //ALLOCATION_MEM_H_INCLUDED
