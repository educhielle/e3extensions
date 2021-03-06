unsigned Unumber::HW_NUMWORDS = 64;

void Unumber::mfer_e0(unsigned m[])
{
	__asm__ ("le3.mfer %0,ye0(0)" : "=r"(m[63]));
	__asm__ ("le3.mfer %0,ye0(1)" : "=r"(m[62]));
	__asm__ ("le3.mfer %0,ye0(2)" : "=r"(m[61]));
	__asm__ ("le3.mfer %0,ye0(3)" : "=r"(m[60]));
	__asm__ ("le3.mfer %0,ye0(4)" : "=r"(m[59]));
	__asm__ ("le3.mfer %0,ye0(5)" : "=r"(m[58]));
	__asm__ ("le3.mfer %0,ye0(6)" : "=r"(m[57]));
	__asm__ ("le3.mfer %0,ye0(7)" : "=r"(m[56]));
	__asm__ ("le3.mfer %0,ye0(8)" : "=r"(m[55]));
	__asm__ ("le3.mfer %0,ye0(9)" : "=r"(m[54]));
	__asm__ ("le3.mfer %0,ye0(10)" : "=r"(m[53]));
	__asm__ ("le3.mfer %0,ye0(11)" : "=r"(m[52]));
	__asm__ ("le3.mfer %0,ye0(12)" : "=r"(m[51]));
	__asm__ ("le3.mfer %0,ye0(13)" : "=r"(m[50]));
	__asm__ ("le3.mfer %0,ye0(14)" : "=r"(m[49]));
	__asm__ ("le3.mfer %0,ye0(15)" : "=r"(m[48]));
	__asm__ ("le3.mfer %0,ye0(16)" : "=r"(m[47]));
	__asm__ ("le3.mfer %0,ye0(17)" : "=r"(m[46]));
	__asm__ ("le3.mfer %0,ye0(18)" : "=r"(m[45]));
	__asm__ ("le3.mfer %0,ye0(19)" : "=r"(m[44]));
	__asm__ ("le3.mfer %0,ye0(20)" : "=r"(m[43]));
	__asm__ ("le3.mfer %0,ye0(21)" : "=r"(m[42]));
	__asm__ ("le3.mfer %0,ye0(22)" : "=r"(m[41]));
	__asm__ ("le3.mfer %0,ye0(23)" : "=r"(m[40]));
	__asm__ ("le3.mfer %0,ye0(24)" : "=r"(m[39]));
	__asm__ ("le3.mfer %0,ye0(25)" : "=r"(m[38]));
	__asm__ ("le3.mfer %0,ye0(26)" : "=r"(m[37]));
	__asm__ ("le3.mfer %0,ye0(27)" : "=r"(m[36]));
	__asm__ ("le3.mfer %0,ye0(28)" : "=r"(m[35]));
	__asm__ ("le3.mfer %0,ye0(29)" : "=r"(m[34]));
	__asm__ ("le3.mfer %0,ye0(30)" : "=r"(m[33]));
	__asm__ ("le3.mfer %0,ye0(31)" : "=r"(m[32]));
	__asm__ ("le3.mfer %0,ye0(32)" : "=r"(m[31]));
	__asm__ ("le3.mfer %0,ye0(33)" : "=r"(m[30]));
	__asm__ ("le3.mfer %0,ye0(34)" : "=r"(m[29]));
	__asm__ ("le3.mfer %0,ye0(35)" : "=r"(m[28]));
	__asm__ ("le3.mfer %0,ye0(36)" : "=r"(m[27]));
	__asm__ ("le3.mfer %0,ye0(37)" : "=r"(m[26]));
	__asm__ ("le3.mfer %0,ye0(38)" : "=r"(m[25]));
	__asm__ ("le3.mfer %0,ye0(39)" : "=r"(m[24]));
	__asm__ ("le3.mfer %0,ye0(40)" : "=r"(m[23]));
	__asm__ ("le3.mfer %0,ye0(41)" : "=r"(m[22]));
	__asm__ ("le3.mfer %0,ye0(42)" : "=r"(m[21]));
	__asm__ ("le3.mfer %0,ye0(43)" : "=r"(m[20]));
	__asm__ ("le3.mfer %0,ye0(44)" : "=r"(m[19]));
	__asm__ ("le3.mfer %0,ye0(45)" : "=r"(m[18]));
	__asm__ ("le3.mfer %0,ye0(46)" : "=r"(m[17]));
	__asm__ ("le3.mfer %0,ye0(47)" : "=r"(m[16]));
	__asm__ ("le3.mfer %0,ye0(48)" : "=r"(m[15]));
	__asm__ ("le3.mfer %0,ye0(49)" : "=r"(m[14]));
	__asm__ ("le3.mfer %0,ye0(50)" : "=r"(m[13]));
	__asm__ ("le3.mfer %0,ye0(51)" : "=r"(m[12]));
	__asm__ ("le3.mfer %0,ye0(52)" : "=r"(m[11]));
	__asm__ ("le3.mfer %0,ye0(53)" : "=r"(m[10]));
	__asm__ ("le3.mfer %0,ye0(54)" : "=r"(m[9]));
	__asm__ ("le3.mfer %0,ye0(55)" : "=r"(m[8]));
	__asm__ ("le3.mfer %0,ye0(56)" : "=r"(m[7]));
	__asm__ ("le3.mfer %0,ye0(57)" : "=r"(m[6]));
	__asm__ ("le3.mfer %0,ye0(58)" : "=r"(m[5]));
	__asm__ ("le3.mfer %0,ye0(59)" : "=r"(m[4]));
	__asm__ ("le3.mfer %0,ye0(60)" : "=r"(m[3]));
	__asm__ ("le3.mfer %0,ye0(61)" : "=r"(m[2]));
	__asm__ ("le3.mfer %0,ye0(62)" : "=r"(m[1]));
	__asm__ ("le3.mfer %0,ye0(63)" : "=r"(m[0]));
}

