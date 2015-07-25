#ifndef ALLOCATION_MEM_H
#define ALLOCATION_MEM_H

typedef struct Passant{
	int right;
	int left;
}Passant;

typedef struct EchiquierSave{
	Piece t;
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
Historic save_echiquier(Historic liste, EchiquierSave *E);

#endif //ALLOCATION_MEM_H_INCLUDED
