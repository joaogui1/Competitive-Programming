/*
 * Solução do problema 'Batalha naval' (OBI 2010 - Nível 2, Fase 1)
 *
 * Maurício de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 *
 * Esta solução consiste em dar números aos navios e associar a cada célula o
 * número do navio correspondente a ela. Conta-se também quantas células corres-
 * pondem a um dado navio. Após disso, é possível identificar qual navio foi
 * atingido por um determinado tiro, e também é possível saber se um navio foi
 * completamente destruído (vendo se a quantidade de pedaços restantes do mesmo
 * é igual a zero).
 */

#include <cstdio>

int qtd_navios, n, m;
int num_navio[100][100];
int pedacos_restantes[10000];

/* Este procedimento numera a célula atual com o código do último navio
 * caso ela não esteja numerada e tenta numerar todos os vizinhos recursiva-
 * mente. Ele é chamado na função main, e deve ser lido apenas depois da lei-
 * tura de tudo que antecede a chamada a ele na função main. */
void numera_navios(int l, int c)
{
    /* Verifica se estamos fora do tabuleiro e pára caso sim. */
    if(l < 0 || l > n-1 || c < 0 || c > m-1)
       return;

    if(num_navio[l][c] != -2)
        return;

    num_navio[l][c] = qtd_navios;

    pedacos_restantes[qtd_navios]++;

    numera_navios(l-1, c);
    numera_navios(l, c-1);
    numera_navios(l+1, c);
    numera_navios(l, c+1);
}

int main()
{
    scanf("%d %d\n", &n, &m);

    /* Primeiro, ler a descrição do tabuleiro, guardando a informação na matriz
     * num_navio. Os valores -1 e -2 significam 'água' e 'navio a ser numerado',
     * respectivamente. */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char tmp;

            scanf("%c", &tmp);

            if(tmp == '.')
                num_navio[i][j] = -1;
            else
                num_navio[i][j] = -2;
        }
        scanf("\n");
    }

    /* Agora, vamos numerar todos os navios. Para cada quadrado não ainda
     * numerado (com valor -2), iremos dar um novo número para ele e todos
     * os outros quadrados acessíveis a partir dele. O contador de navios é
     * então incrementado.
     *
     * O nome técnico deste procedimento é 'flood fill'. Apesar de ter
     * usado recursão na implementação abaixo por motivos didáticos,
     * recomenda-se aos competidores familiares com a estrutura de dados
     * denominada 'pilha' que implementem a função numera_navios usando-a,
     * pois esta é mais apropriada do que a recursão para o flood fill. */
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(num_navio[i][j] == -2) {
                pedacos_restantes[qtd_navios] = 0;
                numera_navios(i, j);
                qtd_navios++;
            }

    int k, resp = 0;
    scanf("%d", &k);

    /* Processa os tiros, um a um */
    for(int i = 0; i < k; i++) {
        int l, c;

        scanf("%d %d", &l, &c);

        /* Os tiros começam do 1, logo precisamos subtrair. */
        l--; c--;

        int navio_atingido = num_navio[l][c];

        /* O tiro atingiu algum navio? */
        if(navio_atingido != -1) {
            /* Se sim, o navio tem um pedaço a menos, agora. Note que aqui
             * estamos explorando o fato de que não é possível atirar num
             * lugar já destruído, já que não é possível dar dois tiros no
             * mesmo lugar. */
            pedacos_restantes[navio_atingido]--;

            /* Se o navio não tem mais nenhum pedaço restante, precisamos
             * incrementar a resposta, pois acabamos de destruir um navio
             * por completo */
            if(pedacos_restantes[navio_atingido] == 0) {
                resp++;
            }
        }
    }

    printf("%d\n", resp);
}
