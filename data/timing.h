
/*
 * arch/arm/include/asm/arch-txl/timing.h
 *
 * Copyright (C) 2015 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __AML_TIMING_H_
#define __AML_TIMING_H_

#include <asm/arch/ddr_define.h>
#include <asm/arch/types.h>
#include <asm/arch/mnPmuSramMsgBlock_ddr3.h>
#include <asm/arch/mnPmuSramMsgBlock_ddr4.h>
#include <asm/arch/mnPmuSramMsgBlock_ddr4_2d.h>
#include <asm/arch/mnPmuSramMsgBlock_lpddr3.h>
#include <asm/arch/mnPmuSramMsgBlock_lpddr4.h>
#include <asm/arch/mnPmuSramMsgBlock_lpddr4_2d.h>

#define BL2_INIT_STAGE_0			0
#define BL2_INIT_STAGE_1			1
#define BL2_INIT_STAGE_2			2
#define BL2_INIT_STAGE_3			3
#define BL2_INIT_STAGE_4			4
#define BL2_INIT_STAGE_5			5
#define BL2_INIT_STAGE_6			6
#define BL2_INIT_STAGE_7			7
#define BL2_INIT_STAGE_8			8
#define BL2_INIT_STAGE_9			9

#define BL2_INIT_STAGE_PWM_PRE_INIT		0x81
#define BL2_INIT_STAGE_PWM_CHK_HW		0x82
#define BL2_INIT_STAGE_PWM_CFG_GROUP	0x83
#define BL2_INIT_STAGE_PWM_INIT			0xC0

#define PWM_CFG0						0
#define PWM_CFG1						1
#define PWM_CFG2						2
#define PWM_CFG3						3
/* etc... */

typedef struct bl2_reg {
	unsigned	int		reg;
	unsigned	int		value;
	unsigned	int		mask;
	unsigned	short	udelay;
	unsigned	char	flag;
	unsigned	char	rsv_0;
}__attribute__ ((packed)) bl2_reg_t;

typedef struct ddr_reg {
	unsigned	int		reg;
	unsigned	int		value;
	unsigned	int		mask;
	unsigned	short	udelay;
	unsigned	char	flag;
	unsigned	char	rsv_0;
}__attribute__ ((packed)) ddr_reg_t;

typedef struct training_delay_set_ps{
	unsigned	char	ac_trace_delay[10];
	unsigned	char	ac_trace_delay_rev[2];
	unsigned	char	read_dqs_delay[16];
	unsigned	char	read_dq_bit_delay[72];
	unsigned	short	write_dqs_delay[16];
//	*/
	unsigned	short	write_dq_bit_delay[72];
	unsigned	short	read_dqs_gate_delay[16];
	unsigned	char	soc_bit_vref[36];
	unsigned	char	dram_bit_vref[32];
	///*
	unsigned	char	rever1;//read_dqs  read_dq,write_dqs, write_dq
	unsigned	char	dfi_mrl;
	unsigned	char	dfi_hwtmrl;
	unsigned	char	ARdPtrInitVal;
	unsigned	short	csr_vrefinglobal;
	unsigned	short	csr_dqsrcvcntrl[4];
	unsigned	short	csr_pptdqscntinvtrntg0[4];
	unsigned	short	csr_pptdqscntinvtrntg1[4];
	unsigned	short	csr_seq0bgpr[9];
	unsigned	short	csr_dllgainctl;
	unsigned	short	csr_dlllockpara;
//	unsigned	short	rever2;
}__attribute__ ((packed)) training_delay_set_ps_t;

typedef struct ddr_mrs_reg {
	unsigned	int		cfg_ddr_mr[8];
	unsigned	int		cfg_ddr_mr11;
	unsigned	int		cfg_ddr_mr12;
	unsigned	int		cfg_ddr_mr13;
	unsigned	int		cfg_ddr_mr14;
	unsigned	int		cfg_ddr_mr16;
	unsigned	int		cfg_ddr_mr17;
	unsigned	int		cfg_ddr_mr22;
	unsigned	int		cfg_ddr_mr24;
}__attribute__ ((packed)) ddr_mrs_reg_t;

typedef struct ddr_timing{
	unsigned	int		identifier;
	unsigned	int		cfg_ddr_mrd;
	unsigned	int		cfg_ddr_rfcab;
	unsigned	int		cfg_ddr_rfcpb;
	unsigned	int		cfg_ddr_rpab;
	unsigned	int		cfg_ddr_rppb;
	unsigned	int		cfg_ddr_rtw;
	unsigned	int		cfg_ddr_rl;
	unsigned	int		cfg_ddr_wl;
	unsigned	int		cfg_ddr_ras;
	unsigned	int		cfg_ddr_rc;
	unsigned	int		cfg_ddr_rcd;
	unsigned	int		cfg_ddr_rrds;
	unsigned	int		cfg_ddr_rrdl;
	unsigned	int		cfg_ddr_faw;
	unsigned	int		cfg_ddr_rtp;
	unsigned	int		cfg_ddr_wr;
	unsigned	int		cfg_ddr_wtrs;
	unsigned	int		cfg_ddr_wtrl;
	unsigned	int		cfg_ddr_ccds;
	unsigned	int		cfg_ddr_ccdl;
	unsigned	int		cfg_ddr_exsr;
	unsigned	int		cfg_ddr_xs;
	unsigned	int		cfg_ddr_xp;
	unsigned	int		cfg_ddr_xpdll;
	unsigned	int		cfg_ddr_zqcs;
	unsigned	int		cfg_ddr_cksre;
	unsigned	int		cfg_ddr_cksrx;
	unsigned	int		cfg_ddr_cke;
	unsigned	int		cfg_ddr_mod;
	unsigned	int		cfg_ddr_dqs;
	unsigned	int		cfg_ddr_rstl;
	unsigned	int		cfg_ddr_zqlat;
	unsigned	int		cfg_ddr_mrr;
	unsigned	int		cfg_ddr_ckesr;
	unsigned	int		cfg_ddr_dpd;
	unsigned	int		cfg_ddr_ckeck;
	unsigned	int		cfg_ddr_refi;
	unsigned	int		cfg_ddr_sr;
	unsigned	int		cfg_ddr_ccdmw;
	unsigned	int		cfg_ddr_escke;
	unsigned	int		cfg_ddr_refi_ddr3;
	unsigned	int		cfg_ddr_dfictrldelay;
	unsigned	int		cfg_ddr_dfiphywrdata;
	unsigned	int		cfg_ddr_dfiphywrlat;
	unsigned	int		cfg_ddr_dfiphyrddataen;
	unsigned	int		cfg_ddr_dfiphyrdlat;
	unsigned	int		cfg_ddr_dfictrlupdmin;
	unsigned	int		cfg_ddr_dfictrlupdmax;
	unsigned	int		cfg_ddr_dfimstrresp;
	unsigned	int		cfg_ddr_dfirefmski;
	unsigned	int		cfg_ddr_dfictrlupdi;
	unsigned	int		cfg_ddr_dfidramclk;
	unsigned	int		cfg_ddr_dfilpresp;
	unsigned	int		cfg_ddr_dfiphymstr;
	unsigned	int		cfg_ddr_rtodt;
	unsigned	int		cfg_ddr_wlmrd;
	unsigned	int		cfg_ddr_wlo;
	unsigned	int		cfg_ddr_al;
	unsigned	int		cfg_ddr_zqcl;
	unsigned	int		cfg_ddr_zqcsi;
	unsigned	int		cfg_ddr_zqreset;
	unsigned	int		cfg_ddr_tdqsck_min;
	unsigned	int		cfg_ddr_tdqsck_max;
	//training_delay_set_ps_t	cfg_ddr_training_delay_ps;
	ddr_mrs_reg_t		cfg_ddr_mrs_reg_ps[2];
	unsigned	int		dfi_odt1_config_ps[2];
	//ddr_mrs_reg_t		cfg_ddr_mrs_reg_ps1;
	#if 0
	unsigned	int		cfg_ddr_mr[8];
	unsigned	int		cfg_ddr_mr11;
	unsigned	int		cfg_ddr_mr12;
	unsigned	int		cfg_ddr_mr13;
	unsigned	int		cfg_ddr_mr14;
	unsigned	int		cfg_ddr_mr16;
	unsigned	int		cfg_ddr_mr17;
	unsigned	int		cfg_ddr_mr22;
	unsigned	int		cfg_ddr_mr24;
	unsigned	int		cfg_ddr_reserve[5];
	#endif
}__attribute__ ((packed)) ddr_timing_t;

