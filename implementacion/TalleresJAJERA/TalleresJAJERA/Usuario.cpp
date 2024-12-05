#include "Usuario.h"

// Inicialización del DBContext
DBContext Usuario::db;

// Constructor para cargar un usuario existente desde la base de datos
Usuario::Usuario(int id) {
    auto res = db.select("SELECT * FROM tUsuario WHERE ID = " + to_string(id));
    if (res.empty()) {
        throw runtime_error("Usuario no encontrado");
    }
    this->id = stoi(res[0][0]);
    this->nombre = res[0][1];
    this->password = res[0][2];
    this->rol = res[0][3];
}

// Constructor para crear un nuevo usuario
Usuario::Usuario(const string& nombre, const string& password, const string& rol) {
    db.execute("INSERT INTO tUsuario (NOMBRE, PASSWORD, ROL) VALUES ('" + nombre + "', '" + password + "', '" + rol + "')");
    auto res = db.select("SELECT LAST_INSERT_ID()");
    if (res.empty()) {
        throw runtime_error("No se pudo obtener el ID del nuevo usuario");
    }
    this->id = stoi(res[0][0]);
    this->nombre = nombre;
    this->password = password;
    this->rol = rol;
}

// Método estático para listar todos los usuarios
vector<Usuario> Usuario::ListarTodos() {
    vector<Usuario> usuarios;
    auto res = db.select("SELECT ID FROM tUsuario");
    for (const auto& row : res) {
        usuarios.emplace_back(stoi(row[0]));
    }
    return usuarios;
}

// Método estático para buscar un usuario por nombre
Usuario Usuario::BuscarPorNombre(const string& nombre) {
    auto res = db.select("SELECT ID FROM tUsuario WHERE NOMBRE = '" + nombre + "'");
    if (res.empty()) {
        throw runtime_error("Usuario no encontrado");
    }
    return Usuario(stoi(res[0][0]));
}

// Setters con actualización en la base de datos
void Usuario::setNombre(const string& nuevoNombre) {
    db.execute("UPDATE tUsuario SET NOMBRE = '" + nuevoNombre + "' WHERE ID = " + to_string(this->id));
    this->nombre = nuevoNombre;
}

void Usuario::setPassword(const string& nuevoPassword) {
    db.execute("UPDATE tUsuario SET PASSWORD = '" + nuevoPassword + "' WHERE ID = " + to_string(this->id));
    this->password = nuevoPassword;
}

void Usuario::setRol(const string& nuevoRol) {
    db.execute("UPDATE tUsuario SET ROL = '" + nuevoRol + "' WHERE ID = " + to_string(this->id));
    this->rol = nuevoRol;
}

// Getters
int Usuario::getId() const {
    return id;
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getPassword() const {
    return password;
}

string Usuario::getRol() const {
    return rol;
}

// Eliminar usuario
void Usuario::borrar() {
    db.execute("DELETE FROM tUsuario WHERE ID = " + to_string(this->id));
    this->id = -1; // Marcamos el usuario como eliminado
}

// Representación en cadena
string Usuario::toString() const {
    return "Usuario: " + nombre + " (Rol: " + rol + ")";
}

// Sobrecarga de operadores
bool Usuario::operator==(const Usuario& other) const {
    return this->id == other.id;
}
