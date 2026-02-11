#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstring>

using namespace std;

struct Clasificacion {
    char clasificacionE[11] = "Para todos";
    char clasificacionET[15] = "Para todos +10";
    char clasificacionT[13] = "Adolescentes";
    char clasificacionM[11] = "Maduro +17";
    char clasificacionAO[17] = "Solo Adultos +18";
};

struct Juego {
    char nombreJuego[100] = { "\0" };
    char clasificacion[20] = { "\0" };
};

struct Usuario {
    char nombreCuenta[50] = { "\0" };
    char nombreApellido[100] = { "\0" };
    char clave[17] = { "\0" };
    Juego juegoFavorito;
};
vector<Usuario> usuarios;
int lugar = NULL;

struct Cuenta {
    char nombre[50] = { "\0" };
    char clave[17] = { "\0" };
};

int opcionSalir;
void salirApp() {
    system("cls");
    cout << "¿Seguro que quieres salir? s/n ";
    opcionSalir = _getch();
    switch (opcionSalir) {
    case 110:
        break;
    case 115: cout << "\n¡Gracias por ver!\n"; return;
        break;
    }
}

bool espaciosBlanco(char texto[], int largo) {
    for (int i = 0; i <= largo; i++) {
        if (texto[i] == ' ')
        {
            cout << "\n\tEl nombre de usuario no puede contener espacios en blanco" << endl;
            cout << "\tIntente de nuevo por favor." << endl;
            cout << "\n";
            return true;
        }
    }
    return false;
}

bool usuarioUnico(const char texto[]) {
    for (size_t i = 0; i < usuarios.size(); i++) {
        if (strcmp(texto, usuarios[i].nombreCuenta) == 0) {
            cout << "\n\tEse nombre de usuario ya existe" << endl;
            cout << "\tPor favor utilice otro nombre." << endl;
            cout << "\n";
            return false;
        }
    }
    return true;
}

void ingresarClave(char clave[], int largo) {
    int i = 0;
    char caracter;

    while (i < largo - 1) {
        caracter = _getch();
        if (caracter == 13) {  // ENTER
            break;
        }
        if (caracter == 8) {   // BACKSPACE
            if (i > 0) { i--; cout << "\b \b"; }
        }
        else { clave[i++] = caracter; cout << "*"; }
    }
    clave[i] = '\0';
}

bool autorizacion() {
    system("cls");
    cout << "--- Acceso de Usuario ---" << endl;
    cout << "Para salir, deje vacío el campo y presione enter\n" << endl;
    Cuenta auxiliar;
    bool correcto = false;
    do {
        bool encontrado = false;
        cout << "Cuenta: ";
        cin.getline(auxiliar.nombre, 50);
        if (strcmp(auxiliar.nombre, "") == 0) {
            cout << "\nRegistro cancelado.\n" << endl;
            system("pause");
            return false;
        }
        else {
            for (size_t i = 0; i < usuarios.size(); i++) {
                if (strcmp(auxiliar.nombre, usuarios[i].nombreCuenta) == 0) {
                    encontrado = true;
                    lugar = i;
                }
            }
            if (encontrado) {
                cout << "\nClave: ";
                //cin.getline(auxiliar.clave, 17);
                ingresarClave(auxiliar.clave, 17);
                if (strcmp(auxiliar.clave, "") == 0) {
                    cout << "\nRegistro cancelado.\n";
                    system("pause");
                    return false;
                }
                if (strcmp(auxiliar.clave, usuarios[lugar].clave) == 0) {
                    correcto = true;
                    return correcto;
                }
                else {
                    cout << "\t¡Clave incorrecta!" << endl;
                    system("pause");
                    continue;
                }
            }
            else {
                cout << "\t¡Usuario no válido o inexistente!" << endl;
                system("pause");
                continue;
            }
        }

    } while (correcto != true);

    return false;
}

