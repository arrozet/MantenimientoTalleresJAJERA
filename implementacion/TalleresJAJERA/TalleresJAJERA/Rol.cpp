#include "Rol.h"

// Inicialización del DBContext
DBContext Rol::db;

// Constructor para cargar un rol existente desde la base de datos
Rol::Rol(int id) {
    auto res = db.select("SELECT * FROM tRol WHERE ID = " + to_string(id));
    if (res.empty()) {
        throw runtime_error("Rol no encontrado");
    }
    this->id = stoi(res[0][0]);
    this->nombre = res[0][1];
}

// Constructor para crear un nuevo rol
Rol::Rol(const string& nombre) {
    db.execute("INSERT INTO tRol (NOMBRE) VALUES ('" + nombre + "')");
    auto res = db.select("SELECT LAST_INSERT_ID()");
    if (res.empty()) {
        throw runtime_error("No se pudo obtener el ID del nuevo rol");
    }
    this->id = stoi(res[0][0]);
    this->nombre = nombre;
}

// Métodos estáticos
vector<Rol> Rol::ListarTodos() {
    vector<Rol> roles;
    auto res = db.select("SELECT ID FROM tRol");
    for (const auto& row : res) {
        roles.emplace_back(stoi(row[0]));
    }
    return roles;
}

Rol Rol::BuscarPorNombre(const string& nombre) {
    auto res = db.select("SELECT ID FROM tRol WHERE NOMBRE = '" + nombre + "'");
    if (res.empty()) {
        throw runtime_error("Rol no encontrado");
    }
    return Rol(stoi(res[0][0]));
}

// Métodos de instancia
int Rol::getId() const {
    return id;
}

string Rol::getNombre() const {
    return nombre;
}

void Rol::setNombre(const string& nuevoNombre) {
    db.execute("UPDATE tRol SET NOMBRE = '" + nuevoNombre + "' WHERE ID = " + to_string(this->id));
    this->nombre = nuevoNombre;
}

void Rol::borrar() {
    db.execute("DELETE FROM tRol WHERE ID = " + to_string(this->id));
    this->id = -1;
}

string Rol::toString() const {
    return "Rol: " + nombre;
}

bool Rol::operator==(const Rol& other) const {
    return this->id == other.id;
}
