/*
 * EFI Boot Guard
 *
 * Copyright (c) Siemens AG, 2017
 *
 * Authors:
 *  Andreas Reichel <andreas.reichel.ext@siemens.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef __H_BOOTGUARD__
#define __H_BOOTGUARD__

#if defined(__GNUC__)
#define __noreturn __attribute__((noreturn))
#define unreachable() __builtin_unreachable()
#else
#define __noreturn /**/
#define unreachable()                                                          \
	do {                                                                   \
	} while (1)
#endif

#include <efi.h>
#include <efilib.h>
#include <efiprot.h>
#include <utils.h>

/* The following definitions regarding status and error constants are
 * implemented the same way the corresponding gnu-efi constants are
 * defined. This is done for symmetry reasons and for the sake of
 * completeness. */
typedef int BG_STATUS;
#define BGERR(a) (-a)
#define BG_ERROR(a) (((int)a) < 0)

#define BG_SUCCESS 0
#define BG_CONFIG_PARTIALLY_CORRUPTED BGERR(100)
#define BG_CONFIG_ERROR BGERR(110)
#define BG_NOT_IMPLEMENTED BGERR(200)

#define DEFAULT_TIMEOUT_SEC 60

#define ENV_FILE_NAME L"BGENV.DAT"

extern EFI_HANDLE this_image;

extern VOLUME_DESC *volumes;
extern UINTN volume_count;

typedef struct _BG_LOADER_PARAMS {
	CHAR16 *payload_path;
	CHAR16 *payload_options;
	UINTN timeout;
} BG_LOADER_PARAMS;

#endif // __H_BOOTGUARD__