void menuRegistro() {
    bool correcto = false;
    Usuario registro;
    system("cls");
    cout << "Registro de Usuario";
    cout << " (Para salir, deje vacío el campo y presione enter)\n" << endl;
    system("pause");
    do {
        system("cls");
        cout << "\nIngrese su Nombre de Usuario" << endl;
        cin.getline(registro.nombreCuenta, 50);
        if (strcmp(registro.nombreCuenta, "") == 0) {
            cout << "\nRegistro cancelado.\n";
            system("pause");
            return;
        }
        else {
            if (espaciosBlanco(registro.nombreCuenta, strlen(registro.nombreCuenta)) == false) {
                if (usuarioUnico(registro.nombreCuenta) == true) {
                    system("cls");
                    cout << "\nIngrese su Nombre y Apellido" << endl;
                    cin.getline(registro.nombreApellido, 100);
                    if (strcmp(registro.nombreApellido, "") == 0) {
                        cout << "\nRegistro cancelado.\n";
                        system("pause");
                        return;
                    }
                    system("cls");
                    cout << "\nIngrese su clave de acceso";
                    cout << "\t(La clave solo puede tener máximo 16 dígitos)" << endl;
                    ingresarClave(registro.clave, 17);
                    //cin.getline(registro.clave, 16);
                    if (strcmp(registro.clave, "") == 0) {
                        cout << "\nRegistro cancelado.\n";
                        system("pause");
                        return;
                    }
                    system("cls");
                    cout << "\nIngrese su juego favorito: " << endl;
                    cin.getline(registro.juegoFavorito.nombreJuego, 100);
                    system("cls");
                    cout << "\n¿Qué Clasificación es el juego?" << endl;
                    Clasificacion clasificaciones;
                    cout << "Presione 1: " << clasificaciones.clasificacionE << endl;
                    cout << "Presione 2: " << clasificaciones.clasificacionET << endl;
                    cout << "Presione 3: " << clasificaciones.clasificacionT << endl;
                    cout << "Presione 4: " << clasificaciones.clasificacionM << endl;
                    cout << "Presione 5: " << clasificaciones.clasificacionAO << endl;
                    cout << "Presione 0 para salir" << endl;
                    int opcion = _getch();
                    switch (opcion) {
                    case 48: cout << "\nRegistro cancelado.\n"; system("pause"); return;
                        break;
                    case 49: strcpy_s(registro.juegoFavorito.clasificacion, clasificaciones.clasificacionE);
                        break;
                    case 50: strcpy_s(registro.juegoFavorito.clasificacion, clasificaciones.clasificacionET);
                        break;
                    case 51: strcpy_s(registro.juegoFavorito.clasificacion, clasificaciones.clasificacionT);
                        break;
                    case 52: strcpy_s(registro.juegoFavorito.clasificacion, clasificaciones.clasificacionM);
                        break;
                    case 53: strcpy_s(registro.juegoFavorito.clasificacion, clasificaciones.clasificacionAO);
                        break;
                    default: cout << "\nLa opción no es valida\n" << endl; system("pause");
                        break;
                    }
                    correcto = true;
                }
                else {
                    system("pause");
                    continue;
                }
            }
            else {
                system("pause");
                continue;
            }
        }
        if (correcto) {
            usuarios.push_back(registro);
            system("cls");
            cout << "\n\t¡Usuario registrado!" << endl;
            cout << '\n';
            system("pause");
        }

    } while (correcto != true);
}

int salirCuenta(int sesion) {
    system("cls");
    cout << "\n¡Hasta Luego!\n" << endl;
    sesion = -1;
    system("pause");
    return sesion;
}

void eliminarCuenta(int sesion) {
    usuarios.erase(usuarios.begin() + sesion);
}

