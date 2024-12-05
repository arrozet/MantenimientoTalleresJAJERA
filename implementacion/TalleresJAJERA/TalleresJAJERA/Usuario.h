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

    // M�todos de listado
    static std::vector<Usuario> ListarTodos();
    static std::vector<Usuario> ListarPorRol(const std::string& rolName);

    // Setters con actualizaci�n en la base de datos
    void setPassword(const std::string& password);
    void setRolName(const std::string& rolName);

    // Getters
    std::string getNombre() const;
    std::string getPassword() const;
    std::string getRolName() const;

    // M�todo para borrar un usuario
    void borrar();

    // Representaci�n en cadena
    std::string toString() const;

    // Comparaci�n
    bool operator==(const Usuario& other) const;

    // DBContext est�tico para compartir la conexi�n
    static DBContext db;
};

#endif // USUARIO_H
