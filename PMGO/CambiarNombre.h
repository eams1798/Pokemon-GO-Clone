#pragma once
#include "Pokemon.h"

namespace PMGO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de CambiarNombre
	/// </summary>
	public ref class CambiarNombre : public System::Windows::Forms::Form
	{
	private:
		CPokemon *myPoke;
	public:
		CambiarNombre(CPokemon *nombrar)
		{
			InitializeComponent();
			myPoke = nombrar;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~CambiarNombre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(162, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Nombrar Pokémon";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CambiarNombre::button1_Click);
			// 
			// CambiarNombre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(287, 65);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"CambiarNombre";
			this->Text = L"Ponle un mote a tu Pokémon";
			this->Load += gcnew System::EventHandler(this, &CambiarNombre::CambiarNombre_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CambiarNombre_Load(System::Object^  sender, System::EventArgs^  e)
	{
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 char *moteP = new char[30]; sprintf(moteP, "%s", textBox1->Text);
				 myPoke->setmote(moteP);
				 textBox1->Clear();
	}
	};
}
