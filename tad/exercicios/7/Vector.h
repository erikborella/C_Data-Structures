typedef struct vector Vector;

Vector* vCriar();

void vLiberar(Vector *v);

int vGet(Vector *v, int i, int *val);

int vPush(Vector *v, int n);

int vRemove(Vector *v, int i, int *val);

int vSize(Vector *v, int *val);