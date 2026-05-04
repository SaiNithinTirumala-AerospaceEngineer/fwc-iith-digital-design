/*
 * FWC IITH – FPGA Verilog (VAMAN QuickLogic EOS-S3)
 * GATE Question: Display f = 1000 Hz on LCD via FPGA fabric
 * Platform: VAMAN board (QuickLogic EOS-S3 FPGA) + LCD JHD162A
 * Toolchain: ql_symbiflow + TinyFPGA-Programmer
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 */

module helloworldfpga(output reg LCD_RS,output reg LCD_E,output reg[7:4] DATA);

    wire clk;
    qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
        .Sys_Clk0 (clk),
    ); // 20MHz clock
    
    integer i = 1;
    reg [25:0] count = 0;
    reg [3:0] Datas [1:41];
    
    // Variables for frequency calculation
    integer frequency = 1000; // Hz
    integer period = 1000000 / frequency; // 1 second in microseconds
    
    // Solution text
    reg [7:0] solution[1:17] = {8'h31, 8'h30, 8'h30, 8'h30, // "1000 = 1 sec × f"
                                 8'h20, 8'h3D, 8'h20, 8'h31, 
                                 8'h20, 8'h73, 8'h65, 8'h63, 
                                 8'h20, 8'hD7, 8'h78, 8'h20,
                                 8'h66};
    
    initial begin
        // Initialize data for LCD
        // (This part remains unchanged from the original code)
    end
    
    always @(posedge clk) begin
        // Load solution text after clearing display
        if (i == 11) begin
            LCD_RS <= 1'b1; // Set RS for data
            DATA <= solution[i - 10]; // Load solution data
            LCD_E <= 1'b1;
            if (count == 800) begin // Wait 40us
                LCD_E <= 1'b0;
                count <= 0;
                i <= i + 1;
            end else
                count <= count + 1;
        end else if (i > 11 && i <= 28) begin // Continue loading solution text
            LCD_RS <= 1'b1; // Set RS for data
            DATA <= solution[i - 10]; // Load solution data
            LCD_E <= 1'b1;
            if (count == 800) begin // Wait 40us
                LCD_E <= 1'b0;
                count <= 0;
                i <= i + 1;
            end else
                count <= count + 1;
        end else if (i == 29) begin // Wait for 3ms after displaying solution
            if (count == 60000) begin // Wait 3ms
                count <= 0;
                i <= i + 1;
            end else
                count <= count + 1;
        end else if (i == 30) begin // Clear display after showing solution
            LCD_RS <= 1'b0; // Set RS for instruction
            DATA <= 4'h1; // Clear display instruction
            LCD_E <= 1'b1;
            if (count == 800) begin // Wait 40us
                LCD_E <= 1'b0;
                count <= 0;
                i <= i + 1;
            end else
                count <= count + 1;
        end else if (i > 30 && i <= 41) begin // Continue clearing display
            LCD_RS <= 1'b0; // Set RS for instruction
            DATA <= 4'h1; // Clear display instruction
            LCD_E <= 1'b1;
            if (count == 800) begin // Wait 40us
                LCD_E <= 1'b0;
                count <= 0;
                i <= i + 1;
            end else
                count <= count + 1;
        end else if (i > 41) begin // Reset loop counter
            i <= 1;
        end else begin // Load remaining initialization data for LCD
            // (This part remains unchanged from the original code)
        end
    end

endmodule