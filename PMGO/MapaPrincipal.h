#pragma once
#include "Controlador.h"
#include "ArrPokeballs.h"
#include "BatallaGym.h"
#include "ListaMyPoke.h"
#include "ListaObjetos.h"
#include "AtraparPoke.h"
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
	/// Resumen de MapaPrincipal
	/// </summary>
	public ref class MapaPrincipal : public System::Windows::Forms::Form
	{
		
		Graphics ^g; CPersonaje *usuario; Bitmap ^bmpMapa, ^spriteUsr, ^Pokeballs;
		CArrPokeballs *objPokeballs; CArrPokemon *objAtraparPokes;
		CControlador *objTodo; CArrAtaque *objAtq;
		BufferedGraphics ^buff;
		Keys tecla;
		array<array<Rectangle>^>^ arrQuadEstados;
		CArrObjeto *arrMyObjetos;

		Rectangle PStop1, PStop2, PStop3, PStop4;
		Rectangle Gym1, Gym2, Gym3;
		Rectangle listPoke = Rectangle(0, 656, 108, 23),
			listObjetos = Rectangle(0, 685, 108, 23),
			btnCerrar = Rectangle(1092, 0, 108, 23);
		SoundPlayer ^simpleSound = gcnew SoundPlayer(L"Pokémon GO - MapaPrincipal.wav");

	private: System::Windows::Forms::Timer^  timer1;
	public:
		MapaPrincipal(CPersonaje *jugador)
		{
			InitializeComponent();
			usuario = jugador;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MapaPrincipal()
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MapaPrincipal::timer1_Tick);
			// 
			// MapaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 720);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MapaPrincipal";
			this->Text = L"timer1";
			this->Load += gcnew System::EventHandler(this, &MapaPrincipal::MapaPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MapaPrincipal::MapaPrincipal_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MapaPrincipal::MapaPrincipal_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MapaPrincipal::MapaPrincipal_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion

		void Reproducir_musica_Juego()
		{
			simpleSound->PlayLooping();
		}
		void Detener_musica_Juego()
		{
			simpleSound->Stop();
		}
	private: System::Void MapaPrincipal_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Reproducir_musica_Juego();
		objTodo = new CControlador(usuario,usuario);
		objAtraparPokes = new CArrPokemon();
		arrMyObjetos = new CArrObjeto();
		objAtq = new CArrAtaque();

		arrQuadEstados = gcnew array<array<Rectangle>^>(45);
		for (int i = 0; i < 45; i++)
		{
			arrQuadEstados[i] = gcnew array<Rectangle>(75);
			for (int j = 0; j < 75; j++)
			{
				arrQuadEstados[i][j] = Rectangle(j * 16, i * 16, 16, 16);
			}
		}

		if (usuario->getsexo() == 0) spriteUsr = gcnew Bitmap("Ash_kantosprite--28_34px.png");
		else if (usuario->getsexo() == 1) spriteUsr = gcnew Bitmap("SerenaSprite--28_34px.png");
		bmpMapa = gcnew Bitmap("TileGO.png");
		Pokeballs = gcnew Bitmap("PokeballCelda.png");

		g = this->CreateGraphics();
		BufferedGraphicsContext ^bgc = BufferedGraphicsManager::Current;
		buff = bgc->Allocate(g, this->ClientRectangle);
		delete bgc;

		objPokeballs = new CArrPokeballs();
		Gym1 = Rectangle(416, 16, 96, 160);
		Gym2 = Rectangle(560, 80, 96, 160);
		Gym3 = Rectangle(704, 16, 96, 160);
		PStop1 = Rectangle(160, 48, 48, 112);
		PStop2 = Rectangle(288,112, 48, 112);
		PStop3 = Rectangle(864, 128, 48, 112);
		PStop4 = Rectangle(1024, 48, 48, 112);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		buff->Graphics->Clear(this->BackColor);

		Drawing::Font ^f = gcnew Drawing::Font("Microsoft Sans Serif", 8.25);
		buff->Graphics->DrawImageUnscaled(bmpMapa, 0,0);
		buff->Graphics->FillRectangle(Brushes::WhiteSmoke, listPoke);
		buff->Graphics->DrawString("Lista de Pokémon", f, Brushes::Black, 10, 660);
		buff->Graphics->FillRectangle(Brushes::WhiteSmoke, listObjetos);
		buff->Graphics->DrawString("Lista de objetos", f, Brushes::Black, 12, 690);
		buff->Graphics->FillRectangle(Brushes::WhiteSmoke, btnCerrar);
		buff->Graphics->DrawString("Cerrar", f, Brushes::Black, 1130, 6);
		buff->Graphics->DrawString("Nivel: " + usuario->getnivel().ToString(), f, Brushes::White, 300, 6);
		buff->Graphics->DrawString("Experiencia: " + usuario->getexperiencia().ToString(), f, Brushes::White, 400, 6);
		buff->Graphics->DrawString("Monedas: " + usuario->getmonedas().ToString(), f, Brushes::White, 500, 6);
		objPokeballs->dibujartodo(buff->Graphics, Pokeballs);
		objTodo->permitirmovimiento(usuario,tecla);
		usuario->dibujar(buff->Graphics, spriteUsr);
		usuario->mover(tecla);

		buff->Render(g);
		tecla = Keys::None;
	}

	private: System::Void MapaPrincipal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		tecla = e->KeyCode;
	}
	private: System::Void MapaPrincipal_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		int xPtr = e->X / 16, yPtr = e->Y / 16;
		int largoC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getLargo(),
			altoC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getAlto(),
			xC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getX(),
			yC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getY(),
			std = objTodo->getTablero()->getCelda(xPtr, yPtr)->getEstado();

		if (std == 2 || std == 3 || std == 4)
		{
			this->Cursor = Cursors::Hand;
		}
		else this->Cursor = Cursors::Default;
	}
