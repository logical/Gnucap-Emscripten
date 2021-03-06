/* $Id: d_mos_base.model,v 26.133 2009/11/26 04:58:04 al Exp $ -*- C++ -*-
 * Copyright (C) 2001 Albert Davis
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
 * MOS model - base for levels 1,2,3,6
 */ 
/* This file is automatically generated. DO NOT EDIT */

  const double mDEFAULT_is = 1e-14;
#include "globals.h"
#include "e_elemnt.h"
#include "d_mos_base.h"
/*--------------------------------------------------------------------------*/
const double NA(NOT_INPUT);
const double INF(BIGBIG);
/*--------------------------------------------------------------------------*/
int MODEL_BUILT_IN_MOS_BASE::_count = 0;
/*--------------------------------------------------------------------------*/
void SDP_BUILT_IN_MOS_BASE::init(const COMMON_COMPONENT* cc)
{
  assert(cc);
  SDP_BUILT_IN_DIODE::init(cc);
  const COMMON_BUILT_IN_MOS* c = prechecked_cast<const COMMON_BUILT_IN_MOS*>(cc);
  assert(c);
  const MODEL_BUILT_IN_MOS_BASE* m = prechecked_cast<const MODEL_BUILT_IN_MOS_BASE*>(c->model());
  assert(m);
  const CARD_LIST* par_scope = m->scope();
  assert(par_scope);
  // adjust: override
  // adjust: raw
  // adjust: calculated
    l_eff = (has_hard_value(c->l_in))
		? c->l_in * m->lmlt + m->xl - 2. * (m->ld + m->del)
		: OPT::defl;
    w_eff = (has_hard_value(c->w_in))
		? c->w_in * m->wmlt + m->xw - 2. * m->wd
		: OPT::defw;
    ad = (has_hard_value(c->ad_in)) ? c->ad_in : OPT::defad;
    as = (has_hard_value(c->as_in)) ? c->as_in : OPT::defas;
    cgate = NA;
    phi = NA;
    cgso = m->cgso * w_eff;
    cgdo = m->cgdo * w_eff;
    cgbo = m->cgbo * l_eff;
  // code_post

      if (has_hard_value(m->rd) || has_hard_value(m->rs)) {
	rd = m->rd;
	rs = m->rs;
      }else{
	rd = m->rsh * c->nrd;
	rs = m->rsh * c->nrs;
      }	
      if (!has_hard_value(m->js) || ad == 0. || as == 0.) {
	idsat = issat = m->is;	/* this convoluted logic */
      }else{			/* is for Spice compatibility */
	idsat = m->js * ad;
	issat = m->js * as;
      }
}
/*--------------------------------------------------------------------------*/
TDP_BUILT_IN_MOS_BASE::TDP_BUILT_IN_MOS_BASE(const DEV_BUILT_IN_MOS*)
{
}
/*--------------------------------------------------------------------------*/
MODEL_BUILT_IN_MOS_BASE::MODEL_BUILT_IN_MOS_BASE(const BASE_SUBCKT* p)
  :MODEL_BUILT_IN_DIODE(p),
   level(1),
   wmax(INF),
   wmin(0.),
   lmax(INF),
   lmin(0.),
   is(mDEFAULT_is),
   js(NA),
   rsh(0.0),
   rd(0.0),
   rs(0.0),
   cbd(NA),
   cbs(NA),
   cgso(0.0),
   cgdo(0.0),
   cgbo(0.0),
   cmodel(0),
   xl(0.0),
   xw(0.0),
   lmlt(1.0),
   wmlt(1.0),
   del(0.0),
   ld(0.0),
   wd(0.0),
   polarity(pN),
   tnom_k(NA),
   egap(NA),
   needs_isub(false)
{
  if (ENV::run_mode != rPRE_MAIN) {
    ++_count;
  }else{
  }
  set_default(&_tnom_c, OPT::tnom_c);
}
/*--------------------------------------------------------------------------*/
MODEL_BUILT_IN_MOS_BASE::MODEL_BUILT_IN_MOS_BASE(const MODEL_BUILT_IN_MOS_BASE& p)
  :MODEL_BUILT_IN_DIODE(p),
   level(p.level),
   wmax(p.wmax),
   wmin(p.wmin),
   lmax(p.lmax),
   lmin(p.lmin),
   is(p.is),
   js(p.js),
   rsh(p.rsh),
   rd(p.rd),
   rs(p.rs),
   cbd(p.cbd),
   cbs(p.cbs),
   cgso(p.cgso),
   cgdo(p.cgdo),
   cgbo(p.cgbo),
   cmodel(p.cmodel),
   xl(p.xl),
   xw(p.xw),
   lmlt(p.lmlt),
   wmlt(p.wmlt),
   del(p.del),
   ld(p.ld),
   wd(p.wd),
   polarity(p.polarity),
   tnom_k(p.tnom_k),
   egap(p.egap),
   needs_isub(p.needs_isub)
{
  if (ENV::run_mode != rPRE_MAIN) {
    ++_count;
  }else{untested();//194
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS_BASE::dev_type()const
{
  if (polarity == pN) {
    return "nmos";
  }else if (polarity == pP) {
    return "pmos";
  }else{untested();//235
    return MODEL_BUILT_IN_DIODE::dev_type();
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS_BASE::set_dev_type(const std::string& new_type)
{
  if (Umatch(new_type, "nmos ")) {
    polarity = pN;
  }else if (Umatch(new_type, "pmos ")) {
    polarity = pP;
  }else{
    MODEL_CARD::set_dev_type(new_type);
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS_BASE::precalc_first()
{
    const CARD_LIST* par_scope = scope();
    assert(par_scope);
    MODEL_CARD::precalc_first();
    e_val(&(this->level), 1, par_scope);
    e_val(&(this->wmax), INF, par_scope);
    e_val(&(this->wmin), 0., par_scope);
    e_val(&(this->lmax), INF, par_scope);
    e_val(&(this->lmin), 0., par_scope);
    e_val(&(this->is), mDEFAULT_is, par_scope);
    e_val(&(this->js), NA, par_scope);
    e_val(&(this->rsh), 0.0, par_scope);
    e_val(&(this->rd), 0.0, par_scope);
    e_val(&(this->rs), 0.0, par_scope);
    e_val(&(this->cbd), NA, par_scope);
    e_val(&(this->cbs), NA, par_scope);
    e_val(&(this->cgso), 0.0, par_scope);
    e_val(&(this->cgdo), 0.0, par_scope);
    e_val(&(this->cgbo), 0.0, par_scope);
    e_val(&(this->cmodel), 0, par_scope);
    e_val(&(this->xl), 0.0, par_scope);
    e_val(&(this->xw), 0.0, par_scope);
    e_val(&(this->lmlt), 1.0, par_scope);
    e_val(&(this->wmlt), 1.0, par_scope);
    e_val(&(this->del), 0.0, par_scope);
    e_val(&(this->ld), 0.0, par_scope);
    e_val(&(this->wd), 0.0, par_scope);
    // final adjust: code_pre
    // final adjust: override
    // final adjust: raw
    e_val(&(this->level), 1, par_scope);
    e_val(&(this->wmax), INF, par_scope);
    e_val(&(this->wmin), 0., par_scope);
    e_val(&(this->lmax), INF, par_scope);
    e_val(&(this->lmin), 0., par_scope);
    e_val(&(this->is), mDEFAULT_is, par_scope);
    e_val(&(this->js), NA, par_scope);
    e_val(&(this->rsh), 0.0, par_scope);
    e_val(&(this->rd), 0.0, par_scope);
    e_val(&(this->rs), 0.0, par_scope);
    e_val(&(this->cbd), NA, par_scope);
    e_val(&(this->cbs), NA, par_scope);
    e_val(&(this->cgso), 0.0, par_scope);
    e_val(&(this->cgdo), 0.0, par_scope);
    e_val(&(this->cgbo), 0.0, par_scope);
    e_val(&(this->cmodel), 0, par_scope);
    e_val(&(this->xl), 0.0, par_scope);
    e_val(&(this->xw), 0.0, par_scope);
    e_val(&(this->lmlt), 1.0, par_scope);
    e_val(&(this->wmlt), 1.0, par_scope);
    e_val(&(this->del), 0.0, par_scope);
    e_val(&(this->ld), 0.0, par_scope);
    e_val(&(this->wd), 0.0, par_scope);
    // final adjust: mid
    // final adjust: calculated
    tnom_k = _tnom_c + P_CELSIUS0;
    egap = 1.16 - (7.02e-4*tnom_k*tnom_k) / (tnom_k+1108.);
    // final adjust: post

      if ((!has_hard_value(rs)) && has_hard_value(rd)) {untested();//106
	error(((!_sim->is_first_expand()) ? (bDEBUG) : (bWARNING)),
	      long_label() + ": rd input, but not rs. setting rs = 0.\n");
	rs.set_default(0.);
      }else if ((!has_hard_value(rd)) && has_hard_value(rs)) {untested();//109
	error(((!_sim->is_first_expand()) ? (bDEBUG) : (bWARNING)), 
	      long_label() + ": rs input, but not rd. setting rd = 0.\n");
	rd.set_default(0.);
      }else{
	/* rd, rs are ok, either have both or neither */
      }
      
      if (has_hard_value(rsh)
	  &&  (has_hard_value(rd) || has_hard_value(rs))) {
	error(((!_sim->is_first_expand()) ? (bDEBUG) : (bWARNING)),
	      long_label() + ": rsh - rs - rd conflict: using "
	      + (((rd <= 0.)  &&  (rs <= 0.)) ? "rsh" : "rs,rd") + '\n');
      }else if (!has_hard_value(rsh)
		&& (!has_hard_value(rd))
		&& (!has_hard_value(rs))) {
	// don't have anything
      }else{
	/* rsh, rd are ok, have one or other */
      }
      
      if (!has_hard_value(is) && !has_hard_value(js)) {
	/* don't have either, use default is */
      }else if (has_hard_value(is) && has_hard_value(js)) {
	error(((!_sim->is_first_expand()) ? (bDEBUG) : (bWARNING)),
	      long_label() + ": is - js conflict\n");
      }else{
	/* is, js are ok, have one or other */
      }
    // final adjust: done
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS_BASE::precalc_last()
{
    MODEL_CARD::precalc_last();
}
/*--------------------------------------------------------------------------*/
SDP_CARD* MODEL_BUILT_IN_MOS_BASE::new_sdp(COMMON_COMPONENT* c)const
{
  assert(c);
  if (COMMON_BUILT_IN_MOS* cc = dynamic_cast<COMMON_BUILT_IN_MOS*>(c)) {
    if (cc->_sdp) {
      cc->_sdp->init(cc);
      return cc->_sdp;
    }else{
      delete cc->_sdp;
      return new SDP_BUILT_IN_MOS_BASE(c);
    }
  }else{
    return MODEL_BUILT_IN_DIODE::new_sdp(c);
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS_BASE::set_param_by_index(int i, std::string& value, int offset)
{
  switch (MODEL_BUILT_IN_MOS_BASE::param_count() - 1 - i) {
  case 0: untested(); break;
  case 1: _tnom_c = value; break;
  case 2: fc = value; break;
  case 3: pb = value; break;
  case 4: cjo = value; break;
  case 5: mj = value; break;
  case 6: cjsw = value; break;
  case 7: pbsw = value; break;
  case 8: mjsw = value; break;
  case 9: kf = value; break;
  case 10: af = value; break;
  case 11: level = value; break;
  case 12: wmax = value; break;
  case 13: wmin = value; break;
  case 14: lmax = value; break;
  case 15: lmin = value; break;
  case 16: is = value; break;
  case 17: js = value; break;
  case 18: rsh = value; break;
  case 19: rd = value; break;
  case 20: rs = value; break;
  case 21: cbd = value; break;
  case 22: cbs = value; break;
  case 23: cgso = value; break;
  case 24: cgdo = value; break;
  case 25: cgbo = value; break;
  case 26: cmodel = value; break;
  case 27: xl = value; break;
  case 28: xw = value; break;
  case 29: lmlt = value; break;
  case 30: wmlt = value; break;
  case 31: del = value; break;
  case 32: ld = value; break;
  case 33: wd = value; break;
  default: throw Exception_Too_Many(i, 33, offset); break;
  }
}
/*--------------------------------------------------------------------------*/
bool MODEL_BUILT_IN_MOS_BASE::param_is_printable(int i)const
{
  switch (MODEL_BUILT_IN_MOS_BASE::param_count() - 1 - i) {
  case 0:  return (false);
  case 1:  return (true);
  case 2:  return (true);
  case 3:  return (true);
  case 4:  return (true);
  case 5:  return (true);
  case 6:  return (true);
  case 7:  return (pbsw != pb);
  case 8:  return (true);
  case 9:  return (has_good_value(kf));
  case 10:  return (has_good_value(af));
  case 11:  return (false);
  case 12:  return (wmax<INF);
  case 13:  return (wmin>0);
  case 14:  return (lmax<INF);
  case 15:  return (lmin>0);
  case 16:  return (true);
  case 17:  return (js.has_hard_value());
  case 18:  return (has_hard_value(rsh));
  case 19:  return (has_hard_value(rd));
  case 20:  return (has_hard_value(rs));
  case 21:  return (cbd.has_hard_value());
  case 22:  return (cbs.has_hard_value());
  case 23:  return (true);
  case 24:  return (true);
  case 25:  return (true);
  case 26:  return (false);
  case 27:  return (xl!=0.0);
  case 28:  return (xw!=0.0);
  case 29:  return (lmlt!=1.0);
  case 30:  return (wmlt!=1.0);
  case 31:  return (del!=0.0);
  case 32:  return (true);
  case 33:  return (wd!=0.0);
  default: return false;
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS_BASE::param_name(int i)const
{
  switch (MODEL_BUILT_IN_MOS_BASE::param_count() - 1 - i) {
  case 0:  return "=====";
  case 1:  return "tnom";
  case 2:  return "fc";
  case 3:  return "pb";
  case 4:  return "cj";
  case 5:  return "mj";
  case 6:  return "cjsw";
  case 7:  return "pbsw";
  case 8:  return "mjsw";
  case 9:  return "kf";
  case 10:  return "af";
  case 11:  return "level";
  case 12:  return "wmax";
  case 13:  return "wmin";
  case 14:  return "lmax";
  case 15:  return "lmin";
  case 16:  return "is";
  case 17:  return "js";
  case 18:  return "rsh";
  case 19:  return "rd";
  case 20:  return "rs";
  case 21:  return "cbd";
  case 22:  return "cbs";
  case 23:  return "cgso";
  case 24:  return "cgdo";
  case 25:  return "cgbo";
  case 26:  return "cmodel";
  case 27:  return "xl";
  case 28:  return "xw";
  case 29:  return "lmlt";
  case 30:  return "wmlt";
  case 31:  return "del";
  case 32:  return "ld";
  case 33:  return "wd";
  default: return "";
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS_BASE::param_name(int i, int j)const
{
  if (j == 0) {
    return param_name(i);
  }else if (j == 1) {
    switch (MODEL_BUILT_IN_MOS_BASE::param_count() - 1 - i) {
    case 0:  return "";
    case 1:  return "";
    case 2:  return "";
    case 3:  return "";
    case 4:  return "";
    case 5:  return "";
    case 6:  return "";
    case 7:  return "";
    case 8:  return "";
    case 9:  return "";
    case 10:  return "";
    case 11:  return "";
    case 12:  return "";
    case 13:  return "";
    case 14:  return "";
    case 15:  return "";
    case 16:  return "";
    case 17:  return "";
    case 18:  return "";
    case 19:  return "";
    case 20:  return "";
    case 21:  return "";
    case 22:  return "";
    case 23:  return "cgs";
    case 24:  return "cgd";
    case 25:  return "cgb";
    case 26:  return "";
    case 27:  return "dl\0ldel";
    case 28:  return "dw\0wdel";
    case 29:  return "";
    case 30:  return "";
    case 31:  return "";
    case 32:  return "dlat\0ladt";
    case 33:  return "";
    default: return "";
    }
  }else{
    return "";
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS_BASE::param_value(int i)const
{
  switch (MODEL_BUILT_IN_MOS_BASE::param_count() - 1 - i) {
  case 0:  unreachable(); return "";
  case 1:  return _tnom_c.string();
  case 2:  return fc.string();
  case 3:  return pb.string();
  case 4:  return cjo.string();
  case 5:  return mj.string();
  case 6:  return cjsw.string();
  case 7:  return pbsw.string();
  case 8:  return mjsw.string();
  case 9:  return kf.string();
  case 10:  return af.string();
  case 11:  return level.string();
  case 12:  return wmax.string();
  case 13:  return wmin.string();
  case 14:  return lmax.string();
  case 15:  return lmin.string();
  case 16:  return is.string();
  case 17:  return js.string();
  case 18:  return rsh.string();
  case 19:  return rd.string();
  case 20:  return rs.string();
  case 21:  return cbd.string();
  case 22:  return cbs.string();
  case 23:  return cgso.string();
  case 24:  return cgdo.string();
  case 25:  return cgbo.string();
  case 26:  return cmodel.string();
  case 27:  return xl.string();
  case 28:  return xw.string();
  case 29:  return lmlt.string();
  case 30:  return wmlt.string();
  case 31:  return del.string();
  case 32:  return ld.string();
  case 33:  return wd.string();
  default: return "";
  }
}
/*--------------------------------------------------------------------------*/
bool MODEL_BUILT_IN_MOS_BASE::is_valid(const COMPONENT* d)const
{
  assert(d);
  const COMMON_BUILT_IN_MOS* c = dynamic_cast<const COMMON_BUILT_IN_MOS*>(d->common());
  if (!c) {
    return MODEL_BUILT_IN_DIODE::is_valid(d);
  }else{
    const MODEL_BUILT_IN_MOS_BASE* m = this;
    c->l_in.e_val(OPT::defl,d->scope());
    c->w_in.e_val(OPT::defw,d->scope());
    m->lmin.e_val(0,m->scope());
    m->lmax.e_val(INF,m->scope());
    m->wmin.e_val(0,m->scope());
    m->wmax.e_val(INF,m->scope());
    return c->l_in >= m->lmin && c->l_in <= m->lmax
      && c->w_in >= m->wmin && c->w_in <= m->wmax;
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS_BASE::tr_eval(COMPONENT*)const
{untested();//425
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
