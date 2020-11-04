/* This testcase is part of GDB, the GNU debugger.

   Copyright 2010-2020 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

asm (".globl cu_text_start");
asm ("cu_text_start:");

asm (".globl func_nofb_start");
asm ("func_nofb_start:");

void
func_nofb (void)
{
  /* int func_nofb_var; */
  /* int func_nofb_var2; */

  extern void func_nofb_marker (void);
  func_nofb_marker ();
}

asm (".globl func_nofb_end");
asm ("func_nofb_end:");

asm (".globl func_loopfb_start");
asm ("func_loopfb_start:");

void
func_loopfb (void)
{
  /* int func_loopfb_var; */
  /* int func_loopfb_var2; */

  extern void func_loopfb_marker (void);
  func_loopfb_marker ();
}

asm (".globl func_loopfb_end");
asm ("func_loopfb_end:");

asm (".globl cu_text_end");
asm ("cu_text_end:");

/* The .debug_names-based index support depends on .debug_aranges
   generated by GCC.  (.gdb_index includes a gdb-generated map
   instead.)  */
asm (
"       .pushsection    .debug_info,\"\",%progbits \n"
".Lcu1_begin: \n"
"       .popsection \n"
"	.pushsection	.debug_aranges,\"\",%progbits \n"
"	.4byte	.Laranges_end - .Laranges_start \n"	// Length of Address Ranges Info
".Laranges_start: \n"
"	.2byte	0x2 \n"	// DWARF Version
"	.4byte  .Lcu1_begin\n" // .Ldebug_info0 - Offset of Compilation Unit Info
"	.byte	4 \n"	// Size of Address
"	.byte	0 \n"	// Size of Segment Descriptor
"	.2byte	0 \n"	// Pad to 16 byte boundary
"	.2byte	0 \n"
"	.4byte	cu_text_start \n"	// Address
"	.4byte	cu_text_end - cu_text_start \n"	// Length
"	.4byte	0 \n"
"	.4byte	0 \n"
".Laranges_end: \n"
"	.popsection \n"
);
