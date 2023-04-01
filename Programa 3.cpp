#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float notas[4];
    float promedio;
    string resultado;
};

void ingresarDatos(Estudiante *estudiantes, int n);
void calcularPromedio(Estudiante *estudiantes, int n);
void determinarResultado(Estudiante *estudiantes, int n);
void guardarDatos(Estudiante *estudiantes, int n);
void mostrarDatos();

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante *estudiantes = new Estudiante[n];

    ingresarDatos(estudiantes, n);
    calcularPromedio(estudiantes, n);
    determinarResultado(estudiantes, n);
    guardarDatos(estudiantes, n);
    mostrarDatos();

    delete[] estudiantes;
    return 0;
}

void ingresarDatos(Estudiante *estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i + 1 << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cin.ignore(); // para evitar problemas con getline
        cout << "Nombres: ";
        getline(cin, estudiantes[i].nombres);
        cout << "Apellidos: ";
        getline(cin, estudiantes[i].apellidos);
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
    }
}

void calcularPromedio(Estudiante *estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        float suma = 0;
        for (int j = 0; j < 4; j++) {
            suma += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = suma / 4;
    }
}

void determinarResultado(Estudiante *estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].promedio >= 60) {
            estudiantes[i].resultado = "APROBADO";
        } else {
            estudiantes[i].resultado = "REPROBADO";
        }
    }
}

void guardarDatos(Estudiante *estudiantes, int n) {
    ofstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) {
            archivo.write(reinterpret_cast<const char*>(&estudiantes[i]), sizeof(Estudiante));
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura" << endl;
    }
}

void mostrarDatos() {
    ifstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        Estudiante estudiante;
        while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
            cout << "ID: " << estudiante.id << endl;
            cout << "Nombres: " << estudiante.nombres << endl;
            cout << "Apellidos: " << estudiante.apellidos << endl;
            for (int i = 0; i < 4; i++) {
                cout << "Nota " << i + 1 << ": " << estudiante.notas[i] << endl;
            }
            cout << "Promedio: << promedio << endl;
        if (promedio >= 60) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
    }
   }
}  


