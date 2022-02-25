#ifndef BibliotecaGeral_h
#define BibliotecaGeral_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funçoes
    void divNotas(FILE *pRef,FILE *pNota1,FILE *pNota2,FILE *pNota3,FILE *pNota4,FILE *pNota5);
    void vocabulario(FILE *pRef, FILE *pTemp);
    int numerodepalavrasnoarquivo(FILE *fp);
    int contarpalavrasnoarquivo(char *palavra, FILE *fp);
    int FinaldaPalavra (char c);
    int ordenaTFIDF(FILE *fp, int notaNum);
    int contalinhasTFIDF(FILE *TF_IDFfile);

//main geral
    int MenuNum;
    char nomeArquivo[30];
    
    FILE *Reviews = NULL;
    FILE *Nota1 = NULL;
    FILE *Nota2 = NULL;
    FILE *Nota3 = NULL;
    FILE *Nota4 = NULL;
    FILE *Nota5 = NULL;
    FILE *pTemp = NULL;
    FILE *TodosTFIDF = NULL;

//divNotas
    #define TAM 99000
    FILE *pRef, *pNota1, *pNota2, *pNota3, *pNota4, *pNota5;
//vocabulario
    char str[50], voca[50]; //palavra por palavra pegar vacabulario do arquivo
    FILE *pTemp;
    int chec, cont = 0, k;
    char fim[5] = {',', ';', '\n', '.', ':'};
    //void vocabulario();

//tfidf
    //char str[200];
    double contadorPalavraN1, contadorPalavraN2, contadorPalavraN3, contadorPalavraN4, contadorPalavraN5,nPalavrasN1 , nPalavrasN2, nPalavrasN3, nPalavrasN4, nPalavrasN5;
    double nDocComPalavra;
    double TF_IDF1, TF_IDF2, TF_IDF3, TF_IDF4, TF_IDF5, IDF, TF1, TF2, TF3, TF4, TF5, x;
    
    char c;
    char palavra[100];
    int i, count = 0;

//bagunça

struct palavraTFIDF {
    char palavra[100];
    char tfidf[20];
};

void divNotas(FILE *pRef,FILE *pNota1,FILE *pNota2, FILE *pNota3,FILE *pNota4,FILE *pNota5){
    int num;
    char str[TAM], temp[TAM];
    
    pRef = fopen("tripadvisor_hotel_reviews.csv", "r");
    pNota1 = fopen("Nota1.txt", "w");
    pNota2 = fopen("Nota2.txt", "w");
    pNota3 = fopen("Nota3.txt", "w");
    pNota4 = fopen("Nota4.txt", "w");
    pNota5 = fopen("Nota5.txt", "w");

    while ((fscanf(pRef, "%[^,]", temp))!= EOF){ //Armazena o review ate encontrar uma virgula enquanto checa se esta no fim do arquivo
                    strcat(str, temp);
                    fgetc(pRef);             //impede um loop infinito
                    if(strcmp(temp, "  ") == 0){
                        fscanf(pRef, "%d", &num);   //Pega a nota do review
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
                        strcpy(str, "");                    //Reseta a string str para passar pro proximo review
                        fgetc(pRef);
                    }
                }
}

void vocabulario(FILE *pRef, FILE *pTemp) {
    
    pRef = fopen("tripadvisor_hotel_reviews.csv", "r");
    pTemp = fopen("vocabulario.txt", "w+");

    while(fscanf(pRef, "%[^ ]", str) != EOF){                   //pega a palavra do documento de reviews
            k = (strlen(str) - 1);
            for(int i=0; i<5; i++){                             //tira virgula, espaco e ponto final das palavras
                if(str[k] == fim[i]){
                    str[k] = '\0';
                    break;
                }
            }
        if(strlen(str) > 3){                                    //palavras apenas com mais de 3 letras
            if(cont == 0){                                      //caso seja a primeira do vocabulario
                strcat(str, " ");
                fputs(str, pTemp);
                cont++;
            }else {
                chec = 0;
                fseek(pTemp, 0, SEEK_SET);
                while(fscanf(pTemp, "%s", voca) != EOF){        //pega a palavra do vocabulario e compara com a do review
                    if(strcmp(voca, str) == 0){
                        chec = 1;
                        break;
                    }
                    fseek(pTemp, 1, SEEK_CUR);
                }
                if(chec == 0){                                  //passa a palavra para o arquivo do vocabulario
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

int comparaEstrutura(const void* s1, const void* s2) {
       struct palavraTFIDF {
        char palavra[100];
        char tfidf[20];
        };
        struct palavraTFIDF *n1 = (struct palavraTFIDF *)s1;
        struct palavraTFIDF *n2 = (struct palavraTFIDF *)s2;
        int comparaTFIDF = strcmp(n1->tfidf, n2->tfidf);
        return -comparaTFIDF;
}

int ordenaTFIDF(FILE *fp, int notaNum) {
   struct palavraTFIDF {
    char palavra[100];
    char tfidf[20];
    };
    char c;
    int i, j =0, numerodelinhas, numerodepalavras;

    numerodelinhas = contalinhasTFIDF(fp);

    struct palavraTFIDF *NotaX;
    
    NotaX = (struct palavraTFIDF *) malloc(sizeof(char) * 120 * numerodelinhas);
    
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
    
    qsort(NotaX, numerodelinhas, sizeof(struct palavraTFIDF), comparaEstrutura);

    for(i = 0; i < numerodepalavras; i++) {
        printf("%s | %s\n", NotaX[i].palavra, NotaX[i].tfidf);
    }

    free(NotaX);
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

        


#endif