void Unumber::mfer_e1(unsigned m[])
{
	__asm__ ("le3.mfer %0,ye1(0)" : "=r"(m[63]));
	__asm__ ("le3.mfer %0,ye1(1)" : "=r"(m[62]));
	__asm__ ("le3.mfer %0,ye1(2)" : "=r"(m[61]));
	__asm__ ("le3.mfer %0,ye1(3)" : "=r"(m[60]));
	__asm__ ("le3.mfer %0,ye1(4)" : "=r"(m[59]));
	__asm__ ("le3.mfer %0,ye1(5)" : "=r"(m[58]));
	__asm__ ("le3.mfer %0,ye1(6)" : "=r"(m[57]));
	__asm__ ("le3.mfer %0,ye1(7)" : "=r"(m[56]));
	__asm__ ("le3.mfer %0,ye1(8)" : "=r"(m[55]));
	__asm__ ("le3.mfer %0,ye1(9)" : "=r"(m[54]));
	__asm__ ("le3.mfer %0,ye1(10)" : "=r"(m[53]));
	__asm__ ("le3.mfer %0,ye1(11)" : "=r"(m[52]));
	__asm__ ("le3.mfer %0,ye1(12)" : "=r"(m[51]));
	__asm__ ("le3.mfer %0,ye1(13)" : "=r"(m[50]));
	__asm__ ("le3.mfer %0,ye1(14)" : "=r"(m[49]));
	__asm__ ("le3.mfer %0,ye1(15)" : "=r"(m[48]));
	__asm__ ("le3.mfer %0,ye1(16)" : "=r"(m[47]));
	__asm__ ("le3.mfer %0,ye1(17)" : "=r"(m[46]));
	__asm__ ("le3.mfer %0,ye1(18)" : "=r"(m[45]));
	__asm__ ("le3.mfer %0,ye1(19)" : "=r"(m[44]));
	__asm__ ("le3.mfer %0,ye1(20)" : "=r"(m[43]));
	__asm__ ("le3.mfer %0,ye1(21)" : "=r"(m[42]));
	__asm__ ("le3.mfer %0,ye1(22)" : "=r"(m[41]));
	__asm__ ("le3.mfer %0,ye1(23)" : "=r"(m[40]));
	__asm__ ("le3.mfer %0,ye1(24)" : "=r"(m[39]));
	__asm__ ("le3.mfer %0,ye1(25)" : "=r"(m[38]));
	__asm__ ("le3.mfer %0,ye1(26)" : "=r"(m[37]));
	__asm__ ("le3.mfer %0,ye1(27)" : "=r"(m[36]));
	__asm__ ("le3.mfer %0,ye1(28)" : "=r"(m[35]));
	__asm__ ("le3.mfer %0,ye1(29)" : "=r"(m[34]));
	__asm__ ("le3.mfer %0,ye1(30)" : "=r"(m[33]));
	__asm__ ("le3.mfer %0,ye1(31)" : "=r"(m[32]));
	__asm__ ("le3.mfer %0,ye1(32)" : "=r"(m[31]));
	__asm__ ("le3.mfer %0,ye1(33)" : "=r"(m[30]));
	__asm__ ("le3.mfer %0,ye1(34)" : "=r"(m[29]));
	__asm__ ("le3.mfer %0,ye1(35)" : "=r"(m[28]));
	__asm__ ("le3.mfer %0,ye1(36)" : "=r"(m[27]));
	__asm__ ("le3.mfer %0,ye1(37)" : "=r"(m[26]));
	__asm__ ("le3.mfer %0,ye1(38)" : "=r"(m[25]));
	__asm__ ("le3.mfer %0,ye1(39)" : "=r"(m[24]));
	__asm__ ("le3.mfer %0,ye1(40)" : "=r"(m[23]));
	__asm__ ("le3.mfer %0,ye1(41)" : "=r"(m[22]));
	__asm__ ("le3.mfer %0,ye1(42)" : "=r"(m[21]));
	__asm__ ("le3.mfer %0,ye1(43)" : "=r"(m[20]));
	__asm__ ("le3.mfer %0,ye1(44)" : "=r"(m[19]));
	__asm__ ("le3.mfer %0,ye1(45)" : "=r"(m[18]));
	__asm__ ("le3.mfer %0,ye1(46)" : "=r"(m[17]));
	__asm__ ("le3.mfer %0,ye1(47)" : "=r"(m[16]));
	__asm__ ("le3.mfer %0,ye1(48)" : "=r"(m[15]));
	__asm__ ("le3.mfer %0,ye1(49)" : "=r"(m[14]));
	__asm__ ("le3.mfer %0,ye1(50)" : "=r"(m[13]));
	__asm__ ("le3.mfer %0,ye1(51)" : "=r"(m[12]));
	__asm__ ("le3.mfer %0,ye1(52)" : "=r"(m[11]));
	__asm__ ("le3.mfer %0,ye1(53)" : "=r"(m[10]));
	__asm__ ("le3.mfer %0,ye1(54)" : "=r"(m[9]));
	__asm__ ("le3.mfer %0,ye1(55)" : "=r"(m[8]));
	__asm__ ("le3.mfer %0,ye1(56)" : "=r"(m[7]));
	__asm__ ("le3.mfer %0,ye1(57)" : "=r"(m[6]));
	__asm__ ("le3.mfer %0,ye1(58)" : "=r"(m[5]));
	__asm__ ("le3.mfer %0,ye1(59)" : "=r"(m[4]));
	__asm__ ("le3.mfer %0,ye1(60)" : "=r"(m[3]));
	__asm__ ("le3.mfer %0,ye1(61)" : "=r"(m[2]));
	__asm__ ("le3.mfer %0,ye1(62)" : "=r"(m[1]));
	__asm__ ("le3.mfer %0,ye1(63)" : "=r"(m[0]));
}

