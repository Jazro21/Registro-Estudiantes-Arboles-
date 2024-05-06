// Notas adicionales del Ing. Ampudia para el Lic. Perez
// hice un intento de crear el metodo de buscar por codigo, pero no funciona
// Notas de actualizacion
// implementé otra forma de buscar por codigo, pero no estoy seguro de su funcionamiento

#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

struct Registro5
{
    char Nombre[20];
    char Apellido[20];
    int Codigo = 0;

    int Dia = 0;
    int Mes = 0;
    int Año = 0;

    Registro5 *izq;
    Registro5 *der;
};

Registro5 *raizF = NULL;
Registro5 *auxF1 = NULL;
Registro5 *auxF2 = NULL;

Registro5 *raizC = NULL;
Registro5 *auxC1 = NULL;
Registro5 *auxC2 = NULL;

int Datos()
{
    auxF1 = (struct Registro5 *)malloc(sizeof(struct Registro5));
    auxC1 = (struct Registro5 *)malloc(sizeof(struct Registro5));

    cout << "Ingrese el nombre: ";
    cin >> auxF1->Nombre;

    cout << "Ingrese el apellido: ";
    cin >> auxF1->Apellido;

    cout << "Ingrese el codigo: ";
    cin >> auxF1->Codigo;

    cout << "Ingrese su dia de nacimiento: ";
    cin >> auxF1->Dia;

    cout << "Ingrese su mes de nacimiento: ";
    cin >> auxF1->Mes;

    cout << "Ingrese su año de nacimiento: ";
    cin >> auxF1->Año;

    strcpy(auxC1->Nombre, auxF1->Nombre);
    strcpy(auxC1->Apellido, auxF1->Apellido);

    auxC1->Codigo = auxF1->Codigo;
    auxC1->Dia = auxF1->Dia;
    auxC1->Mes = auxF1->Mes;
    auxC1->Año = auxF1->Año;

    auxC1->izq = NULL;
    auxC1->der = NULL;

    auxF1->izq = NULL;
    auxF1->der = NULL;
    return 0;
}

// metodos de posicionamiento

int posicionarFecha()
{
    if (auxF1->Año == auxF2->Año && auxF1->Mes == auxF2->Mes && auxF1->Dia == auxF2->Dia)
    {
        if (auxF2->der != NULL)
        {
            auxF2 = auxF2->der;
            posicionarFecha();
        }
        else
        {
            auxF2->der = auxF1;
        }
    }

    if (auxF1->Año != auxF2->Año && auxF1->Mes != auxF2->Mes && auxF1->Dia != auxF2->Dia)
    {
        if (auxF2->izq != NULL)
        {
            auxF2 = auxF2->izq;
            posicionarFecha();
        }
        else
        {
            auxF2->izq = auxF1;
        }
    }
    return 0;
}

int posicionarCodigo()
{
    if (auxC1->Codigo > auxC2->Codigo)
    {
        if (auxC2->der != NULL)
        {
            auxC2 = auxC2->der;
            posicionarCodigo();
        }
    }
    else
    {
        auxC2->der = auxC1;
    }

    if (auxC1->Codigo < auxC2->Codigo)
    {
        if (auxC2->izq != NULL)
        {
            auxC2 = auxC2->izq;
            posicionarCodigo();
        }
        else
        {
            auxC2->izq = auxC1;
        }
    }
    return 0;
}

// Metodos de registro

int registrarFecha()
{
    if (raizF == NULL)
    {
        raizF = auxF1;
        auxF1 = NULL;
        free(auxF1);
    }
    else
    {
        auxF2 = raizF;
        posicionarFecha();
    }
    return 0;
}

int registrarCodigo()
{
    if (raizC == NULL)
    {
        raizC = auxC1;
        auxC1 = NULL;
        free(auxC1);
    }
    else
    {
        auxC2 = raizC;
        posicionarCodigo();
    }
    return 0;
}

