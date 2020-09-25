#pragma once
#include "Juego.h"


namespace Quarantine_Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	//Compone el formulario.
	public ref class Frm_principal : public System::Windows::Forms::Form
	{
	public:
		Frm_principal(void)
		{
			InitializeComponent();
			//Cambiamos a la pantalla del Menu para iniciar el Juego
			cambiarpantalla("Menu"); 
			//Inicializamos nuestro canvas que servira papra nuestros sprites
			canvas = this->CreateGraphics();
			nivel = 1;
			//Inicializamos la clase Juego
			
			//Inicializamos los sprites para usar en el juego a traves del formulario principal
			cancion = gcnew SoundPlayer("Solve The Puzzle.wav");
			fondopantalla = gcnew Bitmap("fondo2.png");
			spritejugador = gcnew Bitmap("Jugadorx256.png");
			spriteadversario = gcnew Bitmap("Adversario1.png");
			spriteadversario2 = gcnew Bitmap("Adversario2.png");
			ladron = gcnew Bitmap("ladron.png");
			spritemensaje = gcnew Bitmap("mensaje.png");
			spritepolicia = gcnew Bitmap("Policiax256.png");
			spriteambulancia = gcnew Bitmap("Ambulancia.png");
			spritemensajevirus = gcnew Bitmap("virus.png");
		}
	protected:
		~Frm_principal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Panel^  pnl_Menu;
		//Creamos nuestro canvas
		Graphics^ canvas;
		//Creamos nuestros Bitmaps que seran nuestros sprites
		Bitmap^ spritejugador;
		Bitmap^ spriteadversario;
		Bitmap^ spriteadversario2;
		Bitmap^ladron;
		Bitmap^ spritepolicia;
		Bitmap^ spriteambulancia;
		Bitmap^ fondopantalla;
		Bitmap^ fondoinstrucciones1;
		Bitmap^ fondoinstrucciones2;
		Bitmap^ spritemensaje;
		Bitmap^ spritemensajevirus;
		SoundPlayer^ cancion;
		//Creamos nuestro objeto juefo
		Juego* juego;
		int nivel;

	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  Pausa;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  RegrsarMenu;
	private: System::Windows::Forms::Timer^  draw;

	private: System::Windows::Forms::Label^  Vidas;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  move;
	public: System::Windows::Forms::Label^  lblpuntaje;
	private:


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  pnl_instrucciones1;
	private: System::Windows::Forms::Panel^  pnl_instrucciones2;
	private: System::Windows::Forms::Button^  btn_ins_next;
	private: System::Windows::Forms::Button^  btn_ins_back;
	private: System::Windows::Forms::Button^  btn_ins2_back;
	private: System::Windows::Forms::Button^  btn_ins_play;
	private: System::Windows::Forms::Label^  lbl_tiempo;
	private: System::Windows::Forms::Label^  lbl_jvidas;
	private: System::Windows::Forms::RadioButton^  rdbtn_Easy;
	private: System::Windows::Forms::RadioButton^  rdbtn_Hard;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  lbl_tiempodejuego;
	private: System::Windows::Forms::Label^  lbl_tjuego;
	private: System::Windows::Forms::Label^  lbl_perdiste;
	private: System::Windows::Forms::Label^  lbl_nivelmas;
	private: System::Windows::Forms::Label^  lbl_ganaste;
	private: System::Windows::Forms::Label^  lbl_menosvida;











	private: System::ComponentModel::IContainer^  components;

	protected:
	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Frm_principal::typeid));
			this->pnl_Menu = (gcnew System::Windows::Forms::Panel());
			this->lbl_tiempo = (gcnew System::Windows::Forms::Label());
			this->lbl_jvidas = (gcnew System::Windows::Forms::Label());
			this->rdbtn_Easy = (gcnew System::Windows::Forms::RadioButton());
			this->rdbtn_Hard = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->RegrsarMenu = (gcnew System::Windows::Forms::Button());
			this->Pausa = (gcnew System::Windows::Forms::Button());
			this->draw = (gcnew System::Windows::Forms::Timer(this->components));
			this->Vidas = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->move = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblpuntaje = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pnl_instrucciones1 = (gcnew System::Windows::Forms::Panel());
			this->btn_ins_next = (gcnew System::Windows::Forms::Button());
			this->btn_ins_back = (gcnew System::Windows::Forms::Button());
			this->pnl_instrucciones2 = (gcnew System::Windows::Forms::Panel());
			this->btn_ins2_back = (gcnew System::Windows::Forms::Button());
			this->btn_ins_play = (gcnew System::Windows::Forms::Button());
			this->lbl_tiempodejuego = (gcnew System::Windows::Forms::Label());
			this->lbl_tjuego = (gcnew System::Windows::Forms::Label());
			this->lbl_perdiste = (gcnew System::Windows::Forms::Label());
			this->lbl_nivelmas = (gcnew System::Windows::Forms::Label());
			this->lbl_ganaste = (gcnew System::Windows::Forms::Label());
			this->lbl_menosvida = (gcnew System::Windows::Forms::Label());
			this->pnl_Menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panel2->SuspendLayout();
			this->pnl_instrucciones1->SuspendLayout();
			this->pnl_instrucciones2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnl_Menu
			// 
			this->pnl_Menu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_Menu.BackgroundImage")));
			this->pnl_Menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_Menu->Controls->Add(this->lbl_tiempo);
			this->pnl_Menu->Controls->Add(this->lbl_jvidas);
			this->pnl_Menu->Controls->Add(this->rdbtn_Easy);
			this->pnl_Menu->Controls->Add(this->rdbtn_Hard);
			this->pnl_Menu->Controls->Add(this->numericUpDown2);
			this->pnl_Menu->Controls->Add(this->numericUpDown1);
			this->pnl_Menu->Controls->Add(this->button3);
			this->pnl_Menu->Controls->Add(this->button1);
			this->pnl_Menu->Controls->Add(this->button2);
			this->pnl_Menu->Location = System::Drawing::Point(66, 110);
			this->pnl_Menu->Name = L"pnl_Menu";
			this->pnl_Menu->Size = System::Drawing::Size(136, 111);
			this->pnl_Menu->TabIndex = 5;
			this->pnl_Menu->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Frm_principal::panel1_Paint);
			// 
			// lbl_tiempo
			// 
			this->lbl_tiempo->AutoSize = true;
			this->lbl_tiempo->BackColor = System::Drawing::Color::Transparent;
			this->lbl_tiempo->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tiempo->ForeColor = System::Drawing::Color::White;
			this->lbl_tiempo->Location = System::Drawing::Point(446, 288);
			this->lbl_tiempo->Name = L"lbl_tiempo";
			this->lbl_tiempo->Size = System::Drawing::Size(86, 15);
			this->lbl_tiempo->TabIndex = 16;
			this->lbl_tiempo->Text = L"Tiempo (Minutos)";
			// 
			// lbl_jvidas
			// 
			this->lbl_jvidas->AutoSize = true;
			this->lbl_jvidas->BackColor = System::Drawing::Color::Transparent;
			this->lbl_jvidas->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_jvidas->ForeColor = System::Drawing::Color::White;
			this->lbl_jvidas->Location = System::Drawing::Point(364, 288);
			this->lbl_jvidas->Name = L"lbl_jvidas";
			this->lbl_jvidas->Size = System::Drawing::Size(33, 15);
			this->lbl_jvidas->TabIndex = 15;
			this->lbl_jvidas->Text = L"Vidas";
			// 
			// rdbtn_Easy
			// 
			this->rdbtn_Easy->AutoSize = true;
			this->rdbtn_Easy->BackColor = System::Drawing::Color::Transparent;
			this->rdbtn_Easy->Checked = true;
			this->rdbtn_Easy->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdbtn_Easy->ForeColor = System::Drawing::Color::White;
			this->rdbtn_Easy->Location = System::Drawing::Point(353, 347);
			this->rdbtn_Easy->Name = L"rdbtn_Easy";
			this->rdbtn_Easy->Size = System::Drawing::Size(82, 19);
			this->rdbtn_Easy->TabIndex = 11;
			this->rdbtn_Easy->TabStop = true;
			this->rdbtn_Easy->Text = L"Principiante";
			this->rdbtn_Easy->UseVisualStyleBackColor = false;
			// 
			// rdbtn_Hard
			// 
			this->rdbtn_Hard->AutoSize = true;
			this->rdbtn_Hard->BackColor = System::Drawing::Color::Transparent;
			this->rdbtn_Hard->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdbtn_Hard->ForeColor = System::Drawing::Color::White;
			this->rdbtn_Hard->Location = System::Drawing::Point(449, 347);
			this->rdbtn_Hard->Name = L"rdbtn_Hard";
			this->rdbtn_Hard->Size = System::Drawing::Size(71, 19);
			this->rdbtn_Hard->TabIndex = 10;
			this->rdbtn_Hard->Text = L"Avanzado";
			this->rdbtn_Hard->UseVisualStyleBackColor = false;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->BackColor = System::Drawing::Color::GreenYellow;
			this->numericUpDown2->Location = System::Drawing::Point(461, 313);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(61, 20);
			this->numericUpDown2->TabIndex = 9;
			this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::GreenYellow;
			this->numericUpDown1->Location = System::Drawing::Point(353, 313);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(61, 20);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::GreenYellow;
			this->button3->Font = (gcnew System::Drawing::Font(L"Impact", 15.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button3->Location = System::Drawing::Point(353, 532);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(169, 54);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Salir";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Frm_principal::button3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::GreenYellow;
			this->button1->Font = (gcnew System::Drawing::Font(L"Impact", 15.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(353, 370);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 54);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Jugar!";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Frm_principal::button1_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::GreenYellow;
			this->button2->Font = (gcnew System::Drawing::Font(L"Impact", 15.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button2->Location = System::Drawing::Point(353, 450);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 54);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Instrucciones";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Frm_principal::button2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Indigo;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->RegrsarMenu);
			this->panel2->Location = System::Drawing::Point(622, 30);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 108);
			this->panel2->TabIndex = 8;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Frm_principal::panel2_Paint);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::GreenYellow;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(23, 62);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Instrucciones de Juego";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Frm_principal::button5_Click);
			// 
			// RegrsarMenu
			// 
			this->RegrsarMenu->BackColor = System::Drawing::Color::GreenYellow;
			this->RegrsarMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->RegrsarMenu->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegrsarMenu->ForeColor = System::Drawing::Color::Black;
			this->RegrsarMenu->Location = System::Drawing::Point(34, 13);
			this->RegrsarMenu->Name = L"RegrsarMenu";
			this->RegrsarMenu->Size = System::Drawing::Size(125, 23);
			this->RegrsarMenu->TabIndex = 0;
			this->RegrsarMenu->Text = L"Regresar al Menu";
			this->RegrsarMenu->UseVisualStyleBackColor = false;
			this->RegrsarMenu->Click += gcnew System::EventHandler(this, &Frm_principal::button4_Click_1);
			// 
			// Pausa
			// 
			this->Pausa->BackColor = System::Drawing::Color::Indigo;
			this->Pausa->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Pausa->Font = (gcnew System::Drawing::Font(L"Impact", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pausa->ForeColor = System::Drawing::Color::White;
			this->Pausa->Location = System::Drawing::Point(683, 12);
			this->Pausa->Name = L"Pausa";
			this->Pausa->Size = System::Drawing::Size(75, 23);
			this->Pausa->TabIndex = 0;
			this->Pausa->Text = L"Pausa";
			this->Pausa->UseVisualStyleBackColor = false;
			this->Pausa->Click += gcnew System::EventHandler(this, &Frm_principal::button4_Click);
			// 
			// draw
			// 
			this->draw->Tick += gcnew System::EventHandler(this, &Frm_principal::timer1_Tick);
			// 
			// Vidas
			// 
			this->Vidas->AutoSize = true;
			this->Vidas->BackColor = System::Drawing::Color::GreenYellow;
			this->Vidas->Font = (gcnew System::Drawing::Font(L"Impact", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Vidas->Location = System::Drawing::Point(29, 22);
			this->Vidas->Name = L"Vidas";
			this->Vidas->Size = System::Drawing::Size(35, 16);
			this->Vidas->TabIndex = 9;
			this->Vidas->Text = L"Vidas";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::GreenYellow;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"3";
			// 
			// move
			// 
			this->move->Tick += gcnew System::EventHandler(this, &Frm_principal::move_Tick);
			// 
			// lblpuntaje
			// 
			this->lblpuntaje->AutoSize = true;
			this->lblpuntaje->BackColor = System::Drawing::Color::GreenYellow;
			this->lblpuntaje->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblpuntaje->Location = System::Drawing::Point(183, 22);
			this->lblpuntaje->Name = L"lblpuntaje";
			this->lblpuntaje->Size = System::Drawing::Size(15, 17);
			this->lblpuntaje->TabIndex = 12;
			this->lblpuntaje->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::GreenYellow;
			this->label3->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(133, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Puntaje";
			// 
			// pnl_instrucciones1
			// 
			this->pnl_instrucciones1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_instrucciones1.BackgroundImage")));
			this->pnl_instrucciones1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_instrucciones1->Controls->Add(this->btn_ins_next);
			this->pnl_instrucciones1->Controls->Add(this->btn_ins_back);
			this->pnl_instrucciones1->Location = System::Drawing::Point(48, 271);
			this->pnl_instrucciones1->Name = L"pnl_instrucciones1";
			this->pnl_instrucciones1->Size = System::Drawing::Size(111, 90);
			this->pnl_instrucciones1->TabIndex = 13;
			// 
			// btn_ins_next
			// 
			this->btn_ins_next->BackColor = System::Drawing::Color::GreenYellow;
			this->btn_ins_next->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_ins_next->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ins_next->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_ins_next->Location = System::Drawing::Point(700, 44);
			this->btn_ins_next->Name = L"btn_ins_next";
			this->btn_ins_next->Size = System::Drawing::Size(122, 44);
			this->btn_ins_next->TabIndex = 3;
			this->btn_ins_next->Text = L"Siguiente";
			this->btn_ins_next->UseVisualStyleBackColor = false;
			this->btn_ins_next->Click += gcnew System::EventHandler(this, &Frm_principal::btn_ins_next_Click);
			// 
			// btn_ins_back
			// 
			this->btn_ins_back->BackColor = System::Drawing::Color::GreenYellow;
			this->btn_ins_back->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_ins_back->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ins_back->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_ins_back->Location = System::Drawing::Point(32, 44);
			this->btn_ins_back->Name = L"btn_ins_back";
			this->btn_ins_back->Size = System::Drawing::Size(122, 44);
			this->btn_ins_back->TabIndex = 2;
			this->btn_ins_back->Text = L"Regresar";
			this->btn_ins_back->UseVisualStyleBackColor = false;
			this->btn_ins_back->Click += gcnew System::EventHandler(this, &Frm_principal::btn_ins_back_Click);
			// 
			// pnl_instrucciones2
			// 
			this->pnl_instrucciones2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_instrucciones2.BackgroundImage")));
			this->pnl_instrucciones2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_instrucciones2->Controls->Add(this->btn_ins2_back);
			this->pnl_instrucciones2->Controls->Add(this->btn_ins_play);
			this->pnl_instrucciones2->Location = System::Drawing::Point(49, 396);
			this->pnl_instrucciones2->Name = L"pnl_instrucciones2";
			this->pnl_instrucciones2->Size = System::Drawing::Size(124, 92);
			this->pnl_instrucciones2->TabIndex = 14;
			// 
			// btn_ins2_back
			// 
			this->btn_ins2_back->BackColor = System::Drawing::Color::GreenYellow;
			this->btn_ins2_back->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_ins2_back->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ins2_back->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_ins2_back->Location = System::Drawing::Point(32, 44);
			this->btn_ins2_back->Name = L"btn_ins2_back";
			this->btn_ins2_back->Size = System::Drawing::Size(122, 44);
			this->btn_ins2_back->TabIndex = 3;
			this->btn_ins2_back->Text = L"Regresar";
			this->btn_ins2_back->UseVisualStyleBackColor = false;
			this->btn_ins2_back->Click += gcnew System::EventHandler(this, &Frm_principal::btn_ins2_back_Click);
			// 
			// btn_ins_play
			// 
			this->btn_ins_play->BackColor = System::Drawing::Color::GreenYellow;
			this->btn_ins_play->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_ins_play->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ins_play->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_ins_play->Location = System::Drawing::Point(355, 564);
			this->btn_ins_play->Name = L"btn_ins_play";
			this->btn_ins_play->Size = System::Drawing::Size(159, 44);
			this->btn_ins_play->TabIndex = 1;
			this->btn_ins_play->Text = L"Jugar";
			this->btn_ins_play->UseVisualStyleBackColor = false;
			this->btn_ins_play->Click += gcnew System::EventHandler(this, &Frm_principal::btn_ins_play_Click);
			// 
			// lbl_tiempodejuego
			// 
			this->lbl_tiempodejuego->AutoSize = true;
			this->lbl_tiempodejuego->BackColor = System::Drawing::Color::GreenYellow;
			this->lbl_tiempodejuego->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_tiempodejuego->ForeColor = System::Drawing::Color::Black;
			this->lbl_tiempodejuego->Location = System::Drawing::Point(280, 22);
			this->lbl_tiempodejuego->Name = L"lbl_tiempodejuego";
			this->lbl_tiempodejuego->Size = System::Drawing::Size(15, 17);
			this->lbl_tiempodejuego->TabIndex = 20;
			this->lbl_tiempodejuego->Text = L"0";
			// 
			// lbl_tjuego
			// 
			this->lbl_tjuego->AutoSize = true;
			this->lbl_tjuego->BackColor = System::Drawing::Color::GreenYellow;
			this->lbl_tjuego->Font = (gcnew System::Drawing::Font(L"Impact", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_tjuego->ForeColor = System::Drawing::Color::Black;
			this->lbl_tjuego->Location = System::Drawing::Point(226, 22);
			this->lbl_tjuego->Name = L"lbl_tjuego";
			this->lbl_tjuego->Size = System::Drawing::Size(54, 17);
			this->lbl_tjuego->TabIndex = 19;
			this->lbl_tjuego->Text = L"Tiempo: ";
			// 
			// lbl_perdiste
			// 
			this->lbl_perdiste->AutoSize = true;
			this->lbl_perdiste->BackColor = System::Drawing::Color::Indigo;
			this->lbl_perdiste->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Strikeout)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_perdiste->ForeColor = System::Drawing::Color::White;
			this->lbl_perdiste->Location = System::Drawing::Point(350, 298);
			this->lbl_perdiste->Name = L"lbl_perdiste";
			this->lbl_perdiste->Size = System::Drawing::Size(122, 36);
			this->lbl_perdiste->TabIndex = 21;
			this->lbl_perdiste->Text = L"PERDISTE";
			// 
			// lbl_nivelmas
			// 
			this->lbl_nivelmas->AutoSize = true;
			this->lbl_nivelmas->BackColor = System::Drawing::Color::GreenYellow;
			this->lbl_nivelmas->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Strikeout)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_nivelmas->ForeColor = System::Drawing::Color::Black;
			this->lbl_nivelmas->Location = System::Drawing::Point(350, 233);
			this->lbl_nivelmas->Name = L"lbl_nivelmas";
			this->lbl_nivelmas->Size = System::Drawing::Size(74, 36);
			this->lbl_nivelmas->TabIndex = 22;
			this->lbl_nivelmas->Text = L"Nivel";
			// 
			// lbl_ganaste
			// 
			this->lbl_ganaste->AutoSize = true;
			this->lbl_ganaste->BackColor = System::Drawing::Color::GreenYellow;
			this->lbl_ganaste->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Strikeout)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_ganaste->ForeColor = System::Drawing::Color::Black;
			this->lbl_ganaste->Location = System::Drawing::Point(350, 171);
			this->lbl_ganaste->Name = L"lbl_ganaste";
			this->lbl_ganaste->Size = System::Drawing::Size(115, 36);
			this->lbl_ganaste->TabIndex = 23;
			this->lbl_ganaste->Text = L"GANASTE";
			this->lbl_ganaste->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_menosvida
			// 
			this->lbl_menosvida->AutoSize = true;
			this->lbl_menosvida->BackColor = System::Drawing::Color::GreenYellow;
			this->lbl_menosvida->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_menosvida->ForeColor = System::Drawing::Color::Black;
			this->lbl_menosvida->Location = System::Drawing::Point(375, 65);
			this->lbl_menosvida->Name = L"lbl_menosvida";
			this->lbl_menosvida->Size = System::Drawing::Size(97, 36);
			this->lbl_menosvida->TabIndex = 24;
			this->lbl_menosvida->Text = L"- 1 VIDA";
			// 
			// Frm_principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(844, 661);
			this->Controls->Add(this->lbl_menosvida);
			this->Controls->Add(this->lbl_ganaste);
			this->Controls->Add(this->lbl_nivelmas);
			this->Controls->Add(this->lbl_perdiste);
			this->Controls->Add(this->lbl_tiempodejuego);
			this->Controls->Add(this->lbl_tjuego);
			this->Controls->Add(this->pnl_instrucciones2);
			this->Controls->Add(this->pnl_instrucciones1);
			this->Controls->Add(this->lblpuntaje);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Vidas);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Pausa);
			this->Controls->Add(this->pnl_Menu);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(860, 700);
			this->MinimumSize = System::Drawing::Size(860, 700);
			this->Name = L"Frm_principal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"877777uuuuuuuu";
			this->Load += gcnew System::EventHandler(this, &Frm_principal::Quarantine_Game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Frm_principal::Frm_principal_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Frm_principal::Frm_principal_KeyUp);
			this->pnl_Menu->ResumeLayout(false);
			this->pnl_Menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->pnl_instrucciones1->ResumeLayout(false);
			this->pnl_instrucciones2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool f = true;
		int countdownjuego = 0, countdowndisparar = 0, countdowncolisionadversario = 15, countdownperdiste = 15;
		bool t;
		int vidasmostrar;
		void mostrarmenos() {
			if (juego->getjugador()->getvidas() < vidasmostrar) {
				lbl_menosvida->Show();
				lbl_menosvida->BringToFront();
				vidasmostrar--;
			}
			if (countdownjuego % 23 == 0)lbl_menosvida->Hide();
			
		}
		void hidelabels() {
			lbl_tiempodejuego->Hide();
			lblpuntaje->Hide();
			label3->Hide();
			label1->Hide();
			lbl_tjuego->Hide();
			Vidas->Hide();
		}
		void showlabels() {
			lbl_tiempodejuego->Show();
			lblpuntaje->Show();
			label3->Show();
			label1->Show();
			lbl_tjuego->Show();
			Vidas->Show();
		}
		void cambiarnivel() {
			if (nivel == 4 || juego->getnivel() == 4) {
				lbl_nivelmas->Hide();
				hidelabels();
				lbl_ganaste->Show();
				if (countdownjuego % 23 == 0) {
					cambiarpantalla("Menu");
					nivel = 1;
					countdownjuego = 0;
					f = true;
					cancion->Stop();
				}
			} else if (juego->getjugador()->getvidas() == 0 || juego->Tiempo() <= 0) {
				lbl_perdiste->Show();
			}

			if (countdownjuego % 17 == 0) {
				if (juego->getpuntaje() >= juego->getnadversarios() * 5 + 5) {
					delete juego;
					nivel++;
					countdownjuego = 0, countdowndisparar = 0, countdowncolisionadversario = 15, countdownperdiste = 15;
					if (nivel != 3)lbl_nivelmas->Text = "NIVEL " + nivel;
					else lbl_nivelmas->Text = "FUNCION ADICIONAL";
					lbl_nivelmas->Show();
					juego = new Juego((int)numericUpDown1->Value, (int)numericUpDown2->Value, rdbtn_Hard->Checked, nivel);
					vidasmostrar = juego->getjugador()->getvidas();
				}
			}

			if (countdownjuego == 25)lbl_nivelmas->Hide();		
		}
		void perdiste() {
			if (juego->getjugador()->getvidas() <= 0 || juego->Tiempo() <= 0) {
				move->Stop();
				if (countdownperdiste <= 0) {
					cambiarpantalla("Menu");
					cancion->Stop();
				}
				nivel = 1;
				countdownjuego = 0;
				f = true;
			}
		}
		void cambiarpantalla(String^ pantalla) {
			pnl_Menu->Dock = System::Windows::Forms::DockStyle::None;
			panel2->Dock = System::Windows::Forms::DockStyle::None;

			if (pantalla == "Menu") {
				//Esconde los otros paneles diferentes al panel de juego.
				if (f) delete juego;
				lbl_menosvida->SendToBack();
				lbl_ganaste->SendToBack();
				lbl_nivelmas->SendToBack();
				lbl_perdiste->SendToBack();
				draw->Enabled = false;
				move->Enabled = false;
				btn_ins_back->SendToBack();
				pnl_instrucciones1->SendToBack();
				pnl_instrucciones2->SendToBack();
				lbl_tjuego->SendToBack();
				lbl_tiempodejuego->SendToBack();
				label1->SendToBack();
				Vidas->SendToBack();
				lblpuntaje->SendToBack();
				label3->SendToBack();
				Pausa->SendToBack();
				panel2->SendToBack();
				//Muestra el panel del Menu, Dock = Fill (Rellenar pantalla), focus()  se utiliza para centrarse en los eventos de ese panel.
				pnl_Menu->Show();
				pnl_Menu->Dock = System::Windows::Forms::DockStyle::Fill;
				pnl_Menu->Focus();

			}
			else if (pantalla == "Juego") {
				//Esconde los otros paneles diferentes al panel de juego.
				if (f) {  juego = new Juego((int)numericUpDown1->Value, (int)numericUpDown2->Value, rdbtn_Hard->Checked, nivel); f = false;}
				vidasmostrar = juego->getjugador()->getvidas();
				lbl_nivelmas->Hide();
				lbl_menosvida->Hide();
				lbl_ganaste->Hide();
				lbl_perdiste->Hide();
				pnl_instrucciones1->Hide();
				pnl_instrucciones2->Hide();
				panel2->Hide();
				pnl_Menu->Hide();
				pnl_Menu->Dock = System::Windows::Forms::DockStyle::None;
				//Parecido a las instrucciones de Menu, solo que para el panel de juego.
				showlabels();
				label1->BringToFront();
				label3->BringToFront();
				lbl_tjuego->BringToFront();
				lbl_tiempodejuego->BringToFront();
				lblpuntaje->BringToFront();
				Vidas->BringToFront();
				Pausa->Show();
				draw->Enabled = true;
				move->Enabled = true;
				this->Focus();
			}
			else if (pantalla == "Instrucciones1") {
				btn_ins_back->Show();
				pnl_Menu->Hide();
				pnl_instrucciones2->SendToBack();
				pnl_Menu->Dock = System::Windows::Forms::DockStyle::None;
				pnl_instrucciones1->Dock = System::Windows::Forms::DockStyle::Fill;
				pnl_instrucciones1->Show();
				pnl_instrucciones1->BringToFront();
				pnl_instrucciones1->Focus();
			}
			else if (pantalla == "Instrucciones2") {
				pnl_instrucciones1->SendToBack();
				pnl_instrucciones1->Dock = System::Windows::Forms::DockStyle::None;
				pnl_instrucciones2->Dock = System::Windows::Forms::DockStyle::Fill;
				pnl_instrucciones2->Show();
				pnl_instrucciones2->BringToFront();
				pnl_instrucciones2->Focus();
			}
		}
		
		

private: System::Void Quarantine_Game_Load(System::Object^  sender, System::EventArgs^  e) {
}	
		 //Panel para el Menu
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
		 //Boton Jugar!!
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Juego");
}
		 //Boton Instrucciones
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Instrucciones1");
}
		 //Boton Salir
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
		 //Boton Pausa
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	t = !t;
	if (t) { draw->Stop(); move->Stop();  panel2->Show(); }
	else if (!t) {
		Pausa->Hide();
		cambiarpantalla("Juego");
	}
}
		
		 //Boton Menu-Pausa
private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Menu");
	nivel = 1;
	countdownjuego = 0;
	cancion->Stop();
	f = true;
	Pausa->Hide();
}
		 //Boton Instrucciones-Pausa
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Instrucciones1");
	btn_ins_back->Hide();
}
		 //Panel de Pausa
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
		 //Accion de presionar tecla
