using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace skaner
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length < 1 && textBox2.Text.Length < 1)
                MessageBox.Show("Enter port name and baud rate!", "Error", MessageBoxButtons.OK);
            else if (textBox2.Text.Length < 1)
                MessageBox.Show("Enter port name!", "Error", MessageBoxButtons.OK);
            else if (textBox1.Text.Length < 1)
                MessageBox.Show("Enter baud rate!", "Error", MessageBoxButtons.OK);
            else
            {
                Form2 form2 = new Form2(this,textBox1.Text,textBox2.Text);
                form2.Show();
                this.Hide();
            }
        }
        
    }
}
