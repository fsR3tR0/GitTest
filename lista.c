#include "inc.h"

typedef uint8_t u8;
typedef uint16_t u16;

typedef struct lista{
	u8 data_i;
	float data_f;
	struct lista *next;
}lista;


lista *beszur(lista *elem,u8 mit,float mit_f);
lista *beszur_hatra(lista *elem, u8 mit_i, float mit_f);
void kiir(lista *elem);
lista * keres(lista *miben, u8 mit);
void felszabadit(lista *mit);
void hossz(u16 *mekkora, lista *elem);

int main(int arcv, char *argc[])
{
	lista *cuccos = 0;
	lista *tmp = 0;
	float j = 2.3;
	u16 listahossz = 0;

	for(u8 i = 1; i < 6; i++){
		cuccos = beszur(cuccos,i,j);
		j += 2.3;
	}
	kiir(cuccos);

	cuccos = beszur_hatra(cuccos, 45, 56.7);
	kiir(cuccos);

	tmp = keres(cuccos,45);
	if( tmp == NULL){
		printf("Nincs benne\n");
	}else{
		printf("Benne van: %d\n",tmp->data_i);
	}

	cuccos = beszur(cuccos, 34, 123.4);

	hossz(&listahossz, cuccos);
	printf("Lista hossza: %d\n",listahossz);

	return 0;
}

void hossz(u16 *mekkora, lista *elem){
	lista *p = elem;
	u16 meret = 0;
	while( p->next != NULL){
		p = p->next;
		meret++;
	}
	meret++;

	*mekkora = meret;
}

lista *beszur(lista *elem, u8 mit, float mit_f){
	lista *ujelem = (lista*)malloc(sizeof(lista));
	ujelem->data_i = mit;
	ujelem->data_f = mit_f;
	ujelem->next = elem;

	return ujelem;
}

void kiir(lista *elem){
	lista *p;
	for(p = elem; p != NULL; p = p->next){
		printf("Elem egesz: %d \t",p->data_i);
		printf("Elem lebego: %.2f\n",p->data_f);
	}
}

void felszabadit(lista *mit){
	lista *p = mit;
	while(p != NULL){
		lista *tmp = p->next;
		free(p);
		p = tmp;
	}
	printf("Felszabaditva\n");
}

lista *keres(lista *miben, u8 mit){
	lista *p = 0;
	for(p = miben; p != NULL; p = p->next){
		if(p->data_i == mit)
			return p;
	}
	return NULL;
}

lista *beszur_hatra(lista *elem, u8 mit_i, float mit_f){
	lista *uj = (lista*)malloc(sizeof(lista));
	uj->data_i = mit_i;
	uj->data_f = mit_f;
	if(elem == NULL){
		return uj;
	}else{
		lista *p = elem;
		while(p->next != NULL)
			p = p->next;
		p->next = uj;
		return elem;
	}
}


