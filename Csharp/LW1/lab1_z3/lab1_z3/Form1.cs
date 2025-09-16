using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
// Remove or comment out the following line if 'MyModels' namespace does not exist or is not needed
// using MyModels;

namespace lab1_z3
{
    public partial class Monkey_Music : Form
    {
        private List<Guitar> guitars = new List<Guitar>(); // список у магазині

        public Monkey_Music()
        {
            InitializeComponent();

            // події меню
            mainToolStripMenuItem.Click += MainToolStripMenuItem_Click;
            adminToolStripMenuItem.Click += AdminToolStripMenuItem_Click;
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            panel1.Visible = false; // ховаємо адмінку

            // початковий список з 20 гітар
            guitars = new List<Guitar>
            {
                new Guitar { Marka="Fender", Model="Stratocaster", Kolir="Black", RikVypusku=2020, Tsina=1500, Status="В наявності"},
                new Guitar { Marka="Gibson", Model="Les Paul", Kolir="Sunburst", RikVypusku=2019, Tsina=2500, Status="Готові до відправки"},
                new Guitar { Marka="Ibanez", Model="RG", Kolir="White", RikVypusku=2021, Tsina=1200, Status="В наявності"},
                new Guitar { Marka="Yamaha", Model="Pacifica", Kolir="Black", RikVypusku=2018, Tsina=2000, Status = "В наявності"}
                // ... додаєш ще до 20 шт.
            };

            dataGridView1.DataSource = guitars;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dataGridView2.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;


            Button btnFilter = new Button { Text = "Фільтр", Location = new System.Drawing.Point(200, 580) };
            btnFilter.Click += BtnFilter_Click;
            this.Controls.Add(btnFilter);


            SetMode("main");
        }

        // Додавання нової гітари (доступно лише в Admin)
        private void BtnAdd_Click(object? sender, EventArgs e)
        {
            if (!adminToolStripMenuItem.Checked)
            {
                MessageBox.Show("Додавати нові позиції можна тільки в режимі Admin!");
                return;
            }

            // Перевірка на порожні значення
            if (string.IsNullOrWhiteSpace(textBox10.Text) ||
                string.IsNullOrWhiteSpace(textBox9.Text) ||
                string.IsNullOrWhiteSpace(textBox8.Text) ||
                string.IsNullOrWhiteSpace(textBox7.Text) ||
                string.IsNullOrWhiteSpace(textBox6.Text))
            {
                MessageBox.Show("Будь ласка, заповніть усі поля для додавання гітари.");
                return;
            }

            // Перевірка правильності числових значень
            if (!int.TryParse(textBox7.Text, out int rik))
            {
                MessageBox.Show("Рік випуску має бути цілим числом.");
                return;
            }
            if (!decimal.TryParse(textBox6.Text, out decimal tsina))
            {
                MessageBox.Show("Ціна має бути числом.");
                return;
            }

            var guitar = new Guitar()
            {
                Marka = comboBox1.Text,
                Model = comboBox2.Text,
                Kolir = comboBox3.Text,
                RikVypusku = rik,
                Tsina = tsina,
                Status = radioButton1.Checked ? "В наявності" :
                         radioButton2.Checked ? "Готові до відправки" : "Невідомо"
            };

            guitars.Add(guitar);

            dataGridView1.DataSource = null;
            dataGridView1.DataSource = guitars;

            dataGridView3.DataSource = null;
            dataGridView3.DataSource = guitars;
            MessageBox.Show("Нову гітару додано!");
        }

        // Фільтрація списку
        private void BtnFilter_Click(object? sender, EventArgs e)
        {
            var filtered = guitars.Where(g =>
                (string.IsNullOrEmpty(comboBox1.Text) || g.Marka.Contains(comboBox1.Text, StringComparison.OrdinalIgnoreCase)) &&
                (string.IsNullOrEmpty(comboBox2.Text) || g.Model.Contains(comboBox2.Text, StringComparison.OrdinalIgnoreCase)) &&
                (string.IsNullOrEmpty(comboBox3.Text) || g.Kolir.Contains(comboBox3.Text, StringComparison.OrdinalIgnoreCase)) &&
                (string.IsNullOrEmpty(comboBox4.Text) || g.RikVypusku.ToString() == comboBox4.Text) &&
                (string.IsNullOrEmpty(textBox5.Text) || g.Tsina <= Convert.ToDecimal(textBox5.Text)) &&
                ((radioButton1.Checked && g.Status == "В наявності") ||
                 (radioButton2.Checked && g.Status == "Готові до відправки") ||
                 (!radioButton1.Checked && !radioButton2.Checked))
            ).ToList();

            dataGridView2.DataSource = null;
            dataGridView2.DataSource = filtered;
        }
        private void ShowMainControls(bool visible)
        {
            comboBox1.Visible = visible;
            comboBox2.Visible = visible;
            comboBox3.Visible = visible;
            comboBox4.Visible = visible;
            textBox5.Visible = visible;
            radioButton1.Visible = visible;
            radioButton2.Visible = visible;
            dataGridView1.Visible = visible;
            dataGridView2.Visible = visible;
            label1.Visible = visible;
            label2.Visible = visible;
            label3.Visible = visible;
            label4.Visible = visible;
            label5.Visible = visible;
            label6.Visible = visible;
            button1.Visible = visible;
        }


        // Перемикання режимів меню
        private void MainToolStripMenuItem_Click(object? sender, EventArgs e)
        {
            panel1.Visible = false;
            ShowMainControls(true);

            SetMode("main");
        }

        private void AdminToolStripMenuItem_Click(object? sender, EventArgs e)
        {
            panel1.Visible = true;
            ShowMainControls(false);

            SetMode("admin");

            // приєднуємо подію тільки один раз
            button2.Click -= BtnAdd_Click;
            button2.Click += BtnAdd_Click;
            button2.Visible = true;
            MessageBox.Show("Ви в режимі Admin. Тепер ви можете додавати нові позиції.");
        }

        private void SetMode(string mode)
        {
            if (mode == "main")
            {
                mainToolStripMenuItem.Checked = true;
                adminToolStripMenuItem.Checked = false;
                // у Main доступна тільки фільтрація
            }
            else
            {
                mainToolStripMenuItem.Checked = false;
                adminToolStripMenuItem.Checked = true;
                // у Admin можна додавати гітари
            }
        }

    }
}
