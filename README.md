[README.md](https://github.com/user-attachments/files/32526067/README.md)
# Projeto-estruturas-de-repeti-o
desafio-monitoramento de temperatura
# Desafio - Monitoramento de Temperatura

## 1. Identificação

- **Aluno:** Matheus de Lima
- **Disciplina:** Programação em C
- **Professora:** Profa. Karla Sartin
- **Título:** Sistema de Monitoramento de Temperatura

## 2. Objetivo

O projeto tem como objetivo desenvolver um programa em linguagem C capaz de monitorar uma sequência de temperaturas, comparando cada leitura com um limite definido pelo usuário. O sistema registra as leituras e apresenta um relatório final com média, maior temperatura, menor temperatura, quantidade de leituras, quantidade de temperaturas acima do limite e percentual acima do limite.

O monitoramento é encerrado automaticamente quando são registradas **três temperaturas consecutivas acima do limite**.

## 3. Funcionamento do programa

### Definição do limite

Primeiro, o usuário informa o limite de temperatura. O programa considera válidos valores entre **-100,0 e 100,0 graus**.

### Realização das leituras

Depois de definir o limite, o programa solicita uma temperatura por vez. A cada leitura são atualizados os dados necessários para o relatório final.

### Tratamento de valores inválidos

O programa verifica se o usuário digitou realmente um número e se a temperatura está dentro do intervalo de -100,0 a 100,0 graus. Caso contrário, uma mensagem de erro é apresentada e a entrada é solicitada novamente.

### Identificação de temperaturas acima do limite

Uma temperatura é considerada acima do limite quando:

```c
temperatura > limite
```

Quando isso acontece, a quantidade de temperaturas acima do limite é incrementada.

### Contagem de temperaturas consecutivas

O programa utiliza a variável `consecutivas` para contar quantas temperaturas seguidas ficaram acima do limite.

- Se a temperatura estiver acima do limite, o contador aumenta em 1.
- Se a temperatura estiver dentro ou igual ao limite, o contador volta para 0.
- Quando o contador chega a 3, o monitoramento é encerrado.

### Condição de encerramento

O laço principal continua enquanto o contador de temperaturas consecutivas for menor que 3:

```c
while (consecutivas < 3)
```

Portanto, o programa termina automaticamente após três temperaturas consecutivas acima do limite.

## 4. Estruturas de repetição utilizadas

### `while`

O `while` foi utilizado no monitoramento principal:

```c
while (consecutivas < 3)
```

Ele permite que novas temperaturas sejam lidas repetidamente enquanto a condição de encerramento ainda não foi atingida.

### `do...while`

O `do...while` foi utilizado na função `lerTemperatura()` para validar as entradas. A leitura precisa acontecer pelo menos uma vez antes de a condição de validade ser verificada. Se o usuário informar um valor inválido, a estrutura repete a solicitação.

Dessa forma, o projeto utiliza uma combinação de `while` e `do...while`, cada um em uma parte adequada do algoritmo.

## 5. Como executar

### Compilar

No terminal, dentro da pasta do projeto, execute:

```bash
gcc monitoramento.c -o monitoramento
```

### Executar no Linux/macOS

```bash
./monitoramento
```

### Executar no Windows

```bash
monitoramento.exe
```

## 6. Testes realizados

### Teste 1 - Validação de entradas inválidas

Foi informado texto no lugar de um número e também uma temperatura fora do intervalo permitido. O programa apresentou mensagens de entrada inválida e solicitou novamente os valores, sem encerrar o monitoramento.

**Resultado:** teste aprovado.

### Teste 2 - Temperaturas acima do limite, porém não consecutivas

Foi utilizado limite de 30 graus e uma sequência contendo temperaturas acima do limite intercaladas com temperaturas dentro do limite. Quando uma temperatura ficou dentro ou igual ao limite, o contador de consecutivas foi reiniciado.

**Resultado:** o programa não encerrou até que ocorresse a sequência de três valores acima do limite. Teste aprovado.

### Teste 3 - Três temperaturas consecutivas acima do limite

Foi utilizado limite de 30 graus e, em determinado momento, foram informadas três temperaturas consecutivas acima do limite. Na terceira ocorrência consecutiva, o programa encerrou automaticamente e apresentou o relatório final.

**Resultado:** encerramento automático correto. Teste aprovado.

As evidências dos testes estão na pasta `evidencias/`.

## 7. Organização do projeto

```text
desafio-monitoramento/
│
├── monitoramento.c
├── README.md
└── evidencias/
    ├── teste01.png
    ├── teste02.png
    └── teste03.png
```

## 8. Reflexão final

Escolhi utilizar `while` no monitoramento porque a quantidade de temperaturas não é conhecida antecipadamente: o programa deve continuar lendo valores até que aconteça a condição de encerramento, que é ter três temperaturas consecutivas acima do limite.

Também utilizei `do...while` na validação das entradas porque nesse caso a leitura precisa acontecer antes da verificação da condição. A diferença foi importante porque o usuário precisa informar um valor pelo menos uma vez e, se o valor for inválido, a estrutura permite repetir a solicitação até que uma entrada válida seja informada.