void modificarCuenta(int sesion) {
    system("cls");
    cout << "Modifique su perfil" << endl;
    bool modificado = false;
    Usuario cambio;
    do {
        system("cls");
        cout << "Nueva cuenta: " << endl;
        cin.getline(cambio.nombreCuenta, 50);
        if (strcmp(cambio.nombreCuenta, "") == 0) {
            cout << "\nRegistro cancelado.\n";
            system("pause");
            return;
        }
        else {
            if (espaciosBlanco(cambio.nombreCuenta, strlen(cambio.nombreCuenta)) == false) {
                if (usuarioUnico(cambio.nombreCuenta) == true) {
                    system("cls");
                    cout << "Nueva clave: " << endl;
                    ingresarClave(cambio.clave, 17);
                    if (strcmp(cambio.clave, "") == 0) {
                        cout << "\nRegistro cancelado.\n";
                        system("pause");
                        return;
                    }
                    system("cls");
                    cout << "Juego favorito: " << endl;
                    cin.getline(cambio.juegoFavorito.nombreJuego, 100);
                    system("cls");
                    cout << "Claisificación: " << endl;
                    Clasificacion clasificaciones;
                    cout << "Presione 1: " << clasificaciones.clasificacionE << endl;
                    cout << "Presione 2: " << clasificaciones.clasificacionET << endl;
                    cout << "Presione 3: " << clasificaciones.clasificacionT << endl;
                    cout << "Presione 4: " << clasificaciones.clasificacionM << endl;
                    cout << "Presione 5: " << clasificaciones.clasificacionAO << endl;
                    cout << "Presione 0 para salir" << endl;
                    int opcion = _getch();
                    switch (opcion) {
                    case 48: cout << "\nRegistro cancelado.\n"; system("pause"); return;
                        break;
                    case 49: strcpy_s(cambio.juegoFavorito.clasificacion, clasificaciones.clasificacionE);
                        break;
                    case 50: strcpy_s(cambio.juegoFavorito.clasificacion, clasificaciones.clasificacionET);
                        break;
                    case 51: strcpy_s(cambio.juegoFavorito.clasificacion, clasificaciones.clasificacionT);
                        break;
                    case 52: strcpy_s(cambio.juegoFavorito.clasificacion, clasificaciones.clasificacionM);
                        break;
                    case 53: strcpy_s(cambio.juegoFavorito.clasificacion, clasificaciones.clasificacionAO);
                        break;
                    default: cout << "\nLa opción no es valida\n" << endl; system("pause");
                        break;
                    }
                    modificado = true;
                }
                else {
                    system("pause");
                    continue;
                }
            }
            else {
                system("pause");
                continue;
            }
        }
        if (modificado) {
            strcpy_s(usuarios[sesion].nombreCuenta, cambio.nombreCuenta);
            strcpy_s(usuarios[sesion].clave, cambio.clave);
            strcpy_s(usuarios[sesion].juegoFavorito.nombreJuego, cambio.juegoFavorito.nombreJuego);
            strcpy_s(usuarios[sesion].juegoFavorito.clasificacion, cambio.juegoFavorito.clasificacion);
        }
    } while (modificado != true);
}

void mostrarLista() {
    system("cls");
    size_t cantidad = usuarios.size();
    cout << "--- LISTA DE PERSONAS ---\n" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << usuarios[i].nombreCuenta << " / " << usuarios[i].nombreApellido
            << " / " << usuarios[i].juegoFavorito.nombreJuego << " / " << usuarios[i].juegoFavorito.clasificacion << endl;
    }
    cout << '\n';
    system("pause");
}

int inicio(int sesion) {
    system("color 71");
    int opcionMenu;
    do {
        system("cls");
        cout << "¡Bienvenido\t" << usuarios[lugar].nombreApellido << "!" << endl;
        cout << "Información de la cuenta" << endl;
        cout << "Cuenta: " << usuarios[lugar].nombreCuenta << endl;
        cout << "Clave: " << usuarios[lugar].clave << endl;
        cout << "Juego Favorito: " << usuarios[lugar].juegoFavorito.nombreJuego << endl;
        cout << "Clasificación: " << usuarios[lugar].juegoFavorito.clasificacion << endl;
        cout << "\nSeleccione una opción:" << endl;
        cout << "1. Modificar Cuenta" << endl;
        cout << "2. Eliminar Cuenta" << endl;
        cout << "0. Salir" << endl;
        opcionMenu = _getch();
        switch (opcionMenu) {
        case 48: sesion = salirCuenta(sesion);
            break;
        case 49: modificarCuenta(sesion);
            break;
        case 50: eliminarCuenta(sesion); sesion = salirCuenta(sesion);
            break;
        }
    } while (sesion != -1);
    lugar = NULL;
    return 0;
}

int main()
{
    int opcionMenu;
    do {
        system("color 70");
        SetConsoleCP(CP_UTF8); // entrada utf-8
        SetConsoleOutputCP(CP_UTF8); // salida utf-8
        system("cls");
        cout << "Práctica de Menú en C++ | Consola Windows | v2.0";
        cout << "\n--- MENU ---\n";
        cout << "1. Ingresar Usuario\n";
        cout << "2. Registrarse\n";
        cout << "3. Lista de Usuarios\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción \n";
        opcionMenu = _getch();
        switch (opcionMenu) {
        case 27:
            break;
        case 48:  salirApp();
            break;
        case 49:
            if (autorizacion() == true) {
                inicio(lugar);
            }
            break;
        case 50: menuRegistro();
            break;
        case 51: mostrarLista();
            break;
        default: cout << "\nLa opción no es valida\n" << endl; system("pause");
            break;
        }

    } while (opcionSalir != 115 && opcionMenu != 27); // Mientras no sea s o Esc

    return 0;
}