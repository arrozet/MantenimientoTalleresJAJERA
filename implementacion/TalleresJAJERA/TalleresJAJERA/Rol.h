#pragma once
#include <string>
#include <vector>
#include "DBContext.h"
#include <stdexcept>

using namespace std;

class Rol {
private:
    int id;             // ID del rol
    string nombre;      // Nombre del rol

    // DBContext est�tico para la conexi�n
    static DBContext db;

public:
    // Constructores
    Rol(int id);
    Rol(const string& nombre);

    // M�todos est�ticos
    static vector<Rol> ListarTodos();
    static Rol BuscarPorNombre(const string& nombre);

    // M�todos de instancia
    int getId() const;
    string getNombre() const;
    void setNombre(const string& nuevoNombre);

    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const Rol& other) const;
};
