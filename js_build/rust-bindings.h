/* Copyright (C) 2019 Open Information Security Foundation
*
* You can copy, redistribute or modify this Program under the terms of
* the GNU General Public License version 2 as published by the Free
* Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* version 2 along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
* 02110-1301, USA.
*/

#ifndef __RUST_BINDINGS_GEN_H_
#define __RUST_BINDINGS_GEN_H_

/* Generated with cbindgen:0.20.0 */

/* DO NOT EDIT This file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct JsonBuilder JsonBuilder;

/**
 * A "mark" or saved state for a JsonBuilder object.
 *
 * The name is full, and the types are u64 as this object is used
 * directly in C as well.
 */
typedef struct JsonBuilderMark {
    uint64_t position;
    uint64_t state_index;
    uint64_t state;
} JsonBuilderMark;




/**
 * Free a CString allocated by Rust (for ex. using `rust_string_to_c`)
 *
 * # Safety
 *
 * s must be allocated by rust, using `CString::new`
 */
void rs_cstring_free(char *s);

struct JsonBuilder *jb_new_object(void);

struct JsonBuilder *jb_new_array(void);

struct JsonBuilder *jb_clone(struct JsonBuilder *js);

void jb_free(struct JsonBuilder *js);

uintptr_t jb_capacity(struct JsonBuilder *jb);

void jb_reset(struct JsonBuilder *jb);

bool jb_open_object(struct JsonBuilder *js, const char *key);

bool jb_start_object(struct JsonBuilder *js);

bool jb_open_array(struct JsonBuilder *js, const char *key);

bool jb_set_string(struct JsonBuilder *js, const char *key, const char *val);

bool jb_set_string_from_bytes(struct JsonBuilder *js,
                              const char *key,
                              const uint8_t *bytes,
                              uint32_t len);

bool jb_set_formatted(struct JsonBuilder *js, const char *formatted);

bool jb_append_object(struct JsonBuilder *jb, const struct JsonBuilder *obj);

bool jb_set_object(struct JsonBuilder *js,
                   const char *key,
                   struct JsonBuilder *val);

bool jb_append_string(struct JsonBuilder *js, const char *val);

bool jb_append_string_from_bytes(struct JsonBuilder *js,
                                 const uint8_t *bytes,
                                 uint32_t len);

bool jb_append_uint(struct JsonBuilder *js, uint64_t val);

bool jb_append_float(struct JsonBuilder *js, double val);

bool jb_set_uint(struct JsonBuilder *js, const char *key, uint64_t val);

bool jb_set_float(struct JsonBuilder *js, const char *key, double val);

bool jb_set_bool(struct JsonBuilder *js, const char *key, bool val);

bool jb_close(struct JsonBuilder *js);

uintptr_t jb_len(const struct JsonBuilder *js);

const uint8_t *jb_ptr(struct JsonBuilder *js);

void jb_get_mark(struct JsonBuilder *js, struct JsonBuilderMark *mark);

bool jb_restore_mark(struct JsonBuilder *js, struct JsonBuilderMark *mark);




#endif /* __RUST_BINDINGS_GEN_H_ */