void Unumber::mfer_e2(unsigned m[])
{
	__asm__ ("le3.mfer %0,ye2(0)" : "=r"(m[63]));
	__asm__ ("le3.mfer %0,ye2(1)" : "=r"(m[62]));
	__asm__ ("le3.mfer %0,ye2(2)" : "=r"(m[61]));
	__asm__ ("le3.mfer %0,ye2(3)" : "=r"(m[60]));
	__asm__ ("le3.mfer %0,ye2(4)" : "=r"(m[59]));
	__asm__ ("le3.mfer %0,ye2(5)" : "=r"(m[58]));
	__asm__ ("le3.mfer %0,ye2(6)" : "=r"(m[57]));
	__asm__ ("le3.mfer %0,ye2(7)" : "=r"(m[56]));
	__asm__ ("le3.mfer %0,ye2(8)" : "=r"(m[55]));
	__asm__ ("le3.mfer %0,ye2(9)" : "=r"(m[54]));
	__asm__ ("le3.mfer %0,ye2(10)" : "=r"(m[53]));
	__asm__ ("le3.mfer %0,ye2(11)" : "=r"(m[52]));
	__asm__ ("le3.mfer %0,ye2(12)" : "=r"(m[51]));
	__asm__ ("le3.mfer %0,ye2(13)" : "=r"(m[50]));
	__asm__ ("le3.mfer %0,ye2(14)" : "=r"(m[49]));
	__asm__ ("le3.mfer %0,ye2(15)" : "=r"(m[48]));
	__asm__ ("le3.mfer %0,ye2(16)" : "=r"(m[47]));
	__asm__ ("le3.mfer %0,ye2(17)" : "=r"(m[46]));
	__asm__ ("le3.mfer %0,ye2(18)" : "=r"(m[45]));
	__asm__ ("le3.mfer %0,ye2(19)" : "=r"(m[44]));
	__asm__ ("le3.mfer %0,ye2(20)" : "=r"(m[43]));
	__asm__ ("le3.mfer %0,ye2(21)" : "=r"(m[42]));
	__asm__ ("le3.mfer %0,ye2(22)" : "=r"(m[41]));
	__asm__ ("le3.mfer %0,ye2(23)" : "=r"(m[40]));
	__asm__ ("le3.mfer %0,ye2(24)" : "=r"(m[39]));
	__asm__ ("le3.mfer %0,ye2(25)" : "=r"(m[38]));
	__asm__ ("le3.mfer %0,ye2(26)" : "=r"(m[37]));
	__asm__ ("le3.mfer %0,ye2(27)" : "=r"(m[36]));
	__asm__ ("le3.mfer %0,ye2(28)" : "=r"(m[35]));
	__asm__ ("le3.mfer %0,ye2(29)" : "=r"(m[34]));
	__asm__ ("le3.mfer %0,ye2(30)" : "=r"(m[33]));
	__asm__ ("le3.mfer %0,ye2(31)" : "=r"(m[32]));
	__asm__ ("le3.mfer %0,ye2(32)" : "=r"(m[31]));
	__asm__ ("le3.mfer %0,ye2(33)" : "=r"(m[30]));
	__asm__ ("le3.mfer %0,ye2(34)" : "=r"(m[29]));
	__asm__ ("le3.mfer %0,ye2(35)" : "=r"(m[28]));
	__asm__ ("le3.mfer %0,ye2(36)" : "=r"(m[27]));
	__asm__ ("le3.mfer %0,ye2(37)" : "=r"(m[26]));
	__asm__ ("le3.mfer %0,ye2(38)" : "=r"(m[25]));
	__asm__ ("le3.mfer %0,ye2(39)" : "=r"(m[24]));
	__asm__ ("le3.mfer %0,ye2(40)" : "=r"(m[23]));
	__asm__ ("le3.mfer %0,ye2(41)" : "=r"(m[22]));
	__asm__ ("le3.mfer %0,ye2(42)" : "=r"(m[21]));
	__asm__ ("le3.mfer %0,ye2(43)" : "=r"(m[20]));
	__asm__ ("le3.mfer %0,ye2(44)" : "=r"(m[19]));
	__asm__ ("le3.mfer %0,ye2(45)" : "=r"(m[18]));
	__asm__ ("le3.mfer %0,ye2(46)" : "=r"(m[17]));
	__asm__ ("le3.mfer %0,ye2(47)" : "=r"(m[16]));
	__asm__ ("le3.mfer %0,ye2(48)" : "=r"(m[15]));
	__asm__ ("le3.mfer %0,ye2(49)" : "=r"(m[14]));
	__asm__ ("le3.mfer %0,ye2(50)" : "=r"(m[13]));
	__asm__ ("le3.mfer %0,ye2(51)" : "=r"(m[12]));
	__asm__ ("le3.mfer %0,ye2(52)" : "=r"(m[11]));
	__asm__ ("le3.mfer %0,ye2(53)" : "=r"(m[10]));
	__asm__ ("le3.mfer %0,ye2(54)" : "=r"(m[9]));
	__asm__ ("le3.mfer %0,ye2(55)" : "=r"(m[8]));
	__asm__ ("le3.mfer %0,ye2(56)" : "=r"(m[7]));
	__asm__ ("le3.mfer %0,ye2(57)" : "=r"(m[6]));
	__asm__ ("le3.mfer %0,ye2(58)" : "=r"(m[5]));
	__asm__ ("le3.mfer %0,ye2(59)" : "=r"(m[4]));
	__asm__ ("le3.mfer %0,ye2(60)" : "=r"(m[3]));
	__asm__ ("le3.mfer %0,ye2(61)" : "=r"(m[2]));
	__asm__ ("le3.mfer %0,ye2(62)" : "=r"(m[1]));
	__asm__ ("le3.mfer %0,ye2(63)" : "=r"(m[0]));
}

