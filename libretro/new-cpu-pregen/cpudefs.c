#include "sysconfig.h"
#include "sysdeps.h"
#include "readcpu.h"
struct instr_def defs68k[] = {
/* ORSR.B  */
{0x003C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{0,0},{0,0},{0,0},{0,0},{0,0}},0x10,_T("ORSR.B  #1"), 0, 0, 0, 0},
/* ORSR.W  */
{0x007C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("ORSR.W  #1"), 0, 0, 0, 0},
/* CHK2.z  */
{0x00C0, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xF9C0,2,5,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("CHK2.z  #1,s[!Dreg,Areg,Aipi,Apdi,Immd]"), 0, 0, 0, 0},
/* OR.z  */
{0x0000, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("OR.z    #z,d[Dreg]"), 2, 0, 2, 3},
/* OR.z  */
{0x0000, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("OR.z    #z,d[!Areg,Dreg]"), 0, 1, 3, 3},
/* ANDSR.B  */
{0x023C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{0,0},{0,0},{0,0},{0,0},{0,0}},0x10,_T("ANDSR.B #1"), 0, 0, 0, 0},
/* ANDSR.W  */
{0x027C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("ANDSR.W #1"), 0, 0, 0, 0},
/* AND.z  */
{0x0200, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("AND.z   #z,d[Dreg]"), 2, 0, 2, 3},
/* AND.z  */
{0x0200, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("AND.z   #z,d[!Areg,Dreg]"), 0, 1, 3, 3},
/* SUB.z  */
{0x0400, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   #z,d[Dreg]"), 2, 0, 2, 3},
/* SUB.z  */
{0x0400, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   #z,d[!Areg,Dreg]"), 0, 1, 3, 3},
/* ADD.z  */
{0x0600, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   #z,d[Dreg]"), 2, 0, 2, 3},
/* ADD.z  */
{0x0600, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   #z,d[!Areg,Dreg]"), 0, 1, 3, 3},
/* CALLM  */
{0x06C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,3,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("CALLM   s[!Dreg,Areg,Aipi,Apdi,Immd]"), 0, 0, 0, 0},
/* RTM  */
{0x06C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,3,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("RTM     s[Dreg,Areg]"), 0, 0, 0, 0},
/* BTST  */
{0x0800, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x11,_T("BTST    #1,s[Dreg]"), 4, 0, 4, 0},
/* BTST  */
{0x0800, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x11,_T("BTST    #1,s[!Areg,Dreg,Immd]"), 0, 0, 4, 3},
/* BCHG  */
{0x0840, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCHG    #1,s[Dreg]"), 6, 0, 6, 0},
/* BCHG  */
{0x0840, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCHG    #1,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 6, 3},
/* BCLR  */
{0x0880, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCLR    #1,s[Dreg]"), 6, 0, 6, 0},
/* BCLR  */
{0x0880, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCLR    #1,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 6, 3},
/* BSET  */
{0x08C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BSET    #1,s[Dreg]"), 6, 0, 6, 0},
/* BSET  */
{0x08C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BSET    #1,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 6, 3},
/* EORSR.B  */
{0x0A3C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{0,0},{0,0},{0,0},{0,0},{0,0}},0x10,_T("EORSR.B #1"), 0, 0, 0, 0},
/* EORSR.W  */
{0x0A7C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("EORSR.W #1"), 0, 0, 0, 0},
/* EOR.z  */
{0x0A00, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("EOR.z   #z,d[Dreg]"), 2, 0, 2, 3},
/* EOR.z  */
{0x0A00, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("EOR.z   #z,d[!Areg,Dreg]"), 0, 1, 3, 3},
/* CMP.z  */
{0x0C00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMP.z   #z,s[Dreg]"), 2, 0, 2, 3},
/* CMP.z  */
{0x0C00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMP.z   #z,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 2, 3},
/* CMP.z  */
{0x0C00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,2,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMP.z   #z,s[PC8r,PC16]"), 0, 0, 2, 3},
/* CAS.B  */
{0x0AC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("CAS.B   #1,s[!Dreg,Areg,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* CAS.W  */
{0x0CC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("CAS.W   #1,s[!Dreg,Areg,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* CAS2.W  */
{0x0CFC, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,2,5,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("CAS2.W  #2"), 0, 0, 0, 0},
/* MOVES.z  */
{0x0E00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,1,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("MOVES.z #1,s[!Dreg,Areg,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* CAS.L  */
{0x0EC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("CAS.L   #1,s[!Dreg,Areg,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* CAS2.L  */
{0x0EFC, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,2,5,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("CAS2.L  #2"), 0, 0, 0, 0},
/* MVPMR.W  */
{0x0100, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,5,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MVPMR.W d[Areg-Ad16],Dr"), 0, 0, 0, 0},
/* MVPMR.L  */
{0x0140, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,5,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MVPMR.L d[Areg-Ad16],Dr"), 0, 0, 0, 0},
/* MVPRM.W  */
{0x0180, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,5,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MVPRM.W Dr,d[Areg-Ad16]"), 0, 0, 0, 0},
/* MVPRM.L  */
{0x01C0, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,5,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MVPRM.L Dr,d[Areg-Ad16]"), 0, 0, 0, 0},
/* BTST  */
{0x0100, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x11,_T("BTST    Dr,s[Dreg]"), 4, 0, 4, 0},
/* BTST  */
{0x0100, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x11,_T("BTST    Dr,s[!Areg,Dreg]"), 0, 0, 4, 1},
/* BCHG  */
{0x0140, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCHG    Dr,s[Dreg]"), 6, 0, 6, 0},
/* BCHG  */
{0x0140, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCHG    Dr,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 6, 1},
/* BCLR  */
{0x0180, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCLR    Dr,s[Dreg]"), 6, 0, 6, 0},
/* BCLR  */
{0x0180, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BCLR    Dr,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 6, 1},
/* BSET  */
{0x01C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BSET    Dr,s[Dreg]"), 6, 0, 6, 0},
/* BSET  */
{0x01C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,0},{1,1},{1,1}},0x13,_T("BSET    Dr,s[!Areg,Dreg,Immd,PC8r,PC16]"), 0, 0, 6, 1},
/* MOVE.B  */
{0x1000,12,{14,14,14,13,13,13,11,11,11,12,12,12, 0, 0, 0, 0},0xF000,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x12,_T("MOVE.B  s,d[!Areg]"), 0, 0, 0, 0},
/* MOVEA.W  */
{0x3000,12,{14,14,14,13,13,13,11,11,11,12,12,12, 0, 0, 0, 0},0xF000,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVEA.W s,d[Areg]"), 0, 0, 0, 0},
/* MOVE.W  */
{0x3000,12,{14,14,14,13,13,13,11,11,11,12,12,12, 0, 0, 0, 0},0xF000,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x12,_T("MOVE.W  s,d[!Areg]"), 0, 0, 0, 0},
/* MOVEA.L  */
{0x2000,12,{14,14,14,13,13,13,11,11,11,12,12,12, 0, 0, 0, 0},0xF000,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVEA.L s,d[Areg]"), 0, 0, 0, 0},
/* MOVE.L  */
{0x2000,12,{14,14,14,13,13,13,11,11,11,12,12,12, 0, 0, 0, 0},0xF000,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x12,_T("MOVE.L  s,d[!Areg]"), 0, 0, 0, 0},
/* NEGX.z  */
{0x4000, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{0,0},{1,4},{0,0},{1,4},{1,0}},0x30,_T("NEGX.z  d[Dreg]"), 2, 0, 2, 0},
/* NEGX.z  */
{0x4000, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{0,0},{1,4},{0,0},{1,4},{1,0}},0x30,_T("NEGX.z  d[!Areg,Dreg]"), 0, 1, 3, 1},
/* MVSR2.W  */
{0x40C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,1,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MVSR2.W d[Dreg]"), 2, 0, 4, 0},
/* MVSR2.W  */
{0x40C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,1,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MVSR2.W d[!Areg,Dreg]"), 2, 0, 4, 2},
/* CLR.z  */
{0x4200, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,2},{1,3},{1,2},{1,2}},0x20,_T("CLR.z   d[Dreg]"), 2, 0, 2, 0},
/* CLR.z  */
{0x4200, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,2},{1,3},{1,2},{1,2}},0x20,_T("CLR.z   d[!Areg,Dreg]"), 0, 1, 3, 2},
/* MVSR2.B  */
{0x42C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,1,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MVSR2.B d[Dreg]"), 2, 0, 4, 0},
/* MVSR2.B  */
{0x42C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,1,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MVSR2.B d[!Areg,Dreg]"), 2, 0, 4, 2},
/* NEG.z  */
{0x4400, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x30,_T("NEG.z   d[Dreg]"), 2, 0, 2, 0},
/* NEG.z  */
{0x4400, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x30,_T("NEG.z   d[!Areg,Dreg]"), 0, 1, 3, 1},
/* MV2SR.B  */
{0x44C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x10,_T("MV2SR.B s[Dreg]"), 4, 0, 4, 0},
/* MV2SR.B  */
{0x44C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x10,_T("MV2SR.B s[!Areg,Dreg]"), 0, 0, 4, 1},
/* NOT.z  */
{0x4600, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x30,_T("NOT.z   d[Dreg]"), 2, 0, 2, 0},
/* NOT.z  */
{0x4600, 8,{17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x30,_T("NOT.z   d[!Areg,Dreg]"), 0, 1, 3, 1},
/* MV2SR.W  */
{0x46C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MV2SR.W s[!Areg]"), 0, 0, 8, 1},
/* LINK.L  */
{0x4808, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,2,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x31,_T("LINK.L  Ar,#2"), 2, 0, 6, 0},
/* NBCD.B  */
{0x4800, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{0,0},{1,5},{0,0},{1,5},{1,0}},0x30,_T("NBCD.B  d[!Areg]"), 0, 0, 6, 0},
/* BKPT  */
{0x4848, 3,{ 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,1,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("BKPT    #k"), 0, 0, 0, 0},
/* SWAP.W  */
{0x4840, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x30,_T("SWAP.W  s[Dreg]"), 4, 0, 4, 0},
/* PEA.L  */
{0x4840, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PEA.L   s[!Dreg,Areg,Aipi,Apdi,Immd]"), 0, 2, 4, 2},
/* EXT.W  */
{0x4880, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x30,_T("EXT.W   d[Dreg]"), 4, 0, 4, 0},
/* MVMLE.W  */
{0x4880, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("MVMLE.W #1,d[!Dreg,Areg,Aipi]"), 0, 0, 0, 0},
/* EXT.L  */
{0x48C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x30,_T("EXT.L   d[Dreg]"), 4, 0, 4, 0},
/* MVMLE.L  */
{0x48C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("MVMLE.L #1,d[!Dreg,Areg,Aipi]"), 0, 0, 0, 0},
/* EXT.B  */
{0x49C0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x30,_T("EXT.B   d[Dreg]"), 4, 0, 4, 0},
/* TST.z  */
{0x4A00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x10,_T("TST.z   s[Dreg]"), 0, 0, 2, 0},
/* TST.z  */
{0x4A00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x10,_T("TST.z   s[!Areg,Dreg,PC16,PC8r,Immd]"), 0, 0, 2, 1},
/* TST.z  */
{0x4A00, 8,{17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,2,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x10,_T("TST.z   s[Areg,PC16,PC8r,Immd]"), 0, 0, 2, 1},
/* TAS.B  */
{0x4AC0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x30,_T("TAS.B   d[Dreg]"), 0, 0, 2, 0},
/* TAS.B  */
{0x4AC0, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x30,_T("TAS.B   d[!Areg,Dreg]"), 0, 0, 2, 1},
/* ILLEGAL  */
{0x4AFC, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x00,_T("ILLEGAL"), 0, 0, 0, 0},
/* MULL.L  */
{0x4C00, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x13,_T("MULL.L  #1,s[!Areg]"), 2, 0,30, 3},
/* DIVL.L  */
{0x4C40, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("DIVL.L  #1,s[!Areg]"), 0, 0,50, 3},
/* MVMEL.W  */
{0x4C80, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x01,_T("MVMEL.W #1,s[!Dreg,Areg,Apdi,Immd]"), 0, 0, 0, 0},
/* MVMEL.L  */
{0x4CC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x01,_T("MVMEL.L #1,s[!Dreg,Areg,Apdi,Immd]"), 0, 0, 0, 0},
/* TRAP  */
{0x4E40, 4,{ 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF0,0,0,0,{{0,1},{0,1},{0,1},{0,1},{0,1}},0x10,_T("TRAP    #J"), 0, 0, 0, 0},
/* LINK.W  */
{0x4E50, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x31,_T("LINK.W  Ar,#1"), 0, 0, 4, 0},
/* UNLK.L  */
{0x4E58, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x30,_T("UNLK.L  Ar"), 0, 0, 5, 0},
/* MVR2USP.L  */
{0x4E60, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,0,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x10,_T("MVR2USP.L Ar"), 4, 0, 4, 0},
/* MVUSP2R.L  */
{0x4E68, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,0,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x20,_T("MVUSP2R.L Ar"), 4, 0, 4, 0},
/* RESET  */
{0x4E70, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("RESET"), 0, 0,518, 0},
/* NOP  */
{0x4E71, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("NOP"), 0, 0, 2, 0},
/* STOP  */
{0x4E72, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,2,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x10,_T("STOP    #1"), 0, 0, 8, 0},
/* RTE  */
{0x4E73, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,2,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x00,_T("RTE"), 1, 9,18, 0},
/* RTD  */
{0x4E74, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,1,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("RTD     #1"), 2, 0,10, 0},
/* RTS  */
{0x4E75, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("RTS"), 1, 0, 9, 0},
/* TRAPV  */
{0x4E76, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{0,1},{0,1},{0,1},{0,1},{0,1}},0x00,_T("TRAPV"), 0, 0, 0, 0},
/* RTR  */
{0x4E77, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x00,_T("RTR"), 1, 0,12, 0},
/* MOVEC2  */
{0x4E7A, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,1,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MOVEC2  #1"), 6, 0, 6, 0},
/* MOVE2C  */
{0x4E7B, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,1,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("MOVE2C  #1"), 6, 0, 6, 0},
/* JSR.L  */
{0x4E80, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{4,6},{4,6},{4,6},{4,6},{4,6}},0x80,_T("JSR.L   s[!Dreg,Areg,Aipi,Apdi,Immd]"), 0, 0, 4, 5},
/* CHK.L  */
{0x4100, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("CHK.L   s[!Areg],Dr"), 0, 0, 0, 0},
/* CHK.W  */
{0x4180, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("CHK.W   s[!Areg],Dr"), 0, 0, 0, 0},
/* JMP.L  */
{0x4EC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,0,0,0,{{4,6},{4,6},{4,6},{4,6},{4,6}},0x80,_T("JMP.L   s[!Dreg,Areg,Aipi,Apdi,Immd]"), 4, 0, 4, 5},
/* LEA.L  */
{0x41C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("LEA.L   s[!Dreg,Areg,Aipi,Apdi,Immd],Ar"), 2, 0, 2, 2},
/* ADDA.W  */
{0x5040, 9,{ 7, 7, 7,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("ADDA.W  #j,d[Areg]"), 2, 0, 2, 0},
/* ADDA.L  */
{0x5080, 9,{ 7, 7, 7,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("ADDA.L  #j,d[Areg]"), 2, 0, 2, 0},
/* ADD.z  */
{0x5000,11,{ 7, 7, 7,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   #j,d[Dreg]"), 2, 0, 2, 0},
/* ADD.z  */
{0x5000,11,{ 7, 7, 7,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   #j,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* SUBA.W  */
{0x5140, 9,{ 7, 7, 7,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("SUBA.W  #j,d[Areg]"), 2, 0, 2, 0},
/* SUBA.L  */
{0x5180, 9,{ 7, 7, 7,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("SUBA.L  #j,d[Areg]"), 2, 0, 2, 0},
/* SUB.z  */
{0x5100,11,{ 7, 7, 7,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   #j,d[Dreg]"), 2, 0, 2, 0},
/* SUB.z  */
{0x5100,11,{ 7, 7, 7,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   #j,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* DBcc.W  */
{0x50C8, 7,{ 2, 2, 2, 2,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xF0F8,0,0,0,{{1,1},{2,1},{2,1},{2,1},{2,1}},0x31,_T("DBcc.W  Dr,#1"),-1, 0, 0, 0},
/* Scc.B  */
{0x50C0,10,{ 2, 2, 2, 2,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0},0xF0C0,0,0,0,{{1,1},{2,1},{2,1},{2,1},{2,1}},0x20,_T("Scc.B   d[Dreg]"), 0, 0, 2, 0},
/* Scc.B  */
{0x50C0,10,{ 2, 2, 2, 2,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0},0xF0C0,0,0,0,{{1,1},{2,1},{2,1},{2,1},{2,1}},0x20,_T("Scc.B   d[!Areg,Dreg]"), 0, 0, 2, 2},
/* TRAPcc  */
{0x50FA, 4,{ 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xF0FF,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("TRAPcc  #1"), 0, 0, 0, 0},
/* TRAPcc  */
{0x50FB, 4,{ 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xF0FF,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("TRAPcc  #2"), 0, 0, 0, 0},
/* TRAPcc  */
{0x50FC, 4,{ 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xF0FF,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x00,_T("TRAPcc"), 0, 0, 0, 0},
/* BSR.W  */
{0x6100, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{4,6},{4,6},{4,6},{4,6},{4,6}},0x40,_T("BSR.W   #1"), 2, 0, 6, 0},
/* BSR.B  */
{0x6100, 8,{ 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0},0xFF00,0,0,0,{{4,6},{4,6},{4,6},{4,6},{4,6}},0x40,_T("BSR.B   #i"), 2, 0, 6, 0},
/* BSR.L  */
{0x61FF, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,0,0,0,{{4,6},{4,6},{4,6},{4,6},{4,6}},0x40,_T("BSR.L   #2"), 2, 0, 6, 0},
/* Bcc.W  */
{0x6000, 4,{ 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xF0FF,0,0,0,{{1,1},{2,1},{2,1},{2,1},{2,1}},0x40,_T("Bcc.W   #1"),-1, 0, 0, 0},
/* Bcc.B  */
{0x6000,12,{ 3, 3, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0},0xF000,0,0,0,{{1,1},{2,1},{2,1},{2,1},{2,1}},0x40,_T("Bcc.B   #i"),-1, 0, 0, 0},
/* Bcc.L  */
{0x60FF, 4,{ 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xF0FF,0,0,0,{{1,1},{2,1},{2,1},{2,1},{2,1}},0x40,_T("Bcc.L   #2"),-1, 0, 0, 0},
/* MOVE.L  */
{0x7000,11,{15,15,15, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x12,_T("MOVE.L  #i,Dr"), 0, 0, 0, 0},
/* OR.z  */
{0x8000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("OR.z    s[Dreg],Dr"), 2, 0, 2, 0},
/* OR.z  */
{0x8000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("OR.z    s[!Areg,Dreg],Dr"), 0, 0, 2, 1},
/* DIVU.W  */
{0x80C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("DIVU.W  s[Dreg],Dr"), 2, 0,54, 0},
/* DIVU.W  */
{0x80C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("DIVU.W  s[!Areg,Dreg],Dr"), 0, 0,54, 1},
/* SBCD.B  */
{0x8100, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{0,0},{1,4},{0,0},{1,4},{1,0}},0x13,_T("SBCD.B  d[Dreg],Dr"), 0, 0, 4, 0},
/* SBCD.B  */
{0x8100, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{0,0},{1,4},{0,0},{1,4},{1,0}},0x13,_T("SBCD.B  d[Areg-Apdi],Arp"), 2, 1,13, 0},
/* OR.z  */
{0x8100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("OR.z    Dr,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* PACK  */
{0x8140, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x12,_T("PACK    d[Dreg],Dr"), 6, 0, 6, 0},
/* PACK  */
{0x8140, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x12,_T("PACK    d[Areg-Apdi],Arp"), 2, 1,11, 0},
/* UNPK  */
{0x8180, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x12,_T("UNPK    d[Dreg],Dr"), 8, 0, 8, 0},
/* UNPK  */
{0x8180, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x12,_T("UNPK    d[Areg-Apdi],Arp"), 2, 1,11, 0},
/* DIVS.W  */
{0x81C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("DIVS.W  s[Dreg],Dr"), 2, 0,54, 0},
/* DIVS.W  */
{0x81C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("DIVS.W  s[!Areg,Dreg],Dr"), 0, 0,54, 1},
/* SUB.z  */
{0x9000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   s[Areg,Dreg],Dr"), 2, 0, 2, 0},
/* SUB.z  */
{0x9000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   s[!Areg,Dreg],Dr"), 0, 0, 2, 1},
/* SUBA.W  */
{0x90C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("SUBA.W  s[Areg,Dreg],Ar"), 4, 0, 4, 0},
/* SUBA.W  */
{0x90C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("SUBA.W  s[!Areg,Dreg],Ar"), 0, 0, 4, 1},
/* SUBX.z  */
{0x9100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{0,0},{1,0},{0,0},{1,0},{1,0}},0x13,_T("SUBX.z  d[Dreg],Dr"), 2, 0, 2, 0},
/* SUBX.z  */
{0x9100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{0,0},{1,0},{0,0},{1,0},{1,0}},0x13,_T("SUBX.z  d[Areg-Apdi],Arp"), 2, 1, 9, 0},
/* SUB.z  */
{0x9100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("SUB.z   Dr,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* SUBA.L  */
{0x91C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("SUBA.L  s[Areg,Dreg],Ar"), 2, 0, 2, 0},
/* SUBA.L  */
{0x91C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("SUBA.L  s[!Areg,Dreg],Ar"), 0, 0, 2, 1},
/* CMP.z  */
{0xB000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMP.z   s[Areg,Dreg],Dr"), 2, 0, 2, 0},
/* CMP.z  */
{0xB000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMP.z   s[!Areg,Dreg],Dr"), 0, 0, 2, 1},
/* CMPA.W  */
{0xB0C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMPA.W  s[Areg,Dreg],Ar"), 4, 0, 4, 0},
/* CMPA.W  */
{0xB0C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMPA.W  s[!Areg,Dreg],Ar"), 0, 0, 4, 1},
/* CMPA.L  */
{0xB1C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMPA.L  s[Areg,Dreg],Ar"), 4, 0, 4, 0},
/* CMPA.L  */
{0xB1C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMPA.L  s[!Areg,Dreg],Ar"), 0, 0, 4, 1},
/* CMPM.z  */
{0xB100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,0},{1,0}},0x11,_T("CMPM.z  d[Areg-Aipi],ArP"), 0, 0, 8, 0},
/* EOR.z  */
{0xB100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("EOR.z   Dr,d[Dreg]"), 2, 0, 2, 0},
/* EOR.z  */
{0xB100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("EOR.z   Dr,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* AND.z  */
{0xC000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("AND.z   s[Dreg],Dr"), 2, 0, 2, 1},
/* AND.z  */
{0xC000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("AND.z   s[!Areg,Dreg],Dr"), 0, 1, 3, 1},
/* MULU.W  */
{0xC0C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("MULU.W  s[!Areg],Dr"), 2, 0,25, 1},
/* ABCD.B  */
{0xC100, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{0,0},{1,4},{0,0},{1,4},{1,0}},0x13,_T("ABCD.B  d[Dreg],Dr"), 0, 0, 4, 0},
/* ABCD.B  */
{0xC100, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{0,0},{1,4},{0,0},{1,4},{1,0}},0x13,_T("ABCD.B  d[Areg-Apdi],Arp"), 2, 1,13, 0},
/* AND.z  */
{0xC100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("AND.z   Dr,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* EXG.L  */
{0xC140, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x33,_T("EXG.L   Dr,d[Dreg]"), 4, 0, 4, 0},
/* EXG.L  */
{0xC140, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x33,_T("EXG.L   Ar,d[Areg]"), 4, 0, 4, 0},
/* EXG.L  */
{0xC180, 9,{15,15,15,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x33,_T("EXG.L   Dr,d[Areg]"), 4, 0, 4, 0},
/* MULS.W  */
{0xC1C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,2}},0x13,_T("MULS.W  s[!Areg],Dr"), 2, 0,25, 1},
/* ADD.z  */
{0xD000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   s[Areg,Dreg],Dr"), 2, 0, 2, 0},
/* ADD.z  */
{0xD000,11,{15,15,15,17,17,11,11,11,12,12,12, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   s[!Areg,Dreg],Dr"), 0, 0, 2, 1},
/* ADDA.W  */
{0xD0C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("ADDA.W  s[Areg,Dreg],Ar"), 0, 0, 4, 0},
/* ADDA.W  */
{0xD0C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("ADDA.W  s[!Areg,Dreg],Ar"), 4, 0, 4, 1},
/* ADDX.z  */
{0xD100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{0,0},{1,0},{0,0},{1,0},{1,0}},0x13,_T("ADDX.z  d[Dreg],Dr"), 2, 0, 2, 0},
/* ADDX.z  */
{0xD100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{0,0},{1,0},{0,0},{1,0},{1,0}},0x13,_T("ADDX.z  d[Areg-Apdi],Arp"), 2, 1, 9, 0},
/* ADD.z  */
{0xD100,11,{15,15,15,17,17,13,13,13,14,14,14, 0, 0, 0, 0, 0},0xF100,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ADD.z   Dr,d[!Areg,Dreg]"), 0, 1, 3, 1},
/* ADDA.L  */
{0xD1C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("ADDA.L  s[Areg,Dreg],Ar"), 2, 0, 2, 0},
/* ADDA.L  */
{0xD1C0, 9,{15,15,15,11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0},0xF1C0,0,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x13,_T("ADDA.L  s[!Areg,Dreg],Ar"), 0, 0, 2, 1},
/* ASf.z  */
{0xE000, 9,{ 7, 7, 7, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ASf.z   #j,DR"), 2, 0, 6, 0},
/* LSf.z  */
{0xE008, 9,{ 7, 7, 7, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{1,0},{1,0},{1,0},{1,2},{1,0}},0x13,_T("LSf.z   #j,DR"), 4, 0, 4, 0},
/* ROXf.z  */
{0xE010, 9,{ 7, 7, 7, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{0,0},{1,0},{1,0},{1,2},{1,0}},0x13,_T("ROXf.z  #j,DR"),10, 0,12, 0},
/* ROf.z  */
{0xE018, 9,{ 7, 7, 7, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,0}},0x13,_T("ROf.z   #j,DR"), 4, 0, 6, 0},
/* ASf.z  */
{0xE020, 9,{15,15,15, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{0,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ASf.z   Dr,DR"), 4, 0, 6, 0},
/* LSf.z  */
{0xE028, 9,{15,15,15, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{0,0},{1,0},{1,0},{1,2},{1,0}},0x13,_T("LSf.z   Dr,DR"), 6, 0, 6, 0},
/* ROXf.z  */
{0xE030, 9,{15,15,15, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{0,0},{1,0},{1,0},{1,2},{1,0}},0x13,_T("ROXf.z  Dr,DR"),10, 0,12, 0},
/* ROf.z  */
{0xE038, 9,{15,15,15, 4,17,17,16,16,16, 0, 0, 0, 0, 0, 0, 0},0xF038,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,0}},0x13,_T("ROf.z   Dr,DR"), 6, 0, 8, 0},
/* ASfW.W  */
{0xE0C0, 7,{ 4,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFEC0,0,0,0,{{1,0},{1,0},{1,0},{1,0},{1,0}},0x13,_T("ASfW.W  d[!Dreg,Areg]"), 0, 0, 4, 1},
/* LSfW.W  */
{0xE2C0, 7,{ 4,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFEC0,0,0,0,{{1,0},{1,0},{1,0},{1,2},{1,0}},0x13,_T("LSfW.W  d[!Dreg,Areg]"), 0, 0, 4, 1},
/* ROXfW.W  */
{0xE4C0, 7,{ 4,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFEC0,0,0,0,{{0,0},{1,0},{1,0},{1,2},{1,0}},0x13,_T("ROXfW.W d[!Dreg,Areg]"), 0, 0, 4, 1},
/* ROfW.W  */
{0xE6C0, 7,{ 4,13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFEC0,0,0,0,{{1,1},{1,0},{1,0},{1,2},{1,0}},0x13,_T("ROfW.W  d[!Dreg,Areg]"), 0, 0, 6, 1},
/* BFTST  */
{0xE8C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("BFTST   #1,s[!Areg,Apdi,Aipi,Immd]"), 0, 0, 0, 0},
/* BFEXTU  */
{0xE9C0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("BFEXTU  #1,s[!Areg,Apdi,Aipi,Immd]"), 0, 0, 0, 0},
/* BFCHG  */
{0xEAC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("BFCHG   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* BFEXTS  */
{0xEBC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("BFEXTS  #1,s[!Areg,Apdi,Aipi,Immd]"), 0, 0, 0, 0},
/* BFCLR  */
{0xECC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("BFCLR   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* BFFFO  */
{0xEDC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("BFFFO   #1,s[!Areg,Apdi,Aipi,Immd]"), 0, 0, 0, 0},
/* BFSET  */
{0xEEC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("BFSET   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* BFINS  */
{0xEFC0, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x13,_T("BFINS   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* FPP  */
{0xF200, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("FPP      #1,s"), 0, 0, 0, 0},
/* FDBcc  */
{0xF240, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("FDBcc    #1,s[Areg-Dreg]"), 0, 0, 0, 0},
/* FScc  */
{0xF240, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("FScc     #1,s[!Areg,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* FTRAPcc  */
{0xF27A, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("FTRAPcc  #1"), 0, 0, 0, 0},
/* FTRAPcc  */
{0xF27B, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("FTRAPcc  #2"), 0, 0, 0, 0},
/* FTRAPcc  */
{0xF27C, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x00,_T("FTRAPcc"), 0, 0, 0, 0},
/* FBcc  */
{0xF280, 6,{10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("FBcc     #K,#1"), 0, 0, 0, 0},
/* FBcc  */
{0xF2C0, 6,{10,10,10,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("FBcc     #K,#2"), 0, 0, 0, 0},
/* FSAVE  */
{0xF300, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x20,_T("FSAVE    s[!Dreg,Areg,Aipi,Immd,PC8r,PC16]"), 0, 0, 0, 0},
/* FRESTORE  */
{0xF340, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,2,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("FRESTORE s[!Dreg,Areg,Apdi,Immd]"), 0, 0, 0, 0},
/* MMUOP030  */
{0xF000, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,3,4,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x11,_T("MMUOP030 s[Dreg,Areg,Apdi,Aipi,Aind,Ad16,Ad8r,absl,absw],#1"), 0, 0, 0, 0},
/* CINVL  */
{0xF408, 5,{18,18,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFF38,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("CINVL    #p,Ar"), 0, 0, 0, 0},
/* CINVP  */
{0xF410, 5,{18,18,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFF38,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("CINVP    #p,Ar"), 0, 0, 0, 0},
/* CINVA  */
{0xF418, 5,{18,18,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFF38,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("CINVA    #p"), 0, 0, 0, 0},
/* CPUSHL  */
{0xF428, 5,{18,18,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFF38,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("CPUSHL   #p,Ar"), 0, 0, 0, 0},
/* CPUSHP  */
{0xF430, 5,{18,18,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFF38,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x02,_T("CPUSHP   #p,Ar"), 0, 0, 0, 0},
/* CPUSHA  */
{0xF438, 5,{18,18,15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFF38,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("CPUSHA   #p"), 0, 0, 0, 0},
/* PFLUSHN  */
{0xF500, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PFLUSHN  Ara"), 0, 0, 0, 0},
/* PFLUSH  */
{0xF508, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PFLUSH   Ara"), 0, 0, 0, 0},
/* PFLUSHAN  */
{0xF510, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PFLUSHAN Ara"), 0, 0, 0, 0},
/* PFLUSHA  */
{0xF518, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PFLUSHA  Ara"), 0, 0, 0, 0},
/* PTESTW  */
{0xF548, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,5,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PTESTW   Ara"), 0, 0, 0, 0},
/* PTESTR  */
{0xF568, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,5,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PTESTR   Ara"), 0, 0, 0, 0},
/* MOVE16  */
{0xF620, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,4,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVE16   ArP,AxP"), 0, 0, 0, 0},
/* MOVE16  */
{0xF600, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,4,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVE16   s[Dreg-Aipi],L"), 0, 0, 0, 0},
/* MOVE16  */
{0xF600, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,4,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVE16   L,d[Areg-Aipi]"), 0, 0, 0, 0},
/* MOVE16  */
{0xF600, 6,{11,11,11,12,12,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,4,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVE16   s[Aind],L"), 0, 0, 0, 0},
/* MOVE16  */
{0xF600, 6,{13,13,13,14,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFC0,4,0,0,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x12,_T("MOVE16   L,d[Aipi-Aind]"), 0, 0, 0, 0},
/* LPSTOP  */
{0xF800, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,5,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x10,_T("LPSTOP   #1"), 0, 0, 0, 0},
/* PLPAW  */
{0xF588, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,5,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PLPAW    Ara"), 0, 0, 0, 0},
/* PLPAR  */
{0xF5C8, 3,{15,15,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFF8,5,0,2,{{1,1},{1,1},{1,1},{1,1},{1,1}},0x00,_T("PLPAR    Ara"), 0, 0, 0, 0},
/* HALT  */
{0x4AC8, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,5,0,2,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x00,_T("HALT"), 0, 0, 0, 0},
/* PULSE  */
{0x4ACC, 0,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},0xFFFF,5,0,0,{{3,5},{3,5},{3,5},{3,5},{3,5}},0x00,_T("PULSE"), 0, 0, 0, 0}};
int n_defs68k = 232;