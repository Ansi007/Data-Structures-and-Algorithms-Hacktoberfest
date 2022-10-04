#include<bits/stdc++.h>

using namespace std;

void cleanWord(string &word){
        string newWord = "";
        int i = 0;
        for(i = 0; i < word.size(); i++){
            if((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))
            newWord += word[i];
        }
        word = newWord;
    }
int _hashMidleSqure(string fruit){
    int size = fruit.size();
    int middle = size/2;
    return middle*middle;
}
int _hashSumASCII(string fruit) {
    cleanWord(fruit); // to remove any special char from string
    int sum = 0;
    for (int i = 0 ; i < fruit.length()- (fruit.size()/2) + 2; i++) {
        sum += fruit[i];
    }
    return sum;
}

int main() {
    freopen ("input.txt","r",stdin);
    string fruit;
    int max = -1;
    while (cin >> fruit){
        int ASCII_SUM = _hashSumASCII(fruit);
        int Middle_SQUAR = _hashMidleSqure(fruit);
        if(ASCII_SUM > max)
            max = ASCII_SUM;
        cout << fruit << " = " << ASCII_SUM << '\n';
    }
    cout << "max = " << max << '\n';
}