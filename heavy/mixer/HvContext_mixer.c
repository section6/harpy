
/**
 * Copyright (c) 2014,2015 Enzien Audio, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, and/or
 * sublicense copies of the Software, strictly on a non-commercial basis,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * DO NOT MODIFY. THIS CODE IS MACHINE GENERATED BY THE SECTION6 HEAVY COMPILER.
 */

/*
 * System Includes
 */

#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include "HvContext_mixer.h"
#include "HeavyMath.h"


/*
 * Function Declarations
 */
static void cReceive_WgSnP_sendMessage(HvBase *, int, const HvMessage *const);
static void cReceive_YEJ8Z_sendMessage(HvBase *, int, const HvMessage *const);
static void cReceive_mUjxA_sendMessage(HvBase *, int, const HvMessage *const);
static void cReceive_3JgnN_sendMessage(HvBase *, int, const HvMessage *const);



/*
 * Static Helper Functions
 */

static void ctx_intern_scheduleMessageForReceiver(
    HvBase *const _c, const char *name, HvMessage *m) {
  switch (msg_symbolToHash(name)) {
    case 0x2FD59180: { // gain2
      ctx_scheduleMessage(_c, m, &cReceive_WgSnP_sendMessage, 0);
      break;
    }
    case 0xB374A581: { // gain3
      ctx_scheduleMessage(_c, m, &cReceive_mUjxA_sendMessage, 0);
      break;
    }
    case 0x14CF200A: { // gain0
      ctx_scheduleMessage(_c, m, &cReceive_YEJ8Z_sendMessage, 0);
      break;
    }
    case 0x20218051: { // gain1
      ctx_scheduleMessage(_c, m, &cReceive_3JgnN_sendMessage, 0);
      break;
    }
    default: return;
  }
}

static struct HvTable *ctx_intern_getTableForHash(HvBase *const _c, hv_uint32_t h) {
  switch (h) {
    default: return NULL;
  }
}



/*
 * Context Include and Implementatons
 */

Hv_mixer *hv_mixer_new_with_pool(double sampleRate, int poolKb) {
  hv_assert(sampleRate > 0.0); // can't initialise with sampling rate of 0
  hv_assert(poolKb >= 1); // a message pool of some reasonable size is always needed
  Hv_mixer *const _c = (Hv_mixer *) hv_malloc(sizeof(Hv_mixer));

  Base(_c)->numInputChannels = 8;
  Base(_c)->numOutputChannels = 2;
  Base(_c)->sampleRate = sampleRate;
  Base(_c)->blockStartTimestamp = 0;
  Base(_c)->f_scheduleMessageForReceiver = &ctx_intern_scheduleMessageForReceiver;
  Base(_c)->f_getTableForHash = &ctx_intern_getTableForHash;
  mq_initWithPoolSize(&Base(_c)->mq, poolKb);
  Base(_c)->basePath = NULL;
  Base(_c)->printHook = NULL;
  Base(_c)->sendHook = NULL;
  Base(_c)->userData = NULL;
  Base(_c)->name = "mixer";

  Base(_c)->numBytes = sizeof(Hv_mixer);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_1fxQa, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_YKDzd, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_jpuoN, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_50il5, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_12TFn, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_qDd93, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_qtgQp, 0.0f, 0.0f, false);
  Base(_c)->numBytes += sVarf_init(&_c->sVarf_exlvd, 0.0f, 0.0f, false);

  // loadbang

  return _c;
}

Hv_mixer *hv_mixer_new(double sampleRate) {
  return hv_mixer_new_with_pool(sampleRate, 10); // default to 10KB MessagePool
}

void hv_mixer_free(Hv_mixer *_c) {

  hv_free(Base(_c)->basePath);
  mq_free(&Base(_c)->mq); // free queue after all objects have been freed, messages may be cancelled

  hv_free(_c);
}



/*
 * Static Function Implementation
 */
static void cReceive_WgSnP_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qDd93, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YKDzd, m);
}

static void cReceive_YEJ8Z_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_12TFn, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jpuoN, m);
}

static void cReceive_mUjxA_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qtgQp, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1fxQa, m);
}

static void cReceive_3JgnN_sendMessage(HvBase *_c, int letIn, const HvMessage *const m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_exlvd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_50il5, m);
}




/*
 * Context Process Implementation
 */

int hv_mixer_process(Hv_mixer *const _c, float **const inputBuffers, float **const outputBuffers, int nx) {
  const int n4 = nx & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1, I2, I3, I4, I5, I6, I7;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = Base(_c)->blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&Base(_c)->mq, nextBlock)) {
      MessageNode *const node = mq_peek(&Base(_c)->mq);
      node->sendMessage(Base(_c), node->let, node->m);
      mq_pop(&Base(_c)->mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));
    __hv_load_f(inputBuffers[2]+n, VOf(I2));
    __hv_load_f(inputBuffers[3]+n, VOf(I3));
    __hv_load_f(inputBuffers[4]+n, VOf(I4));
    __hv_load_f(inputBuffers[5]+n, VOf(I5));
    __hv_load_f(inputBuffers[6]+n, VOf(I6));
    __hv_load_f(inputBuffers[7]+n, VOf(I7));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_var_f(&_c->sVarf_1fxQa, VOf(Bf0));
    __hv_var_f(&_c->sVarf_YKDzd, VOf(Bf1));
    __hv_var_f(&_c->sVarf_jpuoN, VOf(Bf2));
    __hv_var_f(&_c->sVarf_50il5, VOf(Bf3));
    __hv_mul_f(VIf(I2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(I0), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(I4), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(I6), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_var_f(&_c->sVarf_12TFn, VOf(Bf3));
    __hv_var_f(&_c->sVarf_qDd93, VOf(Bf0));
    __hv_var_f(&_c->sVarf_qtgQp, VOf(Bf1));
    __hv_var_f(&_c->sVarf_exlvd, VOf(Bf2));
    __hv_mul_f(VIf(I3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(I7), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(I5), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(I1), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  Base(_c)->blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int hv_mixer_process_inline(Hv_mixer *c, float *const inputBuffers, float *const outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD
  int i = ctx_getNumInputChannels(Base(c));
  float **bIn = (float **) hv_alloca(i*sizeof(float *));
  while (i--) bIn[i] = inputBuffers+(i*n4);

  i = ctx_getNumOutputChannels(Base(c));
  float **bOut = (float **) hv_alloca(i*sizeof(float *));
  while (i--) bOut[i] = outputBuffers+(i*n4);

  int n = hv_mixer_process(c, bIn, bOut, n4);
  return n;
}

int hv_mixer_process_inline_short(Hv_mixer *c, short *const inputBuffers, short *const outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD
  int numChannels = ctx_getNumInputChannels(Base(c));
  float *bIn = (float *) hv_alloca(numChannels*n4*sizeof(float));
  for (int i = 0; i < numChannels; ++i) {
    for (int j = 0; j < n4; ++j) {
      bIn[i*n4+j] = ((float) inputBuffers[i+numChannels*j]) * 0.00003051757813f;
    }
  }

  numChannels = ctx_getNumOutputChannels(Base(c));
  float *bOut = (float *) hv_alloca(numChannels*n4*sizeof(float));

  int n = hv_mixer_process_inline(c, bIn, bOut, n4);

  for (int i = 0; i < numChannels; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+numChannels*j] = (short) (bOut[i*n4+j] * 32767.0f);
    }
  }

  return n;
}