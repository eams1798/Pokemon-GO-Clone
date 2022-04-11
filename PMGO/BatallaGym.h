#pragma once
#include "Controlador.h"
#include "stdlib.h"

namespace PMGO {
	using namespace System;
	using namespace System::Media;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de BatallaGym
	/// </summary>
	public ref class BatallaGym : public System::Windows::Forms::Form
	{
	private:
		CPersonaje *GymLeader; CArrPokemon *objPokes = new CArrPokemon();
		CControlador *objTodo; CArrAtaque *objatq = new CArrAtaque();
		Graphics ^g; BufferedGraphics ^buff;
		int PKUSRindice;
		Bitmap ^escenario;
		array<Bitmap^>^ arrPokeSprites;
		array<Bitmap^>^ arrPokeBackSprites;
		array<Bitmap^>^ arrMegaSprites;
		array<Bitmap^>^ arrMegaBackSprites;
		array<Bitmap^>^ arrMegaYSprites;
		Rectangle ataqueSQR;
		SoundPlayer ^simpleSound = gcnew SoundPlayer(L"Pokémon GO - BatallaGym.wav");

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rbtnMegaY;
	private: System::Windows::Forms::RadioButton^  rbtnMegaX;
	private: System::Windows::Forms::RadioButton^  rbtnPkNormal;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  rbtnAtqDefin;

	private: System::Windows::Forms::RadioButton^  rbtnAtqPrincipal;

			 void Reproducir_musica_Juego()
			 {
				 SoundPlayer ^simpleSound = gcnew SoundPlayer(L"Pokémon GO - BatallaGym.wav");
				 simpleSound->PlayLooping();
			 }
			 void Detener_musica_Juego()
			 {
				 SoundPlayer ^simpleSound = gcnew SoundPlayer(L"Pokémon GO - BatallaGym.wav");
				 simpleSound->Stop();
			 }

			 array<Bitmap^>^ arrMegaYBackSprites;

	public:
		BatallaGym(CControlador *objeto, int indMyPoke, int numeroGym)
		{
			InitializeComponent();
			CPokemon *PKlider; CAtaque *pklideratqP;  CAtaque *pklideratqdef;
			char *nombreLider = new char[30];

			switch (numeroGym)
			{
			case 1:
				PKlider = objPokes->getPoke("Charizard");
				strcpy(nombreLider, "Líder Valor");
				pklideratqP = objatq->getAtaque("Ala de acero");
				pklideratqdef = objatq->getAtaque("Anillo ígneo");
				PKlider->aprenderAtaque(pklideratqP); PKlider->setataquePrincipal(pklideratqP);
				PKlider->aprenderAtaque(pklideratqdef); PKlider->setataqueDefinitivo(pklideratqdef);
				break;
			case 2:
				PKlider = objPokes->getPoke("Blastoise");
				strcpy(nombreLider, "Líder Místico");
				pklideratqP = objatq->getAtaque("Fuerza");
				pklideratqdef = objatq->getAtaque("Hidrocañón");
				PKlider->aprenderAtaque(pklideratqP); PKlider->setataquePrincipal(pklideratqP);
				PKlider->aprenderAtaque(pklideratqdef); PKlider->setataqueDefinitivo(pklideratqdef);
				break;
			case 3:
				PKlider = objPokes->getPoke("Raichu");
				strcpy(nombreLider, "Líder Instinto");
				pklideratqP = objatq->getAtaque("Cola dragón");
				pklideratqdef = objatq->getAtaque("Tacleada de voltios");
				PKlider->aprenderAtaque(pklideratqP); PKlider->setataquePrincipal(pklideratqP);
				PKlider->aprenderAtaque(pklideratqdef); PKlider->setataqueDefinitivo(pklideratqdef);
				break;
			}
			PKlider->setdeEspalda(0);
			PKlider->setPC(850);
			PKlider->setvidaActual(PKlider->getSalud_PC());
			GymLeader = new CPersonaje(0, 0, 28, 34, 0, 0, 0, 0, 4,
				nombreLider, 0, 0, 1, 0, 9, 0, PKlider);
			objeto->setLider(GymLeader);
			objTodo = objeto;
			PKUSRindice = indMyPoke;
		}
		
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~BatallaGym()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Timer^  timer1;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rbtnMegaY = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnMegaX = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnPkNormal = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->rbtnAtqDefin = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnAtqPrincipal = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &BatallaGym::timer1_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rbtnMegaY);
			this->groupBox1->Controls->Add(this->rbtnMegaX);
			this->groupBox1->Controls->Add(this->rbtnPkNormal);
			this->groupBox1->Location = System::Drawing::Point(0, 666);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(423, 44);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Transformar";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &BatallaGym::groupBox1_Enter);
			// 
			// rbtnMegaY
			// 
			this->rbtnMegaY->AutoSize = true;
			this->rbtnMegaY->Location = System::Drawing::Point(302, 13);
			this->rbtnMegaY->Name = L"rbtnMegaY";
			this->rbtnMegaY->Size = System::Drawing::Size(108, 17);
			this->rbtnMegaY->TabIndex = 2;
			this->rbtnMegaY->Text = L"Megaevolución Y";
			this->rbtnMegaY->UseVisualStyleBackColor = true;
			this->rbtnMegaY->CheckedChanged += gcnew System::EventHandler(this, &BatallaGym::rbtnMegaY_CheckedChanged);
			// 
			// rbtnMegaX
			// 
			this->rbtnMegaX->AutoSize = true;
			this->rbtnMegaX->Location = System::Drawing::Point(128, 16);
			this->rbtnMegaX->Name = L"rbtnMegaX";
			this->rbtnMegaX->Size = System::Drawing::Size(108, 17);
			this->rbtnMegaX->TabIndex = 1;
			this->rbtnMegaX->Text = L"Megaevolución X";
			this->rbtnMegaX->UseVisualStyleBackColor = true;
			this->rbtnMegaX->CheckedChanged += gcnew System::EventHandler(this, &BatallaGym::rbtnMegaX_CheckedChanged);
			// 
			// rbtnPkNormal
			// 
			this->rbtnPkNormal->AutoSize = true;
			this->rbtnPkNormal->Checked = true;
			this->rbtnPkNormal->Location = System::Drawing::Point(3, 16);
			this->rbtnPkNormal->Name = L"rbtnPkNormal";
			this->rbtnPkNormal->Size = System::Drawing::Size(58, 17);
			this->rbtnPkNormal->TabIndex = 0;
			this->rbtnPkNormal->TabStop = true;
			this->rbtnPkNormal->Text = L"Normal";
			this->rbtnPkNormal->UseVisualStyleBackColor = true;
			this->rbtnPkNormal->CheckedChanged += gcnew System::EventHandler(this, &BatallaGym::rbtnPkNormal_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->rbtnAtqDefin);
			this->groupBox2->Controls->Add(this->rbtnAtqPrincipal);
			this->groupBox2->Location = System::Drawing::Point(0, 704);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(423, 44);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Atacar";
			// 
			// rbtnAtqDefin
			// 
			this->rbtnAtqDefin->AutoSize = true;
			this->rbtnAtqDefin->Location = System::Drawing::Point(128, 16);
			this->rbtnAtqDefin->Name = L"rbtnAtqDefin";
			this->rbtnAtqDefin->Size = System::Drawing::Size(69, 17);
			this->rbtnAtqDefin->TabIndex = 1;
			this->rbtnAtqDefin->Text = L"Definitivo";
			this->rbtnAtqDefin->UseVisualStyleBackColor = true;
			// 
			// rbtnAtqPrincipal
			// 
			this->rbtnAtqPrincipal->AutoSize = true;
			this->rbtnAtqPrincipal->Checked = true;
			this->rbtnAtqPrincipal->Location = System::Drawing::Point(3, 16);
			this->rbtnAtqPrincipal->Name = L"rbtnAtqPrincipal";
			this->rbtnAtqPrincipal->Size = System::Drawing::Size(65, 17);
			this->rbtnAtqPrincipal->TabIndex = 0;
			this->rbtnAtqPrincipal->TabStop = true;
			this->rbtnAtqPrincipal->Text = L"Principal";
			this->rbtnAtqPrincipal->UseVisualStyleBackColor = true;
			// 
			// BatallaGym
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 741);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"BatallaGym";
			this->Text = L"BatallaGym";
			this->Load += gcnew System::EventHandler(this, &BatallaGym::BatallaGym_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BatallaGym::BatallaGym_MouseClick);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void BatallaGym_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Reproducir_musica_Juego();
		arrPokeSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrPokeBackSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrMegaSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrMegaBackSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrMegaYSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arrMegaYBackSprites = gcnew array<Bitmap^>(objPokes->getsize());

		for (int i = 0; i < objPokes->getsize(); i++)
		{
			arrPokeSprites[i] = gcnew Bitmap(i.ToString() + ".png");
			arrPokeBackSprites[i] = gcnew Bitmap(i.ToString() + "-back.png");
			if (objPokes->getPoke(i)->gettieneMega() == 1 && objPokes->getPoke(i)->getTieneMega2() == 1)
			{
				arrMegaSprites[i] = gcnew Bitmap(i.ToString() + "-mega.png");
				arrMegaBackSprites[i] = gcnew Bitmap(i.ToString() + "-mega-back.png");
				arrMegaYSprites[i] = gcnew Bitmap(i.ToString() + "-mega2.png");
				arrMegaYBackSprites[i] = gcnew Bitmap(i.ToString() + "-mega2-back.png");
			}
			else if (objPokes->getPoke(i)->gettieneMega() == 1 && objPokes->getPoke(i)->getTieneMega2() == 0)
			{
				arrMegaSprites[i] = gcnew Bitmap(i.ToString() + "-mega.png");
				arrMegaBackSprites[i] = gcnew Bitmap(i.ToString() + "-mega-back.png");
				arrMegaYSprites[i] = gcnew Bitmap("-1.png");
				arrMegaYBackSprites[i] = gcnew Bitmap("-1.png");
			}
			else if (objPokes->getPoke(i)->gettieneMega() == 0 && objPokes->getPoke(i)->getTieneMega2() == 0)
			{
				arrMegaSprites[i] = gcnew Bitmap("-1.png");
				arrMegaBackSprites[i] = gcnew Bitmap("-1.png");
				arrMegaYSprites[i] = gcnew Bitmap("-1.png");
				arrMegaYBackSprites[i] = gcnew Bitmap("-1.png");
			}
		}
		escenario = gcnew Bitmap("BattleGym.png");

		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buff = context->Allocate(g, this->ClientRectangle);
		delete context;

		int usrlargo = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getlargo() / 2;
		int usralto = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getalto();
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setx(140 - usrlargo);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->sety(476 - usralto);
		if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->gettieneMega() == 1)
		{
			rbtnMegaX->Enabled = true;
		}
		else rbtnMegaX->Enabled = false;
		if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getTieneMega2() == 1)
		{
			rbtnMegaY->Enabled = true;
		}
		else rbtnMegaY->Enabled = false;

		int drawlargo = objTodo->getLider()->getMyPoke(0)->getlargo() / 2;
		int drawalto = objTodo->getLider()->getMyPoke(0)->getalto();
		objTodo->getLider()->getMyPoke(0)->setx(280 - usrlargo);
		objTodo->getLider()->getMyPoke(0)->sety(286 - usralto);

		ataqueSQR = Rectangle(objTodo->getLider()->getMyPoke(0)->getx(),
			objTodo->getLider()->getMyPoke(0)->gety(),
			objTodo->getLider()->getMyPoke(0)->getlargo(),
			objTodo->getLider()->getMyPoke(0)->getalto());

	}

			 int indicePoke()
			 {
				 int indMyPoke = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getIndice();
				 return indMyPoke;
			 }
			 int indPokeRival()
			 {
				 int indMyPoke = objTodo->getLider()->getMyPoke(0)->getIndice();
				 return indMyPoke;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		buff->Graphics->Clear(this->BackColor);

		String ^strMypoke = gcnew String(objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmote()),
			^strLeaderPoke = gcnew String(objTodo->getLider()->getMyPoke(0)->getmote());
		int PCMyPoke = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getPC(),
			PCGymPoke = objTodo->getLider()->getMyPoke(0)->getPC();
		int vidamaxMyPoke = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getSalud_PC(),
			vidamaxGymPoke = objTodo->getLider()->getMyPoke(0)->getSalud_PC();
		int vidaactualMyPoke = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getvidaActual(),
			vidaactualGymPoke = objTodo->getLider()->getMyPoke(0)->getvidaActual();
		Rectangle img = Rectangle(0, 0, 436, 700);

		Drawing::Font ^f = gcnew Drawing::Font("Microsoft Sans Serif", 12);
		buff->Graphics->DrawImage(escenario, img, img, GraphicsUnit::Pixel);
		buff->Graphics->DrawString(strMypoke + "\nPC " +
			PCMyPoke.ToString() +
			"\nSalud: " + vidaactualMyPoke.ToString() + " / " + vidamaxMyPoke.ToString(),
			f, Brushes::Black, 9, 22);
		buff->Graphics->DrawString(strLeaderPoke + "\nPC " +
			PCGymPoke.ToString() +
			"\nSalud: " + vidaactualGymPoke.ToString() + " / " + vidamaxGymPoke.ToString(),
			f, Brushes::Black, 230, 22);
		if (rbtnPkNormal->Checked == true)
		{
			objTodo->getUsuario()->getMyPoke(PKUSRindice)->
				dibujarEspalda(buff->Graphics, arrPokeBackSprites[indicePoke()]);
		}
		else if(rbtnMegaX->Checked == true)
		{
			objTodo->getUsuario()->getMyPoke(PKUSRindice)->
				dibujarEspalda(buff->Graphics, arrMegaBackSprites[indicePoke()]);
		}
		else if (rbtnMegaY->Checked == true)
		{
			objTodo->getUsuario()->getMyPoke(PKUSRindice)->
				dibujarEspalda(buff->Graphics, arrMegaYBackSprites[indicePoke()]);
		}
		objTodo->getLider()->getMyPoke(0)->dibujar(buff->Graphics, arrPokeSprites[indPokeRival()]);
		buff->Render(g);

	}

			
