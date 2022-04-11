#pragma once
#include "Personaje.h"
#include "MapaPrincipal.h"

namespace PMGO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GO_Pokeform
	/// </summary>
	public ref class GO_Pokeform : public System::Windows::Forms::Form
	{
	private:
		CArrPokemon *objPokes; CPokemon *selectedPokedex; CPersonaje *nuevoP;
		CArrObjeto *arrobjs = new CArrObjeto();
		array<Bitmap^>^ arrPokeSprites;
		array<Bitmap^>^ arrPokeBackSprites;

		array<Bitmap^>^ arrMegaSprites;
		array<Bitmap^>^ arrMegaBackSprites;

		Bitmap ^MegaCharY, ^backMegaCharY;

		Graphics ^g; BufferedGraphics ^buff;















	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ListBox^  lbxPoke;
	private: System::Windows::Forms::Label^  lblIndice;
	private: System::Windows::Forms::Label^  lblTipo;
	private: System::Windows::Forms::Label^  lblSalud;
	private: System::Windows::Forms::Label^  lblAtaque;
	private: System::Windows::Forms::Label^  lblDefensa;
	private: System::Windows::Forms::Label^  lblVelocidad;
	private: System::Windows::Forms::Label^  lblPeso;
	private: System::Windows::Forms::Label^  lblAltura;
	private: System::Windows::Forms::Label^  descripcionPoke;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RadioButton^  selectSerena;

	private: System::Windows::Forms::RadioButton^  selectAsh;












			 CArrAtaque *objAtq;
	public:
		GO_Pokeform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GO_Pokeform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	protected:

	private: System::Windows::Forms::Button^  btnRegistrar;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbxNombrePersonaje;



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GO_Pokeform::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbxNombrePersonaje = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbxPoke = (gcnew System::Windows::Forms::ListBox());
			this->lblIndice = (gcnew System::Windows::Forms::Label());
			this->lblTipo = (gcnew System::Windows::Forms::Label());
			this->lblSalud = (gcnew System::Windows::Forms::Label());
			this->lblAtaque = (gcnew System::Windows::Forms::Label());
			this->lblDefensa = (gcnew System::Windows::Forms::Label());
			this->lblVelocidad = (gcnew System::Windows::Forms::Label());
			this->lblPeso = (gcnew System::Windows::Forms::Label());
			this->lblAltura = (gcnew System::Windows::Forms::Label());
			this->descripcionPoke = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->selectSerena = (gcnew System::Windows::Forms::RadioButton());
			this->selectAsh = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 257);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Selecciona un pokemon:";
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->Location = System::Drawing::Point(583, 405);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(75, 23);
			this->btnRegistrar->TabIndex = 2;
			this->btnRegistrar->Text = L"Registrar";
			this->btnRegistrar->UseVisualStyleBackColor = true;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &GO_Pokeform::btnRegistrar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 228);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Ingresa tu nombre:";
			// 
			// tbxNombrePersonaje
			// 
			this->tbxNombrePersonaje->Location = System::Drawing::Point(113, 221);
			this->tbxNombrePersonaje->Name = L"tbxNombrePersonaje";
			this->tbxNombrePersonaje->Size = System::Drawing::Size(235, 20);
			this->tbxNombrePersonaje->TabIndex = 4;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &GO_Pokeform::timer1_Tick);
			// 
			// lbxPoke
			// 
			this->lbxPoke->FormattingEnabled = true;
			this->lbxPoke->HorizontalScrollbar = true;
			this->lbxPoke->Location = System::Drawing::Point(15, 282);
			this->lbxPoke->Name = L"lbxPoke";
			this->lbxPoke->Size = System::Drawing::Size(101, 160);
			this->lbxPoke->TabIndex = 8;
			this->lbxPoke->SelectedIndexChanged += gcnew System::EventHandler(this, &GO_Pokeform::lbxPoke_SelectedIndexChanged);
			// 
			// lblIndice
			// 
			this->lblIndice->AutoSize = true;
			this->lblIndice->Location = System::Drawing::Point(122, 285);
			this->lblIndice->Name = L"lblIndice";
			this->lblIndice->Size = System::Drawing::Size(72, 13);
			this->lblIndice->TabIndex = 9;
			this->lblIndice->Text = L"No. Pokedex:";
			// 
			// lblTipo
			// 
			this->lblTipo->AutoSize = true;
			this->lblTipo->Location = System::Drawing::Point(122, 311);
			this->lblTipo->Name = L"lblTipo";
			this->lblTipo->Size = System::Drawing::Size(31, 13);
			this->lblTipo->TabIndex = 10;
			this->lblTipo->Text = L"Tipo:";
			// 
			// lblSalud
			// 
			this->lblSalud->AutoSize = true;
			this->lblSalud->Location = System::Drawing::Point(122, 337);
			this->lblSalud->Name = L"lblSalud";
			this->lblSalud->Size = System::Drawing::Size(37, 13);
			this->lblSalud->TabIndex = 11;
			this->lblSalud->Text = L"Salud:";
			// 
			// lblAtaque
			// 
			this->lblAtaque->AutoSize = true;
			this->lblAtaque->Location = System::Drawing::Point(122, 363);
			this->lblAtaque->Name = L"lblAtaque";
			this->lblAtaque->Size = System::Drawing::Size(44, 13);
			this->lblAtaque->TabIndex = 12;
			this->lblAtaque->Text = L"Ataque:";
			this->lblAtaque->Click += gcnew System::EventHandler(this, &GO_Pokeform::label7_Click);
			// 
			// lblDefensa
			// 
			this->lblDefensa->AutoSize = true;
			this->lblDefensa->Location = System::Drawing::Point(122, 389);
			this->lblDefensa->Name = L"lblDefensa";
			this->lblDefensa->Size = System::Drawing::Size(50, 13);
			this->lblDefensa->TabIndex = 13;
			this->lblDefensa->Text = L"Defensa:";
			// 
			// lblVelocidad
			// 
			this->lblVelocidad->AutoSize = true;
			this->lblVelocidad->Location = System::Drawing::Point(122, 415);
			this->lblVelocidad->Name = L"lblVelocidad";
			this->lblVelocidad->Size = System::Drawing::Size(57, 13);
			this->lblVelocidad->TabIndex = 14;
			this->lblVelocidad->Text = L"Velocidad:";
			// 
			// lblPeso
			// 
			this->lblPeso->AutoSize = true;
			this->lblPeso->Location = System::Drawing::Point(266, 285);
			this->lblPeso->Name = L"lblPeso";
			this->lblPeso->Size = System::Drawing::Size(34, 13);
			this->lblPeso->TabIndex = 15;
			this->lblPeso->Text = L"Peso:";
			// 
			// lblAltura
			// 
			this->lblAltura->AutoSize = true;
			this->lblAltura->Location = System::Drawing::Point(266, 311);
			this->lblAltura->Name = L"lblAltura";
			this->lblAltura->Size = System::Drawing::Size(37, 13);
			this->lblAltura->TabIndex = 16;
			this->lblAltura->Text = L"Altura:";
			// 
			// descripcionPoke
			// 
			this->descripcionPoke->AutoSize = true;
			this->descripcionPoke->Location = System::Drawing::Point(405, 285);
			this->descripcionPoke->Name = L"descripcionPoke";
			this->descripcionPoke->Size = System::Drawing::Size(66, 13);
			this->descripcionPoke->TabIndex = 17;
			this->descripcionPoke->Text = L"Descripción:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBox2);
			this->groupBox1->Controls->Add(this->pictureBox4);
			this->groupBox1->Controls->Add(this->pictureBox3);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Controls->Add(this->selectSerena);
			this->groupBox1->Controls->Add(this->selectAsh);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(631, 203);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Selecciona tu personaje:";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(369, 35);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(90, 162);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(460, 43);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(29, 147);
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(141, 43);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(28, 147);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(116, 162);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// selectSerena
			// 
			this->selectSerena->AutoSize = true;
			this->selectSerena->Location = System::Drawing::Point(334, 19);
			this->selectSerena->Name = L"selectSerena";
			this->selectSerena->Size = System::Drawing::Size(51, 17);
			this->selectSerena->TabIndex = 1;
			this->selectSerena->TabStop = true;
			this->selectSerena->Text = L"Mujer";
			this->selectSerena->UseVisualStyleBackColor = true;
			// 
			// selectAsh
			// 
			this->selectAsh->AutoSize = true;
			this->selectAsh->Location = System::Drawing::Point(6, 19);
			this->selectAsh->Name = L"selectAsh";
			this->selectAsh->Size = System::Drawing::Size(62, 17);
			this->selectAsh->TabIndex = 0;
			this->selectAsh->TabStop = true;
			this->selectAsh->Text = L"Hombre";
			this->selectAsh->UseVisualStyleBackColor = true;
			// 
			// GO_Pokeform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 468);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->descripcionPoke);
			this->Controls->Add(this->lblAltura);
			this->Controls->Add(this->lblPeso);
			this->Controls->Add(this->lblVelocidad);
			this->Controls->Add(this->lblDefensa);
			this->Controls->Add(this->lblAtaque);
			this->Controls->Add(this->lblSalud);
			this->Controls->Add(this->lblTipo);
			this->Controls->Add(this->lblIndice);
			this->Controls->Add(this->lbxPoke);
			this->Controls->Add(this->tbxNombrePersonaje);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->label1);
			this->Name = L"GO_Pokeform";
			this->Text = L"GO_Pokeform";
			this->Load += gcnew System::EventHandler(this, &GO_Pokeform::GO_Pokeform_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GO_Pokeform_Load(System::Object^  sender, System::EventArgs^  e)
	{
		objPokes = new CArrPokemon();
		objAtq = new CArrAtaque();
		arrPokeSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrPokeBackSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrMegaSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrMegaBackSprites = gcnew array<Bitmap^>(objPokes->getsize());
		MegaCharY = gcnew Bitmap("6-mega2.png"); backMegaCharY = gcnew Bitmap("6-mega2-back.png");

		for (int i = 0; i < objPokes->getsize(); i++)
		{
			
				String ^strNombre = gcnew String(objPokes->getPoke(i)->getnombre());
				lbxPoke->Items->Add(strNombre);

			arrPokeSprites[i] = gcnew Bitmap(i.ToString()+".png");
			arrPokeBackSprites[i] = gcnew Bitmap(i.ToString()+"-back.png");
			if (objPokes->getPoke(i)->gettieneMega() == 1)
			{
				arrMegaSprites[i] = gcnew Bitmap(i.ToString() + "-mega.png");
				arrMegaBackSprites[i] = gcnew Bitmap(i.ToString() + "-mega-back.png");
			}
			else
			{
				arrMegaSprites[i] = gcnew Bitmap("-1.png");
				arrMegaBackSprites[i] = gcnew Bitmap("-1.png");
			}
		}

		int anchoForm = this->ClientRectangle.Width;
		int altoForm = this->ClientRectangle.Height;
		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buff = context->Allocate(g, this->ClientRectangle);
		delete context;
	}
	private: System::Void btnRegistrar_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (lbxPoke->SelectedIndex == -1 || (selectAsh->Checked == false && selectSerena->Checked == false) || tbxNombrePersonaje->Text == "") MessageBox::Show("Necestas completar todos los datos para iniciar el juego.");
		else
		{
			Random r;
			char *nombreP = new char[30]; sprintf(nombreP, "%s", tbxNombrePersonaje);

			int H_M;
			if (selectAsh->Checked == true) H_M = 0;
			else if (selectSerena->Checked == true) H_M = 1;
			CPokemon *myPoke = selectedPokedex;
			CAtaque *princ = objAtq->getAtaque(r.Next(100, 105));
			int listaatq[10], indatq = 0;
			for (int i = 0; i < objAtq->getsize(); i++)
			{
				if (strcmp(myPoke->gettipo1(), objAtq->getAtaque(i)->gettipo()) == 0)
				{
					listaatq[indatq] = i;
					indatq++;
				}
			}

			CAtaque *def = objAtq->getAtaque(r.Next(listaatq[0], listaatq[9]));

			myPoke->aprenderAtaque(princ); myPoke->setataquePrincipal(princ);
			myPoke->aprenderAtaque(def); myPoke->setataqueDefinitivo(def);
			myPoke->setdeEspalda(1);
			myPoke->setPC(700);
			myPoke->setvidaActual(myPoke->getSalud_PC());

			nuevoP = new CPersonaje(32, 208, 28, 34, 16, 16, 0, 0, 4,
				nombreP, H_M, 0, 1, 0, 100, 8000, myPoke);
			for (int i = 0; i < 10; i++)
			{
				nuevoP->aumentarlistaObj(arrobjs->getObj("Pokeball"));
				nuevoP->aumentarlistaObj(arrobjs->getObj("Poción"));
			}

			CPokemon *objPika = objPokes->getPoke("Pikachu");
			objPika->setPC(1000); objPika->setvidaActual(objPika->getSalud_PC());
			CAtaque *at1 = objAtq->getAtaque("Cola de hierro"), *at2 = objAtq->getAtaque("Impactrueno");
			CAtaque *at3 = objAtq->getAtaque("Velocidad extrema"), *at4 = objAtq->getAtaque("Electrobola");
			objPika->aprenderAtaque(at1); objPika->aprenderAtaque(at2);
			objPika->setataquePrincipal(at1); objPika->setataqueDefinitivo(at2);
			objPika->aprenderAtaque(at3); objPika->aprenderAtaque(at4);
			nuevoP->aumentarlistaPokeatrapado(objPika);

			timer1->Enabled = false;
			MapaPrincipal^ juego = gcnew MapaPrincipal(nuevoP);
			juego->ShowDialog(this);
			this->Close();
		}
	}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e)
{
}
private: System::Void listAtaques_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
}

		 int getIndice()
		 {
			 return lbxPoke->SelectedIndex;
		 }
		 char *getnombrePoke()
		 {
			 String ^pokeSelected = lbxPoke->SelectedItem->ToString();
			 char *nombrePokeSelected = new char[30]; sprintf(nombrePokeSelected, "%s", pokeSelected);
			 return nombrePokeSelected;
		 }
