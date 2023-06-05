#include <stdio.h> 
#include <stdlib.h> 
  
 typedef struct noArv{ 
  
         int chave; 
         struct noArv *esq; 
         struct noArv *dir; 
  
 } noArv; 
  
 noArv* insere(noArv *, int); 
 void showPre(noArv *); 
 void showIn(noArv *); 
 void showPost(noArv *); 
 void erase(noArv *); 
  
 void main (){ 
         unsigned short i; 
         int chave; 
         unsigned short qtsNos; 
         unsigned short qtsCasos, caso = 0; 
 
         scanf("%hu", &qtsCasos); 
  
         while (qtsCasos--){ 
  
                 noArv *arvore = NULL; 
                 scanf("%hu", &qtsNos); 
  
                 for (i = 0; i < qtsNos; i++){ 
  
                         scanf("%d", &chave); 
                         arvore = insere(arvore, chave); 
  
                 } 
  
                 printf("Case %hu:\n", ++caso); 
                 printf("Pre.:"); 
                 showPre(arvore); 
                 printf("\n"); 
                 printf("In..:"); 
                 showIn(arvore); 
                 printf("\n"); 
                 printf("Post:"); 
                 showPost(arvore); 
                 printf("\n\n"); 
                 erase(arvore); 
  
         } 
 } 
  
 noArv* insere(noArv *arvore, int chave){ 
  
         if (!arvore){ 
  
                 arvore = (noArv *) malloc(sizeof(noArv)); 
                 arvore->chave = chave; 
                 arvore->esq = arvore->dir = NULL; 
  
         } 
         else if (arvore->chave > chave) 
                 arvore->esq = insere(arvore->esq, chave); 
  
         else 
                 arvore->dir = insere(arvore->dir, chave); 
  
         return arvore; 
  
 } 
  
 void showPost(noArv *arvore){ 
  
         if (arvore){ 
  
                 showPost(arvore->esq); 
                 showPost(arvore->dir); 
                 printf(" %d", arvore->chave); 
  
         } 
  
 } 
  
 void showPre(noArv *arvore){ 
  
         if (arvore){ 
  
                 printf(" %d", arvore->chave); 
                 showPre(arvore->esq); 
                 showPre(arvore->dir); 
  
         } 
  
 } 
 void showIn(noArv *arvore){ 
  
         if (arvore){ 
  
                 showIn(arvore->esq); 
                 printf(" %d", arvore->chave); 
                 showIn(arvore->dir); 
  
         } 
  
 } 
  
 void erase(noArv *arvore){ 
  
         if (arvore){ 
  
                 erase(arvore->esq); 
                 erase(arvore->dir); 
                 free(arvore); 
                 arvore = NULL; 
  
         } 
  
 }