void Unumber::mfer_e3(unsigned m[])
{
	__asm__ ("le3.mfer %0,ye3(0)" : "=r"(m[63]));
	__asm__ ("le3.mfer %0,ye3(1)" : "=r"(m[62]));
	__asm__ ("le3.mfer %0,ye3(2)" : "=r"(m[61]));
	__asm__ ("le3.mfer %0,ye3(3)" : "=r"(m[60]));
	__asm__ ("le3.mfer %0,ye3(4)" : "=r"(m[59]));
	__asm__ ("le3.mfer %0,ye3(5)" : "=r"(m[58]));
	__asm__ ("le3.mfer %0,ye3(6)" : "=r"(m[57]));
	__asm__ ("le3.mfer %0,ye3(7)" : "=r"(m[56]));
	__asm__ ("le3.mfer %0,ye3(8)" : "=r"(m[55]));
	__asm__ ("le3.mfer %0,ye3(9)" : "=r"(m[54]));
	__asm__ ("le3.mfer %0,ye3(10)" : "=r"(m[53]));
	__asm__ ("le3.mfer %0,ye3(11)" : "=r"(m[52]));
	__asm__ ("le3.mfer %0,ye3(12)" : "=r"(m[51]));
	__asm__ ("le3.mfer %0,ye3(13)" : "=r"(m[50]));
	__asm__ ("le3.mfer %0,ye3(14)" : "=r"(m[49]));
	__asm__ ("le3.mfer %0,ye3(15)" : "=r"(m[48]));
	__asm__ ("le3.mfer %0,ye3(16)" : "=r"(m[47]));
	__asm__ ("le3.mfer %0,ye3(17)" : "=r"(m[46]));
	__asm__ ("le3.mfer %0,ye3(18)" : "=r"(m[45]));
	__asm__ ("le3.mfer %0,ye3(19)" : "=r"(m[44]));
	__asm__ ("le3.mfer %0,ye3(20)" : "=r"(m[43]));
	__asm__ ("le3.mfer %0,ye3(21)" : "=r"(m[42]));
	__asm__ ("le3.mfer %0,ye3(22)" : "=r"(m[41]));
	__asm__ ("le3.mfer %0,ye3(23)" : "=r"(m[40]));
	__asm__ ("le3.mfer %0,ye3(24)" : "=r"(m[39]));
	__asm__ ("le3.mfer %0,ye3(25)" : "=r"(m[38]));
	__asm__ ("le3.mfer %0,ye3(26)" : "=r"(m[37]));
	__asm__ ("le3.mfer %0,ye3(27)" : "=r"(m[36]));
	__asm__ ("le3.mfer %0,ye3(28)" : "=r"(m[35]));
	__asm__ ("le3.mfer %0,ye3(29)" : "=r"(m[34]));
	__asm__ ("le3.mfer %0,ye3(30)" : "=r"(m[33]));
	__asm__ ("le3.mfer %0,ye3(31)" : "=r"(m[32]));
	__asm__ ("le3.mfer %0,ye3(32)" : "=r"(m[31]));
	__asm__ ("le3.mfer %0,ye3(33)" : "=r"(m[30]));
	__asm__ ("le3.mfer %0,ye3(34)" : "=r"(m[29]));
	__asm__ ("le3.mfer %0,ye3(35)" : "=r"(m[28]));
	__asm__ ("le3.mfer %0,ye3(36)" : "=r"(m[27]));
	__asm__ ("le3.mfer %0,ye3(37)" : "=r"(m[26]));
	__asm__ ("le3.mfer %0,ye3(38)" : "=r"(m[25]));
	__asm__ ("le3.mfer %0,ye3(39)" : "=r"(m[24]));
	__asm__ ("le3.mfer %0,ye3(40)" : "=r"(m[23]));
	__asm__ ("le3.mfer %0,ye3(41)" : "=r"(m[22]));
	__asm__ ("le3.mfer %0,ye3(42)" : "=r"(m[21]));
	__asm__ ("le3.mfer %0,ye3(43)" : "=r"(m[20]));
	__asm__ ("le3.mfer %0,ye3(44)" : "=r"(m[19]));
	__asm__ ("le3.mfer %0,ye3(45)" : "=r"(m[18]));
	__asm__ ("le3.mfer %0,ye3(46)" : "=r"(m[17]));
	__asm__ ("le3.mfer %0,ye3(47)" : "=r"(m[16]));
	__asm__ ("le3.mfer %0,ye3(48)" : "=r"(m[15]));
	__asm__ ("le3.mfer %0,ye3(49)" : "=r"(m[14]));
	__asm__ ("le3.mfer %0,ye3(50)" : "=r"(m[13]));
	__asm__ ("le3.mfer %0,ye3(51)" : "=r"(m[12]));
	__asm__ ("le3.mfer %0,ye3(52)" : "=r"(m[11]));
	__asm__ ("le3.mfer %0,ye3(53)" : "=r"(m[10]));
	__asm__ ("le3.mfer %0,ye3(54)" : "=r"(m[9]));
	__asm__ ("le3.mfer %0,ye3(55)" : "=r"(m[8]));
	__asm__ ("le3.mfer %0,ye3(56)" : "=r"(m[7]));
	__asm__ ("le3.mfer %0,ye3(57)" : "=r"(m[6]));
	__asm__ ("le3.mfer %0,ye3(58)" : "=r"(m[5]));
	__asm__ ("le3.mfer %0,ye3(59)" : "=r"(m[4]));
	__asm__ ("le3.mfer %0,ye3(60)" : "=r"(m[3]));
	__asm__ ("le3.mfer %0,ye3(61)" : "=r"(m[2]));
	__asm__ ("le3.mfer %0,ye3(62)" : "=r"(m[1]));
	__asm__ ("le3.mfer %0,ye3(63)" : "=r"(m[0]));
}

