/**
 * Copyright (c) 2014,2015,2016 Enzien Audio Ltd.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include "ControlTabread.h"
#include "HvTable.h"

hv_size_t cTabread_init(ControlTabread *o, struct HvTable *table) {
  o->table = table;
  return 0;
}

void cTabread_onMessage(HvBase *_c, ControlTabread *o, int letIn, const HvMessage *const m,
    void (*sendMessage)(HvBase *, int, const HvMessage *const)) {
  switch (letIn) {
    case 0: {
      if (msg_isFloat(m,0) && o->table != NULL) {
        const int x = (int) msg_getFloat(m,0);
        if (x >= 0 && x < hTable_getSize(o->table)) {
          HvMessage *n = HV_MESSAGE_ON_STACK(1);
          msg_initWithFloat(n,msg_getTimestamp(m), hTable_getBuffer(o->table)[x]);
          sendMessage(_c, 0, n);
        }
      }
      break;
    }
    case 1: {
      if (msg_isHashLike(m,0)) {
        o->table = ctx_getTableForHash(_c, msg_getHash(m,0));
      }
      break;
    }
    default: return;
  }
}
