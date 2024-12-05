#include "Usuario.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Inicialización del DBContext estático
DBContext Usuario::db;

// Constructor para cargar un usuario existente
Usuario::Usuario(const string& nombre) {
    auto res = db.select("SELECT * FROM tUsuario WHERE nombre = '" + nombre + "'");
    if (res.empty()) {
        throw runtime_error("Usuario no encontrado");
    }
    this->nombre = res[0][0];
    this->password = res[0][1];
    this->rolName = res[0][2];
}

// Constructor para insertar un nuevo usuario
Usuario::Usuario(const string& nombre, const string& password, const string& rolName) {
    db.execute("INSERT INTO tUsuario (nombre, password, rolName) VALUES ('" + nombre + "', '" + password + "', '" + rolName + "')");
    this->nombre = nombre;
    this->password = password;
    this->rolName = rolName;
}

// Listar todos los usuarios
vector<Usuario> Usuario::ListarTodos() {
    vector<Usuario> usuarios;
    auto res = db.select("SELECT nombre FROM tUsuario");
    for (const auto& row : res) {
        usuarios.emplace_back(row[0]);
    }
    return usuarios;
}

// Listar usuarios por rol
vector<Usuario> Usuario::ListarPorRol(const string& rolName) {
    vector<Usuario> usuarios;
    auto res = db.select("SELECT nombre FROM tUsuario WHERE rolName = '" + rolName + "'");
    for (const auto& row : res) {
        usuarios.emplace_back(row[0]);
    }
    return usuarios;
}

// Setters con actualización en la base de datos
void Usuario::setPassword(const string& password) {
    db.execute("UPDATE tUsuario SET password = '" + password + "' WHERE nombre = '" + this->nombre + "'");
    this->password = password;
}

void Usuario::setRolName(const string& rolName) {
    db.execute("UPDATE tUsuario SET rolName = '" + rolName + "' WHERE nombre = '" + this->nombre + "'");
    this->rolName = rolName;
}

// Getters
string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getPassword() const {
    return password;
}

string Usuario::getRolName() const {
    return rolName;
}

// Método para borrar un usuario
void Usuario::borrar() {
    db.execute("DELETE FROM tUsuario WHERE nombre = '" + this->nombre + "'");
    this->nombre = "";
    this->password = "";
    this->rolName = "";
}

// Representación en cadena
string Usuario::toString() const {
    return "Usuario: " + nombre + ", Rol: " + rolName;
}

// Comparación
bool Usuario::operator==(const Usuario& other) const {
    return this->nombre == other.nombre;
}
