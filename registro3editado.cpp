//Notas de Lic. Pérez

// Preorden funciona correctamente
// Estuve intentando cambiar buscar() y crear eliminar() pero fueron intentos fallidos
// Aparte de esos dos, faltaría InOrden y PreOrden(Algunas veces entraba en bucle y en otras ocasiones presentaba el mismo problema inicial)
// El codigo no se cierra subitamente, salvo en buscar() que creo que tiene algo mal allí
// He intentado de todo pero nada, hoy no fue para nada productivo, sentí que perdí el día. Desde las 3pm intentando y nada de nada hasta ahora que son las 9:30 p.m.
// Afortunadamente, el ejercicio del parqueadero está listo y funciona correctamente, y la base de este codigo esta presente, hay que tratar de resolver dudas en este ultimo dia o buscar por ayuda, ya caí en la locura.

#include <iostream>
#include <malloc.h>

using namespace std;

struct Registro4 {
  char Nombre[20];
  char Apellido[20];

  int Codigo = 0;
  int Dia = 0;
  int Mes = 0;
  int Año = 0;

  Registro4 *izq;
  Registro4 *der;
};
Registro4 *temp = NULL;

Registro4 *aux1 = NULL;
Registro4 *aux2 = NULL;
Registro4 *aux3 = NULL;
Registro4 *aux4 = NULL;

Registro4 *raiz = NULL;
Registro4 *raiz2 = NULL;

// metodo para pedir los datos

int Datos() {
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

int posicionarFecha() {
  if (aux1->Dia == aux2->Dia && aux1->Mes == aux2->Mes &&
      aux1->Año == aux2->Año) // para la derecha
  {
    if (aux2->der != NULL) {
      aux2 = aux2->der;
      posicionarFecha();
    } else {
      aux2->der = aux1; // ¿Por qué?
    }
  }

  if (aux1->Dia != aux2->Dia && aux1->Mes != aux2->Mes &&
      aux1->Año != aux2->Año) // para la izquierda
  {
    if (aux2->izq != NULL) {
      aux2 = aux2->izq;
      posicionarFecha();
    } else {
      aux2->izq = aux1; // ¿Por qué?
    }
  }
  return 0;
}

int posicionarCodigo() {
  if (aux3->Codigo > aux2->Codigo) // para la derecha
  {
    if (aux2->der != NULL) {
      aux2 = aux2->der;
      posicionarFecha();
    } else {
      aux2->der = aux3; // ¿Por qué?
    }
  }

  if (aux3->Codigo < aux2->Codigo) // para la izquierda
  {
    if (aux2->izq != NULL) {
      aux2 = aux2->izq;
      posicionarFecha();
    } else {
      aux2->izq = aux3; // ¿Por qué?
    }
  }
  return 0;
}

// metodos de registrar los estudiantes

int registrarFecha() {
  if (raiz == NULL) // si no hay raiz, se libera memoria (se utiliza aux1)
  {
    raiz = aux1;
    raiz2 = aux1;
    aux1 = NULL;
    free(aux1);
  } else // si ya hay una raiz, llama a el metodo posicionarFecha (se utiliza
         // aux2)
  {
    aux2 = raiz;
    posicionarFecha();
  }

  return 0;
}

int registrarCodigo() {

  if (raiz2 == NULL) // si no hay raiz, se libera memoria (se utiliza aux3)
  {
    raiz2 = aux3;
    raiz2 = aux3;
    aux3 = NULL;
    free(aux3);
  } else // si ya hay una raiz, llama a el metodo posicionarFecha (se utiliza
         // aux2)
  {
    aux2 = raiz2;
    posicionarCodigo();
  }
  return 0;
}

// Metodos de ordenamiento

int ordenarPre(Registro4 *retroceso) {
    if (retroceso == NULL) {
      return false;
    } else {
      cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
      cout << "Codigo: " << retroceso->Codigo << endl;
      cout << "Fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes
           << "/" << retroceso->Año << endl;
      cout << " " << endl;
      if (!ordenarPre(retroceso->izq)) {
        return false;
      }
      if (!ordenarPre(retroceso->der)) {
        return false;
      }
    }
    return true;
}

void ordenarIn(Registro4* retroceso) {
    if (retroceso == nullptr) {
        return;
    }

    if (retroceso->izq != nullptr) {
        ordenarIn(retroceso->izq);
    }

    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "Codigo: " << retroceso->Codigo << endl;
    cout << "Fecha de Nacimiento: " << retroceso->Dia << "/" << retroceso->Mes << "/" << retroceso->Año << endl;
    cout << endl;

    if (retroceso->der != nullptr) {
        ordenarIn(retroceso->der);
    }
}

void ordenarPost(Registro4 *retroceso) {
  if (retroceso == NULL) {
    return;
  } else {
    ordenarPost(retroceso->izq);
    ordenarPost(retroceso->der);
    cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
    cout << "codigo: " << retroceso->Codigo << endl;
    cout << "fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes
         << "/" << retroceso->Año << endl;
    cout << " " << endl;
  }
}
// Metodos para recorrer el arbol

// Pre orden
int recorrerPreFecha() {
  if (raiz != NULL) {
    ordenarPre(raiz);
  }
  return 0;
}
int recorrerPreCodigo() {
  if (raiz2 != NULL) {
    ordenarPre(raiz2);
  }
  return 0;
}
int recorrerInFecha() {
  if (raiz != NULL) {
    ordenarIn(raiz);
  }
  return 0;
}
int recorrerInCodigo() {
  if (raiz2 != NULL) {
    ordenarIn(raiz2);
  }
  return 0;
}
int recorrerPostFecha() {
  if (raiz != NULL) {
    ordenarPost(raiz);
  }
  return 0;
}
int recorrerPostCodigo() {
  if (raiz2 != NULL) {
    ordenarPost(raiz2);
  }
  return 0;
}

int codigo = 0;
int buscador = 0;

int buscar()
{
    if (raiz && raiz == NULL)
    {
        cout << "No hay estudiantes en el registro" << endl;
        return 0;
    }

    aux1 == raiz && raiz2;

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

void eliminarEstudiante() {
  
}

int opcion = 0;
int opcion2 = 0;

int main() {
  int opcion = 0;
  do{

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

  switch (opcion) {
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
        cin >> opcion2;

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
        cin >> opcion2;

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
        cin >> opcion2;

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

    case 6:
        eliminarEstudiante();
        break;

    case 7:
        cout << "Finalizando programa" << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
  }

  }while (opcion!=7);

  return 0;
}
