using System;
using System.IO.Ports;
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
    public partial class Form2 : Form
    {
        Form1 objForm1;
        string baud;
        string port;
        public Form2(Form1 obj, string baud, string port)
        {
            InitializeComponent();
            objForm1 = obj;
            this.baud = baud;
            this.port = port;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            objForm1.Show();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            try
            {
                serialPort1.BaudRate = Convert.ToInt32(baud);
                serialPort1.PortName = port;
                serialPort1.Open();
                while(serialPort1.IsOpen)
                {
                    string line = serialPort1.ReadLine();
                    float[] coord = coordinates(line);
                    e.Graphics.FillEllipse(Brushes.Black, coord[0], coord[1],3,3);
                }
                serialPort1.Close();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private float[] coordinates(string line)
        {
            try
            {
                string[] words = line.Split(' ');
                float x = float.Parse(words[0]);
                float y = float.Parse(words[1]);
                return new float[] { x, y };

            }
            catch(Exception ex)
            { 
                MessageBox.Show(ex.Message);
                return new float[] { -1, -1 };
            }

        }
    }
}
