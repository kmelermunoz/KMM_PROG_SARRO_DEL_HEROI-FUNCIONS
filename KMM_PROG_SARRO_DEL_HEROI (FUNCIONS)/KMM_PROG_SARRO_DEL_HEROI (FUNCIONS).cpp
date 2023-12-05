#include <iostream>
#include <vector>
#include <algorithm> // Para la función find

using namespace std;

// Declaración de funciones
char menu();
void entrar_objecte(vector<string>& inventari);
void eliminar_objecte(vector<string>& inventari);
void entra_num_objectes(vector<string>& inventari);
void llistar_elements(const vector<string>& inventari);
void buscar_element(const vector<string>& inventari);

int main() {
    // Inicialización del inventario como un vector de strings
    vector<string> inventari;

    // Menú principal
    char opcio;
    do {
        opcio = menu();

        // Ejecutar la opción seleccionada
        switch (opcio) {
        case '1':
            entrar_objecte(inventari);
            break;
        case '2':
            eliminar_objecte(inventari);
            break;
        case '3':
            entra_num_objectes(inventari);
            break;
        case '4':
            llistar_elements(inventari);
            break;
        case '5':
            buscar_element(inventari);
            break;
        case '6':
            inventari.clear(); // Borrar todos los elementos del inventario
            cout << "L'inventari ha estat buidat.\n";
            break;
        case '7':
            cout << "Adeu!\n";
            break;
        default:
            cout << "Opcio no valida. Torna a intentar.\n";
        }

    } while (opcio != '7');

    return 0;
}

// Función para mostrar el menú y obtener la opción del usuario
char menu() {
    // Mostrar opciones del menú
    char opcio;
    cout << "\nMenu:\n";
    cout << "1. Entrar objecte a l'inventari\n";
    cout << "2. Eliminar objecte de l'inventari\n";
    cout << "3. Entrar una quantitat determinada d'objectes\n";
    cout << "4. Llistar elements de l'inventari\n";
    cout << "5. Buscar un element a l'inventari\n";
    cout << "6. Buidar tot l'inventari\n";
    cout << "7. Sortir\n";
    cout << "Selecciona una opcio (1-7): ";
    cin >> opcio;
    return opcio;
}

// Función para añadir un objeto al inventario
void entrar_objecte(vector<string>& inventari) {
    // Pedir y añadir un objeto al inventario
    string nou_objecte;
    cout << "Entra el nom de l'objecte: ";
    cin >> nou_objecte;
    inventari.push_back(nou_objecte);
    cout << nou_objecte << " ha estat afegit a l'inventari.\n";
}

// Función para eliminar un objeto del inventario
void eliminar_objecte(vector<string>& inventari) {
    if (!inventari.empty()) {
        // Pedir y eliminar un objeto del inventario
        cout << "Entra el nom de l'objecte a eliminar: ";
        string nom_objecte;
        cin >> nom_objecte;

        // Utilizar la función find para buscar el elemento
        auto it = find(inventari.begin(), inventari.end(), nom_objecte);

        if (it != inventari.end()) {
            inventari.erase(it); // Borrar el elemento encontrado
            cout << nom_objecte << " ha estat eliminat de l'inventari.\n";
        }
        else {
            cout << nom_objecte << " no es troba a l'inventari.\n";
        }
    }
    else {
        cout << "L'inventari esta buit. No es pot eliminar cap objecte.\n";
    }
}

// Función para añadir una cantidad determinada de objetos al inventario
void entra_num_objectes(vector<string>& inventari) {
    // Pedir cantidad y añadirla al inventario
    int num_objectes;
    cout << "Entra el nombre d'objectes que vols afegir:";
    cin >> num_objectes;

    for (int i = 0; i < num_objectes; ++i) {
        entrar_objecte(inventari);
    }
}

// Función para listar los elementos del inventario
void llistar_elements(const vector<string>& inventari) {
    cout << "\nInventari de l'heroi:\n";
    for (const auto& element : inventari) {
        cout << "- " << element << "\n";
    }
}

// Función para buscar un elemento en el inventario
void buscar_element(const vector<string>& inventari) {
    if (!inventari.empty()) {
        // Pedir y buscar un elemento en el inventario
        cout << "Entra el nom de l'objecte a buscar: ";
        string nom_objecte;
        cin >> nom_objecte;

        // Utilizar la función find para buscar el elemento
        auto it = find(inventari.begin(), inventari.end(), nom_objecte);

        if (it != inventari.end()) {
            cout << nom_objecte << " es troba a l'inventari.\n";
        }
        else {
            cout << nom_objecte << " no es troba a l'inventari.\n";
        }
    }
    else {
        cout << "L'inventari esta buit. No es pot buscar cap element.\n";
    }
}
