#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int minValor();
    int maxValor();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    bool ehABB();
    int minSubArvore(NoArv *p);
    int maxSubArvore(NoArv *p);


  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore
    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    void auxMediaNivel(NoArv *p, int atual, int k, int *nosNivel, int *somaNivel);
    void auxMinValor(NoArv *p, int *menor);
    void auxMaxValor(NoArv *p, int *maior);
    void auxNoMaisEsquerda(NoArv *p, int *valor);
    void auxNoMaisDireita(NoArv *p, int *valor);
    bool auxEhABB(NoArv *p);
//

};

#endif // ARVBIN_H_INCLUDED
