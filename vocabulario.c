#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "vocabulario.h"
int Vocabulario() {
    
    pRef = fopen("tripadvisor_hotel_reviews.csv", "r");
    pTemp = fopen("vocabulario.txt", "w+");

    while(fscanf(pRef, "%[^ ]", str) != EOF){ //pega a palavra do documento de reviews
            k = (strlen(str) - 1);
            for(int i=0; i<5; i++){ //tira virgula, espaco e ponto final das palavras
                if(str[k] == fim[i]){
                    str[k] = '\0';
                    break;
                }
            }
        if(strlen(str) > 3){ //palavras apenas com mais de 3 letras
            if(cont == 0){ //caso seja a primeira do vocabulario
                strcat(str, " ");
                fputs(str, pTemp);
                cont++;
            }else {
                chec = 0;
                fseek(pTemp, 0, SEEK_SET);
                while(fscanf(pTemp, "%s", voca) != EOF){ //pega a palavra do vocabulario e compara com a do review
                    if(strcmp(voca, str) == 0){
                        chec = 1;
                        break;
                    }
                    fseek(pTemp, 1, SEEK_CUR);
                }
                if(chec == 0){ //passa a palavra para o arquivo do vocabulario
                    strcat(str, " ");
                    fputs(str, pTemp);
                    cont++;
                }
            }
        }
        fgetc(pRef);
    }
    fclose(pTemp);
    fclose(pRef);
    return vocabulario;
}



