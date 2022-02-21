#include "vocabulario.h"
#include <stdlib.h>
#include <string.h>
    #define TAM 99000
int main (void){

    voc = fopen("Nota1.txt",'r');  // vocabulario do NOTA 1 
    if (voc == NULL)
        return EXIT_FAILURE;
    while (fgets(line,sizeof line,voc)!=NULL){
            palavras[i] = strdup(line);
            i++;
            numPalavras++;
    }
    int j;
    for(j=0;j<numPalavras;j++)
        printf("\n%s",palavras[j]);

    fclose(voc);

    return EXIT_SUCCESS;

    voc = fopen("Nota2.txt",'r');  // vocabulario do NOTA 2 
    if (voc == NULL)
        return EXIT_FAILURE;
    while (fgets(line,sizeof line,voc)!=NULL){
            palavras[i] = strdup(line);
            i++;
            numPalavras++;
    }
    int j;
    for(j=0;j<numPalavras;j++)
        printf("\n%s",palavras[j]);

    fclose(voc);

    return EXIT_SUCCESS;
    voc = fopen("Nota3.txt",'r');  // vocabulario do NOTA 3 
    if (voc == NULL)
        return EXIT_FAILURE;
    while (fgets(line,sizeof line,voc)!=NULL){
            palavras[i] = strdup(line);
            i++;
            numPalavras++;
    }
    int j;
    for(j=0;j<numPalavras;j++)
        printf("\n%s",palavras[j]);

    fclose(voc);

    return EXIT_SUCCESS;
    voc = fopen("Nota4.txt",'r');  // vocabulario do NOTA 4 
    if (voc == NULL)
        return EXIT_FAILURE;
    while (fgets(line,sizeof line,voc)!=NULL){
            palavras[i] = strdup(line);
            i++;
            numPalavras++;
    }
    int j;
    for(j=0;j<numPalavras;j++)
        printf("\n%s",palavras[j]);

    fclose(voc);

    return EXIT_SUCCESS;
    voc = fopen("Nota5.txt",'r');  // vocabulario do NOTA 5
    if (voc == NULL)
        return EXIT_FAILURE;
    while (fgets(line,sizeof line,voc)!=NULL){
            palavras[i] = strdup(line);
            i++;
            numPalavras++;
    }
    int j;
    for(j=0;j<numPalavras;j++)
        printf("\n%s",palavras[j]);

    fclose(voc);

    return EXIT_SUCCESS;

}
