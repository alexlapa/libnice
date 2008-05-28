/*
 * This file is part of the Nice GLib ICE library.
 *
 * (C) 2007 Nokia Corporation. All rights reserved.
 *  Contact: Rémi Denis-Courmont
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Nice GLib ICE library.
 *
 * The Initial Developers of the Original Code are Collabora Ltd and Nokia
 * Corporation. All Rights Reserved.
 *
 * Contributors:
 *   Rémi Denis-Courmont, Nokia
 *
 * Alternatively, the contents of this file may be used under the terms of the
 * the GNU Lesser General Public License Version 2.1 (the "LGPL"), in which
 * case the provisions of LGPL are applicable instead of those above. If you
 * wish to allow use of your version of this file only under the terms of the
 * LGPL and not to allow others to use your version of this file under the
 * MPL, indicate your decision by deleting the provisions above and replace
 * them with the notice and other provisions required by the LGPL. If you do
 * not delete the provisions above, a recipient may use your version of this
 * file under either the MPL or the LGPL.
 */

#ifndef STUN_UTILS_H
# define STUN_UTILS_H 1

/**
 * @file utils.h
 * @brief STUN client generic utility functions
 */

#include "stun-msg.h"

# ifdef __cplusplus
extern "C" {
# endif


int sockaddrcmp (const struct sockaddr *a, const struct sockaddr *b);

bool stun_optional (uint16_t t);

size_t stun_padding (size_t l);

size_t stun_align (size_t l);

uint16_t stun_getw (const uint8_t *ptr);

uint16_t stun_length (const uint8_t *ptr);

stun_class_t stun_get_class (const uint8_t *msg);

stun_method_t stun_get_method (const uint8_t *msg);

const uint8_t *stun_id (const uint8_t *msg);

bool stun_present (const uint8_t *msg, stun_attr_type_t type);

bool stun_has_unknown (const void *msg);

# ifndef NDEBUG
bool stun_valid (const uint8_t *msg);
# endif

void stun_debug (const char *fmt, ...);

void stun_debug_bytes (const void *data, size_t len);

# ifdef __cplusplus
}
# endif

#endif /* !STUN_UTILS_H */