typedef struct ddr_phy_common_extra_set{
	unsigned	short	csr_pllctrl3;
	unsigned	short	csr_pptctlstatic[4];
	unsigned	short	csr_trainingincdecdtsmen[4];
	unsigned	short	csr_tsmbyte0[4];
	unsigned	short	csr_hwtcamode;
	unsigned	short	csr_hwtlpcsena;
	unsigned	short	csr_hwtlpcsenb;
	unsigned	short	csr_acsmctrl13;
	unsigned	short	csr_acsmctrl23;
	unsigned	char	csr_soc_vref_dac1_dfe[36];
}__attribute__ ((packed)) ddr_phy_common_extra_set_t;

typedef struct retraining_set{
	ddr_phy_common_extra_set_t cfg_ddr_phy_common_extra_set_t;
	training_delay_set_ps_t	cfg_ddr_training_delay_ps;
}__attribute__ ((packed)) retraining_set_t;

typedef struct ddr_set{
	//0x0
	unsigned	int		magic;
	//0x4
	unsigned	char	fast_boot[4];// 0   fastboot enable  1 window test margin  2 auto offset after window test 3 auto window test
	//unsigned	int		rsv_int0;
	//0x8
	unsigned	int		ddr_func;
	//0xC
	unsigned	char	board_id;
	//board id reserve,,do not modify
	//0xD
	unsigned	char	version;
	// firmware reserve version,,do not modify
	//0xE
	unsigned	char	DramType;
	//support DramType should confirm with amlogic
	//#define CONFIG_DDR_TYPE_DDR3				0
	//#define CONFIG_DDR_TYPE_DDR4				1
	//#define CONFIG_DDR_TYPE_LPDDR4				2
	//#define CONFIG_DDR_TYPE_LPDDR3				3
	//#define CONFIG_DDR_TYPE_LPDDR2				4
	//0xF
	unsigned	char	DisabledDbyte;
	//use for dram bus 16bit or 32bit,if use 16bit mode ,should disable bit 2,3
	//bit 0 ---use byte 0 ,1 disable byte 0,
	//bit 1 ---use byte 1 ,1 disable byte 1,
	//bit 2 ---use byte 2 ,1 disable byte 2,
	//bit 3 ---use byte 3 ,1 disable byte 3,
	//0x10
	unsigned	char	Is2Ttiming;
	//ddr3/ddr3 use 2t timing,now only support 2t timming
	//0x11
	unsigned	char	HdtCtrl;
	//training information control,do not modify
	//0x12
	unsigned	char	dram_rank_config;
	//support Dram connection type should confirm with amlogic
	//#define CONFIG_DDR0_16BIT_CH0				0x1  //dram total bus width 16bit only use cs0
	//#define CONFIG_DDR0_16BIT_RANK01_CH0		0x4  //dram total bus width 16bit  use cs0 cs1
	//#define CONFIG_DDR0_32BIT_RANK0_CH0			0x2  //dram total bus width 32bit  use cs0
	//#define CONFIG_DDR0_32BIT_RANK01_CH01		0x3    //only for lpddr4,dram total bus width 32bit  use chanel a cs0 cs1 chanel b cs0 cs1
	//#define CONFIG_DDR0_32BIT_16BIT_RANK0_CH0		0x5    //dram total bus width 32bit only use cs0,but high address use 16bit mode
	//#define CONFIG_DDR0_32BIT_16BIT_RANK01_CH0	0x6   //dram total bus width 32bit  use cs0 cs1,but cs1 use 16bit mode ,current phy not support reserve
	//#define CONFIG_DDR0_32BIT_RANK01_CH0		0x7       //dram total bus width 32bit  use cs0 cs1
	//#define CONFIG_DDR0_32BIT_RANK0_CH01		0x8     //only for lpddr4,dram total bus width 32bit  use chanel a cs0  chanel b cs0

	/* rsv_char0. update for diagnose type define */
	//0x13
	unsigned	char	diagnose;
	//0x14
	unsigned	short	soc_data_drv_ohm_ps1;
	//0x16
	unsigned	short	dram_data_drv_ohm_ps1;
	//0x18
	unsigned	short	soc_data_odt_ohm_ps1;
	//0x1a
	unsigned	short	dram_data_odt_ohm_ps1;
	//0x1c
	unsigned	short	dram_data_wr_odt_ohm_ps1;
	/* imem/dmem define */
	//0x1e
	unsigned	int		imem_load_addr;
	//0x22 ---
	//system reserve,do not modify
	unsigned	int		dmem_load_addr;
	//0x26
	//system reserve,do not modify
	unsigned	short	imem_load_size;
	//0x28
	//system reserve,do not modify
	unsigned	short	dmem_load_size;
	//0x2a
	//system reserve,do not modify
	unsigned	int		ddr_base_addr;
	//0x2e ---
	//system reserve,do not modify
	unsigned	int		ddr_start_offset;
	//system reserve,do not modify
	//0x32
	unsigned	short	dram_cs0_size_MB;
	//0x34
	//config cs0 dram size ,like 1G DRAM ,setting 1024
	unsigned	short	dram_cs1_size_MB;
	//config cs1 dram size,like 512M DRAM ,setting 512
	/* align8 */
	//0x36
	unsigned	short	training_SequenceCtrl[2];
	//0x3a
	//system reserve,do not modify
	unsigned	char	phy_odt_config_rank[2];
	//0x3c
	//unsigned	char	 rever1;
	//unsigned	char	 rever2;
	unsigned	short	rank1_ca_vref_permil;
	//0x3e
	//training odt config ,only use for training
	// [0]Odt pattern for accesses targeting rank 0. [3:0] is used for write ODT [7:4] is used for read ODT
	// [1]Odt pattern for accesses targeting rank 1. [3:0] is used for write ODT [7:4] is used for read ODT
	unsigned	int		dfi_odt_config;
	//0x42
	//normal go status od config,use for normal status
	//bit 12.  rank1 ODT default. default vulue for ODT[1] pins if theres no read/write activity.
	//bit 11.  rank1 ODT write sel.  enable ODT[1] if there's write occur in rank1.
	//bit 10.  rank1 ODT write nsel. enable ODT[1] if theres's write occur in rank0.
	//bit 9.   rank1 odt read sel.   enable ODT[1] if there's read occur in rank1.
	//bit 8.   rank1 odt read nsel.  enable ODT[1] if there's read occure in rank0.
	//bit 4.   rank0 ODT default.    default vulue for ODT[0] pins if theres no read/write activity.
	//bit 3.   rank0 ODT write sel.  enable ODT[0] if there's write occur in rank0.
	//bit 2.   rank0 ODT write nsel. enable ODT[0] if theres's write occur in rank1.
	//bit 1.   rank0 odt read sel.   enable ODT[0] if there's read occur in rank0.
	//bit 0.   rank0 odt read nsel.  enable ODT[0] if there's read occure in rank1.
	unsigned	short	DRAMFreq[4];
	//0x4a ---- here
	//config dram frequency,use DRAMFreq[0],ohter reserve
	unsigned	char	PllBypassEn;
	//0x4b--
	//system reserve,do not modify
	unsigned	char	ddr_rdbi_wr_enable;
	//0x4B
	//system reserve,do not modify
	unsigned	char	ddr_rfc_type;
	//0x4C
	//config dram rfc type,according dram type,also can use same dram type max config
	//#define DDR_RFC_TYPE_DDR3_512Mbx1				0
	//#define DDR_RFC_TYPE_DDR3_512Mbx2				1
	//#define DDR_RFC_TYPE_DDR3_512Mbx4				2
	//#define DDR_RFC_TYPE_DDR3_512Mbx8				3
	//#define DDR_RFC_TYPE_DDR3_512Mbx16				4
	//#define DDR_RFC_TYPE_DDR4_2Gbx1					5
	//#define DDR_RFC_TYPE_DDR4_2Gbx2					6
	//#define DDR_RFC_TYPE_DDR4_2Gbx4					7
	//#define DDR_RFC_TYPE_DDR4_2Gbx8					8
	//#define DDR_RFC_TYPE_LPDDR4_2Gbx1				9
	//#define DDR_RFC_TYPE_LPDDR4_3Gbx1				10
	//#define DDR_RFC_TYPE_LPDDR4_4Gbx1				11
	unsigned	char	enable_lpddr4x_mode;
	//0x4D
	//system reserve,do not modify
	/* align8 */

	unsigned	int		pll_ssc_mode;
	//0x51
	//
	/* pll ssc config:
	 *
	 *   pll_ssc_mode = (1<<20) | (1<<8) | ([strength] << 4) | [mode],
	 *      ppm = strength * 500
	 *      mode: 0=center, 1=up, 2=down
	 *
	 *   eg:
	 *     1. config 1000ppm center ss. then mode=0, strength=2
	 *        .pll_ssc_mode = (1<<20) | (1<<8) | (2 << 4) | 0,
	 *     2. config 3000ppm down ss. then mode=2, strength=6
	 *        .pll_ssc_mode = (1<<20) | (1<<8) | (6 << 4) | 2,
	 */
	unsigned	short	clk_drv_ohm;
	//0x53
	//config soc clk pin signal driver stength ,select 20,30,40,60ohm
	unsigned	short	cs_drv_ohm;
	//0x55
	//config soc cs0 cs1 pin signal driver stength ,select 20,30,40,60ohm
	unsigned	short	ac_drv_ohm;
	//0x57
	//config soc  normal address command pin driver stength ,select 20,30,40,60ohm
	unsigned	short	soc_data_drv_ohm_p;
	//0x59
	//config soc data pin pull up driver stength,select 0,28,30,32,34,37,40,43,48,53,60,68,80,96,120ohm
	unsigned	short	soc_data_drv_ohm_n;
	//0x5b
	//config soc data pin pull down driver stength,select 0,28,30,32,34,37,40,43,48,53,60,68,80,96,120ohm
	unsigned	short	soc_data_odt_ohm_p;
	//0x5d
	//config soc data pin odt pull up stength,select 0,28,30,32,34,37,40,43,48,53,60,68,80,96,120ohm
	unsigned	short	soc_data_odt_ohm_n;
	//0x5f
	//config soc data pin odt pull down stength,select 0,28,30,32,34,37,40,43,48,53,60,68,80,96,120ohm
	unsigned	short	dram_data_drv_ohm;
	//0x61
	//config dram data pin pull up pull down driver stength,ddr3 select 34,40ohm,ddr4 select 34,48ohm,lpddr4 select 40,48,60,80,120,240ohm
	unsigned	short	dram_data_odt_ohm;
	//0x63
	//config dram data pin odt pull up down stength,ddr3 select 40,60,120ohm,ddr4 select 34,40,48,60,120,240ohm,lpddr4 select 40,48,60,80,120,240ohm
	unsigned	short	dram_ac_odt_ohm;
	//0x65
	//config dram ac pin odt pull up down stength,use for lpddr4, select 40,48,60,80,120,240ohm
	unsigned	short	soc_clk_slew_rate;
	//0x67
	//system reserve,do not modify
	unsigned	short	soc_cs_slew_rate;
	//0x69
	//system reserve,do not modify
	unsigned	short	soc_ac_slew_rate;
	//0x6B
	//system reserve,do not modify
	unsigned	short	soc_data_slew_rate;
	//0x6D
	//system reserve,do not modify
	unsigned	short	vref_output_permil; //phy
	//0x6F
	//setting same with vref_dram_permil
	unsigned	short	vref_receiver_permil; //soc
	//0x71
	//soc init SOC receiver vref ,config like 500 means 0.5VDDQ,take care ,please follow SI
	unsigned	short	vref_dram_permil;
	//0x73
	//soc init DRAM receiver vref ,config like 500 means 0.5VDDQ,take care ,please follow SI
	unsigned	short	max_core_timmming_frequency;
	//0x75
	//use for limited ddr speed core timmming parameter,for some old dram maybe have no over speed register
	/* align8 */

	unsigned	char	ac_trace_delay[10];
	//0x7f
	unsigned	char	lpddr4_dram_vout_voltage_1_3_2_5_setting;
	//0x80
	//use for lpddr4 read vout voltage  setting 0 --->2/5VDDQ ,1--->1/3VDDQ
	unsigned	char	lpddr4_x8_mode;
	//0x81
	unsigned	char	slt_test_function[2];  //[0] slt test function enable,bit 0 enable 4 frequency scan,bit 1 enable force delay line offset ,bit 7 enable skip training function
	//0x83
	//[1],slt test parameter ,use for force delay line offset
	//system reserve,do not modify
	unsigned	short	tdqs2dq;
	//0x85
	unsigned	char	dram_data_wr_odt_ohm;
	//0x86
	unsigned	char	bitTimeControl_2d;
	//0x87
	//system reserve,do not modify
	/* align8 */
    unsigned	char	char_rev1;
	//0x88
	unsigned	char	training_offset;//char_rev2;
	//0x89
	unsigned	int		ddr_dmc_remap[5];
	//0x9d
	unsigned	int		dram_rtt_nom_wr_park[2];
	//0xa5
	//system reserve,do not modify
	/* align8 */
	unsigned	char	ddr_lpddr34_ca_remap[4];
	//0xa9
	////use for lpddr3 /lpddr4 ca training data byte lane remap
	unsigned	char	ddr_lpddr34_dq_remap[32];
	//0xc9
	////use for lpddr3 /lpddr4 ca pinmux remap
	// this is 28
	unsigned	char	ac_pinmux[DWC_AC_PINMUX_TOTAL];
	//0xe5
	//use for lpddr3 /lpddr4 ca pinmux remap
	// this is 26
	unsigned	char	dfi_pinmux[DWC_DFI_PINMUX_TOTAL];
	//0xff
	unsigned	char	char_rev3;
	//0x100
	unsigned	char	char_rev4;
	//0x101
	ddr_phy_common_extra_set_t cfg_ddr_phy_common_extra_set_t;
	training_delay_set_ps_t	cfg_ddr_training_delay_ps[2];

	//override read bit delay
}__attribute__ ((packed)) ddr_set_t;

typedef struct pll_set{
	unsigned	short	cpu_clk;
	unsigned	short	pxp;
	unsigned	int		spi_ctrl;
	unsigned	short	vddee;
	unsigned	short	vcck;
	unsigned	char	szPad[4];

	unsigned	long	lCustomerID;
	unsigned	char	debug_mode;
	unsigned	char	log_chl;
	unsigned	char	log_ctrl;
	unsigned	char	ddr_timming_save_mode;
	unsigned	int		nCFGTAddr;
	/* align 8Byte */

	unsigned	int		sys_pll_cntl[8];
	unsigned	int		ddr_pll_cntl[8];
	unsigned	int		fix_pll_cntl[8];
}__attribute__ ((packed)) pll_set_t;

typedef struct dmem_cfg {
	PMU_SMB_DDR3U_1D_t ddr3u;
	PMU_SMB_DDR4U_1D_t ddr4u;
	PMU_SMB_DDR4U_2D_t ddr4u_2d;
	PMU_SMB_LPDDR3_1D_t lpddr3u;
	PMU_SMB_LPDDR4_1D_t lpddr4u;
	PMU_SMB_LPDDR4_2D_t lpddr4u_2d;
} dmem_cfg_t;

#endif //__AML_TIMING_H_