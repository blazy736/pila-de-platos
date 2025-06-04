#include <iostream>
#include <string>
#include <locale>
using namespace std;
struct Nodo {
    string plato;
    Nodo* siguiente;
};

class Pila {
private:
    Nodo* tope;
    int tamano;
public:
    Pila() {
        tope = NULL;
        tamano = 0;
    }

    void ingresoP(string plato) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->plato = plato;
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
        tamano++;
        cout << "El plato " << plato << " se ha insertado." << endl;
    }

    void EliminarP() {
        if (tope == NULL) {
            cout << "La pila de platos está vacía." << endl;
        } else {
            Nodo* temp = tope;
            cout << "El plato " << tope->plato << " se ha eliminado." << endl;
            tope = tope->siguiente;
            delete temp;
            tamano--;
        }
    }

    string UltimoE() {
        if (tope != NULL) {
            return tope->plato;
        } else {
            return "Pila vacía.";
        }
    }

    bool Vacio() {
        return tope == NULL;
    }

    void Mostrarp() {
        if (Vacio()) {
            cout << "La pila de platos está vacía." << endl;
        } else {
            cout << "Lista de platos:" << endl;
            Nodo* temp = tope;
            while (temp != NULL) {
                cout << temp->plato << " ";
                temp = temp->siguiente;
            }
            cout << endl;
        }
    }

    int TamanoPila() {
        return tamano;
    }

    void VaciarPila() {
        while (!Vacio()) {
            EliminarP();
        }
        cout << "Todos los elementos han sido eliminados." << endl;
    }
};
struct NodoInt {
    int valor;
    NodoInt* siguiente;
};

class PilaInt {
private:
    NodoInt* tope;
public:
    PilaInt() {
        tope = NULL;
    }
    void push(int valor) {
        NodoInt* nuevo = new NodoInt();
        nuevo->valor = valor;
        nuevo->siguiente = tope;
        tope = nuevo;
    }
    int pop() {
        if (tope == NULL) {
            cout << "La pila de enteros está vacía." << endl;
            return 1; // Valor por defecto en caso de error
        } else {
            int val = tope->valor;
            NodoInt* temp = tope;
            tope = tope->siguiente;
            delete temp;
            return val;
        }
    }
    bool empty() {
        return tope == NULL;
    }
};

void resolverFactorial() {
    int n;
    cout << "\n--- Resolver Problema Matemático: Calcular Factorial ---" << endl;
    cout << "Problema: Calcular el factorial de un número entero n (n!)." << endl;
    cout << "Definición: n! = n * (n-1) * (n-2) * ... * 1, siendo 0! = 1." << endl;
    cout << "Ingrese un número entero no negativo: ";
    cin >> n;
    
    // Verificación básica e interpretación del input.
    if (n < 0) {
        cout << "\nInterpretación: El número ingresado (" << n << ") es negativo." << endl;
        cout << "El factorial está definido solo para enteros no negativos." << endl;
        return;
    }
    
    cout << "\nInterpretación: Ha ingresado n = " << n << ". Procederemos a calcular " << n << "!" << endl;
    cout << "Paso 1: La pila se utilizará para almacenar los números del 1 hasta " << n << "." << endl;
    
    PilaInt pila;
    for (int i = 1; i <= n; i++) {
        pila.push(i);
        cout << "Interpretación: Se agrega el factor " << i << " a la pila." << endl;
    }
    
    long long resultado = 1;
    cout << "\nPaso 2: Se extraen los factores de la pila para multiplicarlos:" << endl;
    while (!pila.empty()) {
        int factor = pila.pop();
        cout << "Interpretación: Se extrae el factor " << factor << " de la pila." << endl;
        resultado *= factor;
        cout << "Interpretación: Resultado intermedio = " << resultado << endl;
    }
    
    cout << "\nInterpretación: El factorial de " << n << " (n!) es: " << resultado << endl;
}
int main() {
    setlocale(LC_CTYPE, "Spanish");
    
    Pila pilaPlatos;
    int opcion;
    string plato;
    
    do {
        cout << "\n=== MENÚ PRINCIPAL ===" << endl;
        cout << "1. Insertar plato en la pila" << endl;
        cout << "2. Eliminar plato de la pila" << endl;
        cout << "3. Ver plato superior" << endl;
        cout << "4. Verificar si la pila de platos está vacía" << endl;
        cout << "5. Mostrar todos los platos" << endl;
        cout << "6. Mostrar tamaño de la pila de platos" << endl;
        cout << "7. Eliminar todos los platos de la pila" << endl;
        cout << "8. Resolver problema matemático: Calcular factorial" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del plato: ";
                cin >> plato;
                pilaPlatos.ingresoP(plato);
                break;
            case 2:
                pilaPlatos.EliminarP();
                break;
            case 3:
                cout << "Plato superior: " << pilaPlatos.UltimoE() << endl;
                break;
            case 4:
                cout << (pilaPlatos.Vacio() ? "La pila de platos está vacía." : "La pila de platos tiene elementos.") << endl;
                break;
            case 5:
                pilaPlatos.Mostrarp();
                break;
            case 6:
                cout << "Tamaño de la pila de platos: " << pilaPlatos.TamanoPila() << endl;
                break;
            case 7:
                pilaPlatos.VaciarPila();
                break;
            case 8:
                resolverFactorial();
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 9);

    return 0;
}
