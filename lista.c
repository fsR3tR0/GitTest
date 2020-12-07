#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef uint8_t u8;
typedef uint16_t u16;

typedef struct lista{
	u8 data_i;
	float data_f;
	struct lista *next;
}lista;

lista *beszur(lista *elem,u8 mit,float mit_f);
void kiir(lista *elem);

int main(int arcv, char *argc[])
{
	lista *cuccos = 0;
	float j = 2.3;

	for(u8 i = 1; i < 12; i++){
		cuccos = beszur(cuccos,i,j);
		j += 2.3;
	}

	kiir(cuccos);

	return 0;
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
		printf("Elem egesz: %d\n",p->data_i);
		printf("Elem lebego: %.2f\n",p->data_f);
	}
}




