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

    i1 = extractIndex[buffer1]/10 - 1;
    j1 = extractIndex[buffer1]%10 - 1;
    i2 = extractIndex[buffer2]/10 - 1;
    j2 = extractIndex[buffer2]%10 - 1;
    //printf("%d=%d=%d=%d\n", i1,j1,i2,j2);

    if(i1==i2 && j1==j2){
        encrypted_i1 = (i1 + 1)%5;
        encrypted_j1 = (j1 + 1)%5;
        encrypted_i2 = (i2 + 1)%5;
        encrypted_j2 = (j2 + 1)%5;
    }
    else if(i1==i2){
        encrypted_i1 = i1;
        encrypted_j1 = (j1 + 1)%5;
        encrypted_i2 = i2;
        encrypted_j2 = (j2 + 1)%5;
    }
    else if(j1==j2){
        encrypted_i1 = (i1 + 1)%5;
        encrypted_j1 = j1;
        encrypted_i2 = (i2 + 1)%5;
        encrypted_j2 = j2;
    }
    else{
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

    if(i1==i2 && j1==j2){
        decrypted_i1 = ((i1 - 1)%5+5)%5;
        decrypted_j1 = ((j1 - 1)%5+5)%5;
        decrypted_i2 = ((i2 - 1)%5+5)%5;
        decrypted_j2 = ((j2 - 1)%5+5)%5;
    }
    else if(i1==i2){
        decrypted_i1 = i1;
        decrypted_j1 = ((j1 - 1)%5+5)%5;
        decrypted_i2 = i2;
        decrypted_j2 = ((j2 - 1)%5+5)%5;
    }
    else if(j1==j2){
        decrypted_i1 = ((i1 - 1)%5+5)%5;
        decrypted_j1 = j1;
        decrypted_i2 = ((i2 - 1)%5+5)%5;
        decrypted_j2 = j2;
    }
    else{
        decrypted_i1 = i1;
        decrypted_j1 = j2;
        decrypted_i2 = i2;
        decrypted_j2 = j1;
    }

    buffer1 = extractChar[decrypted_i1][decrypted_j1];
    buffer2 = extractChar[decrypted_i2][decrypted_j2];
}

int main(){

    string test; 
    char count, length, mode;
    bool hurufBesar1, hurufBesar2;
    //test = "Dtppr Fvksmb Bunoxoy";
    test = "Fanni Bucins Sekali";
    mode = 'e';
    count = 1;
    hurufBesar1 = false;
    hurufBesar2 = false;

    // cout << test[2] << "\n";

    generateExtractIndex();
  
    printf("File OK\n");
    // printf("%d\n", extractIndex['d']);

    // printf("%c", extractChar[0][3]);

    for (int i = 0; i <= test.length(); i++)
    {

        if(test[i] == ' ')
        {
            if (count == 1) printf(" ");
            continue;
        }  
        
        if (i == test.length() && count == 2)
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

            printf("%c%c#", buffer1, buffer2);
            count = 1;
            continue;
        } 

        if (count != 2)
        {
            buffer1 = test[i];
            //cek apakah huruf kecil atau besar
            if(buffer1>64 && buffer1<91){
                buffer1 = buffer1 + 32;
                hurufBesar1 = true;
            }
            count++;
        }
        else if(count == 2)
        {
            buffer2 = test[i];
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

            if(test[i-1] == ' ')
            {
                printf("%c %c.", buffer1, buffer2);
            }
            else printf("%c%c.", buffer1, buffer2);
            
            count = 1;
        }

    }
}
