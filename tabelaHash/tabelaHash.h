struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash* cria_hash(int tamanho);
void libera_hash(Hash* ha);
int valor_string(char *str);
int insereHash_semColisao(Hash* ha, struct aluno al);
int buscaHash_semColisao(Hash* ha, int mat, struct aluno* al);
int insereHash_enderAberto(Hash* ha, struct aluno al);
int buscaHash_enderAberto(Hash* ha, int mat, struct aluno* al);