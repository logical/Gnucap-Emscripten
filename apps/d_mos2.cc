/* $Id: d_mos2.model,v 26.133 2009/11/26 04:58:04 al Exp $ -*- C++ -*-
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
 * mos model equations: spice level 2 equivalent
 */
/* This file is automatically generated. DO NOT EDIT */

#include "l_compar.h"
#include "l_denoise.h"
#include "globals.h"
#include "e_elemnt.h"
#include "d_mos2.h"
/*--------------------------------------------------------------------------*/
const double NA(NOT_INPUT);
const double INF(BIGBIG);
/*--------------------------------------------------------------------------*/
int MODEL_BUILT_IN_MOS2::_count = 0;
/*--------------------------------------------------------------------------*/
const int LEVEL(2);
/*--------------------------------------------------------------------------*/
void d_mos2(void) { 
  static DEV_BUILT_IN_MOS p1d;
  static MODEL_BUILT_IN_MOS2 p1(&p1d);
  static DISPATCHER<MODEL_CARD>::INSTALL
    d1(&model_dispatcher, "nmos2|pmos2", &p1);
}
/*--------------------------------------------------------------------------*/
void SDP_BUILT_IN_MOS2::init(const COMMON_COMPONENT* cc)
{
  assert(cc);
  SDP_BUILT_IN_MOS123::init(cc);
  const COMMON_BUILT_IN_MOS* c = prechecked_cast<const COMMON_BUILT_IN_MOS*>(cc);
  assert(c);
  const MODEL_BUILT_IN_MOS2* m = prechecked_cast<const MODEL_BUILT_IN_MOS2*>(c->model());
  assert(m);
  const CARD_LIST* par_scope = m->scope();
  assert(par_scope);
  // adjust: override
  // adjust: raw
  // adjust: calculated
    relxj = ((m->xj != NA && m->xj > 0)
	       ? .5 * m->xj / l_eff
	       : NA);
    eta_1 = ((cgate != 0)
	       ? M_PI_4 * P_EPS_SI * m->delta / cgate * l_eff
	       : 0.);
    eta = eta_1 + 1.;
    eta_2 = eta / 2.;
  // code_post
}
/*--------------------------------------------------------------------------*/
TDP_BUILT_IN_MOS2::TDP_BUILT_IN_MOS2(const DEV_BUILT_IN_MOS* d)
  :TDP_BUILT_IN_MOS123(d)
{
  assert(d);
  const COMMON_BUILT_IN_MOS* c = prechecked_cast<const COMMON_BUILT_IN_MOS*>(d->common());
  assert(c);
  const SDP_BUILT_IN_MOS2* s = prechecked_cast<const SDP_BUILT_IN_MOS2*>(c->sdp());
  assert(s);
  const MODEL_BUILT_IN_MOS2* m = prechecked_cast<const MODEL_BUILT_IN_MOS2*>(c->model());
  assert(m);
  const CARD_LIST* par_scope = d->scope();
  assert(par_scope);
    // final adjust: code_pre

      double temp = d->_sim->_temp_c + P_CELSIUS0;
      double tempratio  = temp / m->tnom_k; // ratio
      double tempratio4 = tempratio * sqrt(tempratio);
      double kt = temp * P_K;
      double egap = 1.16 - (7.02e-4*temp*temp) / (temp+1108.);
      double arg = (m->egap*tempratio - egap) / (2*kt);
    // final adjust: override
    // final adjust: raw
    // final adjust: mid
    // final adjust: calculated
    vt = temp * P_K_Q;
    phi = m->phi*tempratio + (-2*vt*(1.5*log(tempratio)+P_Q*(arg)));
    sqrt_phi = sqrt(phi);
    phi_sqrt_phi = phi * sqrt_phi;
    beta = (m->kp / tempratio4) * s->w_eff / s->l_eff;
    uo = m->uo * tempratio4;
    vbi = (fixzero(
	(m->vto - m->gamma * sqrt(m->phi)
	 +.5*(m->egap-egap) + m->polarity* .5 * (phi-m->phi)), m->phi));
    // final adjust: post
    // final adjust: done
}
/*--------------------------------------------------------------------------*/
MODEL_BUILT_IN_MOS2::MODEL_BUILT_IN_MOS2(const BASE_SUBCKT* p)
  :MODEL_BUILT_IN_MOS123(p),
   kp(NA),
   nfs_cm(0.0),
   vmax(NA),
   neff(1.0),
   ucrit_cm(1e4),
   uexp(NA),
   utra(NA),
   delta(0.0),
   nfs(NA),
   ucrit(NA),
   calc_kp(false),
   alpha(NA),
   xd(NA),
   xwb(NA),
   vbp(NA),
   cfsox(NA)
{
  if (ENV::run_mode != rPRE_MAIN) {
    ++_count;
  }else{
  }
  set_default(&mjsw, .33);
  set_default(&tox, 1e-7);
  set_default(&cox, NA);
  set_default(&vto, NA);
  set_default(&gamma, NA);
  set_default(&phi, NA);
  set_default(&mos_level, LEVEL);
}
/*--------------------------------------------------------------------------*/
MODEL_BUILT_IN_MOS2::MODEL_BUILT_IN_MOS2(const MODEL_BUILT_IN_MOS2& p)
  :MODEL_BUILT_IN_MOS123(p),
   kp(p.kp),
   nfs_cm(p.nfs_cm),
   vmax(p.vmax),
   neff(p.neff),
   ucrit_cm(p.ucrit_cm),
   uexp(p.uexp),
   utra(p.utra),
   delta(p.delta),
   nfs(p.nfs),
   ucrit(p.ucrit),
   calc_kp(p.calc_kp),
   alpha(p.alpha),
   xd(p.xd),
   xwb(p.xwb),
   vbp(p.vbp),
   cfsox(p.cfsox)
{
  if (ENV::run_mode != rPRE_MAIN) {
    ++_count;
  }else{untested();//194
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS2::dev_type()const
{
  if (polarity == pN) {
    return "nmos2";
  }else if (polarity == pP) {
    return "pmos2";
  }else{untested();//235
    return MODEL_BUILT_IN_MOS123::dev_type();
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS2::set_dev_type(const std::string& new_type)
{
  if (Umatch(new_type, "nmos2 ")) {
    polarity = pN;
  }else if (Umatch(new_type, "pmos2 ")) {
    polarity = pP;
  }else{
    MODEL_BUILT_IN_MOS123::set_dev_type(new_type);
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS2::precalc_first()
{
    const CARD_LIST* par_scope = scope();
    assert(par_scope);
    MODEL_BUILT_IN_MOS123::precalc_first();
    e_val(&(this->kp), NA, par_scope);
    e_val(&(this->nfs_cm), 0.0, par_scope);
    e_val(&(this->vmax), NA, par_scope);
    e_val(&(this->neff), 1.0, par_scope);
    e_val(&(this->ucrit_cm), 1e4, par_scope);
    e_val(&(this->uexp), NA, par_scope);
    e_val(&(this->utra), NA, par_scope);
    e_val(&(this->delta), 0.0, par_scope);
    // final adjust: code_pre
      
      if (!has_good_value(tox)) {
	tox = 1e-7;
      }
      cox = P_EPS_OX / tox;
      if (kp == NA) {
	kp = uo * cox;
	calc_kp = true;
      }
      if (nsub != NA) {
	if (phi == NA) {
	  phi = (2. * P_K_Q) * tnom_k * log(nsub/NI);
	  if (phi < .1) {
	    untested();
	    error(((!_sim->is_first_expand()) ? (bDEBUG) : (bWARNING)),
		  long_label() + ": calculated phi too small, using .1\n");
	    phi = .1;
	  }
	  calc_phi = true;
	}
	if (gamma == NA) {
	  gamma = sqrt(2. * P_EPS_SI * P_Q * nsub) / cox;
	  calc_gamma = true;
	}
	if (vto == NA) {
	  double phi_ms = (tpg == gtMETAL)
	    ? polarity * (-.05 - (egap + polarity * phi) / 2.)
	    : -(tpg * egap + phi) / 2.;
	  double vfb = phi_ms - polarity * P_Q * nss / cox;
	  vto = vfb + phi + gamma * sqrt(phi);
	  calc_vto = true;
	}
      }
    // final adjust: override
    if (cox == NA) {
      cox = P_EPS_OX/tox;
    }else{
    }
    if (vto == NA) {
      vto = 0.0;
    }else{
    }
    if (gamma == NA) {
      gamma = 0.0;
    }else{
    }
    if (phi == NA) {
      phi = 0.6;
    }else{
    }
    // final adjust: raw
    e_val(&(this->kp), 2e-5, par_scope);
    e_val(&(this->nfs_cm), 0.0, par_scope);
    e_val(&(this->vmax), NA, par_scope);
    e_val(&(this->neff), 1.0, par_scope);
    e_val(&(this->ucrit_cm), 1e4, par_scope);
    e_val(&(this->uexp), NA, par_scope);
    e_val(&(this->utra), NA, par_scope);
    e_val(&(this->delta), 0.0, par_scope);
    // final adjust: mid
    // final adjust: calculated
    nfs = nfs_cm*ICM2M2;
    ucrit = ucrit_cm*ICM2M;
    alpha = ((nsub != NA)
	? (2. * P_EPS_SI) / (P_Q * nsub)
	: 0.);
    xd = sqrt(alpha);
    xwb = ((nsub != NA)
	? xd * sqrt(pb)
	: .25e-6);
    vbp = ucrit * P_EPS_SI / cox;
    cfsox = P_Q * nfs / cox;
    // final adjust: post
    // final adjust: done
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS2::precalc_last()
{
    MODEL_BUILT_IN_MOS123::precalc_last();
}
/*--------------------------------------------------------------------------*/
SDP_CARD* MODEL_BUILT_IN_MOS2::new_sdp(COMMON_COMPONENT* c)const
{
  assert(c);
  if (COMMON_BUILT_IN_MOS* cc = dynamic_cast<COMMON_BUILT_IN_MOS*>(c)) {
    if (cc->_sdp) {
      cc->_sdp->init(cc);
      return cc->_sdp;
    }else{
      delete cc->_sdp;
      return new SDP_BUILT_IN_MOS2(c);
    }
  }else{
    return MODEL_BUILT_IN_MOS123::new_sdp(c);
  }
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS2::set_param_by_index(int i, std::string& value, int offset)
{
  switch (MODEL_BUILT_IN_MOS2::param_count() - 1 - i) {
  case 0: level = value; break; //2
  case 1: unreachable(); break;
  case 2: unreachable(); break;
  case 3: unreachable(); break;
  case 4: unreachable(); break;
  case 5: unreachable(); break;
  case 6: unreachable(); break;
  case 7: mos_level = value; break;
  case 8: kp = value; break;
  case 9: nfs_cm = value; break;
  case 10: vmax = value; break;
  case 11: neff = value; break;
  case 12: ucrit_cm = value; break;
  case 13: uexp = value; break;
  case 14: utra = value; break;
  case 15: delta = value; break;
  default: MODEL_BUILT_IN_MOS123::set_param_by_index(i, value, offset); break;
  }
}
/*--------------------------------------------------------------------------*/
bool MODEL_BUILT_IN_MOS2::param_is_printable(int i)const
{
  switch (MODEL_BUILT_IN_MOS2::param_count() - 1 - i) {
  case 0:  return (true);
  case 1:  return (false);
  case 2:  return (false);
  case 3:  return (false);
  case 4:  return (false);
  case 5:  return (false);
  case 6:  return (false);
  case 7:  return (mos_level != LEVEL);
  case 8:  return (!calc_kp);
  case 9:  return (true);
  case 10:  return (vmax.has_hard_value());
  case 11:  return (neff != 1.0 || lambda == NA);
  case 12:  return (ucrit_cm != 1e4 || uexp != NA);
  case 13:  return (uexp.has_hard_value());
  case 14:  return (false);
  case 15:  return (true);
  default: return MODEL_BUILT_IN_MOS123::param_is_printable(i);
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS2::param_name(int i)const
{
  switch (MODEL_BUILT_IN_MOS2::param_count() - 1 - i) {
  case 0:  return "level";
  case 1:  return "=====";
  case 2:  return "=====";
  case 3:  return "=====";
  case 4:  return "=====";
  case 5:  return "=====";
  case 6:  return "=====";
  case 7:  return "diodelevel";
  case 8:  return "kp";
  case 9:  return "nfs";
  case 10:  return "vmax";
  case 11:  return "neff";
  case 12:  return "ucrit";
  case 13:  return "uexp";
  case 14:  return "utra";
  case 15:  return "delta";
  default: return MODEL_BUILT_IN_MOS123::param_name(i);
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS2::param_name(int i, int j)const
{
  if (j == 0) {
    return param_name(i);
  }else if (j == 1) {
    switch (MODEL_BUILT_IN_MOS2::param_count() - 1 - i) {
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
    default: return MODEL_BUILT_IN_MOS123::param_name(i, j);
    }
  }else if (i < 16) {
    return "";
  }else{
    return MODEL_BUILT_IN_MOS123::param_name(i, j);
  }
}
/*--------------------------------------------------------------------------*/
std::string MODEL_BUILT_IN_MOS2::param_value(int i)const
{
  switch (MODEL_BUILT_IN_MOS2::param_count() - 1 - i) {
  case 0:  return "2";
  case 1:  unreachable(); return "";
  case 2:  unreachable(); return "";
  case 3:  unreachable(); return "";
  case 4:  unreachable(); return "";
  case 5:  unreachable(); return "";
  case 6:  unreachable(); return "";
  case 7:  return mos_level.string();
  case 8:  return kp.string();
  case 9:  return nfs_cm.string();
  case 10:  return vmax.string();
  case 11:  return neff.string();
  case 12:  return ucrit_cm.string();
  case 13:  return uexp.string();
  case 14:  return utra.string();
  case 15:  return delta.string();
  default: return MODEL_BUILT_IN_MOS123::param_value(i);
  }
}
/*--------------------------------------------------------------------------*/
bool MODEL_BUILT_IN_MOS2::is_valid(const COMPONENT* d)const
{
  assert(d);
  return MODEL_BUILT_IN_MOS123::is_valid(d);
}
/*--------------------------------------------------------------------------*/
void MODEL_BUILT_IN_MOS2::tr_eval(COMPONENT* brh)const
{
  DEV_BUILT_IN_MOS* d = prechecked_cast<DEV_BUILT_IN_MOS*>(brh);
  assert(d);
  const COMMON_BUILT_IN_MOS* c = prechecked_cast<const COMMON_BUILT_IN_MOS*>(d->common());
  assert(c);
  const SDP_BUILT_IN_MOS2* s = prechecked_cast<const SDP_BUILT_IN_MOS2*>(c->sdp());
  assert(s);
  const MODEL_BUILT_IN_MOS2* m = this;
  const TDP_BUILT_IN_MOS2 T(d);
  const TDP_BUILT_IN_MOS2* t = &T;

    #define short_channel	(m->xj != NOT_INPUT  &&  m->xj > 0.)
    #define do_subthreshold	(m->nfs != 0.)
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    trace1(d->long_label().c_str(), d->evaliter());
    trace3("", d->vds, d->vgs, d->vbs);
    assert(m->tnom_k > 0);
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    d->reverse_if_needed();
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    double v_phi_s = t->phi - d->vbs;
    double sarg, dsarg_dvbs, d2sdb2, sarg3;
    {
      if (d->vbs <= 0.) {
	sarg = sqrt(v_phi_s);
	dsarg_dvbs = -.5 / sarg;
	d2sdb2 = .5 * dsarg_dvbs / v_phi_s;
	d->sbfwd = false;
	trace3("sb-ok", sarg, v_phi_s, dsarg_dvbs);
      }else{
	if (OPT::mosflags & 01000) {
	  sarg = t->sqrt_phi / (1. + .5 * d->vbs / t->phi);
	  dsarg_dvbs = -.5 * sarg * sarg / t->phi_sqrt_phi;
	  d2sdb2 = -dsarg_dvbs * sarg / t->phi_sqrt_phi;
	  untested();
	  trace3("***sb-reversed(01000)***", sarg, v_phi_s, dsarg_dvbs);
	}else{
	  sarg = t->sqrt_phi 
	    / (1. + .5 * d->vbs / t->phi 
	       + .375 * d->vbs * d->vbs / (t->phi * t->phi));
	  dsarg_dvbs = (-.5 * sarg * sarg / t->phi_sqrt_phi) 
	    * (1. + 1.5 * d->vbs / t->phi);
	  d2sdb2 = (-dsarg_dvbs * sarg / t->phi_sqrt_phi)
	    - (.75 * sarg / (t->phi_sqrt_phi * t->phi)) 
	    * (2. * d->vbs * dsarg_dvbs + sarg);
	  untested();
	  trace3("***sb-reversed(00000)***", sarg, v_phi_s, dsarg_dvbs);
	}
	d->sbfwd = true;
      }
      sarg3 = sarg*sarg*sarg;
      assert(sarg > 0.);
      assert(dsarg_dvbs < 0.);
      assert(up_order(-1/t->phi, d2sdb2, 1/t->phi));
      trace2("", d2sdb2, sarg3);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    double barg, dbarg_dvbs, d2bdb2;
    {
      double vbd = d->vbs - d->vds;
      double v_phi_d = t->phi - vbd;
      if (vbd <= 0.) {
	barg = sqrt(v_phi_d);
	dbarg_dvbs = -.5 / barg;
	d2bdb2 = .5 * dbarg_dvbs / v_phi_d;
	//d->dbfwd = false;
	trace4("db-ok", barg, v_phi_d, dbarg_dvbs, d2bdb2);
      }else{
	if (OPT::mosflags & 01000) {
	  barg = t->sqrt_phi / (1. + .5 * vbd / t->phi);
	  dbarg_dvbs = -.5 * barg * barg / t->phi_sqrt_phi;
	  d2bdb2 = -dbarg_dvbs * barg / t->phi_sqrt_phi;
	  untested();
	  trace4("***db-reversed(00000)***",barg, v_phi_d, dbarg_dvbs, d2bdb2);
	}else{
	  barg = t->sqrt_phi 
	    / (1. + .5 * vbd / t->phi 
	       + .375 * vbd * vbd / (t->phi * t->phi));
	  dbarg_dvbs = (-.5 * barg * barg / t->phi_sqrt_phi) 
	    * (1. + 1.5 * vbd / t->phi);
	  d2bdb2 = (-dbarg_dvbs * barg / t->phi_sqrt_phi)
	    - (.75 * barg / (t->phi_sqrt_phi * t->phi)) 
	    * (2. * vbd * dbarg_dvbs + barg);
	  trace4("***db-reversed(00000)***",barg, v_phi_d, dbarg_dvbs, d2bdb2);
	}
	//d->dbfwd = true;
      }
      assert(barg > 0.);
      assert(dbarg_dvbs < 0.);
      assert(up_order(-1/t->phi, d2bdb2, 1/t->phi));
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    double gamma_s, dgamma_s_dvds, dgamma_s_dvbs, dgddb2;
    {
      if (short_channel) {
	double argxd = 1. + 2. * barg * m->xd / m->xj;
	assert(argxd > 0);
	double argd = sqrt(argxd);
	trace2("", argxd, argd);
	
	double alpha_d = s->relxj * (argd - 1.);
	double dalpha_d_dvds = m->xd / (4. * s->l_eff * argd * barg);
	double dalpha_d_dvbs = -dalpha_d_dvds;
	trace3("", alpha_d, dalpha_d_dvds, dalpha_d_dvbs);
	
	double argxs = 1. + 2. * sarg * m->xd / m->xj;
	assert(argxs > 0);
	double args = sqrt(argxs);
	trace2("", argxs, args);
	
	double alpha_s = s->relxj * (args - 1.);
	double dalpha_s_dvbs = -m->xd / (4. * s->l_eff * args * sarg);
	trace2("", alpha_s, dalpha_s_dvbs);
	
	gamma_s = m->gamma * (1. - alpha_s - alpha_d);
	dgamma_s_dvds = -m->gamma *  dalpha_d_dvds;
	dgamma_s_dvbs = -m->gamma * (dalpha_d_dvbs + dalpha_s_dvbs);
	
	double dasdb2=-m->xd*(d2sdb2+dsarg_dvbs*dsarg_dvbs*m->xd/(m->xj*argxs))
	  / (s->l_eff*args);
	double daddb2=-m->xd*(d2bdb2+dbarg_dvbs*dbarg_dvbs*m->xd/(m->xj*argxd))
	  / (s->l_eff*argd);
	dgddb2 = -.5 * m->gamma * (dasdb2 + daddb2);
	
	if (gamma_s <= 0. && m->gamma > 0.) {
	  untested();
	  error(bTRACE, d->long_label() + ": gamma is negative\n");
	  error(bTRACE, "+   gamma_s=%g, alpha_s=%g, alpha_d=%g\n",
		gamma_s,    alpha_s,    alpha_d);
	}
	trace4("no short chan", gamma_s, dgamma_s_dvds, dgamma_s_dvds, dgddb2);
      }else{
	gamma_s = m->gamma;
	dgamma_s_dvds = dgamma_s_dvbs = 0.;
	dgddb2 = 0.;
	trace4("short channel", gamma_s, dgamma_s_dvds, dgamma_s_dvds, dgddb2);
      }
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    /* von, subthreshold, cutoff, vgst */
    double vc, vc_eta, dvon_dvbs;
    double xn, vtxn, dxn_dvbs;	/* subthreshold only */
    {
      double vbin = t->vbi + s->eta_1 * v_phi_s;
      d->von = vbin + gamma_s * sarg;
      dvon_dvbs = -s->eta_1 + dgamma_s_dvbs * sarg + gamma_s * dsarg_dvbs;
      trace3("guess", vbin, d->von, dvon_dvbs);
      
      if (do_subthreshold) {
	double cdonco = -(gamma_s*dsarg_dvbs + dgamma_s_dvbs*sarg) + s->eta_1;
	xn = 1. + m->cfsox + cdonco;
	vtxn = t->vt * xn;
	dxn_dvbs = 2. * dgamma_s_dvbs * dsarg_dvbs
	  + gamma_s * d2sdb2 + dgddb2 * sarg;
	trace3("do_sub", xn, vtxn, dxn_dvbs);
	
	d->von += vtxn;
	dvon_dvbs += t->vt * dxn_dvbs;
	d->vgst = d->vgs - d->von;
	trace3("", d->von, dvon_dvbs, d->vgst);
	
	d->subthreshold = (d->vgs < d->von);
	d->cutoff = false;
      }else{
	xn = vtxn = dxn_dvbs = 0.;
	d->vgst = d->vgs - d->von;
	trace3("no_sub", xn, vtxn, dxn_dvbs);
	trace3("", d->von, dvon_dvbs, d->vgst);
	
	d->subthreshold = false;
	d->cutoff = (d->vgs < d->von);
	if (d->cutoff) {
	  trace0("***** cut off *****");
	  d->ids = 0.;
	  d->gmf = d->gmr = 0.;
	  d->gds = 0.;
	  d->gmbf = d->gmbr = 0.;
	  return;
	}
      }
      double vgsx = (d->subthreshold) ? d->von : d->vgs;
      vc = vgsx - vbin;
      vc_eta = vc / s->eta;
      trace3("", vgsx, vc, vc_eta);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 

    double ufact, duf_dvgs, duf_dvds, duf_dvbs, ueff;
    {
      if (m->uexp != NOT_INPUT  &&  d->vgst > m->vbp) {
	ufact = pow(m->vbp/d->vgst, m->uexp);
	duf_dvgs = -ufact * m->uexp / d->vgst;
	duf_dvds = 0.;	/* wrong, but as per spice2 */
	duf_dvbs = dvon_dvbs * ufact * m->uexp / d->vgst;
	trace4("calc ufact", ufact, duf_dvgs, duf_dvds, duf_dvbs);
      }else{
	ufact = 1.;
	duf_dvgs = duf_dvds = duf_dvbs = 0.;
	trace4("def ufact", ufact, duf_dvgs, duf_dvds, duf_dvbs);
      }
      ueff = t->uo * ufact;	/* ???? */
      trace2("", ufact, ueff);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    /* vdsat  according to Baum's Theory of scattering velocity saturation  */
    int use_vmax = m->vmax != NOT_INPUT;
    if (use_vmax) {
      double gammad = gamma_s / s->eta;
      double v1 = vc_eta + v_phi_s;
      double v2 = v_phi_s;
      double xv = m->vmax * s->l_eff / ueff;
      double a1 = gammad * (4./3.);
      double b1 = -2. * (v1+xv);
      double c1 = -2. * gammad * xv;			/* end of scope */
      double d1 = 2.*v1*(v2+xv) - v2*v2 - (4./3.)*gammad*sarg3;
      double a = -b1;					/* xv, v1, v2, sarg3 */
      double b = a1 * c1 - 4. * d1;
      double C = -d1 * (a1*a1 - 4.*b1) - c1*c1;
      double r = -a*a / 3. + b;
      double r3 = r*r*r;				/* r */
      double S = 2. * a*a*a / 27. - a*b / 3. + C;	/* b, c */
      double s2 = S*S;
      double p = s2 / 4. + r3 / 27.;			/* r */
      double y3;
      if (p < 0.) {					/* p */
	double ro = pow((-r3 / 27), (1./6.));		/* s2, r3 */
	double fi = atan(-2. * sqrt(-p) / S);
	y3 = 2. * ro * cos(fi/3.) - a / 3.;
      }else{
	double p2 = sqrt(p);
	double p3 = pow((fabs(-S/2.+p2)), (1./3.));
	double p4 = pow((fabs(-S/2.-p2)), (1./3.));	/* s */
	y3 = p3 + p4 - a / 3.;				/* a */
	untested();
      }
      
      double x4[8];
      int iknt = 0;
      if (a1*a1 / 4. - b1 + y3  < 0.  &&  y3*y3 / 4. - d1  < 0.) {
	untested();
	error(bWARNING,
	      "%s: internal error: a3,b4, a1=%g, b1=%g, y3=%g, d1=%g\n",
	      d->long_label().c_str(),    a1,    b1,    y3,    d1);
      }else{
	double a3 = sqrt(a1*a1 / 4. - b1 + y3);
	double b3 = sqrt(y3*y3 / 4. - d1);
	for (int i = 0;   i < 4;   i++) {
	  static const double sig1[4] = {1., -1., 1., -1.};
	  static const double sig2[4] = {1., 1., -1., -1.};
	  double a4 = a1 / 2. + sig1[i] * a3;
	  double b4 = y3 / 2. + sig2[i] * b3;		/* y3 */
	  double delta4 = a4*a4 / 4. - b4;
	  if (delta4 >= 0.) {
	    double sd4 = sqrt(delta4);
	    x4[iknt++] = - a4 / 2. + sd4;
	    x4[iknt++] = - a4 / 2. - sd4;		/* i */
	  }
	}
      }
      
      double xvalid = 0.;
      int root_count = 0;
      for (int j = 0;   j < iknt;   j++) {			/* iknt */
	if (x4[j] > 0.) {
	  double poly4 = x4[j]*x4[j]*x4[j]*x4[j]/* ~= 0, used as check	*/
	    + a1 * x4[j]*x4[j]*x4[j]		/* roundoff error not	*/
	    + b1 * x4[j]*x4[j]			/* propagated, so ok	*/
	    + c1 * x4[j]
	    + d1;				/* a1, b1, c1, d1 */
	  if (fabs(poly4) <= 1e-6) {
	    root_count++;
	    if (root_count <= 1) {		/* xvalid = min(x4[j]) */
	      xvalid=x4[j];
	    }
	    if (x4[j] <= xvalid) {
	      xvalid=x4[j];				/* x4[], j */
	    }else{
	      untested();
	    }
	  }
	}
      }
      if (root_count <= 0) {				/* root_count */
	error(bTRACE, d->long_label() + ": Baum's theory rejected\n");
	use_vmax = false;
	d->vdsat = 0.;
	trace1("use_vmax rejected", d->vdsat);
      }else{
	d->vdsat = xvalid*xvalid - v_phi_s;
	trace1("use_vmax", d->vdsat);
      }
    }else{
      d->vdsat = 0.;
      trace1("!use_vmax", d->vdsat);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    /* vdsat     according to Grove-Frohman equation  */
    double dvdsat_dvgs = NOT_VALID;
    double dvdsat_dvbs = NOT_VALID;
    if (!use_vmax) {
      if (gamma_s > 0.) {
	double argv = vc_eta + v_phi_s;
	if (argv > 0.) {
	  double gammad = gamma_s / s->eta;
	  double gammd2 = gammad * gammad;
	  double arg1 = sqrt(1. + 4. * argv / gammd2);
	  d->vdsat = vc_eta  +  gammd2 * (1.-arg1) / 2.;
	  dvdsat_dvgs = (1. - 1./arg1) / s->eta;
	  dvdsat_dvbs = (gammad * (1.-arg1) + 2.*argv / (gammad*arg1))
	    / s->eta * dgamma_s_dvbs
	    + 1./arg1 + s->eta_1 * dvdsat_dvgs;
	  trace3("!use_vmax,gamma>0,argv>0",d->vdsat,dvdsat_dvgs,dvdsat_dvbs);
	}else{
	  untested();
	  d->vdsat = 0.;
	  dvdsat_dvgs = dvdsat_dvbs = 0.;
	  error(bTRACE, d->long_label() + ": argv is negative\n");
	  trace2("argv<0", argv, vc);
	  trace3("!use_vmax,gamma>0,argv<=0",d->vdsat,dvdsat_dvgs,dvdsat_dvbs);
	}
      }else{
	d->vdsat = vc_eta;
	dvdsat_dvgs = 1.;
	dvdsat_dvbs = 0.;
	trace3("!use_vmax, gamma<=0", d->vdsat, dvdsat_dvgs, dvdsat_dvbs);
      }
    }else{
      /* dvdsat_dvgs, dvdsat_dvbs   deferred */
      trace3("use_vmax", d->vdsat, dvdsat_dvgs, dvdsat_dvbs);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    if (d->vdsat < 0.) {
      error(bWARNING,
	    "%s: calculated vdsat (%g) < 0.  using vdsat = 0.\n",
	    d->long_label().c_str(), d->vdsat);
      d->vdsat = 0.;
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    double bsarg, dbsarg_dvbs;
    {
      double vbdsat = d->vbs - d->vdsat;
      if (vbdsat <= 0.) {
	double v_phi_ds = t->phi - vbdsat;
	bsarg = sqrt(v_phi_ds);
	dbsarg_dvbs = -.5 / bsarg;
	trace3("vbdsat <= 0", vbdsat, bsarg, dbsarg_dvbs);
      }else{
	bsarg = t->sqrt_phi / (1. + .5 * vbdsat / t->phi);
	dbsarg_dvbs = -.5 * bsarg * bsarg / t->phi_sqrt_phi;
	untested();
	trace3("vbdsat > 0", vbdsat, bsarg, dbsarg_dvbs);
      }
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    /* local   dvdsat_dvgs, dvdsat_dvbs   maybe */
    {
      if (use_vmax) {
	double bodys = bsarg*bsarg*bsarg - sarg3;
	double gdbdvs =
	  2. * gamma_s * (bsarg*bsarg*dbsarg_dvbs - sarg*sarg*dsarg_dvbs);
	double argv = vc_eta - d->vdsat;
	double vqchan = argv - gamma_s * bsarg;
	double dqdsat = -1. + gamma_s * dbsarg_dvbs;
	double vl = m->vmax * s->l_eff;
	double dfunds = vl * dqdsat - ueff * vqchan;
	double dfundg = (vl - ueff * d->vdsat) / s->eta;
	double dfundb = -vl * (1. + dqdsat - s->eta_1 / s->eta)
	  + ueff * (gdbdvs - dgamma_s_dvbs * bodys / 1.5) / s->eta;
	dvdsat_dvgs = -dfundg / dfunds;
	dvdsat_dvbs = -dfundb / dfunds;
	trace2("use_vmax", dvdsat_dvgs, dvdsat_dvbs);
      }else{
	/* dvdsat_dvgs, dvdsat_dvbs   already set */
	trace2("!use_vmax", dvdsat_dvgs, dvdsat_dvbs);
      }
      assert(dvdsat_dvgs != NOT_VALID);
      assert(dvdsat_dvbs != NOT_VALID);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    double  dl_dvgs, dl_dvds, dl_dvbs, clfact;
    {
      if (d->vds >= 0.) {
	if (m->lambda == NOT_INPUT) {
	  double dldsat;
	  if (use_vmax) {
	    double xdv = m->xd / sqrt(m->neff);
	    double xlv = m->vmax * xdv / (2. * ueff);
	    double argv = d->vds - d->vdsat;
	    if (argv < 0.) {
	      argv = 0.;
	    }
	    double xls = sqrt(xlv*xlv + argv);
	    double dl = (xls-xlv) * xdv;
	    /* lambda = dl / (s->l_eff * d->vds); */
	    clfact = (1. - dl / s->l_eff);
	    dldsat = xdv / (2. * xls * s->l_eff);
	  }else{
	    double argv = (d->vds - d->vdsat) / 4.;
	    double sargv = sqrt(1. + argv*argv);
	    if (argv + sargv >= 0.) {
	      double dl = m->xd * sqrt(argv + sargv);
	      /* lambda = dl / (s->l_eff * d->vds); */
	      clfact = (1. - dl / s->l_eff);
	      /* dldsat = lambda * d->vds / (8. * sargv); */
	      dldsat = dl / (s->l_eff * 8. * sargv);
	    }else{
	      /* lambda = 0.; */
	      clfact = 1.;
	      dldsat = 0.;
	      untested();
	      error(bWARNING,
		    "%s: internal error: vds(%g) < vdsat(%g)\n",
		    d->long_label().c_str(), d->vds,   d->vdsat);
	    }
	  }
	  dl_dvgs =  dvdsat_dvgs * dldsat;
	  dl_dvds =              - dldsat;
	  dl_dvbs =  dvdsat_dvbs * dldsat;
	}else{
	  /* lambda = m->lambda; */
	  clfact = (1. - m->lambda * d->vds);
	  dl_dvgs = dl_dvbs = 0.;
	  dl_dvds = -m->lambda;
	}
	
	/* clfact = (1. - lambda * d->vds); */
	if (clfact < m->xwb/s->l_eff) {
	  double leff = m->xwb / (2. - (clfact * s->l_eff / m->xwb));
	  double dfact = (leff * leff) / (m->xwb * m->xwb);
	  clfact = leff / s->l_eff;
	  dl_dvgs *= dfact;
	  dl_dvds *= dfact;
	  dl_dvbs *= dfact;
	}
      }else{  /* vds <= 0. */
	/* lambda = 0.; */
	clfact = 1.;
	dl_dvgs = dl_dvds = dl_dvbs = 0.;
	trace1("*** vds < 0 ***", d->vds);
      }
      trace4("", dl_dvgs, dl_dvds, dl_dvbs, clfact);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */ 
    /* ids, gmf, gds, gmbf */
    {
      d->saturated = (d->vds > d->vdsat);
      double vdsx =  (d->saturated) ? d->vdsat : d->vds;
      double bargx = (d->saturated) ? bsarg : barg;
      double body = bargx*bargx*bargx - sarg3;
      double expg = (d->subthreshold) ? exp(d->vgst / vtxn) : 1.;
      trace4("", vdsx, bargx, body, expg);
      
      trace3("", t->beta, ufact, clfact);
      double beta = t->beta * ufact / clfact;
      double ids_on = 
	beta * ((vc - s->eta_2 * vdsx) * vdsx  - (2./3.) * gamma_s * body);
      trace4("", beta, vc, (s->eta*vdsx),  (gamma_s*bargx));
      double didvds = beta * (vc  -  s->eta * vdsx  -  gamma_s * bargx);
      fixzero(&didvds, ids_on);
      trace4("", beta, ids_on, didvds, d->saturated);
      
      d->ids = ids_on * expg;
      
      d->gmf = beta * vdsx;
      d->gmf += ids_on * (duf_dvgs/ufact - dl_dvgs/clfact);
      if (d->saturated) {
	d->gmf += didvds * dvdsat_dvgs;
      }
      if (d->subthreshold) {
	d->gmf = ids_on / vtxn;
	if (d->saturated) {
	  d->gmf += didvds * dvdsat_dvgs;
	}
	d->gmf *= expg;
      }
      
      d->gds = (d->saturated) ? 0.: didvds;
      d->gds += ids_on * (duf_dvds/ufact - dl_dvds/clfact);
      if (short_channel) {
	d->gds -= beta * (2./3.) * body * dgamma_s_dvds;
      }
      if (d->subthreshold) {
	double dxndvd = dgamma_s_dvds * dsarg_dvbs;
	double dodvds = dgamma_s_dvds * sarg + t->vt * dxndvd;
	double gmw = d->ids * d->vgst / (vtxn * xn);
	d->gds *= expg;
	d->gds -= d->gmf * dodvds + gmw * dxndvd;
      }
      
      d->gmbf = beta * (s->eta_1 * vdsx - gamma_s * (sarg - bargx));
      d->gmbf += ids_on * (duf_dvbs/ufact - dl_dvbs/clfact);
      if (short_channel) {
	d->gmbf -= beta * (2./3.) * body * dgamma_s_dvbs;
      }
      if (d->saturated) {
	d->gmbf += didvds * dvdsat_dvbs;
      }
      if (d->subthreshold) {
	double gmw = d->ids * d->vgst / (vtxn * xn);
	d->gmbf += beta * dvon_dvbs * vdsx;
	d->gmbf *= expg;
	d->gmbf -= d->gmf * dvon_dvbs + gmw * dxn_dvbs;
      }
      trace4("", d->ids, d->gmf, d->gds, d->gmbf);
    }
    if (d->reversed) {
      d->ids *= -1;
      d->gmr = d->gmf;
      d->gmbr = d->gmbf;
      d->gmf = d->gmbf = 0;
    }else{
      d->gmr = d->gmbr = 0.;
    }
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
