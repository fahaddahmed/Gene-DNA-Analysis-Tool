#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define NUMPROTEINS 64

int isBasePair(char nucleotide1, char nucleotide2);
int isItaDnaSequence(char strand1[SIZE], char strand2[SIZE]);
void reverse(char aStrand[SIZE]);
void complementIt(char aStrand[SIZE]);
int isItPalindrome(char aStrand[SIZE]);
int isStrandDnaPalindrome(char aStrand[SIZE]);
int howMany(char aStrand[SIZE], char neu);
void dnaToMrna(char aSeq[SIZE], char mRNA[SIZE]);
void translateDnaToMrnaProteins(char aSeq[SIZE]);

void testIsBasePair();
void testIsItaDnaSequence();
void testReverse();
void testComplementIt();
void testIsItPalindrome();
void testIsStrandDnaPalindrome();
void testHowMany();
void testDnaToMrna();
void testTranslateDnaToMrnaProteins();

int main(int argc, char *argv[])
{
    testIsBasePair();
    printf("\n");
    testIsItaDnaSequence();
    printf("\n");
    testReverse();
    printf("\n");
    testComplementIt();
    printf("\n");
    testIsItPalindrome();
    printf("\n");
    testIsStrandDnaPalindrome();
    printf("\n");
    testHowMany();
    printf("\n");
    testDnaToMrna();
    printf("\n");
    testTranslateDnaToMrnaProteins();
    printf("\n");

    return EXIT_SUCCESS;
}

void testIsBasePair()
{
    printf("Testing isBasePair function\n");

    printf("isBasePair('A', 'T') = %d\n", isBasePair('A', 'T'));
    printf("isBasePair('T', 'A') = %d\n", isBasePair('T', 'A'));
    printf("isBasePair('C', 'G') = %d\n", isBasePair('C', 'G'));
    printf("isBasePair('G', 'C') = %d\n", isBasePair('G', 'C'));

    printf("isBasePair('A', 'C') = %d\n", isBasePair('A', 'C'));
    printf("isBasePair('C', 'A') = %d\n", isBasePair('C', 'A'));
    printf("isBasePair('T', 'G') = %d\n", isBasePair('T', 'G'));
    printf("isBasePair('G', 'T') = %d\n", isBasePair('G', 'T'));
}

void testIsItaDnaSequence()
{
    printf("Testing isItaDnaSequence function\n");

    char strand1[SIZE] = "ATCG";
    char strand2[SIZE] = "TAGC";
    printf("isItaDnaSequence(%s, %s) = %d\n", strand1, strand2, isItaDnaSequence(strand1, strand2));

    strcpy(strand1, "ATCG");
    strcpy(strand2, "TAGT");
    printf("isItaDnaSequence(%s, %s) = %d\n", strand1, strand2, isItaDnaSequence(strand1, strand2));

    strcpy(strand1, "ATCG");
    strcpy(strand2, "TAG");
    printf("isItaDnaSequence(%s, %s) = %d\n", strand1, strand2, isItaDnaSequence(strand1, strand2));
}

void testReverse()
{
    printf("Testing reverse function\n");

    char strand[SIZE] = "ATCG";
    printf("reverse(%s) = ", strand);
    reverse(strand);
    printf("%s\n", strand);
}

void testComplementIt()
{
    printf("Testing complementIt function\n");

    char strand[SIZE] = "ATCG";
    printf("complementIt(%s) = ", strand);
    complementIt(strand);
    printf("%s\n", strand);

    strcpy(strand, "TAGC");
    printf("complementIt(%s) = ", strand);
    complementIt(strand);
    printf("%s\n", strand);
}

void testIsItPalindrome()
{
    printf("Testing isItPalindrome function\n");

    char strand[SIZE] = "ATCG";
    printf("isItPalindrome(%s) = %d\n", strand, isItPalindrome(strand));

    strcpy(strand, "ATCGGCTA");
    printf("isItPalindrome(%s) = %d\n", strand, isItPalindrome(strand));
}

void testIsStrandDnaPalindrome()
{
    printf("Testing isStrandDnaPalindrome function\n");

    char strand[SIZE] = "ATCG";
    printf("isStrandDnaPalindrome(%s) = %d\n", strand, isStrandDnaPalindrome(strand));

    strcpy(strand, "ATCGGCTA");
    printf("isStrandDnaPalindrome(%s) = %d\n", strand, isStrandDnaPalindrome(strand));

    strcpy(strand, "AG");
    printf("isStrandDnaPalindrome(%s) = %d\n", strand, isStrandDnaPalindrome(strand));

    strcpy(strand, "AT");
    printf("isStrandDnaPalindrome(%s) = %d\n", strand, isStrandDnaPalindrome(strand));
}

void testHowMany()
{
    printf("Testing howMany function\n");

    char strand[SIZE] = "ATCG";
    char neu = 'A';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
    neu = 'T';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
    neu = 'C';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
    neu = 'G';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));

    strcpy(strand, "ATCGGCTA");
    neu = 'A';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
    neu = 'T';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
    neu = 'C';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
    neu = 'G';
    printf("howMany(%s, %c) = %d\n", strand, neu, howMany(strand, neu));
}

void testDnaToMrna()
{
    printf("Testing dnaToMrna function\n");

    char strand[SIZE] = "ATCG";
    char mRNA[SIZE];
    dnaToMrna(strand, mRNA);
    printf("dnaToMrna(%s) = %s\n", strand, mRNA);

    strcpy(strand, "ATCGGCTA");
    dnaToMrna(strand, mRNA);
    printf("dnaToMrna(%s) = %s\n", strand, mRNA);

    strcpy(strand, "CATG");
    dnaToMrna(strand, mRNA);
    printf("dnaToMrna(%s) = %s\n", strand, mRNA);
}

void testTranslateDnaToMrnaProteins()
{
    printf("Testing translateDnaToMrnaProteins function\n");

    char strand[SIZE] = "CGTAGGCAT";
    translateDnaToMrnaProteins(strand);
    printf("\n");

    strcpy(strand, "CACGC");
    translateDnaToMrnaProteins(strand);
    printf("\n");

    strcpy(strand, "CAXGC");
    translateDnaToMrnaProteins(strand);
    printf("\n");
}
