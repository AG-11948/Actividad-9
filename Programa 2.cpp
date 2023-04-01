#include <iostream>
#include <string>
using namespace std;

const int MAX_ESTUDIANTES = 100;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
};

void ingresarEstudiantes(Estudiante *estudiantes, int numEstudiantes);
double calcularPromedio(double *notas, int numNotas);
void mostrarResultados(Estudiante *estudiantes, int numEstudiantes);

int main() {
    int numEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> numEstudiantes;

    Estudiante *estudiantes = new Estudiante[numEstudiantes];
    ingresarEstudiantes(estudiantes, numEstudiantes);
    mostrarResultados(estudiantes, numEstudiantes);

    delete[] estudiantes;
    return 0;
}

void ingresarEstudiantes(Estudiante *estudiantes, int numEstudiantes) {
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nIngrese datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        cout << "Notas (separadas por espacios): ";
        for (int j = 0; j < 4; j++) {
            cin >> *(estudiantes[i].notas + j);
        }
    }
}

double calcularPromedio(double *notas, int numNotas) {
    double suma = 0;
    for (int i = 0; i < numNotas; i++) {
        suma += *(notas + i);
    }
    return suma / numNotas;
}

void mostrarResultados(Estudiante *estudiantes, int numEstudiantes) {
    for (int i = 0; i < numEstudiantes; i++) {
        double promedio = calcularPromedio(estudiantes[i].notas, 4);
        cout << "\nResultados para el estudiante " << i + 1 << ":" << endl;
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Nombres: " << estudiantes[i].nombres << endl;
        cout << "Apellidos: " << estudiantes[i].apellidos << endl;
        cout << "Promedio: " << promedio << endl;
        if (promedio >= 60) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
    }
}

