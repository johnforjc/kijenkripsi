#include <bits/stdc++.h>
#include "fair.h"
using namespace std;

class playFair{
    FILE *in, *out;
    bool modeEn;
    public:
    void setPathFile(char path[255], bool mode)
    {
        in = fopen (path, "r");
        char pathEn[255], *pch;
        pch= strrchr(path, '.');
        int indexTerminateCopy=pch-path;
        strncpy(pathEn, path, indexTerminateCopy);
        if(mode) strcat(pathEn, "_Encrypted");
        else strcat(pathEn, "_Decrypted");
        strcat(pathEn, pch);
        remove(pathEn);
        out = fopen(pathEn,"a");
        modeEn=mode;
    }

    void enkripsi(char &buffer1, char &buffer2){
        int i1,j1,i2,j2,encrypted_i1,encrypted_i2,encrypted_j1,encrypted_j2;

        if(buffer1 == 'j'){
            buffer1 = 'i';
        }
        if(buffer2 == 'j'){
            buffer2 = 'i';
        }

        i1 = extractIndex[buffer1]/10 - 1;
        j1 = extractIndex[buffer1]%10 - 1;
        i2 = extractIndex[buffer2]/10 - 1;
        j2 = extractIndex[buffer2]%10 - 1;
        //printf("%d=%d=%d=%d\n", i1,j1,i2,j2);

        if(i1==i2 && j1==j2)                    // Hurufnya double (*Dengan asumsi menggunakan play fair modern)
        {
            encrypted_i1 = (i1 + 1)%5;
            encrypted_j1 = (j1 + 1)%5;
            encrypted_i2 = (i2 + 1)%5;
            encrypted_j2 = (j2 + 1)%5;
        }
        else if(i1==i2)                         // Barisnya sama tetapi kolom beda
        {
            encrypted_i1 = i1;
            encrypted_j1 = (j1 + 1)%5;
            encrypted_i2 = i2;
            encrypted_j2 = (j2 + 1)%5;
        }
        else if(j1==j2)                         // Kolomnya sama tetapi baris beda
        {
            encrypted_i1 = (i1 + 1)%5;
            encrypted_j1 = j1;
            encrypted_i2 = (i2 + 1)%5;
            encrypted_j2 = j2;
        }
        else                                    // Beda kolom dan baris
        {
            encrypted_i1 = i1;
            encrypted_j1 = j2;
            encrypted_i2 = i2;
            encrypted_j2 = j1;
        }

        buffer1 = extractChar[encrypted_i1][encrypted_j1];
        buffer2 = extractChar[encrypted_i2][encrypted_j2];
    }

    void dekripsi(char &buffer1, char &buffer2){
        int i1,j1,i2,j2,decrypted_i1,decrypted_i2,decrypted_j1,decrypted_j2;

        i1 = extractIndex[buffer1]/10 - 1;
        j1 = extractIndex[buffer1]%10 - 1;
        i2 = extractIndex[buffer2]/10 - 1;
        j2 = extractIndex[buffer2]%10 - 1;
        //printf("%d=%d=%d=%d\n", i1,j1,i2,j2);

        if(i1==i2 && j1==j2)                    // Hurufnya double (*Dengan asumsi menggunakan play fair modern)
        {
            decrypted_i1 = ((i1 - 1)%5+5)%5;
            decrypted_j1 = ((j1 - 1)%5+5)%5;
            decrypted_i2 = ((i2 - 1)%5+5)%5;
            decrypted_j2 = ((j2 - 1)%5+5)%5;
        }
        else if(i1==i2)                         // Barisnya sama tetapi kolom beda
        {
            decrypted_i1 = i1;
            decrypted_j1 = ((j1 - 1)%5+5)%5;
            decrypted_i2 = i2;
            decrypted_j2 = ((j2 - 1)%5+5)%5;
        }
        else if(j1==j2)                         // Kolomnya sama tetapi baris beda
        {
            decrypted_i1 = ((i1 - 1)%5+5)%5;
            decrypted_j1 = j1;
            decrypted_i2 = ((i2 - 1)%5+5)%5;
            decrypted_j2 = j2;
        }
        else                                    // Beda kolom dan baris
        {
            decrypted_i1 = i1;
            decrypted_j1 = j2;
            decrypted_i2 = i2;
            decrypted_j2 = j1;
        }

        buffer1 = extractChar[decrypted_i1][decrypted_j1];
        buffer2 = extractChar[decrypted_i2][decrypted_j2];

    }

