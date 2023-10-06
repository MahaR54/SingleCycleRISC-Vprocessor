// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


void VALU::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VALU::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clock));
        tracep->chgBit(oldp+1,(vlTOPp->reset));
        tracep->chgIData(oldp+2,(vlTOPp->io_in_A),32);
        tracep->chgIData(oldp+3,(vlTOPp->io_in_B),32);
        tracep->chgCData(oldp+4,(vlTOPp->io_alu_Op),4);
        tracep->chgIData(oldp+5,(vlTOPp->io_out),32);
    }
}

void VALU::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
