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
	wire B,K;
	always@(posedge clk)
	begin 
	if(Q==0)
		Q = ~B
	else
		Q = K
	end
endmodule


/*module ic232(
	input A0, 
	input A1, 
	input A2, 
	input clk,
	output Q0,
	output Q1,
	output Z
	);
   
	// write your code here
	
endmodule*/