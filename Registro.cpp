// notas adicionales del Ing. Ampudia para el Lic. Perez

// Este es le codigo base.
// faltan las funciones eliminar y buscar (aun no se como hacerlas) le pido de su colaboracion para la realizacion de dichas funciones
// ocurre un inconveniente. al momento de registrar un segundo estudiente, el programa se cierra
// Por lo tanto, no se puedo verificar los tipos de recorrido (Pre, In y Post)
// Solucionar lo antes posible

// Notas del Lic. Pérez para el Ing. Ampudia.

// Primeramente, no logro hacer que aparezca el error el cual no permite ingresar un segundo estudiante, cuando lo hice en mi visual, pude registrar un segundo, tercer, cuarto y hasta quinto estudiante sin
// problemas, aunque de todas maneras, pude que al borrar los temporales y demás, allí aparezca el error. Notese que al agregar un estudiante y escribir su nombre, lanza error que no deja avanzar. podría
// sugerir que puede ser la manera en que se usa string, ya que normalmente no se usa "cin" sinó "getline y lo demás en paréntesis", cuando cambié Nombre y Apellido a char, el error desaparecio.
// por allí poseo la forma de buscar por código y la de eliminar, revísela a gusto y ya en la noche que esté disponible, revisaré el código, y de ser necesario, lo ubicaré aquí para el correcto funcionamiento
// de dichas funciones.

// Notas adicionales del Ing. Ampudia para el Lic. Perez

// Se solucionó el error de cerrar el programa al registrar un segundo estudiante.
// falta revisar si los tipos de recorrido funcionan correctamente.
// los metodos eliminar y buscar todavia siguen sin ser implementados.

// Notas adicionales del Ing. Ampudia para el Lic. Perez

// Se añadió el metodo de buscar estudiante.
// Es funcional, pero no se añadió el mensaje (estudiante no encontrado) si el codigo gresado no este registrado en el arbol
// Solucionar lo antes posible

// Notas adicionales del Lic. Pérez para el Ing. Ampudia

// En la hora que tuvimos libre el martes 23 de abril, aproveche para mejorar el código, ahora pasarán 2 cosas al buscar un estudiante por código
// 1. Si el usuario desea buscar un estudiante sin haber ingresado un estudiante anteriormente, el programa le dirá al usuario que el arbol está vacío
// 2. En caso tal que ingrese el código de un estudiante que no está registrado, el programa le dirá al usuario que el estudiante con dicho código no se encuentra registrado
// Es necesario revisar el código y hacer la función/método eliminar();

#include <iostream>
#include <malloc.h>

using namespace std;

struct Registro
{
    char Nombre[20];
    char Apellido[20];
    int Codigo = 0;

    int Dia = 0;
    int Mes = 0;
    int Año = 0;

    Registro *izq;
    Registro *der;
};

Registro *aux = NULL;
Registro *aux2 = NULL;
Registro *raiz = NULL;

int posicionar()
{
    if (aux->Dia == aux2->Dia && aux->Mes == aux2->Mes && aux->Año == aux2->Año) // para la derecha
    {
        if (aux2->der != NULL)
        {
            aux2 = aux2->der;
            posicionar();
        }
        else
        {
            aux2->der = aux; // ¿Por qué?
        }
    }

    if (aux->Dia != aux2->Dia && aux->Mes != aux2->Mes && aux->Año != aux2->Año) // para la izquierda
    {
        if (aux2->izq != NULL)
        {
            aux2 = aux2->izq;
            posicionar();
        }
        else
        {
            aux2->izq = aux; // ¿Por qué?
        }
    }
    return 0;
}

int registrar()
{
    aux = (struct Registro *)malloc(sizeof(struct Registro));

    cout << "Ingrese el nombre: ";
    cin >> aux->Nombre;

    cout << "Ingrese el apellido: ";
    cin >> aux->Apellido;

    cout << "Ingrese el codigo: ";
    cin >> aux->Codigo;

    cout << "Ingrese su dia de nacimiento: ";
    cin >> aux->Dia;

    cout << "Ingrese su mes de nacimiento: ";
    cin >> aux->Mes;

    cout << "Ingrese su año de nacimiento: ";
    cin >> aux->Año;

    aux->izq = NULL;
    aux->der = NULL;

    if (raiz == NULL) // si no hay raiz, se libera memoria (se utiliza aux)
    {
        raiz = aux;
        aux = NULL;
        free(aux);
    }
    else // si ya hay una raiz, llama a el metodo posicionar (se utiliza aux2)
    {
        aux2 = raiz;
        posicionar();
    }
    return 0;
}

int ordenarPre(Registro *retroceso)
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
int recorrerPre()
{
    aux = raiz;

    if (aux != NULL)
    {
        ordenarPre(aux);
    }
    return 0;
}

int ordenarIn(Registro *retroceso)
{
    if (retroceso->izq != NULL)
    {
        ordenarPre(retroceso->izq);
    }
    if (retroceso->der != NULL)
    {
        ordenarPre(retroceso->der);
    }
    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "Codigo: " << retroceso->Codigo << endl;
    cout << "Fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes << "/" << retroceso->Año << endl;
    cout << " " << endl;

    return 0;
}
int recorrerIn()
{
    aux = raiz;

    if (aux != NULL)
    {
        ordenarIn(aux);
    }
    return 0;
}

int ordenarPost(Registro *retroceso)
{
    if (retroceso->izq != NULL)
    {
        ordenarPre(retroceso->izq);
    }
    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "codigo: " << retroceso->Codigo << endl;
    cout << "fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes << "/" << retroceso->Año << endl;
    cout << " " << endl;

    if (retroceso->der != NULL)
    {
        ordenarPre(retroceso->der);
    }
    return 0;
}

int recorrerPost()
{
    aux = raiz;

    if (aux != NULL)
    {
        ordenarPost(aux);
    }
    return 0;
}

int buscador = 0;

int buscar()
{
    if (raiz == NULL) {
        cout << "No hay estudiantes en el registro" << endl;
        return 0;
    }

    aux = raiz;

    cout << "Ingrese el codigo del estudiante que desea buscar: ";
    cin >> buscador;

    if (buscador != aux->Codigo){
        cout << "Estudiante no registrado" << endl;
    }

    if (aux != NULL)
    {
        if (buscador != aux->Codigo)
        {
            if (aux->der != NULL && aux->izq != NULL)
            {
                aux = aux->der;
                aux = aux->izq;
                buscar();
            }
        }
        else if (buscador == aux->Codigo)
        {
            cout << "Estudiante encontrado" << endl;
            cout << "Nombre: " << aux->Nombre << " " << aux->Apellido << endl;
            cout << "Codigo: " << aux->Codigo << endl;
            cout << "Fecha de nacimiento: " << aux->Dia << "/" << aux->Mes << "/" << aux->Año << endl;
            cout << " " << endl;
        }
    }
    return 0;
}

int main()
{
    int opcion = 0;
    do
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
            registrar();
            break;
        case 2:
            buscar();
            break;
        case 3:
            cout << "Recorrido en Pre_orden:" << endl;
            recorrerPre();
            break;
        case 4:
            cout << "Recorrido en In_orden:" << endl;
            recorrerIn();
            break;
        case 5:
            cout << "Recorrido en Post_orden:" << endl;
            recorrerPost();
            break;
        case 6:
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