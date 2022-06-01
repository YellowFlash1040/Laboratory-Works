#pragma once

#include "Game.h"

namespace Minor
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MinorForm
	/// </summary>
	public ref class MinorForm : public System::Windows::Forms::Form
	{
	public:

		Game* game;

		MinorForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			countOfFlags_Label->BringToFront();
			Players_Time_Label->BringToFront();

			isGameStarted = false;

			game = new Game();

			countOfFlags_Label->Text = game->countOfFlags.ToString();

			int sizeOfCell = 50;
			Cells = gcnew array<PictureBox^, 2>(10, 10);
			for (int i = 0; i < game->heightOfPitch; i++)
			{
				for (int j = 0; j < game->widthOfPitch; j++)
				{
					PictureBox^ Cell = gcnew PictureBox();
					Cell->Name = "Cell";
					Cell->Size = System::Drawing::Size(sizeOfCell, sizeOfCell);
					Cell->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
					Cell->Location = System::Drawing::Point(i * sizeOfCell, j * sizeOfCell + 100 - 19);
					Cell->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MinorForm::Cell_MouseClick);
					Cell->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MinorForm::Cell_MouseDown);
					Cell->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MinorForm::Cell_MouseUp);
					if ((i + j) % 2 == 0)
					{
						Cell->BackColor = System::Drawing::Color::Green;
					}
					else
					{
						Cell->BackColor = System::Drawing::Color::LightGreen;
					}
					Cells[i, j] = Cell;
					this->Controls->Add(Cell);
				}

				this->ClientSize = System::Drawing::Size(sizeOfCell * game->widthOfPitch, sizeOfCell * game->heightOfPitch + 100 - 19);
			}
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MinorForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Timer^ time_Timer;
	private: System::Windows::Forms::Label^ Players_Time_Label;
	private: System::Windows::Forms::Label^ countOfFlags_Label;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ FlagPicture_PictureBox;
	private: System::Windows::Forms::PictureBox^ ClockPicture_PictureBox;
	private: System::Windows::Forms::PictureBox^ Restart_Button;


	private: System::ComponentModel::IContainer^ components;



	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MinorForm::typeid));
			this->time_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Players_Time_Label = (gcnew System::Windows::Forms::Label());
			this->countOfFlags_Label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FlagPicture_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->ClockPicture_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Restart_Button = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FlagPicture_PictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClockPicture_PictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Restart_Button))->BeginInit();
			this->SuspendLayout();
			// 
			// time_Timer
			// 
			this->time_Timer->Interval = 1000;
			this->time_Timer->Tick += gcnew System::EventHandler(this, &MinorForm::time_Timer_Tick);
			// 
			// Players_Time_Label
			// 
			this->Players_Time_Label->AutoSize = true;
			this->Players_Time_Label->BackColor = System::Drawing::Color::OliveDrab;
			this->Players_Time_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->Players_Time_Label->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->Players_Time_Label->Location = System::Drawing::Point(366, 29);
			this->Players_Time_Label->Name = L"Players_Time_Label";
			this->Players_Time_Label->Size = System::Drawing::Size(143, 38);
			this->Players_Time_Label->TabIndex = 3;
			this->Players_Time_Label->Text = L"0:00:00";
			// 
			// countOfFlags_Label
			// 
			this->countOfFlags_Label->AutoSize = true;
			this->countOfFlags_Label->BackColor = System::Drawing::Color::OliveDrab;
			this->countOfFlags_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->countOfFlags_Label->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->countOfFlags_Label->Location = System::Drawing::Point(144, 29);
			this->countOfFlags_Label->Name = L"countOfFlags_Label";
			this->countOfFlags_Label->Size = System::Drawing::Size(35, 38);
			this->countOfFlags_Label->TabIndex = 1;
			this->countOfFlags_Label->Text = L"0";
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::OliveDrab;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(667, 100);
			this->label1->TabIndex = 4;
			// 
			// FlagPicture_PictureBox
			// 
			this->FlagPicture_PictureBox->BackColor = System::Drawing::Color::OliveDrab;
			this->FlagPicture_PictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FlagPicture_PictureBox.Image")));
			this->FlagPicture_PictureBox->Location = System::Drawing::Point(10, 0);
			this->FlagPicture_PictureBox->Name = L"FlagPicture_PictureBox";
			this->FlagPicture_PictureBox->Size = System::Drawing::Size(100, 100);
			this->FlagPicture_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->FlagPicture_PictureBox->TabIndex = 5;
			this->FlagPicture_PictureBox->TabStop = false;
			// 
			// ClockPicture_PictureBox
			// 
			this->ClockPicture_PictureBox->BackColor = System::Drawing::Color::OliveDrab;
			this->ClockPicture_PictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ClockPicture_PictureBox.Image")));
			this->ClockPicture_PictureBox->Location = System::Drawing::Point(250, 0);
			this->ClockPicture_PictureBox->Name = L"ClockPicture_PictureBox";
			this->ClockPicture_PictureBox->Size = System::Drawing::Size(100, 100);
			this->ClockPicture_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ClockPicture_PictureBox->TabIndex = 6;
			this->ClockPicture_PictureBox->TabStop = false;
			// 
			// Restart_Button
			// 
			this->Restart_Button->BackColor = System::Drawing::Color::OliveDrab;
			this->Restart_Button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Restart_Button.Image")));
			this->Restart_Button->Location = System::Drawing::Point(582, 20);
			this->Restart_Button->Name = L"Restart_Button";
			this->Restart_Button->Size = System::Drawing::Size(60, 60);
			this->Restart_Button->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Restart_Button->TabIndex = 7;
			this->Restart_Button->TabStop = false;
			this->Restart_Button->Click += gcnew System::EventHandler(this, &MinorForm::Restart_Button_Click);
			// 
			// MinorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(828, 269);
			this->Controls->Add(this->Restart_Button);
			this->Controls->Add(this->ClockPicture_PictureBox);
			this->Controls->Add(this->FlagPicture_PictureBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->countOfFlags_Label);
			this->Controls->Add(this->Players_Time_Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MinorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Minor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FlagPicture_PictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClockPicture_PictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Restart_Button))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		array<PictureBox^, 2>^ Cells;
		bool LeftButtonDown;
		bool RightButtonDown;
		int timeInSeconds;
		int seconds;
		int minutes;
		int hours;
		bool isGameStarted;

	private: System::Void Cell_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (!isGameStarted)
		{
			isGameStarted = true;
			time_Timer->Start();
		}

		if (!game->gameOver)
		{
			PictureBox^ Cell = (PictureBox^)sender;
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				if (Cell->Text != "f")
				{
					int x = Cell->Left / 50;
					int y = (Cell->Top - 81) / 50;
					if (Cells[x, y]->Text != "opened" && Cells[x, y]->Text != "f")
					{
						OpenCell(x, y);
						if (game->countOfOpenedCells == game->countOfCellsThatNeedToOpen)
						{
							Win();
						}
					}
				}
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Right)
			{
				if (Cell->Text == "" && game->countOfFlags > 0)
				{
					Cell->Image = gcnew Bitmap("Flag.png");
					Cell->Text = "f";
					game->countOfFlags--;
					countOfFlags_Label->Text = game->countOfFlags.ToString();

				}
				else if (Cell->Text == "f")
				{
					Cell->Image = nullptr;
					Cell->Text = "";
					game->countOfFlags++;
					countOfFlags_Label->Text = game->countOfFlags.ToString();
				}
			}
		}
	}

	private:void OpenCell(int x, int y)
	{
		if (game->Pitch[y][x] == 0)
		{
			Cells[x, y]->Image = gcnew Bitmap("0.jpg");
			Cells[x, y]->Text = "opened";

			int minX = x == 0 ? 0 : x - 1;
			int minY = y == 0 ? 0 : y - 1;
			int maxX = x == game->heightOfPitch - 1 ? game->heightOfPitch - 1 : x + 1;
			int maxY = y == game->widthOfPitch - 1 ? game->widthOfPitch - 1 : y + 1;

			for (int i = minX; i <= maxX; i++)
			{
				for (int j = minY; j <= maxY; j++)
				{
					if (i != x)
					{
						if (Cells[i, j]->Text != "opened" && Cells[i, j]->Text != "f")
						{
							OpenCell(i, j);
						}
					}
					else
					{
						if (j != y)
						{
							if (Cells[i, j]->Text != "opened" && Cells[i, j]->Text != "f")
							{
								OpenCell(i, j);
							}
						}
					}
				}
			}
		}
		else
		{
			String^ filePath = game->Pitch[y][x].ToString() + ".jpg";
			Cells[x, y]->Image = gcnew Bitmap(filePath);

			Cells[x, y]->Text = "opened";
			if (game->Pitch[y][x] == 9)
			{
				GameOver();
			}
		}

		game->countOfOpenedCells++;
	}

	private:void GameOver()
	{
		time_Timer->Stop();

		game->gameOver = true;

		for (int i = 0; i < game->countOfBombs; i++)
		{
			int location = game->placesOfBombs[i];
			int x = location / (game->heightOfPitch);
			int y = location % (game->widthOfPitch);
			Cells[y, x]->Image = gcnew Bitmap("9.jpg");
		}
	}

	private:void Win()
	{
		time_Timer->Stop();

		PictureBox^ winLabel = gcnew PictureBox();
		winLabel->Name = "Cell";
		winLabel->Size = System::Drawing::Size((game->heightOfPitch - 2) * 50, (game->widthOfPitch - 2) * 50);
		winLabel->Location = System::Drawing::Point(50, 50 + 81);
		winLabel->Image = gcnew Bitmap("WinLabel.png");
		winLabel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;

		this->Controls->Add(winLabel);
		winLabel->BringToFront();

		for (int i = 0; i < game->heightOfPitch; i++)
		{
			for (int j = 0; j < game->widthOfPitch; j++)
			{
				Cells[i, j]->Image = nullptr;
				if ((i + j) % 2 == 0)
				{
					//Cells[i, j]->BackColor = System::Drawing::Color::FromArgb(164, 100, 0);
					
					//Cells[i, j]->BackColor = System::Drawing::Color::FromArgb(233, 252, 15);
					Cells[i, j]->BackColor = System::Drawing::Color::FromArgb(191, 191, 186);
				}
				else
				{
					//Cells[i, j]->BackColor = System::Drawing::Color::FromArgb(176, 254, 0);
					 
					//Cells[i, j]->BackColor = System::Drawing::Color::FromArgb(164, 100, 0);
					Cells[i, j]->BackColor = System::Drawing::Color::FromArgb(147, 148, 135);
				}
			}
		}
	}

	private: System::Void Cell_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			RightButtonDown = true;
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			LeftButtonDown = true;
		}
	}

	private: System::Void Cell_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		PictureBox^ Cell = (PictureBox^)sender;
		if (RightButtonDown && LeftButtonDown)
		{
			int x = Cell->Left / 50;
			int y = Cell->Top / 50;
			if (Cells[x, y]->Text == "opened")
			{
				int minX = x == 0 ? 0 : x - 1;
				int minY = y == 0 ? 0 : y - 1;
				int maxX = x == game->heightOfPitch - 1 ? game->heightOfPitch - 1 : x + 1;
				int maxY = y == game->widthOfPitch - 1 ? game->widthOfPitch - 1 : y + 1;

				for (int i = minX; i <= maxX; i++)
				{
					for (int j = minY; j <= maxY; j++)
					{
						if (i != x)
						{
							if (Cells[i, j]->Text != "opened" && Cells[i, j]->Text != "f")
							{
								OpenCell(i, j);
							}
						}
						else
						{
							if (j != y)
							{
								if (Cells[i, j]->Text != "opened" && Cells[i, j]->Text != "f")
								{
									OpenCell(i, j);
								}
							}
						}
					}
				}

				if (game->countOfOpenedCells == game->countOfCellsThatNeedToOpen)
				{
					Win();
				}
			}
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			RightButtonDown = false;
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			LeftButtonDown = false;
		}
	}

	private: System::Void time_Timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		timeInSeconds++;
		seconds = timeInSeconds % 50;
		minutes = timeInSeconds / 50;
		hours = timeInSeconds / 3500;
		if (seconds < 10)
		{
			if (minutes < 10)
			{
				Players_Time_Label->Text = hours.ToString() + ":0" + minutes.ToString() + ":0" + seconds.ToString();
			}
			else
			{
				Players_Time_Label->Text = hours.ToString() + ":" + minutes.ToString() + ":0" + seconds.ToString();
			}
		}
		else
		{
			if (minutes < 10)
			{
				Players_Time_Label->Text = hours.ToString() + ":0" + minutes.ToString() + ":" + seconds.ToString();
			}
			else
			{
				Players_Time_Label->Text = hours.ToString() + ":" + minutes.ToString() + ":" + seconds.ToString();
			}
		}
	}

	private: System::Void Restart_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		time_Timer->Stop();
		isGameStarted = false;
		timeInSeconds = 0;

		for (int i = 0; i < Controls->Count; i++)
		{
			if (Controls[i]->Name == "Cell")
			{
				delete Controls[i];
				i--;
			}
		}

		Players_Time_Label->Text = "0:00:00";


		game = new Game();

		countOfFlags_Label->Text = game->countOfFlags.ToString();

		int sizeOfCell = 50;
		Cells = gcnew array<PictureBox^, 2>(10, 10);
		for (int i = 0; i < game->heightOfPitch; i++)
		{
			for (int j = 0; j < game->widthOfPitch; j++)
			{
				PictureBox^ Cell = gcnew PictureBox();
				Cell->Name = "Cell";
				Cell->Size = System::Drawing::Size(sizeOfCell, sizeOfCell);
				Cell->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				Cell->Location = System::Drawing::Point(i * sizeOfCell, j * sizeOfCell + 100 - 19);
				Cell->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MinorForm::Cell_MouseClick);
				Cell->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MinorForm::Cell_MouseDown);
				Cell->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MinorForm::Cell_MouseUp);
				if ((i + j) % 2 == 0)
				{
					Cell->BackColor = System::Drawing::Color::Green;
				}
				else
				{
					Cell->BackColor = System::Drawing::Color::LightGreen;
				}
				Cells[i, j] = Cell;
				this->Controls->Add(Cell);
			}

			this->ClientSize = System::Drawing::Size(sizeOfCell * game->widthOfPitch, sizeOfCell * game->heightOfPitch + 100 - 19);
		}
	}
};
}