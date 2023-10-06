// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VALU::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VALU::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VALU::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VALU::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clock", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"io_in_A", false,-1, 31,0);
        tracep->declBus(c+4,"io_in_B", false,-1, 31,0);
        tracep->declBus(c+5,"io_alu_Op", false,-1, 3,0);
        tracep->declBus(c+6,"io_out", false,-1, 31,0);
        tracep->declBit(c+1,"ALU clock", false,-1);
        tracep->declBit(c+2,"ALU reset", false,-1);
        tracep->declBus(c+3,"ALU io_in_A", false,-1, 31,0);
        tracep->declBus(c+4,"ALU io_in_B", false,-1, 31,0);
        tracep->declBus(c+5,"ALU io_alu_Op", false,-1, 3,0);
        tracep->declBus(c+6,"ALU io_out", false,-1, 31,0);
    }
}

void VALU::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VALU::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VALU::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clock));
        tracep->fullBit(oldp+2,(vlTOPp->reset));
        tracep->fullIData(oldp+3,(vlTOPp->io_in_A),32);
        tracep->fullIData(oldp+4,(vlTOPp->io_in_B),32);
        tracep->fullCData(oldp+5,(vlTOPp->io_alu_Op),4);
        tracep->fullIData(oldp+6,(vlTOPp->io_out),32);
    }
}
