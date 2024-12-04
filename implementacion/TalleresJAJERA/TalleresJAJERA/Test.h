#pragma once

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
		Test(void)
		{
			
			InitializeComponent();
			LoadPiezas();

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


	protected:

	private: System::Windows::Forms::DataGridView^ testDataGridView;
	private:
		void LoadPiezas();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// testDataGridView
			// 
			this->testDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->testDataGridView->Location = System::Drawing::Point(111, 315);
			this->testDataGridView->Margin = System::Windows::Forms::Padding(4);
			this->testDataGridView->Name = L"testDataGridView";
			this->testDataGridView->RowHeadersWidth = 51;
			this->testDataGridView->Size = System::Drawing::Size(1241, 233);
			this->testDataGridView->TabIndex = 0;
			this->testDataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Test::testDataGridView_CellClick);
			// 
			// labelMaterias
			// 
			this->labelMaterias->AutoSize = true;
			this->labelMaterias->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMaterias->Location = System::Drawing::Point(212, 132);
			this->labelMaterias->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMaterias->Name = L"labelMaterias";
			this->labelMaterias->Size = System::Drawing::Size(123, 32);
			this->labelMaterias->TabIndex = 2;
			this->labelMaterias->Text = L"Materias";
			// 
			// lMaterias
			// 
			this->lMaterias->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaterias->FormattingEnabled = true;
			this->lMaterias->ItemHeight = 16;
			this->lMaterias->Location = System::Drawing::Point(459, 95);
			this->lMaterias->Margin = System::Windows::Forms::Padding(4);
			this->lMaterias->Name = L"lMaterias";
			this->lMaterias->Size = System::Drawing::Size(539, 116);
			this->lMaterias->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(117, 631);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(117, 684);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Fabricante";
			// 
			// tNombre
			// 
			this->tNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tNombre->Location = System::Drawing::Point(253, 626);
			this->tNombre->Margin = System::Windows::Forms::Padding(4);
			this->tNombre->Name = L"tNombre";
			this->tNombre->Size = System::Drawing::Size(1097, 30);
			this->tNombre->TabIndex = 6;
			// 
			// tFabricante
			// 
			this->tFabricante->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tFabricante->Location = System::Drawing::Point(253, 679);
			this->tFabricante->Margin = System::Windows::Forms::Padding(4);
			this->tFabricante->Name = L"tFabricante";
			this->tFabricante->Size = System::Drawing::Size(1097, 30);
			this->tFabricante->TabIndex = 7;
			// 
			// bInsertar
			// 
			this->bInsertar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bInsertar->Location = System::Drawing::Point(253, 754);
			this->bInsertar->Margin = System::Windows::Forms::Padding(4);
			this->bInsertar->Name = L"bInsertar";
			this->bInsertar->Size = System::Drawing::Size(152, 28);
			this->bInsertar->TabIndex = 8;
			this->bInsertar->Text = L"Insertar";
			this->bInsertar->UseVisualStyleBackColor = true;
			// 
			// bActualizar
			// 
			this->bActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bActualizar->Location = System::Drawing::Point(543, 754);
			this->bActualizar->Margin = System::Windows::Forms::Padding(4);
			this->bActualizar->Name = L"bActualizar";
			this->bActualizar->Size = System::Drawing::Size(152, 28);
			this->bActualizar->TabIndex = 9;
			this->bActualizar->Text = L"Actualizar";
			this->bActualizar->UseVisualStyleBackColor = true;
			// 
			// bEliminar
			// 
			this->bEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bEliminar->Location = System::Drawing::Point(833, 754);
			this->bEliminar->Margin = System::Windows::Forms::Padding(4);
			this->bEliminar->Name = L"bEliminar";
			this->bEliminar->Size = System::Drawing::Size(152, 28);
			this->bEliminar->TabIndex = 10;
			this->bEliminar->Text = L"Eliminar";
			this->bEliminar->UseVisualStyleBackColor = true;
			// 
			// bLimpiar
			// 
			this->bLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLimpiar->Location = System::Drawing::Point(1108, 754);
			this->bLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->bLimpiar->Name = L"bLimpiar";
			this->bLimpiar->Size = System::Drawing::Size(152, 28);
			this->bLimpiar->TabIndex = 11;
			this->bLimpiar->Text = L"Limpiar";
			this->bLimpiar->UseVisualStyleBackColor = true;
			this->bLimpiar->Click += gcnew System::EventHandler(this, &Test::bLimpiar_Click);
			// 
			// Test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1539, 831);
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
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Test";
			this->Text = L"Test";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void bLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Vaciar el contenido de la listBox 
		lMaterias->SelectedItem = nullptr;

		// Deseleccionar cualquier objeto del DataGridView 
		testDataGridView->ClearSelection();

		// Eliminar el texto de los textBox 
		tNombre->Text = "";
		tFabricante->Text = "";
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Ocurrió un error en Limpiar: " + ex->Message);
	}

}
private: System::Void testDataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	try {
		tNombre->Text = testDataGridView->SelectedRows[0]->Cells["Nombre"]->Value->ToString();
		tFabricante->Text = testDataGridView->SelectedRows[0]->Cells["Fabricante"]->Value->ToString();
		//AQUI HAY QUE PONER QUE SE SELECCIONE
		// DE LA LISTBOX EL NOMBRE DEL TIPOPRODUCTO SELECCIONADO (IDPRODUCTO)
		

	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Ocurrió un error al hacer click en el dataGridView: " + ex->Message);
	}

}
};
}
