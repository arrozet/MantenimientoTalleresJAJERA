#pragma once
#include <string>
#include "DBContext.h"
#include <stdexcept>
#include <vector>

using namespace std;

class Usuario {
private:
    int id;                  // ID del usuario
    string nombre;           // Nombre del usuario
    string password;         // Contraseña del usuario
    string rol;              // Rol del usuario

    // DBContext para esta clase
    static DBContext db;

public:
    // Constructores
    Usuario(int id);
    Usuario(const string& nombre, const string& password, const string& rol);

    // Métodos estáticos
    static vector<Usuario> ListarTodos();
    static Usuario BuscarPorNombre(const string& nombre);

    // Métodos de instancia
    void setNombre(const string& nuevoNombre);
    void setPassword(const string& nuevoPassword);
    void setRol(const string& nuevoRol);

    int getId() const;
    string getNombre() const;
    string getPassword() const;
    string getRol() const;

    void borrar();
    string toString() const;

    // Sobrecarga de operadores
    bool operator==(const Usuario& other) const;
};