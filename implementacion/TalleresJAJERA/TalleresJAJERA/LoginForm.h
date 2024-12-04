#pragma once

namespace TalleresJAJERA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lUsuario;
	private: System::Windows::Forms::Label^ lPassword;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lUsuario = (gcnew System::Windows::Forms::Label());
			this->lPassword = (gcnew System::Windows::Forms::Label());
			this->tUsuario = (gcnew System::Windows::Forms::TextBox());
			this->tPassword = (gcnew System::Windows::Forms::TextBox());
			this->bOk = (gcnew System::Windows::Forms::Button());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(5, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(561, 66);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Bienvenido";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lUsuario
			// 
			this->lUsuario->AutoSize = true;
			this->lUsuario->Location = System::Drawing::Point(62, 162);
			this->lUsuario->Name = L"lUsuario";
			this->lUsuario->Size = System::Drawing::Size(79, 25);
			this->lUsuario->TabIndex = 1;
			this->lUsuario->Text = L"Usuario";
			// 
			// lPassword
			// 
			this->lPassword->AutoSize = true;
			this->lPassword->Location = System::Drawing::Point(62, 263);
			this->lPassword->Name = L"lPassword";
			this->lPassword->Size = System::Drawing::Size(98, 25);
			this->lPassword->TabIndex = 2;
			this->lPassword->Text = L"Password";
			// 
			// tUsuario
			// 
			this->tUsuario->Location = System::Drawing::Point(207, 162);
			this->tUsuario->Name = L"tUsuario";
			this->tUsuario->Size = System::Drawing::Size(294, 30);
			this->tUsuario->TabIndex = 3;
			// 
			// tPassword
			// 
			this->tPassword->Location = System::Drawing::Point(207, 263);
			this->tPassword->Name = L"tPassword";
			this->tPassword->Size = System::Drawing::Size(294, 30);
			this->tPassword->TabIndex = 4;
			// 
			// bOk
			// 
			this->bOk->Location = System::Drawing::Point(207, 384);
			this->bOk->Name = L"bOk";
			this->bOk->Size = System::Drawing::Size(75, 37);
			this->bOk->TabIndex = 5;
			this->bOk->Text = L"OK";
			this->bOk->UseVisualStyleBackColor = true;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(383, 384);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(118, 37);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"CANCEL";
			this->bCancel->UseVisualStyleBackColor = true;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 502);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bOk);
			this->Controls->Add(this->tPassword);
			this->Controls->Add(this->tUsuario);
			this->Controls->Add(this->lPassword);
			this->Controls->Add(this->lUsuario);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
