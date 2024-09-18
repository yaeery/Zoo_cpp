#pragma once
#include"MainInfo.h"

namespace KursZoo {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DaysForm
	/// </summary>
	public ref class DaysForm : public System::Windows::Forms::Form
	{
	public:
		DaysForm()
		{
			InitializeComponent();
			
		}
		MainInfo* _MainInfo;
		DaysForm(MainInfo& MainInfo)
		{

			_MainInfo = &MainInfo;//Присовение через равно, т.к. необходим один и тот же объект _MainInfo во всем проекте
			InitializeComponent();
			
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DaysForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора 
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(276, 59);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Выбор дня недели";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &DaysForm::label1_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::Color::Black;
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkedListBox1->ForeColor = System::Drawing::Color::White;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Понедельник", L"Вторник", L"Среда", L"Четверг",
					L"Пятница", L"Суббота", L"Воскресенье"
			});
			this->checkedListBox1->Location = System::Drawing::Point(12, 71);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->checkedListBox1->Size = System::Drawing::Size(276, 268);
			this->checkedListBox1->TabIndex = 8;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &DaysForm::checkedListBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(12, 312);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(276, 42);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Применить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &DaysForm::button1_Click);
			// 
			// DaysForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(302, 363);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"DaysForm";
			this->ShowIcon = false;
			this->Text = L"DaysForm";
			this->Load += gcnew System::EventHandler(this, &DaysForm::DaysForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DaysForm_Load(System::Object^ sender, System::EventArgs^ e);
    private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
