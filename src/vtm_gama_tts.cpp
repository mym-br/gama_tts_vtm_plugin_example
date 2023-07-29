/*
 * Copyright 2021 Marcelo Y. Matuda
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "vtm_gama_tts.h"

#include <iostream>

#include "VocalTractModel5.h"



extern "C" {

void*
GAMA_TTS_construct_vocal_tract_model(const void* config_data, int is_interactive)
{
	try {
		return new GS::VTM::VocalTractModel5<double, 1>(*reinterpret_cast<const GS::ConfigurationData*>(config_data), is_interactive);
	} catch (std::exception& exc) {
		std::cerr << "Error in the constructor of VocalTractModel5: " << exc.what() << std::endl;
		return NULL;
	} catch (...) {
		std::cerr << "Unknown exception thrown by the constructor of VocalTractModel5." << std::endl;
		return NULL;
	}
}

void
GAMA_TTS_destruct_vocal_tract_model(void *vtm)
{
	delete reinterpret_cast<GS::VTM::VocalTractModel5<double, 1>*>(vtm);
}

} // extern "C"
