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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// testDataGridView
			// 
			this->testDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->testDataGridView->Location = System::Drawing::Point(83, 256);
			this->testDataGridView->Name = L"testDataGridView";
			this->testDataGridView->Size = System::Drawing::Size(931, 189);
			this->testDataGridView->TabIndex = 0;
			this->testDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Test::testDataGridView_CellContentClick);
			// 
			// labelMaterias
			// 
			this->labelMaterias->AutoSize = true;
			this->labelMaterias->Location = System::Drawing::Point(85, 91);
			this->labelMaterias->Name = L"labelMaterias";
			this->labelMaterias->Size = System::Drawing::Size(47, 13);
			this->labelMaterias->TabIndex = 2;
			this->labelMaterias->Text = L"Materias";
			// 
			// lMaterias
			// 
			this->lMaterias->FormattingEnabled = true;
			this->lMaterias->Location = System::Drawing::Point(344, 77);
			this->lMaterias->Name = L"lMaterias";
			this->lMaterias->Size = System::Drawing::Size(405, 95);
			this->lMaterias->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(88, 509);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(88, 552);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Fabricante";
			// 
			// tNombre
			// 
			this->tNombre->Location = System::Drawing::Point(190, 509);
			this->tNombre->Name = L"tNombre";
			this->tNombre->Size = System::Drawing::Size(824, 20);
			this->tNombre->TabIndex = 6;
			// 
			// tFabricante
			// 
			this->tFabricante->Location = System::Drawing::Point(190, 552);
			this->tFabricante->Name = L"tFabricante";
			this->tFabricante->Size = System::Drawing::Size(824, 20);
			this->tFabricante->TabIndex = 7;
			// 
			// Test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1154, 675);
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
	private: System::Void testDataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}


};
}
