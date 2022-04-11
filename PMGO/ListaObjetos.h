#pragma once
#include "Personaje.h"

namespace PMGO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ListaObjetos
	/// </summary>
	public ref class ListaObjetos : public System::Windows::Forms::Form
	{
	private:
		CPersonaje *user; int stdobj;
	private: System::Windows::Forms::ListBox^  lbxObjs;
	private: System::Windows::Forms::ComboBox^  cbxPoke;
	public:
		ListaObjetos(CPersonaje *nuevoP, int estado)
		{
			InitializeComponent();
			user = nuevoP; stdobj = estado;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~ListaObjetos()
		{
			if (components)
			{
				delete components;
			}
		}









	private: System::Windows::Forms::Button^  btnUsarPKBall;



	protected:

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
			this->btnUsarPKBall = (gcnew System::Windows::Forms::Button());
			this->cbxPoke = (gcnew System::Windows::Forms::ComboBox());
			this->lbxObjs = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnUsarPKBall
			// 
			this->btnUsarPKBall->Enabled = false;
			this->btnUsarPKBall->Location = System::Drawing::Point(148, 12);
			this->btnUsarPKBall->Name = L"btnUsarPKBall";
			this->btnUsarPKBall->Size = System::Drawing::Size(96, 23);
			this->btnUsarPKBall->TabIndex = 3;
			this->btnUsarPKBall->Text = L"Usar";
			this->btnUsarPKBall->UseVisualStyleBackColor = true;
			this->btnUsarPKBall->Click += gcnew System::EventHandler(this, &ListaObjetos::btnUsarPKBall_Click);
			// 
			// cbxPoke
			// 
			this->cbxPoke->FormattingEnabled = true;
			this->cbxPoke->Location = System::Drawing::Point(250, 12);
			this->cbxPoke->Name = L"cbxPoke";
			this->cbxPoke->Size = System::Drawing::Size(96, 21);
			this->cbxPoke->TabIndex = 4;
			// 
			// lbxObjs
			// 
			this->lbxObjs->FormattingEnabled = true;
			this->lbxObjs->Location = System::Drawing::Point(12, 12);
			this->lbxObjs->Name = L"lbxObjs";
			this->lbxObjs->Size = System::Drawing::Size(109, 212);
			this->lbxObjs->TabIndex = 1;
			this->lbxObjs->SelectedIndexChanged += gcnew System::EventHandler(this, &ListaObjetos::lbxObjs_SelectedIndexChanged);
			// 
			// ListaObjetos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 384);
			this->Controls->Add(this->cbxPoke);
			this->Controls->Add(this->btnUsarPKBall);
			this->Controls->Add(this->lbxObjs);
			this->Name = L"ListaObjetos";
			this->Text = L"ListaObjetos";
			this->Load += gcnew System::EventHandler(this, &ListaObjetos::ListaObjetos_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ListaObjetos_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 actualizalistaobjetos();
	}

			 void actualizalistaobjetos()
			 {
				 cbxPoke->Items->Clear();
				 for (int i = 0; i < user->getlistaMisPokes().size(); i++)
				 {
					 String ^nPoke = gcnew String(user->getMyPoke(i)->getmote());
					 int vida = user->getMyPoke(i)->getvidaActual();
					 int vidaM = user->getMyPoke(i)->getSalud_PC();
					 cbxPoke->Items->Add(nPoke + " " + vida + "/" + vidaM);
				 }
				 for (int i = 0; i < user->getlistaMisObjs().size(); i++)
				 {
					 String ^nomObj = gcnew String(user->getlistaMisObjs()[i]->getnombre());
					 lbxObjs->Items->Add(nomObj);
				 }
			 }
private: System::Void btnCurar_Click(System::Object^  sender, System::EventArgs^  e)
{
}


private: System::Void btnUsarPKBall_Click(System::Object^  sender, System::EventArgs^  e)
{
			 if (lbxObjs->SelectedIndex != -1 && cbxPoke->SelectedIndex != -1)
			 {
				 if (strcmp(user->getItem(lbxObjs->SelectedIndex)->getnombre(), "Poción") == 0)
				 {
					 user->getMyPoke(cbxPoke->SelectedIndex)->setvidaActual(
						 user->getMyPoke(cbxPoke->SelectedIndex)->getvidaActual() + 30);
				 }
				 else if (strcmp(user->getItem(lbxObjs->SelectedIndex)->getnombre(), "Baya especial") == 0)
				 {
					 user->getMyPoke(cbxPoke->SelectedIndex)->setvidaActual(
						 user->getMyPoke(cbxPoke->SelectedIndex)->getvidaActual() + 75);
				 }
				 if (user->getMyPoke(cbxPoke->SelectedIndex)->getvidaActual() > user->getMyPoke(cbxPoke->SelectedIndex)->getSalud_PC())
				 {
					 user->getMyPoke(cbxPoke->SelectedIndex)->setvidaActual(user->getMyPoke(cbxPoke->SelectedIndex)->getSalud_PC());
				 }
				 Close();
			 }
			 else MessageBox::Show("Seleccione el elemento faltante", "Error");
}

private: System::Void lbxObjCura_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
}

private: System::Void lbxObjs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
			 String ^strobjs = lbxObjs->SelectedItem->ToString();
			 char *nObj = new char[30]; sprintf(nObj, "%s", strobjs);
			 switch (stdobj)
			 {
			 case 0:
				 if (strcmp(nObj, "Pokeball") == 0 || strcmp(nObj, "Ultraball") == 0)
				 {
					 btnUsarPKBall->Enabled = false;
				 }
				 else
				 {
					 btnUsarPKBall->Enabled = true;
				 }
				 break;
			 case 1:
				 if (strcmp(nObj, "Poción") == 0 || strcmp(nObj, "Baya especial") == 0)
				 {
					 btnUsarPKBall->Enabled = false;
				 }
				 else
				 {
					 btnUsarPKBall->Enabled = true;
				 }
				 break;
			 }
}
};
}
