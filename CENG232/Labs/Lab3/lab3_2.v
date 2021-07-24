`timescale 1ns / 1ps
module QueueCounter(
	input [7:0] llmt,
	input [7:0] ulmt,
	input en,
	input mode, // 1:delete, 0:insert
	input clk,
	output reg [7:0] head,
	output reg [7:0] tail,
	output reg empty,
	output reg full);
	
	//you may write your code here

	initial
	begin
		head = llmt;
		tail = llmt;
	end

	always @(posedge clk)begin
		if(en==1)begin
			case(mode)
			
				1'b0:begin
					if(full!=1)begin
						if(tail!=ulmt)begin
							tail<=tail+1;
							if(tail+1==head)begin
								full<=1;
							end
						end else begin
							tail<=llmt;
							if(llmt==head)begin
								full<=1;
							end
						end
					end
				end
				
				1'b1:begin
					if(empty!=1)begin
						if(head!=ulmt)begin
							head<=head+1;
							if(head+1==tail)begin
								empty<=1;
							end
						end else begin
							head<=llmt;
							if(llmt==tail)begin
								empty<=1;
							end
						end
					end
				end
				
			endcase
		end
	end


endmodule


module Numerator(
	input clinic, 
	input mode, 
	input en, 
	input clk,
	output [7:0] ann,
	output [7:0] print);

	//write your code here

endmodule
