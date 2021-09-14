#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncadDesc.h"


struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor {
    struct elemento *inicio;
    struct elemento *final;
    int tamanho;
};

Lista* cria_lista() {
    Lista *li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL) {
        li->inicio = NULL;
        li->final = NULL;
        li->tamanho = 0;
    }
    
    return li;
}


void libera_lista(Lista *li) {
    if (li != NULL) {
        Elem *no;
        while (li->inicio != NULL) {
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}


int tamanho_lista(Lista *li) {
    if (li == NULL)
        return 0;
    
    return li->tamanho;
}


int insere_lista_inicio(Lista *li , struct aluno al) {
    if (li == NULL) 
        return 0;
    
    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;
    
    no->dados = al;
    no->prox = li->inicio;

    if (li->inicio == NULL)
        li->final = no;
    
    li->inicio = no;
    li->tamanho++;

    return 1;
}


int insere_lista_final(Lista *li, struct aluno al) {
    if (li == NULL)
        return 0;
    
    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;
    
    no->dados = al;
    no->prox = NULL;

    if (li->inicio == NULL)
        li->inicio = no;
    else
        li->final->prox = no;

    li->final = no;
    li->tamanho++;

    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al) {
    if (li == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->dados = al;

    if (li->inicio == NULL) {
        li->inicio = no;
        li->final = no;
    } else if (li->inicio->dados.matricula > al.matricula) {
        no->prox = li->inicio;
        li->inicio = no;
    } else {
        Elem *aux = li->inicio;
        
        while (aux->prox != NULL && aux->prox->dados.matricula < al.matricula )
            aux = aux->prox;
        
        no->prox = aux->prox;
        aux->prox = no;

        if (no->prox == NULL)
            li->final = no;
    }

    li->tamanho++;
    
    return 1;
        
}


int remove_lista_incio(Lista *li) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)
        return 0;

    Elem *no = li->inicio;
    li->inicio = no->prox;

    free(no);

    if (li->inicio == NULL)
        li->final = NULL;
    
    li->tamanho--;

    return 1;
}


int remove_lista_final(Lista *li) {
    if (li == NULL) 
        return 0;
    if (li->final == NULL)
        return 0;

    Elem *ant, *no = li->inicio;

    while (no != li->final) {
        ant = no;
        no = no->prox;
    }

    if (no == li->inicio) {
        li->final = NULL;
        li->inicio = NULL;
        free(no);
    } else {
        ant->prox = NULL;
        li->final = ant;
        free(no);
    }

    li->tamanho--;

    return 1;
}


int lista_vazia(Lista *li) {
    if (li == NULL)
        return 1;
    if (li->inicio == NULL)
        return 1;
    
    return 0;
}


int lista_cheia(Lista *li) {
    return 0;
}


int busca_lista_mat(Lista *li, int mat, struct aluno *al) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)
        return 0;

    Elem *no = li->inicio;

    while (no != NULL && no->dados.matricula != mat)
        no = no->prox;
    
    if (no == NULL)
        return 0;
    
    *al = no->dados;

    return 1;
}


int busca_lista_pos(Lista *li, int pos, struct aluno *al) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)
        return 0;

    Elem *no = li->inicio;
    int i = 0;

    while (no != NULL && i != pos) {
        no = no->prox;
        i++;
    }

    if (no == NULL)
        return 0;
    
    *al = no->dados;

    return 1;
}
