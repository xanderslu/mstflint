/*
 * Copyright (c) 2021 NVIDIA CORPORATION & AFFILIATES. ALL RIGHTS RESERVED.
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
#include <linux/highmem.h>
#include <linux/sched.h>
#include "mst_kernel.h"

/****************************************************/
int pci_read4_vpd(struct mst_dev_data* dev, unsigned int timeout, unsigned int offset, u32* buf)
{
    struct pci_dev* pci_dev = dev->pci_dev;
    int vpd_cap = dev->vpd_cap_addr;
    unsigned long end;
    uint16_t addr;
    int done, res = 0;

    if (!vpd_cap)
    {
        mst_err("device %s not support Vital Product Data\n", dev->name);
        return -ENODEV;
    }

    if (!timeout)
        timeout = MST_VPD_DEFAULT_TOUT;

    /* sets F bit to zero and write VPD addr */
    addr = (0x7fff & offset);
    res = pci_write_config_word(pci_dev, vpd_cap + PCI_VPD_ADDR, addr);
    if (res)
    {
        mst_err("pci_write_config_dword failed\n");
        return res;
    }

    /* wait for data until F bit is set with one */
    addr = 0x0;
    done = 0;

    end = msecs_to_jiffies(timeout) + jiffies;
    while (time_before(jiffies, end))
    {
        res = pci_read_config_word(pci_dev, vpd_cap + PCI_VPD_ADDR, &addr);
        if (res)
        {
            mst_err("pci_read_config_word failed\n");
            return res;
        }

        if (addr & 0x8000)
        {
            done = 1;
            break;
        }

        cond_resched();
    }

    if (!done)
        return -ETIMEDOUT;

    /* read data */
    res = pci_read_config_dword(pci_dev, vpd_cap + PCI_VPD_DATA, buf);
    if (res)
    {
        mst_err("pci_read_config_word failed\n");
        return res;
    }

    return res;
}
EXPORT_SYMBOL(pci_read4_vpd);

int pci_write4_vpd(struct mst_dev_data* dev, unsigned int timeout, unsigned int offset, u32 buf)
{
    struct pci_dev* pci_dev = dev->pci_dev;
    int vpd_cap = dev->vpd_cap_addr;
    unsigned long end;
    uint16_t addr;
    int done, res = 0;

    if (!vpd_cap)
    {
        mst_err("device %s not support Vital Product Data\n", dev->name);
        return -ENODEV;
    }

    if (!timeout)
        timeout = MST_VPD_DEFAULT_TOUT;

    /* write data */
    res = pci_write_config_dword(pci_dev, vpd_cap + PCI_VPD_DATA, buf);
    if (res)
    {
        mst_err("pci_read_config_word failed\n");
        return res;
    }

    /* sets F bit to one and write VPD addr */
    addr = 0x8000 | (0x7ffff & offset);
    res = pci_write_config_word(pci_dev, vpd_cap + PCI_VPD_ADDR, addr);
    if (res)
    {
        mst_err("pci_write_config_dword failed\n");
        return res;
    }

    /* wait for data until F bit is set with zero */
    addr = 0x0;
    done = 0;

    end = msecs_to_jiffies(timeout) + jiffies;
    while (time_before(jiffies, end))
    {
        res = pci_read_config_word(pci_dev, vpd_cap + PCI_VPD_ADDR, &addr);
        if (res)
        {
            mst_err("pci_read_config_word failed\n");
            return res;
        }

        if (!(addr & 0x8000))
        {
            done = 1;
            break;
        }

        cond_resched();
    }

    if (!done)
        return -ETIMEDOUT;

    return res;
}
EXPORT_SYMBOL(pci_write4_vpd);
