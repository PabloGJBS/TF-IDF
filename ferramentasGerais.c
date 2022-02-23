#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "ferramentasGerais.h"

FILE *abrirarquivo(char *nomearquivo) {
    return fopen(nomearquivo, "r");
}

FILE *escreverarquivo(char *nomearquivo) {
    return fopen(nomearquivo, "w");
}

int Numero(char c) {
    if(c >=  45 && c <= 57){
        return 1;
    }
    return 0;
}

int FinaldaPalavra (char c){
    int final = 0, i;
    char finais[8] = {' ',';','\n', ':', '.', '\\', '/', ',',};
    for(i = 0; i < 8; i++){
        if (c == finais[i]){
            final  = 1;
            break;
        }
    }
    return final;
}

int contarcaracternoarquivo(FILE *nomedoarquivo) {
    int contador = 0, i;
    char palavra[30], c;

    while((c = fgetc(nomedoarquivo)) != EOF){

        if(!Finaldapalavra(c)) {
            i = 0;

            while(!Finaldapalavra(c)) {
                palavra[i] = c;
                c = fgetc(nomedoarquivo);
                i++;
            }

            if(i > 3) {
                i ++;
                contador = contador + i;
            }
        } 
    }
    return contador;
}

int contarpalavrasnoarquivo(char *palavra, FILE *fp) {
    int contador = 0, i;
    char palavranoarquivo[100], c;
    
    fseek(fp, 0, SEEK_SET);
    while((c = fgetc(fp)) != EOF) {
        i = 0;
        
        while(!FinaldaPalavra(c)) {
            palavranoarquivo[i] = c;
            c = fgetc(fp);
            i++;
        }

        if(strcmp(palavra, palavranoarquivo) == 0)
            contador++;

        memset(palavranoarquivo, 0, 100);
    }
    //if(contador > 0)
    //    printf("%d ", contador); 
    return contador;
}

int numerodepalavrasnoarquivo(FILE *fp) {
    int contador = 1;
    char c;

    fseek(fp, 0, SEEK_SET);
    while((c = fgetc(fp)) != EOF) {
        if(FinaldaPalavra(c))
            contador++;
    }
    return contador;
}

int checarpalavrasrepetidas(char *palavra, FILE *fp, long int posicaodapalvra){
    char c, palavra2[50];
    int i;
   
    //printf("%s\n", palavra); 
    fseek(fp, 0, SEEK_SET); 
    //printf("%ld\n", ftell(fp));
    //printf("%ld\n", posicaodapalavra);
    c = fgetc(fp);
    //printf("%c\n", c);
    while(ftell(fp) <  posicaodapalvra) {
        //printf("%c", c);
        //printf("%ld ", ftell(fp));
        if(c == '"') {
            while((c = fgetc(fp)) != '"') {
                i = 0;
                while(!FinaldaPalavra(c)) {
                    palavra2[i] = c;
                    c = fgetc(fp);
                    i++;
                }
                palavra2[i] = ' ';
                //printf("%s", palavra2);
                if(strcmp(palavra,palavra2) == 0)
                     return 1;

                memset(palavra2, 0, 50);
           }
        }

        c = fgetc(fp);
    }
    //printf("%ld ", ftell(fp));
    return 0;
}

int checarpalavrasrepetidas2(char *palavra, FILE *fp){
    char c, palavra2[100];
    int i;

    fseek(fp, 0, SEEK_SET);
    //printf("%ld", ftell(fp)); 
    //printf("%s", palavra);
    while((c = fgetc(fp)) != EOF) {
        i = 0;
        //printf("%c", c);
        while(c != '\n') {
            //printf("%c", c);
            palavra2[i] = c;
            c = fgetc(fp);
            i++;
        } 
        palavra2[i] = '\n';
        //printf("\n"); 
        //printf("%s ", palavra2);
        if(strcmp(palavra, palavra2) == 0)
            return 1;

        memset(palavra2, 0, 100);
    }
        //printf("%ld", ftell(fp)); 
    return 0;
}

