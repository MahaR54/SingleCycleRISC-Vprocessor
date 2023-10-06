module ALU(
  input         clock,
  input         reset,
  input  [31:0] io_in_A,
  input  [31:0] io_in_B,
  input  [3:0]  io_alu_Op,
  output [31:0] io_out
);
  wire [31:0] _io_out_T_1 = $signed(io_in_A) & $signed(io_in_B); // @[ALU.scala 32:27]
  wire [31:0] _GEN_0 = io_alu_Op == 4'h0 ? $signed(_io_out_T_1) : $signed(32'sh0); // @[ALU.scala 31:36 ALU.scala 32:16 ALU.scala 29:12]
  wire [31:0] _io_out_T_3 = $signed(io_in_A) | $signed(io_in_B); // @[ALU.scala 35:27]
  wire [31:0] _GEN_1 = io_alu_Op == 4'h6 ? $signed(_io_out_T_3) : $signed(_GEN_0); // @[ALU.scala 34:34 ALU.scala 35:16]
  wire [31:0] _io_out_T_6 = $signed(io_in_A) + $signed(io_in_B); // @[ALU.scala 38:27]
  wire [31:0] _GEN_2 = io_alu_Op == 4'h7 ? $signed(_io_out_T_6) : $signed(_GEN_1); // @[ALU.scala 37:36 ALU.scala 38:16]
  wire [31:0] _io_out_T_9 = $signed(io_in_A) - $signed(io_in_B); // @[ALU.scala 41:27]
  wire [31:0] _GEN_3 = io_alu_Op == 4'h8 ? $signed(_io_out_T_9) : $signed(_GEN_2); // @[ALU.scala 40:35 ALU.scala 41:16]
  wire [31:0] _io_out_T_11 = $signed(io_in_A) ^ $signed(io_in_B); // @[ALU.scala 44:27]
  wire [31:0] _GEN_4 = io_alu_Op == 4'h4 ? $signed(_io_out_T_11) : $signed(_GEN_3); // @[ALU.scala 43:34 ALU.scala 44:16]
  wire [62:0] _GEN_10 = {{31{io_in_A[31]}},io_in_A}; // @[ALU.scala 47:27]
  wire [62:0] _io_out_T_13 = $signed(_GEN_10) << io_in_B[4:0]; // @[ALU.scala 47:27]
  wire [62:0] _GEN_5 = io_alu_Op == 4'h1 ? $signed(_io_out_T_13) : $signed({{31{_GEN_4[31]}},_GEN_4}); // @[ALU.scala 46:34 ALU.scala 47:16]
  wire [62:0] _GEN_6 = io_alu_Op == 4'h5 ? $signed(_io_out_T_13) : $signed(_GEN_5); // @[ALU.scala 49:34 ALU.scala 50:15]
  wire [31:0] _io_out_T_17 = $signed(io_in_A) >>> io_in_B[4:0]; // @[ALU.scala 53:25]
  wire [62:0] _GEN_7 = io_alu_Op == 4'hd ? $signed({{31{_io_out_T_17[31]}},_io_out_T_17}) : $signed(_GEN_6); // @[ALU.scala 52:34 ALU.scala 53:14]
  wire  _io_out_T_19 = $signed(io_in_A) < $signed(io_in_B); // @[ALU.scala 56:37]
  wire [62:0] _GEN_8 = io_alu_Op == 4'h2 ? $signed({63{_io_out_T_19}}) : $signed(_GEN_7); // @[ALU.scala 55:34 ALU.scala 56:14]
  wire [62:0] _GEN_9 = io_alu_Op == 4'h3 ? $signed({63{_io_out_T_19}}) : $signed(_GEN_8); // @[ALU.scala 58:36 ALU.scala 59:14]
  assign io_out = _GEN_9[31:0];
endmodule
