#--
# Copyright (c) 2004-2021 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
#
# This software is available to you under a choice of one of two
# licenses.  You may choose to be licensed under the terms of the GNU
# General Public License (GPL) Version 2, available from the file
# COPYING in the main directory of this source tree, or the
# OpenIB.org BSD license below:
#
#     Redistribution and use in source and binary forms, with or
#     without modification, are permitted provided that the following
#     conditions are met:
#
#      - Redistributions of source code must retain the above
#        copyright notice, this list of conditions and the following
#        disclaimer.
#
#      - Redistributions in binary form must reproduce the above
#        copyright notice, this list of conditions and the following
#        disclaimer in the documentation and/or other materials
#        provided with the distribution.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
# ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#--

# Makefile.am -- Process this file with automake to produce Makefile.in
USER_DIR = $(top_srcdir)
AM_CPPFLAGS = -I. -I$(USER_DIR) -I$(USER_DIR)/common $(COMPILER_FPIC)

AM_CFLAGS = -MD -pipe -Wall -W  $(COMPILER_FPIC)

AM_CXXFLAGS = -Wall -W -g -MP -MD -pipe  $(COMPILER_FPIC)

noinst_HEADERS = mft_sig_handler.h errmsg.h hex64.h

noinst_LTLIBRARIES = libmftutils.la

libmftutils_la_SOURCES =  mft_sig_handler.c errmsg.cpp calc_hw_crc.c mlarge_buffer.cpp mft_utils.cpp hex64.cpp crc16.h crc16.cpp

