// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"
#include "VALU__Syms.h"

//==========

void VALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval\n"); );
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VALU::_combo__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_combo__TOP__1\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ALU__DOT___io_out_T_13 = (0x7fffffffffffffffULL 
                                      & ((((QData)((IData)(
                                                           (0x7fffffffU 
                                                            & (- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->io_in_A 
                                                                             >> 0x1fU))))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlTOPp->io_in_A))) 
                                         << (0x1fU 
                                             & vlTOPp->io_in_B)));
    vlTOPp->ALU__DOT___io_out_T_17 = VL_SHIFTRS_III(32,32,5, vlTOPp->io_in_A, 
                                                    (0x1fU 
                                                     & vlTOPp->io_in_B));
    vlTOPp->ALU__DOT___io_out_T_19 = VL_LTS_III(1,32,32, vlTOPp->io_in_A, vlTOPp->io_in_B);
    vlTOPp->ALU__DOT___GEN_4 = ((4U == (IData)(vlTOPp->io_alu_Op))
                                 ? (vlTOPp->io_in_A 
                                    ^ vlTOPp->io_in_B)
                                 : ((8U == (IData)(vlTOPp->io_alu_Op))
                                     ? (vlTOPp->io_in_A 
                                        - vlTOPp->io_in_B)
                                     : ((7U == (IData)(vlTOPp->io_alu_Op))
                                         ? (vlTOPp->io_in_A 
                                            + vlTOPp->io_in_B)
                                         : ((6U == (IData)(vlTOPp->io_alu_Op))
                                             ? (vlTOPp->io_in_A 
                                                | vlTOPp->io_in_B)
                                             : ((0U 
                                                 == (IData)(vlTOPp->io_alu_Op))
                                                 ? 
                                                (vlTOPp->io_in_A 
                                                 & vlTOPp->io_in_B)
                                                 : 0U)))));
    vlTOPp->io_out = (IData)((0x7fffffffffffffffULL 
                              & ((3U == (IData)(vlTOPp->io_alu_Op))
                                  ? (- (QData)((IData)(vlTOPp->ALU__DOT___io_out_T_19)))
                                  : ((2U == (IData)(vlTOPp->io_alu_Op))
                                      ? (- (QData)((IData)(vlTOPp->ALU__DOT___io_out_T_19)))
                                      : ((0xdU == (IData)(vlTOPp->io_alu_Op))
                                          ? (((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & (- (IData)(
                                                                            (1U 
                                                                             & (vlTOPp->ALU__DOT___io_out_T_17 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->ALU__DOT___io_out_T_17)))
                                          : ((5U == (IData)(vlTOPp->io_alu_Op))
                                              ? vlTOPp->ALU__DOT___io_out_T_13
                                              : ((1U 
                                                  == (IData)(vlTOPp->io_alu_Op))
                                                  ? vlTOPp->ALU__DOT___io_out_T_13
                                                  : 
                                                 (((QData)((IData)(
                                                                   (0x7fffffffU 
                                                                    & (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->ALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->ALU__DOT___GEN_4))))))))));
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VALU::_change_request_1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request_1\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_alu_Op & 0xf0U))) {
        Verilated::overWidthError("io_alu_Op");}
}
#endif  // VL_DEBUG
