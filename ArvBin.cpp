#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        int contNosEsq = auxContaNos(p->getEsq());
        int contNosDir = auxContaNos(p->getDir());
        return contNosDir + contNosEsq + 1;
    }
}

int ArvBin::contaNosFolhas()
{
    return auxContaNosFolhas(raiz);
}
int ArvBin::auxContaNosFolhas(NoArv *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else if (p->getEsq() == NULL && p->getDir() == NULL)
    {
        return 1;
    }
    else
    {
        int contFolhasEsq = auxContaNosFolhas(p->getEsq());
        int contFolhasDir = auxContaNosFolhas(p->getDir());
        return contFolhasDir + contFolhasEsq;
    }

}

int ArvBin::altura()
{
    return auxAltura(raiz);
}
int ArvBin::auxAltura(NoArv *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        int alturaEsq = auxAltura(p->getEsq());
        int altraDir = auxAltura(p->getDir());

        return 1 + max(alturaEsq, altraDir);
    }
}

int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}
int ArvBin::auxContaImpar(NoArv *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        int contImparesEsq = auxContaImpar(p->getEsq());
        int contImparesDir = auxContaImpar(p->getDir());

        if(p->getInfo() % 2 != 0)
        {
            return contImparesDir + contImparesEsq + 1;
        }
        else
        {
            return contImparesDir + contImparesEsq;
        }
    }
}

int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}
int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else if(p->getEsq() == NULL && p->getDir() == NULL)
    {
        if(p->getInfo() % 2 != 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int contFolhasImparesEsq = auxContaFolhaImpar(p->getEsq());
        int contFolhasImparesDir = auxContaFolhaImpar(p->getDir());
        return contFolhasImparesDir + contFolhasImparesEsq;
    }
}

void ArvBin::imprimeNivel(int k)
{
    auxImpNivel(raiz, 1, k);
}
void ArvBin::auxImpNivel(NoArv *p, int atual, int k)
{
    if(p != NULL)
    {
        if(atual == k)
        {
            cout << p->getInfo() << " ";
        }

        auxImpNivel(p->getEsq(), atual + 1, k);
        auxImpNivel(p->getDir(), atual + 1, k);
    }
}

float ArvBin::mediaNivel(int k)
{
    int soma = 0, nos = 0;
    auxMediaNivel(raiz, 1, k, &nos, &soma);
    return (float) soma / nos;
}
void ArvBin::auxMediaNivel(NoArv *p, int atual, int k, int *nosNivel, int *somaNivel)
{
    if(p != NULL)
    {
        if(atual == k)
        {
            *nosNivel = *nosNivel + 1;
            *somaNivel = *somaNivel + p->getInfo();
        }
        else
        {
            auxMediaNivel(p->getEsq(), atual + 1, k, nosNivel, somaNivel);
            auxMediaNivel(p->getDir(), atual + 1, k, nosNivel, somaNivel);
        }
    }
}

int ArvBin::minValor()
{
    int menor = raiz->getInfo();
    auxMinValor(raiz, &menor);
    return menor;
}
void ArvBin::auxMinValor(NoArv *p, int *menor)
{
    if(p != NULL)
    {
        if(p->getInfo() < *menor)
        {
            *menor = p->getInfo();
        }

        auxMinValor(p->getDir(), menor);
        auxMinValor(p->getEsq(), menor);

    }
}

int ArvBin::maxValor()
{
    int maior = raiz->getInfo();
    auxMaxValor(raiz, &maior);
    return maior;
}
void ArvBin::auxMaxValor(NoArv *p, int *maior)
{
    if(p != NULL)
    {
        if(p->getInfo() > *maior)
        {
            *maior = p->getInfo();
        }

        auxMaxValor(p->getDir(), maior);
        auxMaxValor(p->getEsq(), maior);
    }
}

void ArvBin::inverte()
{
    auxInverte(raiz);
}
void ArvBin::auxInverte(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getDir() != NULL && p->getEsq() != NULL)
        {
            NoArv *aux = new NoArv();
            aux->setDir(p->getDir());
            p->setDir(p->getEsq());
            p->setEsq(aux->getDir());
        }

        auxInverte(p->getDir());
        auxInverte(p->getEsq());
    }
}

int ArvBin::noMaisDireita()
{
    int valor = 0;
    auxNoMaisDireita(raiz, &valor);
    return valor;
}
void ArvBin::auxNoMaisDireita(NoArv *p, int *valor)
{
    if(p != NULL)
    {
        *valor = p->getInfo();
        auxNoMaisDireita(p->getDir(), valor);
    }
}

int ArvBin::noMaisEsquerda()
{
    int valor = 0;
    auxNoMaisEsquerda(raiz, &valor);
    return valor;
}
void ArvBin::auxNoMaisEsquerda(NoArv *p, int *valor)
{
    if(p != NULL)
    {
        *valor = p->getInfo();
        auxNoMaisEsquerda(p->getEsq(), valor);
    }
}

bool ArvBin::ehABB()
{
    return auxEhABB(raiz);
}
bool ArvBin::auxEhABB(NoArv *p)
{
    int raizIntEsq = 0;
    int raizIntDir = 0;

    if(p == NULL)
    {
        return false;
    }

    auxMaxValor(raiz->getDir(), &raizIntDir);
    auxMaxValor(raiz->getEsq(), &raizIntEsq);

    if(raizIntEsq < getRaiz() && raizIntDir > getRaiz())
    {
        return true;
    }
    else
    {
        return false;
    }
}








