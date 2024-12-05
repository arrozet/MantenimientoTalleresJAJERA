#include "Permiso.h"
#include <iostream>
#include <stdexcept>
#include "DBContext.h"  // Reemplaza con tu clase de acceso a la base de datos

// Habilitamos el uso del namespace std
using namespace std;

// Define el DBContext estático
DBContext Permiso::db;

// Constructor para cargar un permiso existente
Permiso::Permiso(const std::string& rolName, const std::string& pantalla) {
    auto res = db.select(
        "SELECT * FROM tPermiso WHERE rolName = '" + rolName + "' AND pantalla = '" + pantalla + "'"
    );
    if (res.empty()) {
        throw std::runtime_error("Permiso no encontrado");
    }
    this->rolName = res[0][0];
    this->pantalla = res[0][1];
    this->acceso = res[0][2] == "1";
    this->modificacion = res[0][3] == "1";
}

// Constructor para insertar un nuevo permiso
Permiso::Permiso(const std::string& rolName, const std::string& pantalla, bool acceso, bool modificacion) {
    db.execute(
        "INSERT INTO tPermiso (rolName, pantalla, acceso, modificacion) VALUES ('" + rolName + "', '" + pantalla + "', " +
        std::to_string(acceso) + ", " + std::to_string(modificacion) + ")"
    );
    this->rolName = rolName;
    this->pantalla = pantalla;
    this->acceso = acceso;
    this->modificacion = modificacion;
}

// Listar todos los permisos
std::vector<Permiso> Permiso::ListarTodos() {
    std::vector<Permiso> permisos;
    auto res = db.select("SELECT rolName, pantalla FROM tPermiso");
    for (const auto& row : res) {
        permisos.emplace_back(row[0], row[1]);
    }
    return permisos;
}

// Listar permisos por rol
std::vector<Permiso> Permiso::ListarPorRol(const std::string& rolName) {
    std::vector<Permiso> permisos;
    auto res = db.select(
        "SELECT pantalla FROM tPermiso WHERE rolName = '" + rolName + "'"
    );
    for (const auto& row : res) {
        permisos.emplace_back(rolName, row[0]);
    }
    return permisos;
}

// Listar permisos por pantalla
std::vector<Permiso> Permiso::ListarPorPantalla(const std::string& pantalla) {
    std::vector<Permiso> permisos;
    auto res = db.select(
        "SELECT rolName FROM tPermiso WHERE pantalla = '" + pantalla + "'"
    );
    for (const auto& row : res) {
        permisos.emplace_back(row[0], pantalla);
    }
    return permisos;
}

// Setters con actualización en la base de datos
void Permiso::setAcceso(bool acceso) {
    db.execute(
        "UPDATE tPermiso SET acceso = " + std::to_string(acceso) +
        " WHERE rolName = '" + this->rolName + "' AND pantalla = '" + this->pantalla + "'"
    );
    this->acceso = acceso;
}

void Permiso::setModificacion(bool modificacion) {
    db.execute(
        "UPDATE tPermiso SET modificacion = " + std::to_string(modificacion) +
        " WHERE rolName = '" + this->rolName + "' AND pantalla = '" + this->pantalla + "'"
    );
    this->modificacion = modificacion;
}

// Getters
std::string Permiso::getRolName() const {
    return rolName;
}

std::string Permiso::getPantalla() const {
    return pantalla;
}

bool Permiso::getAcceso() const {
    return acceso;
}

bool Permiso::getModificacion() const {
    return modificacion;
}

// Método para borrar un permiso
void Permiso::borrar() {
    db.execute(
        "DELETE FROM tPermiso WHERE rolName = '" + this->rolName + "' AND pantalla = '" + this->pantalla + "'"
    );
    this->rolName.clear();
    this->pantalla.clear();
}

// Representación en cadena
std::string Permiso::toString() const {
    return "Rol: " + rolName + ", Pantalla: " + pantalla + ", Acceso: " + (acceso ? "Sí" : "No") + ", Modificación: " + (modificacion ? "Sí" : "No");
}
