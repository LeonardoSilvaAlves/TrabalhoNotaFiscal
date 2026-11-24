#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*
Grupo de configuração da Impressora Elgin na linguagem C, usando a DLL E1_Impressora01.dll.
 *
- 		================ GRUPO: ANDREW GABRIEL DE ASSIS MOREIRA RA: 181867
								              LEONARDO DA SILVA ALVES RA: 194574
                              KAWAN RIBEIRO DE OLIVEIRA FERNANDES RA : 078360    
*/

/* TIPOS DAS FUNÇÕES */
typedef int (*TipoAbrirConexao)(
    int tipoConexao,
    const char *modeloImpressora,
    const char *portaConexao,
    int parametro
);

typedef int (*TipoFecharConexao)(void);

typedef int (*TipoImprimirTexto)(
    const char *texto,
    int posicao,
    int estilo,
    int tamanho
);

typedef int (*TipoCortarPapel)(int avancoPapel);

typedef int (*TipoImprimirQRCode)(
    const char *dadosQRCode,
    int tamanho,
    int nivelCorrecao
);

typedef int (*TipoImprimirCodigoBarras)(
    int tipoCodigo,
    const char *dadosCodigo,
    int altura,
    int largura,
    int HRI
);

typedef int (*TipoAvancarPapel)(int quantidadeLinhas);
typedef int (*TipoConsultarStatus)(int parametroStatus);

typedef int (*TipoAbrirGavetaElgin)(
    int pino,
    int tempoInicial,
    int tempoFinal
);

typedef int (*TipoAbrirGaveta)(
    int pino,
    int tempoInicial,
    int tempoFinal
);

typedef int (*TipoEmitirSom)(
    int quantidadeToques,
    int tempoInicio,
    int tempoFim
);

typedef int (*TipoAtivarModoPagina)(void);
typedef int (*TipoLimparBufferPagina)(void);
typedef int (*TipoImprimirPagina)(void);
typedef int (*TipoModoPadrao)(void);

typedef int (*TipoPosicaoHorizontal)(int posicaoHorizontal);
typedef int (*TipoPosicaoVertical)(int posicaoVertical);

typedef int (*TipoImprimirXMLSAT)(
    const char *conteudoXML,
    int parametro
);

typedef int (*TipoImprimirCancelamentoSAT)(
    const char *conteudoXML,
    const char *chaveQRCode,
    int parametro
);

/* PONTEIROS DAS FUNÇÕES */

static TipoAbrirConexao fnAbrirConexao;
static TipoFecharConexao fecharConexao;
static TipoImprimirTexto imprimirTexto;
static TipoCortarPapel cortarPapel;
static TipoImprimirQRCode imprimirQRCode;
static TipoImprimirCodigoBarras imprimirCodigoBarras;
static TipoAvancarPapel avancarPapel;
static TipoConsultarStatus consultarStatus;
static TipoAbrirGavetaElgin abrirGavetaElgin;
static TipoAbrirGaveta abrirGaveta;
static TipoEmitirSom emitirSom;
static TipoAtivarModoPagina ativarModoPagina;
static TipoLimparBufferPagina limparBufferPagina;
static TipoImprimirPagina imprimirPagina;
static TipoModoPadrao modoPadrao;
static TipoPosicaoHorizontal posicaoHorizontal;
static TipoPosicaoVertical posicaoVertical;
static TipoImprimirXMLSAT imprimirXMLSAT;
static TipoImprimirCancelamentoSAT imprimirCancelamentoSAT;

/* BIBLIOTECA DA IMPRESSORA */
static HMODULE biblioteca = NULL;

/* BUSCA UMA FUNÇÃO DENTRO DA DLL */
static int buscarFuncao(void *enderecoDestino, const char *nomeDaFuncao) {

    FARPROC enderecoFuncao = GetProcAddress(biblioteca, nomeDaFuncao);

    if (enderecoFuncao == NULL) {
        printf("Comando '%s' nao encontrado na DLL.\n", nomeDaFuncao);
        return 0;
    }

    *(FARPROC *)enderecoDestino = enderecoFuncao;

    return 1;
}