private: System::Void LViewPoke_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{

}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	int indPoke = objPokes->getPoke(getnombrePoke())->getIndice();
	
	buff->Graphics->Clear(this->BackColor);
	selectedPokedex->dibujar(buff->Graphics, arrPokeSprites[indPoke]);
	buff->Render(g);
}

private: System::Void lbxPoke_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int indiceSlct = lbxPoke->SelectedIndex;
	int indPokedex = objPokes->getPoke(getnombrePoke())->getIndice();

	if (indiceSlct != -1)
	{
		timer1->Enabled = true;

		selectedPokedex = objPokes->getPoke(getnombrePoke());

		int drawlargo = selectedPokedex->getlargo() / 2;
		int drawalto = selectedPokedex->getalto();

		selectedPokedex->setx(297 - drawlargo);
		selectedPokedex->sety(415 - drawalto);

		String ^strTipo1 = gcnew String(selectedPokedex->gettipo1());
		String ^strTipo2 = gcnew String(selectedPokedex->gettipo2());
		int PkSalud = selectedPokedex->getvidaMaxima();
		double PkAtaque = selectedPokedex->getataque();
		double PkDefensa = selectedPokedex->getdefensa();
		double PkVelocidad = selectedPokedex->getvelocidad();
		double PkPeso = selectedPokedex->getpeso();
		double PkAltura = selectedPokedex->getaltura();
		String ^strPKDescripcion = gcnew String(selectedPokedex->getdescripcion());

		lblIndice->Text = "No. Pokedex: " + indPokedex.ToString();
		if (strTipo2 != "") lblTipo->Text = "Tipo: " + strTipo1 + " / " + strTipo2;
		else lblTipo->Text = "Tipo: " + strTipo1;
		lblSalud->Text = "Salud: " + PkSalud.ToString();
		lblAtaque->Text = "Ataque: " + PkAtaque.ToString();
		lblDefensa->Text = "Defensa: " + PkDefensa.ToString();
		lblVelocidad->Text = "Velocidad: " + PkVelocidad.ToString();
		lblPeso->Text = "Peso: " + PkPeso.ToString() + " kg";
		lblAltura->Text = "Altura: " + PkAltura.ToString() + " m";
		descripcionPoke->Text = "Descripción: \n" + strPKDescripcion;
	}
	else
	{
		timer1->Enabled = false;
	}
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e){
}
};
}
