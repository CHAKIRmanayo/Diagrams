#pragma once
#include <math.h>;

namespace Diagrams {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	struct Rows {
		char* NameD;
		float CountD;
	};
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Button^  btnCom;
	protected:

	protected:
	private: System::Windows::Forms::Button^  btnCirc;
	private: System::Windows::Forms::PictureBox^  pb;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Count1;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCom = (gcnew System::Windows::Forms::Button());
			this->btnCirc = (gcnew System::Windows::Forms::Button());
			this->pb = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Name1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Count1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCom
			// 
			this->btnCom->Location = System::Drawing::Point(649, 444);
			this->btnCom->Name = L"btnCom";
			this->btnCom->Size = System::Drawing::Size(132, 66);
			this->btnCom->TabIndex = 0;
			this->btnCom->Text = L"Common";
			this->btnCom->UseVisualStyleBackColor = true;
			this->btnCom->Click += gcnew System::EventHandler(this, &MyForm::btnCom_Click);
			// 
			// btnCirc
			// 
			this->btnCirc->Location = System::Drawing::Point(841, 442);
			this->btnCirc->Name = L"btnCirc";
			this->btnCirc->Size = System::Drawing::Size(132, 70);
			this->btnCirc->TabIndex = 1;
			this->btnCirc->Text = L"Circle";
			this->btnCirc->UseVisualStyleBackColor = true;
			this->btnCirc->Click += gcnew System::EventHandler(this, &MyForm::btnCirc_Click);
			// 
			// pb
			// 
			this->pb->Location = System::Drawing::Point(12, 36);
			this->pb->Name = L"pb";
			this->pb->Size = System::Drawing::Size(587, 476);
			this->pb->TabIndex = 2;
			this->pb->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Name1,
					this->Count1
			});
			this->dataGridView1->Location = System::Drawing::Point(632, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(341, 191);
			this->dataGridView1->TabIndex = 3;
			// 
			// Name1
			// 
			this->Name1->HeaderText = L"Name";
			this->Name1->Name = L"Name1";
			// 
			// Count1
			// 
			this->Count1->HeaderText = L"Count";
			this->Count1->Name = L"Count1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1014, 550);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pb);
			this->Controls->Add(this->btnCirc);
			this->Controls->Add(this->btnCom);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		char* convertStringToChar(String^ path) {
			return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(path).ToPointer();
		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btnCirc_Click(System::Object^  sender, System::EventArgs^  e) {
		pb->Image = gcnew Bitmap(pb->Width, pb->Height);
		Graphics^ g = Graphics::FromImage(pb->Image);
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);
		Pen^ p = gcnew Pen(Color::Black);
		circleDiagram(p, brush, g);
		pb->Invalidate();

	}
	private: System::Void btnCom_Click(System::Object^  sender, System::EventArgs^  e) {
		pb->Image = gcnew Bitmap(pb->Width, pb->Height);
		Graphics^ g = Graphics::FromImage(pb->Image);
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);
		commonDiagram(brush, g);
		pb->Invalidate();
	}

	private: Rows* getRows(int* flag) {
		int t = dataGridView1->RowCount - 1;
		double f;
		Rows* R = new Rows[t];
		for (int i = 0; i < t; i++) {
			if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr) {
				*flag = 2;
				break;
			}
			if ((dataGridView1->Rows[i]->Cells[1]->Value != nullptr) && (Double::TryParse(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), f))) {
				if (f > 0) {
					R[i].CountD = f;
					R[i].NameD = convertStringToChar(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				}
				else {
					*flag = 1;
					break;
				}
			}
			else {
				*flag = 1;
				break;
			}
		}
		return R;
	}
	private: void commonDiagram(SolidBrush^ brush, Graphics^ g) {
		float indent = 20;
		int flag = 0;
		Rows* R = getRows(&flag);
		if (control(flag)) {
			return;
		}
		int t = dataGridView1->RowCount - 1;
		float max = findMax(R, t);
		float width = (pb->Width - 2 * indent) / t / 2;
		float scale = (pb->Height - 2 * indent) / max;
		drawComDiagram(brush, g, t, R, width, scale, indent);
	}

	private: bool control(int flag) {
		if (flag == 1) {
			MessageBox::Show("Error: invalid value");
			return true;
		}
		if (flag == 2) {
			MessageBox::Show("Error: invalid name");
			return true;
		}
		return false;
	}

	private: void drawComDiagram(SolidBrush^ brush, Graphics^ g, int t, Rows* R, float widht, float scale, float indent) {
		for (int i = 0; i < t; i++) {
			brush->Color = Color::FromArgb(255, (120 + i * 200) % 255, (50 + i * 300) % 255, (200 + i * 100) % 255);
			g->FillRectangle(brush, float(indent + i * 2 * widht), float(pb->Height - indent - R[i].CountD * scale), float(widht), float(R[i].CountD * scale));
			brush->Color = Color::Black;
			System::Drawing::Font^ font1 = gcnew System::Drawing::Font(FontFamily::GenericMonospace, 12);
			String^ str = gcnew String(R[i].NameD);
			g->DrawString(str, font1, brush, indent + i * 2 * widht + (widht / 2.0) - (str->Length / 2.0 * 11), pb->Height - indent + 2);
		}
	}

	private: void circleDiagram(Pen^ pen, SolidBrush^ brush, Graphics^ g) {
		float indent = 30;
		int flag = 0;
		Rows* R = getRows(&flag);
		if (control(flag)) {
			return;
		}
		int t = dataGridView1->RowCount - 1;
		if (t > 0) {
			float scale = 360 / sum(R, t);
			drawCircDiagram(brush, g, t, R, indent, scale);
		}
	}

	private: void drawCircDiagram(SolidBrush^ brush, Graphics^ g, int t, Rows* R, float indent, float scale) {
		float r = pb->Width < pb->Height ? pb->Width : pb->Height;
		Rectangle rect = Rectangle(2 * indent, 2 * indent, float((r - 3 * indent)), float((r - 3 * indent)));
		float angle = 0;
		for (int i = 0; i < t; i++) {
			brush->Color = Color::FromArgb(255, (120 + i * 200) % 255, (50 + i * 300) % 255, (200 + i * 100) % 255);
			g->FillPie(brush, rect, angle, scale * R[i].CountD);
			float xpos = 0;
			float ypos = 0;
			getPos(angle, angle + scale * R[i].CountD, float(r - 2 * 10) / 2, &xpos, &ypos);
			brush->Color = Color::Black;
			System::Drawing::Font^ font1 = gcnew System::Drawing::Font(FontFamily::GenericMonospace, 11);
			g->DrawString(gcnew String(R[i].NameD), font1, brush, r / 2 + xpos, r / 2 + (ypos / 1.1));
			angle += scale * R[i].CountD;
		}
		g->FillPie(brush, rect, angle, 360 - angle);

	}

	private: void getPos(float startAngle, float endAngle, float radius, float* xpos, float* ypos) {
		float angle = (startAngle + endAngle) / 2;
		float cos = Math::Cos(angle / 180 * 3.14);
		float sin = Math::Sin(angle / 180 * 3.14);
		*xpos = radius * cos;
		*ypos = radius * sin;
	}

	private: float findMax(Rows* R, int t) {
		float max;
		for (int i = 0; i < t; i++) {
			if (t == 0) {
				max = R[i].CountD;
			}
			if (R[i].CountD > max) {
				max = R[i].CountD;
			}
		}
		return max;
	}

	private: float sum(Rows* R, int t) {
		float s = 0;
		for (int i = 0; i < t; i++) {
			s += R[i].CountD;
		}
		return s;
	}
	};
}
