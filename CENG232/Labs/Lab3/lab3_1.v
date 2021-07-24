`timescale 1ns / 1ps
module kb(
	input K,
	input B,
	input clk,
	output reg Q
	);
    
	initial begin
		Q = 0;
	end
	 
	// write your code here
   always @ (posedge clk)  
      case ({K,B})  
         2'b00 :  Q <= ~Q;  
         2'b01 :  Q <= 0;  
         2'b10 :  Q <= 1;  
         2'b11 :  Q <= Q;  
      endcase  

endmodule


module ic232(
	input A0, 
	input A1, 
	input A2, 
	input clk,
	output Q0,
	output Q1,
	output Z
	);
   
	// write your code here
	wire Ab0;
	wire Ab2;
	wire J1;
	wire J2;
	wire K1;
	wire K2;
	
	not(Ab0,A0);
	not(Ab2,A2);
	nor(J1,A0,A1);
	and(K1,J1,Ab2);
	or(J2,Ab0,A1);
	xor(K2,J2,A2);
	
	kb kb_1(
	.K (K1),
	.B (A1),
	.clk (clk),
	.Q (Q0)
	);
	
	kb kb_2(
	.K (Ab2),
	.B (K2),
	.clk (clk),
	.Q (Q1)
	);
	
	xnor(Z,Q0,Q1);

endmodule
