#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <bits/stdc++.h>
using namespace std;
map <char, int> extractIndex; 
char extractChar[5][5]={{'q', 'u', 'a', 't', 'e'},
                            {'r', 'v', 'o', 'i', 's'},
                            {'b', 'c', 'd', 'f', 'g'},
                            {'h', 'k', 'l', 'm', 'n'},
                            {'p', 'w', 'x', 'y', 'z'}};
void generateExtractIndex(){
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            extractIndex.insert(pair<char, int>(extractChar[i][j], (i+1)*10+(j+1)));
        }
    }
}

void printHelp()
{
    printf("Program ini merupakan program yang digunakan untuk mengenkripsi ataupun mendekripsikan sebuah file\n");
    printf("Program ini menggunakan key \"QUATERVOIS\"");
    printf("Format untuk menjalankan program ini adalah\n");
    printf("\t\t./playFair -mode path\n");
    printf("Mode yang bisa dilakukan adalah:\n");
    printf("\t\t\t--h -help\t\tmode ini digunakan untuk melihat help seperti ini\n");
    printf("\t\t\t--e -Enkripsi\t\tmode untuk mengenkripsikan sebuah teks sesuai dengan path file yang telah ditentukan\n");
    printf("\t\t\t--d -Dekripsi\t\tmode untuk mendekripsikan sebuah teks sesuai dengan path file yang telah ditentukan\n");
}

#endif
