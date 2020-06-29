using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Bitmap RotatingBlocks;
        Point DrawHere;
        Rectangle InvalidRect;
    
        public Form1()
        {
            InitializeComponent();
            RotatingBlocks = new Bitmap("C:\\programmers.gif");
            DrawHere = new Point(20, 20);
            InvalidRect = new Rectangle(DrawHere, RotatingBlocks.Size);

            this.SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer, true);
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            ImageAnimator.UpdateFrames(RotatingBlocks);
            e.Graphics.DrawImage(RotatingBlocks, DrawHere);
        }
        private void OnFrameChanged(object o, EventArgs e)
        {
            this.Invalidate(InvalidRect);
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            if(ImageAnimator.CanAnimate(RotatingBlocks))
            {
                ImageAnimator.Animate(RotatingBlocks, new EventHandler(this.OnFrameChanged));
            }
        }
        private void label1_Click(object sender, EventArgs e)
        { 
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.Hide();
            f.Show();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Form3 f = new Form3();
            f.Hide();
            f.Show();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