void Unumber::mter_e0(unsigned m[]) {
	__asm__ ("le3.mter ye0(0),%0" : : "r"(m[63]));
	__asm__ ("le3.mter ye0(1),%0" : : "r"(m[62]));
	__asm__ ("le3.mter ye0(2),%0" : : "r"(m[61]));
	__asm__ ("le3.mter ye0(3),%0" : : "r"(m[60]));
	__asm__ ("le3.mter ye0(4),%0" : : "r"(m[59]));
	__asm__ ("le3.mter ye0(5),%0" : : "r"(m[58]));
	__asm__ ("le3.mter ye0(6),%0" : : "r"(m[57]));
	__asm__ ("le3.mter ye0(7),%0" : : "r"(m[56]));
	__asm__ ("le3.mter ye0(8),%0" : : "r"(m[55]));
	__asm__ ("le3.mter ye0(9),%0" : : "r"(m[54]));
	__asm__ ("le3.mter ye0(10),%0" : : "r"(m[53]));
	__asm__ ("le3.mter ye0(11),%0" : : "r"(m[52]));
	__asm__ ("le3.mter ye0(12),%0" : : "r"(m[51]));
	__asm__ ("le3.mter ye0(13),%0" : : "r"(m[50]));
	__asm__ ("le3.mter ye0(14),%0" : : "r"(m[49]));
	__asm__ ("le3.mter ye0(15),%0" : : "r"(m[48]));
	__asm__ ("le3.mter ye0(16),%0" : : "r"(m[47]));
	__asm__ ("le3.mter ye0(17),%0" : : "r"(m[46]));
	__asm__ ("le3.mter ye0(18),%0" : : "r"(m[45]));
	__asm__ ("le3.mter ye0(19),%0" : : "r"(m[44]));
	__asm__ ("le3.mter ye0(20),%0" : : "r"(m[43]));
	__asm__ ("le3.mter ye0(21),%0" : : "r"(m[42]));
	__asm__ ("le3.mter ye0(22),%0" : : "r"(m[41]));
	__asm__ ("le3.mter ye0(23),%0" : : "r"(m[40]));
	__asm__ ("le3.mter ye0(24),%0" : : "r"(m[39]));
	__asm__ ("le3.mter ye0(25),%0" : : "r"(m[38]));
	__asm__ ("le3.mter ye0(26),%0" : : "r"(m[37]));
	__asm__ ("le3.mter ye0(27),%0" : : "r"(m[36]));
	__asm__ ("le3.mter ye0(28),%0" : : "r"(m[35]));
	__asm__ ("le3.mter ye0(29),%0" : : "r"(m[34]));
	__asm__ ("le3.mter ye0(30),%0" : : "r"(m[33]));
	__asm__ ("le3.mter ye0(31),%0" : : "r"(m[32]));
	__asm__ ("le3.mter ye0(32),%0" : : "r"(m[31]));
	__asm__ ("le3.mter ye0(33),%0" : : "r"(m[30]));
	__asm__ ("le3.mter ye0(34),%0" : : "r"(m[29]));
	__asm__ ("le3.mter ye0(35),%0" : : "r"(m[28]));
	__asm__ ("le3.mter ye0(36),%0" : : "r"(m[27]));
	__asm__ ("le3.mter ye0(37),%0" : : "r"(m[26]));
	__asm__ ("le3.mter ye0(38),%0" : : "r"(m[25]));
	__asm__ ("le3.mter ye0(39),%0" : : "r"(m[24]));
	__asm__ ("le3.mter ye0(40),%0" : : "r"(m[23]));
	__asm__ ("le3.mter ye0(41),%0" : : "r"(m[22]));
	__asm__ ("le3.mter ye0(42),%0" : : "r"(m[21]));
	__asm__ ("le3.mter ye0(43),%0" : : "r"(m[20]));
	__asm__ ("le3.mter ye0(44),%0" : : "r"(m[19]));
	__asm__ ("le3.mter ye0(45),%0" : : "r"(m[18]));
	__asm__ ("le3.mter ye0(46),%0" : : "r"(m[17]));
	__asm__ ("le3.mter ye0(47),%0" : : "r"(m[16]));
	__asm__ ("le3.mter ye0(48),%0" : : "r"(m[15]));
	__asm__ ("le3.mter ye0(49),%0" : : "r"(m[14]));
	__asm__ ("le3.mter ye0(50),%0" : : "r"(m[13]));
	__asm__ ("le3.mter ye0(51),%0" : : "r"(m[12]));
	__asm__ ("le3.mter ye0(52),%0" : : "r"(m[11]));
	__asm__ ("le3.mter ye0(53),%0" : : "r"(m[10]));
	__asm__ ("le3.mter ye0(54),%0" : : "r"(m[9]));
	__asm__ ("le3.mter ye0(55),%0" : : "r"(m[8]));
	__asm__ ("le3.mter ye0(56),%0" : : "r"(m[7]));
	__asm__ ("le3.mter ye0(57),%0" : : "r"(m[6]));
	__asm__ ("le3.mter ye0(58),%0" : : "r"(m[5]));
	__asm__ ("le3.mter ye0(59),%0" : : "r"(m[4]));
	__asm__ ("le3.mter ye0(60),%0" : : "r"(m[3]));
	__asm__ ("le3.mter ye0(61),%0" : : "r"(m[2]));
	__asm__ ("le3.mter ye0(62),%0" : : "r"(m[1]));
	__asm__ ("le3.mter ye0(63),%0" : : "r"(m[0]));
}