/* CARREGA A DLL E SUAS FUNÇÕES */
static int carregarBiblioteca(void) {

    biblioteca = LoadLibraryA("E1_Impressora01.dll");

    if (biblioteca == NULL) {
        printf("Nao foi possivel carregar a DLL.\n");
        return 0;
    }

    int todasFuncoesCarregadas = 1;

    todasFuncoesCarregadas &= buscarFuncao(&fnAbrirConexao, "AbreConexaoImpressora");
    todasFuncoesCarregadas &= buscarFuncao(&fecharConexao, "FechaConexaoImpressora");
    todasFuncoesCarregadas &= buscarFuncao(&imprimirTexto, "ImpressaoTexto");
    todasFuncoesCarregadas &= buscarFuncao(&cortarPapel, "Corte");
    todasFuncoesCarregadas &= buscarFuncao(&imprimirQRCode, "ImpressaoQRCode");
    todasFuncoesCarregadas &= buscarFuncao(&imprimirCodigoBarras, "ImpressaoCodigoBarras");
    todasFuncoesCarregadas &= buscarFuncao(&avancarPapel, "AvancaPapel");
    todasFuncoesCarregadas &= buscarFuncao(&consultarStatus, "StatusImpressora");
    todasFuncoesCarregadas &= buscarFuncao(&abrirGavetaElgin, "AbreGavetaElgin");
    todasFuncoesCarregadas &= buscarFuncao(&abrirGaveta, "AbreGaveta");
    todasFuncoesCarregadas &= buscarFuncao(&emitirSom, "SinalSonoro");
    todasFuncoesCarregadas &= buscarFuncao(&ativarModoPagina, "ModoPagina");
    todasFuncoesCarregadas &= buscarFuncao(&limparBufferPagina, "LimpaBufferModoPagina");
    todasFuncoesCarregadas &= buscarFuncao(&imprimirPagina, "ImprimeModoPagina");
    todasFuncoesCarregadas &= buscarFuncao(&modoPadrao, "ModoPadrao");
    todasFuncoesCarregadas &= buscarFuncao(&posicaoHorizontal, "PosicaoImpressaoHorizontal");
    todasFuncoesCarregadas &= buscarFuncao(&posicaoVertical, "PosicaoImpressaoVertical");
    todasFuncoesCarregadas &= buscarFuncao(&imprimirXMLSAT, "ImprimeXMLSAT");
    todasFuncoesCarregadas &= buscarFuncao(&imprimirCancelamentoSAT, "ImprimeXMLCancelamentoSAT");

    if (!todasFuncoesCarregadas) {
    FreeLibrary(biblioteca);
    biblioteca = NULL;
    return 0;
}

return 1;
}

/* VARIÁVEIS DO PROGRAMA */
static int impressoraConectada = 0;
static int tipoConexao = 1;
static char modeloImpressora[50] = "i9";
static char portaConexao[50] = "USB";
static int configuracao = 0;

/* CHAVE DO QR CODE */
static const char *CHAVE_QRCODE =
    "Q5DLkpdRijIRGY6YSSNsTWK1TztHL1vD0V1Jc4spo/CEUqICEb9SFy82ym8EhBRZjbh3btsZhF+sjHqEMR159i4agru9x6KsepK/"
    "q0E2e5xlU5cv3m1woYfgHyOkWDNcSdMsS6bBh2Bpq6s89yJ9Q6qh/J8YHi306ce9Tqb/drKvN2XdE5noRSS32TAWuaQEVd7u+"
    "TrvXlOQsE3fHR1D5f1saUwQLPSdIv01NF6Ny7jZwjCwv1uNDgGZONJdlTJ6p0ccqnZvuE70aHOI09elpjEO6Cd+orI7XHHrFCwhFhAcbalc+"
    "ZfO5b/+vkyAHS6CYVFCDtYR9Hi5qgdk31v23w==";

/* CAPTURA ENTRADA DO USUÁRIO */
static void capturarEntrada(
    const char *mensagemUsuario,
    char *textoDigitado,
    int limiteCaracteres
) {

    printf("%s", mensagemUsuario);

    if (fgets(textoDigitado, limiteCaracteres, stdin) == NULL) {
        textoDigitado[0] = '\0';
        return;
    }

    textoDigitado[strcspn(textoDigitado, "\r\n")] = '\0';
}

