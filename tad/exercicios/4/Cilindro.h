typedef struct cilindro Cilindro;

Cilindro* cCria(float h, float r);

void cLibera(Cilindro *c);

int cAcessa(Cilindro *c, float *h, float *r);

float cArea(Cilindro *c);

float cVolume(Cilindro *c);