#include <iostream>
#include <vector>
#include <algorithm> // Per a la funció find

using namespace std;

// Declaració de funcions
char menu();
void entrar_objecte(vector<string>& inventari);
void eliminar_objecte(vector<string>& inventari);
void entra_num_objectes(vector<string>& inventari);
void llistar_elements(const vector<string>& inventari);
void buscar_element(const vector<string>& inventari);

int main() {
    // Inicialització de l'inventari com a vector de strings
    vector<string> inventari;

    // Menú principal
    char opcio;
    do {
        opcio = menu();

        // Executar l'opció seleccionada
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
            inventari.clear(); // Buidar tots els elements de l'inventari
            cout << "L'inventari ha estat buidat.\n";
            break;
        case '7':
            cout << "Adeu!\n";
            break;
        default:
            cout << "Opció no vàlida. Torna a intentar.\n";
        }

    } while (opcio != '7');

    return 0;
}

// Funció per mostrar el menú i obtenir l'opció de l'usuari
char menu() {
    // Mostrar opcions del menú
    char opcio;
    cout << "\nMenu:\n";
    cout << "1. Entrar objecte a l'inventari\n";
    cout << "2. Eliminar objecte de l'inventari\n";
    cout << "3. Entrar una quantitat determinada d'objectes\n";
    cout << "4. Llistar elements de l'inventari\n";
    cout << "5. Buscar un element a l'inventari\n";
    cout << "6. Buidar tot l'inventari\n";
    cout << "7. Sortir\n";
    cout << "Selecciona una opció (1-7): ";
    cin >> opcio;
    return opcio;
}

// Funció per afegir un objecte a l'inventari
void entrar_objecte(vector<string>& inventari) {
    // Demanar i afegir un objecte a l'inventari
    string nou_objecte;
    cout << "Entra el nom de l'objecte: ";
    cin >> nou_objecte;
    inventari.push_back(nou_objecte);
    cout << nou_objecte << " ha estat afegit a l'inventari.\n";
}

// Funció per eliminar un objecte de l'inventari
void eliminar_objecte(vector<string>& inventari) {
    if (!inventari.empty()) {
        // Demanar i eliminar un objecte de l'inventari
        cout << "Entra el nom de l'objecte a eliminar: ";
        string nom_objecte;
        cin >> nom_objecte;

        // Utilitzar la funció find per buscar l'element
        auto it = find(inventari.begin(), inventari.end(), nom_objecte);

        if (it != inventari.end()) {
            inventari.erase(it); // Eliminar l'element trobat
            cout << nom_objecte << " ha estat eliminat de l'inventari.\n";
        }
        else {
            cout << nom_objecte << " no es troba a l'inventari.\n";
        }
    }
    else {
        cout << "L'inventari està buit. No es pot eliminar cap objecte.\n";
    }
}

// Funció per afegir una quantitat determinada d'objectes a l'inventari
void entra_num_objectes(vector<string>& inventari) {
    // Demanar quantitat i afegir-la a l'inventari
    int num_objectes;
    cout << "Entra el nombre d'objectes que vols afegir:";
    cin >> num_objectes;

    for (int i = 0; i < num_objectes; ++i) {
        entrar_objecte(inventari);
    }
}

// Funció per llistar els elements de l'inventari
void llistar_elements(const vector<string>& inventari) {
    cout << "\nInventari de l'heroi:\n";
    for (const auto& element : inventari) {
        cout << "- " << element << "\n";
    }
}

// Funció per buscar un element a l'inventari
void buscar_element(const vector<string>& inventari) {
    if (!inventari.empty()) {
        // Demanar i buscar un element a l'inventari
        cout << "Entra el nom de l'objecte a buscar: ";
        string nom_objecte;
        cin >> nom_objecte;

        // Utilitzar la funció find per buscar l'element
        auto it = find(inventari.begin(), inventari.end(), nom_objecte);

        if (it != inventari.end()) {
            cout << nom_objecte << " es troba a l'inventari.\n";
        }
        else {
            cout << nom_objecte << " no es troba a l'inventari.\n";
        }
    }
    else {
        cout << "L'inventari està buit. No es pot buscar cap element.\n";
    }
}
