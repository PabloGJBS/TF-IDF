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

#endif