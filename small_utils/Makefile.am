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

PYTHON_WRAPPER_SCRIPT = ../common/python_wrapper

AM_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include/mtcr_ul -I$(top_srcdir)/common -I$(top_builddir)/common -I$(top_srcdir)/mvpd -I$(top_srcdir)/dev_mgt $(COMPILER_FPIC)

bin_PROGRAMS = \
    mstmread \
    mstmwrite \
    mstmcra \
    mstmtserver \
    mstvpd \
    mstcongestion \
    mstmget_temp

bin_SCRIPTS = mstfwreset

mstmread_SOURCES = mread.c
mstmread_DEPENDENCIES = $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la
mstmread_LDADD = $(mstmread_DEPENDENCIES) ${LDL}
mstmread_LDFLAGS = -static

mstmwrite_SOURCES = mwrite.c
mstmwrite_DEPENDENCIES = $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la
mstmwrite_LDADD = $(mstmwrite_DEPENDENCIES) ${LDL}
mstmwrite_LDFLAGS = -static

mstvpd_SOURCES = vpd.c
mstvpd_DEPENDENCIES = $(top_builddir)/mvpd/libmvpd.la \
               $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la \
               $(top_builddir)/dev_mgt/libdev_mgt.la \
               $(top_builddir)/reg_access/libreg_access.la \
               $(top_builddir)/tools_layouts/libtools_layouts.la
mstvpd_LDADD = $(mstvpd_DEPENDENCIES) ${LDL}
mstvpd_LDFLAGS = -static

mstcongestion_SOURCES = congestion.cpp
mstcongestion_DEPENDENCIES = $(top_builddir)/cmdif/libcmdif.la \
					  $(top_builddir)/dev_mgt/libdev_mgt.la \
                      $(top_builddir)/reg_access/libreg_access.la \
                      $(top_builddir)/tools_layouts/libtools_layouts.la \
                      $(top_builddir)/cmdparser/libcmdparser.a \
                      $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la
mstcongestion_LDADD = $(mstcongestion_DEPENDENCIES) ${LDL}
mstcongestion_LDFLAGS = -static

mstmcra_SOURCES = mcra.c
mstmcra_DEPENDENCIES = $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la
mstmcra_LDADD = $(mstmcra_DEPENDENCIES) ${LDL}
mstmcra_LDFLAGS = -static

if LINUX_BUILD
bin_PROGRAMS += mstfwctrl

mstfwctrl_SOURCES = mstfwctrl.c
mstfwctrl_DEPENDENCIES = $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la \
               			 $(top_builddir)/dev_mgt/libdev_mgt.la \
 	                     $(top_builddir)/reg_access/libreg_access.la
mstfwctrl_LDADD = $(mstfwctrl_DEPENDENCIES) ${LDL}
mstfwctrl_LDFLAGS = -static
endif

mstmtserver_SOURCES = mtserver.c tcp.c tcp.h
mstmtserver_CFLAGS = -DMST_UL
mstmtserver_DEPENDENCIES = $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la
mstmtserver_LDADD = $(mstmtserver_DEPENDENCIES) ${LDL}
mstmtserver_LDFLAGS = -static

SUBDIRS = mlxfwresetlib
MSTFWRESET_PYTHON_WRAPPER=mstfwreset
${MSTFWRESET_PYTHON_WRAPPER}: $(PYTHON_WRAPPER_SCRIPT)
	cp $(PYTHON_WRAPPER_SCRIPT) $@
mstfwresetlibdir=$(libdir)/mstflint/python_tools/$(MSTFWRESET_PYTHON_WRAPPER)

mlxpcilibdir=$(libdir)/mstflint/python_tools/mlxpci
mlxpcilib_DATA = binary_file.py mlxpci_lib.py

mstfwresetlib_DATA = $(MSTFWRESET_PYTHON_WRAPPER).py

bin_PROGRAMS += mstmget_temp

mstmget_temp_SOURCES = mget_temp.c mget_temp.h
mstmget_temp_DEPENDENCIES = $(top_builddir)/${MTCR_CONF_DIR}/libmtcr_ul.la \
               			 $(top_builddir)/dev_mgt/libdev_mgt.la \
 	                     $(top_builddir)/reg_access/libreg_access.la
mstmget_temp_LDADD = $(mstmget_temp_DEPENDENCIES) ${LDL}
mstmget_temp_LDFLAGS = -static
