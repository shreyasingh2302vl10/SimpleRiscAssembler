# SimpleRisc Assembler

## Overview  
SimpleRisc Assembler is a custom assembler written in C++ that translates assembly code into 32-bit binary machine code. It supports various addressing modes, processes labels, and performs moderate-level error checking to ensure correctness.

## Working Mechanism  
The assembler operates using a two-pass approach:  

- **First Pass:** Stores label addresses.  
- **Second Pass:** Converts each instruction into its binary representation.

## Versions  
We have provided two versions of our project:  


### 1. Normal Version (Main Branch)  
- This version can be executed in any IDE, such as **VS Code**.  
- It includes the following files:  

  - **input.asm** – The assembly source code.  
  - **output.bin** – The assembled binary output.  
  - **assembler.cpp** – The main assembler code.  

### 2.Web-Based Implementation  
We have also incorporated a web-based interface for the assembler, consisting of the following files:  

- **README.md** – Documentation of the project.  
- **assembler.cpp** – The main C++ assembler source code.  
- **assembler.exe** – Compiled executable of the assembler.  
- **index.html** – Front-end for input submission and output display.  
- **input.asm** – Assembly source file.  
- **output.bin** – Generated binary output.  
- **package-lock.json** – Dependency lock file.  
- **package.json** – Node.js package configuration.  
- **server.js** – Backend server to handle file execution and processing.  

## Usage  
- The **normal version** can be run in any C++ environment.  
- The **web-based version** enables users to input assembly code through a browser and receive results dynamically.  

This project provides flexibility for users to assemble code using different interfaces based on their preference.  
## Instruction Set Support  
The assembler supports a variety of instructions, categorized as follows:  

### 1. Arithmetic Operations  
- **ADD** – Addition  
- **SUB** – Subtraction  
- **MUL** – Multiplication  
- **DIV** – Division  
- **MOD** – Modulus  

### 2. Logical Operations  
- **AND** – Bitwise AND  
- **OR** – Bitwise OR  
- **NOT** – Bitwise NOT  
- **CMP** – Compare  

### 3. Data Transfer Instructions  
- **MOV** – Move data  
- **LD** – Load data from memory  
- **ST** – Store data to memory  

### 4. Shift Operations  
- **LSL** – Logical Shift Left  
- **LSR** – Logical Shift Right  
- **ASR** – Arithmetic Shift Right  

### 5. Branching Instructions  
- **BEQ** – Branch if equal  
- **BGT** – Branch if greater  
- **B** – Unconditional branch  
- **CALL** – Function call  
- **RET** – Return from function  

### 6. Miscellaneous Instructions  
- **HLT** – Halt execution  
- **NOP** – No operation  

The assembler efficiently translates these instructions into their respective **32-bit binary representations**, ensuring correctness and optimization.  
## Addressing Modes  
The assembler supports various addressing modes to accommodate different instruction formats and data access methods.  

### 1. Immediate Addressing :45
### 2. Register Direct Addressing :R1  
### 3. Register Indirect Addressing :A012 
This flexible addressing mechanism allows efficient memory and register usage, optimizing instruction execution.

## Label Support
The assembler supports labels for jumps and subroutine calls. It resolves label addresses during the first pass.
## Error Handling  
The assembler provides **basic error detection** to handle common mistakes, including:  

- **Incorrect operand count** – If an instruction has too few or too many operands.  
- **Incomplete statements** – If an instruction is not fully written.  
- **Invalid labels** – If a label is not defined correctly or used improperly.  

However, even if an error occurs (such as an incorrect label), the assembler **still generates some binary output** and continues processing the remaining instructions instead of hal
# How to Use SimpleRisc Assembler  

## Prerequisites  
Before using the assembler, ensure you have the following installed:  
- **VS Code** (with extensions: Live Server, C++ Compiler)  
- **Node.js** (for backend execution)  
- **g++** (for compiling the assembler)  

# How to Use the Assembler

## Prerequisites
Make sure you have **VS Code** installed with the necessary extensions:
- Live Server
- C++ Compiler

Also, install **Node.js** on your system.

## Installation Steps

###  Install Dependencies
Open **VS Code** and run the following commands in the terminal:

```sh
npm init -y
npm install express multer child_process cors
```

### Installed Packages:
- **express** → Web framework to handle requests
- **multer** → File upload handling
- **child_process** → To execute `assembler.cpp`
- **cors** → To allow frontend to communicate with the backend

### Compile the Assembler (Windows)

```sh
g++ assembler.cpp -o assembler.exe
```
This creates `assembler.exe` (the executable file).

### Start the Backend Server

```sh
node server.js
```

### Open the Web Interface
- Open `index.html` in a browser using **Live Server** in VS Code.

###  Upload Assembly File
- Click **Upload** and select `input.asm`.
- The assembler will process the file.
- The output (`output.bin`) will be downloaded automatically.
