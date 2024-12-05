#ifndef ROL_H
#define ROL_H

#include <string>
#include <vector>
#include "DBContext.h"  // Reemplaza con tu clase de acceso a la base de datos

class Rol {
private:
    std::string rolName;
    std::string rolDes;
    bool admin;

public:
    // Constructor para cargar un rol existente
    Rol(const std::string& rolName);

    // Constructor para insertar un nuevo rol
    Rol(const std::string& rolName, const std::string& rolDes, bool admin);

    // Métodos de listado
    static std::vector<Rol> ListarTodos();

    // Setters con actualización en la base de datos
    void setRolDes(const std::string& rolDes);
    void setAdmin(bool admin);

    // Getters
    std::string getRolName() const;
    std::string getRolDes() const;
    bool isAdmin() const;

    // Método para borrar un rol
    void borrar();

    // Representación en cadena
    std::string toString() const;

    // DBContext estático para compartir la conexión
    static DBContext db;
};

#endif
