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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// testDataGridView
			// 
			this->testDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->testDataGridView->Location = System::Drawing::Point(55, 66);
			this->testDataGridView->Name = L"testDataGridView";
			this->testDataGridView->Size = System::Drawing::Size(656, 275);
			this->testDataGridView->TabIndex = 0;
			this->testDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Test::testDataGridView_CellContentClick);
			// 
			// Test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 428);
			this->Controls->Add(this->testDataGridView);
			this->Name = L"Test";
			this->Text = L"Test";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void testDataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	};
}
