#include "Permiso.h"

// Inicialización del DBContext
DBContext Permiso::db;

// Constructor para cargar un permiso existente desde la base de datos
Permiso::Permiso(int id) {
    auto res = db.select("SELECT * FROM tPermiso WHERE ID = " + to_string(id));
    if (res.empty()) {
        throw runtime_error("Permiso no encontrado");
    }
    this->id = stoi(res[0][0]);
    this->nombre = res[0][1];
}

// Constructor para crear un nuevo permiso
Permiso::Permiso(const string& nombre) {
    db.execute("INSERT INTO tPermiso (NOMBRE) VALUES ('" + nombre + "')");
    auto res = db.select("SELECT LAST_INSERT_ID()");
    if (res.empty()) {
        throw runtime_error("No se pudo obtener el ID del nuevo permiso");
    }
    this->id = stoi(res[0][0]);
    this->nombre = nombre;
}

// Métodos estáticos
vector<Permiso> Permiso::ListarTodos() {
    vector<Permiso> permisos;
    auto res = db.select("SELECT ID FROM tPermiso");
    for (const auto& row : res) {
        permisos.emplace_back(stoi(row[0]));
    }
    return permisos;
}

Permiso Permiso::BuscarPorNombre(const string& nombre) {
    auto res = db.select("SELECT ID FROM tPermiso WHERE NOMBRE = '" + nombre + "'");
    if (res.empty()) {
        throw runtime_error("Permiso no encontrado");
    }
    return Permiso(stoi(res[0][0]));
}

// Métodos de instancia
int Permiso::getId() const {
    return id;
}

string Permiso::getNombre() const {
    return nombre;
}

void Permiso::setNombre(const string& nuevoNombre) {
    db.execute("UPDATE tPermiso SET NOMBRE = '" + nuevoNombre + "' WHERE ID = " + to_string(this->id));
    this->nombre = nuevoNombre;
}

void Permiso::borrar() {
    db.execute("DELETE FROM tPermiso WHERE ID = " + to_string(this->id));
    this->id = -1;
}

string Permiso::toString() const {
    return "Permiso: " + nombre;
}

bool Permiso::operator==(const Permiso& other) const {
    return this->id == other.id;
}