private: System::Void MapaPrincipal_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	Random ^r = gcnew Random(DateTime::Now.Ticks);
	CObjeto *obj;
	int xPtr = e->X / 16, yPtr = e->Y / 16;
	int largoC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getLargo(),
		altoC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getAlto(),
		xC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getX(),
		yC = objTodo->getTablero()->getCelda(xPtr, yPtr)->getY(),
		std = objTodo->getTablero()->getCelda(xPtr, yPtr)->getEstado();
	Rectangle cursorquad = Rectangle(xC, yC, largoC, altoC);
	if (std == 2)
	{
		if (objPokeballs->colisiona(e->X, e->Y) == true)
		{
			if (objPokeballs->returnedpos(cursorquad)->hayColision(e->X, e->Y) == true)
			{
				Detener_musica_Juego();
				timer1->Enabled = false;
				AtraparPoke ^captura = gcnew AtraparPoke(usuario, objPokeballs->returnedpos(cursorquad)->getPoke());
				captura->ShowDialog(this);
				timer1->Enabled = true;
				objPokeballs->eliminarPoke(objPokeballs->returnedposint(objPokeballs->returnedpos(cursorquad)));
				Reproducir_musica_Juego();
			}
		}
		else
		{
			CPokemon *nuevo = objAtraparPokes->getPoke(r->Next(0, objAtraparPokes->getsize()));

			CAtaque *princ = objAtq->getAtaque(r->Next(0, 180));
			int listaatq[10], indatq = 0;
			for (int i = 0; i < objAtq->getsize(); i++)
			{
				if (strcmp(nuevo->gettipo1(), objAtq->getAtaque(i)->gettipo()) == 0)
				{
					listaatq[indatq] = i;
					indatq++;
				}
			}
			CAtaque *def = objAtq->getAtaque(r->Next(listaatq[0], listaatq[9]));
			nuevo->setPC(r->Next(10, 5000)); nuevo->setvidaActual(nuevo->getSalud_PC());
			nuevo->aprenderAtaque(princ); nuevo->aprenderAtaque(def);
			nuevo->setataquePrincipal(princ); nuevo->setataqueDefinitivo(def);
			CPokeballCelda *balls = new CPokeballCelda(xC, yC, largoC, altoC, 2, nuevo);
			objPokeballs->agregar(balls);
		}
		

	}
	if (std == 3)
	{
		String ^strgetObjeto = "Has obtenido:\n";
		String ^stradicional;
		int length = r->Next(3, 25);
		if (PStop1.IntersectsWith(cursorquad))
		{
			for (int i = 0; i < length; i++)
			{
				obj = arrMyObjetos->getObj(r->Next(0, 4));
				usuario->aumentarlistaObj(obj);
				stradicional = gcnew String(obj->getnombre());
				strgetObjeto += stradicional + "\n";
			}
			MessageBox::Show(strgetObjeto);
		}
		if (PStop2.IntersectsWith(cursorquad))
		{
			for (int i = 0; i < length; i++)
			{
				obj = arrMyObjetos->getObj(r->Next(0, 4));
				usuario->aumentarlistaObj(obj);
				stradicional = gcnew String(obj->getnombre());
				strgetObjeto += stradicional + "\n";
			}
			MessageBox::Show(strgetObjeto);
		}
		if (PStop3.IntersectsWith(cursorquad))
		{
			for (int i = 0; i < length; i++)
			{
				obj = arrMyObjetos->getObj(r->Next(0, 4));
				usuario->aumentarlistaObj(obj);
				stradicional = gcnew String(obj->getnombre());
				strgetObjeto += stradicional + "\n";
			}
			MessageBox::Show(strgetObjeto);
		}
		if (PStop4.IntersectsWith(cursorquad))
		{
			for (int i = 0; i < length; i++)
			{
				obj = arrMyObjetos->getObj(r->Next(0, 4));
				usuario->aumentarlistaObj(obj);
				stradicional = gcnew String(obj->getnombre());
				strgetObjeto += stradicional + "\n";
			}
			MessageBox::Show(strgetObjeto);
		}
		usuario->setexperiencia(usuario->getexperiencia() + length);
		if (usuario->getexperiencia() >= 200)
		{
			usuario->subirdenivel();
			usuario->setexperiencia(0);
		}
	}
	if (std == 4)
	{
		int gymEstado; int indMyPoke;
		for (int i = 0; i < usuario->getlistaMisPokes().size(); i++)
		{
			if (usuario->getMyPoke(i)->getdeEspalda() == 1)
			{
				indMyPoke = i;
			}
		}
		if (Gym1.IntersectsWith(cursorquad))
		{
			gymEstado = 1;
		}
		if (Gym2.IntersectsWith(cursorquad))
		{
			gymEstado = 2;
		}
		if (Gym3.IntersectsWith(cursorquad))
		{
			gymEstado = 3;
		}
		Detener_musica_Juego();
		timer1->Enabled = false;
		BatallaGym ^battle = gcnew BatallaGym(objTodo, indMyPoke, gymEstado);
		battle->ShowDialog(this);
		timer1->Enabled = true;
		Reproducir_musica_Juego();
	}
	if (listPoke.IntersectsWith(cursorquad))
	{
		timer1->Enabled = false;
		ListaMyPoke ^pkview = gcnew ListaMyPoke(usuario);
		pkview->ShowDialog(this);
		timer1->Enabled = true;
	}
	if (listObjetos.IntersectsWith(cursorquad))
	{
		timer1->Enabled = false;
		ListaObjetos ^objview = gcnew ListaObjetos(usuario,0);
		objview->ShowDialog(this);
		timer1->Enabled = true;
	}
	if (btnCerrar.IntersectsWith(cursorquad))
	{
		timer1->Enabled = false;
		Detener_musica_Juego();
		this->Close();
	}
}
};
}
