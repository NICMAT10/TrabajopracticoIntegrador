#include <stdio.h>
#include <stdlib.h>

struct alumno
{
    int dni;
    int nota;
};

struct alumno lista_alumnos[10];

int dni_ingresado, valido, nueva_nota, dni, nota;
int cant_alumnos = 10;
int bandera = 0;

void cargarAlumno();
void buscarAlumno();
void modificarNota();
void mostrarAlumnos();
int validarDni();
int validarNota();

void main()
{
    int opcion=0;
    do
    {
        printf("\n");
        printf("Ingrese una opcion \n");
        printf("1-Cargar alumnos \n");
        printf("2-Buscar un alumno \n");
        printf("3-Modificar la nota de un alumno \n");
        printf("4-Mostrar un listado de los 10 alumnos \n");
        printf("5-Salir \n");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1: // carga de datos
            cargarAlumno();
            break;

        case 2: // búsqueda
            buscarAlumno();
            break;

        case 3: // modificación de notas de alumnos
            modificarNota();
            break;

        case 4: // listado de alumnos
            mostrarAlumnos();
            break;
        }

    } while (opcion != 5);

    system("pause");
}

void cargarAlumno()
{
    printf("Ingrese datos de los alumnos \n");
    printf("\n");
    for (int i = 0; i < cant_alumnos; i++)
    {
        do
        {
            printf("DNI del alumno: %i \n", i + 1);
            scanf("%i", &dni);
            valido = validarDni(dni);
            if (valido == 1)
            {
                lista_alumnos[i].dni = dni;
            }
            else
            {
                printf("ERROR: no ingres%c un dni valido\n", 162);
            }
        } while (valido == 0);

        do
        {
            printf("Nota: \n");
            scanf("%i", &nota);
            valido = validarNota(nota);
            if (valido == 1)
            {
                lista_alumnos[i].nota = nota;
            }
            else
            {
                printf("ERROR: no ingres%c una nota valida\n", 162);
            }
        } while (valido == 0);

        printf("\n");
    }
}

int validarDni(int dni)
{
    if (dni >= 1000000 && dni <= 99999999)
    {
        return 1;
    }
    return 0;
}

int validarNota(int nota)
{
    if (nota >= 1 && nota <= 10)
    {
        return 1;
    }
    return 0;
}

void buscarAlumno()
{
    printf("ingrese DNI del alumno que desea buscar\n");
    scanf("%i", &dni_ingresado);
    bandera = 0;
    int i = 0;
    do
    {
        if (dni_ingresado == lista_alumnos[i].dni)
        {
            bandera = 1;
        }
        else
        {
            i = i + 1;
        }

    } while (i < cant_alumnos && bandera == 0);

    if (bandera == 1)
    {
        printf("DNI: %i \t nota: %i \n", lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
    else
    {
        printf("No se encontr%c un alumno con el DNI: %i \n", 162, dni_ingresado);
    }
}

void modificarNota()
{
    printf("ingrese DNI del alumno del cual desea modificar la nota\n");
    scanf("%i", &dni_ingresado);
    int i = 0;
    bandera = 0;
    do
    {
        if (dni_ingresado == lista_alumnos[i].dni)
        {
            bandera = 1;
        }
        else
        {
            i = i + 1;
        }
    } while (i < cant_alumnos && bandera == 0);

    if (bandera == 1)
    {
        printf("El alumno con DNI %i tiene nota: %i \n", lista_alumnos[i].dni, lista_alumnos[i].nota);
        do
        {
            printf("Ingrese la nueva nota\n");
            scanf("%i", &nueva_nota);
            valido = validarNota(nueva_nota);
            if (valido == 0)
            {
                printf("ERROR: no ingres%c una nota valida\n", 162);
            }
        } while (valido == 0);

        lista_alumnos[i].nota = nueva_nota;

        printf("DNI: %i \t nueva nota: %i \n", lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
    else
    {
        printf("No se encontr%c un alumno con ese DNI \n", 162);
    }
}

void mostrarAlumnos()
{
    printf("Lista de alumnos \n");
    for (int i = 0; i < cant_alumnos; i++)
    {
        printf("Alumno %i \t DNI: %i \t nota: %i \n", i + 1, lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
}