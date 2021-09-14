typedef struct conjunto Conjunto;

Conjunto* cCriar();

void cLiberar(Conjunto *c);

int cPertence(Conjunto *c, int val);

int cInserir(Conjunto *c, int val);

int cRemover(Conjunto *c, int i, int *val);

int cInterseccao(Conjunto *c1, Conjunto *c2, Conjunto **res);

int cDiferenca(Conjunto *c1, Conjunto *c2, Conjunto **res);

int cUniao(Conjunto *c1, Conjunto *c2, Conjunto **res);

int cMenor(Conjunto *c, int *val);

int cMaior(Conjunto *c, int *val);

int cTamanho(Conjunto *c, int *val);

int cEhIgual(Conjunto *c1, Conjunto *c2);

int cEhVazio(Conjunto *c);
