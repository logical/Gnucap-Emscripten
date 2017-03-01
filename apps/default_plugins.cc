/*$Id: signon.cc,v 26.138 2013/04/24 02:44:30 al Exp $ -*- C++ -*-
 * Copyright (C) 2013 Albert Davis
 * Author: Albert Davis <aldavis@gnu.org>
 *
 * This file is part of "Gnucap", the Gnu Circuit Analysis Package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *------------------------------------------------------------------
 * print a message at sign-on.
 */
#include "globals.h"
#include "io_.h"
#include "patchlev.h"
#include "default_plugins.h"
/*--------------------------------------------------------------------------*/
class SIGN_ON {
public:
  SIGN_ON() {
    IO::mstdout << "default plugins: " PATCHLEVEL "\n";
  }
};
void load_default_plugins(void){

 d_diode();
 d_bjt();
 d_mos1();
 d_mos2();
 d_mos3();
 d_mos4();
 d_mos5();
 d_mos6();
 d_mos7();
 d_mos8();
 
 d_admit();
 d_cap();
 d_cccs();
 d_ccvs();
 d_coil();
 d_cs();
 d_poly_cap();
 d_poly_g();
 d_res();
 d_switch();
 
 d_trln();
 d_vcg();
 d_vcr();
 d_vcvs();
 d_vs();
 d_meter();
 bm_complex(); 
 bm_exp();
 bm_fit();
 bm_generator();
 bm_model();
 bm_poly();
 bm_posy();
 bm_pulse();
 bm_pwl();
 bm_sffm();

  bm_sin();
  bm_tanh();
  bmm_table();
  bmm_semi();
  c_clear();
  c_command();
  c_delete();
  c_exp();
  c_genrat();
  c_help();
  c_list();
  c_measure();
  c_modify();

 c_param();
 c_prbcmd();
 c_status();
 c_sweep();
 c_sim();
 c_system();
 s_ac();
 s_dc();
 s_fo();
 s_tr();
 lang_spice_load();
 lang_spectre_load();
 lang_verilog_load();

 func_core();
 measure_eval();
 measure_max();
 measure_min();
 measure_slewrate();
 measure_cross();
 measure_integral();
 measure_average();
 measure_rms();
 measure_at();
 spice_wrapper();


 SIGN_ON sign_on;


 }
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
// vim:ts=8:sw=2:noet:
