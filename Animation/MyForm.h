#pragma once
#include"Header.h"
#include "time.h"
#include <cmath>
#include <array>
#include <fstream>
#include <iostream>
#include "list"
#include "array"
#include"Traj.h"


namespace Animation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			pb->Image = gcnew Bitmap(pb->Width, pb->Height);
			br = gcnew SolidBrush(Color::White);
			br_pink = gcnew SolidBrush(Color::Pink);
			br_yellow = gcnew SolidBrush(Color::LightGoldenrodYellow);
			br_blue = gcnew SolidBrush(Color::Blue);
			br_green = gcnew SolidBrush(Color::DarkOliveGreen);
			br_gray = gcnew SolidBrush(Color::SlateGray);
			gr = Graphics::FromImage(pb->Image);
			pn_line_pink = gcnew Pen(Color::DeepPink, 5);
			pn_big = gcnew Pen(Color::DeepPink, 6);
			pn_green = gcnew Pen(Color::DarkGreen, 6);
			pn_gray = gcnew Pen(Color::DarkSlateGray, 4);
			pn_white = gcnew Pen(Color::White, 1);

			head = gcnew array<PointF>(72);
			h1_1 = gcnew array<PointF>(16);
			h1_2 = gcnew array<PointF>(16);
			h1_3 = gcnew array<PointF>(12);
			h2_1 = gcnew array<PointF>(14);
			h2_2 = gcnew array<PointF>(16);
			h3_1 = gcnew array<PointF>(17);
			h3_2 = gcnew array<PointF>(13);
			h4_1 = gcnew array<PointF>(14);
			h4_2 = gcnew array<PointF>(14);
			h4_3 = gcnew array<PointF>(12);

			ground = gcnew array<PointF>(16);
			plant = gcnew array<PointF>(20);
			plant1 = gcnew array<PointF>(20);
			plant2 = gcnew array<PointF>(20);
			plant3 = gcnew array<PointF>(20);
			plant4 = gcnew array<PointF>(20);
			rock1 = gcnew array<PointF>(14);
			rock2 = gcnew array<PointF>(5);
			rock3 = gcnew array<PointF>(5);
			rock4 = gcnew array<PointF>(5);
			pz1 = gcnew array<PointF>(11);
			pz2 = gcnew array<PointF>(11);
			pz3 = gcnew array<PointF>(11);
			rpz = gcnew array<PointF>(3);
			rp = gcnew array<PointF>(1);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::PictureBox^ pb;
	private: System::Windows::Forms::Button^ btn;
	private: System::Windows::Forms::Label^ lbCoord;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pb = (gcnew System::Windows::Forms::PictureBox());
			this->btn = (gcnew System::Windows::Forms::Button());
			this->lbCoord = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb))->BeginInit();
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// pb
			// 
			this->pb->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->pb->Location = System::Drawing::Point(1, 1);
			this->pb->Name = L"pb";
			this->pb->Size = System::Drawing::Size(996, 668);
			this->pb->TabIndex = 0;
			this->pb->TabStop = false;
			this->pb->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pb_MouseMove);
			// 
			// btn
			// 
			this->btn->Location = System::Drawing::Point(1217, 12);
			this->btn->Name = L"btn";
			this->btn->Size = System::Drawing::Size(75, 23);
			this->btn->TabIndex = 1;
			this->btn->Text = L"button1";
			this->btn->UseVisualStyleBackColor = true;
			this->btn->Click += gcnew System::EventHandler(this, &MyForm::btn_Click);
			// 
			// lbCoord
			// 
			this->lbCoord->AutoSize = true;
			this->lbCoord->Location = System::Drawing::Point(1132, 22);
			this->lbCoord->Name = L"lbCoord";
			this->lbCoord->Size = System::Drawing::Size(35, 13);
			this->lbCoord->TabIndex = 2;
			this->lbCoord->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1345, 755);
			this->Controls->Add(this->lbCoord);
			this->Controls->Add(this->btn);
			this->Controls->Add(this->pb);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Pen^ pn_line_pink, ^pn_big, ^pn_green, ^pn_gray, ^pn_white;
		Brush^ br, ^ br_yellow, ^ br_pink, ^ br_blue, ^br_green, ^br_gray;
		Graphics^ gr;

		array<PointF>^ head, ^ h1_1, ^h1_2,^h1_3, ^h2_1, ^h2_2, ^h3_1, ^h3_2, ^h4_1, ^h4_2, ^h4_3, ^ground, ^plant, ^plant1, ^plant2, ^plant3, ^plant4, ^rock1, ^rock2, ^rock3, ^rock4, ^pz1, ^pz2, ^pz3, ^rpz, ^rp;

		int ticks = 0;
		int ticks_pz = 0;
		int ticks_h = 0;


		void rot(float phi, int size, array<PointF>^ a, PointF c) {
			array<float, 2>^ rot = gcnew array<float, 2>(3, 3);
			rotate_mat(c, phi, rot);
			for (int i = 0; i < size; i++) {
				a[i] = apply(a[i], rot);
			}
		}

		void move(float x, float y, int size, array<PointF>^ a) {
			array<float, 2>^ move = gcnew array<float, 2>(3, 3);
			move_mat(x, y, move);
			for (int i = 0; i < size; i++) {
				a[i] = apply(a[i], move);
			}
		}

		void scale(float x, float y, int size, array<PointF>^ a, PointF c) {
			array<float, 2>^ sc = gcnew array<float, 2>(3, 3);
			scale_mat(c, x, y, sc);
			for (int i = 0; i < size; i++) {
				a[i] = apply(a[i], sc);
			}
		}

		void initPoint() {
			head[0] = PointF(93, 272);
			head[1] = PointF(91, 276);
			head[2] = PointF(88, 280);
			head[3] = PointF(85, 281);
			head[4] = PointF(83, 277);
			head[5] = PointF(81, 272);
			head[6] = PointF(80, 268);
			head[7] = PointF(76, 279);
			head[8] = PointF(73, 282);
			head[9] = PointF(72, 284);
			head[10] = PointF(69, 278);
			head[11] = PointF(68, 271);
			head[12] = PointF(66, 266);
			head[13] = PointF(63, 271);
			head[14] = PointF(61, 280);
			head[15] = PointF(58, 286);
			head[16] = PointF(54, 285);
			head[17] = PointF(52, 277);
			head[18] = PointF(51, 272);
			head[19] = PointF(50, 268);
			head[20] = PointF(48, 271);
			head[21] = PointF(47, 276);
			head[22] = PointF(46, 282);
			head[23] = PointF(44, 284);
			head[24] = PointF(42, 282);
			head[25] = PointF(40, 275);
			head[26] = PointF(40, 272);
			head[27] = PointF(39, 267);
			head[28] = PointF(40, 260);
			head[29] = PointF(42, 252);
			head[30] = PointF(46, 244);
			head[31] = PointF(51, 234);
			head[32] = PointF(57, 225);
			head[33] = PointF(72, 216);
			head[34] = PointF(83, 210);
			head[35] = PointF(96, 205);
			head[36] = PointF(112, 208);
			head[37] = PointF(126, 216);
			head[38] = PointF(140, 224);
			head[39] = PointF(152, 236);
			head[40] = PointF(156, 249);
			head[41] = PointF(158, 261);
			head[42] = PointF(159, 271);
			head[43] = PointF(155, 277);
			head[44] = PointF(150, 284);
			head[45] = PointF(148, 286);
			head[46] = PointF(146, 284);
			head[47] = PointF(144, 277);
			head[48] = PointF(142, 272);
			head[49] = PointF(138, 265);
			head[50] = PointF(135, 272);
			head[51] = PointF(132, 277);
			head[52] = PointF(130, 282);
			head[53] = PointF(129, 284);
			head[54] = PointF(125, 282);
			head[55] = PointF(124, 277);
			head[56] = PointF(122, 271);
			head[57] = PointF(120, 265);
			head[58] = PointF(118, 262);
			head[59] = PointF(115, 267);
			head[60] = PointF(113, 274);
			head[61] = PointF(112, 278);
			head[62] = PointF(110, 281);
			head[63] = PointF(108, 282);
			head[64] = PointF(105, 275);
			head[65] = PointF(102, 268);
			head[66] = PointF(101, 263);
			head[67] = PointF(99, 256);
			head[68] = PointF(97, 262);
			head[69] = PointF(96, 267);
			head[70] = PointF(94, 269);
			head[71] = PointF(93, 274);

			h1_1[0] = PointF(53, 259);
			h1_1[1] = PointF(57, 256);
			h1_1[2] = PointF(61, 258);
			h1_1[3] = PointF(61, 264);
			h1_1[4] = PointF(60, 271);
			h1_1[5] = PointF(58, 278);
			h1_1[6] = PointF(56, 287);
			h1_1[7] = PointF(53, 294);
			h1_1[8] = PointF(51, 300);
			h1_1[9] = PointF(48, 302);
			h1_1[10] = PointF(44, 301);
			h1_1[11] = PointF(44, 296);
			h1_1[12] = PointF(44, 287);
			h1_1[13] = PointF(47, 279);
			h1_1[14] = PointF(49, 270);
			h1_1[15] = PointF(52, 259);

			h1_2[0] = PointF(39, 299);
			h1_2[1] = PointF(47, 293);
			h1_2[2] = PointF(50, 302);
			h1_2[3] = PointF(50, 310);
			h1_2[4] = PointF(49, 319);
			h1_2[5] = PointF(46, 326);
			h1_2[6] = PointF(44, 334);
			h1_2[7] = PointF(41, 338);
			h1_2[8] = PointF(37, 340);
			h1_2[9] = PointF(34, 339);
			h1_2[10] = PointF(33, 334);
			h1_2[11] = PointF(32, 328);
			h1_2[12] = PointF(34, 320);
			h1_2[13] = PointF(36, 312);
			h1_2[14] = PointF(39, 305);
			h1_2[15] = PointF(40, 299);

			h1_3[0] = PointF(40, 334);
			h1_3[1] = PointF(42, 340);
			h1_3[2] = PointF(43, 347);
			h1_3[3] = PointF(43, 356);
			h1_3[4] = PointF(43, 366);
			h1_3[5] = PointF(40, 368);
			h1_3[6] = PointF(35, 370);
			h1_3[7] = PointF(31, 365);
			h1_3[8] = PointF(30, 359);
			h1_3[9] = PointF(31, 352);
			h1_3[10] = PointF(31, 343);
			h1_3[11] = PointF(35, 334);

			h2_1[0] = PointF(74, 266);
			h2_1[1] = PointF(79, 260);
			h2_1[2] = PointF(83, 260);
			h2_1[3] = PointF(85, 271);
			h2_1[4] = PointF(85, 280);
			h2_1[5] = PointF(84, 289);
			h2_1[6] = PointF(80, 298);
			h2_1[7] = PointF(76, 303);
			h2_1[8] = PointF(70, 303);
			h2_1[9] = PointF(68, 297);
			h2_1[10] = PointF(69, 287);
			h2_1[11] = PointF(71, 281);
			h2_1[12] = PointF(72, 270);
			h2_1[13] = PointF(74, 266);

			h2_2[0] = PointF(73, 296);
			h2_2[1] = PointF(69, 300);
			h2_2[2] = PointF(66, 305);
			h2_2[3] = PointF(66, 310);
			h2_2[4] = PointF(64, 317);
			h2_2[5] = PointF(62, 322);
			h2_2[6] = PointF(61, 329);
			h2_2[7] = PointF(60, 331);
			h2_2[8] = PointF(60, 337);
			h2_2[9] = PointF(63, 339);
			h2_2[10] = PointF(67, 335);
			h2_2[11] = PointF(71, 327);
			h2_2[12] = PointF(73, 315);
			h2_2[13] = PointF(74, 308);
			h2_2[14] = PointF(75, 299);
			h2_2[15] = PointF(73, 298);

			h3_1[0] = PointF(105, 263);
			h3_1[1] = PointF(108, 259);
			h3_1[2] = PointF(111, 259);
			h3_1[3] = PointF(114, 263);
			h3_1[4] = PointF(116, 267);
			h3_1[5] = PointF(116, 275);
			h3_1[6] = PointF(117, 283);
			h3_1[7] = PointF(117, 289);
			h3_1[8] = PointF(117, 295);
			h3_1[9] = PointF(117, 298);
			h3_1[10] = PointF(112, 301);
			h3_1[11] = PointF(110, 296);
			h3_1[12] = PointF(108, 291);
			h3_1[13] = PointF(108, 284);
			h3_1[14] = PointF(106, 276);
			h3_1[15] = PointF(105, 270);
			h3_1[16] = PointF(105, 263);

			h3_2[0] = PointF(112, 294);
			h3_2[1] = PointF(109, 301);
			h3_2[2] = PointF(110, 312);
			h3_2[3] = PointF(110, 318);
			h3_2[4] = PointF(111, 323);
			h3_2[5] = PointF(115, 328);
			h3_2[6] = PointF(116, 328);
			h3_2[7] = PointF(119, 323);
			h3_2[8] = PointF(119, 318);
			h3_2[9] = PointF(119, 306);
			h3_2[10] = PointF(116, 298);
			h3_2[11] = PointF(113, 289);
			h3_2[12] = PointF(112, 296);

			h4_1[0] = PointF(149, 267);
			h4_1[1] = PointF(144, 274);
			h4_1[2] = PointF(141, 289);
			h4_1[3] = PointF(141, 297);
			h4_1[4] = PointF(144, 305);
			h4_1[5] = PointF(144, 311);
			h4_1[6] = PointF(148, 316);
			h4_1[7] = PointF(151, 316);
			h4_1[8] = PointF(154, 308);
			h4_1[9] = PointF(155, 301);
			h4_1[10] = PointF(155, 293);
			h4_1[11] = PointF(152, 282);
			h4_1[12] = PointF(152, 267);
			h4_1[13] = PointF(149, 264);

			h4_2[0] = PointF(149, 304);
			h4_2[1] = PointF(147, 311);
			h4_2[2] = PointF(146, 318);
			h4_2[3] = PointF(144, 325);
			h4_2[4] = PointF(143, 333);
			h4_2[5] = PointF(144, 340);
			h4_2[6] = PointF(147, 344);
			h4_2[7] = PointF(154, 345);
			h4_2[8] = PointF(155, 338);
			h4_2[9] = PointF(156, 327);
			h4_2[10] = PointF(156, 318);
			h4_2[11] = PointF(156, 308);
			h4_2[12] = PointF(153, 300);
			h4_2[13] = PointF(148, 302);

			h4_3[0] = PointF(149, 342);
			h4_3[1] = PointF(148, 349);
			h4_3[2] = PointF(146, 357);
			h4_3[3] = PointF(143, 365);
			h4_3[4] = PointF(147, 370);
			h4_3[5] = PointF(153, 371);
			h4_3[6] = PointF(157, 368);
			h4_3[7] = PointF(157, 360);
			h4_3[8] = PointF(157, 352);
			h4_3[9] = PointF(156, 346);
			h4_3[10] = PointF(154, 339);
			h4_3[11] = PointF(150, 339);

			ground[0] = PointF(0, 589);
			ground[1] = PointF(77, 585);
			ground[2] = PointF(185, 571);
			ground[3] = PointF(263, 592);
			ground[4] = PointF(351, 577);
			ground[5] = PointF(427, 600);
			ground[6] = PointF(522, 589);
			ground[7] = PointF(599, 566);
			ground[8] = PointF(670, 557);
			ground[9] = PointF(755, 549);
			ground[10] = PointF(831, 560);
			ground[11] = PointF(911, 575);
			ground[12] = PointF(982, 599);
			ground[13] = PointF(1067, 606);
			ground[14] = PointF(1067, 667);
			ground[15] = PointF(0, 667);

			plant[0] = PointF(730, 576);
			plant[1] = PointF(728, 567);
			plant[2] = PointF(730, 553);
			plant[3] = PointF(719, 540);
			plant[4] = PointF(727, 522);
			plant[5] = PointF(721, 509);
			plant[6] = PointF(728, 495);
			plant[7] = PointF(737, 487);
			plant[8] = PointF(744, 490);
			plant[9] = PointF(742, 498);
			plant[10] = PointF(733, 507);
			plant[11] = PointF(735, 519);
			plant[12] = PointF(740, 528);
			plant[13] = PointF(733, 536);
			plant[14] = PointF(734, 544);
			plant[15] = PointF(743, 552);
			plant[16] = PointF(744, 567);
			plant[17] = PointF(744, 574);
			plant[18] = PointF(739, 576);
			plant[19] = PointF(729, 575);

			rock1[0] = PointF(719, 628);
			rock1[1] = PointF(712, 623);
			rock1[2] = PointF(709, 615);
			rock1[3] = PointF(715, 610);
			rock1[4] = PointF(722, 607);
			rock1[5] = PointF(733, 607);
			rock1[6] = PointF(745, 606);
			rock1[7] = PointF(753, 610);
			rock1[8] = PointF(750, 617);
			rock1[9] = PointF(744, 621);
			rock1[10] = PointF(734, 626);
			rock1[11] = PointF(726, 627);
			rock1[12] = PointF(720, 628);
			rock1[13] = PointF(717, 628);

			rock2[0] = PointF(921, 637);
			rock2[1] = PointF(916, 630);
			rock2[2] = PointF(927, 625);
			rock2[3] = PointF(933, 638);
			rock2[4] = PointF(922, 637);

			pz1[0] = PointF(717, 482);
			pz1[1] = PointF(712, 481);
			pz1[2] = PointF(710, 476);
			pz1[3] = PointF(711, 470);
			pz1[4] = PointF(716, 468);
			pz1[5] = PointF(721, 468);
			pz1[6] = PointF(724, 471);
			pz1[7] = PointF(726, 477);
			pz1[8] = PointF(724, 479);
			pz1[9] = PointF(722, 481);
			pz1[10] = PointF(718, 482);

			rpz[0] = PointF(718, 475);
			rpz[1] = PointF(747, 454);
			rpz[2] = PointF(700, 445);

			rp[0] = PointF(270, 260);




			for (int i = 0; i < 20; i++) {
				plant1[i] = plant[i];
			}
			for (int i = 0; i < 20; i++) {
				plant2[i] = plant[i];
			}
			for (int i = 0; i < 20; i++) {
				plant3[i] = plant[i];
			}
			for (int i = 0; i < 20; i++) {
				plant4[i] = plant[i];
			}
			for (int i = 0; i < 5; i++) {
				rock3[i] = rock2[i];
			}
			for (int i = 0; i < 5; i++) {
				rock4[i] = rock2[i];
			}
			for (int i = 0; i < 11; i++) {
				pz2[i] = pz1[i];
			}
			for (int i = 0; i < 11; i++) {
				pz3[i] = pz1[i];
			}

			move(-30, 10, 20, plant1);
			move(50, 50, 20, plant2);
			move(20, 5, 20, plant3);
			move(-70, 60, 20, plant4);

			move(-300, -20, 5, rock3);
			move(-400, 25, 5, rock4);

			move(30, -20, 11, pz2);
			move(-20, -30, 11, pz3);
		}

		void drawAll() {

			gr->FillClosedCurve(br_yellow, ground);
			gr->FillClosedCurve(br_green, plant);
			gr->FillClosedCurve(br_green, plant1);
			gr->FillClosedCurve(br_green, plant2);
			gr->FillClosedCurve(br_green, plant3);
			gr->FillClosedCurve(br_green, plant4);
			gr->FillPolygon(br_gray, rock1);
			gr->FillPolygon(br_gray, rock2);
			gr->FillPolygon(br_gray, rock3);
			gr->FillPolygon(br_gray, rock4);

			gr->DrawLines(pn_green, plant);
			gr->DrawLines(pn_green, plant1);
			gr->DrawLines(pn_green, plant2);
			gr->DrawLines(pn_green, plant3);
			gr->DrawLines(pn_green, plant4);
			gr->DrawLines(pn_gray, rock1);
			gr->DrawLines(pn_gray, rock2);
			gr->DrawLines(pn_gray, rock3);
			gr->DrawLines(pn_gray, rock4);

			gr->DrawLines(pn_white, pz1);
			gr->DrawLines(pn_white, pz2);
			gr->DrawLines(pn_white, pz3);

			gr->DrawLines(pn_line_pink, h1_3);
			gr->FillPolygon(br_pink, h1_3);
			gr->DrawLines(pn_line_pink, h4_3);
			gr->FillPolygon(br_pink, h4_3);

			gr->DrawLines(pn_line_pink, h1_2);
			gr->FillPolygon(br_pink, h1_2);
			gr->DrawLines(pn_line_pink, h2_2);
			gr->FillPolygon(br_pink, h2_2);
			gr->DrawLines(pn_line_pink, h3_2);
			gr->FillPolygon(br_pink, h3_2);
			gr->DrawLines(pn_line_pink, h4_2);
			gr->FillPolygon(br_pink, h4_2);

			gr->DrawLines(pn_line_pink, h1_1);
			gr->FillPolygon(br_pink, h1_1);
			gr->DrawLines(pn_line_pink, h2_1);
			gr->FillPolygon(br_pink, h2_1);
			gr->DrawLines(pn_line_pink, h3_1);
			gr->FillPolygon(br_pink, h3_1);
			gr->DrawLines(pn_line_pink, h4_1);
			gr->FillPolygon(br_pink, h4_1);
			gr->DrawLines(pn_line_pink, head);
			gr->FillPolygon(br_pink, head);
		}

		void refresh_pz() {
			pz1[0] = PointF(717, 482);
			pz1[1] = PointF(712, 481);
			pz1[2] = PointF(710, 476);
			pz1[3] = PointF(711, 470);
			pz1[4] = PointF(716, 468);
			pz1[5] = PointF(721, 468);
			pz1[6] = PointF(724, 471);
			pz1[7] = PointF(726, 477);
			pz1[8] = PointF(724, 479);
			pz1[9] = PointF(722, 481);
			pz1[10] = PointF(718, 482);

			rpz[0] = PointF(718, 475);
			rpz[1] = PointF(747, 454);
			rpz[2] = PointF(700, 445);
			for (int i = 0; i < 11; i++) {
				pz2[i] = pz1[i];
			}
			for (int i = 0; i < 11; i++) {
				pz3[i] = pz1[i];
			}
			move(30, -20, 11, pz2);
			move(-20, -30, 11, pz3);
		}

		void rotAll(int key, float phi) {
			if (key == 1) {
				rot(-phi, 72, head, rp[0]);
				rot(-phi, 16, h1_1, rp[0]);
				rot(-phi, 16, h1_2, rp[0]);
				rot(-phi, 12, h1_3, rp[0]);
				rot(-phi, 14, h2_1, rp[0]);
				rot(-phi, 16, h2_2, rp[0]);
				rot(-phi, 17, h3_1, rp[0]);
				rot(-phi, 13, h3_2, rp[0]);
				rot(-phi, 14, h4_1, rp[0]);
				rot(-phi, 14, h4_2, rp[0]);
				rot(-phi, 12, h4_3, rp[0]);
			}
			if (key == 2) {
				rot(phi, 72, head, rp[0]);
				rot(phi, 16, h1_1, rp[0]);
				rot(phi, 16, h1_2, rp[0]);
				rot(phi, 12, h1_3, rp[0]);
				rot(phi, 14, h2_1, rp[0]);
				rot(phi, 16, h2_2, rp[0]);
				rot(phi, 17, h3_1, rp[0]);
				rot(phi, 13, h3_2, rp[0]);
				rot(phi, 14, h4_1, rp[0]);
				rot(phi, 14, h4_2, rp[0]);
				rot(phi, 12, h4_3, rp[0]);
			}
		}

		void rotHands() {
			if (ticks_h < 25) {
				rot(-0.017, 16, h1_1, h1_1[0]);
				rot(-0.03, 16, h1_2, h1_2[0]);
				rot(-0.04, 12, h1_3, h1_3[0]);
				rot(-0.01, 14, h2_1, h2_1[0]);
				rot(-0.02, 16, h2_2, h2_2[0]);

				rot(0.01, 17, h3_1, h3_1[0]);
				rot(0.02, 13, h3_2, h3_2[0]);
				rot(0.02, 14, h4_1, h4_1[0]);
				rot(0.033, 14, h4_2, h4_2[0]);
				rot(0.04, 12, h4_3, h4_3[0]);
				//
				rot(-0.006, 16, h1_1, head[68]);
				rot(-0.0115, 16, h1_2, head[68]);
				rot(-0.022, 12, h1_3, head[68]);
				rot(-0.004, 14, h2_1, head[68]);
				rot(-0.005, 16, h2_2, head[68]);

				rot(0.004, 17, h3_1, head[68]);
				rot(0.0055, 13, h3_2, head[68]);
				rot(0.006, 14, h4_1, head[68]);
				rot(0.01, 14, h4_2, head[68]);
				rot(0.02, 12, h4_3, head[68]);


			}
			if (ticks_h > 25 && ticks_h < 50) {
				rot(0.017, 16, h1_1, h1_1[0]);
				rot(0.03, 16, h1_2, h1_2[0]);
				rot(0.04, 12, h1_3, h1_3[0]);
				rot(0.01, 14, h2_1, h2_1[0]);
				rot(0.02, 16, h2_2, h2_2[0]);

				rot(-0.01, 17, h3_1, h3_1[0]);
				rot(-0.02, 13, h3_2, h3_2[0]);
				rot(-0.02, 14, h4_1, h4_1[0]);
				rot(-0.033, 14, h4_2, h4_2[0]);
				rot(-0.04, 12, h4_3, h4_3[0]);
				//
				rot(0.006, 16, h1_1, head[68]);
				rot(0.0115, 16, h1_2, head[68]);
				rot(0.022, 12, h1_3, head[68]);
				rot(0.004, 14, h2_1, head[68]);
				rot(0.005, 16, h2_2, head[68]);

				rot(-0.004, 17, h3_1, head[68]);
				rot(-0.0055, 13, h3_2, head[68]);
				rot(-0.006, 14, h4_1, head[68]);
				rot(-0.01, 14, h4_2, head[68]);
				rot(-0.02, 12, h4_3, head[68]);
				if (ticks_h == 49) {
					ticks_h = 0;
				}
			}
		}

		void movePoint() {
			if ((ticks == 145) || (ticks == 292)) {
				move(340, 0, 1, rp);
			}
		}
		void bubble() {
			if (ticks_pz < 50) {
				move(0, -10, 11, pz1);
				move(0, -10, 11, pz2);
				move(0, -10, 11, pz3);
				move(0, -10, 3, rpz);

				rot(0.1, 11, pz1, rpz[0]);
				rot(0.1, 11, pz2, rpz[1]);
				rot(0.1, 11, pz3, rpz[2]);
				if (ticks_pz == 49) {
					ticks_pz = 0;
					refresh_pz();
				}
			}
		}

		void scaleHead() {
			if (ticks_h < 25) {
				scale(1.01, 1, 72, head, head[68]);
				scale(1, 0.99, 72, head, head[68]);
			}
			if (ticks_h >= 25 && ticks_h < 50) {
				scale(0.99, 1, 72, head, head[68]);
				scale(1, 1.01, 72, head, head[68]);
			}
		}

		private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			ticks_h++;
			ticks ++;
			ticks_pz++;

			if (ticks < 146) {
				gr->FillRectangle(br_blue, 0, 0, pb->Width, pb->Height);
				bubble();
				if (ticks_h < 25) {
					rotAll(1, 0.015);
				}
				else {
					if (ticks_h > 25 && ticks_h < 50) {
						rotAll(1, 0.03);
					}
				}
				rotHands();
				scaleHead();
				movePoint();
				drawAll();
				pb->Refresh();
			}
			if (ticks > 146 && ticks < 293) {
				gr->FillRectangle(br_blue, 0, 0, pb->Width, pb->Height);
				bubble();
				if (ticks_h < 25) {
					rotAll(2, 0.015);
				}
				else{
					if (ticks_h > 25 && ticks_h < 50) {
						rotAll(2, 0.03);
					}
				}
				rotHands();
				scaleHead();
				movePoint();
				drawAll();
				pb->Refresh();
				if (ticks == 292) {
					initPoint();
					ticks = 0;
					ticks_pz = 0;
					ticks_h = 0;
				}
			}

		}

	private: System::Void btn_Click(System::Object^ sender, System::EventArgs^ e) {
		initPoint();
		timer->Enabled = true;
		ticks = 0;
		ticks_pz = 0;
		ticks_h = 0;
	}
	private: System::Void pb_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		lbCoord->Text = Convert::ToString(e->Location);
	}
};
}
