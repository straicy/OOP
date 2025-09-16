using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1_z3
{
    public class Guitar
    {
        public string Marka { get; set; }
        public string Model { get; set; }
        public string Kolir { get; set; }
        public int RikVypusku { get; set; }
        public decimal Tsina { get; set; }
        public string Status { get; set; } // В наявності / Готові до відправки
    }
}
