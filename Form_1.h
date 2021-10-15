#pragma once

#include <Windows.h>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "GestureSet.h"
#include "GestureToFile.h"
#include "GestureListToDataGridView.h"
#include <thread>
#include <vector>

namespace MouseController {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form_1
	/// </summary>
	public ref class Form_1 : public System::Windows::Forms::Form
	{
	public:
		Form_1(void)
		{
			InitializeComponent();
			Form_1::Show();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>ц
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form_1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ Set;
	private: System::Windows::Forms::TabPage^ Delete;
	private: System::Windows::Forms::TabPage^ Logs;
	private: System::Windows::Forms::TabPage^ Statistics;
	private: System::Windows::Forms::TabPage^ Settings;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Path;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ PlaySound;
	protected:



	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Set = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Delete = (gcnew System::Windows::Forms::TabPage());
			this->Logs = (gcnew System::Windows::Forms::TabPage());
			this->Statistics = (gcnew System::Windows::Forms::TabPage());
			this->Settings = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Path = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PlaySound = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->tabControl1->SuspendLayout();
			this->Set->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->Delete->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->Set);
			this->tabControl1->Controls->Add(this->Delete);
			this->tabControl1->Controls->Add(this->Logs);
			this->tabControl1->Controls->Add(this->Statistics);
			this->tabControl1->Controls->Add(this->Settings);
			this->tabControl1->Location = System::Drawing::Point(4, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(559, 436);
			this->tabControl1->TabIndex = 0;
			// 
			// Set
			// 
			this->Set->Controls->Add(this->button3);
			this->Set->Controls->Add(this->button2);
			this->Set->Controls->Add(this->label2);
			this->Set->Controls->Add(this->label1);
			this->Set->Controls->Add(this->textBox2);
			this->Set->Controls->Add(this->button1);
			this->Set->Controls->Add(this->textBox1);
			this->Set->Controls->Add(this->pictureBox1);
			this->Set->Location = System::Drawing::Point(4, 25);
			this->Set->Name = L"Set";
			this->Set->Padding = System::Windows::Forms::Padding(3);
			this->Set->Size = System::Drawing::Size(551, 407);
			this->Set->TabIndex = 0;
			this->Set->Text = L"Set a new gesture";
			this->Set->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(448, 144);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(94, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Add";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form_1::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(448, 112);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 26);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Set";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form_1::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Description";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 314);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Path";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 40);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(233, 66);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(480, 334);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(62, 24);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 334);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(465, 22);
			this->textBox1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(445, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 100);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Delete
			// 
			this->Delete->Controls->Add(this->dataGridView1);
			this->Delete->Location = System::Drawing::Point(4, 25);
			this->Delete->Name = L"Delete";
			this->Delete->Padding = System::Windows::Forms::Padding(3);
			this->Delete->Size = System::Drawing::Size(551, 407);
			this->Delete->TabIndex = 1;
			this->Delete->Text = L"Delete a gesture";
			this->Delete->UseVisualStyleBackColor = true;
			// 
			// Logs
			// 
			this->Logs->Location = System::Drawing::Point(4, 25);
			this->Logs->Name = L"Logs";
			this->Logs->Size = System::Drawing::Size(551, 407);
			this->Logs->TabIndex = 2;
			this->Logs->Text = L"Logs";
			this->Logs->UseVisualStyleBackColor = true;
			// 
			// Statistics
			// 
			this->Statistics->Location = System::Drawing::Point(4, 25);
			this->Statistics->Name = L"Statistics";
			this->Statistics->Size = System::Drawing::Size(551, 407);
			this->Statistics->TabIndex = 3;
			this->Statistics->Text = L"Statistics";
			this->Statistics->UseVisualStyleBackColor = true;
			// 
			// Settings
			// 
			this->Settings->Location = System::Drawing::Point(4, 25);
			this->Settings->Name = L"Settings";
			this->Settings->Size = System::Drawing::Size(551, 407);
			this->Settings->TabIndex = 4;
			this->Settings->Text = L"Settings";
			this->Settings->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Number,
					this->Description, this->Path, this->PlaySound
			});
			dataGridView1->Rows->Add(9);
			dataGridView1->Rows[1]->Cells[2]->Value = "rrr";
			gestureListToTable();

			this->dataGridView1->Location = System::Drawing::Point(6, 60);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(539, 277);
			this->dataGridView1->TabIndex = 0;
			// 
			// Number
			// 
			this->Number->HeaderText = L"Number";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->ReadOnly = true;
			// 
			// Description
			// 
			this->Description->HeaderText = L"Description";
			this->Description->MinimumWidth = 6;
			this->Description->Name = L"Description";
			this->Description->ReadOnly = true;
			this->Description->Width = 125;
			// 
			// Path
			// 
			this->Path->HeaderText = L"Path";
			this->Path->MinimumWidth = 6;
			this->Path->Name = L"Path";
			this->Path->ReadOnly = true;
			this->Path->Width = 125;
			// 
			// PlaySound
			// 
			this->PlaySound->HeaderText = L"PlaySound";
			this->PlaySound->MinimumWidth = 6;
			this->PlaySound->Name = L"PlaySound";
			this->PlaySound->ReadOnly = true;
			this->PlaySound->Width = 125;
			// 
			// Form_1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 436);
			this->Controls->Add(this->tabControl1);
			this->MaximizeBox = false;
			this->Name = L"Form_1";
			this->Text = L"Form_1";
			this->tabControl1->ResumeLayout(false);
			this->Set->ResumeLayout(false);
			this->Set->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->Delete->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
		/*
		////////////

		bool Draw;


	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {\
		Graphics^ graf = pictureBox1->CreateGraphics();
		   if (Draw == true)
		   {
			   graf->FillEllipse(Brushes::Red, e->X, e->Y, 3, 3); // толщина кисти
		   }
	}
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Draw = true;
		pictureBox1->Refresh();
		//std::thread setCursorVector(obt);
	}

	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Draw = false;
	}*/
		   /*
	private: void saveAs() {
		openFileDialog1->ShowDialog();
		if (openFileDialog1->FileName != nullptr)
			this->pictureBox1->ImageLocation = this->openFileDialog1->FileName;
		if (pictureBox1->Image)
			Beep(500, 500);
		
		/// <summary>
		/// 
		/// </summary>
		Bitmap^ bitmap1 = gcnew Bitmap(pictureBox1->InitialImage);
		if (!pictureBox1->Image)
			Beep(500, 500);
		Color pixelColor = bitmap1->GetPixel(0, 0);
		if (pixelColor.R == 0)
			Beep(1000, 1000);
		//while (true) {
			bitmap1->SetPixel(0, 0, Color::FromArgb(100, 100, 100));
			bitmap1->SetPixel(1, 1, Color::FromArgb(100, 100, 100));
			bitmap1->SetPixel(2, 2, Color::FromArgb(100, 100, 100));
			bitmap1->SetPixel(2, 1, Color::FromArgb(100, 100, 100));
		//}
	}

	////////////
	*/
		   	//	std::vector <std::pair <int, int> > cursor;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->ShowDialog();
	std::string path = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
	if (path != "")
		textBox1->Text = msclr::interop::marshal_as<String^>(path);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	SetCursorPos(900, 500);

	std::vector <std::pair <int, int> > cursor;
	int y = cursor.size();
	std::string path = "C:\\System64\Window\HWND\3.dll";
	obt(path, cursor);

	Graphics^ graf = pictureBox1->CreateGraphics();
	pictureBox1->Refresh();

	for (int i = 0; i < cursor.size(); ++i) {
		//here must be a vector of cooordinates red from the file
		graf->FillEllipse(Brushes::Red, cursor[i].first, cursor[i].second, 3, 3);
		
	}
	std::ofstream fout("C:\\MouseController\\UserGesture.txt");
	fout << cursor.size() << std::endl;
	for (int i = 0; i < cursor.size(); ++i) {
		fout << cursor[i].first << " " << cursor[i].second;
		fout << std::endl;
	}
	fout.close();


}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	HWND hWnd = GetForegroundWindow();
	if (textBox1->Text == "") {
		MessageBoxW(hWnd, L"Path is empty", L"Error", MB_ICONEXCLAMATION | MB_OK);
	}
	else if (textBox2->Text == "") {
		MessageBoxW(hWnd, L"Description is empty", L"Error", MB_ICONEXCLAMATION | MB_OK);
	}
	else {
		std::ifstream fin("C:\\MouseController\\UserGesture.txt");
		std::vector<std::pair <int, int> > cursor;
		std::string description, path;
		int tmp1, tmp2;
		int size;
		fin >> size;
		for (int i = 0; i < size; ++i) {
			fin >> tmp1 >> tmp2;
			cursor.push_back(std::make_pair(tmp1, tmp2));
		}
		fin.close();
		std::ifstream finl("C:\\MouseController\\GestureList.txt");
		std::string filepath;
		std::string mas[10];
		for (int i = 0; i < 10; ++i)
			finl >> mas[i];
		finl.close();
		for (int i = 0; i < 10; ++i) {
			if (mas[i] == "NO") {
				mas[i] = "YES";
				filepath = "C:\\MouseController\\G";
				filepath += std::to_string(i + 1);
				filepath += ".txt";
				break;
			}
		}
		if (filepath == "")
			filepath = "C:\\MouseController\\G1.txt";//you already have more than 10 gestures
		std::ofstream fout("C:\\MouseController\\GestureList.txt");
		for (int i = 0; i < 10; ++i)
			fout << mas[i] << std::endl;
		fout.close();
		path = msclr::interop::marshal_as<std::string>(textBox1->Text);
		description = msclr::interop::marshal_as<std::string>(textBox2->Text);

		precedencing(cursor, path, filepath, description);

		MessageBoxW(hWnd, L"A new gesture added successfully", L"Success", MB_ICONINFORMATION | MB_OK);
		textBox1->Text = "";
		textBox2->Text = "";
		delete pictureBox1->Image;
		pictureBox1->Image = nullptr;
	}
}
};
}
