#pragma once
#include "Controlador.h"
#include "BolaAtrapar.h"
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
	/// Resumen de AtraparPoke
	/// </summary>
	public ref class AtraparPoke : public System::Windows::Forms::Form
	{
	private:
		CPersonaje *user; CPokemon *salvaje;
		CArrPokemon *objPokes;
		Bitmap ^scenario; array<Bitmap^>^ arrPokeSprites;
		Bitmap ^Pokeball;
		Graphics ^g; BufferedGraphics ^buff;
		Rectangle btncerrar;
		array<Bitmap^>^ arratrapball;
		SoundPlayer ^simpleSound = gcnew SoundPlayer(L"Pokémon GO - AtraparPoke.wav");
		CBolaAtrapar *obj;
		int numPKBalls = 0, numUBalls = 0;

		bool holded;
		bool clicked;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rbtnPokeball;
	private: System::Windows::Forms::RadioButton^  rbtnUltraball;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;


			 void Reproducir_musica_Juego()
			 {
				 simpleSound->PlayLooping();
			 }
			 void Detener_musica_Juego()
			 {
				 simpleSound->Stop();
			 }



	private: System::Windows::Forms::Timer^  timer1;
	public:
		AtraparPoke(CPersonaje *elegido, CPokemon *pokes)
		{
			InitializeComponent();
			user = elegido; salvaje = pokes;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~AtraparPoke()
		{
			if (components)
			{
				delete components;
			}
		}
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AtraparPoke::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->rbtnUltraball = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnPokeball = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &AtraparPoke::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 663);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(19, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AtraparPoke::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBox3);
			this->groupBox1->Controls->Add(this->pictureBox2);
			this->groupBox1->Controls->Add(this->rbtnUltraball);
			this->groupBox1->Controls->Add(this->rbtnPokeball);
			this->groupBox1->Location = System::Drawing::Point(405, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(61, 183);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Elige";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &AtraparPoke::groupBox1_Enter);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(0, 127);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(61, 55);
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 43);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(61, 55);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// rbtnUltraball
			// 
			this->rbtnUltraball->AutoSize = true;
			this->rbtnUltraball->Location = System::Drawing::Point(6, 104);
			this->rbtnUltraball->Name = L"rbtnUltraball";
			this->rbtnUltraball->Size = System::Drawing::Size(43, 17);
			this->rbtnUltraball->TabIndex = 0;
			this->rbtnUltraball->Text = L"350";
			this->rbtnUltraball->UseVisualStyleBackColor = true;
			this->rbtnUltraball->CheckedChanged += gcnew System::EventHandler(this, &AtraparPoke::radioButton1_CheckedChanged);
			// 
			// rbtnPokeball
			// 
			this->rbtnPokeball->AutoSize = true;
			this->rbtnPokeball->Checked = true;
			this->rbtnPokeball->Location = System::Drawing::Point(10, 20);
			this->rbtnPokeball->Name = L"rbtnPokeball";
			this->rbtnPokeball->Size = System::Drawing::Size(43, 17);
			this->rbtnPokeball->TabIndex = 0;
			this->rbtnPokeball->TabStop = true;
			this->rbtnPokeball->Text = L"100";
			this->rbtnPokeball->UseVisualStyleBackColor = true;
			this->rbtnPokeball->CheckedChanged += gcnew System::EventHandler(this, &AtraparPoke::radioButton1_CheckedChanged);
			// 
			// AtraparPoke
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 720);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AtraparPoke";
			this->Text = L"AtraparPoke";
			this->Load += gcnew System::EventHandler(this, &AtraparPoke::AtraparPoke_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AtraparPoke::AtraparPoke_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &AtraparPoke::AtraparPoke_MouseMove);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		int indicePKBLL()
		{
			int i;
			if (rbtnPokeball->Checked == true && rbtnUltraball->Checked == false)
				i = 0;
			if (rbtnPokeball->Checked == false && rbtnUltraball->Checked == true)
				i = 1;
			return i;
		}
	private: System::Void AtraparPoke_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Reproducir_musica_Juego();
		obj = new CBolaAtrapar(177, 635, 52, 52, 0, 0, 0, 0, 12);
		holded = false;
		clicked = false;
		
		salvaje->setx(202 - (salvaje->getlargo() / 2)); salvaje->sety(360 - (salvaje->getalto()));
		scenario = gcnew Bitmap("AtraparPoke.png");
		Pokeball = gcnew Bitmap("PokeballAnim1.png");
		objPokes = new CArrPokemon();
				 
		arrPokeSprites = gcnew array<Bitmap^>(objPokes->getsize());
		arratrapball = gcnew array<Bitmap^>(2);
		arratrapball[0] = gcnew Bitmap("PokeballAnim1.png");
		arratrapball[1] = gcnew Bitmap("PokeballAnim2.png");
		for (int i = 0; i < objPokes->getsize(); i++)
		{
		 arrPokeSprites[i] = gcnew Bitmap(i.ToString() + ".png");
		}

		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buff = context->Allocate(g, this->ClientRectangle);
		delete context;
		btncerrar = Rectangle(29, 23, 54, 54);

		for (int i = 0; i < user->getlistaMisObjs().size(); i++)
		{
			if (strcmp(user->getlistaMisObjs()[i]->getnombre(), "Pokeball") == 0)
			{
				numPKBalls++;
			}
			if (strcmp(user->getlistaMisObjs()[i]->getnombre(), "Ultraball") == 0)
			{
				numUBalls++;
			}
		}
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
	
		buff->Graphics->Clear(this->BackColor);
				 String ^pokename = gcnew String(salvaje->getnombre());
				 Rectangle
					 ints = Rectangle(0, 0, 405, 720),
					 exts = Rectangle(0, 0, 1080, 1920),
					 pokecelda = Rectangle(salvaje->getx(), salvaje->gety(),
						salvaje->getlargo(), salvaje->getalto()),
					 recball = Rectangle(obj->getx(), obj->gety(), obj->getlargo(), obj->getalto());
				 buff->Graphics->DrawImage(scenario, ints, exts, GraphicsUnit::Pixel);
				 salvaje->dibujar(buff->Graphics,arrPokeSprites[idx()]);
				 rbtnPokeball->Text = numPKBalls.ToString();
				 rbtnUltraball->Text = numUBalls.ToString();

				 int maxy = 570;

				 Drawing::Font ^f = gcnew Drawing::Font("Microsoft Sans Serif", 12);
				 buff->Graphics->DrawString(pokename, f, Brushes::White, 180, 130);
				 buff->Graphics->DrawString("PC " + salvaje->getPC().ToString(), f, Brushes::White, 190, 150);

				 if (recball.IntersectsWith(pokecelda))
				 {
					 timer1->Enabled = false;
					 user->aumentarlistaPokeatrapado(salvaje);
					 MessageBox::Show("Has capturado un " + pokename);
					 user->setexperiencia(user->getexperiencia() + 30);
					 if (user->getexperiencia() >= 200)
					 {
						 user->subirdenivel();
					 }
					 this->Close();
				 }
				 if (obj->gety() < maxy) obj->setMover(true);
				 if (obj->getMover())
				 {
					 clicked = false;
					 obj->girar(buff->Graphics, arratrapball[indicePKBLL()], this->ClientRectangle.Height / 2);
				 }
				 else
				 {
					 obj->dibujarEstatico(buff->Graphics, arratrapball[indicePKBLL()]);
				 }

				 buff->Render(g);
	}
			 int idx()
			 {
				 return salvaje->getIndice();
			 }
	private: System::Void AtraparPoke_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
				 Rectangle ptrRec = Rectangle(e->X, e->Y, 4, 4);
				 if (ptrRec.IntersectsWith(btncerrar))
				 {
					 timer1->Enabled = false;
					 Close();
				 }

				 if (obj->colision(e->X, e->Y))
				 { 
					 clicked = true;
					 if (indicePKBLL() == 0) numPKBalls--;
					 else if (indicePKBLL() == 1) numUBalls--;
				 }
	}
	private: System::Void AtraparPoke_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (clicked)
		{
			obj->setx(e->X - obj->getlargo() / 2);
			obj->sety(e->Y - obj->getalto() / 2);
			if (obj->getx() <= 240) { obj->setAngulo(PI); obj->setGiro(true); }
			else { obj->setAngulo(0); obj->setGiro(false); }
		}
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	obj->setx(177); obj->sety(635); obj->setlargo(52); obj->setalto(52);
	holded = false; obj->setMover(false);
	clicked = false;
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