/* SISTEMA DE LOGIN 
    Usuario: admin
    Senha: 1234
*/
static int fazerLogin(void) {

    char usuario[50];
    char senha[50];
    int tentativas = 0;

    while (tentativas < 3) {

        printf("\n===== SISTEMA DE LOGIN =====\n");

        capturarEntrada("Usuario: ", usuario, 50);
        capturarEntrada("Senha: ", senha, 50);

        if (strcmp(usuario, "admin") == 0 &&
            strcmp(senha, "1234") == 0) {

            printf("\nLogin realizado com sucesso!\n");
            return 1;

        } else {

            tentativas++;

            printf("\nUsuario ou senha incorretos!\n");
            printf("Tentativas restantes: %d\n", 3 - tentativas);
        }
    }

    printf("\nAcesso bloqueado!\n");
    return 0;
}

/* MENU PRINCIPAL */
static void exibirMenu(void) {

    printf("\n====================================\n");
    printf("       IMPRESSORA ELGIN I9\n");
    printf("====================================\n");
    printf("1 - Configurar conexao\n");
    printf("2 - Abrir conexao\n");
    printf("3 - Fechar conexao\n");
    printf("4 - Imprimir texto\n");
    printf("5 - Imprimir QR Code\n");
    printf("6 - Imprimir codigo de barras\n");
    printf("7 - Imprimir XML SAT\n");
    printf("8 - Imprimir cancelamento SAT\n");
    printf("9 - Abrir gaveta Elgin\n");
    printf("10 - Abrir gaveta\n");
    printf("11 - Emitir sinal sonoro\n");
    printf("12 - Cortar papel\n");
    printf("0 - Sair do programa\n");
    printf("====================================\n");
}

/* CONFIGURACAO DA CONEXAO */
static void configurarConexao(void) {

    char entrada[50];

    printf("\n===== CONFIGURAR CONEXAO =====\n");

    /* DEFINE O TIPO DE CONEXAO */
    capturarEntrada("Tipo de conexao: ", entrada, 50);
    tipoConexao = atoi(entrada);

    /* DEFINE O MODELO DA IMPRESSORA */
    capturarEntrada("Modelo da impressora: ", modeloImpressora, 50);

    /* DEFINE A PORTA DA IMPRESSORA */
    capturarEntrada("Porta de conexao: ", portaConexao, 50);

    /* DEFINE O PARAMETRO DA CONEXAO */
    capturarEntrada("Parametro de configuracao: ", entrada, 50);
    configuracao = atoi(entrada);

    printf("\nConfiguracao salva!\n");

    printf("Tipo de conexao: %d\n", tipoConexao);
    printf("Modelo: %s\n", modeloImpressora);
    printf("Porta: %s\n", portaConexao);
    printf("Parametro: %d\n", configuracao);
}


/*FUNÇÃO MAIN PARA PODER RODAR O CÓDIGO*/

int main(void) {

    char opcao[10];

    /* VERIFICA O LOGIN */
    if (fazerLogin() == 0) {
        return 1;
    }

    /* CARREGA A BIBLIOTECA DA IMPRESSORA */
    if (carregarBiblioteca() == 0) {
        return 1;
    }

    printf("DLL carregada com sucesso!\n");

    /* LOOP MENU PRINCIPAL */
    while (1) {

        exibirMenu();

        capturarEntrada("Escolha uma opcao: ", opcao, 10);

        /* ENCERRA O PROGRAMA */
        if (strcmp(opcao, "0") == 0) {

            printf("\nEncerrando programa...\n");
            break;

        /* CONFIGURA A CONEXAO DA IMPRESSORA */
        } else if (strcmp(opcao, "1") == 0) {

            configurarConexao();

        } else {

            printf("\nOpcao ainda nao implementada!\n");
        }
    }

    /* LIBERA A DLL ANTES DE ENCERRAR O PROGRAMA */
    FreeLibrary(biblioteca);

    return 0;
}