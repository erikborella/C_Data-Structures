typedef struct complexo Complexo;

Complexo* cCriar(float x, float y);

void cLiberar(Complexo *c);

int cAcessar(Complexo *c, float *x, float *y);

int cSomar(Complexo *c1, Complexo *c2, Complexo *res);

int cSubtrair(Complexo *c1, Complexo *c2, Complexo *res);

int cMultiplicar(Complexo *c1, Complexo *c2, Complexo *res);

int cDividir(Complexo *c1, Complexo *c2, Complexo *res);