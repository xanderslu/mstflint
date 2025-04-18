# Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES. ALL RIGHTS RESERVED.
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

# Makefile.am -- Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
    -I$(srcdir) \
    -I$(top_srcdir) \
    -I$(top_srcdir)/common -I$(top_builddir)/common

AM_CXXFLAGS = -Wall -W  -g -MP -MD -pipe $(COMPILER_FPIC)
AM_CXXFLAGS += -DTOOLS_CRYPTO_KEY='$(TOOLS_CRYPTO_KEY)' -DTOOLS_CRYPTO_IV='$(TOOLS_CRYPTO_IV)'

noinst_LTLIBRARIES = libmlxsign.la
libmlxsign_la_SOURCES = mlxsign_lib.cpp mlxsign_lib.h mlxsign_com_def.h \
                       mlxsign_signer_interface.h mlxsign_signer_interface.cpp

if ENABLE_OPENSSL
else
AM_CXXFLAGS += -DNO_OPEN_SSL
endif