void Unumber::mter_e1(unsigned m[]) {
	__asm__ ("le3.mter ye1(0),%0" : : "r"(m[63]));
	__asm__ ("le3.mter ye1(1),%0" : : "r"(m[62]));
	__asm__ ("le3.mter ye1(2),%0" : : "r"(m[61]));
	__asm__ ("le3.mter ye1(3),%0" : : "r"(m[60]));
	__asm__ ("le3.mter ye1(4),%0" : : "r"(m[59]));
	__asm__ ("le3.mter ye1(5),%0" : : "r"(m[58]));
	__asm__ ("le3.mter ye1(6),%0" : : "r"(m[57]));
	__asm__ ("le3.mter ye1(7),%0" : : "r"(m[56]));
	__asm__ ("le3.mter ye1(8),%0" : : "r"(m[55]));
	__asm__ ("le3.mter ye1(9),%0" : : "r"(m[54]));
	__asm__ ("le3.mter ye1(10),%0" : : "r"(m[53]));
	__asm__ ("le3.mter ye1(11),%0" : : "r"(m[52]));
	__asm__ ("le3.mter ye1(12),%0" : : "r"(m[51]));
	__asm__ ("le3.mter ye1(13),%0" : : "r"(m[50]));
	__asm__ ("le3.mter ye1(14),%0" : : "r"(m[49]));
	__asm__ ("le3.mter ye1(15),%0" : : "r"(m[48]));
	__asm__ ("le3.mter ye1(16),%0" : : "r"(m[47]));
	__asm__ ("le3.mter ye1(17),%0" : : "r"(m[46]));
	__asm__ ("le3.mter ye1(18),%0" : : "r"(m[45]));
	__asm__ ("le3.mter ye1(19),%0" : : "r"(m[44]));
	__asm__ ("le3.mter ye1(20),%0" : : "r"(m[43]));
	__asm__ ("le3.mter ye1(21),%0" : : "r"(m[42]));
	__asm__ ("le3.mter ye1(22),%0" : : "r"(m[41]));
	__asm__ ("le3.mter ye1(23),%0" : : "r"(m[40]));
	__asm__ ("le3.mter ye1(24),%0" : : "r"(m[39]));
	__asm__ ("le3.mter ye1(25),%0" : : "r"(m[38]));
	__asm__ ("le3.mter ye1(26),%0" : : "r"(m[37]));
	__asm__ ("le3.mter ye1(27),%0" : : "r"(m[36]));
	__asm__ ("le3.mter ye1(28),%0" : : "r"(m[35]));
	__asm__ ("le3.mter ye1(29),%0" : : "r"(m[34]));
	__asm__ ("le3.mter ye1(30),%0" : : "r"(m[33]));
	__asm__ ("le3.mter ye1(31),%0" : : "r"(m[32]));
	__asm__ ("le3.mter ye1(32),%0" : : "r"(m[31]));
	__asm__ ("le3.mter ye1(33),%0" : : "r"(m[30]));
	__asm__ ("le3.mter ye1(34),%0" : : "r"(m[29]));
	__asm__ ("le3.mter ye1(35),%0" : : "r"(m[28]));
	__asm__ ("le3.mter ye1(36),%0" : : "r"(m[27]));
	__asm__ ("le3.mter ye1(37),%0" : : "r"(m[26]));
	__asm__ ("le3.mter ye1(38),%0" : : "r"(m[25]));
	__asm__ ("le3.mter ye1(39),%0" : : "r"(m[24]));
	__asm__ ("le3.mter ye1(40),%0" : : "r"(m[23]));
	__asm__ ("le3.mter ye1(41),%0" : : "r"(m[22]));
	__asm__ ("le3.mter ye1(42),%0" : : "r"(m[21]));
	__asm__ ("le3.mter ye1(43),%0" : : "r"(m[20]));
	__asm__ ("le3.mter ye1(44),%0" : : "r"(m[19]));
	__asm__ ("le3.mter ye1(45),%0" : : "r"(m[18]));
	__asm__ ("le3.mter ye1(46),%0" : : "r"(m[17]));
	__asm__ ("le3.mter ye1(47),%0" : : "r"(m[16]));
	__asm__ ("le3.mter ye1(48),%0" : : "r"(m[15]));
	__asm__ ("le3.mter ye1(49),%0" : : "r"(m[14]));
	__asm__ ("le3.mter ye1(50),%0" : : "r"(m[13]));
	__asm__ ("le3.mter ye1(51),%0" : : "r"(m[12]));
	__asm__ ("le3.mter ye1(52),%0" : : "r"(m[11]));
	__asm__ ("le3.mter ye1(53),%0" : : "r"(m[10]));
	__asm__ ("le3.mter ye1(54),%0" : : "r"(m[9]));
	__asm__ ("le3.mter ye1(55),%0" : : "r"(m[8]));
	__asm__ ("le3.mter ye1(56),%0" : : "r"(m[7]));
	__asm__ ("le3.mter ye1(57),%0" : : "r"(m[6]));
	__asm__ ("le3.mter ye1(58),%0" : : "r"(m[5]));
	__asm__ ("le3.mter ye1(59),%0" : : "r"(m[4]));
	__asm__ ("le3.mter ye1(60),%0" : : "r"(m[3]));
	__asm__ ("le3.mter ye1(61),%0" : : "r"(m[2]));
	__asm__ ("le3.mter ye1(62),%0" : : "r"(m[1]));
	__asm__ ("le3.mter ye1(63),%0" : : "r"(m[0]));
}

