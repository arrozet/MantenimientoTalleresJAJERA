# Maintenance System for JAJERA Workshops

This project is a workshop maintenance application developed for the Information Management course at UMA's ETSII. It uses C++ and MySQL to manage mechanical part inventories and user permissions.

## Features

- **User Management**: manage users with roles and permissions for accessing different parts of the system.
- **Part Management**: create, edit, delete, and list mechanical parts with their respective types.
- **Role-Based Access Control (RBAC)**: different levels of access and modification permissions for each user role.

## Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/arrozet/MantenimientoTalleresJAJERA.git
   cd MantenimientoTalleresJAJERA
   ```

2. **Database Setup**:

   - Use the SQL script `!aux/TrabajoGI2425.sql` to create and populate the database.
   - Ensure the MySQL connection details in `DBContext.cpp` are correctly configured:

     ```cpp
     string DBContext::Host = "your-database-host";
     string DBContext::User = "your-username";
     string DBContext::Password = "your-password";
     string DBContext::Database = "your-database-name";
     ```

3. **Build and Run**:

   - Open `TalleresJAJERA.sln` in Visual Studio (Version 17 or higher).
   - Build the solution in "Release" mode and set the platform to "x64."
   - Run the application or use the precompiled executable found in `implementacion/TalleresJAJERA/x64/Release/`.

## Usage

1. **Login**: authenticate users based on role.
2. **Manage Parts**: add, edit, or delete parts and assign types to them.
3. **Role Permissions**: define and manage role-based access permissions for users.

## Configuration

The application configuration is stored in `DBContext.cpp`. Ensure the connection strings are correctly set before running.

## Dependencies

- **MySQL Connector C++**: for database connection.
- **.NET Framework (4.8 or above)**: runtime environment for the application.
- **ISO C++14 Standard**: Used as the default C++ standard for compilation.

## License

This project is intended for educational purposes only. The author is not responsible for any misuse of the software.
