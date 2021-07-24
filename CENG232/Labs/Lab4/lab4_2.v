module IntersectionSimulator(
	input [2:0] mode, //1xx:display, 000:remA, 001:remB, 010:addA, 011:addB
	input [4:0] plateIn,
	input action,
	input clk,
	output reg  greenForA,
	output reg  greenForB,
	output reg 	rushHourWarning,
	output reg [3:0]  hour,
	output reg [5:0]  minute,	
	output reg [5:0]  second,
	output reg	am_pm, //0:am, 1:pm
	output reg [4:0]  numOfCarsA,
	output reg [4:0]  numOfCarsB,
	output reg [6:0]  remainingTime,
	output reg [4:0]  blackListDisplay
	);
	
	reg [6:0] nextRedDurationA;	
	reg [6:0] nextRedDurationB;
	reg lastgreen; //0 : A  , 1 : B
	
	initial begin
		greenForA=1;
		greenForB=0;
		rushHourWarning=0;
		hour=6;
		minute=0;
		second=0;
		am_pm=0;
		numOfCarsA=0;
		numOfCarsB=0;
		remainingTime=50;
		blackListDisplay=0;
		
		nextRedDurationA=40;
		nextRedDurationB=50;
		lastgreen=0;
	end


	always@(posedge action)
	begin
	
		//...
		
	end


	always @(posedge clk)
	begin
		//time
		if(second!=59)begin
			second<=second+1;
		end
		else if(minute!=59 && second==59)begin
			second<=0;
			minute<=minute+1;
		end 
		else if(hour!=12 && minute==59 && second==59)begin
			second<=0;
			minute<=0;
			hour<=hour+1;
		end	
		else if(hour==12 && minute==59 && second==59)begin
			second<=0;
			minute<=0;
			hour<=0;
			am_pm<=am_pm^1;
		end
		
		//rush hour
		if((am_pm==0 && hour==6 && minute==59 && second==59) | (am_pm==1 && hour==4 && minute==59 && second==59))
			rushHourWarning<=1;
		else if((am_pm==0 && hour==8 && minute==59 && second==59) | (am_pm==1 && hour==6 && minute==59 && second==59))
			rushHourWarning<=0;
			
			
		//lights and remaining time
		if(remainingTime!=1 && remainingTime!=0)begin
			remainingTime<=remainingTime-1;
		end 
		
		else if(remainingTime==1)begin
			if(greenForA==1)begin
				greenForA<=0;
				lastgreen<=0;
			end
			else if(greenForB==1)begin
				greenForB<=0;
				lastgreen<=1;
			end
		end
		
		else if(remainingTime==0)begin
			if(lastgreen==0)begin
				greenForB<=1;
				case(numOfCarsB)
					5'b00000,5'b00001,5'b00010,5'b00011,5'b00100,5'b00101,5'b00110,5'b00111,5'b01000,5'b01001,5'b01010:begin
						if(rushHourWarning==0 && nextRedDurationB!=7'b1010000)
							nextRedDurationB<=nextRedDurationB+5;
						else if(rushHourWarning==1 && nextRedDurationB!=7'b1000110)
							nextRedDurationB<=nextRedDurationB+5;
					end
					5'b01011,5'b01100,5'b01101,5'b01110,5'b01111,5'b10000,5'b10001,5'b10010,5'b10011:begin
						nextRedDurationB<=nextRedDurationB;
					end
					5'b10100,5'b10101,5'b10110,5'b10111,5'b11000,5'b11001,5'b11010,5'b11010,5'b11011,5'b11100,5'b11101,5'b11110,5'b11111:begin
						if(rushHourWarning==0 && nextRedDurationB!=7'b0110010)
							nextRedDurationB<=nextRedDurationB-5;
						else if(rushHourWarning==1 && nextRedDurationB!=7'b0101000)
							nextRedDurationB<=nextRedDurationB-5;
					end
				endcase
				remainingTime<=nextRedDurationA;	
			end 
			
			else if(lastgreen==1)begin
				greenForA<=1;	
				case(numOfCarsA)
					5'b00000,5'b00001,5'b00010,5'b00011,5'b00100,5'b00101,5'b00110,5'b00111,5'b01000,5'b01001,5'b01010:begin
						if(rushHourWarning==0 && nextRedDurationA!=7'b1000110)
							nextRedDurationA<=nextRedDurationA+5;
						else if(rushHourWarning==1 && nextRedDurationA!=7'b0111100)
							nextRedDurationA<=nextRedDurationA+5;
					end
					5'b01011,5'b01100,5'b01101,5'b01110,5'b01111,5'b10000,5'b10001,5'b10010,5'b10011:begin
						nextRedDurationA<=nextRedDurationA;
					end
					5'b10100,5'b10101,5'b10110,5'b10111,5'b11000,5'b11001,5'b11010,5'b11010,5'b11011,5'b11100,5'b11101,5'b11110,5'b11111:begin
						if(rushHourWarning==0 && nextRedDurationA!=7'b0101000)
							nextRedDurationA<=nextRedDurationA-5;
						else if(rushHourWarning==1 && nextRedDurationA!=7'b0011110)
							nextRedDurationA<=nextRedDurationA-5;
					end
				endcase
				remainingTime<=nextRedDurationB;
			end
			
		end 
		
	end


endmodule