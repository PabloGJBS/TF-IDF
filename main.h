#ifndef main_h
#define main_h
#include <stdio.h>
    
    // variaveis gerais
    int MenuNum;
    char nomeArquivo[30];
    vocabulario = fopen("vocabulary.txt", "w+");
    Reviews = fopen("tripadvisor_hotel_reviews.csv", "r");
    FILE *Reviews = NULL;
    FILE *Nota1 = NULL;
    FILE *Nota2 = NULL;
    FILE *Nota3 = NULL;
    FILE *Nota4 = NULL;
    FILE *Nota5 = NULL;
    FILE *vocabulary = NULL;
    FILE *TodosTFIDF = NULL;

    //TF-IDF
    
    //case 2 

    char c;
    char palavra[100];
    int i, count = 0;
    long int posicaoArquivo;

    //case 3

    char str[200];
    double contadorPalavraN1, contadorPalavraN2, contadorPalavraN3, contadorPalavraN4, contadorPalavraN5,nPalavrasN1 , nPalavrasN2, nPalavrasN3, nPalavrasN4, nPalavrasN5;
    double nDocComPalavra;
    double TF_IDF1, TF_IDF2, TF_IDF3, TF_IDF4, TF_IDF5, IDF, TF1, TF2, TF3, TF4, TF5, x;

#endif //main.h