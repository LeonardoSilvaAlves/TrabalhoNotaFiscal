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

static TipoAbrirConexao abrirConexao;
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

    todasFuncoesCarregadas &= buscarFuncao(&abrirConexao, "AbreConexaoImpressora");
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

    return todasFuncoesCarregadas;
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
