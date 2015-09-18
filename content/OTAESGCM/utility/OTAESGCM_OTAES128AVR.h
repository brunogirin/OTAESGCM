/*
The OpenTRV project licenses this file to you
under the Apache Licence, Version 2.0 (the "Licence");
you may not use this file except in compliance
with the Licence. You may obtain a copy of the Licence at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the Licence is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied. See the Licence for the
specific language governing permissions and limitations
under the Licence.

Author(s) / Copyright (s): Deniz Erbillgin 2015
                           Damon Hart-Davis 2015
*/

/* Atmel AVR/ATMega (eg ATMega328P) AES(128) implementation. */

#ifndef ARDUINO_LIB_OTAESGCM_OTAES128AVR_H
#define ARDUINO_LIB_OTAESGCM_OTAES128AVR_H

#if defined(__AVR_ARCH__) || defined(ARDUINO_ARCH_AVR) // Atmel AVR only.

#include <stdint.h>
#include "OTAESGCM_OTAES128.h"


// Use namespaces to help avoid collisions.
namespace OTAESGCM
    {


// TODO: move static workspace up into private fields.  (Then use of separate instance would also be thread-safe.)

    // AVR encrypt-only implementation.
    // Neither re-entrant nor ISR-safe except where stated.
    // Carries workspace but logically no state is carried from one operation to the next.
    class OTAES128E_AVR : public OTAES128E
        {
        public:
            /**
             *    @brief    AES128 block encryption
             *    @param    input takes a pointer to an array containing plaintext, of size 16 bytes; never NULL
             *    @param    key takes a pointer to a 128-bit (16-byte) secret key; never NULL
             *    @param    output takes a pointer to an array to fill with ciphertext, of size 16 bytes; never NULL
             */
            virtual void blockEncrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);
        };

    // AVR decrypt and encrypt implementation.
    // Neither re-entrant nor ISR-safe except where stated.
    // Carries workspace but logically no state is carried from one operation to the next.
    class OTAES128DE_AVR : public OTAES128D, public OTAES128E_AVR
        {
        public:
            /**
             *    @brief    AES128 block decryption
             *    @param    input takes a pointer to an array containing ciphertext, of size 16 bytes; never NULL
             *    @param    key takes a pointer to a 128-bit (16-byte) secret key; never NULL
             *    @param    output takes a pointer to an array to fill with plaintext, of size 16 bytes; never NULL
             */
            virtual void blockDecrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);
        };


    }

#endif
#endif
