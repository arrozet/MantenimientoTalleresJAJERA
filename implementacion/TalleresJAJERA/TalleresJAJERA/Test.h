#pragma once

#include <string>

namespace TalleresJAJERA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Test
	/// </summary>
	public ref class Test : public System::Windows::Forms::Form
	{
	public:
		Test(std::string& rol)
		{
			
			InitializeComponent();
			LoadPiezas();
			gestionarPermisos(rol);

			//Se encarga de ocupar todo el recuadro
			testDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Test()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelMaterias;
	private: System::Windows::Forms::ListBox^ lMaterias;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tNombre;
	private: System::Windows::Forms::TextBox^ tFabricante;
	private: System::Windows::Forms::Button^ bInsertar;
	private: System::Windows::Forms::Button^ bActualizar;
	private: System::Windows::Forms::Button^ bEliminar;
	private: System::Windows::Forms::Button^ bLimpiar;
	private: System::Windows::Forms::Button^ bSalir;


	protected:

	private: System::Windows::Forms::DataGridView^ testDataGridView;
	private:
		void LoadPiezas();
		void refreshDataGridForSelectedType(const std::string& tipoSeleccionado);
		void gestionarPermisos(std::string& rol);
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Test::typeid));
			this->testDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->labelMaterias = (gcnew System::Windows::Forms::Label());
			this->lMaterias = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tNombre = (gcnew System::Windows::Forms::TextBox());
			this->tFabricante = (gcnew System::Windows::Forms::TextBox());
			this->bInsertar = (gcnew System::Windows::Forms::Button());
			this->bActualizar = (gcnew System::Windows::Forms::Button());
			this->bEliminar = (gcnew System::Windows::Forms::Button());
			this->bLimpiar = (gcnew System::Windows::Forms::Button());
			this->bSalir = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// testDataGridView
			// 
			this->testDataGridView->AllowUserToAddRows = false;
			this->testDataGridView->AllowUserToDeleteRows = false;
			this->testDataGridView->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->testDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->testDataGridView->Location = System::Drawing::Point(92, 197);
			this->testDataGridView->Name = L"testDataGridView";
			this->testDataGridView->RowHeadersWidth = 51;
			this->testDataGridView->Size = System::Drawing::Size(922, 278);
			this->testDataGridView->TabIndex = 0;
			this->testDataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Test::testDataGridView_CellClick);
			// 
			// labelMaterias
			// 
			this->labelMaterias->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelMaterias->AutoSize = true;
			this->labelMaterias->BackColor = System::Drawing::Color::Black;
			this->labelMaterias->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMaterias->ForeColor = System::Drawing::Color::White;
			this->labelMaterias->Location = System::Drawing::Point(159, 107);
			this->labelMaterias->Name = L"labelMaterias";
			this->labelMaterias->Size = System::Drawing::Size(95, 26);
			this->labelMaterias->TabIndex = 2;
			this->labelMaterias->Text = L"Materias";
			// 
			// lMaterias
			// 
			this->lMaterias->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lMaterias->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaterias->FormattingEnabled = true;
			this->lMaterias->Location = System::Drawing::Point(344, 77);
			this->lMaterias->Name = L"lMaterias";
			this->lMaterias->Size = System::Drawing::Size(405, 95);
			this->lMaterias->TabIndex = 3;
			this->lMaterias->SelectedIndexChanged += gcnew System::EventHandler(this, &Test::lMaterias_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(88, 512);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(88, 556);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Fabricante";
			// 
			// tNombre
			// 
			this->tNombre->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tNombre->Location = System::Drawing::Point(190, 509);
			this->tNombre->Name = L"tNombre";
			this->tNombre->Size = System::Drawing::Size(824, 26);
			this->tNombre->TabIndex = 6;
			// 
			// tFabricante
			// 
			this->tFabricante->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tFabricante->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tFabricante->Location = System::Drawing::Point(190, 552);
			this->tFabricante->Name = L"tFabricante";
			this->tFabricante->Size = System::Drawing::Size(824, 26);
			this->tFabricante->TabIndex = 7;
			// 
			// bInsertar
			// 
			this->bInsertar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bInsertar->BackColor = System::Drawing::Color::Black;
			this->bInsertar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bInsertar->ForeColor = System::Drawing::Color::White;
			this->bInsertar->Location = System::Drawing::Point(190, 613);
			this->bInsertar->Name = L"bInsertar";
			this->bInsertar->Size = System::Drawing::Size(114, 40);
			this->bInsertar->TabIndex = 8;
			this->bInsertar->Text = L"Insertar";
			this->bInsertar->UseVisualStyleBackColor = false;
			this->bInsertar->Click += gcnew System::EventHandler(this, &Test::bInsertar_Click);
			// 
			// bActualizar
			// 
			this->bActualizar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bActualizar->BackColor = System::Drawing::Color::Black;
			this->bActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bActualizar->ForeColor = System::Drawing::Color::White;
			this->bActualizar->Location = System::Drawing::Point(407, 613);
			this->bActualizar->Name = L"bActualizar";
			this->bActualizar->Size = System::Drawing::Size(114, 40);
			this->bActualizar->TabIndex = 9;
			this->bActualizar->Text = L"Actualizar";
			this->bActualizar->UseVisualStyleBackColor = false;
			this->bActualizar->Click += gcnew System::EventHandler(this, &Test::bActualizar_Click);
			// 
			// bEliminar
			// 
			this->bEliminar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bEliminar->BackColor = System::Drawing::Color::Black;
			this->bEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bEliminar->ForeColor = System::Drawing::Color::White;
			this->bEliminar->Location = System::Drawing::Point(625, 613);
			this->bEliminar->Name = L"bEliminar";
			this->bEliminar->Size = System::Drawing::Size(114, 40);
			this->bEliminar->TabIndex = 10;
			this->bEliminar->Text = L"Eliminar";
			this->bEliminar->UseVisualStyleBackColor = false;
			this->bEliminar->Click += gcnew System::EventHandler(this, &Test::bEliminar_Click);
			// 
			// bLimpiar
			// 
			this->bLimpiar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bLimpiar->BackColor = System::Drawing::Color::Black;
			this->bLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLimpiar->ForeColor = System::Drawing::Color::White;
			this->bLimpiar->Location = System::Drawing::Point(831, 613);
			this->bLimpiar->Name = L"bLimpiar";
			this->bLimpiar->Size = System::Drawing::Size(114, 40);
			this->bLimpiar->TabIndex = 11;
			this->bLimpiar->Text = L"Limpiar";
			this->bLimpiar->UseVisualStyleBackColor = false;
			this->bLimpiar->Click += gcnew System::EventHandler(this, &Test::bLimpiar_Click);
			// 
			// bSalir
			// 
			this->bSalir->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bSalir->BackColor = System::Drawing::Color::Maroon;
			this->bSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bSalir->ForeColor = System::Drawing::Color::White;
			this->bSalir->Location = System::Drawing::Point(1007, 593);
			this->bSalir->Name = L"bSalir";
			this->bSalir->Size = System::Drawing::Size(135, 70);
			this->bSalir->TabIndex = 12;
			this->bSalir->Text = L"SALIR";
			this->bSalir->UseVisualStyleBackColor = false;
			this->bSalir->Click += gcnew System::EventHandler(this, &Test::bSalir_Click);
			// 
			// Test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1154, 675);
			this->Controls->Add(this->bSalir);
			this->Controls->Add(this->bLimpiar);
			this->Controls->Add(this->bEliminar);
			this->Controls->Add(this->bActualizar);
			this->Controls->Add(this->bInsertar);
			this->Controls->Add(this->tFabricante);
			this->Controls->Add(this->tNombre);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lMaterias);
			this->Controls->Add(this->labelMaterias);
			this->Controls->Add(this->testDataGridView);
			this->Name = L"Test";
			this->Text = L"Test";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void bLimpiar_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void testDataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void lMaterias_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void bInsertar_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bEliminar_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bActualizar_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void bSalir_Click(System::Object^ sender, System::EventArgs^ e);
};
}
