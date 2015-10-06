#include "fonctions.h"


int main(){
    
    int a = 0;
    int b = 0;
    int resultat = 0;
    
    printf(" Entrez un premier nombre ");
    scanf("%d", &a);
    printf(" Entrez un deuxième nombre ");
    scanf("%d", &b);
    
    resultat = calculatrice(a,b);
    printf(" Le résultat de %d+%d vaut %d ", a, b, resultat);
    
    return 0;    
    
}