private: System::Void Frm_principal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Up) {
		juego->jugadorsetfila(0);
		juego->setdir(Arriba);
		juego->jugadorsetdy(-14);
		juego->jugadorsetdx(0);
	} 
	else if (e->KeyCode == Keys::Down) {
		juego->jugadorsetfila(1);
		juego->setdir(Abajo);
		juego->jugadorsetdy(14);
		juego->jugadorsetdx(0);
	} 
	else if (e->KeyCode == Keys::Left) {
		juego->jugadorsetfila(3);
		juego->setdir(Izquierda);
		juego->jugadorsetdx(-14);
		juego->jugadorsetdy(0);
	}
	else if (e->KeyCode == Keys::Right) {
		juego->jugadorsetfila(2);
		juego->setdir(Derecha);
		juego->jugadorsetdx(14);
		juego->jugadorsetdy(0);
	}

	if (juego->disparar(e->KeyCode, countdowndisparar)) {
		countdowndisparar = 3;
	}
}

		 //Timer mostrar
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e){
	BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
	BufferedGraphics^ bf = bfc->Allocate(canvas, this->ClientRectangle);

	if (nivel != 4) {
		juego->mostrarpantalla(bf->Graphics, fondopantalla);
		juego->mostrarjugador(bf->Graphics, spritejugador);
		if (nivel == 3) {
			juego->mostraradversarios(bf->Graphics, spriteadversario, ladron);
		}else juego->mostraradversarios(bf->Graphics, spriteadversario, spriteadversario2);
		juego->mostrardisparo(bf->Graphics, spritemensaje, spritemensajevirus);
		juego->mostrarayudantes(bf->Graphics, spritepolicia, spriteambulancia);
		label1->Text = "" + juego->mostrarvidas();
		juego->colisionmensaje();
	}
	mostrarmenos();
	perdiste();
	countdowncolisionadversario--;
	countdownperdiste--;
	countdowndisparar--;
	bf->Render(canvas);
	delete bf, bfc;
}
		 //Timer mover
