#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "BibliotecaGeral.h"

void menu(){                                                        // função do menu

printf("\n~################### MENU ####################~\n");
printf("\n Escolha o que deseja realizar:                \n");
printf("\n~(1) Ler o Dataset do TripAdvisor e gerar os  ~\n");
printf("\n~    arquivos Nota1,Nota2,Nota3,Nota4 e Nota,5~\n");
printf("\n~(2) Gerar vocabulário                        ~\n");
printf("\n~(3) Gerar os TF-IDFs                         ~\n");
printf("\n~(4) Printar TF-IDF                           ~\n");
printf("\n~(5) SAIR DO PROGRAMA                         ~\n");

}
int main(){
do {                                                                 //casos escolhidos pelo usuario no menu
    menu();
    scanf("%d",&MenuNum);
    switch (MenuNum) {
        case 1: //divNotas
             divNotas(pRef,pNota1,pNota2,pNota3,pNota4,pNota5);
        case 2: //vocabulario
             vocabulario(pRef, pTemp);
        case 3: //tfidf
            pTemp = fopen("vocabulario.txt","r");
            Nota1 = fopen("Nota1.txt","r");
            Nota2 = fopen("Nota2.txt","r");
            Nota3 = fopen("Nota3.txt","r");
            Nota4 = fopen("Nota4.txt","r");
            Nota5 = fopen("Nota5.txt","r");
            TodosTFIDF = fopen("TodosTFIDF.csv","w");

            nPalavrasN1 = numerodepalavrasnoarquivo(Nota1);
            nPalavrasN2 = numerodepalavrasnoarquivo(Nota2);
            nPalavrasN3 = numerodepalavrasnoarquivo(Nota3);
            nPalavrasN4 = numerodepalavrasnoarquivo(Nota4);
            nPalavrasN5 = numerodepalavrasnoarquivo(Nota5);

            printf("Gerando TF-IDF\n");
            fputs("Vocabulario,Nota1,Nota2,Nota3,Nota4,Nota5\n",TodosTFIDF);
                while((c = fgetc(pTemp))!= EOF){
                    i = 0;
                    nDocComPalavra = 0;
                    while(!FinaldaPalavra(c)) {
                                palavra[i] = c;
                                c = fgetc(pTemp);
                                i++;
                    }
                        contadorPalavraN1 = contarpalavrasnoarquivo(palavra, Nota1);  
                        contadorPalavraN2 = contarpalavrasnoarquivo(palavra, Nota2); 
                        contadorPalavraN3 = contarpalavrasnoarquivo(palavra, Nota3); 
                        contadorPalavraN4 = contarpalavrasnoarquivo(palavra, Nota4); 
                        contadorPalavraN5 = contarpalavrasnoarquivo(palavra, Nota5); 
                        if(contadorPalavraN1)
                            nDocComPalavra++;
                        if(contadorPalavraN2)
                            nDocComPalavra++;
                        if(contadorPalavraN3)
                            nDocComPalavra++;
                        if(contadorPalavraN4)
                            nDocComPalavra++;
                        if(contadorPalavraN5)
                            nDocComPalavra++;
                        if(nDocComPalavra==0)
                            nDocComPalavra=1;
                        //TF-IDF
                        x = 5/nDocComPalavra;
                        IDF = log10(x);
                        TF1 = contadorPalavraN1/nPalavrasN1;
                        TF2 = contadorPalavraN1/nPalavrasN2;
                        TF3 = contadorPalavraN1/nPalavrasN3;
                        TF4 = contadorPalavraN1/nPalavrasN4;
                        TF5 = contadorPalavraN1/nPalavrasN5;

                        TF_IDF1 = TF1 * IDF;
                        TF_IDF2 = TF2 * IDF;
                        TF_IDF3 = TF3 * IDF;
                        TF_IDF4 = TF4 * IDF;
                        TF_IDF5 = TF5 * IDF;
                        sprintf(str,"\"%s\",%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",palavra, TF_IDF1, TF_IDF2, TF_IDF3, TF_IDF4, TF_IDF5);
                        fputs(str,TodosTFIDF);

                        memset(palavra,0,100);
        case 4: // print tfidf
            
              if(TodosTFIDF != NULL)
                    fclose(TodosTFIDF);
                TodosTFIDF = fopen("TodosTFIDF.csv","r");

                printf("Nota1,Nota2,Nota3,Nota4,Nota5\n");
                printf("Qual Nota a ser visualizada: ");
                scanf("%s",nomeArquivo);
                if(strcmp(nomeArquivo, "Nota1") == 0) { 
                    ordenaTFIDF(TodosTFIDF, 1);
                    break;
                } else if(strcmp(nomeArquivo, "Nota2") == 0) {
                    ordenaTFIDF(TodosTFIDF, 2);
                    break;
                } else if(strcmp(nomeArquivo, "Nota3") == 0) {
                    ordenaTFIDF(TodosTFIDF, 3);
                    break;
                } else if(strcmp(nomeArquivo, "Nota4") == 0) {
                    ordenaTFIDF(TodosTFIDF, 4);
                    break;
                } else if(strcmp(nomeArquivo, "Nota5") == 0) {
                    ordenaTFIDF(TodosTFIDF, 5);
                    break;
                } else
                    printf("Entrada inválida\n");
                break;

        case 5: 
            fclose(Reviews);
            fclose(Nota1);
            fclose(Nota2);
            fclose(Nota3);
            fclose(Nota4);
            fclose(Nota5);
            fclose(pTemp);
            fclose(TodosTFIDF);
            break;//saida
        default:
            printf("Digite um numero valido!\n");
                break;
    }
} 
}while (MenuNum != 5);

}