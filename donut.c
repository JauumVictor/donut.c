#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    float A = 0, B = 0, i, j, z[1760];
    int k;
    char b[1760];

    // Limpa a tela do console
    system("cls");

    // Loop infinito para renderizar a animação
    for (;;)
    {
        // Preenche o array 'b' com espaços em branco
        memset(b, 32, 1760);

        // Preenche o array 'z' com zeros
        memset(z, 0, 7040);

        // Loop para percorrer as coordenadas 3D (i, j)
        for (j = 0; j < 6.28; j += 0.07)
        {
            for (i = 0; i < 6.28; i += 0.02)
            {
                // Cálculos das coordenadas 3D para 2D usando a fórmula de projeção
                float sini = sin(i);
                float cosj = cos(j);
                float sinA = sin(A);
                float sinj = sin(j);
                float cosA = cos(A);
                float cosj2 = cosj + 2;
                float mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5);
                float cosi = cos(i);
                float cosB = cos(B);
                float sinB = sin(B);
                float t = sini * cosj2 * cosA - sinj * sinA;
                int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB);
                int y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB);
                int o = x + 80 * y;
                int N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);

                // Desenha o caractere na coordenada (x, y) se estiver dentro do limite da tela
                if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o])
                {
                    z[o] = mess;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Move o cursor para o início da linha (comando ANSI)
        printf("\x1b[d");

        // Imprime o array 'b' na tela
        for (k = 0; k < 1761; k++)
        {
            putchar(k % 80 ? b[k] : '\n');
        }

        // Incrementa os ângulos A e B para animação
        A += 0.08;
        B += 0.06;
    }

    return 0;
}
