#pragma once
#include "Personaje.h"
#include "CambiarNombre.h"

namespace PMGO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ListaMyPoke
	/// </summary>
	public ref class ListaMyPoke : public System::Windows::Forms::Form
	{
	private:
		CPersonaje *user; CPokemon *selectedPK; CArrPokemon *objPokes;
		Rectangle btnCerrar; 
		Rectangle btnSubirPC; 
		Rectangle btnEvolucionar;
		Rectangle pokedraws = Rectangle(192, 0, 303, 720);
		Rectangle origen = Rectangle(0, 0, 1079, 2564);
		array<Bitmap^>^ arrPokeSprites;
		Bitmap ^formPoke;
		Graphics ^g; BufferedGraphics ^buff;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::LinkLabel^  linkDescription;

	private: System::Windows::Forms::Label^  lblTipoAtqPrinc;
	private: System::Windows::Forms::Label^  lblTipoAtqDef;


	private: System::Windows::Forms::Label^  lblDañoAtqPrinc;
	private: System::Windows::Forms::Label^  lblDañoAtqDef;




	private: System::Windows::Forms::Label^  lblPeso;
	private: System::Windows::Forms::Label^  lblAltura;
	private: System::Windows::Forms::Label^  lblPolvoEst;
	private: System::Windows::Forms::Label^  lblEvolC;
	private: System::Windows::Forms::Label^  lblReqCarameloEvol;

	private: System::Windows::Forms::Label^  lblReqCarameloMasPC;
	private: System::Windows::Forms::LinkLabel^  linkMote;
	private: System::Windows::Forms::LinkLabel^  linkTransfer;
	private: System::Windows::Forms::LinkLabel^  linkTitular;




	private: System::Windows::Forms::Label^  lblReqPovoEstMasPC;







	public:
		ListaMyPoke(CPersonaje *returned)
		{
			InitializeComponent();
			user = returned;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~ListaMyPoke()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:








	private: System::Windows::Forms::ListBox^  lbxPoke;
	private: System::Windows::Forms::Label^  label1;



	private:

	internal:


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  lbxAtaque;


	private: System::Windows::Forms::Label^  lblPC;
	private: System::Windows::Forms::Label^  lblNombre;
	private: System::Windows::Forms::Label^  lblPS;
	private: System::Windows::Forms::Label^  lblTipo;




	private: System::Windows::Forms::Label^  lblNomAtqPrinc;
	private: System::Windows::Forms::Label^  lblNomAtqDef;


	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lbxPoke = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lbxAtaque = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblPC = (gcnew System::Windows::Forms::Label());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->lblPS = (gcnew System::Windows::Forms::Label());
			this->lblTipo = (gcnew System::Windows::Forms::Label());
			this->lblNomAtqPrinc = (gcnew System::Windows::Forms::Label());
			this->lblNomAtqDef = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->linkDescription = (gcnew System::Windows::Forms::LinkLabel());
			this->lblTipoAtqPrinc = (gcnew System::Windows::Forms::Label());
			this->lblTipoAtqDef = (gcnew System::Windows::Forms::Label());
			this->lblDañoAtqPrinc = (gcnew System::Windows::Forms::Label());
			this->lblDañoAtqDef = (gcnew System::Windows::Forms::Label());
			this->lblPeso = (gcnew System::Windows::Forms::Label());
			this->lblAltura = (gcnew System::Windows::Forms::Label());
			this->lblPolvoEst = (gcnew System::Windows::Forms::Label());
			this->lblEvolC = (gcnew System::Windows::Forms::Label());
			this->lblReqCarameloEvol = (gcnew System::Windows::Forms::Label());
			this->lblReqCarameloMasPC = (gcnew System::Windows::Forms::Label());
			this->lblReqPovoEstMasPC = (gcnew System::Windows::Forms::Label());
			this->linkMote = (gcnew System::Windows::Forms::LinkLabel());
			this->linkTransfer = (gcnew System::Windows::Forms::LinkLabel());
			this->linkTitular = (gcnew System::Windows::Forms::LinkLabel());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbxPoke
			// 
			this->lbxPoke->FormattingEnabled = true;
			this->lbxPoke->HorizontalScrollbar = true;
			this->lbxPoke->Location = System::Drawing::Point(18, 34);
			this->lbxPoke->Name = L"lbxPoke";
			this->lbxPoke->Size = System::Drawing::Size(101, 199);
			this->lbxPoke->TabIndex = 19;
			this->lbxPoke->SelectedIndexChanged += gcnew System::EventHandler(this, &ListaMyPoke::lbxPoke_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 26);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Selecciona un\r\npokemon:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lbxAtaque);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(18, 239);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(168, 324);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ataques aprendidos:";
			// 
			// lbxAtaque
			// 
			this->lbxAtaque->FormattingEnabled = true;
			this->lbxAtaque->Location = System::Drawing::Point(3, 16);
			this->lbxAtaque->Name = L"lbxAtaque";
			this->lbxAtaque->Size = System::Drawing::Size(155, 199);
			this->lbxAtaque->TabIndex = 32;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 23);
			this->button2->TabIndex = 31;
			this->button2->Text = L"Ataque definitivo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ListaMyPoke::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 23);
			this->button1->TabIndex = 31;
			this->button1->Text = L"Ataque principal";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ListaMyPoke::button1_Click);
			// 
			// lblPC
			// 
			this->lblPC->AutoSize = true;
			this->lblPC->BackColor = System::Drawing::Color::GhostWhite;
			this->lblPC->Location = System::Drawing::Point(328, 219);
			this->lblPC->Name = L"lblPC";
			this->lblPC->Size = System::Drawing::Size(0, 13);
			this->lblPC->TabIndex = 34;
			this->lblPC->Visible = false;
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->BackColor = System::Drawing::Color::GhostWhite;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombre->Location = System::Drawing::Point(291, 242);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(0, 19);
			this->lblNombre->TabIndex = 35;
			this->lblNombre->Visible = false;
			// 
			// lblPS
			// 
			this->lblPS->AutoSize = true;
			this->lblPS->BackColor = System::Drawing::Color::GhostWhite;
			this->lblPS->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPS->Location = System::Drawing::Point(311, 286);
			this->lblPS->Name = L"lblPS";
			this->lblPS->Size = System::Drawing::Size(35, 13);
			this->lblPS->TabIndex = 36;
			this->lblPS->Text = L"            /";
			this->lblPS->Visible = false;
			// 
			// lblTipo
			// 
			this->lblTipo->AutoSize = true;
			this->lblTipo->BackColor = System::Drawing::Color::GhostWhite;
			this->lblTipo->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTipo->Location = System::Drawing::Point(331, 320);
			this->lblTipo->Name = L"lblTipo";
			this->lblTipo->Size = System::Drawing::Size(0, 13);
			this->lblTipo->TabIndex = 37;
			this->lblTipo->Visible = false;
			// 
			// lblNomAtqPrinc
			// 
			this->lblNomAtqPrinc->AutoSize = true;
			this->lblNomAtqPrinc->BackColor = System::Drawing::Color::GhostWhite;
			this->lblNomAtqPrinc->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNomAtqPrinc->Location = System::Drawing::Point(241, 539);
			this->lblNomAtqPrinc->Name = L"lblNomAtqPrinc";
			this->lblNomAtqPrinc->Size = System::Drawing::Size(85, 13);
			this->lblNomAtqPrinc->TabIndex = 38;
			this->lblNomAtqPrinc->Text = L"Ataque principal";
			this->lblNomAtqPrinc->Visible = false;
			// 
			// lblNomAtqDef
			// 
			this->lblNomAtqDef->AutoSize = true;
			this->lblNomAtqDef->BackColor = System::Drawing::Color::GhostWhite;
			this->lblNomAtqDef->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNomAtqDef->Location = System::Drawing::Point(241, 566);
			this->lblNomAtqDef->Name = L"lblNomAtqDef";
			this->lblNomAtqDef->Size = System::Drawing::Size(87, 13);
			this->lblNomAtqDef->TabIndex = 38;
			this->lblNomAtqDef->Text = L"Ataque definitivo";
			this->lblNomAtqDef->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &ListaMyPoke::timer1_Tick);
			// 
			// linkDescription
			// 
			this->linkDescription->AutoSize = true;
			this->linkDescription->BackColor = System::Drawing::Color::GhostWhite;
			this->linkDescription->Location = System::Drawing::Point(379, 618);
			this->linkDescription->Name = L"linkDescription";
			this->linkDescription->Size = System::Drawing::Size(80, 13);
			this->linkDescription->TabIndex = 41;
			this->linkDescription->TabStop = true;
			this->linkDescription->Text = L"Ver descripción";
			this->linkDescription->Visible = false;
			this->linkDescription->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ListaMyPoke::linkDescripcion_LinkClicked);
			// 
			// lblTipoAtqPrinc
			// 
			this->lblTipoAtqPrinc->AutoSize = true;
			this->lblTipoAtqPrinc->BackColor = System::Drawing::Color::GhostWhite;
			this->lblTipoAtqPrinc->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTipoAtqPrinc->Location = System::Drawing::Point(360, 539);
			this->lblTipoAtqPrinc->Name = L"lblTipoAtqPrinc";
			this->lblTipoAtqPrinc->Size = System::Drawing::Size(27, 13);
			this->lblTipoAtqPrinc->TabIndex = 38;
			this->lblTipoAtqPrinc->Text = L"Tipo";
			this->lblTipoAtqPrinc->Visible = false;
			// 
			// lblTipoAtqDef
			// 
			this->lblTipoAtqDef->AutoSize = true;
			this->lblTipoAtqDef->BackColor = System::Drawing::Color::GhostWhite;
			this->lblTipoAtqDef->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTipoAtqDef->Location = System::Drawing::Point(360, 566);
			this->lblTipoAtqDef->Name = L"lblTipoAtqDef";
			this->lblTipoAtqDef->Size = System::Drawing::Size(27, 13);
			this->lblTipoAtqDef->TabIndex = 38;
			this->lblTipoAtqDef->Text = L"Tipo";
			this->lblTipoAtqDef->Visible = false;
			this->lblTipoAtqDef->Click += gcnew System::EventHandler(this, &ListaMyPoke::label9_Click);
			// 
			// lblDañoAtqPrinc
			// 
			this->lblDañoAtqPrinc->AutoSize = true;
			this->lblDañoAtqPrinc->BackColor = System::Drawing::Color::GhostWhite;
			this->lblDañoAtqPrinc->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDañoAtqPrinc->Location = System::Drawing::Point(431, 539);
			this->lblDañoAtqPrinc->Name = L"lblDañoAtqPrinc";
			this->lblDañoAtqPrinc->Size = System::Drawing::Size(32, 13);
			this->lblDañoAtqPrinc->TabIndex = 38;
			this->lblDañoAtqPrinc->Text = L"Daño";
			this->lblDañoAtqPrinc->Visible = false;
			// 
			// lblDañoAtqDef
			// 
			this->lblDañoAtqDef->AutoSize = true;
			this->lblDañoAtqDef->BackColor = System::Drawing::Color::GhostWhite;
			this->lblDañoAtqDef->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDañoAtqDef->Location = System::Drawing::Point(431, 566);
			this->lblDañoAtqDef->Name = L"lblDañoAtqDef";
			this->lblDañoAtqDef->Size = System::Drawing::Size(32, 13);
			this->lblDañoAtqDef->TabIndex = 38;
			this->lblDañoAtqDef->Text = L"Daño";
			this->lblDañoAtqDef->Visible = false;
			// 
			// lblPeso
			// 
			this->lblPeso->AutoSize = true;
			this->lblPeso->BackColor = System::Drawing::Color::GhostWhite;
			this->lblPeso->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPeso->Location = System::Drawing::Point(234, 313);
			this->lblPeso->Name = L"lblPeso";
			this->lblPeso->Size = System::Drawing::Size(0, 13);
			this->lblPeso->TabIndex = 37;
			this->lblPeso->Visible = false;
			// 
			// lblAltura
			// 
			this->lblAltura->AutoSize = true;
			this->lblAltura->BackColor = System::Drawing::Color::GhostWhite;
			this->lblAltura->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAltura->Location = System::Drawing::Point(418, 313);
			this->lblAltura->Name = L"lblAltura";
			this->lblAltura->Size = System::Drawing::Size(0, 13);
			this->lblAltura->TabIndex = 37;
			this->lblAltura->Visible = false;
			// 
			// lblPolvoEst
			// 
			this->lblPolvoEst->AutoSize = true;
			this->lblPolvoEst->BackColor = System::Drawing::Color::GhostWhite;
			this->lblPolvoEst->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPolvoEst->Location = System::Drawing::Point(270, 375);
			this->lblPolvoEst->Name = L"lblPolvoEst";
			this->lblPolvoEst->Size = System::Drawing::Size(13, 13);
			this->lblPolvoEst->TabIndex = 37;
			this->lblPolvoEst->Text = L"0";
			this->lblPolvoEst->Visible = false;
			// 
			// lblEvolC
			// 
			this->lblEvolC->AutoSize = true;
			this->lblEvolC->BackColor = System::Drawing::Color::GhostWhite;
			this->lblEvolC->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEvolC->Location = System::Drawing::Point(396, 375);
			this->lblEvolC->Name = L"lblEvolC";
			this->lblEvolC->Size = System::Drawing::Size(13, 13);
			this->lblEvolC->TabIndex = 37;
			this->lblEvolC->Text = L"0";
			this->lblEvolC->Visible = false;
			// 
			// lblReqCarameloEvol
			// 
			this->lblReqCarameloEvol->AutoSize = true;
			this->lblReqCarameloEvol->BackColor = System::Drawing::Color::Lavender;
			this->lblReqCarameloEvol->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblReqCarameloEvol->Location = System::Drawing::Point(422, 475);
			this->lblReqCarameloEvol->Name = L"lblReqCarameloEvol";
			this->lblReqCarameloEvol->Size = System::Drawing::Size(0, 13);
			this->lblReqCarameloEvol->TabIndex = 37;
			this->lblReqCarameloEvol->Visible = false;
			// 
			// lblReqCarameloMasPC
			// 
			this->lblReqCarameloMasPC->AutoSize = true;
			this->lblReqCarameloMasPC->BackColor = System::Drawing::Color::Lavender;
			this->lblReqCarameloMasPC->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblReqCarameloMasPC->Location = System::Drawing::Point(422, 431);
			this->lblReqCarameloMasPC->Name = L"lblReqCarameloMasPC";
			this->lblReqCarameloMasPC->Size = System::Drawing::Size(0, 13);
			this->lblReqCarameloMasPC->TabIndex = 37;
			this->lblReqCarameloMasPC->Visible = false;
			// 
			// lblReqPovoEstMasPC
			// 
			this->lblReqPovoEstMasPC->AutoSize = true;
			this->lblReqPovoEstMasPC->BackColor = System::Drawing::Color::Lavender;
			this->lblReqPovoEstMasPC->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblReqPovoEstMasPC->Location = System::Drawing::Point(363, 431);
			this->lblReqPovoEstMasPC->Name = L"lblReqPovoEstMasPC";
			this->lblReqPovoEstMasPC->Size = System::Drawing::Size(0, 13);
			this->lblReqPovoEstMasPC->TabIndex = 37;
			this->lblReqPovoEstMasPC->Visible = false;
			// 
			// linkMote
			// 
			this->linkMote->AutoSize = true;
			this->linkMote->BackColor = System::Drawing::Color::GhostWhite;
			this->linkMote->Location = System::Drawing::Point(241, 618);
			this->linkMote->Name = L"linkMote";
			this->linkMote->Size = System::Drawing::Size(86, 13);
			this->linkMote->TabIndex = 41;
			this->linkMote->TabStop = true;
			this->linkMote->Text = L"Apodo Pokémon";
			this->linkMote->Visible = false;
			this->linkMote->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ListaMyPoke::linkMote1_LinkClicked);
			// 
			// linkTransfer
			// 
			this->linkTransfer->AutoSize = true;
			this->linkTransfer->BackColor = System::Drawing::Color::GhostWhite;
			this->linkTransfer->Location = System::Drawing::Point(234, 641);
			this->linkTransfer->Name = L"linkTransfer";
			this->linkTransfer->Size = System::Drawing::Size(99, 13);
			this->linkTransfer->TabIndex = 42;
			this->linkTransfer->TabStop = true;
			this->linkTransfer->Text = L"Transferir Pokémon";
			this->linkTransfer->Visible = false;
			this->linkTransfer->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ListaMyPoke::linkTransfer_LinkClicked);
			// 
			// linkTitular
			// 
			this->linkTitular->AutoSize = true;
			this->linkTitular->BackColor = System::Drawing::Color::GhostWhite;
			this->linkTitular->Location = System::Drawing::Point(375, 641);
			this->linkTitular->Name = L"linkTitular";
			this->linkTitular->Size = System::Drawing::Size(90, 13);
			this->linkTitular->TabIndex = 42;
			this->linkTitular->TabStop = true;
			this->linkTitular->Text = L"Enviar a combate";
			this->linkTitular->Visible = false;
			this->linkTitular->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ListaMyPoke::linkTitular_LinkClicked);
			// 
			// ListaMyPoke
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 719);
			this->Controls->Add(this->linkTitular);
			this->Controls->Add(this->linkTransfer);
			this->Controls->Add(this->linkMote);
			this->Controls->Add(this->linkDescription);
			this->Controls->Add(this->lblDañoAtqDef);
			this->Controls->Add(this->lblTipoAtqDef);
			this->Controls->Add(this->lblNomAtqDef);
			this->Controls->Add(this->lblDañoAtqPrinc);
			this->Controls->Add(this->lblTipoAtqPrinc);
			this->Controls->Add(this->lblNomAtqPrinc);
			this->Controls->Add(this->lblReqCarameloEvol);
			this->Controls->Add(this->lblReqCarameloMasPC);
			this->Controls->Add(this->lblEvolC);
			this->Controls->Add(this->lblAltura);
			this->Controls->Add(this->lblReqPovoEstMasPC);
			this->Controls->Add(this->lblPolvoEst);
			this->Controls->Add(this->lblPeso);
			this->Controls->Add(this->lblTipo);
			this->Controls->Add(this->lblPS);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->lblPC);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lbxPoke);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ListaMyPoke";
			this->Text = L"ListaMyPoke";
			this->Load += gcnew System::EventHandler(this, &ListaMyPoke::ListaMyPoke_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ListaMyPoke::ListaMyPoke_MouseClick);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int getidx()
		{
			return lbxPoke->SelectedIndex;
		}
		int getindicePKdex()
		{
			return user->getMyPoke(getidx())->getIndice();
		}
	private: System::Void ListaMyPoke_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 g = this->CreateGraphics();
				 BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
				 buff = context->Allocate(g, this->ClientRectangle);
				 delete context;

				 objPokes = new CArrPokemon();
				 arrPokeSprites = gcnew array<Bitmap^>(objPokes->getsize());

				 for (int i = 0; i < objPokes->getsize(); i++)
				 {
					 arrPokeSprites[i] = gcnew Bitmap(i.ToString() + ".png");
				 }
				 for (int i = 0; i < user->getlistaMisPokes().size(); i++)
				 {
					 String ^strnombre = gcnew String(user->getlistaMisPokes()[i]->getnombre());
					 lbxPoke->Items->Add(strnombre);
				 }
				 formPoke = gcnew Bitmap("FormPoke.png");
				 btnCerrar = Rectangle(325, 662, 37, 37);
				 btnSubirPC = Rectangle(220, 420, 122, 37);
				 btnEvolucionar = Rectangle(220, 464, 122, 36);

				 buff->Graphics->DrawImage(formPoke, pokedraws, origen, GraphicsUnit::Pixel);
	}
