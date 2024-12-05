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

    // DBContext estático para la conexión
    static DBContext db;

public:
    // Constructores
    Rol(int id);
    Rol(const string& nombre);

    // Métodos estáticos
    static vector<Rol> ListarTodos();
    static Rol BuscarPorNombre(const string& nombre);

    // Métodos de instancia
    int getId() const;
    string getNombre() const;
    void setNombre(const string& nuevoNombre);

    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const Rol& other) const;
};
