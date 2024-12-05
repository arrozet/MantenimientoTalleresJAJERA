#pragma once
#include "Usuario.h"
#include "Rol.h"
#include "Permiso.h"
#include <string>
#include "DBContext.h"
#include <vector>
using namespace std;
namespace TalleresJAJERA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{

	public:
		Login(void)
		{
			InitializeComponent();
			this->bOk->Click += gcnew System::EventHandler(this, &Login::bOk_Click);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lBienvenido;
	private: System::Windows::Forms::Label^ labUsuario;
	private: System::Windows::Forms::Label^ labPassword;
	private: System::Windows::Forms::TextBox^ tUsuario;
	private: System::Windows::Forms::TextBox^ tPassword;
	private: System::Windows::Forms::Button^ bOk;
	private: System::Windows::Forms::Button^ bCancel;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lBienvenido = (gcnew System::Windows::Forms::Label());
			this->labUsuario = (gcnew System::Windows::Forms::Label());
			this->labPassword = (gcnew System::Windows::Forms::Label());
			this->tUsuario = (gcnew System::Windows::Forms::TextBox());
			this->tPassword = (gcnew System::Windows::Forms::TextBox());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lBienvenido
			// 
			this->lBienvenido->AutoSize = true;
			this->lBienvenido->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBienvenido->Location = System::Drawing::Point(95, 30);
			this->lBienvenido->Name = L"lBienvenido";
			this->lBienvenido->Size = System::Drawing::Size(169, 33);
			this->lBienvenido->TabIndex = 0;
			this->lBienvenido->Text = L"Bienvenido";
			// 
			// labUsuario
			// 
			this->labUsuario->AutoSize = true;
			this->labUsuario->Location = System::Drawing::Point(41, 93);
			this->labUsuario->Name = L"labUsuario";
			this->labUsuario->Size = System::Drawing::Size(43, 13);
			this->labUsuario->TabIndex = 1;
			this->labUsuario->Text = L"Usuario";
			// 
			// labPassword
			// 
			this->labPassword->AutoSize = true;
			this->labPassword->Location = System::Drawing::Point(41, 195);
			this->labPassword->Name = L"labPassword";
			this->labPassword->Size = System::Drawing::Size(53, 13);
			this->labPassword->TabIndex = 2;
			this->labPassword->Text = L"Password";
			// 
			// tUsuario
			// 
			this->tUsuario->Location = System::Drawing::Point(125, 93);
			this->tUsuario->Name = L"tUsuario";
			this->tUsuario->Size = System::Drawing::Size(194, 20);
			this->tUsuario->TabIndex = 3;
			// 
			// tPassword
			// 
			this->tPassword->Location = System::Drawing::Point(125, 195);
			this->tPassword->Name = L"tPassword";
			this->tPassword->Size = System::Drawing::Size(194, 20);
			this->tPassword->TabIndex = 4;
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(101, 261);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 23);
			this->bOk->TabIndex = 5;
			this->bOk->Text = L"OK";
			this->bOk->UseVisualStyleBackColor = true;
			this->bOk->Click += gcnew System::EventHandler(this, &Login::bOk_Click);
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(221, 260);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"Cancel";
			this->bCancel->UseVisualStyleBackColor = true;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 309);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->tPassword);
			this->Controls->Add(this->tUsuario);
			this->Controls->Add(this->labPassword);
			this->Controls->Add(this->labUsuario);
			this->Controls->Add(this->lBienvenido);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: bool autenticar(const std::string& nombre, const std::string& password);
private: Usuario obtenerUsuario(const std::string& nombre);
public: System::Void bOk_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

