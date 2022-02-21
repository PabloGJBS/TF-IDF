#include <stdio.h>
#include <stdlib.h>

#define TAM 99000
void main(){
    int opcao = 0, num;
    char str[TAM], temp[TAM];
    FILE *pRef, *pNota1, *pNota2, *pNota3, *pNota4, *pNota5;

    pRef = fopen("tripadvisor_hotel_reviews.csv", "r");
    pNota1 = fopen("Nota1.txt", "w");
    pNota2 = fopen("Nota2.txt", "w");
    pNota3 = fopen("Nota3.txt", "w");
    pNota4 = fopen("Nota4.txt", "w");
    pNota5 = fopen("Nota5.txt", "w");

    while(opcao != 5){
        printf("\n**********MENU**********\n1- Ler dataset\n2- Gerar vocabulario\n3- Exibir TF-IDFs\n4- Exibir por nota\n5- Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
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
                    }
                }
                printf("Opcao 1\n");
                break;
            case 2:
                printf("Opcao 2\n");
                break;
            case 3:
                printf("Opcao 3\n");
                break;
            case 4:
                printf("Opcao 4\n");
                break;
            case 5:
                fclose(pNota1);
                fclose(pNota2);
                fclose(pNota3);
                fclose(pNota4);
                fclose(pNota5);
                printf("Opcao 5\n");
                break;
            default:
                printf("Opcao invalida, por favor tente novamente\n");
        }
    }


}

