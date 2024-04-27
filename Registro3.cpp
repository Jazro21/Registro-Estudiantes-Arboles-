// notas adicionales del Ing. Ampudia para el Lic. Perez

// Este es le codigo base.
// faltan las funciones eliminar y buscar (aun no se como hacerlas) le pido de su colaboracion para la realizacion de dichas funciones
// ocurre un inconveniente. al momento de datos un segundo estudiente, el programa se cierra
// Por lo tanto, no se puedo verificar los tipos de recorrido (Pre, In y Post)
// Solucionar lo antes posible

// Notas del Lic. Pérez para el Ing. Ampudia.

// Primeramente, no logro hacer que aparezca el error el cual no permite ingresar un segundo estudiante, cuando lo hice en mi visual, pude datos un segundo, tercer, cuarto y hasta quinto estudiante sin
// problemas, aunque de todas maneras, pude que al borrar los temporales y demás, allí aparezca el error. Notese que al agregar un estudiante y escribir su nombre, lanza error que no deja avanzar. podría
// sugerir que puede ser la manera en que se usa string, ya que normalmente no se usa "cin" sinó "getline y lo demás en paréntesis", cuando cambié Nombre y Apellido a char, el error desaparecio.
// por allí poseo la forma de buscar por código y la de eliminar, revísela a gusto y ya en la noche que esté disponible, revisaré el código, y de ser necesario, lo ubicaré aquí para el correcto funcionamiento
// de dichas funciones.

// Notas adicionales del Ing. Ampudia para el Lic. Perez

// Se solucionó el error de cerrar el programa al datos un segundo estudiante.
// falta revisar si los tipos de recorrido funcionan correctamente.
// los metodos eliminar y buscar todavia siguen sin ser implementados.

// Notas adicionales del Ing. Ampudia para el Lic. Perez

// Se añadió el metodo de buscar estudiante.
// Es funcional, pero no se añadió el mensaje (estudiante no encontrado) si el codigo gresado no este registrado en el arbol
// Solucionar lo antes posible

// Notas adicionales del Ing. Ampudia para el Lic. Perez

// Ocurrio un problema. se modifico el codigo para ordenar los estudiantes de acuerdo a su codigo, por lo que tuve que hacer varias modificaciones
// Al final, no pude añadir dicha opcion. ademas, cada ves que se recorre el arreglo, aparece un bucle
// Este codigo es nuevo. quise empezar desde cero por que se me hacia más facil
// aun falta el metodo eliminar

#include <iostream>
#include <malloc.h>

using namespace std;

struct Registro4
{
    char Nombre[20];
    char Apellido[20];

    int Codigo = 0;
    int Dia = 0;
    int Mes = 0;
    int Año = 0;

    Registro4 *izq;
    Registro4 *der;
};

Registro4 *aux1 = NULL;
Registro4 *aux2 = NULL;
Registro4 *aux3 = NULL;
Registro4 *aux4 = NULL;

Registro4 *raiz = NULL;
Registro4 *raiz2 = NULL;

// metodo para pedir los datos

int Datos()
{
    aux1 = (struct Registro4 *)malloc(sizeof(struct Registro4));
    aux3 = (struct Registro4 *)malloc(sizeof(struct Registro4));

    cout << "Ingrese el nombre: ";
    cin >> aux1->Nombre;

    cout << "Ingrese el apellido: ";
    cin >> aux1->Apellido;

    cout << "Ingrese el codigo: ";
    cin >> aux1->Codigo;

    cout << "Ingrese su dia de nacimiento: ";
    cin >> aux1->Dia;

    cout << "Ingrese su mes de nacimiento: ";
    cin >> aux1->Mes;

    cout << "Ingrese su año de nacimiento: ";
    cin >> aux1->Año;

    aux1->izq = NULL;
    aux1->der = NULL;

    aux3->izq = NULL;
    aux3->der = NULL;

    aux3 = aux1;
    return 0;
}

// metodos de posicionar los datos

int posicionarFecha()
{
    if (aux1->Dia == aux2->Dia && aux1->Mes == aux2->Mes && aux1->Año == aux2->Año) // para la derecha
    {
        if (aux2->der != NULL)
        {
            aux2 = aux2->der;
            posicionarFecha();
        }
        else
        {
            aux2->der = aux1; // ¿Por qué?
        }
    }

    if (aux1->Dia != aux2->Dia && aux1->Mes != aux2->Mes && aux1->Año != aux2->Año) // para la izquierda
    {
        if (aux2->izq != NULL)
        {
            aux2 = aux2->izq;
            posicionarFecha();
        }
        else
        {
            aux2->izq = aux1; // ¿Por qué?
        }
    }
    return 0;
}

int posicionarCodigo()
{
    if (aux3->Codigo > aux2->Codigo) // para la derecha
    {
        if (aux2->der != NULL)
        {
            aux2 = aux2->der;
            posicionarFecha();
        }
        else
        {
            aux2->der = aux3; // ¿Por qué?
        }
    }

    if (aux3->Codigo < aux2->Codigo) // para la izquierda
    {
        if (aux2->izq != NULL)
        {
            aux2 = aux2->izq;
            posicionarFecha();
        }
        else
        {
            aux2->izq = aux3; // ¿Por qué?
        }
    }
    return 0;
}

// metodos de registrar los estudiantes

int registrarFecha()
{
    if (raiz == NULL) // si no hay raiz, se libera memoria (se utiliza aux1)
    {
        raiz = aux1;
        raiz2 = aux1;
        aux1 = NULL;
        free(aux1);
    }
    else // si ya hay una raiz, llama a el metodo posicionarFecha (se utiliza aux2)
    {
        aux2 = raiz;
        posicionarFecha();
    }

    return 0;
}