int classificar(FILE *Reviews, FILE *Nota1, FILE *Nota2, FILE *Nota3, FILE *Nota4, FILE *Nota5) {
    char buff[20000], c;
    int i;

    c = fgetc(Reviews);
    while (c != EOF) {
        if(c == '"') {
            memset(buff, 0, 20000);
            c = fgetc(Reviews);
            i = 0;
            while (c != '"') { //le todos os caracteres entre aspas
                buff[i] = c;   // adiciona o caracter do arquivo a um vetor
                c = fgetc(Reviews); // passa para o proximo caracter
                i++;
            }
            buff[i] = '\n';
        }

        switch (c) {
            case '1':
                fputs(buff, Nota1);
                break;
            case '2':
                fputs(buff, Nota2);
                break;
            case '3':
                fputs(buff, Nota3);
                break;
            case '4':
                fputs(buff, Nota4);
                break;
            case '5':
                fputs(buff, Nota5);
                break;
            default:
                break;
        }

        c = fgetc(Reviews); //anda para o proximo caractere
    }
    memset(buff, 0, 20000);
    return 0;
}

int contalinhasTFIDF(FILE *TF_IDFfile) {
    int contador = -1;
    char c;
    
    fseek(TF_IDFfile, 0, SEEK_SET);
    while((c = fgetc(TF_IDFfile)) != EOF) {
        if(c == '\n')
            contador++;
    }
    return contador;
}


struct PalavraTFIDF {
    char palavra[100];
    char tfidf[20];
};

int comparaEstrutura(const void* s1, const void* s2) {
    
    struct PalavraTFIDF *n1 = (struct PalavraTFIDF *)s1;
    struct PalavraTFIDF *n2 = (struct PalavraTFIDF *)s2;
    int comparaTFIDF = strcmp(n1->tfidf, n2->tfidf);
    return -comparaTFIDF;
}

int ordenaTFIDF(FILE *fp, int notaNum) {
    char c;
    int i, j =0, numerodelinhas, numerodepalavras;

    numerodelinhas = countLinesTFIDF(fp);

    struct PalavraTFIDF *NotaX;
    
    NotaX = (struct PalavraTFIDF *) malloc(sizeof(char) * 120 * numerodelinhas);
    
    fseek(fp, 0, SEEK_SET);

    printf("Escolha quantas palavras você deseja mostrar: ");
    scanf("%d", &numerodepalavras);
    printf("\nPalavra | TF-IDF\n");

    while((c = fgetc(fp)) != EOF) {
        //printf("%c", c);
        if(c == '"') {
            i = 0;
            c = fgetc(fp);
            //printf("%c", c);
            while(c != '"') {
                //printf("%c", c);
                NotaX[j].palavra[i] = c;
                c = fgetc(fp);
                i++;
            }
            
            c = fgetc(fp);

            switch(notaNum) {
                case 1:
                    c = fgetc(fp);
                    break;
                case 2:
                    for(i=0; i<14; i++) {
                        c = fgetc(fp);
                    }
                    break;
                case 3:
                    for(i=0; i<27; i++) {
                        c = fgetc(fp);
                    }
                    break;
                case 4:
                    for(i=0; i<40; i++) {
                        c = fgetc(fp);
                    }
                    break;
                case 5:
                    for(i=0; i<53; i++) {
                        c = fgetc(fp);
                    }
                    break;
            } 
                    
            for(i = 0; i < 12; i++) { 
                NotaX[j].tfidf[i] = c;
                c = fgetc(fp);
            }
            //printf("%s\n", NotaX[j].tfidf);
            j++; 
        }
    } 
    
    qsort(NotaX, numerodelinhas, sizeof(struct PalavraTFIDF), comparaEstrutura);

    for(i = 0; i < numerodepalavras; i++) {
        printf("%s | %s\n", NotaX[i].palavra, NotaX[i].tfidf);
    }

    free(NotaX);
    return 0;
}


