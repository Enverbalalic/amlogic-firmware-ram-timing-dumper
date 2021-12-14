use byteorder::{BigEndian, LittleEndian, ReadBytesExt};
use color_eyre::eyre::Result;
use std::{fs::File, io::Read, path::PathBuf};
use thiserror::Error;

const DDR_MAGIC: u32 = 0x2e676663;

use clap::Parser;

#[derive(Debug)]
#[repr(packed)]
struct DdrSet {
    magic: u32,
    fast_boot: [u8; 4],
    board_id: u8,
    version: u8,
    dram_type: u8,
    disable_d_byte: u8,
    is2_timing: u8,
    hdt_ctrl: u8,
    dram_rank_config: u8,
    diagnose: u8,
    // soc_data_drv_ohm_ps1: u16,
    // dram_data_drv_ohm_ps1: u16,
    // soc_data_odt_ohm_ps1: u16,
    // dram_data_odt_ohm_ps1: u16,
    // dram_data_wr_odt_ohm_ps1: u16,
    imem_load_addr: u32,
    dmem_load_addr: u32,
    imem_load_size: u16,
    dmem_load_size: u16,
    ddr_base_addr: u32,
    ddr_start_offset: u32,
    dram_cs0_size_mb: u16,
    dram_cs1_size_mb: u16,
    training_SequenceCtrl: [u16; 2],
    phy_odt_config_rank: [u8; 4],
    dfi_odt_config: u32,
    DRAMFreq: [u16; 4],
    PllBypassEn: u8,
    ddr_rdbi_wr_enable: u8,
    ddr_rfc_type: u8,
    enable_lpddr4x_mode: u8,
    pll_ssc_mode: u32,
    clk_drv_ohm: u16,
    cs_drv_ohm: u16,
    ac_drv_ohm: u16,
    soc_data_drv_ohm_p: u16,
    soc_data_drv_ohm_n: u16,
    soc_data_odt_ohm_p: u16,
    soc_data_odt_ohm_n: u16,
    dram_data_drv_ohm: u16,
    dram_data_odt_ohm: u16,
    dram_ac_odt_ohm: u16,
    soc_clk_slew_rate: u16,
    soc_cs_slew_rate: u16,
    soc_ac_slew_rate: u16,
    soc_data_slew_rate: u16,
    vref_output_permil: u16,
    vref_receiver_permil: u16,
    vref_dram_permil: u16,
    max_core_timmming_frequency: u16,
    ac_trace_delay: [u8; 12],
    // todo check
    ac_pinmux: [u8; 28],
    dfi_pinmux: [u8; 26],
    rsv_char1: [u8; 6],
    ddr_dmc_remap: [u32; 5],
    ddr_lpddr34_ca_remap: [u8; 4],
    ddr_lpddr34_dq_remap: [u8; 32],
    dram_rtt_nom_wr_park: [u32; 2],
    ddr_func: u32,
    rsv_long0: [u64; 2],
}

// #[repr(packed)]
// struct DdrSetKhadas {
//     magic: u32,
//     fast_boot: [u8; 4],
//     ddr_func: u32,
//     board_id: u8,
//     version: u8,
//     dram_type: u8,
//     disable_d_byte: u8,
//     is2_timing: u8,
//     hdt_ctrl: u8,
//     dram_rank_config: u8,
//     diagnose: u8,
//     soc_data_drv_ohm_ps1: u16,
//     dram_data_drv_ohm_ps1: u16,
//     soc_data_odt_ohm_ps1: u16,
//     dram_data_odt_ohm_ps1: u16,
//     dram_data_wr_odt_ohm_ps1: u16,
//     // imem_load_addr: u32,
//     // dmem_load_addr: u32,
//     // imem_load_size: u16,
//     dmem_load_size: u16,
//     ddr_base_addr: u32,
//     ddr_start_offset: u32,
//     dram_cs0_size_mb: u16,
//     dram_cs1_size_mb: u16,
//     training_SequenceCtrl: [u16; 2],
//     phy_odt_config_rank: [u8; 2],
//     rank1_ca_vref_permil: u16,
//     dfi_odt_config: u32,
//     DRAMFreq: [u16; 4],
//     PllBypassEn: u8,
//     ddr_rdbi_wr_enable: u8,
//     ddr_rfc_type: u8,
//     enable_lpddr4x_mode: u8,
//     pll_ssc_mode: u32,
//     clk_drv_ohm: u16,
//     cs_drv_ohm: u16,
//     ac_drv_ohm: u16,
//     soc_data_drv_ohm_p: u16,
//     soc_data_drv_ohm_n: u16,
//     soc_data_odt_ohm_p: u16,
//     soc_data_odt_ohm_n: u16,
//     dram_data_drv_ohm: u16,
//     dram_data_odt_ohm: u16,
//     dram_ac_odt_ohm: u16,
//     soc_clk_slew_rate: u16,
//     soc_cs_slew_rate: u16,
//     soc_ac_slew_rate: u16,
//     soc_data_slew_rate: u16,
//     vref_output_permil: u16,
//     vref_receiver_permil: u16,
//     vref_dram_permil: u16,
//     max_core_timmming_frequency: u16,
//     ac_trace_delay: [u8; 10],
//     lpddr4_dram_vout_voltage_1_3_2_5_setting: u8,
//     lpddr4_x8_mode: u8,
//     slt_test_function: [u8; 2],
//     tdqs2dq: u16,
//     dram_data_wr_odt_ohm: u8,
//     bitTimeControl_2d: u8,
//     char_rev1: u8,
//     training_offset: u8,
//     ddr_dmc_remap: [u32; 5],
//     dram_rtt_nom_wr_park: [u32; 2],
//     ddr_lpddr34_ca_remap: [u8; 4],
//     ddr_lpddr34_dq_remap: [u8; 32],
//     ac_pinmux: [u8; 28],
//     dfi_pinmux: [u8; 26],
//     char_rev3: u8,
//     char_rev4: u8,
// }

/// Simple program to greet a person
#[derive(Parser, Debug)]
#[clap(about, version, author)]
struct Args {
    file: PathBuf,
}

fn main() -> Result<()> {
    color_eyre::install()?;

    let args = Args::parse();

    let mut file = File::open(args.file)?;
    let mut buf = vec![];
    file.read_to_end(&mut buf)?;

    let (_, ints, _) = unsafe { buf.align_to::<u32>() };

    let u32_ddr_offsets: Vec<usize> = ints
        .iter()
        .enumerate()
        .filter_map(|(index, int)| {
            if *int == DDR_MAGIC {
                return Some(index * 4);
            }

            None
        })
        .collect();

    println!("Found DDR Structs at - {u32_ddr_offsets:x?}");

    let ddr_structs: Vec<DdrSet> = u32_ddr_offsets
        .iter()
        .filter_map(|offset| {
            let buf_start = &buf[*offset..*offset + 768];
            let s: DdrSet = unsafe { std::ptr::read(buf_start.as_ptr() as *const _) };
            Some(s)
        })
        .collect();

    for ddr in ddr_structs {
        println!("{ddr:#x?}");
    }

    Ok(())
}
