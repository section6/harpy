
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
 * DO NOT MODIFY. THIS CODE IS MACHINE GENERATED BY THE ENZIEN AUDIO HEAVY COMPILER.
 */

#ifndef _HEAVYCONTEXT_SLOT0_H_
#define _HEAVYCONTEXT_SLOT0_H_

#include "HvBase.h"

#define Context(_x) ((Hv_slot0 *) (_x))

// object includes
#include "ControlSystem.h"
#include "SignalVar.h"
#include "ControlCast.h"
#include "SignalLine.h"
#include "HeavyMath.h"
#include "ControlBinop.h"
#include "ControlDelay.h"
#include "ControlVar.h"
#include "SignalPhasor.h"
#include "ControlUnop.h"

typedef struct Hv_slot0 {
  HvBase base;

  // objects
  SignalLine sLine_jF2jq;
  SignalPhasor sPhasor_G9l1w;
  SignalLine sLine_O7R26;
  SignalVarf sVarf_7hiGi;
  SignalVarf sVarf_mEhBS;
  SignalVarf sVarf_SSqFv;
  ControlBinop cBinop_vtAOk;
  ControlBinop cBinop_7no2o;
  ControlDelay cDelay_kkkKn;
  ControlVar cVar_ZpZIH;
  ControlBinop cBinop_3JGoR;
  ControlBinop cBinop_kL7Y1;
} Hv_slot0;

#endif // _HEAVYCONTEXT_SLOT0_H_
