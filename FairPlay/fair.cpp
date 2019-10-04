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

int main(){

    string test; 
    char buffer1, buffer2, count, length;
    test = "Fanni Bucins";
    count = 1;

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
            printf("%c%c. ", buffer1, buffer2);
            count = 1;
            continue;
        } 

        if (count != 2)
        {
            buffer1 = test[i];
            count++;
        }
        else if(count == 2)
        {
            buffer2 = test[i];
            if(test[i-1] == ' ')
            {
                printf("%c %c.", buffer1, buffer2);
            }
            else printf("%c%c.", buffer1, buffer2);
            
            count = 1;
        }

    }
}
