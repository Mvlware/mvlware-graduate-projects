using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Math;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        private void Form2_Load(object sender, EventArgs e)
        {
        }
        private void DoubleDigittextBox_1KeyPress_1(object sender, KeyPressEventArgs e)
        {
            TextBox cc = (TextBox)sender;
            bool TZFound = false; //знак разделителя найден
            String TorZ = System.Globalization.NumberFormatInfo.CurrentInfo.NumberDecimalSeparator;
            if (Char.IsDigit(e.KeyChar) == true) return;
            if ((e.KeyChar) == (char)Keys.Back) return;
            if (cc.Text.IndexOf(TorZ) != -1) TZFound = true;
            if (TZFound == true)
            {
                e.Handled = true;
                return;
            }
            if (e.KeyChar.ToString() == TorZ) return;
            e.Handled = true;
        }
        private void DoubleDigittextBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            TextBox cc = (TextBox)sender;
            bool TZFound = false; //знак разделителя найден
            String TorZ = System.Globalization.NumberFormatInfo.CurrentInfo.NumberDecimalSeparator;
            if (Char.IsDigit(e.KeyChar) == true) return;
            if ((e.KeyChar) == (char)Keys.Back) return;
            if (cc.Text.IndexOf(TorZ) != -1) TZFound = true;
            if (TZFound == true)
            {
                e.Handled = true;
                return;
            }
            if (e.KeyChar.ToString() == TorZ) return;
            e.Handled = true;
        }
        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar))
                e.Handled = true;
        }
        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar))
                e.Handled = true;
        }
        private void button4_Click(object sender, EventArgs e)
        {
            string i, f, r;
            i = textBox1.Text;
            f = textBox2.Text;
            r = textBox4.Text;
            if (i == "" && f == "" && r == "")
            {
                MessageBox.Show("Введите значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                MessageBox.Show("x=" + i + " n=" + f + "\nПо формуле разложения степенной ряд Ai(x)= " + r + "\nПо формуле разложения степенной рял Bi(x) = ", "Отчет", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
        private void button2_Click_1(object sender, EventArgs e)
        {
            string i, f, r, t;
            i = textBox1.Text;
            f = textBox2.Text;
            t = textBox3.Text;
            r = textBox4.Text;
            if (i == "" || f == "" || r == "" || t == "")
            {
                MessageBox.Show("Значения отсутствуют!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
                textBox4.Text = "";
            }
        }
        private void button3_Click_1(object sender, EventArgs e)
        {
            string i, f, r, t;
            i = textBox1.Text;
            f = textBox2.Text;
            t = textBox3.Text;
            r = textBox4.Text;
            if (i == "" || f == "" || r == "" || t == "")
            {
                MessageBox.Show("Введите значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                MessageBox.Show("x = " + i + " e = " + f + "\nПо формуле разложения степенной ряд Ai(x) = " + r + "\nПо формуле разложения степенной ряд Bi(x) = " + t, "Отчет", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
        private void buttonback_Click(object sender, EventArgs e)
        {
            Application.OpenForms[0].Show();
            Application.OpenForms[1].Hide();
        }
        private void button5_Click(object sender, EventArgs e)
        {
            string i, f, r, t;
            i = textBox1.Text;
            f = textBox2.Text;
            t = textBox3.Text;
            r = textBox4.Text;
            FileInfo file = new FileInfo("result.txt");
            if (i == "" || f == "" || r == "" || t == "") //Если значения отсутствуют
            {
                MessageBox.Show("Значения отсутствуют!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else if (file.Exists == false) //Если файл не существует
            {
                file.Create(); //Создаем
                StreamWriter write_text;  //Класс для записи в файл
                write_text = file.CreateText();//.AppendText(); //Дописываем инфу в файл, если файла не существует он создастся
                write_text.WriteLine(textBox1.Text);
                write_text.WriteLine(textBox2.Text);
                write_text.WriteLine(textBox3.Text);
                write_text.WriteLine(textBox4.Text); //Записываем в файл текст из текстового поля
                write_text.Close(); // Закрываем файл
                MessageBox.Show("Результат сохранен!", "Информация", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Результат сохранен!", "Информация", MessageBoxButtons.OK, MessageBoxIcon.Information);
                StreamWriter write_text;  //Класс для записи в файл
                write_text = file.CreateText();//.AppendText(); //Дописываем инфу в файл, если файла не существует он создастся
                write_text.WriteLine(textBox1.Text);
                write_text.WriteLine(textBox2.Text);
                write_text.WriteLine(textBox3.Text);
                write_text.WriteLine(textBox4.Text); //Записываем в файл текст из текстового поля
                write_text.Close(); // Закрываем файл
            }
            }
        private void button3_Click(object sender, EventArgs e)
        {
            FileInfo file = new FileInfo("result.txt");
            if (file.Exists == true) //Если файл существует
            {
                StreamReader streamReader = new StreamReader("result.txt"); //Открываем файл для чтения
                string str = ""; //Объявляем переменную, в которую будем записывать текст из файла

                TextBox[] textMas = new TextBox[] { textBox1, textBox2, textBox3, textBox4 };

                int i = 0;
                while (!streamReader.EndOfStream) //Цикл длиться пока не будет достигнут конец файла
                {
                    str = streamReader.ReadLine(); //В переменную str по строчно записываем содержимое файла
                    textMas[i].Text = str;
                    i++;
                }
                streamReader.Close();
            }
            else MessageBox.Show("Файла не существует!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
        private void button6_Click(object sender, EventArgs e)
        {
            FileInfo file = new FileInfo("result.txt");
            if (file.Exists == true) //Если файл существует
            {
                file.Delete(); //Удаляем
            }
            else MessageBox.Show("Файла не существует!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
        private void label3_Click_1(object sender, EventArgs e)
        {
        }
        private void button11_Click(object sender, EventArgs e)
        {
            string p, p1;
            double x, eps, a, b;
            p = textBox1.Text;
            p1 = textBox2.Text;
            if (p == "" && p1 == "")
            {
                MessageBox.Show("Введите значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                x = System.Convert.ToDouble(textBox1.Text);
                eps = System.Convert.ToDouble(textBox2.Text);
                double i = 0, f = 1, k = 1, j = 1, r = 1;
                double l = x * x * x;
                label: i = i + 3;
                k = k * l * j;
                double m = f;
                r = r * i * (i - 1) * (i - 2);
                f = f + k / r;
                j = j + 3;
                if (Abs(f - m) > eps)
                {
                    goto label;
                }
                else
                {
                    i = 1;
                    double g = 1;
                    k = 1;
                    r = 1;
                    label2: i = i + 3;
                    k = k * (i - 2) * l;
                    m = g;
                    r = r * i * (i - 2) * (i - 1);
                    g = g + k / r;
                    if (Abs(g - m) > eps)
                    {
                        goto label2;
                    }
                    else
                    {
                        g = g * x;
                        double c = .355028054;
                        double d = .258819404;
                        a = c * f - d * g;
                        b = (c * f + d * g) * Sqrt(3);
                    }
                }
                textBox4.Text = System.Convert.ToString(a);
                textBox3.Text = System.Convert.ToString(b);
            }
        }
        private void button8_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
