#ifndef CHOICE_PLAYER_H
#define CHOICE_PLAYER_H

int move_piece(Echiquier *E, Position2 *movement);

enum joueur_type {joueur=1, ordinateur=2};

int get_joueur_mvt(Historic_elements **list, Echiquier *E);
int ia_player(Historic_elements **list, Echiquier *E);

typedef int (*get_mvt_funct)(Historic_elements **list, Echiquier *E);

const static get_mvt_funct get_mvt[]={
	NULL,
	&get_joueur_mvt,
	&ia_player
};

#endif //CHOICE_PLAYER_H_INCLUDED 