private: System::Void move_Tick(System::Object^  sender, System::EventArgs^  e) {

	juego->moverjugador(canvas);
	lbl_tiempodejuego->Text = juego->Tiempo().ToString();
	lblpuntaje->Text = "" + juego->getpuntaje();
	juego->agregaradversarios(countdownjuego++);
	juego->movimientoadversarios(canvas);
	juego->moverdisparo(canvas);
	juego->moverayudantes(canvas);
	juego->eliminarmensajes(canvas);

	if (juego->colisionadversario() && countdowncolisionadversario<=0) {
		countdowncolisionadversario = 15;
		countdownperdiste = 25;
		juego->getjugador()->setvidas(juego->getjugador()->getvidas() - 1);
	}
	if (juego->colisionvirus()) countdownperdiste = 25;

	cambiarnivel();
}

		 //BOTONES INSTRUCCIONES
private: System::Void btn_ins_back_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Menu");
}
private: System::Void btn_ins_next_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Instrucciones2");
}
private: System::Void btn_ins2_back_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Instrucciones1");
	if (!f)btn_ins_back->Hide();
}
private: System::Void btn_ins_play_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarpantalla("Juego");
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void Frm_principal_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Up) {
		juego->jugadorsetdy(0);
	}
	else if (e->KeyCode == Keys::Down) {
		juego->jugadorsetdy(0);
	}
	else if (e->KeyCode == Keys::Left) {
		juego->jugadorsetdx(0);
	}
	else if (e->KeyCode == Keys::Right) {
		juego->jugadorsetdx(0);
	}
}
};


}

