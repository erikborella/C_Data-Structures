typedef struct cubo Cubo;

Cubo* cCria(float d);

void cLibera(Cubo* c);

int cTamanho(Cubo* c, float *tam);

int cArea(Cubo* c, float *a);

int cVolume(Cubo* c, float *v);