/* SPDX-License-Identifier: LGPL-3.0-or-later */
/*
 * Copyright(c) 2022 John Sanpe <sanpeqf@gmail.com>
 */

#include <bfdev/crc.h>
#include <bfdev/crypto/crc-rocksoft-inline.h>
#include <export.h>

export uint64_t
bfdev_crc_rocksoft(const void *data, size_t len, uint64_t crc)
{
    return bfdev_crc_rocksoft_inline(data, len, crc);
}
