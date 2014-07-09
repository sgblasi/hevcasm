/*
The copyright in this software is being made available under the BSD
License, included below. This software may be subject to other third party
and contributor rights, including patent rights, and no such rights are
granted under this license.


Copyright(c) 2011 - 2014, Parabola Research Limited
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met :

* Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and / or other materials provided with the distribution.
* Neither the name of the copyright holder nor the names of its contributors may
be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef INCLUDED_sad_h
#define INCLUDED_sad_h

#include "hevcasm.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Rectangular SAD (Sum of Absolute Differences) with single reference */
typedef int hevcasm_sad(const uint8_t *src, ptrdiff_t stride_src, const uint8_t *ref, ptrdiff_t stride_ref, uint32_t rect);
hevcasm_sad* HEVCASM_API hevcasm_get_sad(int width, int height, hevcasm_instruction_set mask);
int HEVCASM_API hevcasm_test_sad(hevcasm_instruction_set mask);

/* Rectangular SAD (Sum of Absolute Differences) with multiple references */
typedef void hevcasm_sad_multiref(const uint8_t *src, ptrdiff_t stride_src, const uint8_t *ref[], ptrdiff_t stride_ref, int sad[], uint32_t rect);
hevcasm_sad_multiref* HEVCASM_API hevcasm_get_sad_multiref(int ways, int width, int height, hevcasm_instruction_set mask);
int HEVCASM_API hevcasm_test_sad_multiref(hevcasm_instruction_set mask);



#ifdef __cplusplus
}
#endif


#endif