    void readFile()
    {
        char buffer1, buffer2; 
        char count, length, mode, pick;
        char tmp=NULL;
        bool hurufBesar1, hurufBesar2;
        count = 1;
        hurufBesar1 = false;
        hurufBesar2 = false;
        queue <char> ignoredChar;

        generateExtractIndex();
    
        printf("File OK\n");
        do
        {
            pick = getc(in);

            if (pick == EOF && count == 2)
            {
                buffer2 = 'x';

                //cek apakah huruf kecil atau besar
                if(buffer2>64 && buffer2<91){
                    buffer2 = buffer2 + 32;
                    hurufBesar2 = true;
                }

                //enkripsi atau dekripsi
                if(modeEn){
                    enkripsi(buffer1, buffer2);
                }
                else{
                    dekripsi(buffer1, buffer2);
                }

                //kembalikan ke huruf besar (jika huruf besar)
                if(hurufBesar1){
                    buffer1 = buffer1 - 32;
                    hurufBesar1 = false;
                }
                if(hurufBesar2){
                    buffer2 = buffer2 - 32;
                    hurufBesar2 = false;
                }

                fprintf(out,"%c%c", buffer1, buffer2);
                count = 1;
                continue;
            } 

            else if(! ( (pick>64 && pick<91 ) || (pick>96 && pick<123 ) ) )
            {
                if (count == 1) fprintf(out,"%c", pick);
                else ignoredChar.push(pick);
            }  

            else if (count != 2)
            {
                buffer1 = pick;
                //cek apakah huruf kecil atau besar
                if(buffer1>64 && buffer1<91){
                    buffer1 = buffer1 + 32;
                    hurufBesar1 = true;
                }
                count++;
            }
            else if(count == 2)
            {
                buffer2 = pick;
                //cek apakah huruf kecil atau besar
                if(buffer2>64 && buffer2<91){
                    buffer2 = buffer2 + 32;
                    hurufBesar2 = true;
                }

                if(buffer1==buffer2) buffer2='x', tmp=pick;

                //enkripsi atau dekripsi
                //enkripsi atau dekripsi
                if(modeEn){
                    enkripsi(buffer1, buffer2);
                }
                else{
                    dekripsi(buffer1, buffer2);
                }

                //kembalikan ke huruf besar (jika huruf besar)
                if(hurufBesar1){
                    buffer1 = buffer1 - 32;
                    hurufBesar1 = false;
                }
                if(hurufBesar2){
                    buffer2 = buffer2 - 32;
                    hurufBesar2 = false;
                }

                fprintf(out,"%c", buffer1);
                while(!ignoredChar.empty())
                {
                    fprintf(out,"%c", ignoredChar.front());
                    ignoredChar.pop();
                }
                fprintf(out,"%c", buffer2);
                
                count = 1;
            }

            if(tmp!=NULL)
            {
                buffer1=tmp;
                tmp=NULL;
                count=2;
            }

        }
        while(pick != EOF);

        while(!ignoredChar.empty()) fprintf(out,"%c", ignoredChar.front()), ignoredChar.pop();
    }

    void closeFile()
    {
        system("clear");
        fclose(in);
        fclose(out);
        if(modeEn)
        {
            printf("Enskripsi selesai\n");
        }
        else
        {
            printf("Dekripsi selsai\n");
        }
    }
};

void printHelp()
{
    printf("Program ini merupakan program yang digunakan untuk mengenkripsi ataupun mendekripsikan sebuah file\n");
    printf("Program ini menggunakan key \"QUATERVOIS\"");
    printf("Format untuk menjalankan program ini adalah\n");
    printf("\t\t./playFair -mode path\n");
    printf("Mode yang bisa dilakukan adalah:\n");
    printf("\t\t\t-h --help\t\tmode ini digunakan untuk melihat help seperti ini\n");
    printf("\t\t\t-e --Enkripsi\t\tmode untuk mengenkripsikan sebuah teks sesuai dengan path file yang telah ditentukan\n");
    printf("\t\t\t-d --Dekripsi\t\tmode untuk mendekripsikan sebuah teks sesuai dengan path file yang telah ditentukan\n");
}

int main(int argc, char *argv[]){

    char mode[50], path[255];

    if(argc==1) printHelp();
    else{
        strcpy(mode, argv[1]);
        if(!strcmp(mode, "-e") && !strcmp(mode, "-d") && !strcmp(mode, "--Dekripsi") && !strcmp(mode, "--Enkripsi")) printHelp();
        else if(argc<=2)
        {
            printHelp();
        }
        else{
            playFair myPlayFair;
            // strcpy(path, argv[2]);
            int i;
            for(i=0; i<strlen(argv[2]); i++)
            {
                path[i]=argv[2][i];
            }
            path[i]='\0';
            // printf("%s", argv[2]);
            bool myMode;
            if(strcmp(mode, "-e") || strcmp(mode, "--Enkripsi")) myMode=true;
            else myMode=false;
            myPlayFair.setPathFile(path, myMode);
            myPlayFair.readFile();
            myPlayFair.closeFile();
        }
    }

    return 0;
}