int registrarCodigo()
{

    if (raiz2 == NULL) // si no hay raiz, se libera memoria (se utiliza aux3)
    {
        raiz2 = aux3;
        raiz2 = aux3;
        aux3 = NULL;
        free(aux3);
    }
    else // si ya hay una raiz, llama a el metodo posicionarFecha (se utiliza aux2)
    {
        aux2 = raiz2;
        posicionarCodigo();
    }
    return 0;
}

// Metodos de ordenamiento

int ordenarPre(Registro4 *retroceso)
{
    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "Codigo: " << retroceso->Codigo << endl;
    cout << "Fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes << "/" << retroceso->Año << endl;
    cout << " " << endl;
    if (retroceso->izq != NULL)
    {
        ordenarPre(retroceso->izq);
    }
    if (retroceso->der != NULL)
    {
        ordenarPre(retroceso->der);
    }
    return 0;
}

int ordenarIn(Registro4 *retroceso)
{
    if (retroceso->izq != NULL)
    {
        ordenarIn(retroceso->izq);
    }
    if (retroceso->der != NULL)
    {
        ordenarIn(retroceso->der);
    }
    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "Codigo: " << retroceso->Codigo << endl;
    cout << "Fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes << "/" << retroceso->Año << endl;
    cout << " " << endl;

    return 0;
}

int ordenarPost(Registro4 *retroceso)
{
    if (retroceso->izq != NULL)
    {
        ordenarPost(retroceso->izq);
    }
    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "codigo: " << retroceso->Codigo << endl;
    cout << "fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes << "/" << retroceso->Año << endl;
    cout << " " << endl;

    if (retroceso->der != NULL)
    {
        ordenarPost(retroceso->der);
    }
    return 0;
}

// Metodos para recorrer el arbol

// Pre orden
int recorrerPreFecha()
{
    aux1 = raiz;

    if (aux1 != NULL)
    {
        ordenarPre(aux1);
    }
    return 0;
}
int recorrerPreCodigo()
{
    aux3 = raiz2;

    if (aux3 != NULL)
    {
        ordenarPre(aux3);
    }
    return 0;
}

// In orden
int recorrerInFecha()
{
    aux1 = raiz;

    if (aux1 != NULL)
    {
        ordenarIn(aux1);
    }
    return 0;
}
int recorrerInCodigo()
{
    aux3 = raiz2;

    if (aux3 != NULL)
    {
        ordenarIn(aux3);
    }
    return 0;
}

// Post orden
int recorrerPostFecha()
{
    aux1 = raiz;

    if (aux1 != NULL)
    {
        ordenarPost(aux1);
    }
    return 0;
}
int recorrerPostCodigo()
{
    aux3 = raiz2;

    if (aux3 != NULL)
    {
        ordenarPost(aux3);
    }
    return 0;
}

int buscador = 0;

int buscar()
{
    if (raiz == NULL)
    {
        cout << "No hay estudiantes en el registro" << endl;
        return 0;
    }

    aux1 = raiz;

    cout << "Ingrese el codigo del estudiante que desea buscar: ";
    cin >> buscador;

    if (buscador != aux1->Codigo)
    {
        cout << "Estudiante no registrado" << endl;
    }

    if (aux1 != NULL)
    {
        if (buscador != aux1->Codigo)
        {
            if (aux1->der != NULL && aux1->izq != NULL)
            {
                aux1 = aux1->der;
                aux1 = aux1->izq;
                buscar();
            }
        }
        else if (buscador == aux1->Codigo)
        {
            cout << "Estudiante encontrado" << endl;
            cout << "Nombre: " << aux1->Nombre << " " << aux1->Apellido << endl;
            cout << "Codigo: " << aux1->Codigo << endl;
            cout << "Fecha de nacimiento: " << aux1->Dia << "/" << aux1->Mes << "/" << aux1->Año << endl;
            cout << " " << endl;
        }
    }
    return 0;
}

int opcion = 0;
int opcion2 = 0;

int menu()
{
    cout << "menu de registro de estudiantes" << endl;
    cout << "1. Agregar estudiante" << endl;
    cout << "2. Buscar estudiante" << endl;
    cout << "3. Recorrer el listado de estudiantes (Pre_Orden)" << endl;
    cout << "4. Recorrer el listado de estudiantes (In_Orden)" << endl;
    cout << "5. Recorrer el listado de estudiantes (Post_Orden)" << endl;
    cout << "6. Eliminar estudiante (no disponible)" << endl;
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
    case 2:
        buscar();
        break;
    case 3:
        cout << "que desea prevalecer:" << endl;
        cout << "1. fecha" << endl;
        cout << "2. codigo" << endl;

        switch (opcion2)
        {
        case 1:
            cout << "Recorrido en Pre_orden:" << endl;
            recorrerPreFecha();
            break;

        case 2:
            cout << "Recorrido en Pre_orden:" << endl;
            recorrerPreCodigo();
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        break;

    case 4:
        cout << "que desea prevalecer:" << endl;
        cout << "1. fecha" << endl;
        cout << "2. codigo" << endl;

        switch (opcion2)
        {
        case 1:
            cout << "Recorrido en In_orden:" << endl;
            recorrerInFecha();
            break;

        case 2:
            cout << "Recorrido en In_orden:" << endl;
            recorrerInCodigo();
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        break;

    case 5:
        cout << "que desea prevalecer:" << endl;
        cout << "1. fecha" << endl;
        cout << "2. codigo" << endl;

        switch (opcion2)
        {
        case 1:
            cout << "Recorrido en Post_orden:" << endl;
            recorrerPostFecha();
            break;

        case 2:
            cout << "Recorrido en Post_orden:" << endl;
            recorrerPostCodigo();
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        break;

    case 7:
        cout << "Finalizando programa" << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    return 0;
}
