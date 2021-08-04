#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
	int valor;
	struct s_nodo *next;
}	t_nodo;

typedef struct s_list
{
	int size;
	t_nodo *firstItem;
	t_nodo *lastItem;
}	t_list;

t_nodo *getNodo(int valor)
{
	t_nodo *nodo = (t_nodo *)malloc(sizeof(t_nodo));
	nodo->valor = valor;
	nodo->next = NULL;
	return nodo;
}

//enlazar nueva lista ligada
t_list *getNewList()
{
	t_list *ll = (t_list *)malloc(sizeof(t_list));
	ll->size = 0;
	ll->firstItem = NULL;
	ll->lastItem = NULL;
	return ll;
}

// operaciones CRUD

void add(t_list *ll, t_nodo *nodo)
{
	if(ll->firstItem == NULL)
		ll->firstItem = nodo;
	else
		ll->lastItem->next = nodo;
	ll->lastItem = nodo;
	ll->size++;
}

t_nodo *read(t_list *ll, unsigned int indice)
{
	int i;
	t_nodo *exploradorLista;

	if (ll->size &&  indice < ll->size)
	{
		exploradorLista = ll->firstItem;
		i = 0;
		while (i++ < indice)
			exploradorLista = exploradorLista->next; 
	}	
	return exploradorLista;
}

void update(t_list *ll, unsigned int indice, int newValue)
{
	int i;
	t_nodo *exploradorLista;

	if (ll->size &&  indice < ll->size)
	{
		exploradorLista = ll->firstItem;
		i = 0;
		while (i++ < indice)
			exploradorLista = exploradorLista->next;
		exploradorLista->valor = newValue;
	}
	free(exploradorLista);	
}

void removed(t_list *ll, unsigned int indice)
{
	t_nodo *aux;
	t_nodo *exportadorLista;
	int i;

	if (ll->size && indice < ll->size)
	{
		if (indice == 0)
		{
			aux = ll->firstItem;
			ll->firstItem = ll->firstItem->next;
		}
		else
		{
			exportadorLista = ll->firstItem;
			i = 0;
			while (i++ < indice - 1)
				exportadorLista = exportadorLista->next;
			aux = exportadorLista->next;
			if (indice == ll->size - 1)
			{
				exportadorLista->next = exportadorLista;
			} else {
				exportadorLista->next = exportadorLista->next->next;
			}
		}
	}
	free(aux);
	ll->size--;
}

int main()
{
	t_list *lista = getNewList();
	t_nodo *a = getNodo(1);
	t_nodo *b = getNodo(2);
	t_nodo *c = getNodo(3);
	t_nodo *d = getNodo(4);
	
	add(lista, a);
	add(lista, b);
	add(lista, c);
	add(lista, d);
	
	printf("%d\n", read(lista, 3)->valor);
	update(lista, 3, 11);
	printf("%i\n", read(lista, 3)->valor);
	printf("%i\n", read(lista, 0)->valor);
	removed(lista, 0);
	printf("%i\n", read(lista, 0)->valor);

	free(lista);
	return (0);
}