private: System::Void lbxPoke_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
			 if (lbxPoke->SelectedIndex != -1)
			 {
				 timer1->Enabled = true;
				 lbxAtaque->Items->Clear();
				 int sizeatq = user->getMyPoke(getidx())->getataquesAprendidos().size();
				 for (int i = 0; i < sizeatq; i++)
				 {
					 String ^stratqnom = gcnew String(user->getMyPoke(getidx())->getAtaqueAprendido(i)->getnombre());
					 String ^stratqtipo = gcnew String(user->getMyPoke(getidx())->getAtaqueAprendido(i)->gettipo());
					 int daño = user->getMyPoke(getidx())->getAtaqueAprendido(i)->getdaño();

					 lbxAtaque->Items->Add(stratqnom);
				 }
				 int largopoke = user->getMyPoke(getidx())->getlargo() / 2;
				 int altopoke = user->getMyPoke(getidx())->getalto();
				 user->getMyPoke(getidx())->setx(340 - largopoke);
				 user->getMyPoke(getidx())->sety(200 - altopoke);

				 lblPC->Visible = true;
				 lblNombre->Visible = true;
				 lblPS->Visible = true;
				 lblPeso->Visible = true;
				 lblTipo->Visible = true;
				 lblAltura->Visible = true;
				 lblPolvoEst->Visible = true;
				 lblEvolC->Visible = true;
				 lblReqPovoEstMasPC->Visible = true;
				 lblReqCarameloMasPC->Visible = true;
				 lblReqCarameloEvol->Visible = true;
				 lblNomAtqPrinc->Visible = true;
				 lblTipoAtqPrinc->Visible = true;
				 lblDañoAtqPrinc->Visible = true;
				 lblNomAtqDef->Visible = true;
				 lblTipoAtqDef->Visible = true;
				 lblDañoAtqDef->Visible = true;

				 linkMote->Visible = true;
				 linkTransfer->Visible = true;
				 linkDescription->Visible = true;
				 linkTitular->Visible = true;
			 } 
}
private: System::Void LViewAtaque_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
	//Apodo
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
			 
			 buff->Graphics->Clear(this->BackColor);
			 buff->Graphics->DrawImage(formPoke, pokedraws, origen, GraphicsUnit::Pixel);
			 user->getMyPoke(getidx())->dibujar(buff->Graphics, arrPokeSprites[getindicePKdex()]);

			 buff->Render(g);
			 
			 String ^strmote = gcnew String(user->getMyPoke(getidx())->getmote());
			 String ^strnombre = gcnew String(user->getMyPoke(getidx())->getnombre());
			 String ^strtipo;
			 if (strcmp(user->getMyPoke(getidx())->gettipo2(), "") == 0)
			 {
				 strtipo = gcnew String(user->getMyPoke(getidx())->gettipo1());
			 }
			 else
			 {
				 String ^t2 = gcnew String(user->getMyPoke(getidx())->gettipo2());
				 strtipo = gcnew String(user->getMyPoke(getidx())->gettipo1()) + "\n" + t2;
			 }
			 String ^stratqprinc = gcnew String(user->getMyPoke(getidx())->getataquePrincipal()->getnombre());
			 String ^strtipoatqprinc = gcnew String(user->getMyPoke(getidx())->getataquePrincipal()->gettipo());
			 String ^stratqdef = gcnew String(user->getMyPoke(getidx())->getataqueDefinitivo()->getnombre());
			 String ^strtipoatqdef = gcnew String(user->getMyPoke(getidx())->getataqueDefinitivo()->gettipo());
			 lblPC->Text = "PC " + user->getMyPoke(getidx())->getPC().ToString();
			 if (strcmp(user->getMyPoke(getidx())->getnombre(), user->getMyPoke(getidx())->getmote()) == 0)
			 {
				 lblNombre->Text = strnombre;
			 }
			 else
			 {
				 lblNombre->Text = strmote + " (" + strnombre + ")";
			 }
			 
			 lblPS->Text = user->getMyPoke(getidx())->getvidaActual().ToString() + " / " +
				 user->getMyPoke(getidx())->getSalud_PC().ToString() + " PS";
			 lblPeso->Text = user->getMyPoke(getidx())->getpeso().ToString() + " kg";
			 lblTipo->Text = strtipo;
			 lblAltura->Text = user->getMyPoke(getidx())->getaltura().ToString() + " m";
			 lblPolvoEst->Text = user->getnPolvoestelares().ToString();
			 lblEvolC->Text = user->getnCaramelos().ToString();
			 lblReqPovoEstMasPC->Text = user->getMyPoke(getidx())->getnPolvoEst_requiereMasPC().ToString();
			 lblReqCarameloMasPC->Text = "1";
			 lblReqCarameloEvol->Text = user->getMyPoke(getidx())->getnCaram_requiereEvol().ToString();
			 lblNomAtqPrinc->Text = stratqprinc;
			 lblTipoAtqPrinc->Text = strtipoatqprinc;
			 lblDañoAtqPrinc->Text = user->getMyPoke(getidx())->getataquePrincipal()->getdaño().ToString();
			 lblNomAtqDef->Text = stratqdef;
			 lblTipoAtqDef->Text = strtipoatqdef;
			 lblDañoAtqDef->Text = user->getMyPoke(getidx())->getataqueDefinitivo()->getdaño().ToString();

}
private: System::Void ListaMyPoke_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
			 Rectangle Cursorquad = Rectangle(e->X, e->Y, 4, 4);
			 if (btnCerrar.IntersectsWith(Cursorquad))
			 {
				 timer1->Enabled = false;
				 this->Close();
			 }
			 if (btnEvolucionar.IntersectsWith(Cursorquad))
			 {
				 if (user->getMyPoke(getidx())->gettieneEvolucion() == 1)
				 {
					 if (user->getnCaramelos() >= user->getMyPoke(getidx())->getnCaram_requiereEvol())
					 {
						 String ^motePK = gcnew String(user->getMyPoke(getidx())->getmote()),
							 ^strevol;
						 user->evolucionar(getidx());
						 strevol = gcnew String(user->getMyPoke(getidx())->getnombre());
						
						 MessageBox::Show("Tu " + motePK + " ha evolucionado a " + strevol);
					 }
					 else
					 {
						 MessageBox::Show("No tienes los suficientes\ncaramelos para evolucionar");
					 }
				 }
				 else
				 {
					 MessageBox::Show("Este Pokémon está en su forma máxima.\nNo puede evolucionar");
				 }
			 }
			 if (btnSubirPC.IntersectsWith(Cursorquad))
			 {
				 if (user->getnPolvoestelares() >= user->getMyPoke(getidx())->getnPolvoEst_requiereMasPC())
				 {
					 String ^strmote = gcnew String(user->getMyPoke(getidx())->getmote());
					 user->subirPC(user->getMyPoke(getidx()),
						 user->getMyPoke(getidx())->getnPolvoEst_requiereMasPC());
					 MessageBox::Show("Tu " + strmote + " ha aumentado sus\npuntos de combate");
				 }
			 }
}
private: System::Void linkTitular_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
			 for (int i = 0; i < user->getlistaMisPokes().size(); i++)
			 {
				 user->getMyPoke(i)->setdeEspalda(5);
			 }
			 user->getMyPoke(getidx())->setdeEspalda(1);
			 MessageBox::Show("Tu Pokemon està listo para combatir");
}
private: System::Void linkTransfer_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
			 lblPC->Visible = false;
			 lblNombre->Visible = false;
			 lblPS->Visible = false;
			 lblPeso->Visible = false;
			 lblTipo->Visible = false;
			 lblAltura->Visible = false;
			 lblPolvoEst->Visible = false;
			 lblEvolC->Visible = false;
			 lblReqPovoEstMasPC->Visible = false;
			 lblReqCarameloMasPC->Visible = false;
			 lblReqCarameloEvol->Visible = false;
			 lblNomAtqPrinc->Visible = false;
			 lblTipoAtqPrinc->Visible = false;
			 lblDañoAtqPrinc->Visible = false;
			 lblNomAtqDef->Visible = false;
			 lblTipoAtqDef->Visible = false;
			 lblDañoAtqDef->Visible = false;
			 linkMote->Visible = false;
			 linkTransfer->Visible = false;
			 linkDescription->Visible = false;
			 linkTitular->Visible = false;

			 String ^strn = gcnew String(user->getMyPoke(getidx())->getmote());

			 buff->Graphics->Clear(this->BackColor);
			 timer1->Enabled = false;
			 lbxPoke->Items->Clear();
			 user->transferirPoke(getidx());

			 for (int i = 0; i < user->getlistaMisPokes().size(); i++)
			 {
				 String ^strnombre = gcnew String(user->getlistaMisPokes()[i]->getnombre());
				 lbxPoke->Items->Add(strnombre);
			 }
			 MessageBox::Show("Has transferido a " + strn + " por 6 caramelos");
}
private: System::Void linkDescripcion_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
			 String ^strdescripcion = gcnew String(user->getMyPoke(getidx())->getdescripcion());
			 int atq = user->getMyPoke(getidx())->getataque(),
				 def = user->getMyPoke(getidx())->getdefensa(),
				 vel = user->getMyPoke(getidx())->getvelocidad();
			 MessageBox::Show("Ataque: " + atq.ToString() + "\n\nDefensa: " + def.ToString() + "\n\nVelocidad: " + vel.ToString()
				 + "\n\nDescripción\n" + strdescripcion );
}
private: System::Void linkMote1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
			 timer1->Enabled = false;
			 CambiarNombre ^motesP = gcnew CambiarNombre(user->getMyPoke(getidx()));
			 motesP->ShowDialog(this);
			 timer1->Enabled = true;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
			 //Ataque principal
			 CAtaque *getAtq = user->getMyPoke(getidx())->getAtaqueAprendido(lbxAtaque->SelectedIndex);
			 user->getMyPoke(getidx())->setataquePrincipal(getAtq);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
			 //Ataque definitivo
			 CAtaque *getAtq = user->getMyPoke(getidx())->getAtaqueAprendido(lbxAtaque->SelectedIndex);
			 user->getMyPoke(getidx())->setataqueDefinitivo(getAtq);
}
};
}
