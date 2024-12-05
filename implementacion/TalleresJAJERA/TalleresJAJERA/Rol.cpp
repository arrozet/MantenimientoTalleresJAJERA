#include "Rol.h"
#include <iostream>
#include <stdexcept>
#include "DBContext.h"  // Reemplaza con tu clase de acceso a la base de datos

// Habilitamos el uso del namespace std
using namespace std;

// Define el DBContext estático
DBContext Rol::db;

// Constructor para cargar un rol existente
Rol::Rol(const string& rolName) {
    auto res = db.select("SELECT * FROM tRol WHERE rolName = '" + rolName + "'");
    if (res.empty()) {
        throw std::runtime_error("Rol no encontrado");
    }
    this->rolName = res[0][0];
    this->rolDes = res[0][1];
    this->admin = res[0][2] == "1";
}

// Constructor para insertar un nuevo rol
Rol::Rol(const string& rolName, const string& rolDes, bool admin) {
    db.execute("INSERT INTO tRol (rolName, rolDes, admin) VALUES ('" + rolName + "', '" + rolDes + "', " + std::to_string(admin) + ")");
    this->rolName = rolName;
    this->rolDes = rolDes;
    this->admin = admin;
}

// Listar todos los roles
std::vector<Rol> Rol::ListarTodos() {
    std::vector<Rol> roles;
    auto res = db.select("SELECT rolName FROM tRol");
    for (const auto& row : res) {
        roles.emplace_back(row[0]);
    }
    return roles;
}

// Setters con actualización en la base de datos
void Rol::setRolDes(const string& rolDes) {
    db.execute("UPDATE tRol SET rolDes = '" + rolDes + "' WHERE rolName = '" + this->rolName + "'");
    this->rolDes = rolDes;
}

void Rol::setAdmin(bool admin) {
    db.execute("UPDATE tRol SET admin = " + to_string(admin) + " WHERE rolName = '" + this->rolName + "'");
    this->admin = admin;
}

// Getters
std::string Rol::getRolName() const {
    return rolName;
}

std::string Rol::getRolDes() const {
    return rolDes;
}

bool Rol::isAdmin() const {
    return admin;
}

// Método para borrar un rol
void Rol::borrar() {
    db.execute("DELETE FROM tRol WHERE rolName = '" + this->rolName + "'");
    this->rolName.clear();
}

// Representación en cadena
std::string Rol::toString() const {
    return "Rol: " + rolName + ", Descripción: " + rolDes + ", Admin: " + (admin ? "Sí" : "No");
}
