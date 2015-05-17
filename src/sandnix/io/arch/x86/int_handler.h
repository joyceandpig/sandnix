/*
	Copyright 2015,��ҹ���� <darknightghost.cn@gmail.com>

	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef	INT_HANDLER_H_INCLUDE
#define	INT_HANDLER_H_INCLUDE

#define	INT_HNDLR(num)		void	int_##num()

void	de_int_handler();
void	db_int_handler();
void	nmi_int_handler();
void	bp_int_handler();
void	of_int_handler();
void	br_int_handler();
void	ud_int_handler();
void	nm_int_handler();
void	df_int_handler();
void	fpu_int_handler();
void	ts_int_handler();
void	np_int_handler();
void	ss_int_handler();
void	gp_int_handler();
void	pf_int_handler();
void	reserved_int_handler();
void	mf_int_handler();
void	ac_int_handler();
void	mc_int_handler();
void	xf_int_handler();

INT_HNDLR(0x14);
INT_HNDLR(0x15);
INT_HNDLR(0x16);
INT_HNDLR(0x17);
INT_HNDLR(0x18);
INT_HNDLR(0x19);
INT_HNDLR(0x1A);
INT_HNDLR(0x1B);
INT_HNDLR(0x1C);
INT_HNDLR(0x1D);
INT_HNDLR(0x1E);
INT_HNDLR(0x1F);

INT_HNDLR(0x20);
INT_HNDLR(0x21);
INT_HNDLR(0x22);
INT_HNDLR(0x23);
INT_HNDLR(0x24);
INT_HNDLR(0x25);
INT_HNDLR(0x26);
INT_HNDLR(0x27);
INT_HNDLR(0x28);
INT_HNDLR(0x29);
INT_HNDLR(0x2A);
INT_HNDLR(0x2B);
INT_HNDLR(0x2C);
INT_HNDLR(0x2D);
INT_HNDLR(0x2E);
INT_HNDLR(0x2F);

INT_HNDLR(0x30);
INT_HNDLR(0x31);
INT_HNDLR(0x32);
INT_HNDLR(0x33);
INT_HNDLR(0x34);
INT_HNDLR(0x35);
INT_HNDLR(0x36);
INT_HNDLR(0x37);
INT_HNDLR(0x38);
INT_HNDLR(0x39);
INT_HNDLR(0x3A);
INT_HNDLR(0x3B);
INT_HNDLR(0x3C);
INT_HNDLR(0x3D);
INT_HNDLR(0x3E);
INT_HNDLR(0x3F);

INT_HNDLR(0x40);
INT_HNDLR(0x41);
INT_HNDLR(0x42);
INT_HNDLR(0x43);
INT_HNDLR(0x44);
INT_HNDLR(0x45);
INT_HNDLR(0x46);
INT_HNDLR(0x47);
INT_HNDLR(0x48);
INT_HNDLR(0x49);
INT_HNDLR(0x4A);
INT_HNDLR(0x4B);
INT_HNDLR(0x4C);
INT_HNDLR(0x4D);
INT_HNDLR(0x4E);
INT_HNDLR(0x4F);

INT_HNDLR(0x50);
INT_HNDLR(0x51);
INT_HNDLR(0x52);
INT_HNDLR(0x53);
INT_HNDLR(0x54);
INT_HNDLR(0x55);
INT_HNDLR(0x56);
INT_HNDLR(0x57);
INT_HNDLR(0x58);
INT_HNDLR(0x59);
INT_HNDLR(0x5A);
INT_HNDLR(0x5B);
INT_HNDLR(0x5C);
INT_HNDLR(0x5D);
INT_HNDLR(0x5E);
INT_HNDLR(0x5F);

INT_HNDLR(0x60);
INT_HNDLR(0x61);
INT_HNDLR(0x62);
INT_HNDLR(0x63);
INT_HNDLR(0x64);
INT_HNDLR(0x65);
INT_HNDLR(0x66);
INT_HNDLR(0x67);
INT_HNDLR(0x68);
INT_HNDLR(0x69);
INT_HNDLR(0x6A);
INT_HNDLR(0x6B);
INT_HNDLR(0x6C);
INT_HNDLR(0x6D);
INT_HNDLR(0x6E);
INT_HNDLR(0x6F);

INT_HNDLR(0x70);
INT_HNDLR(0x71);
INT_HNDLR(0x72);
INT_HNDLR(0x73);
INT_HNDLR(0x74);
INT_HNDLR(0x75);
INT_HNDLR(0x76);
INT_HNDLR(0x77);
INT_HNDLR(0x78);
INT_HNDLR(0x79);
INT_HNDLR(0x7A);
INT_HNDLR(0x7B);
INT_HNDLR(0x7C);
INT_HNDLR(0x7D);
INT_HNDLR(0x7E);
INT_HNDLR(0x7F);

INT_HNDLR(0x80);
INT_HNDLR(0x81);
INT_HNDLR(0x82);
INT_HNDLR(0x83);
INT_HNDLR(0x84);
INT_HNDLR(0x85);
INT_HNDLR(0x86);
INT_HNDLR(0x87);
INT_HNDLR(0x88);
INT_HNDLR(0x89);
INT_HNDLR(0x8A);
INT_HNDLR(0x8B);
INT_HNDLR(0x8C);
INT_HNDLR(0x8D);
INT_HNDLR(0x8E);
INT_HNDLR(0x8F);

INT_HNDLR(0x90);
INT_HNDLR(0x91);
INT_HNDLR(0x92);
INT_HNDLR(0x93);
INT_HNDLR(0x94);
INT_HNDLR(0x95);
INT_HNDLR(0x96);
INT_HNDLR(0x97);
INT_HNDLR(0x98);
INT_HNDLR(0x99);
INT_HNDLR(0x9A);
INT_HNDLR(0x9B);
INT_HNDLR(0x9C);
INT_HNDLR(0x9D);
INT_HNDLR(0x9E);
INT_HNDLR(0x9F);

INT_HNDLR(0xA0);
INT_HNDLR(0xA1);
INT_HNDLR(0xA2);
INT_HNDLR(0xA3);
INT_HNDLR(0xA4);
INT_HNDLR(0xA5);
INT_HNDLR(0xA6);
INT_HNDLR(0xA7);
INT_HNDLR(0xA8);
INT_HNDLR(0xA9);
INT_HNDLR(0xAA);
INT_HNDLR(0xAB);
INT_HNDLR(0xAC);
INT_HNDLR(0xAD);
INT_HNDLR(0xAE);
INT_HNDLR(0xAF);

INT_HNDLR(0xB0);
INT_HNDLR(0xB1);
INT_HNDLR(0xB2);
INT_HNDLR(0xB3);
INT_HNDLR(0xB4);
INT_HNDLR(0xB5);
INT_HNDLR(0xB6);
INT_HNDLR(0xB7);
INT_HNDLR(0xB8);
INT_HNDLR(0xB9);
INT_HNDLR(0xBA);
INT_HNDLR(0xBB);
INT_HNDLR(0xBC);
INT_HNDLR(0xBD);
INT_HNDLR(0xBE);
INT_HNDLR(0xBF);

INT_HNDLR(0xC0);
INT_HNDLR(0xC1);
INT_HNDLR(0xC2);
INT_HNDLR(0xC3);
INT_HNDLR(0xC4);
INT_HNDLR(0xC5);
INT_HNDLR(0xC6);
INT_HNDLR(0xC7);
INT_HNDLR(0xC8);
INT_HNDLR(0xC9);
INT_HNDLR(0xCA);
INT_HNDLR(0xCB);
INT_HNDLR(0xCC);
INT_HNDLR(0xCD);
INT_HNDLR(0xCE);
INT_HNDLR(0xCF);

INT_HNDLR(0xD0);
INT_HNDLR(0xD1);
INT_HNDLR(0xD2);
INT_HNDLR(0xD3);
INT_HNDLR(0xD4);
INT_HNDLR(0xD5);
INT_HNDLR(0xD6);
INT_HNDLR(0xD7);
INT_HNDLR(0xD8);
INT_HNDLR(0xD9);
INT_HNDLR(0xDA);
INT_HNDLR(0xDB);
INT_HNDLR(0xDC);
INT_HNDLR(0xDD);
INT_HNDLR(0xDE);
INT_HNDLR(0xDF);

INT_HNDLR(0xE0);
INT_HNDLR(0xE1);
INT_HNDLR(0xE2);
INT_HNDLR(0xE3);
INT_HNDLR(0xE4);
INT_HNDLR(0xE5);
INT_HNDLR(0xE6);
INT_HNDLR(0xE7);
INT_HNDLR(0xE8);
INT_HNDLR(0xE9);
INT_HNDLR(0xEA);
INT_HNDLR(0xEB);
INT_HNDLR(0xEC);
INT_HNDLR(0xED);
INT_HNDLR(0xEE);
INT_HNDLR(0xEF);

INT_HNDLR(0xF0);
INT_HNDLR(0xF1);
INT_HNDLR(0xF2);
INT_HNDLR(0xF3);
INT_HNDLR(0xF4);
INT_HNDLR(0xF5);
INT_HNDLR(0xF6);
INT_HNDLR(0xF7);
INT_HNDLR(0xF8);
INT_HNDLR(0xF9);
INT_HNDLR(0xFA);
INT_HNDLR(0xFB);
INT_HNDLR(0xFC);
INT_HNDLR(0xFD);
INT_HNDLR(0xFE);
INT_HNDLR(0xFF);

#endif	//!	INT_HANDLER_H_INCLUDE
