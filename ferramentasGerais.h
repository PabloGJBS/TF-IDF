#ifndef ferramentasGerais_h
#define ferramentasGerais_h
#include <stdio.h>
    FILE *abrirarquivo(char *nomearquivo);
    FILE *escreverarquivo(char *nomearquivo);
    int Numero(char c);
    int contarcaracternoarquivo(FILE *nomedoarquivo);
    int FinaldaPalavra (char c);
    int Numero(char c);
    int contarcaracternoarquivo(FILE *nomedoarquivo);
    int contarpalavrasnoarquivo(char *palavra, FILE *fp);
    int numerodepalavrasnoarquivo(FILE *fp);
    int checarpalavrasrepetidas(char *palavra, FILE *fp, long int posicaodapalvra);
    int checarpalavrasrepetidas2(char *palavra, FILE *fp);
    int classificar(FILE *Reviews, FILE *Nota1, FILE *Nota2, FILE *Nota3, FILE *Nota4, FILE *Nota5);
    int contalinhasTFIDF(FILE *TF_IDFfile);
    int comparaEstrutura(const void* s1, const void* s2);
    int ordenaTFIDF(FILE *fp, int notaNum);
    char c;
    int i, j =0, numerodelinhas, numerodepalavras;
    

#endif //ferramentasGerais_h