#include <iostream>
#include <malloc.h>

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
    auxF1 = (Registro5 *)malloc(sizeof(Registro5));
    auxC1 = (Registro5 *)malloc(sizeof(Registro5));

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

    auxC1 = auxF1;
    return 0;
}

// metodos de mosicionamiento

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
        auxC2->izq = auxC1;
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

    return 0;
}
int ordenarInF(Registro5 *Retroceso2)
{

    return 0;
}
int ordenarPostF(Registro5 *Retroceso3)
{

    return 0;
}

// por Codigo
int ordenarPreC(Registro5 *Retroceso4)
{

    return 0;
}
int ordenarInC(Registro5 *Retroceso5)
{

    return 0;
}
int ordenarPostC(Registro5 *Retroceso5)
{

    return 0;
}

// metodos de recorrido
// Pre orden
int recorrerPreF()
{

    return 0;
}
int recorrerPreC()
{

    return 0;
}
// In orden
int recorrerInF()
{

    return 0;
}
int recorrerInC()
{

    return 0;
}
// Post orden
int recorrerPostF()
{

    return 0;
}
int recorrerPostC()
{

    return 0;
}

int opcion = 0;
int opcion2 = 0;
int main()
{
    do
    {
        cout << "menu" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "3. Recorrer el listado de estudiantes (Pre_Orden)" << endl;
        cout << "4. Recorrer el listado de estudiantes (In_Orden)" << endl;
        cout << "5. Recorrer el listado de estudiantes (Post_Orden)" << endl;
        cout << "7. salir" << endl;
        cout << " " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Datos();
            registrarFecha();
            registrarCodigo();
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