#include <stdio.h>

#define MIN_TEMPERATURA -100.0
#define MAX_TEMPERATURA 100.0

/* Le um numero real e garante que a entrada seja valida. */
double lerTemperatura(const char *mensagem) {
    double valor;
    int resultado;

    do {
        printf("%s", mensagem);
        resultado = scanf("%lf", &valor);

        if (resultado != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n');
        } else if (valor < MIN_TEMPERATURA || valor > MAX_TEMPERATURA) {
            printf("Temperatura invalida. Use um valor entre %.1f e %.1f graus.\n",
                   MIN_TEMPERATURA, MAX_TEMPERATURA);
        }
    } while (resultado != 1 || valor < MIN_TEMPERATURA || valor > MAX_TEMPERATURA);

    return valor;
}

int main(void) {
    double limite;
    double temperatura;
    double soma = 0.0;
    double maior = 0.0;
    double menor = 0.0;
    int quantidade = 0;
    int acimaDoLimite = 0;
    int consecutivas = 0;
    double media;
    double percentual;

    printf("========================================\n");
    printf("     MONITORAMENTO DE TEMPERATURA\n");
    printf("========================================\n");
    printf("Valores validos: %.1f a %.1f graus.\n\n", MIN_TEMPERATURA, MAX_TEMPERATURA);

    limite = lerTemperatura("Digite o limite de temperatura: ");

    printf("\nIniciando monitoramento...\n");
    printf("O programa encerra quando houver 3 temperaturas consecutivas acima do limite.\n\n");

    /* O while mantem o monitoramento ate ocorrer a condicao de encerramento. */
    while (consecutivas < 3) {
        temperatura = lerTemperatura("Digite uma temperatura: ");

        quantidade++;
        soma += temperatura;

        if (quantidade == 1) {
            maior = temperatura;
            menor = temperatura;
        } else {
            if (temperatura > maior) {
                maior = temperatura;
            }
            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        /* Conta somente valores acima do limite e zera quando a sequencia quebra. */
        if (temperatura > limite) {
            acimaDoLimite++;
            consecutivas++;
            printf("ALERTA: temperatura acima do limite! (%d consecutiva(s))\n", consecutivas);
        } else {
            consecutivas = 0;
            printf("Temperatura dentro do limite. Contador consecutivo reiniciado.\n");
        }
    }

    media = soma / quantidade;
    percentual = ((double)acimaDoLimite / quantidade) * 100.0;

    printf("\n========================================\n");
    printf("       MONITORAMENTO ENCERRADO\n");
    printf("========================================\n");
    printf("Motivo: 3 temperaturas consecutivas acima do limite.\n");
    printf("Quantidade de leituras: %d\n", quantidade);
    printf("Media das temperaturas: %.2f graus\n", media);
    printf("Maior temperatura: %.2f graus\n", maior);
    printf("Menor temperatura: %.2f graus\n", menor);
    printf("Temperaturas acima do limite: %d\n", acimaDoLimite);
    printf("Percentual acima do limite: %.2f%%\n", percentual);

    return 0;
}
