/**
 * Copyright (c) 2014, 2015, Enzien Audio Ltd.
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

#include "ControlSystem.h"
#include "HvTable.h"

void cSystem_onMessage(HvBase *_c, void *o, int letIn, const HvMessage *const m,
    void (*sendMessage)(HvBase *, int, const HvMessage *const)) {

  HvMessage *n = HV_MESSAGE_ON_STACK(1);
  if (msg_compareSymbol(m, 0, "samplerate")) {
    msg_initWithFloat(n, msg_getTimestamp(m), (float) ctx_getSampleRate(_c));
  } else if (msg_compareSymbol(m, 0, "numInputChannels")) {
    msg_initWithFloat(n, msg_getTimestamp(m), (float) ctx_getNumInputChannels(_c));
  } else if (msg_compareSymbol(m, 0, "numOutputChannels")) {
    msg_initWithFloat(n, msg_getTimestamp(m), (float) ctx_getNumOutputChannels(_c));
  } else if (msg_compareSymbol(m, 0, "currentTime")) {
    msg_initWithFloat(n, msg_getTimestamp(m), (float) msg_getTimestamp(m));
  } else if (msg_compareSymbol(m, 0, "table")) {
    // NOTE(mhroth): no need to check message format for symbols as table lookup will fail otherwise
    HvTable *o = ctx_getTableForHash(_c, msg_getHash(m,1));
    if (o != NULL) {
      if (msg_compareSymbol(m, 2, "length")) {
        msg_initWithFloat(n, msg_getTimestamp(m), (float) hTable_getLength(o));
      } else if (msg_compareSymbol(m, 2, "size")) {
        msg_initWithFloat(n, msg_getTimestamp(m), (float) hTable_getSize(o));
      } else if (msg_compareSymbol(m, 2, "head")) {
        msg_initWithFloat(n, msg_getTimestamp(m), (float) hTable_getHead(o));
      } else return;
    } else return;
  } else return;
  sendMessage(_c, 0, n);
}
