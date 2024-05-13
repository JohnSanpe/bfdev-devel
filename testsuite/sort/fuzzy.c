/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2022 John Sanpe <sanpeqf@gmail.com>
 */

#define MODULE_NAME "sort-fuzzy"
#define bfdev_log_fmt(fmt) MODULE_NAME ": " fmt

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <bfdev/macro.h>
#include <bfdev/sort.h>
#include <bfdev/log.h>
#include <testsuite.h>

#define TEST_LOOP 100

struct sort_test {
    unsigned int index;
    unsigned int value;
};

static long
sort_test_cmp(const void *nodea, const void *nodeb, void *pdata)
{
    unsigned int val1, val2;

    val1 = ((struct sort_test *)nodea)->value;
    val2 = ((struct sort_test *)nodeb)->value;

    return bfdev_cmp(val1 > val2);
}

static void *
test_prepare(int argc, const char *argv[])
{
    return malloc(sizeof(struct sort_test) * TEST_LOOP);
}

static void
test_release(void *data)
{
    free(data);
}

TESTSUITE(
    "sort:fuzzy",
    test_prepare, test_release,
    "sort fuzzy test"
) {
    struct sort_test *test;
    unsigned int count;

    test = data;
    srand(time(NULL));

    for (count = 0; count < TEST_LOOP; ++count) {
        test[count].index = count;
        test[count].value = (unsigned int)rand();
        bfdev_log_debug("generating %u = %u\n", count, test[count].value);
    }

    bfdev_sort(test, TEST_LOOP, sizeof(*test), sort_test_cmp, NULL);
    for (count = 0; count < TEST_LOOP; ++count) {
        bfdev_log_debug("result %u = %u\n", test[count].index, test[count].value);
        if (count && test[count].value < test[count - 1].value) {
            bfdev_log_err("sort failed\n");
            return -BFDEV_EFAULT;
        }
    }

    return -BFDEV_ENOERR;
}
