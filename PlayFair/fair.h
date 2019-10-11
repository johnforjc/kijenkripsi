#ifndef FAIR_H
#define FAIR_H

#include <bits/stdc++.h>
using namespace std;
map <char, int> extractIndex; 
char extractChar[5][5]={{'q', 'u', 'a', 't', 'e'},
                            {'r', 'v', 'o', 'i', 's'},
                            {'b', 'c', 'd', 'f', 'g'},
                            {'h', 'k', 'l', 'm', 'n'},
                            {'p', 'w', 'x', 'y', 'z'}};
void generateExtractIndex(){
    extractIndex.insert(pair<char, int>('q', 11));
    extractIndex.insert(pair<char, int>('u', 12));
    extractIndex.insert(pair<char, int>('a', 13));
    extractIndex.insert(pair<char, int>('t', 14));
    extractIndex.insert(pair<char, int>('e', 15));
    extractIndex.insert(pair<char, int>('r', 21));
    extractIndex.insert(pair<char, int>('v', 22));
    extractIndex.insert(pair<char, int>('o', 23));
    extractIndex.insert(pair<char, int>('i', 24));
    extractIndex.insert(pair<char, int>('s', 25));
    extractIndex.insert(pair<char, int>('b', 31));
    extractIndex.insert(pair<char, int>('c', 32));
    extractIndex.insert(pair<char, int>('d', 33));
    extractIndex.insert(pair<char, int>('f', 34));
    extractIndex.insert(pair<char, int>('g', 35));
    extractIndex.insert(pair<char, int>('h', 41));
    extractIndex.insert(pair<char, int>('k', 42));
    extractIndex.insert(pair<char, int>('l', 43));
    extractIndex.insert(pair<char, int>('m', 44));
    extractIndex.insert(pair<char, int>('n', 45));
    extractIndex.insert(pair<char, int>('p', 51));
    extractIndex.insert(pair<char, int>('w', 52));
    extractIndex.insert(pair<char, int>('x', 53));
    extractIndex.insert(pair<char, int>('y', 54));
    extractIndex.insert(pair<char, int>('z', 55));
}

#endif
