#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {

    float notas[ESTUDIANTES][ASIGNATURAS];
    float promedio_est[ESTUDIANTES];
    float promedio_asig[ASIGNATURAS];

    int aprobados[ASIGNATURAS] = {0};
    int reprobados[ASIGNATURAS] = {0};

    int i, j;
    float suma, max, min;

    // pedir notas
    for(i = 0; i < ESTUDIANTES; i++) {
        printf("\nEstudiante %d\n", i + 1);

        for(j = 0; j < ASIGNATURAS; j++) {

            // validar que esté entre 0 y 10
            do {
                printf("Nota materia %d: ", j + 1);
                scanf("%f", &notas[i][j]);

                if(notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Ingresa una nota valida (0-10)\n");
                }

            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // promedio por estudiante
    printf("\nPromedio por estudiante:\n");

    for(i = 0; i < ESTUDIANTES; i++) {

        suma = 0;
        max = notas[i][0];
        min = notas[i][0];

        for(j = 0; j < ASIGNATURAS; j++) {
            suma += notas[i][j];

            if(notas[i][j] > max) max = notas[i][j];
            if(notas[i][j] < min) min = notas[i][j];
        }

        promedio_est[i] = suma / ASIGNATURAS;

        printf("Est %d -> prom: %.2f | mayor: %.2f | menor: %.2f\n",
               i + 1, promedio_est[i], max, min);
    }

    // promedio por materia
    printf("\nPromedio por materia:\n");

    for(j = 0; j < ASIGNATURAS; j++) {

        suma = 0;
        max = notas[0][j];
        min = notas[0][j];

        for(i = 0; i < ESTUDIANTES; i++) {

            suma += notas[i][j];

            if(notas[i][j] > max) max = notas[i][j];
            if(notas[i][j] < min) min = notas[i][j];

            // contar aprobados y reprobados
            if(notas[i][j] >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }

        promedio_asig[j] = suma / ESTUDIANTES;

        printf("Materia %d -> prom: %.2f | mayor: %.2f | menor: %.2f\n",
               j + 1, promedio_asig[j], max, min);

        printf("   apr: %d | rep: %d\n", aprobados[j], reprobados[j]);
    }

    return 0;
}