private: System::Void rbtnPkNormal_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (rbtnPkNormal->Checked == true)
	{
		if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmegaevoluionado() == true)
		{
			objTodo->getUsuario()->Mega_a_estado_normal(objTodo->getUsuario()->getMyPoke(PKUSRindice));
		}
		int usrlargo = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getlargo() / 2;
		int usralto = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getalto();
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setx(140 - usrlargo);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->sety(476 - usralto);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setmegaevoluionado(false);
	}
}

private: System::Void rbtnMegaX_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (rbtnMegaX->Checked == true)
	{
		if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmegaevoluionado() == true)
		{
			objTodo->getUsuario()->Mega_a_estado_normal(objTodo->getUsuario()->getMyPoke(PKUSRindice));
		}
		objTodo->getUsuario()->Megaevolucionar(objTodo->getUsuario()->getMyPoke(PKUSRindice), 1);
		int usrlargo = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getlargo() / 2;
		int usralto = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getalto();
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setx(140 - usrlargo);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->sety(476 - usralto);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setmegaevoluionado(true);
	}
}
private: System::Void rbtnMegaY_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (rbtnMegaY->Checked == true)
	{
		if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmegaevoluionado() == true)
		{
			objTodo->getUsuario()->Mega_a_estado_normal(objTodo->getUsuario()->getMyPoke(PKUSRindice));
		}
		objTodo->getUsuario()->Megaevolucionar(objTodo->getUsuario()->getMyPoke(PKUSRindice), 2);
		int usrlargo = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getlargo() / 2;
		int usralto = objTodo->getUsuario()->getMyPoke(PKUSRindice)->getalto();
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setx(140 - usrlargo);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->sety(476 - usralto);
		objTodo->getUsuario()->getMyPoke(PKUSRindice)->setmegaevoluionado(true);
	}
}
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void BatallaGym_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	Rectangle Cursorquad = Rectangle(e->X, e->Y, e->X + 16, e->Y + 24);
	String ^strMyPoke = gcnew String(objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmote());
	String ^strGymPoke = gcnew String(objTodo->getLider()->getMyPoke(0)->getmote());
	String ^stratqMyPoke, ^stratqPokeGym, ^strefectivo1, ^strefectivo2;
	String ^strnombreLider = gcnew String(objTodo->getLider()->getnombre());
	if (ataqueSQR.IntersectsWith(Cursorquad))
	{
		if (rbtnAtqPrincipal->Checked == true)
		{
			objTodo->atacar(objTodo->getUsuario()->getMyPoke(PKUSRindice),
				objTodo->getUsuario()->getMyPoke(PKUSRindice)->getataquePrincipal(),
				objTodo->getLider()->getMyPoke(0));
			strefectivo1 = gcnew String(objTodo->getAtqefectivo(
				objTodo->getUsuario()->getMyPoke(PKUSRindice)->getataquePrincipal(),
				objTodo->getLider()->getMyPoke(0))
				);
			objTodo->atacar(objTodo->getLider()->getMyPoke(0),
				objTodo->getLider()->getMyPoke(0)->getataquePrincipal(),
				objTodo->getUsuario()->getMyPoke(PKUSRindice));
			strefectivo2 = gcnew String(objTodo->getAtqefectivo(
				objTodo->getLider()->getMyPoke(0)->getataquePrincipal(),
				objTodo->getUsuario()->getMyPoke(PKUSRindice))
				);
			stratqMyPoke = gcnew String(objTodo->getUsuario()->getMyPoke(PKUSRindice)->
				getataquePrincipal()->getnombre());
			stratqPokeGym = gcnew String(objTodo->getLider()->getMyPoke(0)->
				getataquePrincipal()->getnombre());
			
			
		}
		else if (rbtnAtqDefin->Checked == true)
		{
			objTodo->atacar(objTodo->getUsuario()->getMyPoke(PKUSRindice),
				objTodo->getUsuario()->getMyPoke(PKUSRindice)->getataqueDefinitivo(),
				objTodo->getLider()->getMyPoke(0));
			objTodo->atacar(objTodo->getLider()->getMyPoke(0),
				objTodo->getLider()->getMyPoke(0)->getataqueDefinitivo(),
				objTodo->getUsuario()->getMyPoke(PKUSRindice));
			stratqMyPoke = gcnew String(objTodo->getUsuario()->getMyPoke(PKUSRindice)->
				getataqueDefinitivo()->getnombre());
			stratqPokeGym = gcnew String(objTodo->getLider()->getMyPoke(0)->
				getataqueDefinitivo()->getnombre());
			strefectivo1 = gcnew String(objTodo->getAtqefectivo(
				objTodo->getUsuario()->getMyPoke(PKUSRindice)->getataqueDefinitivo(),
				objTodo->getLider()->getMyPoke(0))
				);
			strefectivo2 = gcnew String(objTodo->getAtqefectivo(
				objTodo->getLider()->getMyPoke(0)->getataqueDefinitivo(),
				objTodo->getUsuario()->getMyPoke(PKUSRindice))
				);
		}
		MessageBox::Show("Tu " + strMyPoke + " usó " + stratqMyPoke
			+ "\n" + strefectivo1
			+ "\n\n" + "El " + strGymPoke + " del " + strnombreLider + " usó " + stratqPokeGym
			+ "\n" + strefectivo2);
		if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getvidaActual() <= 0)
		{
			MessageBox::Show("Tu " + strMyPoke + " está fuera de combate");
			if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmegaevoluionado() == true)
			{
				objTodo->getUsuario()->Mega_a_estado_normal(objTodo->getUsuario()->getMyPoke(PKUSRindice));
				objTodo->getUsuario()->getMyPoke(PKUSRindice)->setmegaevoluionado(false);
			}
			timer1->Enabled = false;
			this->Close();
		}
		if (objTodo->getLider()->getMyPoke(0)->getvidaActual() <= 0)
		{
			MessageBox::Show("El " + strGymPoke + " del " + strnombreLider + " está fuera de combate\n\n" +
							 "Has obtenido 500 monedas\nHas recibido 50 puntos de experiencia");
			objTodo->getUsuario()->setexperiencia(objTodo->getUsuario()->getexperiencia() + 50);
			objTodo->getUsuario()->setmonedas(objTodo->getUsuario()->getmonedas() + 500);
			if (objTodo->getUsuario()->getMyPoke(PKUSRindice)->getmegaevoluionado() == true)
			{ 
				rbtnMegaX->Checked = false; rbtnMegaY->Checked = false;
				rbtnPkNormal->Checked = true;
				objTodo->getUsuario()->Mega_a_estado_normal(objTodo->getUsuario()->getMyPoke(PKUSRindice));
				objTodo->getUsuario()->getMyPoke(PKUSRindice)->setmegaevoluionado(false);

			}
			if (objTodo->getUsuario()->getexperiencia() >= 200)
			{
				MessageBox::Show("Has subido de nivel");
				objTodo->getUsuario()->subirdenivel();
				objTodo->getUsuario()->setexperiencia(0);
			}
			timer1->Enabled = false;
			Detener_musica_Juego();
			this->Close();
		}
		
	}
}
};
}