void Unumber::mter_e2(unsigned m[]) {
	__asm__ ("le3.mter ye2(0),%0" : : "r"(m[63]));
	__asm__ ("le3.mter ye2(1),%0" : : "r"(m[62]));
	__asm__ ("le3.mter ye2(2),%0" : : "r"(m[61]));
	__asm__ ("le3.mter ye2(3),%0" : : "r"(m[60]));
	__asm__ ("le3.mter ye2(4),%0" : : "r"(m[59]));
	__asm__ ("le3.mter ye2(5),%0" : : "r"(m[58]));
	__asm__ ("le3.mter ye2(6),%0" : : "r"(m[57]));
	__asm__ ("le3.mter ye2(7),%0" : : "r"(m[56]));
	__asm__ ("le3.mter ye2(8),%0" : : "r"(m[55]));
	__asm__ ("le3.mter ye2(9),%0" : : "r"(m[54]));
	__asm__ ("le3.mter ye2(10),%0" : : "r"(m[53]));
	__asm__ ("le3.mter ye2(11),%0" : : "r"(m[52]));
	__asm__ ("le3.mter ye2(12),%0" : : "r"(m[51]));
	__asm__ ("le3.mter ye2(13),%0" : : "r"(m[50]));
	__asm__ ("le3.mter ye2(14),%0" : : "r"(m[49]));
	__asm__ ("le3.mter ye2(15),%0" : : "r"(m[48]));
	__asm__ ("le3.mter ye2(16),%0" : : "r"(m[47]));
	__asm__ ("le3.mter ye2(17),%0" : : "r"(m[46]));
	__asm__ ("le3.mter ye2(18),%0" : : "r"(m[45]));
	__asm__ ("le3.mter ye2(19),%0" : : "r"(m[44]));
	__asm__ ("le3.mter ye2(20),%0" : : "r"(m[43]));
	__asm__ ("le3.mter ye2(21),%0" : : "r"(m[42]));
	__asm__ ("le3.mter ye2(22),%0" : : "r"(m[41]));
	__asm__ ("le3.mter ye2(23),%0" : : "r"(m[40]));
	__asm__ ("le3.mter ye2(24),%0" : : "r"(m[39]));
	__asm__ ("le3.mter ye2(25),%0" : : "r"(m[38]));
	__asm__ ("le3.mter ye2(26),%0" : : "r"(m[37]));
	__asm__ ("le3.mter ye2(27),%0" : : "r"(m[36]));
	__asm__ ("le3.mter ye2(28),%0" : : "r"(m[35]));
	__asm__ ("le3.mter ye2(29),%0" : : "r"(m[34]));
	__asm__ ("le3.mter ye2(30),%0" : : "r"(m[33]));
	__asm__ ("le3.mter ye2(31),%0" : : "r"(m[32]));
	__asm__ ("le3.mter ye2(32),%0" : : "r"(m[31]));
	__asm__ ("le3.mter ye2(33),%0" : : "r"(m[30]));
	__asm__ ("le3.mter ye2(34),%0" : : "r"(m[29]));
	__asm__ ("le3.mter ye2(35),%0" : : "r"(m[28]));
	__asm__ ("le3.mter ye2(36),%0" : : "r"(m[27]));
	__asm__ ("le3.mter ye2(37),%0" : : "r"(m[26]));
	__asm__ ("le3.mter ye2(38),%0" : : "r"(m[25]));
	__asm__ ("le3.mter ye2(39),%0" : : "r"(m[24]));
	__asm__ ("le3.mter ye2(40),%0" : : "r"(m[23]));
	__asm__ ("le3.mter ye2(41),%0" : : "r"(m[22]));
	__asm__ ("le3.mter ye2(42),%0" : : "r"(m[21]));
	__asm__ ("le3.mter ye2(43),%0" : : "r"(m[20]));
	__asm__ ("le3.mter ye2(44),%0" : : "r"(m[19]));
	__asm__ ("le3.mter ye2(45),%0" : : "r"(m[18]));
	__asm__ ("le3.mter ye2(46),%0" : : "r"(m[17]));
	__asm__ ("le3.mter ye2(47),%0" : : "r"(m[16]));
	__asm__ ("le3.mter ye2(48),%0" : : "r"(m[15]));
	__asm__ ("le3.mter ye2(49),%0" : : "r"(m[14]));
	__asm__ ("le3.mter ye2(50),%0" : : "r"(m[13]));
	__asm__ ("le3.mter ye2(51),%0" : : "r"(m[12]));
	__asm__ ("le3.mter ye2(52),%0" : : "r"(m[11]));
	__asm__ ("le3.mter ye2(53),%0" : : "r"(m[10]));
	__asm__ ("le3.mter ye2(54),%0" : : "r"(m[9]));
	__asm__ ("le3.mter ye2(55),%0" : : "r"(m[8]));
	__asm__ ("le3.mter ye2(56),%0" : : "r"(m[7]));
	__asm__ ("le3.mter ye2(57),%0" : : "r"(m[6]));
	__asm__ ("le3.mter ye2(58),%0" : : "r"(m[5]));
	__asm__ ("le3.mter ye2(59),%0" : : "r"(m[4]));
	__asm__ ("le3.mter ye2(60),%0" : : "r"(m[3]));
	__asm__ ("le3.mter ye2(61),%0" : : "r"(m[2]));
	__asm__ ("le3.mter ye2(62),%0" : : "r"(m[1]));
	__asm__ ("le3.mter ye2(63),%0" : : "r"(m[0]));
}

