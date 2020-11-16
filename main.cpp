#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

#define MIN(x,y) ((x) < (y) ? (x) : (y)) 

class Compara{
    public:
        char palavra1[20];
        char palavra2[20];
        char palavranova[20];

        void fraseToPalavra(string[]); 
        void leArquivo(string, string[]);
        void valida(char[], char[]);
};


int main() {
    Compara compara;
    string frase[2];

    compara.leArquivo("Arquivo01.txt", frase);
    compara.fraseToPalavra(frase);
    compara.valida(compara.palavra1, compara.palavra2);

    return 0;
}


void Compara::fraseToPalavra(string frase[]){
    strcpy(palavranova, frase[0].c_str());
    strcpy(palavra1, frase[0].c_str());
    strcpy(palavra2, frase[1].c_str());
}

void Compara::leArquivo(string nameArq, string Frase[]){
    int i=0;
    string linha;
    ifstream inFile (nameArq);
    if(!inFile.is_open()) cout<<"ERRO AO ABRIR O ARQUIVO: "<<nameArq;
    else{
        while (!inFile.eof() ){
            getline(inFile, linha);
            Frase[i++]=linha;
        }
        inFile.close();
    } 
 }

 void Compara::valida(char p1[], char p2[]){
    int i, j,k=0, l1, l2, t, track;
    int dist[50][50];

    l1 = strlen(p1);
    l2 = strlen(p2);

    for(i=0;i<=l1;i++)
        dist[0][i] = i;

    for(j=0;j<=l2;j++) 
        dist[j][0] = j;

    cout<<palavranova<<" -> ";
    
    for (j=1;j<=l1;j++){
        for(i=1;i<=l2;i++){
            if(p1[i-1] == p2[j-1]){
                track = 0;
            }else{
                track = 1;
            }
        t = MIN((dist[i-1][j]+1),(dist[i][j-1]+1));
        dist[i][j] = MIN(t,(dist[i-1][j-1]+track));
        }
        palavranova[k] = p2[k];
        k++;
        cout<<palavranova<<" -> ";
    }

    palavranova[4] = p2[4];
    cout<<palavranova<<endl;
    cout<<"A distancia de Levinstein é: "<<dist[l2][l1];
 }