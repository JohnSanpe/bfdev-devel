/* SPDX-License-Identifier: LGPL-3.0-or-later */
/*
 * Copyright(c) 2022 John Sanpe <sanpeqf@gmail.com>
 */

#ifndef _BFX_BTREE_H_
#define _BFX_BTREE_H_

#include <bfdev/config.h>
#include <bfdev/btree.h>

BFDEV_BEGIN_DECLS

extern bfdev_btree_layout_t
bfx_btree_layout32;

extern bfdev_btree_layout_t
bfx_btree_layout64;

extern bfdev_btree_layout_t
bfx_btree_layoutptr;

extern long
bfx_btree_key_find(bfdev_btree_root_t *root, uintptr_t *node, uintptr_t *key);

extern void *
bfx_btree_alloc(bfdev_btree_root_t *root);

extern void
bfx_btree_free(bfdev_btree_root_t *root, void *node);

BFDEV_END_DECLS

#endif /* _BFX_BTREE_H_ */