void Unumber::mter_e3(unsigned m[]) {
	__asm__ ("le3.mter ye3(0),%0" : : "r"(m[63]));
	__asm__ ("le3.mter ye3(1),%0" : : "r"(m[62]));
	__asm__ ("le3.mter ye3(2),%0" : : "r"(m[61]));
	__asm__ ("le3.mter ye3(3),%0" : : "r"(m[60]));
	__asm__ ("le3.mter ye3(4),%0" : : "r"(m[59]));
	__asm__ ("le3.mter ye3(5),%0" : : "r"(m[58]));
	__asm__ ("le3.mter ye3(6),%0" : : "r"(m[57]));
	__asm__ ("le3.mter ye3(7),%0" : : "r"(m[56]));
	__asm__ ("le3.mter ye3(8),%0" : : "r"(m[55]));
	__asm__ ("le3.mter ye3(9),%0" : : "r"(m[54]));
	__asm__ ("le3.mter ye3(10),%0" : : "r"(m[53]));
	__asm__ ("le3.mter ye3(11),%0" : : "r"(m[52]));
	__asm__ ("le3.mter ye3(12),%0" : : "r"(m[51]));
	__asm__ ("le3.mter ye3(13),%0" : : "r"(m[50]));
	__asm__ ("le3.mter ye3(14),%0" : : "r"(m[49]));
	__asm__ ("le3.mter ye3(15),%0" : : "r"(m[48]));
	__asm__ ("le3.mter ye3(16),%0" : : "r"(m[47]));
	__asm__ ("le3.mter ye3(17),%0" : : "r"(m[46]));
	__asm__ ("le3.mter ye3(18),%0" : : "r"(m[45]));
	__asm__ ("le3.mter ye3(19),%0" : : "r"(m[44]));
	__asm__ ("le3.mter ye3(20),%0" : : "r"(m[43]));
	__asm__ ("le3.mter ye3(21),%0" : : "r"(m[42]));
	__asm__ ("le3.mter ye3(22),%0" : : "r"(m[41]));
	__asm__ ("le3.mter ye3(23),%0" : : "r"(m[40]));
	__asm__ ("le3.mter ye3(24),%0" : : "r"(m[39]));
	__asm__ ("le3.mter ye3(25),%0" : : "r"(m[38]));
	__asm__ ("le3.mter ye3(26),%0" : : "r"(m[37]));
	__asm__ ("le3.mter ye3(27),%0" : : "r"(m[36]));
	__asm__ ("le3.mter ye3(28),%0" : : "r"(m[35]));
	__asm__ ("le3.mter ye3(29),%0" : : "r"(m[34]));
	__asm__ ("le3.mter ye3(30),%0" : : "r"(m[33]));
	__asm__ ("le3.mter ye3(31),%0" : : "r"(m[32]));
	__asm__ ("le3.mter ye3(32),%0" : : "r"(m[31]));
	__asm__ ("le3.mter ye3(33),%0" : : "r"(m[30]));
	__asm__ ("le3.mter ye3(34),%0" : : "r"(m[29]));
	__asm__ ("le3.mter ye3(35),%0" : : "r"(m[28]));
	__asm__ ("le3.mter ye3(36),%0" : : "r"(m[27]));
	__asm__ ("le3.mter ye3(37),%0" : : "r"(m[26]));
	__asm__ ("le3.mter ye3(38),%0" : : "r"(m[25]));
	__asm__ ("le3.mter ye3(39),%0" : : "r"(m[24]));
	__asm__ ("le3.mter ye3(40),%0" : : "r"(m[23]));
	__asm__ ("le3.mter ye3(41),%0" : : "r"(m[22]));
	__asm__ ("le3.mter ye3(42),%0" : : "r"(m[21]));
	__asm__ ("le3.mter ye3(43),%0" : : "r"(m[20]));
	__asm__ ("le3.mter ye3(44),%0" : : "r"(m[19]));
	__asm__ ("le3.mter ye3(45),%0" : : "r"(m[18]));
	__asm__ ("le3.mter ye3(46),%0" : : "r"(m[17]));
	__asm__ ("le3.mter ye3(47),%0" : : "r"(m[16]));
	__asm__ ("le3.mter ye3(48),%0" : : "r"(m[15]));
	__asm__ ("le3.mter ye3(49),%0" : : "r"(m[14]));
	__asm__ ("le3.mter ye3(50),%0" : : "r"(m[13]));
	__asm__ ("le3.mter ye3(51),%0" : : "r"(m[12]));
	__asm__ ("le3.mter ye3(52),%0" : : "r"(m[11]));
	__asm__ ("le3.mter ye3(53),%0" : : "r"(m[10]));
	__asm__ ("le3.mter ye3(54),%0" : : "r"(m[9]));
	__asm__ ("le3.mter ye3(55),%0" : : "r"(m[8]));
	__asm__ ("le3.mter ye3(56),%0" : : "r"(m[7]));
	__asm__ ("le3.mter ye3(57),%0" : : "r"(m[6]));
	__asm__ ("le3.mter ye3(58),%0" : : "r"(m[5]));
	__asm__ ("le3.mter ye3(59),%0" : : "r"(m[4]));
	__asm__ ("le3.mter ye3(60),%0" : : "r"(m[3]));
	__asm__ ("le3.mter ye3(61),%0" : : "r"(m[2]));
	__asm__ ("le3.mter ye3(62),%0" : : "r"(m[1]));
	__asm__ ("le3.mter ye3(63),%0" : : "r"(m[0]));
}
/*
void Unumber::hw_modmul()
{
	__asm__ ("le3.modmul ye0,ye1,ye2,ye3");	
}

void Unumber::hw_modexp()
{
	__asm__ ("le3.modexp ye0,ye1,ye2,ye3");
}

void Unumber::hw_gcd()
{
	__asm__ ("le3.gcd ye0,ye1,ye2");
}

void Unumber::hw_inv()
{
	__asm__ ("le3.inv ye0,ye1,ye2");
}

void Unumber::hw_gfun()
{
	__asm__ ("le3.gfun ye0,ye1,ye2,ye3");
}
*/