// metodos de ordenamiento
// por fecha
int ordenarPreF(Registro5 *Retroceso1)
{
    cout << "Nombre: " << Retroceso1->Nombre << " " << Retroceso1->Apellido << endl;
    cout << "Codigo: " << Retroceso1->Codigo << endl;
    cout << "Fecha de nacimiento: " << Retroceso1->Dia << "/" << Retroceso1->Mes << "/" << Retroceso1->Año << endl;
    cout << " " << endl;
    if (Retroceso1->izq != NULL)
    {
        ordenarPreF(Retroceso1->izq);
    }
    if (Retroceso1->der != NULL)
    {
        ordenarPreF(Retroceso1->der);
    }
    return 0;
}
int ordenarInF(Registro5 *Retroceso2)
{
    if (Retroceso2->izq != NULL)
    {
        ordenarInF(Retroceso2->izq);
    }
    cout << "Nombre: " << Retroceso2->Nombre << " " << Retroceso2->Apellido << endl;
    cout << "Codigo: " << Retroceso2->Codigo << endl;
    cout << "Fecha de nacimiento: " << Retroceso2->Dia << "/" << Retroceso2->Mes << "/" << Retroceso2->Año << endl;
    cout << " " << endl;
    if (Retroceso2->der != NULL)
    {
        ordenarInF(Retroceso2->der);
    }
    return 0;
}
int ordenarPostF(Registro5 *Retroceso3)
{
    if (Retroceso3->izq != NULL)
    {
        ordenarPostF(Retroceso3->izq);
    }
    if (Retroceso3->der != NULL)
    {
        ordenarPostF(Retroceso3->der);
    }
    cout << "Nombre: " << Retroceso3->Nombre << " " << Retroceso3->Apellido << endl;
    cout << "Codigo: " << Retroceso3->Codigo << endl;
    cout << "Fecha de nacimiento: " << Retroceso3->Dia << "/" << Retroceso3->Mes << "/" << Retroceso3->Año << endl;
    cout << " " << endl;
    return 0;
}

// por Codigo
int ordenarPreC(Registro5 *Retroceso4)
{
    cout << "Nombre: " << Retroceso4->Nombre << " " << Retroceso4->Apellido << endl;
    cout << "Codigo: " << Retroceso4->Codigo << endl;
    cout << "Fecha de nacimiento: " << Retroceso4->Dia << "/" << Retroceso4->Mes << "/" << Retroceso4->Año << endl;
    cout << " " << endl;
    if (Retroceso4->izq != NULL)
    {
        ordenarPreC(Retroceso4->izq);
    }
    if (Retroceso4->der != NULL)
    {
        ordenarPreC(Retroceso4->der);
    }
    return 0;
}
int ordenarInC(Registro5 *Retroceso5)
{
    if (Retroceso5->izq != NULL)
    {
        ordenarInC(Retroceso5->izq);
    }
    cout << "Nombre: " << Retroceso5->Nombre << " " << Retroceso5->Apellido << endl;
    cout << "Codigo: " << Retroceso5->Codigo << endl;
    cout << "Fecha de nacimiento: " << Retroceso5->Dia << "/" << Retroceso5->Mes << "/" << Retroceso5->Año << endl;
    cout << " " << endl;
    if (Retroceso5->der != NULL)
    {
        ordenarInC(Retroceso5->der);
    }
    return 0;
}
int ordenarPostC(Registro5 *Retroceso6)
{
    if (Retroceso6->izq != NULL)
    {
        ordenarPostC(Retroceso6->izq);
    }
    if (Retroceso6->der != NULL)
    {
        ordenarPostC(Retroceso6->der);
    }
    cout << "Nombre: " << Retroceso6->Nombre << " " << Retroceso6->Apellido << endl;
    cout << "Codigo: " << Retroceso6->Codigo << endl;
    cout << "Fecha de nacimiento: " << Retroceso6->Dia << "/" << Retroceso6->Mes << "/" << Retroceso6->Año << endl;
    cout << " " << endl;
    return 0;
}

// metodos de recorrido
// Pre orden
int recorrerPreF()
{
    if (auxF1 != NULL)
    {
        ordenarPreF(raizF);
    }
    return 0;
}
int recorrerPreC()
{
    if (auxC1 != NULL)
    {
        ordenarPreC(raizC);
    }
    return 0;
}

// In orden
int recorrerInF()
{
    if (auxF1 != NULL)
    {
        ordenarInF(raizF);
    }
    return 0;
}
int recorrerInC()
{
    if (auxC1 != NULL)
    {
        ordenarInC(raizC);
    }
    return 0;
}
// Post orden
int recorrerPostF()
{
    if (auxF1 != NULL)
    {
        ordenarPostF(raizF);
    }
    return 0;
}
int recorrerPostC()
{
    if (auxC1 != NULL)
    {
        ordenarPostC(raizC);
    }
    return 0;
}

