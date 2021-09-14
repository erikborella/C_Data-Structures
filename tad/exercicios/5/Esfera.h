typedef struct esfera Esfera;

Esfera* eCriar(float r);

void eLiberar(Esfera *e);

int eAcessar(Esfera *e, float *r);

float eArea(Esfera *e);

float eVolume(Esfera *e);