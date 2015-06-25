/*$Id: func_core.cc,v 26.137 2010/04/10 02:37:05 al Exp $ -*- C++ -*-
 * Copyright (C) 2008 Albert Davis
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
 */
#include "globals.h"
#include "u_parameter.h"
#include "u_function.h"
/*--------------------------------------------------------------------------*/
namespace {
/*--------------------------------------------------------------------------*/
class abs : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::abs(x));
  }
} p_abs;
/*--------------------------------------------------------------------------*/
class sqrt : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::sqrt(x));
  }
} p_sqrt;
/*--------------------------------------------------------------------------*/
class log : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::log(x));
  }
} p_log;
/*--------------------------------------------------------------------------*/
class exp : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::exp(x));
  }
} p_exp;
/*--------------------------------------------------------------------------*/
class INT : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::floor(x));
  }
} p_int;
/*--------------------------------------------------------------------------*/
class pow : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x, y;
    Cmd >> x >> y;
    x.e_val(NOT_INPUT, Scope);
    y.e_val(NOT_INPUT, Scope);
    return to_string(std::pow(x,y));
  }
} p_pow;
/*--------------------------------------------------------------------------*/
class MAX : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x, y;
    Cmd >> x >> y;
    x.e_val(NOT_INPUT, Scope);
    y.e_val(NOT_INPUT, Scope);
    return to_string(std::max(x,y));
  }
} p_max;
/*--------------------------------------------------------------------------*/
class MIN : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x, y;
    Cmd >> x >> y;
    x.e_val(NOT_INPUT, Scope);
    y.e_val(NOT_INPUT, Scope);
    return to_string(std::min(x,y));
  }
} p_min;
/*--------------------------------------------------------------------------*/
class IF : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x, y, z;
    Cmd >> x >> y >> z;
    x.e_val(NOT_INPUT, Scope);
    y.e_val(NOT_INPUT, Scope);
    z.e_val(NOT_INPUT, Scope);
    return to_string(x ? y : z);
  }
} p_if;
/*--------------------------------------------------------------------------*/
class sin : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::sin(x));
  }
} p_sin;
/*--------------------------------------------------------------------------*/
class sinh : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::sinh(x));
  }
} p_sinh;
/*--------------------------------------------------------------------------*/
class cos : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::cos(x));
  }
} p_cos;
/*--------------------------------------------------------------------------*/
class cosh : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::cosh(x));
  }
} p_cosh;
/*--------------------------------------------------------------------------*/
class tan : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::tan(x));
  }
} p_tan;
/*--------------------------------------------------------------------------*/
class tanh : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> x;
    Cmd >> x;
    x.e_val(NOT_INPUT, Scope);
    return to_string(std::tanh(x));
  }
} p_tanh;
/*--------------------------------------------------------------------------*/
class na : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> arg;
    Cmd >> arg;
    arg.e_val(NOT_INPUT, Scope);
    return "NA";
    //return (arg.has_hard_value()) ? (to_string(double(arg))) : ("NA");
  }
} p_na;
/*--------------------------------------------------------------------------*/
// random funcs:
// Respectively you can give a parameter a statistical dispersion function,
// either rectangular distribution 
//	UNIF(nom_val, rel_var)
//	AUNIF(nom_val, abs_var)
// or normal distribution: 
//	GAUSS(nom_val, rel_var, sigma)
//	AGAUSS(nom_val, abs_var, sigma)
// Normal distribution can be represented with variation values of 1, 2 or 3 sigmas.
// In both cases rel_var=abs_var/nom_val.
// for now, stubs, return nom_val
/*--------------------------------------------------------------------------*/
class RANDOM_STUB : public FUNCTION {
public:
  std::string eval(CS& Cmd, const CARD_LIST* Scope)const
  {
    PARAMETER<double> arg;
    Cmd >> arg;
    arg.e_val(NOT_INPUT, Scope);
    return to_string(double(arg));
  }
} p_stub;
}
void func_core(void){
static DISPATCHER<FUNCTION>::INSTALL d_abs(&function_dispatcher, "abs", &p_abs);
static DISPATCHER<FUNCTION>::INSTALL d_sqrt(&function_dispatcher, "sqrt", &p_sqrt);
static DISPATCHER<FUNCTION>::INSTALL d_log(&function_dispatcher, "log", &p_log);
static DISPATCHER<FUNCTION>::INSTALL d_exp(&function_dispatcher, "exp", &p_exp);
static DISPATCHER<FUNCTION>::INSTALL d_int(&function_dispatcher, "int", &p_int);
static DISPATCHER<FUNCTION>::INSTALL d_pow(&function_dispatcher, "pow", &p_pow);
static DISPATCHER<FUNCTION>::INSTALL d_max(&function_dispatcher, "max", &p_max);
static DISPATCHER<FUNCTION>::INSTALL d_min(&function_dispatcher, "min", &p_min);
static DISPATCHER<FUNCTION>::INSTALL d_if(&function_dispatcher, "if", &p_if);
static DISPATCHER<FUNCTION>::INSTALL d_sin(&function_dispatcher, "sin", &p_sin);
static DISPATCHER<FUNCTION>::INSTALL d_sinh(&function_dispatcher, "sinh", &p_sinh);
static DISPATCHER<FUNCTION>::INSTALL d_cos(&function_dispatcher, "cos", &p_cos);
static DISPATCHER<FUNCTION>::INSTALL d_cosh(&function_dispatcher, "cosh", &p_cosh);
static DISPATCHER<FUNCTION>::INSTALL d_tan(&function_dispatcher, "tan", &p_tan);
static DISPATCHER<FUNCTION>::INSTALL d_tanh(&function_dispatcher, "tanh", &p_tanh);
static DISPATCHER<FUNCTION>::INSTALL d_na(&function_dispatcher, "na", &p_na);
static DISPATCHER<FUNCTION>::INSTALL d_stub(&function_dispatcher, "agauss|gauss|aunif|unif", &p_stub);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

// vim:ts=8:sw=2:noet:
