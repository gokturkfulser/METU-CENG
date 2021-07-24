module ROM (
input [2:0] addr, 
output reg [7:0] dataOut);

reg [7:0] rom[7:0];

initial begin
	rom[0]=8'b00000000;
	rom[1]=8'b01010101;
	rom[2]=8'b10101010;
	rom[3]=8'b00110011;
	rom[4]=8'b11001100;
	rom[5]=8'b00001111;
	rom[6]=8'b11110000;
	rom[7]=8'b11111111;
end

always @(addr)begin
	dataOut=rom[addr];
end
	
endmodule


module XOR_RAM (
input mode, 
input [2:0] addr, 
input [7:0] dataIn, 
input [7:0] mask, 
input CLK, 
output reg [7:0] dataOut);

reg [7:0] ram[7:0];

initial begin
	ram[0]=8'b00000000;
	ram[1]=8'b00000000;
	ram[2]=8'b00000000;
	ram[3]=8'b00000000;
	ram[4]=8'b00000000;
	ram[5]=8'b00000000;
	ram[6]=8'b00000000;
	ram[7]=8'b00000000;
	dataOut=8'b00000000;
end

always @(addr)begin
	if(mode==1)
		dataOut=ram[addr];
end

always @(posedge CLK)begin
	if(mode==0)
		ram[addr]<=dataIn^mask;
end

endmodule


module EncodedMemory (
input mode, 
input [2:0] index, 
input [7:0] number, 
input CLK, 
output [7:0] result);
	
	// DO NOT EDIT THIS MODULE
	
	wire [7:0] mask;
	
	ROM R(index, mask);
	XOR_RAM XR(mode, index, number, mask, CLK, result);

endmodule