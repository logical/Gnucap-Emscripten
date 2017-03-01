CCP = em++
CC = emcc

OPTIMIZE = -s DISABLE_EXCEPTION_CATCHING=0 -O2
INCLUDES = -Iinclude/
CFLAGS = -DEMSCRIPTEN -DNDEBUG -DUNIX -Dlinux -DSPICE_3f -DPREDICTOR -DAN_pz -DAN_disto -DAN_noise -DHAS_STDLIB $(OPTIMIZE)
CPPFLAGS = $(CFLAGS) -std=c++11


LIBFILES = globals \
m_expression_dump m_expression_in m_expression_reduce \
m_base_in m_base_math m_fft  m_spline \
ap_construct ap_convert ap_error ap_get ap_match ap_skip \
l_ftos l_pmatch l_timer l_trim l_wmatch \
io io_contr io_error io_findf io_out io_xopen \
u_lang u_nodemap u_opt1 u_opt2 \
u_parameter u_prblst u_probe u_sim_data u_xprobe \
d_subckt d_logic d_logicmod \
e_base e_card e_node e_model e_compon \
e_elemnt e_ccsrc e_storag e_cardlist \
bm_cond bm_value bm \
c__cmd c_attach c_file \
findbr plot

APPFILES = \
d_diode  d_bjt d_mos_base d_mos d_mos1 d_mos2 d_mos3 d_mos4 d_mos5 d_mos6 d_mos7 d_mos8 d_mos123 \
d_admit d_cap d_cccs d_ccvs d_coil d_cs d_poly_g d_poly_cap d_res d_switch \
d_trln d_vcg d_vcr d_vcvs d_vs d_meter bm_complex bm_exp bm_fit bm_generator bm_model bm_poly bm_posy bm_pulse bm_pwl bm_sffm \
bm_sin bm_tanh bmm_table bmm_semi c_clear c_comand c_delete c_exp c_genrat c_help c_list c_measure c_modify \
c_param c_prbcmd c_status c_sweep c_sim c_system s__init s__out s__solve s_ac s_dc s_fo s_tr s_tr_set s_tr_swp lang_spice lang_spectre lang_verilog \
func_core measure_eval measure_max measure_min measure_slewrate measure_cross measure_integral measure_average measure_rms measure_at default_plugins



JFETFILES = jfet jfetacld jfetask jfetdel jfetdest jfetdist jfetdset jfetic jfetload jfetmask jfetmdel jfetmpar \
	jfetnoi jfetpar jfetpzld jfetset jfettemp jfettrun 


$(addprefix lib/,$(LIBFILES:=.bc)):$(addprefix lib/,$(LIBFILES:=.cc))
	for CCFILE in $(addprefix lib/,$(LIBFILES)) ;do \
		echo $$CCFILE.bc ;\
		$(CCP) $(CPPFLAGS) $(INCLUDES) -Ilib/ -Ilibapps/O $$CCFILE.cc -c -o $$CCFILE.bc ;\
	done

$(addprefix apps/,$(APPFILES:=.bc)):$(addprefix apps/,$(APPFILES:=.cc))
	for CCFILE in $(addprefix apps/,$(APPFILES)) ;do \
		echo $$CCFILE.bc ;\
		$(CCP) $(CPPFLAGS) $(INCLUDES) -Iapps/ -Iapps/O $$CCFILE.cc -c -o $$CCFILE.bc ;\
	done


lib/O/libgnucap.bc:$(addprefix lib/,$(LIBFILES:=.bc)) 
	-mkdir lib/O 
	$(CCP) $(OPTIMIZE) $(addprefix lib/,$(LIBFILES:=.bc)) -o lib/O/libgnucap.bc 

apps/O/libgnucap-default-plugins.bc:$(addprefix apps/,$(APPFILES:=.bc)) 
	-mkdir apps/O
	$(CCP) $(OPTIMIZE) $(addprefix apps/,$(APPFILES:=.bc)) -o apps/O/libgnucap-default-plugins.bc
	
models-spice3f5/jfet/O/d_jfet.bc:
	-mkdir models-spice3f5/jfet/O
		echo $$CCFILE.bc ;\
	$(CCP)  $(CPPFLAGS) $(INCLUDES) -Imodels-spice3f5/Include -Imodels-spice3f5/jfet models-spice3f5/Gnucap/spice-wrapper.cc -c -o models-spice3f5/Gnucap/spice-wrapper.bc 
	$(CC) $(CFLAGS) $(INCLUDES) -Imodels-spice3f5/Include models-spice3f5/Include/devsup.c -c -o models-spice3f5/Include/devsup.bc
	for CCFILE in $(addprefix models-spice3f5/jfet/,$(JFETFILES)) ;do \
		echo $$CCFILE.bc ;\
		$(CC) $(CFLAGS) -Wno-implicit-function-declaration $(INCLUDES) -Imodels-spice3f5/Include -Imodels-spice3f5/jfet $$CCFILE.c -c -o $$CCFILE.bc ;\
	done
	$(CCP) $(CPPFLAGS)  $(addprefix models-spice3f5/jfet/,$(JFETFILES:=.bc)) models-spice3f5/Gnucap/spice-wrapper.bc models-spice3f5/Include/devsup.bc -o models-spice3f5/jfet/O/d_jfet.bc
		
main/O/main.bc: main/main.cc
	-mkdir main/O
	$(CCP) $(CPPFLAGS) $(INCLUDES) main/main.cc -c -o main/O/main.bc 
	
clear-cache:
	-emcc --clear-cache

javascript: clear-cache main/O/main.bc lib/O/libgnucap.bc apps/O/libgnucap-default-plugins.bc models-spice3f5/jfet/O/d_jfet.bc
	$(CCP) $(OPTIMIZE) main/O/main.bc lib/O/libgnucap.bc apps/O/libgnucap-default-plugins.bc models-spice3f5/jfet/O/d_jfet.bc -o main/O/gnucap.bc #--pre-js pre.js 
	$(CCP) --memory-init-file 0 $(OPTIMIZE) main/O/gnucap.bc -o main/O/gnucap.html #--pre-js pre.js 


uglify:
	uglifyjs -v main/O/gnucap.js > main/O/gnucap-ugly.js

clean:
	-rm lib/*.bc
	-rm models-spice3f5/jfet/*.bc
	-rm apps/*.bc
	-rm apps/O/*.js
	-rm lib/O/*.bc
	-rm models-spice3f5/jfet/O/d_jfet.bc
	-rm apps/O/*.bc
	-rm main/O/*.bc
	-rm main/O/*.html
	-rm main/O/*.js
	-rm main/O/gnucap.html.mem


#command to minify
#uglifyjs -v main/O/gnucap.js > main/O/gnucap-ugly.js

