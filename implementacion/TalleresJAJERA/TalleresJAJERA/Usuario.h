#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "DBContext.h"

class Usuario {
private:
    std::string nombre;
    std::string password;
    std::string rolName;

public:
    // Constructor para cargar un usuario existente
    Usuario(const std::string& nombre);

    // Constructor para insertar un nuevo usuario
    Usuario(const std::string& nombre, const std::string& password, const std::string& rolName);

    // Métodos de listado
    static std::vector<Usuario> ListarTodos();
    static std::vector<Usuario> ListarPorRol(const std::string& rolName);

    // Setters con actualización en la base de datos
    void setPassword(const std::string& password);
    void setRolName(const std::string& rolName);

    // Getters
    std::string getNombre() const;
    std::string getPassword() const;
    std::string getRolName() const;

    // Método para borrar un usuario
    void borrar();

    // Representación en cadena
    std::string toString() const;

    // Comparación
    bool operator==(const Usuario& other) const;

    // DBContext estático para compartir la conexión
    static DBContext db;
};

#endif // USUARIO_H
