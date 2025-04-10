/*
 * Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES. ALL RIGHTS RESERVED.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/***

         *** This file was generated at "2023-06-01 20:24:55"
         *** by:
         ***    > [REDACTED]/adb2pack.py --input adb/fs5_image_layout/fs5_image_layout.adb --file-prefix fs5_image_layout --prefix fs5_image_layout_ --no-adb-utils
         ***/
#ifndef FS5_IMAGE_LAYOUT_LAYOUTS_H
#define FS5_IMAGE_LAYOUT_LAYOUTS_H


#ifdef __cplusplus
extern "C" {
#endif

#include "adb_to_c_utils.h"
/* Description -   */
/* Size in bytes - 4 */
struct fs5_image_layout_bch_boot_component_flags {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.0 - 0x0.29 */
	u_int32_t res;
	/* Description -  */
	/* 0x0.30 - 0x0.30 */
	u_int8_t is_debug;
	/* Description -  */
	/* 0x0.31 - 0x0.31 */
	u_int8_t is_encrypted;
};

/* Description -  HW pointer entry */
/* Size in bytes - 8 */
struct fs5_image_layout_hw_pointer_entry {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description - pointer */
	/* 0x0.0 - 0x0.31 */
	u_int32_t ptr;
/*---------------- DWORD[1] (Offset 0x4) ----------------*/
	/* Description - crc16 as calculated by HW */
	/* 0x4.0 - 0x4.15 */
	u_int16_t crc;
};

/* Description -   */
/* Size in bytes - 64 */
struct fs5_image_layout_u8_digest {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.0 - 0x3c.31 */
	u_int32_t digest[16];
};

/* Description -   */
/* Size in bytes - 384 */
struct fs5_image_layout_u8_stage1_signature {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.24 - 0x180.23 */
	/* access: RW */
	u_int8_t u8_dummy[384];
};

/* Description -   */
/* Size in bytes - 1068 */
struct fs5_image_layout_u8_stage1_res {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description - Reserved for PSC use */
	/* 0x0.0 - 0x0.31 */
	u_int32_t reserved;
/*---------------- DWORD[4] (Offset 0x10) ----------------*/
	/* Description - Offset relative to load address of the starting location of the HASH table (for NCORE.FMC use) */
	/* 0x10.0 - 0x10.31 */
	u_int32_t hash_offset;
/*---------------- DWORD[5] (Offset 0x14) ----------------*/
	/* Description - Version of PSC.BL1 to be bind with this NCORE.FMC version (will be compared to BL1 version as specified in PSC.BL1.BCH) */
	/* 0x14.0 - 0x14.31 */
	u_int32_t BL1_bind_version;
/*---------------- DWORD[6] (Offset 0x18) ----------------*/
	/* Description - Version of PSC.FW to be bind with this NCORE.FMC version (will be compared to FW version as specified in PSC.FW.BCH) */
	/* 0x18.0 - 0x18.31 */
	u_int32_t FW_bind_version;
};

/* Description -   */
/* Size in bytes - 4 */
struct fs5_image_layout_boot_component_ver {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.0 - 0x0.7 */
	/* access: RW */
	u_int8_t u8_ver_major;
	/* Description -  */
	/* 0x0.8 - 0x0.15 */
	/* access: RW */
	u_int8_t u8_ver_minor;
	/* Description -  */
	/* 0x0.16 - 0x0.23 */
	/* access: RW */
	u_int8_t u8_ratchet_level;
	/* Description -  */
	/* 0x0.24 - 0x0.31 */
	/* access: RW */
	u_int8_t u8_res;
};

/* Description -   */
/* Size in bytes - 144 */
struct fs5_image_layout_u8_stage1_component {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description - served for PSC use,indicate component type */
	/* 0x0.24 - 0x4.23 */
	/* access: RW */
	u_int8_t u8_binary_magic[4];
/*---------------- DWORD[1] (Offset 0x4) ----------------*/
	/* Description - length[bytes] */
	/* 0x4.0 - 0x4.31 */
	/* access: RW */
	u_int32_t u32_binary_len;
/*---------------- DWORD[2] (Offset 0x8) ----------------*/
	/* Description - the destination of the component to be copied to */
	/* 0x8.0 - 0x8.31 */
	/* access: RW */
	u_int32_t u32_load_dest;
/*---------------- DWORD[3] (Offset 0xc) ----------------*/
	/* Description - the entry_point (absolute value) to start (jump address) */
	/* 0xc.0 - 0xc.31 */
	/* access: RW */
	u_int32_t u32_entry_point;
/*---------------- DWORD[4] (Offset 0x10) ----------------*/
	/* Description -  */
	/* 0x10.0 - 0x10.31 */
	/* access: RW */
	struct fs5_image_layout_boot_component_ver ver;
/*---------------- DWORD[5] (Offset 0x14) ----------------*/
	/* Description -  */
	/* 0x14.24 - 0x1c.23 */
	/* access: RW */
	u_int8_t u8_res[8];
/*---------------- DWORD[7] (Offset 0x1c) ----------------*/
	/* Description -  */
	/* 0x1c.0 - 0x1c.31 */
	/* access: RW */
	struct fs5_image_layout_bch_boot_component_flags flags;
/*---------------- DWORD[20] (Offset 0x50) ----------------*/
	/* Description -  */
	/* 0x50.0 - 0x8c.31 */
	/* access: RW */
	struct fs5_image_layout_u8_digest u8_digest;
};

/* Description -  BCH - boot component header */
/* Size in bytes - 8192 */
struct fs5_image_layout_boot_component_header {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.24 - 0x4.23 */
	/* access: RW */
	u_int8_t u8_header_magic[4];
/*---------------- DWORD[1] (Offset 0x4) ----------------*/
	/* Description -  */
	/* 0x4.0 - 0x40.31 */
	struct fs5_image_layout_u8_digest u8_digest;
/*---------------- DWORD[1600] (Offset 0x1900) ----------------*/
	/* Description -  */
	/* 0x1900.0 - 0x1a7c.31 */
	/* access: RW */
	struct fs5_image_layout_u8_stage1_signature u8_stage1_signature;
/*---------------- DWORD[1705] (Offset 0x1aa4) ----------------*/
	/* Description -  */
	/* 0x1aa4.0 - 0x1ecc.31 */
	struct fs5_image_layout_u8_stage1_res u8_stage1_res;
/*---------------- DWORD[1976] (Offset 0x1ee0) ----------------*/
	/* Description -  */
	/* 0x1ee0.0 - 0x1ffc.31 */
	struct fs5_image_layout_u8_stage1_component stage1_components[2];
};

/* Description -  HW pointers */
/* Size in bytes - 128 */
struct fs5_image_layout_hw_pointers_gilboa {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.0 - 0x4.31 */
	struct fs5_image_layout_hw_pointer_entry psc_bct_pointer;
/*---------------- DWORD[2] (Offset 0x8) ----------------*/
	/* Description -  */
	/* 0x8.0 - 0xc.31 */
	struct fs5_image_layout_hw_pointer_entry boot2_ptr;
/*---------------- DWORD[4] (Offset 0x10) ----------------*/
	/* Description -  */
	/* 0x10.0 - 0x14.31 */
	struct fs5_image_layout_hw_pointer_entry toc_ptr;
/*---------------- DWORD[6] (Offset 0x18) ----------------*/
	/* Description -  */
	/* 0x18.0 - 0x1c.31 */
	struct fs5_image_layout_hw_pointer_entry tools_ptr;
/*---------------- DWORD[8] (Offset 0x20) ----------------*/
	/* Description -  */
	/* 0x20.0 - 0x24.31 */
	struct fs5_image_layout_hw_pointer_entry psc_bl1_bch_pointer;
/*---------------- DWORD[10] (Offset 0x28) ----------------*/
	/* Description -  */
	/* 0x28.0 - 0x2c.31 */
	struct fs5_image_layout_hw_pointer_entry psc_bl1_pointer;
/*---------------- DWORD[12] (Offset 0x30) ----------------*/
	/* Description -  */
	/* 0x30.0 - 0x34.31 */
	struct fs5_image_layout_hw_pointer_entry ncore_bch_pointer;
/*---------------- DWORD[14] (Offset 0x38) ----------------*/
	/* Description -  */
	/* 0x38.0 - 0x3c.31 */
	struct fs5_image_layout_hw_pointer_entry reserved;
/*---------------- DWORD[16] (Offset 0x40) ----------------*/
	/* Description -  */
	/* 0x40.0 - 0x44.31 */
	struct fs5_image_layout_hw_pointer_entry psc_fw_bch_pointer;
/*---------------- DWORD[18] (Offset 0x48) ----------------*/
	/* Description -  */
	/* 0x48.0 - 0x4c.31 */
	struct fs5_image_layout_hw_pointer_entry psc_fw_pointer;
/*---------------- DWORD[20] (Offset 0x50) ----------------*/
	/* Description -  */
	/* 0x50.0 - 0x54.31 */
	struct fs5_image_layout_hw_pointer_entry image_info_section_pointer;
/*---------------- DWORD[22] (Offset 0x58) ----------------*/
	/* Description -  */
	/* 0x58.0 - 0x5c.31 */
	struct fs5_image_layout_hw_pointer_entry image_signature_pointer;
/*---------------- DWORD[24] (Offset 0x60) ----------------*/
	/* Description -  */
	/* 0x60.0 - 0x64.31 */
	struct fs5_image_layout_hw_pointer_entry public_key_pointer;
/*---------------- DWORD[26] (Offset 0x68) ----------------*/
	/* Description -  */
	/* 0x68.0 - 0x6c.31 */
	struct fs5_image_layout_hw_pointer_entry fw_security_version_pointer;
/*---------------- DWORD[28] (Offset 0x70) ----------------*/
	/* Description -  */
	/* 0x70.0 - 0x74.31 */
	struct fs5_image_layout_hw_pointer_entry gcm_iv_delta_pointer;
/*---------------- DWORD[30] (Offset 0x78) ----------------*/
	/* Description -  */
	/* 0x78.0 - 0x7c.31 */
	struct fs5_image_layout_hw_pointer_entry ncore_hashes_pointer;
};

/* Description -   */
/* Size in bytes - 8192 */
union fs5_image_layout_fs5_image_layout_Nodes {
/*---------------- DWORD[0] (Offset 0x0) ----------------*/
	/* Description -  */
	/* 0x0.0 - 0x7c.31 */
	struct fs5_image_layout_hw_pointers_gilboa hw_pointers_gilboa;
	/* Description -  */
	/* 0x0.0 - 0x1ffc.31 */
	struct fs5_image_layout_boot_component_header boot_component_header;
};


/*================= PACK/UNPACK/PRINT FUNCTIONS ======================*/
/* bch_boot_component_flags */
void fs5_image_layout_bch_boot_component_flags_pack(const struct fs5_image_layout_bch_boot_component_flags *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_bch_boot_component_flags_unpack(struct fs5_image_layout_bch_boot_component_flags *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_bch_boot_component_flags_print(const struct fs5_image_layout_bch_boot_component_flags *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_bch_boot_component_flags_size(void);
#define FS5_IMAGE_LAYOUT_BCH_BOOT_COMPONENT_FLAGS_SIZE    (0x4)
void fs5_image_layout_bch_boot_component_flags_dump(const struct fs5_image_layout_bch_boot_component_flags *ptr_struct, FILE *fd);
/* hw_pointer_entry */
void fs5_image_layout_hw_pointer_entry_pack(const struct fs5_image_layout_hw_pointer_entry *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_hw_pointer_entry_unpack(struct fs5_image_layout_hw_pointer_entry *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_hw_pointer_entry_print(const struct fs5_image_layout_hw_pointer_entry *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_hw_pointer_entry_size(void);
#define FS5_IMAGE_LAYOUT_HW_POINTER_ENTRY_SIZE    (0x8)
void fs5_image_layout_hw_pointer_entry_dump(const struct fs5_image_layout_hw_pointer_entry *ptr_struct, FILE *fd);
/* u8_digest */
void fs5_image_layout_u8_digest_pack(const struct fs5_image_layout_u8_digest *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_u8_digest_unpack(struct fs5_image_layout_u8_digest *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_u8_digest_print(const struct fs5_image_layout_u8_digest *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_u8_digest_size(void);
#define FS5_IMAGE_LAYOUT_U8_DIGEST_SIZE    (0x40)
void fs5_image_layout_u8_digest_dump(const struct fs5_image_layout_u8_digest *ptr_struct, FILE *fd);
/* u8_stage1_component */
void fs5_image_layout_u8_stage1_component_pack(const struct fs5_image_layout_u8_stage1_component *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_u8_stage1_component_unpack(struct fs5_image_layout_u8_stage1_component *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_u8_stage1_component_print(const struct fs5_image_layout_u8_stage1_component *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_u8_stage1_component_size(void);
#define FS5_IMAGE_LAYOUT_U8_STAGE1_COMPONENT_SIZE    (0x90)
void fs5_image_layout_u8_stage1_component_dump(const struct fs5_image_layout_u8_stage1_component *ptr_struct, FILE *fd);
/* boot_component_ver */
void fs5_image_layout_boot_component_ver_pack(const struct fs5_image_layout_boot_component_ver *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_boot_component_ver_unpack(struct fs5_image_layout_boot_component_ver *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_boot_component_ver_print(const struct fs5_image_layout_boot_component_ver *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_boot_component_ver_size(void);
#define FS5_IMAGE_LAYOUT_BOOT_COMPONENT_VER_SIZE    (0x4)
void fs5_image_layout_boot_component_ver_dump(const struct fs5_image_layout_boot_component_ver *ptr_struct, FILE *fd);
/* u8_stage1_res */
void fs5_image_layout_u8_stage1_res_pack(const struct fs5_image_layout_u8_stage1_res *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_u8_stage1_res_unpack(struct fs5_image_layout_u8_stage1_res *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_u8_stage1_res_print(const struct fs5_image_layout_u8_stage1_res *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_u8_stage1_res_size(void);
#define FS5_IMAGE_LAYOUT_U8_STAGE1_RES_SIZE    (0x42c)
void fs5_image_layout_u8_stage1_res_dump(const struct fs5_image_layout_u8_stage1_res *ptr_struct, FILE *fd);
/* u8_stage1_signature */
void fs5_image_layout_u8_stage1_signature_pack(const struct fs5_image_layout_u8_stage1_signature *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_u8_stage1_signature_unpack(struct fs5_image_layout_u8_stage1_signature *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_u8_stage1_signature_print(const struct fs5_image_layout_u8_stage1_signature *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_u8_stage1_signature_size(void);
#define FS5_IMAGE_LAYOUT_U8_STAGE1_SIGNATURE_SIZE    (0x180)
void fs5_image_layout_u8_stage1_signature_dump(const struct fs5_image_layout_u8_stage1_signature *ptr_struct, FILE *fd);
/* boot_component_header */
void fs5_image_layout_boot_component_header_pack(const struct fs5_image_layout_boot_component_header *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_boot_component_header_unpack(struct fs5_image_layout_boot_component_header *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_boot_component_header_print(const struct fs5_image_layout_boot_component_header *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_boot_component_header_size(void);
#define FS5_IMAGE_LAYOUT_BOOT_COMPONENT_HEADER_SIZE    (0x2000)
void fs5_image_layout_boot_component_header_dump(const struct fs5_image_layout_boot_component_header *ptr_struct, FILE *fd);
/* hw_pointers_gilboa */
void fs5_image_layout_hw_pointers_gilboa_pack(const struct fs5_image_layout_hw_pointers_gilboa *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_hw_pointers_gilboa_unpack(struct fs5_image_layout_hw_pointers_gilboa *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_hw_pointers_gilboa_print(const struct fs5_image_layout_hw_pointers_gilboa *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_hw_pointers_gilboa_size(void);
#define FS5_IMAGE_LAYOUT_HW_POINTERS_GILBOA_SIZE    (0x80)
void fs5_image_layout_hw_pointers_gilboa_dump(const struct fs5_image_layout_hw_pointers_gilboa *ptr_struct, FILE *fd);
/* fs5_image_layout_Nodes */
void fs5_image_layout_fs5_image_layout_Nodes_pack(const union fs5_image_layout_fs5_image_layout_Nodes *ptr_struct, u_int8_t *ptr_buff);
void fs5_image_layout_fs5_image_layout_Nodes_unpack(union fs5_image_layout_fs5_image_layout_Nodes *ptr_struct, const u_int8_t *ptr_buff);
void fs5_image_layout_fs5_image_layout_Nodes_print(const union fs5_image_layout_fs5_image_layout_Nodes *ptr_struct, FILE *fd, int indent_level);
unsigned int fs5_image_layout_fs5_image_layout_Nodes_size(void);
#define FS5_IMAGE_LAYOUT_FS5_IMAGE_LAYOUT_NODES_SIZE    (0x2000)
void fs5_image_layout_fs5_image_layout_Nodes_dump(const union fs5_image_layout_fs5_image_layout_Nodes *ptr_struct, FILE *fd);


#ifdef __cplusplus
}
#endif

#endif // FS5_IMAGE_LAYOUT_LAYOUTS_H

