# Sistema de Controle de Impressora Elgin em C

## Sobre o projeto

Este projeto foi desenvolvido como trabalho acadêmico do curso de Ciência da Computação do UNASP, com o objetivo de criar um sistema de configuração e controle de uma impressora térmica Elgin i9 utilizando a linguagem C.

O sistema utiliza a biblioteca `E1_Impressora01.dll` para realizar a comunicação com a impressora por meio de uma interface interativa no terminal.

## Integrantes do grupo

| Nome | RA |
|---|---|
| Andrew Gabriel de Assis Moreira | 181867 |
| Leonardo da Silva Alves | 194574 |
| Kawan Ribeiro de Oliveira Fernandes | 078360 |

## Tecnologias utilizadas

- Linguagem C
- Visual Studio Code
- GCC (MinGW-w64)
- MSYS2
- Windows API
- E1_Impressora01.dll
- Git e GitHub

## Objetivo

Aplicar os conhecimentos adquiridos durante as aulas de programação no desenvolvimento de um sistema capaz de realizar a comunicação com dispositivos externos, utilizando bibliotecas, funções, estruturas condicionais, estruturas de repetição e manipulação de dados.

O projeto também busca desenvolver habilidades de trabalho em equipe, organização de código e versionamento de software.

## Requisitos

- Sistema operacional Windows.
- Compilador GCC de 64 bits.
- Biblioteca `E1_Impressora01.dll`.
- Impressora compatível para testes físicos.

## Como compilar e executar

Abra a pasta do projeto no Visual Studio Code e execute o seguinte comando no terminal:

```bash
gcc -Wall -Wextra -m64 main.c -o impressora.exe
```

Após a compilação, execute:

```powershell
.\impressora.exe
```

A biblioteca `E1_Impressora01.dll` deve estar localizada na mesma pasta do executável.

## Acesso ao sistema

Credenciais utilizadas para fins acadêmicos:

- Usuário: `admin`
- Senha: `1234`

## Status do projeto

Em desenvolvimento.

## Finalidade acadêmica

Este projeto possui finalidade exclusivamente educacional, buscando relacionar os conhecimentos teóricos adquiridos em sala de aula com situações práticas de desenvolvimento de software.

---

**UNASP — Centro Universitário Adventista de São Paulo**

Ciência da Computação | 2026
