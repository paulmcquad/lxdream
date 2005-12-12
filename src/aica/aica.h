/**
 * $Id: aica.h,v 1.1 2005-12-11 12:00:09 nkeynes Exp $
 * 
 * MMIO definitions for the AICA sound chip. Note that the regions defined
 * here are relative to the SH4 memory map (0x00700000 based), rather than
 * the ARM addresses (0x00800000 based).
 *
 * Copyright (c) 2005 Nathan Keynes.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "mmio.h"

MMIO_REGION_BEGIN( 0x00700000, AICA0, "AICA Sound System 0-31" )
LONG_PORT( 0x000, AICACH0, PORT_MRW, UNDEFINED, "Channel 0" )
MMIO_REGION_END

MMIO_REGION_BEGIN( 0x00701000, AICA1, "AICA Sound System 32-63" )
LONG_PORT( 0x000, AICACH32, PORT_MRW, UNDEFINED, "Channel 32" )
MMIO_REGION_END

MMIO_REGION_BEGIN( 0x00702000, AICA2, "AICA Sound System Control" )
LONG_PORT( 0x040, VOLLEFT, PORT_MRW, 0, "Volume left" )
LONG_PORT( 0x044, VOLRIGHT, PORT_MRW, 0, "Volume right" )
LONG_PORT( 0x800, AICA_CTRL, PORT_MRW, UNDEFINED, "AICA control" )
LONG_PORT( 0xC00, AICA_RESET,PORT_MRW, 0, "AICA reset" )
MMIO_REGION_END

MMIO_REGION_LIST_BEGIN( spu )
    MMIO_REGION( AICA0 )
    MMIO_REGION( AICA1 )
    MMIO_REGION( AICA2 )
MMIO_REGION_LIST_END

void aica_init( void );
void aica_reset( void );