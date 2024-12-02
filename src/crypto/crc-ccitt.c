/* SPDX-License-Identifier: LGPL-3.0-or-later */
/*
 * Copyright(c) 2022 Jalen Wong <sanpeqf@gmail.com>
 */

#include <bfdev/crc.h>
#include <bfdev/crypto/crc-ccitt-inline.h>
#include <export.h>

export uint16_t
bfdev_crc_ccitt(const void *data, size_t len, uint16_t crc)
{
    return bfdev_crc_ccitt_inline(data, len, crc);
}
