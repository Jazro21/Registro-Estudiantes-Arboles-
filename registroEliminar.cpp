#include <iostream>
#include <malloc.h>

using namespace std;

struct Registro {
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

int posicionar() {
  if (aux->Dia == aux2->Dia && aux->Mes == aux2->Mes &&
      aux->Año == aux2->Año) // para la derecha
  {
    if (aux2->der != NULL) {
      aux2 = aux2->der;
      posicionar();
    } else {
      aux2->der = aux; // ¿Por qué?
    }
  }

  if (aux->Dia != aux2->Dia && aux->Mes != aux2->Mes &&
      aux->Año != aux2->Año) // para la izquierda
  {
    if (aux2->izq != NULL) {
      aux2 = aux2->izq;
      posicionar();
    } else {
      aux2->izq = aux; // ¿Por qué?
    }
  }
  return 0;
}

int registrar() {
  aux = (struct Registro *)malloc(sizeof(struct Registro));

  cout << "Ingrese el codigo: ";
  cin >> aux->Codigo;

  // Check if the ID is already in use
  aux2 = raiz;
  bool idExists = false;
  while (aux2 != NULL) {
    if (aux->Codigo == aux2->Codigo) {
      cout << "El Código ya está en uso. Ingrese un código diferente." << endl;
      idExists = true;
      break;
    }
    if (aux->Codigo > aux2->Codigo) {
      aux2 = aux2->der;
    } else {
      aux2 = aux2->izq;
    }
  }

  if (!idExists) {
    cout << "Ingrese el nombre: ";
    cin >> aux->Nombre;

    cout << "Ingrese el apellido: ";
    cin >> aux->Apellido;

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
    } else // si ya hay una raiz, llama a el metodo posicionar (se utiliza aux2)
    {
      aux2 = raiz;
      posicionar();
    }
  }

  return 0;
}

int ordenarPre(Registro *retroceso) {
  cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
  cout << "Codigo: " << retroceso->Codigo << endl;
  cout << "Fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes
       << "/" << retroceso->Año << endl;
  cout << " " << endl;
  if (retroceso->izq != NULL) {
    ordenarPre(retroceso->izq);
  }
  if (retroceso->der != NULL) {
    ordenarPre(retroceso->der);
  }
  return 0;
}
int recorrerPre() {
  aux = raiz;

  if (aux != NULL) {
    ordenarPre(aux);
  }
  return 0;
}

int ordenarIn(Registro *retroceso) {
  if (retroceso->izq != NULL) {
    ordenarPre(retroceso->izq);
  }
  if (retroceso->der != NULL) {
    ordenarPre(retroceso->der);
  }
  cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
  cout << "Codigo: " << retroceso->Codigo << endl;
  cout << "Fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes
       << "/" << retroceso->Año << endl;
  cout << " " << endl;

  return 0;
}
int recorrerIn() {
  aux = raiz;

  if (aux != NULL) {
    ordenarIn(aux);
  }
  return 0;
}

int ordenarPost(Registro *retroceso) {
  if (retroceso->izq != NULL) {
    ordenarPre(retroceso->izq);
  }
  cout << "Nombre: " << retroceso->Nombre << " " << retroceso->Apellido << endl;
  cout << "codigo: " << retroceso->Codigo << endl;
  cout << "fecha de nacimiento: " << retroceso->Dia << "/" << retroceso->Mes
       << "/" << retroceso->Año << endl;
  cout << " " << endl;

  if (retroceso->der != NULL) {
    ordenarPre(retroceso->der);
  }
  return 0;
}

int recorrerPost() {
  aux = raiz;

  if (aux != NULL) {
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


void reconectar(Registro *nodoEliminar) {
  if (nodoEliminar->der == NULL && nodoEliminar->izq != NULL) {
    if (nodoEliminar == aux2->izq) {
      aux2->izq = nodoEliminar->izq;
      free(nodoEliminar);
    } else if (nodoEliminar == aux2->der) {
      aux2->der = nodoEliminar->izq;
      free(nodoEliminar);
    }
  } else if (nodoEliminar->izq == NULL && nodoEliminar->der != NULL) {
    if (nodoEliminar == aux2->izq) {
      aux2->izq = nodoEliminar->der;
      free(nodoEliminar);
    } else if (nodoEliminar == aux2->der) {
      aux2->der = nodoEliminar->der;
      free(nodoEliminar);
    }
  } else {
    if (nodoEliminar == aux2->izq) {
      aux2->izq = nodoEliminar->der;
      free(nodoEliminar);
    } else if (nodoEliminar == aux2->der) {
      aux2->der = nodoEliminar->izq;
      free(nodoEliminar);
    }
  }
}
void eliminarEstudiante() {
  int codigoEliminar;

  cout << "Ingrese el código del estudiante a eliminar: ";
  cin >> codigoEliminar;
  aux = raiz;
  aux2 = NULL;
  while (aux != NULL) {
    if (codigoEliminar == aux->Codigo) {
      if (aux == raiz) {
        if (aux->der == NULL && aux->izq == NULL) {
          raiz = NULL;
        } else if (aux->der == NULL) {
          raiz = aux->izq;
        } else if (aux->izq == NULL) {
          raiz = aux->der;
        } else {
          aux2 = aux->der;
          while (aux2->izq != NULL) {
            aux2 = aux2->izq;
          }
          aux2->izq = aux->izq;
          raiz = aux->der;
        }
        free(aux);
        cout << "Estudiante con código " << codigoEliminar
             << " eliminado exitosamente" << endl;
        return;
      } else {
        reconectar(aux);
        cout << "Estudiante con código " << codigoEliminar
             << " eliminado exitosamente" << endl;
        return;
      }
    }

    aux2 = aux;
    if (codigoEliminar > aux->Codigo) {
      aux = aux->der;
    } else {
      aux = aux->izq;
    }
  }
  cout << "Estudiante no encontrado en el registro" << endl;
}

int main() {
  int opcion = 0;
  do {

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
      eliminarEstudiante();
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
