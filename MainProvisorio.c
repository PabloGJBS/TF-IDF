#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "main.h"
//#include "BibliotecaDoProjeto"

#define TAM 99000 //teste

void menu(){

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
    
do {
    menu();
    scanf("%d",&MenuNum);
    switch (MenuNum) {
        case 1:
            printf("./tripadvisor_hotel_reviews.csv\n");
            printf("Digite o nome do arquivo: ");
            scanf("%s",nomeArquivo);

            Reviews = abreArquivo(nomeArquivo);

            if(Reviews == NULL){
                printf("Erro ao ler o arquivo");
                break;
            }

            Nota1 = fopen("Nota1.txt","w");
            Nota2 = fopen("Nota2.txt","w");
            Nota3 = fopen("Nota3.txt","w");
            Nota4 = fopen("Nota4.txt","w");
            Nota5 = fopen("Nota5.txt","w");

            separaPelaNota(Reviews, Nota1, Nota2, Nota3, Nota4, Nota5);

            printf("Todos os arquivos foram gerados com sucesso\n");
            break;
        case 2:
            printf("Gerando o vocabulario");
            if(Reviews != NULL)
                fclose(Reviews);
            if(vocabulario !=NULL)
                fclose(vocabulario);
            while((c = fgetc(Reviews))!= EOF){
                if (c == '"'){
                    i = 0;
                    posicaoArquivo = ftell(vocabulario);
                    while(!isEndWord(c)){
                        palavra[i]=c;
                        c = fgetc(Reviews);
                        i++;
                    }
                palavra[i] = '\n';
                    if(i >3){
                        if(!BuscaPorRepetidas2(palavra,vocabulario)){
                            fputs(palavra,vocabulario);
                            count ++;
                        }
                    }
                    memset(palavra,0,100);
                }
            }
            break;
        case 3:
            if(vocabulario != NULL)
                fclose(vocabulario);
            if(Nota1 !=NULL){
                fclose(Nota1);
                fclose(Nota2); 
                fclose(Nota3); 
                fclose(Nota4); 
                fclose(Nota5);
            }  
            vocabulario = fopen("vocabulario.txt","r");
            Nota1 = fopen("Nota1.txt","r");
            Nota2 = fopen("Nota2.txt","r");
            Nota3 = fopen("Nota3.txt","r");
            Nota4 = fopen("Nota4.txt","r");
            Nota5 = fopen("Nota5.txt","r");
            TodosTFIDF = fopen("TodosTFIDF.csv","w");

            nPalavrasN1 = numberOfWordsInFile(Nota1);
            nPalavrasN2 = numberOfWordsInFile(Nota2);
            nPalavrasN3 = numberOfWordsInFile(Nota3);
            nPalavrasN4 = numberOfWordsInFile(Nota4);
            nPalavrasN5 = numberOfWordsInFile(Nota5);

            print("Gerando TF-IDF\n");
            fputs("Vocabulario,Nota1,Nota2,Nota3,Nota4,Nota5\n",TodosTFIDF);
                while((c = fgetc(vocabulario))!= EOF){
                    i = 0;
                    nDocComPalavra = 0;
                    while(!isEndWord(c)) {
                                palavra[i] = c;
                                c = fgetc(vocabulary);
                                i++;
                    }
                        contadorPalavraN1 = wordCountInFile(palavra, Nota1);  
                        contadorPalavraN2 = wordCountInFile(palavra, Nota2); 
                        contadorPalavraN3 = wordCountInFile(palavra, Nota3); 
                        contadorPalavraN4 = wordCountInFile(palavra, Nota4); 
                        contadorPalavraN5 = wordCountInFile(palavra, Nota5); 
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
                }
                break;
            case 4:

                if(TodosTFIDF != NULL)
                    fclose(TodosTFIDF);
                TodosTFIDF = fopen("TodosTFIDF.csv","r");

                printf("Nota1,Nota2,Nota3,Nota4,Nota5\n");
                printf("Qual Nota a ser visualizada: ");
                scanf("%s",nomeArquivo);
                if(strcmp(nomeArquivo, "Nota1") == 0) { 
                    sortTFIDF(TodosTFIDF, 1);
                    break;
                } else if(strcmp(nomeArquivo, "Nota2") == 0) {
                    sortTFIDF(TodosTFIDF, 2);
                    break;
                } else if(strcmp(nomeArquivo, "Nota3") == 0) {
                    sortTFIDF(TodosTFIDF, 3);
                    break;
                } else if(strcmp(nomeArquivo, "Nota4") == 0) {
                    sortTFIDF(TodosTFIDF, 4);
                    break;
                } else if(strcmp(nomeArquivo, "Nota5") == 0) {
                    sortTFIDF(TodosTFIDF, 5);
                    break;
                } else
                    printf("Entrada inválida\n");
                break;
            case 5:
                break;
            default:
                printf("Digite um numero valido!\n");
                break;
        }   

    } while (MenuNum != 0);

    fclose(Reviews);
    fclose(Nota1);
    fclose(Nota2);
    fclose(Nota3);
    fclose(Nota4);
    fclose(Nota5);
    fclose(vocabulary);
    fclose(TodosTFIDF);
    return 0;
}

