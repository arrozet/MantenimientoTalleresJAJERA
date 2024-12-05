#pragma once
#include <string>
#include <vector>
#include "DBContext.h"
#include <stdexcept>

using namespace std;

class Permiso {
private:
    int id;             // ID del permiso
    string nombre;      // Nombre del permiso

    // DBContext est�tico para la conexi�n
    static DBContext db;

public:
    // Constructores
    Permiso(int id);
    Permiso(const string& nombre);

    // M�todos est�ticos
    static vector<Permiso> ListarTodos();
    static Permiso BuscarPorNombre(const string& nombre);

    // M�todos de instancia
    int getId() const;
    string getNombre() const;
    void setNombre(const string& nuevoNombre);

    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const Permiso& other) const;
};