int opcion = 0;
int opcion2 = 0;
int opcion3 = 0;
int buscadorCodigo = 0;

int buscadorDia = 0;
int BuscadorMes = 0;
int BuscadorAño = 0;

int buscarF()
{
    if (auxF1 == NULL)
    {
        cout << "no hay estudiantes registrados" << endl;
    }
    if (auxF1 != NULL)
    {
        if (auxF1->Dia == buscadorDia && auxF1->Mes == BuscadorMes && auxF1->Año == BuscadorAño)
        {
            cout << "Nombre: " << auxF1->Nombre << " " << auxF1->Apellido << endl;
            cout << "Codigo: " << auxF1->Codigo << endl;
            cout << "Fecha de nacimiento: " << auxF1->Dia << "/" << auxF1->Mes << "/" << auxF1->Año << endl;
        }
        if (auxF1->Dia != buscadorDia && auxF1->Mes == BuscadorMes && auxF1->Año == BuscadorAño)
        {
            if (auxF1->izq != NULL)
            {
                auxF1 = auxF1->izq;
                buscarF();
            }
            if (auxF1->der != NULL)
            {
                auxF1 = auxF1->der;
                buscarF();
            }
        }
    }
    return 0;
}

int buscarC()
{
    if (auxC1 == NULL)
    {
        cout << "no hay estudiantes registrados" << endl;
    }

    if (auxC1 != NULL)
    {
        if (auxC1->Codigo == buscadorCodigo)
        {
            cout << "Nombre: " << auxC1->Nombre << " " << auxC1->Apellido << endl;
            cout << "Codigo: " << auxC1->Codigo << endl;
            cout << "Fecha de nacimiento: " << auxC1->Dia << "/" << auxC1->Mes << "/" << auxC1->Año << endl;
            cout << " " << endl;
            return 0;
        }
        if (auxC1->Codigo != buscadorCodigo)
        {
            if (auxC1->der != NULL)
            {
                auxC1 = auxC1->der;
                buscarC();
            }
            if (auxC1->izq != NULL)
            {
                auxC1 = auxC1->izq;
                buscarC();
            }
        }
    }

    return 0;
}

int buscar()
{
    int opcion4 = 0;
    cout << "1. por codigo" << endl;
    cout << "2. por fecha" << endl;
    cin >> opcion4;

    switch (opcion4)
    {
    case 1:
        cout << "ingrese el codigo" << endl;
        cin >> buscadorCodigo;
        auxC1 = raizC;
        buscarC();
        break;
    case 2:
        cout << "ingrese el dia" << endl;
        cin >> buscadorDia;

        cout << "ingrese el mes" << endl;
        cin >> BuscadorMes;

        cout << "ingrese el año" << endl;
        cin >> BuscadorAño;
        auxF1 = raizF;
        buscarF();
        break;

    default:
        break;
    }
    return 0;
}
int main()
{
    do
    {
        cout << "menu" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. buscar estudiante" << endl;
        cout << "3. Recorrer el listado de estudiantes (Pre_Orden)" << endl;
        cout << "4. Recorrer el listado de estudiantes (In_Orden)" << endl;
        cout << "5. Recorrer el listado de estudiantes (Post_Orden)" << endl;
        cout << "7. salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Datos();
            registrarFecha();
            registrarCodigo();
            break;
        case 2:
            buscar();
            break;
        case 3:
            cout << "recorrido en Pre-Orden (fecha)" << endl;
            recorrerPreF();
            cout << "" << endl;

            cout << "recorrido en Pre-Orden (codigo)" << endl;
            recorrerPreC();
            cout << "" << endl;
            break;
        case 4:
            cout << "recorrido en In-Orden (fecha)" << endl;
            recorrerInF();
            cout << "" << endl;

            cout << "recorrido en In-Orden (codigo)" << endl;
            recorrerInC();
            cout << "" << endl;
            break;
        case 5:
            cout << "recorrido en Post-Orden (fecha)" << endl;
            recorrerPostF();
            cout << "" << endl;

            cout << "recorrido en Post-Orden (codigo)" << endl;
            recorrerPostC();
            cout << "" << endl;
            break;
        case 7:
            cout << "Finalizando programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 7);

    return 0;
}
