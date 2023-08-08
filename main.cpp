#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    // arv.insere(15);
    // arv.insere(25);
    // arv.insere(10);
    arv.preOrdem();
    cout << endl;
    cout << "O Numero de Nos da arvore e: " << arv.contaNos() << endl;
    cout << "O Numero de Folhas da arvore e: " << arv.contaNosFolhas() << endl;
    cout << "A Altura da Arvore e: " << arv.altura() << endl;
    cout << "O Numero de Impares da arvore e: " << arv.contaImpar() << endl;
    cout << "O Numero de Folhas Impares da arvore e: " << arv.contaFolhaImpar() << endl;
    cout << "Impressao do nivel 2 e: " ;
    arv.imprimeNivel(2);
    cout << endl;
    cout << "A Media do Nivel 2 da arvore e: " << arv.mediaNivel(2) << endl;
    cout << "O Menor valor da arvore e: " << arv.minValor() << endl;
    cout << "O Maior valor da arvore e: " << arv.maxValor() << endl;
    arv.inverte();
    arv.preOrdem();
    cout << endl;
    cout << "O No mais a direita da arvore e: " << arv.noMaisDireita() << endl;
    cout << "O No mais a esquerda da arvore e: " << arv.noMaisEsquerda() << endl;
    cout << "E arvore binaria de busca? " << arv.ehABB() << endl;
    return 0;
}
