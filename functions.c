#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define SIZE 100
#define NUMPROTEINS 64

/**
 * THE PROFESSOR GAVE US THIS FUNCTION TO BE USED
 * THIS IS NOT WRITTEN BY ME
 * IT WAS FROM getCode.C
 **/
char getCode(char protein[3])
{
    char allProteins[NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA", "AGG", "CGA", "CGC", "CGG", "CGU", "GAC", "GAU", "AAC", "AAU", "UGC", "UGU", "GAA", "GAG", "CAA", "CAG", "GGA", "GGC", "GGG", "GGU", "CAC", "CAU", "AUA", "AUC", "AUU", "UUA", "UUG", "CUA", "CUC", "CUG", "CUU", "AAA", "AAG", "AUG", "UUC", "UUU", "CCA", "CCC", "CCG", "CCU", "AGC", "AGU", "UCA", "UCC", "UCG", "UCU", "ACA", "ACC", "ACG", "ACU", "UGG", "UAC", "UAU", "GUA", "GUC", "GUG", "GUU"};
    char allCodes[NUMPROTEINS] = {'A', 'A', 'A', 'A', 'R', 'R', 'R', 'R', 'R', 'R', 'D', 'D', 'N', 'N', 'C', 'C', 'E', 'E', 'Q', 'Q', 'G', 'G', 'G', 'G', 'H', 'H', 'I', 'I', 'I', 'L', 'L', 'L', 'L', 'L', 'L', 'K', 'K', 'M', 'F', 'F', 'P', 'P', 'P', 'P', 'S', 'S', 'S', 'S', 'S', 'S', 'T', 'T', 'T', 'T', 'W', 'Y', 'Y', 'V', 'V', 'V', 'V'};

    for (int i = 0; i < NUMPROTEINS; i++)
    {
        if (strncmp(protein, allProteins[i], 3) == 0)
        {
            return allCodes[i];
        }
    }

    return 'Z';
}

/**
 * @param neu1 The first nucleotide
 * @param neu2 The second nucleotide
 * @return true if neu1 and neu2 are a base pair. false otherwise
 **/
bool isBasePair(char neu1, char neu2)
{
    // Simple checks based on rules of base pairing in DNA
    return (neu1 == 'A' && neu2 == 'T') ||
           (neu1 == 'T' && neu2 == 'A') ||
           (neu1 == 'C' && neu2 == 'G') ||
           (neu1 == 'G' && neu2 == 'C');
}

/**
 * @param strand1 The first strand
 * @param strand2 The second strand
 * @return true if strand1 and strand2 are a dna sequence. false otherwise
 */
bool isItaDnaSequence(char strand1[SIZE], char strand2[SIZE])
{
    int i = 0;

    // Iterate through the strands and check if they are base pairs
    // We can assume that the strands are the same length as given in the assignment description
    while (strand1[i] != '\0')
    {
        if (!isBasePair(strand1[i], strand2[i]))
        {
            return false;
        }

        i++;
    }

    return true;
}

/**
 * @param aStrand The strand to reverse
 */
void reverse(char aStrand[SIZE])
{
    int i = 0;
    int j = 0;

    // temp variable for swapping
    char temp;

    // Gets the length of the strand string
    while (aStrand[i] != '\0')
    {
        i++;
    }

    // i is now the length of the string
    i--;

    // Swap the characters from the start and end of the string
    while (j < i)
    {
        temp = aStrand[i];
        aStrand[i] = aStrand[j];
        aStrand[j] = temp;
        j++;
        i--;
    }
}

/**
 * @param aStrand The strand to complement
 */
void complementIt(char aStrand[SIZE])
{
    int i = 0;

    // Iterate through the strand and replace each character with its complement
    // Rules used for complement were given in requirements/mapping of nucleotides to their complements
    while (aStrand[i] != '\0')
    {
        if (aStrand[i] == 'A')
        {
            aStrand[i] = 'T';
        }
        else if (aStrand[i] == 'T')
        {
            aStrand[i] = 'A';
        }
        else if (aStrand[i] == 'C')
        {
            aStrand[i] = 'G';
        }
        else if (aStrand[i] == 'G')
        {
            aStrand[i] = 'C';
        }

        i++;
    }
}

/**
 * @param aStrand The strand to check
 * @return true if aStrand is a palindrome. false otherwise
 */
bool isItPalindrome(char aStrand[SIZE])
{
    int i = 0;
    int j = 0;

    // Get the length of the string
    while (aStrand[i] != '\0')
    {
        i++;
    }

    i--;

    // Check if the string is a palindrome by comparing the start and end characters as we move towards the middle
    while (j < i)
    {
        if (aStrand[i] != aStrand[j])
        {
            return false;
        }

        j++;
        i--;
    }

    return true;
}

/**
 * @param aStrand The strand to check
 * @return true if aStrand is a dna_palindrome. false otherwise
 */
bool isStrandDnaPalindrome(char aStrand[SIZE])
{
    /*
    The algorithm I went with is to first create a temp variable and store the complement of the strand in it.
    Then, I combine the two strands with the complement being first and check if the combined strand is a palindrome.
    This works because according to the definition the complement reads the same as the original strand backwards.
    So we could either reverse the complement and compare each character or do it the method I chose which was to
    Prepend the original strand to the complement and check if the combined strand is a palindrome.
    */

    char temp[SIZE];
    char combined[SIZE * 2];

    strcpy(temp, aStrand);

    complementIt(temp);

    strcpy(combined, temp);
    strcat(combined, aStrand);

    return isItPalindrome(combined);
}

/**
 * @param aStrand The strand to check
 * @param neu The nucleotide to count
 * @return The number of times neu appears in aStrand
 */
int howMany(char aStrand[SIZE], char neu)
{
    int i = 0;
    int count = 0;

    // Iterate through the strand and count the number of times neu appears
    while (aStrand[i] != '\0')
    {
        if (aStrand[i] == neu)
        {
            count++;
        }
        i++;
    }

    return count;
}

/**
 * @param aStrand The strand to check
 * @param mRna The mRNA to create
 * @return true if aStrand is a dna sequence. false otherwise
 */
void dnaToMrna(char aSeq[SIZE], char mRNA[SIZE])
{
    int i = 0;

    // Uses rules given in assignment description to create the mapping as we iterate through. It then stores the result in mRNA
    while (aSeq[i] != '\0')
    {
        if (aSeq[i] == 'A')
        {
            mRNA[i] = 'U';
        }
        else if (aSeq[i] == 'T')
        {
            mRNA[i] = 'A';
        }
        else if (aSeq[i] == 'C')
        {
            mRNA[i] = 'G';
        }
        else if (aSeq[i] == 'G')
        {
            mRNA[i] = 'C';
        }
        else
        {
            mRNA[i] = aSeq[i];
        }
        i++;
    }

    mRNA[i] = '\0';
}

/**
 * @param aSeq The sequence to translate
 */
void translateDnaToMrnaProteins(char aSeq[SIZE])
{
    char mRNA[SIZE];
    char protein[3];
    char result;
    int i = 0;
    int j = 0;

    printf("DNA: %s\n", aSeq);

    // First convert the dna sequence to mRNA
    dnaToMrna(aSeq, mRNA);

    printf("mRNA: %s, which translates to:\n", mRNA);

    // Iterate through the mRNA and create the proteins
    while (mRNA[i] != '\0')
    {
        // Create the protein by taking 3 characters from the mRNA
        protein[j] = mRNA[i];
        j++;

        // If we have 3 characters, we check if we can create the protein. If not we print an error message
        if (j == 3)
        {
            protein[j] = '\0';

            result = getCode(protein);

            printf("%s : %c\n", protein, result);

            if (result == 'Z')
            {
                printf("The input sequence has an incorrect base\n");
            }

            j = 0;
        }

        i++;
    }
}
