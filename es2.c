#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    float *a = malloc(n * sizeof(float));
   

    float media = 0;
    for (int i = 0; i < n; i++) {
        printf("Inserisci il %d numero: ", i + 1);
        scanf("%f", &a[i]);
        media += a[i];
    }

    media = media / n;
    printf("\nLa media e': %f\n", media);

    printf("Numeri superiori alla media:\n");
    for (int i = 0; i < n; i++) {
        if (a[i] > media) {
            printf("%f\n", a[i]);
        }
    }

    free(a);
    return 0;
}
