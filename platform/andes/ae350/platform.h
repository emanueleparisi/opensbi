/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2019 Andes Technology Corporation
 *
 * Authors:
 *   Zong Li <zong@andestech.com>
 *   Nylon Chen <nylon7@andestech.com>
 */

#ifndef _AE350_PLATFORM_H_
#define _AE350_PLATFORM_H_

#define AE350_HART_COUNT		4

#define AE350_PLIC_ADDR			0xe4000000
#define AE350_PLIC_NUM_SOURCES		71

#define AE350_PLICSW_ADDR		0xe6400000

#define AE350_L2C_ADDR			0xe0500000

/*Memory and Miscellaneous Registers*/
#define CSR_MILMB		0x7c0
#define CSR_MDLMB		0x7c1
#define CSR_MECC_CDOE		0x7c2
#define CSR_MNVEC		0x7c3
#define CSR_MPFTCTL		0x7c5
#define CSR_MCACHECTL		0x7ca
#define CSR_MCCTLBEGINADDR	0x7cb
#define CSR_MCCTLCOMMAND	0x7cc
#define CSR_MCCTLDATA		0x7cc
#define CSR_SCCTLDATA		0x9cd
#define CSR_UCCTLBEGINADDR	0x80c
#define CSR_MMISCCTL		0x7d0

enum sbi_ext_andes_fid {
	SBI_EXT_ANDES_GET_MCACHE_CTL_STATUS = 0,
	SBI_EXT_ANDES_GET_MMISC_CTL_STATUS,
	SBI_EXT_ANDES_SET_MCACHE_CTL,
	SBI_EXT_ANDES_SET_MMISC_CTL,
	SBI_EXT_ANDES_ICACHE_OP,
	SBI_EXT_ANDES_DCACHE_OP,
	SBI_EXT_ANDES_L1CACHE_I_PREFETCH,
	SBI_EXT_ANDES_L1CACHE_D_PREFETCH,
	SBI_EXT_ANDES_NON_BLOCKING_LOAD_STORE,
	SBI_EXT_ANDES_WRITE_AROUND,
};

/* nds v5 mmisc_ctl register*/
#define V5_MMISC_CTL_VEC_PLIC_OFFSET            1
#define V5_MMISC_CTL_RVCOMPM_OFFSET             2
#define V5_MMISC_CTL_BRPE_OFFSET                3
#define V5_MMISC_CTL_MSA_OR_UNA_OFFSET          6
#define V5_MMISC_CTL_NON_BLOCKING_OFFSET        8
#define V5_MCACHE_CTL_L1I_PREFETCH_OFFSET       9
#define V5_MCACHE_CTL_L1D_PREFETCH_OFFSET       10
#define V5_MCACHE_CTL_DC_WAROUND_OFFSET_1       13
#define V5_MCACHE_CTL_DC_WAROUND_OFFSET_2       14

#define V5_MMISC_CTL_VEC_PLIC_EN        (1UL << V5_MMISC_CTL_VEC_PLIC_OFFSET)
#define V5_MMISC_CTL_RVCOMPM_EN         (1UL << V5_MMISC_CTL_RVCOMPM_OFFSET)
#define V5_MMISC_CTL_BRPE_EN            (1UL << V5_MMISC_CTL_BRPE_OFFSET)
#define V5_MMISC_CTL_MSA_OR_UNA_EN      (1UL << V5_MMISC_CTL_MSA_OR_UNA_OFFSET)
#define V5_MMISC_CTL_NON_BLOCKING_EN    (1UL << V5_MMISC_CTL_NON_BLOCKING_OFFSET)
#define V5_MCACHE_CTL_L1I_PREFETCH_EN   (1UL << V5_MCACHE_CTL_L1I_PREFETCH_OFFSET)
#define V5_MCACHE_CTL_L1D_PREFETCH_EN   (1UL << V5_MCACHE_CTL_L1D_PREFETCH_OFFSET)
#define V5_MCACHE_CTL_DC_WAROUND_1_EN   (1UL << V5_MCACHE_CTL_DC_WAROUND_OFFSET_1)
#define V5_MCACHE_CTL_DC_WAROUND_2_EN   (1UL << V5_MCACHE_CTL_DC_WAROUND_OFFSET_2)

