#include <bits/stdc++.h>
#include "fair.h"
using namespace std;

// class playFair{
// 	private:
// 		map<char, int> indexMatrix
// 		char matrix[5][5];
// 	public:
// 	enkripsi();
// 	dekripsi();
// };

char buffer1, buffer2;

void enkripsi(){
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

void dekripsi(){
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

int main(){

    FILE *in, *out;

    in = fopen ("testCase.txt", "r");
    out = fopen("testCase_Encrypted.txt","a");

    if(!in)
    {
        printf("File txt tidak bisa dibuka.\n");
        exit(0);
    }

    string test; 
    char count, length, mode, pick;
    char tmp=NULL;
    bool hurufBesar1, hurufBesar2;
    //test = "Dtppr Fvksmb Bunoxoy";
    //test = "Box";
    mode = 'e';
    count = 1;
    hurufBesar1 = false;
    hurufBesar2 = false;
    queue <char> ignoredChar;

    // cout << test[2] << "\n";

    generateExtractIndex();
  
    printf("File OK\n");
    // printf("%d\n", extractIndex['d']);

    // printf("%c", extractChar[0][3]);

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
            if(mode == 'e'){
                enkripsi();
            }
            else if(mode == 'd'){
                dekripsi();
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
            if(mode == 'e'){
                enkripsi();
            }
            else if(mode == 'd'){
                dekripsi();
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

    fclose(in);
    fclose(out);
}
