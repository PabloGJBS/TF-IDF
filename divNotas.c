#include "divNotas.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
    int opcao = 0, num;
    char str[TAM], temp[TAM];
    
    pRef = fopen("tripadvisor_hotel_reviews.csv", "r");
    pNota1 = fopen("Nota1.txt", "w");
    pNota2 = fopen("Nota2.txt", "w");
    pNota3 = fopen("Nota3.txt", "w");
    pNota4 = fopen("Nota4.txt", "w");
    pNota5 = fopen("Nota5.txt", "w");

while ((fscanf(pRef, "%[^,]", temp))!= EOF){ //Armazena o review ate encontrar uma virgula enquanto checa se esta no fim do arquivo
                    strcat(str, temp);
                    fgetc(pRef); //impede um loop infinito
                    if(strcmp(temp, "  ") == 0){
                        fscanf(pRef, "%d", &num); //Pega a nota do review
                        switch(num){
                            case 1:
                                fprintf(pNota1, "%s", str);
                                break;
                            case 2:
                                fprintf(pNota2, "%s", str);
                                break;
                            case 3:
                                fprintf(pNota3, "%s", str);
                                break;
                            case 4:
                                fprintf(pNota4, "%s", str);
                                break;
                            case 5:
                                fprintf(pNota5, "%s", str);
                                break;
                        }
                        strcpy(str, ""); //Reseta a string str para passar pro proximo review
                        fgetc(pRef);
                    }//return divNotas;           // tem que arrumar o return
                }