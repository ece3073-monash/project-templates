// *********************************
//
// VGA Controller Module
// Made for students to use during the ECE3073 Project
// 
// Author(s): ECE3073 staff
// Last Edited: 25/02/2024
//
// Copyright © 2025 Copyright, Monash University
//
// *********************************


module vga_controller (
	input [3:0] VGA_DATA,
	input VGA_CLK,
	
	output [18:0] VGA_ADDR, // This address may vary, having it longer that what you use wont be an issue
	output [3:0] VGA_R,
	output [3:0] VGA_G,
	output [3:0] VGA_B,
	output VGA_HS,
	output VGA_VS
);

	// VGA Spec Parameters
	parameter H_SYNC = 96;
	parameter H_BACK = 48;
	parameter H_FRONT = 16;
	parameter H_CYCLE = 800;
	
	parameter V_SYNC = 2;
	parameter V_BACK = 33;
	parameter V_FRONT = 10;
	parameter V_CYCLE = 525;
	
	reg [18:0] H_ADDR, V_ADDR;

	always @(posedge VGA_CLK) // Horizontal Counter
		begin
			if (H_ADDR < H_CYCLE)
				H_ADDR <= H_ADDR + 1;
			else
				H_ADDR <= 0;
		end
		
	always @(posedge VGA_CLK) // Vertical Counter
		begin
			if (H_ADDR == H_CYCLE)
				begin
					if (V_ADDR < V_CYCLE)
						V_ADDR <= V_ADDR + 1;
					else
						V_ADDR <= 0;
				end
		end
		
	assign VGA_HS = (H_ADDR < H_SYNC) ? 1 : 0; 
	assign VGA_VS = (V_ADDR < V_SYNC) ? 1 : 0; 

	assign pixelValid = (H_ADDR >= 144 && H_ADDR < 784) && (V_ADDR >= 35 && V_ADDR < 515);
	assign VGA_R = pixelValid ? VGA_DATA : 4'd0;
	assign VGA_G = pixelValid ? VGA_DATA : 4'd0;
	assign VGA_B = pixelValid ? VGA_DATA : 4'd0;
	
	wire [18:0] H_MEM_ADDR, V_MEM_ADDR;	
	
	assign H_MEM_ADDR = H_ADDR - 144;
	assign V_MEM_ADDR = V_ADDR - 35;
	
	// Scale the addresses to 320X240 instead of 640x480. 
	assign VGA_ADDR = ((H_MEM_ADDR>>1) + ((V_MEM_ADDR>>1) * 320));
					
	
endmodule