#define V5_MMISC_CTL_MASK  (V5_MMISC_CTL_VEC_PLIC_EN | V5_MMISC_CTL_RVCOMPM_EN \
	| V5_MMISC_CTL_BRPE_EN | V5_MMISC_CTL_MSA_OR_UNA_EN | V5_MMISC_CTL_NON_BLOCKING_EN)

/* nds mcache_ctl register*/
#define V5_MCACHE_CTL_IC_EN_OFFSET      0
#define V5_MCACHE_CTL_DC_EN_OFFSET      1
#define V5_MCACHE_CTL_IC_ECCEN_OFFSET   2
#define V5_MCACHE_CTL_DC_ECCEN_OFFSET   4
#define V5_MCACHE_CTL_IC_RWECC_OFFSET   6
#define V5_MCACHE_CTL_DC_RWECC_OFFSET   7
#define V5_MCACHE_CTL_CCTL_SUEN_OFFSET  8

/*nds cctl command*/
#define V5_UCCTL_L1D_WBINVAL_ALL 6
#define V5_UCCTL_L1D_WB_ALL 7

#define V5_MCACHE_CTL_IC_EN     (1UL << V5_MCACHE_CTL_IC_EN_OFFSET)
#define V5_MCACHE_CTL_DC_EN     (1UL << V5_MCACHE_CTL_DC_EN_OFFSET)
#define V5_MCACHE_CTL_IC_RWECC  (1UL << V5_MCACHE_CTL_IC_RWECC_OFFSET)
#define V5_MCACHE_CTL_DC_RWECC  (1UL << V5_MCACHE_CTL_DC_RWECC_OFFSET)
#define V5_MCACHE_CTL_CCTL_SUEN (1UL << V5_MCACHE_CTL_CCTL_SUEN_OFFSET)

#define V5_MCACHE_CTL_MASK (V5_MCACHE_CTL_IC_EN | V5_MCACHE_CTL_DC_EN \
	| V5_MCACHE_CTL_IC_RWECC | V5_MCACHE_CTL_DC_RWECC \
	| V5_MCACHE_CTL_CCTL_SUEN | V5_MCACHE_CTL_L1I_PREFETCH_EN \
	| V5_MCACHE_CTL_L1D_PREFETCH_EN | V5_MCACHE_CTL_DC_WAROUND_1_EN \
	| V5_MCACHE_CTL_DC_WAROUND_2_EN)

#define V5_L2C_CTL_OFFSET           0x8
#define V5_L2C_CTL_ENABLE_OFFSET    0
#define V5_L2C_CTL_IPFDPT_OFFSET    3
#define V5_L2C_CTL_DPFDPT_OFFSET    5
#define V5_L2C_CTL_TRAMOCTL_OFFSET  8
#define V5_L2C_CTL_TRAMICTL_OFFSET  10
#define V5_L2C_CTL_DRAMOCTL_OFFSET  11
#define V5_L2C_CTL_DRAMICTL_OFFSET  13

#define V5_L2C_CTL_ENABLE_MASK      (1UL << V5_L2C_CTL_ENABLE_OFFSET)
#define V5_L2C_CTL_IPFDPT_MASK      (3UL << V5_L2C_CTL_IPFDPT_OFFSET)
#define V5_L2C_CTL_DPFDPT_MASK      (3UL << V5_L2C_CTL_DPFDPT_OFFSET)
#define V5_L2C_CTL_TRAMOCTL_MASK    (3UL << V5_L2C_CTL_TRAMOCTL_OFFSET)
#define V5_L2C_CTL_TRAMICTL_MASK    (1UL << V5_L2C_CTL_TRAMICTL_OFFSET)
#define V5_L2C_CTL_DRAMOCTL_MASK    (3UL << V5_L2C_CTL_DRAMOCTL_OFFSET)
#define V5_L2C_CTL_DRAMICTL_MASK    (1UL << V5_L2C_CTL_DRAMICTL_OFFSET)

#endif /* _AE350_PLATFORM_H_ */
