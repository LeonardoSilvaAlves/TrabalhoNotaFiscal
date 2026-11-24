# Controle de Impressora Térmica Elgin em C

## Sobre o projeto

Projeto acadêmico desenvolvido para o curso de Ciência da Computação do UNASP, com o objetivo de controlar uma impressora térmica Elgin utilizando a linguagem C e a biblioteca `E1_Impressora01.dll`.

O programa possui um sistema de autenticação e um menu interativo que permite configurar a conexão e executar diferentes comandos da impressora.

## Integrantes

| Nome | RA |
|---|---|
| Andrew Gabriel de Assis Moreira | 181867 |
| Leonardo da Silva Alves | 194574 |
| Kawan Ribeiro de Oliveira Fernandes | 078360 |

## Tecnologias utilizadas

- Linguagem C
- GCC (MinGW / MSYS2)
- Windows API
- Biblioteca E1_Impressora01.dll
- Git e GitHub

## Funcionalidades

| Opção | Funcionalidade |
|---|---|
| 1 | Configurar conexão |
| 2 | Abrir conexão |
| 3 | Fechar conexão |
| 4 | Imprimir texto |
| 5 | Imprimir QR Code |
| 6 | Imprimir código de barras |
| 7 | Imprimir XML SAT |
| 8 | Imprimir cancelamento SAT |
| 9 | Abrir gaveta Elgin |
| 10 | Abrir gaveta |
| 11 | Emitir sinal sonoro |
| 12 | Cortar papel |
| 0 | Sair do programa |

## Requisitos

- Sistema operacional Windows.
- Compilador GCC de 64 bits.
- Biblioteca E1_Impressora01.dll de 64 bits.
- Impressora térmica Elgin i8 ou i9.
- Arquivos XMLSAT.xml e CANC_SAT.xml para os testes de impressão SAT.

A DLL e os arquivos XML devem estar na raiz do projeto.

## Como compilar

Abra o terminal na pasta do projeto e execute:

```powershell
gcc -Wall -Wextra -m64 main.c -o impressora.exe
```

## Como executar

```powershell
.\impressora.exe
```

## Credenciais de acesso

- **Usuário:** admin
- **Senha:** 1234

O sistema permite até três tentativas de autenticação.

## Configuração padrão da impressora

| Parâmetro | Valor |
|---|---|
| Tipo de conexão | 1 (USB) |
| Modelo | i9 |
| Porta | USB |
| Parâmetro adicional | 0 |

## Status do projeto

- Desenvolvimento concluído.
- Compilação realizada com sucesso.

## Finalidade acadêmica

O projeto tem como finalidade aplicar os conhecimentos adquiridos em programação C, utilizando funções, estruturas condicionais, laços de repetição, ponteiros, manipulação de arquivos e integração com bibliotecas externas.

**UNASP — Ciência da Computação | 2026**
