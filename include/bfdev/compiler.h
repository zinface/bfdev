/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2023 John Sanpe <sanpeqf@gmail.com>
 */

#ifndef _BFDEV_COMPILER_H_
#define _BFDEV_COMPILER_H_

#ifndef likely
# define likely(x)               __builtin_expect(!!(x), 1)
# define unlikely(x)             __builtin_expect(!!(x), 0)
# define likely_notrace(x)       __builtin_expect(!!(x), 1)
# define unlikely_notrace(x)     __builtin_expect(!!(x), 0)
#endif

/*
 * Optimization barrier
 * The "volatile" is due to gcc bugs
 */
#ifndef barrier
# define barrier() __asm__ __volatile__("": : :"memory")
#endif

/* Not-quite-unique ID. */
#ifndef __UNIQUE_ID
# define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __LINE__)
#endif

#endif /* _BFDEV_COMPILER_H_ */
